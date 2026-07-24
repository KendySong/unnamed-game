#pragma once
#include <RayEngine.hpp>

class Player : RE::GameObject
{
public :
	Player() = default;
	Player(b3WorldId worldID, b3Vec3 position);
	void update();

private :
	b3Capsule m_mover;
	b3WorldId m_worldID;
};