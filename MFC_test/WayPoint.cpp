#include "stdafx.h"
#include "WayPoint.h"


WayPoint::WayPoint(Vec2 & Poss, WayPoint * nextWP, bool is_StartLine, Vec2 & m_assistDir) {
	Pos = Poss;
	m_is_StartLine = is_StartLine;
	m_nextWP = nextWP;
}
WayPoint::WayPoint(Vec2 & Poss, bool is_StartLine, Vec2 & m_assistDir) {
	Pos = Poss;
	m_is_StartLine = is_StartLine;
	m_nextWP = nullptr;
}
WayPoint::WayPoint() {
	m_is_StartLine = false;
	m_nextWP = nullptr;
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
