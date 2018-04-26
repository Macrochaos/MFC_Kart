#include "stdafx.h"
#include "World.h"
World::World(){
	m_nKarts = 100;
	m_nWayPoints = 15;
	m_nLaps = 10;
	m_bRacing = true;
	Vec2 origin;
	Kart * K;

	WayPoint * WP;
	for (int i = 0; i < m_nWayPoints; ++i) {
		WP = new WayPoint(origin, false, origin);
		m_vWP.push_back(WP);
	}
	for (int i = 0; i < m_nWayPoints; ++i) {
		if (i < m_nWayPoints-1) {
			m_vWP[i]->SetNext_WayPoint(m_vWP[i + 1]);
		}
		else {
			m_vWP[i]->SetNext_WayPoint(m_vWP[0]);
		}
	}
	m_vWP[0]->m_is_StartLine = true;
	/*WayPoint WP(origin, true, origin);
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
	}*/

	//////////////////////////////////////////////
	////////////// WayPoint pos set //////////////
	//////////////////////////////////////////////

	m_vWP[0]->SetPos(80, 180);
	m_vWP[1]->SetPos(50, 220);
	m_vWP[2]->SetPos(160, 380);
	m_vWP[3]->SetPos(240, 300);
	m_vWP[4]->SetPos(500, 350);
	m_vWP[5]->SetPos(280, 80);
	m_vWP[6]->SetPos(400, 15);
	m_vWP[7]->SetPos(480, 50);
	m_vWP[8]->SetPos(600, 30);
	m_vWP[9]->SetPos(620, 220);
	m_vWP[10]->SetPos(480, 150);
	m_vWP[11]->SetPos(280, 160);
	m_vWP[12]->SetPos(180, 220);
	m_vWP[13]->SetPos(200, 140);
	m_vWP[14]->SetPos(100, 130);
	/*
	m_vWP[0].Pos.x = 20 * 4; m_vWP[0].Pos.y = 180;
	m_vWP[1].Pos.x = 25 * 4; m_vWP[1].Pos.y = 220;
	m_vWP[2].Pos.x = 40 * 4; m_vWP[2].Pos.y = 280;
	m_vWP[3].Pos.x = 100 * 4; m_vWP[3].Pos.y = 240;
	m_vWP[4].Pos.x = 150 * 4; m_vWP[4].Pos.y = 300;
	m_vWP[5].Pos.x = 50 * 4; m_vWP[5].Pos.y = 20;
	m_vWP[6].Pos.x = 100 * 4; m_vWP[6].Pos.y = 15;
	m_vWP[7].Pos.x = 120 * 4; m_vWP[7].Pos.y = 50;
	m_vWP[8].Pos.x = 130 * 4; m_vWP[8].Pos.y = 200;
	m_vWP[9].Pos.x = 100 * 4; m_vWP[9].Pos.y = 220;
	m_vWP[10].Pos.x = 80 * 4; m_vWP[10].Pos.y = 230;
	m_vWP[11].Pos.x = 70 * 4; m_vWP[11].Pos.y = 200;
	m_vWP[12].Pos.x = 50 * 4; m_vWP[12].Pos.y = 180;
	m_vWP[13].Pos.x = 40 * 4; m_vWP[13].Pos.y = 140;
	m_vWP[14].Pos.x = 30 * 4; m_vWP[14].Pos.y = 130;
	*/
	

	///////////////////////////////////////////////
	////////////// Kart pos generate //////////////
	///////////////////////////////////////////////
	for (int i = 0; i < m_nKarts; ++i) {
		K = new Kart(m_vWP[0]->Pos, 5 + (i * 0.01), 2.5 + (i * 0.005), this);
		K->Pos.x += -40 +(i * 10);
		K->setm_prevWP(&*m_vWP[0]);
		K->setNextWP(&*m_vWP[1]);
		Vec2 startSpd = (K->m_currWP->Pos - K->Pos);
		startSpd *= K->m_maxm_Speed;
		K->setm_Speed(startSpd);
		m_vKart.push_back(K);
	}
}
World::~World(){

}
void World::Update(){
	int nObj = m_vKart.size();
	if(m_bRacing) {
		for (int i = 0; i < nObj; ++i) {
			m_vKart[i]->Update();
		}
	}
}