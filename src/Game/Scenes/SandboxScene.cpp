#include "SandboxScene.hpp"

SandboxScene::SandboxScene() : SceneSkeleton(), m_view(ViewMode::FREE), m_skybox(2000)
{
	m_shapeDef = b3DefaultShapeDef();
	m_shapeDef.density = 2.0;
	m_shapeDef.baseMaterial.friction = 1.0;

	m_view.camera3D.position = { -10, 0, 0 };
	m_framebuffer = RE::FrameBuffer(800, 450);
	m_light = RE::PointLight("../assets/shaders/blight.vs", "../assets/shaders/blight.fs", { 0, 5, 0 }, WHITE);

	m_customModel = RE::GameObject(world, { 10, 15, 10 }, b3_dynamicBody);
	m_customModel.loadModel(new Model(LoadModel("../assets/models/spear.obj")), m_shapeDef);

	SetMaterialTexture(&m_customModel.model->materials[0], MATERIAL_MAP_DIFFUSE, LoadTexture("../assets/textures/brick.png"));
	m_customModel.setShader(m_light.shader);

	this->loadMap();

	m_player = Player(world, { 0, 10, 0 });
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
	m_customModel.updatePhysics();
	m_player.update();
}

void SandboxScene::render()
{
	BeginTextureMode(m_framebuffer.target);
		ClearBackground({ 40, 40, 40 });
		BeginMode3D(m_view.camera3D);
			m_customModel.draw();
			m_skybox.draw();
			DrawSphere({ 0, 10, 0}, 2, RED);

			for (size_t i = 0; i < m_map.size(); i++)
			{
				m_map[i].draw();
			}

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

		for (size_t i = 0; i < m_map.size(); i++)
		{
			ImGui::PushID(i);
				m_map[i].gui();
			ImGui::PopID();
		}

	ImGui::End();
}

void SandboxScene::loadMap()
{
	Model* p1 = new Model(LoadModel("../assets/models/p1.obj"));
	Model* p2 = new Model(LoadModel("../assets/models/p2.obj"));
	Model* p3 = new Model(LoadModel("../assets/models/p3.obj"));
	Model* p4 = new Model(LoadModel("../assets/models/p4.obj"));

	Texture2D groundTexture = LoadTexture("../assets/textures/ground.png");
	m_map.emplace_back(RE::GameObject(world, { 0, -15, 0 }, b3_staticBody));
	m_map[0].loadModel(p1, m_shapeDef);
	SetMaterialTexture(&m_map[0].model->materials[0], MATERIAL_MAP_DIFFUSE, groundTexture);

	m_map.emplace_back(RE::GameObject(world, { 48, -15, 20 }, b3_staticBody));
	m_map[1].loadModel(p1, m_shapeDef);
	SetMaterialTexture(&m_map[1].model->materials[0], MATERIAL_MAP_DIFFUSE, groundTexture);

	m_map.emplace_back(RE::GameObject(world, { -47, -21, -29 }, b3_staticBody));
	m_map[2].loadModel(p1, m_shapeDef);
	SetMaterialTexture(&m_map[2].model->materials[0], MATERIAL_MAP_DIFFUSE, groundTexture);

	m_map.emplace_back(RE::GameObject(world, { -8, -21, -45 }, b3_staticBody));
	m_map[3].loadModel(p2, m_shapeDef);
	SetMaterialTexture(&m_map[3].model->materials[0], MATERIAL_MAP_DIFFUSE, groundTexture);

	m_map.emplace_back(RE::GameObject(world, { -69, -21, 38 }, b3_staticBody));
	m_map[4].loadModel(p3, m_shapeDef);
	SetMaterialTexture(&m_map[4].model->materials[0], MATERIAL_MAP_DIFFUSE, groundTexture);

	m_map.emplace_back(RE::GameObject(world, { 200, 2.7, 0 }, b3_staticBody));
	m_map[5].loadModel(p4, m_shapeDef);
	SetMaterialTexture(&m_map[5].model->materials[0], MATERIAL_MAP_DIFFUSE, groundTexture);
}