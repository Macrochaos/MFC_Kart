#include "stdafx.h"
#include "World.h"
World::World(){

}
World::~World(){

}
void World::Update(){
	int nObj = m_vGO.size();
	for (int i = 0; i < nObj; ++i) {
		m_vGO[i].Update();
	}
}