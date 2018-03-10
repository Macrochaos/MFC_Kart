
// MFC_testDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMFC_testDlg dialog
class CMFC_testDlg : public CDialogEx
{
// Construction
public:
	CMFC_testDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_MainBox;
	CStatic m_ScreenControl;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	int m_MousePosX;
	int m_MousePosY;
	afx_msg void OnArchivoSalir();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedGoKarting();
};
