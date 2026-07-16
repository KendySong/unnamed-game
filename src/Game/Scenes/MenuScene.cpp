#include "MenuScene.hpp"

MenuScene::MenuScene() : SceneSkeleton()
{
	
}

void MenuScene::update()
{

}

void MenuScene::render()
{
	ClearBackground({ 40, 40, 40 });
	
	if (GuiButton({ 100, 100, 200, 50 }, "Play"))
	{
		DisableCursor();
		RE::SceneManager::instance().setCurrent("sandbox");
	}
	
	if (GuiButton({ 100, 200, 200, 50 }, "Option"))
	{
		Settings::showOptions = !Settings::showOptions;
	}

	if (Settings::showOptions)
	{
		UI::options();
	}

	if (GuiButton({ 100, 300, 200, 50 }, "Quit"))
	{
		exit(0);
	}
}

void MenuScene::gui()
{
	ImGui::Begin("Settings[menu]");
	ImGui::End();
}