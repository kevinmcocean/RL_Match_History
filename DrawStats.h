#pragma once
#include "GuiBase.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "Session.h"

class DrawStats
{
private:

	// Variables
	CanvasWrapper* canvas = nullptr;

	int alphaBox = 190;
	int alphaText = 190;

	Vector2 drawPos;
	int lineSpacing = 15;

	void SetColorByValueFloat(float flt);
	void SetColorByValueInt(int i);

public:
	void Render(class CanvasWrapper canvas, Session& session);

	void AddLine() { drawPos.Y += lineSpacing; }
	void AdjustDrawPos(int xOffset, int yOffset) { drawPos.X += xOffset; drawPos.Y += yOffset; }
	void DrawColorStringFloat(float flt, std::string text);
	void DrawColorStringInt(int val, std::string text);
	void DrawWhiteString(std::string text);
	
};