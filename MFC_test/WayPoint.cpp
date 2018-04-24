#include "stdafx.h"
#include "WayPoint.h"


WayPoint::WayPoint(Vec3 Poss, WayPoint * nextWP, bool is_StartLine, Vec3 m_assistDir) {
	Pos = Poss;
	m_is_StartLine = is_StartLine;
	m_nextWP = nextWP;
}
WayPoint::WayPoint(Vec3 Poss, bool is_StartLine, Vec3 m_assistDir) {
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
void WayPoint::SetPos(Vec3 position){ 
	Pos = position;
}
void WayPoint::SetWorld(World * ZA_Waruldo) {
	g_ZA_Waruldo = ZA_Waruldo;
}
