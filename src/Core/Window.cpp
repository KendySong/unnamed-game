#include "Window.hpp"

Window Window::s_window;

Window& Window::instance()
{
	return s_window;
}

Window::Window()
{
	srand(Settings::seed);
	InitWindow(Settings::width, Settings::height, "unnamed-game");
	//SetWindowState(FLAG_BORDERLESS_WINDOWED_MODE);

	rlImGuiSetup(true);
	SetExitKey(KEY_NULL);
}

void Window::run()
{
	//Load scenes
	MenuScene menu;
	SandboxScene sandbox;

	RE::SceneManager& sceneManager = RE::SceneManager::instance();	
	sceneManager.scenes["menu"] = &menu;
	sceneManager.scenes["sandbox"] = &sandbox;
	sceneManager.setCurrent("menu");
	
	//Init default keys setup
	RE::Input::instance();
	while (!WindowShouldClose())
	{
		//Update
		if (!Settings::showPause)
		{
			sceneManager.current->update();
		}
		
		RE::Input::instance().executeNavigation();
		
		//Render
		BeginDrawing();
		sceneManager.current->render();

		if (Settings::showPause)
		{
			UI::pause();
		}

		//Gui
		if (Settings::debugMode)
		{
			rlImGuiBegin();
			sceneManager.current->gui();
			rlImGuiEnd();
		}
	
		EndDrawing();		
	}

	rlImGuiShutdown();
	CloseWindow();
}