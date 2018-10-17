
// ProgBarTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProgBarTest.h"
#include "ProgBarTestDlg.h"
#include "afxcolorpickerctrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CProgBarTestDlg::CProgBarTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProgBarTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProgBarTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_PROGRESS1, m_progChild);
	DDX_Control(pDX, IDC_SETPOS_SLIDER, m_setPosSlider);
	DDX_Control(pDX, IDC_START_BUTTON, m_startColour);	
	DDX_Control(pDX, IDC_END_BUTTON, m_endColour);	
	DDX_Control(pDX, IDC_BACK_BUTTON, m_backColour);
}

BEGIN_MESSAGE_MAP(CProgBarTestDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_START_BUTTON, &CProgBarTestDlg::OnBnClickedStartButton)
	ON_BN_CLICKED(IDC_END_BUTTON, &CProgBarTestDlg::OnBnClickedEndButton)
	ON_BN_CLICKED(IDC_BACK_BUTTON, &CProgBarTestDlg::OnBnClickedBackButton)
END_MESSAGE_MAP()


// CProgBarTestDlg message handlers

BOOL CProgBarTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_setPosSlider.SetRange(0,100);
	m_setPosSlider.SetPos(50);

	m_progChild.SetRange(0,100);
	m_progChild.SetPos(50);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProgBarTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProgBarTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CProgBarTestDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (nSBCode == TB_THUMBTRACK)
		m_progChild.SetPos(nPos);
}

void CProgBarTestDlg::OnBnClickedStartButton()
{
	COLORREF		colorStart;
	COLORREF		colorEnd;
	m_progChild.GetGradientColors(&colorStart, &colorEnd);
	
	CColorDialog	dlg(colorStart);
	 
	if (dlg.DoModal() == IDOK) 
	{ 
		colorStart = dlg.GetColor(); 

		SendDlgItemMessage(IDC_PROGRESS1,PBM_SETBARCOLOR,colorEnd, colorStart);

		CString reportString;
		reportString.Format(_T("The Start Colour is 0x%X"), colorStart);

		SetDlgItemText(IDC_START_STATIC, (LPCTSTR)reportString);
	}
}

void CProgBarTestDlg::OnBnClickedEndButton()
{
	COLORREF		colorStart;
	COLORREF		colorEnd;
	m_progChild.GetGradientColors(&colorStart, &colorEnd);
	
	CColorDialog	dlg(colorEnd);

	if (dlg.DoModal() == IDOK) 
	{ 
		colorEnd = dlg.GetColor(); 

		SendDlgItemMessage(IDC_PROGRESS1,PBM_SETBARCOLOR,colorEnd, colorStart);

		CString reportString;
		reportString.Format(_T("The End Colour is 0x%X"), colorEnd);

		SetDlgItemText(IDC_END_STATIC, (LPCTSTR)reportString);
	}
}

void CProgBarTestDlg::OnBnClickedBackButton()
{
	COLORREF		colorBack; 
	colorBack = m_progChild.GetBkColor();

	CColorDialog	dlg(colorBack);
	 
	if (dlg.DoModal() == IDOK) 
	{
		colorBack = dlg.GetColor();

		SendDlgItemMessage(IDC_PROGRESS1,PBM_SETBKCOLOR, 0, colorBack);

		CString reportString;
		reportString.Format(_T("The Back Colour is 0x%X"), colorBack);

		SetDlgItemText(IDC_BACK_STATIC, (LPCTSTR)reportString);
	}
}
