#include "stdafx.h"
#include "Kart.h"
#include "World.h"

#define HUE_DEGREE 512

COLORREF
hsv2rgb(int _h, UCHAR _s, UCHAR _v)
{
	BYTE r, g, b;

	if (_s == 0) {
		r = g = b = _v;
	}
	else {
		int h = _h;
		int s = _s;
		int v = _v;
		int i = h / (60 * HUE_DEGREE);
		int p = (256 * v - s*v) / 256;

		if (i & 1) {
			int q = (256 * 60 * HUE_DEGREE*v - h*s*v + 60 * HUE_DEGREE*s*v*i) / (256 * 60 * HUE_DEGREE);
			switch (i) {
			case 1:   r = q; g = v; b = p; break;
			case 3:   r = p; g = q; b = v; break;
			case 5:   r = v; g = p; b = q; break;
			}
		}
		else {
			int t = (256 * 60 * HUE_DEGREE*v + h*s*v - 60 * HUE_DEGREE*s*v*(i + 1)) / (256 * 60 * HUE_DEGREE);
			switch (i) {
			case 0:   r = v; g = t; b = p; break;
			case 2:   r = p; g = v; b = t; break;
			case 4:   r = t; g = p; b = v; break;
			}
		}
	}

	return RGB(r, g, b);
}

Kart::Kart(Vec2 & Position, float maxSpd, float mass, World * p_World) {
	Pos = Position;
	m_maxm_Speed = maxSpd;
	if (m_maxm_Speed < 1) {
		m_maxm_Speed = 1;
	}
	g_ZA_Waruldo = p_World;
	m_currWP = nullptr;
	m_mass = 1 / mass;

	m_KartSize = 5;
	m_nKartLaps = 0;

	m_color = hsv2rgb(rand() % (360 * HUE_DEGREE - 1) * 4, 128 + (rand() % 128), 255);
}
Kart::Kart(const Kart & otherK) {
	Pos = otherK.Pos;
	m_Speed = otherK.m_Speed;
	m_maxm_Speed = otherK.m_maxm_Speed;
	m_prevWP = otherK.m_prevWP;
	m_currWP = otherK.m_currWP;
	m_mass = otherK.m_mass;
	m_KartSize = 10;
	m_nKartLaps = 0;
}
void Kart::Update() {
	Vec2 steering;
	// mass
	// add all force then truncate if > m_maxm_Speed
	// dir becomes new m_Speed
	//m_Speed = (dir + steering) * m_maxm_Speed;

	/////////////////////////////////////////////////
	////////////// Steering Behaivours //////////////
	/////////////////////////////////////////////////
	if (m_currWP != nullptr) {
		steering += Seek(m_currWP->Pos, 100);
		steering += KartCollisionAvoidance() * 10;
		steering += StayOnPath(m_currWP->Pos) * 10;
	}
	else {
		m_currWP = g_ZA_Waruldo->m_vWP[0];
		steering += Seek(m_currWP->Pos, 100);
		steering += KartCollisionAvoidance() * 10;
		steering += StayOnPath(m_currWP->Pos) * 10;
	}
	//////////////////////////////////////////////
	////////////// Truncating m_Speed //////////////
	//////////////////////////////////////////////
	if (steering.Mag() > m_maxm_Speed) {
		steering.Normalize();
		steering*m_maxm_Speed;
	}
	if (steering.Mag() < 1) {
		steering.Normalize();
	}
	////////////// Off Roading //////////////
	Vec2 RoadDist = StayOnPath(m_currWP->Pos);
	if (RoadDist.Mag() > m_currWP->m_pathSize) {
		//m_Speed += RoadDist*10;
	}
		m_Speed += steering*m_mass;
	
	if (m_Speed.Mag() > m_maxm_Speed) {
		m_Speed.Normalize();
		m_Speed*m_maxm_Speed;
	}
	if (m_Speed.Mag() < 1) {
		m_Speed.Normalize();
	}
	//////////////////////////////////////////////
	////////////// Position changes //////////////
	//////////////////////////////////////////////
	//steering *= 15;
	Pos += m_Speed;
	m_steering = steering;
	m_steering.Normalize();
	/////////////////////////////////////////////
	////////////// Waypoint Switch //////////////
	/////////////////////////////////////////////
	float m_currWPDist = (m_currWP->Pos - Pos).Mag();
	if (m_currWPDist <  m_currWP->m_pathSize) {
		m_prevWP = m_currWP;
		if (m_currWP->m_is_StartLine) {
			++m_nKartLaps;
		}
		m_currWP = m_currWP->m_nextWP;
	}
	//////////////////////////////////////////////
	////////////// Race ended check //////////////
	//////////////////////////////////////////////
	if (m_nKartLaps == g_ZA_Waruldo->m_nLaps) {
		g_ZA_Waruldo->m_bRacing = false;
	}
}

void Kart::setNextWP(WayPoint * next) {
	m_currWP = next;
}
void Kart::setm_prevWP(WayPoint * last) {
	m_prevWP = last;
}
void Kart::setm_Speed(const Vec2 spd) {
	m_Speed = spd;
}
Vec2 Kart::KartCollisionAvoidance() {
	/////////////////////////////////////////////////
	////////////// Colission detection //////////////
	/////////////////////////////////////////////////
	Vec2 avoid;
	for (int i = 0; i < g_ZA_Waruldo->m_vKart.size(); ++i) {
		if ((g_ZA_Waruldo->m_vKart[i]->Pos - Pos).Mag() < m_KartSize*2) {
			if (g_ZA_Waruldo->m_vKart[i] != this) {
				avoid += (Pos - g_ZA_Waruldo->m_vKart[i]->Pos) * (m_maxm_Speed * 100);
			}
		}
	}
	return avoid;
}
float DotNormalized(Vec2 & Projected, Vec2 & ProjectedOn) {
	// calc dot of vectors
	// dive by product of magnitudes
	// res = cos(theta) of the first vector's mag projected on vector 2
	float dot = (Projected.x*ProjectedOn.x + Projected.y*ProjectedOn.y);
	float magmag = Projected.Mag() * ProjectedOn.Mag();
	return dot / magmag;
}
Vec2 Kart::StayOnPath(Vec2 & /*next wp*/target) {
	Vec2 LastWP2m_currWP = target - m_prevWP->Pos;
	Vec2 Kart2NextWP = Pos - m_prevWP->Pos;

	float mag = 1.0f / Kart2NextWP.Mag();

	Vec2 RetValue;
	float res = DotNormalized(Kart2NextWP * mag, LastWP2m_currWP * mag);
	if (res >= 1) {
		RetValue = target - Pos;
	}
	else if (res <= 0) {
		RetValue = m_prevWP->Pos - Pos;
	}
	else {
		Vec2 PointInTrack = Kart2NextWP * res;
		RetValue = PointInTrack - Pos;
	}
	RetValue.Normalize();
	return RetValue;
}

