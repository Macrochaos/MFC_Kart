#include "stdafx.h"
#include "WayPoint.h"

#define HUE_DEGREE_ 512

COLORREF
hsv2rgb_(int _h, UCHAR _s, UCHAR _v)
{
	BYTE r, g, b;

	if (_s == 0) {
		r = g = b = _v;
	}
	else {
		int h = _h;
		int s = _s;
		int v = _v;
		int i = h / (60 * HUE_DEGREE_);
		int p = (256 * v - s*v) / 256;

		if (i & 1) {
			int q = (256 * 60 * HUE_DEGREE_*v - h*s*v + 60 * HUE_DEGREE_*s*v*i) / (256 * 60 * HUE_DEGREE_);
			switch (i) {
			case 1:   r = q; g = v; b = p; break;
			case 3:   r = p; g = q; b = v; break;
			case 5:   r = v; g = p; b = q; break;
			}
		}
		else {
			int t = (256 * 60 * HUE_DEGREE_*v + h*s*v - 60 * HUE_DEGREE_*s*v*(i + 1)) / (256 * 60 * HUE_DEGREE_);
			switch (i) {
			case 0:   r = v; g = t; b = p; break;
			case 2:   r = p; g = v; b = t; break;
			case 4:   r = t; g = p; b = v; break;
			}
		}
	}

	return RGB(r, g, b);
}

WayPoint::WayPoint(Vec2 & Poss, WayPoint * nextWP, bool is_StartLine, Vec2 & m_assistDir) {
	Pos = Poss;
	m_is_StartLine = is_StartLine;
	m_nextWP = nextWP;
	m_pathSize = 15;
	m_WPcolor = hsv2rgb_(rand() % (360 * HUE_DEGREE_ - 1) * 4, 128 + (rand() % 128), 255);
}
WayPoint::WayPoint(Vec2 & Poss, bool is_StartLine, Vec2 & m_assistDir) {
	Pos = Poss;
	m_is_StartLine = is_StartLine;
	m_nextWP = nullptr;
	m_pathSize = 15;
	m_WPcolor = hsv2rgb_(rand() % (360 * HUE_DEGREE_ - 1) * 4, 128 + (rand() % 128), 255);
}
WayPoint::WayPoint() {
	m_is_StartLine = false;
	m_nextWP = nullptr;
	m_pathSize = 15;
	m_WPcolor = hsv2rgb_(rand() % (360 * HUE_DEGREE_ - 1) * 4, 128 + (rand() % 128), 255);
}
WayPoint::~WayPoint() {

}
void WayPoint::Update() {

}
void WayPoint::SetNext_WayPoint(WayPoint * nextWP) {
	m_nextWP = nextWP;
}
void WayPoint::SetPos(Vec2 & position){
	Pos = position;
}
void WayPoint::SetPos(const int xx, const int yy) {
	Pos.x = xx; Pos.y = yy;
}
void WayPoint::SetWorld(World * ZA_Waruldo) {
	g_ZA_Waruldo = ZA_Waruldo;
}
