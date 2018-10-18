#pragma once
#include "afxcmn.h"


/////////////////////////////////////////////////////////////////////////////
// class CProgressChild
class CProgressChild :	public CProgressCtrl
{

private:
	COLORREF	m_ColourStartEndArray[2];
	COLORREF	m_ColourBack;

	struct CDrawInfo
	{
		CPaintDC*	pDC;
		CRect		rcClient;
		int			nCurPos;
		int			nLower;
		int			nUpper;
	};

public: // structors
	CProgressChild(void);
	~CProgressChild(void){}

// Attributes
public:
	void GetGradientColors(COLORREF* pClrStart, COLORREF* pClrEnd);
	COLORREF GetBkColor() {return m_ColourBack;}

private: // Helpers
	void SetBkColor(COLORREF colourBack) {m_ColourBack = colourBack;}
	void SetGradientColors(COLORREF clrStart, COLORREF clrEnd);
	CRect ConvertToReal(const CDrawInfo& info, const CRect& rcVirt);
	void DrawMultiGradient(const CDrawInfo& info, const CRect &rcGrad, const CRect &rcClip);
	void DrawGradient(const CDrawInfo& info, const CRect &rcGrad, const CRect &rcClip, COLORREF clrStart, COLORREF clrEnd);

	afx_msg void OnPaint();
	afx_msg LRESULT OnSetBarColor(WPARAM, LPARAM);
	afx_msg LRESULT OnSetBkColor(WPARAM, LPARAM);

	DECLARE_MESSAGE_MAP()
};
