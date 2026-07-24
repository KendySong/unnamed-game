#pragma once
#include <RayEngine.hpp>

class Skybox
{
public :
	Skybox(float size);
	void draw();
	std::vector<RE::GameObject> m_box;
private :
	
};