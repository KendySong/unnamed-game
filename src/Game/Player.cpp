#include "Player.hpp"

Player::Player(b3WorldId worldID, b3Vec3 position) : GameObject(worldID, position, b3_dynamicBody)
{
	m_mover.center1 = { 0, 0.25, 0 };
	m_mover.center2 = { 0, 1.25, 0 };
	m_mover.radius = 0.25f;


	RE::Input::instance().viewFPS.hold[KEY_W] = []() -> void {
		//b3World_CastMover(m_worldID, transform.position, &m_mover, );
	};
}

void Player::update()
{
	
}