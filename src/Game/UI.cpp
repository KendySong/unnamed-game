#include "UI.hpp"

UI::UI()
{

}

void UI::pause()
{
	if (GuiButton({ 100, 100, 200, 50 }, "Resume"))
	{
		DisableCursor();
		Settings::showPause = false;
	}

	if (GuiButton({ 100, 200, 200, 50 }, "Option"))
	{
		Settings::showOptions = true;
	}

	if (GuiButton({ 100, 300, 200, 50 }, "Quit"))
	{
		exit(0);
	}

	if (Settings::showOptions)
	{
		UI::options();
	}
}

void UI::options()
{
	if (GuiWindowBox({ 600, 400, 600, 400 }, "Options"))
	{
		Settings::showOptions = !Settings::showOptions;
	}
}