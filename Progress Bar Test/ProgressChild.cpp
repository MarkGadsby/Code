#include "StdAfx.h"
#include "ProgressChild.h"


BEGIN_MESSAGE_MAP(CProgressChild, CProgressCtrl)
	ON_WM_PAINT()
	ON_MESSAGE(PBM_SETBARCOLOR, OnSetBarColor)
	ON_MESSAGE(PBM_SETBKCOLOR, OnSetBkColor)
END_MESSAGE_MAP()

CProgressChild::CProgressChild(void): m_ColourBack(0xC08080)
{
	SetGradientColors(0xC08080, 0x400000);
}

void CProgressChild::SetGradientColors(COLORREF clrStart, COLORREF clrEnd)
{
	m_ColourStartEndArray[0] = clrStart;
	m_ColourStartEndArray[1] = clrEnd; 
}

void CProgressChild::GetGradientColors(COLORREF* pClrStart, COLORREF* pClrEnd)
{
	*pClrStart	= m_ColourStartEndArray[0];
	*pClrEnd	= m_ColourStartEndArray[1]; 
}

void CProgressChild::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	CDrawInfo info;
	GetClientRect(&info.rcClient);

	// retrieve current position and range
	info.nCurPos = GetPos();
	GetRange(info.nLower, info.nUpper);

	// if current pos is out of range return
	if (info.nCurPos < info.nLower || info.nCurPos > info.nUpper)
		return;

	info.pDC = &dc;
	
	// fill background 
	info.pDC->FillSolidRect(&info.rcClient, m_ColourBack);

	// calculate visible gradient width
	CRect rcBar(0,0,0,0);
	CRect rcWhole(0,0,0,0);

	rcWhole.right = info.rcClient.Width();
	rcBar.right = (int)((float)(info.nCurPos-info.nLower) * rcWhole.right / (info.nUpper-info.nLower));

	DrawGradient(info, rcWhole, rcBar, m_ColourStartEndArray[0], m_ColourStartEndArray[1]);
	// Do not call CProgressCtrl::OnPaint() for painting messages
}

void CProgressChild::DrawGradient(const CDrawInfo& info, const CRect &rcWhole, const CRect &rcBar, COLORREF clrStart, COLORREF clrEnd)
{
	// Split colors to RGB chanels, find chanel with maximum difference 
	// between the start and end colors. This distance will determine 
	// number of steps of gradient
	int r = (GetRValue(clrEnd) - GetRValue(clrStart));
	int g = (GetGValue(clrEnd) - GetGValue(clrStart));
	int b = (GetBValue(clrEnd) - GetBValue(clrStart));
	int nSteps = max(abs(r), max(abs(g), abs(b)));

	// if number of pixels in gradient less than number of steps - 
	// use it as numberof steps
	int nPixels = rcWhole.Width();

	nSteps = min(nPixels, nSteps);

	if (nSteps == 0) 
		nSteps = 1;

	float rStep = (float)r / nSteps;
	float gStep = (float)g / nSteps;
	float bStep = (float)b / nSteps;

	r = GetRValue(clrStart);
	g = GetGValue(clrStart);
	b = GetBValue(clrStart);

	float nWidthPerStep = (float)rcWhole.Width() / nSteps;
	
	CRect rcFill(rcWhole);
	
	// Start filling
	for (int i = 0; i < nSteps; i++) 
	{
		rcFill.left = rcWhole.left + (int)(nWidthPerStep * i);
		rcFill.right = rcWhole.left + (int)(nWidthPerStep * (i+1));

		if (i == nSteps-1)	//last step (because of problems with float)
			rcFill.right = rcWhole.right;

		if (rcFill.right < rcBar.left)
			continue; // skip - band before cliping rect
		
		// clip it
		if (rcFill.left < rcBar.left)
			rcFill.left = rcBar.left;

		if (rcFill.right > rcBar.right)
			rcFill.right = rcBar.right;

		COLORREF clrFill = RGB(r + (int)(i * rStep),
		                       g + (int)(i * gStep),
		                       b + (int)(i * bStep));

		info.pDC->FillSolidRect(&ConvertToReal(info, rcFill), clrFill);

		if (rcFill.right >= rcBar.right)
			break; // stop filling if we reach current position
	}
}

CRect CProgressChild::ConvertToReal(const CDrawInfo& info, const CRect& rcVirt)
{
	CRect rc(info.rcClient);

	rc.left = info.rcClient.left + rcVirt.left;
	rc.right = rc.left + rcVirt.Width();

	return rc;
}
	
LRESULT CProgressChild::OnSetBarColor(WPARAM clrEnd, LPARAM clrStart)
{
	SetGradientColors(clrStart, clrEnd ? clrEnd : clrStart);
	return CLR_DEFAULT;
}

LRESULT CProgressChild::OnSetBkColor(WPARAM, LPARAM clrBk)
{
	m_ColourBack = clrBk;
	return CLR_DEFAULT;
}



