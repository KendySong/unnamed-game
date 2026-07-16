#pragma once
#include <RayEngine.hpp>

#include "../UI.hpp"

class MenuScene : public RE::SceneSkeleton
{
public :
	MenuScene();
	void update() override;
	void render() override;
	void gui() override;

private : 
};