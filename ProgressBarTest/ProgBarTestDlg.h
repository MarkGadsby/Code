#include "ProgressChild.h"

#pragma once

class CProgBarTestDlg : public CDialog
{
// Construction
public:
	CProgBarTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_PROGBARTEST_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	CProgressChild		m_progChild;
	CSliderCtrl			m_setPosSlider;
	CButton				m_startColour;	
	CButton				m_endColour;	
	CButton				m_backColour;

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedStartButton();
	afx_msg void OnBnClickedEndButton();
	afx_msg void OnBnClickedBackButton();
};
