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
END_MESSAGE_MAP()


// CKartDlg message handlers


BOOL CKartDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	

	// TODO:  Add extra initialization here
	//Make timer here
	//timer calls update
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
void CKartDlg::Update() {
	m_Zawarudo.Update();
}
void CKartDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDialog::OnPaint() for painting messages

	CDC* IMG_DC = m_KartBox.GetDC();
	for (int i = 0; i < m_Zawarudo.m_vKart.size(); ++i) {
		IMG_DC->Ellipse(m_Zawarudo.m_vKart[i].Pos.x - 1, m_Zawarudo.m_vKart[i].Pos.y - 1, m_Zawarudo.m_vKart[i].Pos.x + 1, m_Zawarudo.m_vKart[i].Pos.y + 1);
	}

}
