#pragma once
#pragma once
#include <RayEngine.hpp>

#include "../Skybox.hpp"
#include "../Player.hpp"

class SandboxScene : public RE::SceneSkeleton
{
public :
	SandboxScene();
	void update() override;
	void render() override;
	void gui() override;

private : 
	void loadMap();

	View m_view;
	b3ShapeDef m_shapeDef;

	RE::FrameBuffer m_framebuffer;
	RE::PointLight m_light;

	RE::GameObject m_customModel;

	Skybox m_skybox;
	std::vector<RE::GameObject> m_map;

	Player m_player;
};