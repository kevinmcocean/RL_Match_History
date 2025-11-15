#pragma once
#include "GuiBase.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

class DrawStats
{
private:

	// Variables
	int alphaBox = 190;
	int alphaText = 190;

public:
	void Render(class CanvasWrapper canvas);
};