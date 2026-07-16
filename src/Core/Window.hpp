#pragma once
#include <RayEngine.hpp>

#include "../Game/Scenes/MenuScene.hpp"
#include "../Game/Scenes/SandboxScene.hpp"
#include "../Game/UI.hpp"

class Window
{
public :
	static Window& instance();
	void run();

private :
	static Window s_window;
	Window();	
};