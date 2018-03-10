#pragma once


// CDlgName dialog

class CDlgName : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgName)

public:
	CDlgName(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgName();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_NAME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_Name;
	afx_msg void OnBnClickedOk();
};
