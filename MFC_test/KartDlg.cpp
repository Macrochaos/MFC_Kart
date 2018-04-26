// KartDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_test.h"
#include "KartDlg.h"
#include "afxdialogex.h"
#include "World.h"


// CKartDlg dialog

IMPLEMENT_DYNAMIC(CKartDlg, CDialog)
/*
//bool find_uint_InVector(vector<unsigned int> vec, int val) {
//	int s = vec.size();
//	for (int i = 0; i < s; ++i) {
//		if (vec[i] = val)
//			return true;
//	}
//	return false;
//}
//Vec2 vecMidPoint(Vec2 &head, Vec2 &tail) {
//	return (head - tail) * 0.5;
//}
//Vec2 Normalized(Vec2 &vec) {
//	return vec *(1 / vec.Mag());
//}
//float Dot(Vec2 & vecA, Vec2 & vecB) {
//	Vec2 vecN_A = Normalized(vecA);
//	Vec2 vecN_B = Normalized(vecB);
//	return(vecN_A.x*vecN_B.x + vecN_A.y*vecN_B.y + vecN_A.z*vecN_B.z);
//}
*/
CKartDlg::CKartDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_KART, pParent)
{

}
CKartDlg::~CKartDlg() {

}

void CKartDlg::DoDataExchange(CDataExchange* pDX) {
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_KARTBOX, m_KartBox);
}


BEGIN_MESSAGE_MAP(CKartDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CKartDlg message handlers


BOOL CKartDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// TODO:  Add extra initialization here
	this->SetTimer(1, 16, NULL);

	//Make timer here
	//timer calls update
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
void CKartDlg::Update() {
	m_Zawarudo.Update();
}

void CKartDlg::OnTimer(UINT_PTR nIDEvent) {
	// TODO: Add your message handler code here and/or call default
	if (nIDEvent == 1) 	{
		Update();
		UpdatePaintData();
		m_KartBox.UpdateData(FALSE);
	}
	//CTime CurrTime = CTime::GetCurrentTime();

	CDialog::OnTimer(nIDEvent);
}
void CKartDlg::OnPaint()
{
	                   // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDialog::OnPaint() for painting messages
	CPaintDC dc(this);
	CDC* IMG_DC = m_KartBox.GetDC();
}
void CKartDlg::UpdatePaintData() {

	RECT ClientRect;
	m_KartBox.GetClientRect(&ClientRect);

	CPaintDC dc(this);
	CDC* IMG_DC = m_KartBox.GetDC();
	IMG_DC->Rectangle(&ClientRect);

	IMG_DC->MoveTo(m_Zawarudo.m_vWP[0]->Pos.x, m_Zawarudo.m_vWP[0]->Pos.y); // Moves to position of first Waypoint
	HGDIOBJ pAnteriorBrush;
	for (auto& wp : m_Zawarudo.m_vWP) { // Paints waypoints and the lines that connect them 
		CBrush br(static_cast<COLORREF>(wp->m_WPcolor));
		pAnteriorBrush = IMG_DC->SelectObject(br);

		IMG_DC->Rectangle(wp->Pos.x + wp->m_pathSize, wp->Pos.y + wp->m_pathSize, 
			wp->Pos.x - wp->m_pathSize, wp->Pos.y - wp->m_pathSize);
		IMG_DC->LineTo(wp->Pos.x, wp->Pos.y);

		IMG_DC->SelectObject(pAnteriorBrush);
	}
	IMG_DC->LineTo(m_Zawarudo.m_vWP[0]->Pos.x, m_Zawarudo.m_vWP[0]->Pos.y); // Paints last line to first Waypoint
	
	
	for (auto& kart : m_Zawarudo.m_vKart) { // Paints the karts
		CBrush br(static_cast<COLORREF>(kart->m_color));
		pAnteriorBrush = IMG_DC->SelectObject(br);
		
		IMG_DC->Ellipse(kart->Pos.x + kart->m_KartSize, kart->Pos.y + kart->m_KartSize,
			kart->Pos.x - kart->m_KartSize, kart->Pos.y - kart->m_KartSize);
		
		IMG_DC->MoveTo(kart->Pos.x, kart->Pos.y);
		IMG_DC->LineTo(kart->Pos.x + (kart->m_steering.x * kart->m_maxm_Speed  * 5),
					   kart->Pos.y + (kart->m_steering.y * kart->m_maxm_Speed) * 5);

		IMG_DC->SelectObject(pAnteriorBrush);
	}
}


