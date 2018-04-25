#include "stdafx.h"
#include "World.h"
World::World(){
	m_nKarts = 20;
	m_nWayPoints = 15;

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

	m_vWP[0]->SetPos(20 * 4, 180);
	m_vWP[1]->SetPos(25 * 4, 220);
	m_vWP[2]->SetPos(40 * 4, 380);
	m_vWP[3]->SetPos(80 * 4, 300);
	m_vWP[4]->SetPos(150 * 4, 400);
	//m_vWP[0].Pos.x = 20 * 4; m_vWP[0].Pos.y = 180;
	//m_vWP[1].Pos.x = 25 * 4; m_vWP[1].Pos.y = 220;
	//m_vWP[2].Pos.x = 40 * 4; m_vWP[2].Pos.y = 280;
	//m_vWP[3].Pos.x = 100 * 4; m_vWP[3].Pos.y = 240;
	//m_vWP[4].Pos.x = 150 * 4; m_vWP[4].Pos.y = 300;
	m_vWP[5]->SetPos(50 * 4, 20);
	m_vWP[6]->SetPos(100 * 4, 15);
	m_vWP[7]->SetPos(120 * 4, 50);
	m_vWP[8]->SetPos(150 * 4, 30);
	m_vWP[9]->SetPos(155 * 4, 220);
	//m_vWP[5].Pos.x = 50 * 4; m_vWP[5].Pos.y = 20;
	//m_vWP[6].Pos.x = 100 * 4; m_vWP[6].Pos.y = 15;
	//m_vWP[7].Pos.x = 120 * 4; m_vWP[7].Pos.y = 50;
	//m_vWP[8].Pos.x = 130 * 4; m_vWP[8].Pos.y = 200;
	//m_vWP[9].Pos.x = 100 * 4; m_vWP[9].Pos.y = 220;
	m_vWP[10]->SetPos(120 * 4, 150);
	m_vWP[11]->SetPos(70 * 4, 200);
	m_vWP[12]->SetPos(50 * 4, 180);
	m_vWP[13]->SetPos(40 * 4, 140);
	m_vWP[14]->SetPos(30 * 4, 130);
	//m_vWP[10].Pos.x = 80 * 4; m_vWP[10].Pos.y = 230;
	//m_vWP[11].Pos.x = 70 * 4; m_vWP[11].Pos.y = 200;
	//m_vWP[12].Pos.x = 50 * 4; m_vWP[12].Pos.y = 180;
	//m_vWP[13].Pos.x = 40 * 4; m_vWP[13].Pos.y = 140;
	//m_vWP[14].Pos.x = 30 * 4; m_vWP[14].Pos.y = 130;

	///////////////////////////////////////////////
	////////////// Kart pos generate //////////////
	///////////////////////////////////////////////
	for (int i = 0; i < m_nKarts; ++i) {
		K = new Kart(m_vWP[0]->Pos, 100, 5, this);
		K->KPos.x += -40 +(i * 10);
		K->currWP = &*m_vWP[1];
		m_vKart.push_back(K);
	}
}
World::~World(){

}
void World::Update(){
	//int nObj = m_vGO.size();
	int nObj = m_vKart.size();
	for (int i = 0; i < nObj; ++i) {
		m_vKart[i]->Update();
	}
}