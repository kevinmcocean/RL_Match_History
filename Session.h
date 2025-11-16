#pragma once
#include "GuiBase.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "GameType.h"

class DrawStats;
class GameWrapper;
class MMRWrapper;

class Session
{
private:

	// Variables
	int currentPlaylist = -1;
	GameType currentGameType;
	std::vector<GameType> gameTypes;

	GameType& getOrCreateGameType(int playlist, float currentMMR);

public:

	void GameEnded(std::shared_ptr<GameWrapper> gameWrapper);
	void JoinedOnlineGame(std::shared_ptr<GameWrapper> gameWrapper);
	
	void Render(DrawStats& drawStats);
};