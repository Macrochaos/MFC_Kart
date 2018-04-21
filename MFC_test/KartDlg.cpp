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
//Vec3 vecMidPoint(Vec3 &head, Vec3 &tail) {
//	return (head - tail) * 0.5;
//}
//Vec3 Normalized(Vec3 &vec) {
//	return vec *(1 / vec.Mag());
//}
//float Dot(Vec3 & vecA, Vec3 & vecB) {
//	Vec3 vecN_A = Normalized(vecA);
//	Vec3 vecN_B = Normalized(vecB);
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
	this->SetTimer(1, 100, NULL);

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
	CPaintDC dc(this);
	CDC* IMG_DC = m_KartBox.GetDC();
	IMG_DC->MoveTo(m_Zawarudo.m_vWP[0].Pos.x, m_Zawarudo.m_vWP[0].Pos.y);

	for (int i = 0; i < m_Zawarudo.m_vWP.size(); ++i) {
		IMG_DC->Rectangle(m_Zawarudo.m_vWP[i].Pos.x - 5, m_Zawarudo.m_vWP[i].Pos.y - 5, m_Zawarudo.m_vWP[i].Pos.x + 5, m_Zawarudo.m_vWP[i].Pos.y + 5);

		IMG_DC->LineTo(m_Zawarudo.m_vWP[i].Pos.x, m_Zawarudo.m_vWP[i].Pos.y);

	}
	IMG_DC->LineTo(m_Zawarudo.m_vWP[0].Pos.x, m_Zawarudo.m_vWP[0].Pos.y);
	for (int i = 0; i < m_Zawarudo.m_vKart.size(); ++i) {
		IMG_DC->Ellipse(m_Zawarudo.m_vKart[i].Pos.x - 2, m_Zawarudo.m_vKart[i].Pos.y - 2, m_Zawarudo.m_vKart[i].Pos.x + 2, m_Zawarudo.m_vKart[i].Pos.y + 2);
	}
}


