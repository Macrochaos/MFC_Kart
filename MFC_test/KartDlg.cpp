// KartDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_test.h"
#include "KartDlg.h"
#include "afxdialogex.h"


// CKartDlg dialog

IMPLEMENT_DYNAMIC(CKartDlg, CDialog)
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
//////////////////////////////////////////// ^ Struct Vec3 ^ ////////////////////////////////////////////
CKartDlg::CKartDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_DLG_KART, pParent)
{

}

CKartDlg::~CKartDlg()
{
}

void CKartDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CKartDlg, CDialog)
END_MESSAGE_MAP()


// CKartDlg message handlers
