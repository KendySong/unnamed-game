#pragma once
#pragma once
#include <RayEngine.hpp>

#include "../Skybox.hpp"

class SandboxScene : public RE::SceneSkeleton
{
public :
	SandboxScene();
	void update() override;
	void render() override;
	void gui() override;

private : 
	View m_view;
	RE::FrameBuffer m_framebuffer;
	RE::PointLight m_light;

	RE::GameObject m_cube;
	RE::GameObject m_customModel;

	Skybox m_skybox;
};