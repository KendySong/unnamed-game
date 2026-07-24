#include "Skybox.hpp"

Skybox::Skybox(float size)
{
	float hsize = size / 2;
	RE::AssetManager& assetM = RE::AssetManager::instance();

	assetM.model["skybox"] = LoadModelFromMesh(GenMeshCube(size, size, 0.1));
	assetM.setModeleTexture("skybox", MATERIAL_MAP_DIFFUSE, LoadTexture("../assets/textures/night.png"));
	
	for (size_t i = 0; i < 6; i++)
	{
		m_box.push_back(RE::GameObject());
		m_box[i].model = &assetM.model["skybox"];
	}

	m_box[0].transform.position = { 0, 0, hsize };
	m_box[1].transform.position = { 0, 0, -hsize };

	m_box[2].transform.position = { hsize, 0, 0 };
	m_box[2].transform.rotation = b3MakeQuatFromAxisAngle(b3Vec3_axisY, M_PI_2);

	m_box[3].transform.position = { -hsize, 0, 0 };
	m_box[3].transform.rotation = b3MakeQuatFromAxisAngle(b3Vec3_axisY, M_PI_2);

	m_box[4].transform.position = { 0, hsize, 0 };
	m_box[4].transform.rotation = b3MakeQuatFromAxisAngle(b3Vec3_axisX, M_PI_2);

	m_box[5].transform.position = { 0, -hsize, 0 };
	m_box[5].transform.rotation = b3MakeQuatFromAxisAngle(b3Vec3_axisX, M_PI_2);
}

void Skybox::draw()
{
	for (size_t i = 0; i < m_box.size(); i++)
	{
		m_box[i].draw();
	}
}