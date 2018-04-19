#include "stdafx.h"
#include "World.h"
World::World(){
	Vec3 origin;
	WayPoint WP(origin, true, origin);
	WayPoint next_WP(origin, false, origin);

	WP.SetNext_WayPoint(&next_WP);

	m_vWP.push_back(WP);
	m_vWP.push_back(next_WP);

	for (int i = 2; i < m_nWayPoints;++i) {
		WP = next_WP;
		next_WP = WayPoint(origin, false, origin);
		WP.SetNext_WayPoint(&next_WP);
		m_vWP.push_back(WP);
		if (i == m_nWayPoints - 1) {
			m_vWP[i].SetNext_WayPoint(&m_vWP[0]);
		}
	}
	////////////
	// WayPoint pos set
	////////////
	m_vWP[0].Pos.x = 20; m_vWP[0].Pos.y = 180;
	m_vWP[1].Pos.x = 25; m_vWP[1].Pos.y = 220;
	m_vWP[2].Pos.x = 40; m_vWP[2].Pos.y = 280;
	m_vWP[3].Pos.x = 100; m_vWP[3].Pos.y = 240;
	m_vWP[4].Pos.x = 150; m_vWP[4].Pos.y = 300;

	m_vWP[5].Pos.x = 50; m_vWP[5].Pos.y = 20;
	m_vWP[6].Pos.x = 100; m_vWP[6].Pos.y = 15;
	m_vWP[7].Pos.x = 120; m_vWP[7].Pos.y = 50;
	m_vWP[8].Pos.x = 130; m_vWP[8].Pos.y = 200;
	m_vWP[9].Pos.x = 100; m_vWP[9].Pos.y = 220;

	m_vWP[10].Pos.x = 80; m_vWP[10].Pos.y = 230;
	m_vWP[11].Pos.x = 70; m_vWP[11].Pos.y = 200;
	m_vWP[12].Pos.x = 50; m_vWP[12].Pos.y = 180;
	m_vWP[13].Pos.x = 40; m_vWP[13].Pos.y = 140;
	m_vWP[14].Pos.x = 30; m_vWP[14].Pos.y = 130;

	////////// Kart pos generate //////////
	for (int i = 0; i < m_nKarts; ++i) {
		Kart K(m_vWP[0].Pos, i+1, this);
		K.Pos.x += i * 5;
		m_vKart.push_back(K);
	}
	//Kart KKS(m_vWP[0].Pos, 1, this);
	//m_vGO.push_back(KKS);
}
World::~World(){

}
void World::Update(){
	//int nObj = m_vGO.size();
	int nObj = m_vKart.size();
	for (int i = 0; i < nObj; ++i) {
		m_vKart[i].Update();
	}
}