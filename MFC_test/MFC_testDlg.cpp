
// MFC_testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_test.h"
#include "MFC_testDlg.h"

#include "afxdialogex.h"
#include "DlgName.h"
#include "KartDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_testDlg dialog
//CD  dc(wnd)


CMFC_testDlg::CMFC_testDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_TEST_DIALOG, pParent)
	, m_MainBox(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_testDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MAINBOX2, m_MainBox);
	DDX_Control(pDX, IDC_MAINSCR, m_ScreenControl);
}

BEGIN_MESSAGE_MAP(CMFC_testDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFC_testDlg::OnBnClickedOk)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_ARCHIVO_SALIR, &CMFC_testDlg::OnArchivoSalir)
	ON_BN_CLICKED(button_Go_Karting, &CMFC_testDlg::OnBnClickedGoKarting)
END_MESSAGE_MAP()


// CMFC_testDlg message handlers

BOOL CMFC_testDlg::OnInitDialog() {
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_MousePosX = 0;
	m_MousePosY = 0;

	m_MainBox = TEXT("Hola");
	UpdateData(false);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFC_testDlg::OnPaint() {
	if (IsIconic()) {
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
	else {
		CDialogEx::OnPaint();

		CDC* pDE = m_ScreenControl.GetDC();
		
		POINT punto;
		punto.x = 100;
		punto.y = 100;


		int ticks = GetTickCount();
		CString texto;
		texto.Format(TEXT("%d"), ticks);
		
		CPen pen(PS_SOLID, 0, RGB(255, 0, 0));
		CPen* pOldPen = pDE->SelectObject(&pen);

		pDE->LineTo(punto);
		pDE->TextOutW(punto.x, punto.y, texto);

		pDE->SelectObject(&pOldPen);
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFC_testDlg::OnQueryDragIcon() {
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC_testDlg::OnBnClickedOk() {
	// TODO: Add your control notification handler code here
	//CDialogEx::OnOK();
	//Beep(750, 300);

	//MessageBox(m_MainBox, TEXT("Mensaje!!!"), MB_OK);
	//m_MainBox += TEXT("Este es el mensaje que quiero en el control.\r\n");
	//UpdateData(false);
	/*
	CDlgName miDialogo;
	miDialogo.DoModal();

	m_MainBox += miDialogo.m_Name;
	UpdateData(false);
	*/

	MessageBeep(MB_ICONERROR);
}


void CMFC_testDlg::OnMouseMove(UINT nFlags, CPoint point) {
	// TODO: Add your message handler code here and/or call default
	m_MousePosX = point.x;
	m_MousePosY = point.y;

	CDC* pDE = m_ScreenControl.GetDC();

	POINT punto;
	punto.x = 100;
	punto.y = 120;

	CString texto;
	texto.Format(TEXT("%04d, %04d"), m_MousePosX, m_MousePosY);
	//pDE->TextOutW(punto.x, punto.y, texto);

	CDialogEx::OnMouseMove(nFlags, point);
}


void CMFC_testDlg::OnArchivoSalir() {
	// TODO: Add your command handler code here
	int msg = MessageBox(TEXT("Seguro?"), TEXT("Salir?"), MB_OKCANCEL);
	if(msg == 1) {
		OnCancel();
	}
}
//////////


void CMFC_testDlg::OnBnClickedGoKarting() {
	// TODO: Add your control notification handler code here
	CKartDlg KartingTime;
	KartingTime.DoModal();
}
