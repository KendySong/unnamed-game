#include "SandboxScene.hpp"

SandboxScene::SandboxScene() : SceneSkeleton(), m_view(ViewMode::FPS), m_skybox(2000)
{
	b3ShapeDef shapeDef = b3DefaultShapeDef();
	shapeDef.density = 2.0;
	shapeDef.baseMaterial.friction = 0.1;

	m_view.camera3D.position = { -10, 0, 0 };
	m_framebuffer = RE::FrameBuffer(800, 450);
	m_light = RE::PointLight("../assets/shaders/blight.vs", "../assets/shaders/blight.fs", { 0, 5, 0 }, WHITE);

	m_cube = RE::GameObject(world, { 0, -10, 0 }, b3Quat_identity, b3_staticBody);
	m_cube.loadModel(new Model(LoadModelFromMesh(GenMeshCube(400, 0.1, 400))), shapeDef);
	m_cube.setShader(m_light.shader);

	m_customModel = RE::GameObject(world, { 10, 0, 10 }, b3Quat_identity, b3_dynamicBody);
	m_customModel.loadModel(new Model(LoadModel("../assets/models/sword.obj")), shapeDef);
	SetMaterialTexture(&m_customModel.model->materials[0], MATERIAL_MAP_DIFFUSE, LoadTexture("../assets/textures/brick.png"));

	m_customModel.setShader(m_light.shader);
}

void SandboxScene::update()
{
	float dt = GetFrameTime();
	if (!Settings::debugMode)
	{
		m_view.update();
	}

	b3World_Step(world, dt, Settings::subStepCount);

	m_light.updateUniform();
	m_cube.updatePhysics();
	m_customModel.updatePhysics();
}

void SandboxScene::render()
{
	BeginTextureMode(m_framebuffer.target);
		ClearBackground({ 40, 40, 40 });
		BeginMode3D(m_view.camera3D);
		
			m_cube.draw();
			m_customModel.draw();
			m_skybox.draw();
			DrawSphere({ 0, 0, 0}, 2, RED);

		EndMode3D();
	EndTextureMode();

	ClearBackground({ 40, 40, 40 });
	m_framebuffer.render();
}

void SandboxScene::gui()
{
	ImGui::Begin("Settings[sandbox]");
		m_view.gui();
		m_skybox.m_box[3].gui();
	ImGui::End();
}