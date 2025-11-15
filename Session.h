#pragma once
#include "GuiBase.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "GameType.h"

class Session
{
private:

	// Variables
	int currentPlaylist = -1;
	GameType currentGameType;

public:

	void JoinedOnlineGame(std::shared_ptr<GameWrapper> gameWrapper);
	void Render(class CanvasWrapper canvas, Vector2 drawPos, int alphaText);

};