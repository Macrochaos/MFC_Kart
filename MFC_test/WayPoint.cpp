#include "stdafx.h"
#include "WayPoint.h"


WayPoint::WayPoint(Vec3 Poss, WayPoint * nextWP, bool is_StartLine, Vec3 m_assistDir) {
	Pos = Poss;
	m_is_StartLine = is_StartLine;
	m_nextWP = nextWP;
}
WayPoint::~WayPoint() {

}
