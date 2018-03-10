#pragma once


// CKartDlg dialog
struct Vec3 {
	union {
		float x, y, z = 0;
		float v[3];
	};
	Vec3() {
		x = 0; y = 0; z = 0;
	}
	Vec3(float xx, float yy, float zz) {
		x = xx; y = yy; z = zz;
	}
	Vec3 operator = (Vec3 other) {
		x = other.x; y = other.y; z = other.z;
		return *this;
	}
	Vec3 operator +=(Vec3 other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}
	Vec3 operator *(float f) {
		x *= f;
		y *= f;
		z *= f;
		return *this;
	}
	Vec3 operator *=(float f) {
		x *= f;
		y *= f;
		z *= f;
		return *this;
	}
	Vec3 operator /(float f) {
		x /= f;
		y /= f;
		z /= f;
		return *this;
	}
	Vec3 operator -(Vec3 other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}
	Vec3 operator +(Vec3 other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}
	void Normalize(Vec3 &vect) {
		float mag = 0;
		mag = vect.x * vect.x + vect.y * vect.y + vect.z * vect.z;
		mag = sqrt(mag);
		vect.x *= mag; vect.y *= mag; vect.z *= mag;
	}
	float Mag() {
		return sqrt(x*x + y*y + z*z);
	}
	//float
};
class WayPoint : public CDialog {
public:
	Vec3 Pos;
	bool is_StartLine;
	WayPoint * nextWP;
	WayPoint * prevWP;

	WayPoint(Vec3 Pos);

};
class Kart {
public:
	Vec3 Pos;
	Vec3 dir;
	float currSpeed;
	float maxSpeed;
	WayPoint * startWP;

	Kart(Vec3 Pos);
};
//18 WPs
//range of detection 1 unit
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
};
