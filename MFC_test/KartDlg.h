#pragma once
#include "afxwin.h"
#include "World.h"

// CKartDlg dialog





class CKartDlg : public CDialog
{
	DECLARE_DYNAMIC(CKartDlg)

public:
	
	CKartDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CKartDlg();
	
// Dialog Data
	
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_KART };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	World m_Zawarudo;
	CStatic m_KartBox;
	virtual BOOL OnInitDialog();
	void Update();
	void UpdatePaintData();
	//void OnTimer(UINT_PTR nIDEvent);

	afx_msg void OnPaint();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
