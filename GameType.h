#pragma once
#include <string>
#include "GuiBase.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "Database.h"

class DrawStats;
class CanvasWrapper;

class GameType
{
private:

	int playlist;
	float startingMMR;
	float currentMMR;
	float previousMMR;
	float currentStreakMMR;

	int currentStreak;

public:
	
	// Constructors
	GameType() : playlist(-1), startingMMR(0.0f), currentMMR(0.0f), previousMMR(0.0f), currentStreakMMR(0.0f), currentStreak(0) {}
	GameType(int playlist, float startingMMR);

	// Game ended
	void GameEnded(std::shared_ptr<class GameWrapper> gameWrapper, std::shared_ptr<class Database> db);

	// Variable access
	int getPlaylist() const { return playlist; };
	std::string GetGameTypeName(int gameType);

	// Variable modification
	void SetCurrentMMR(float mmr) { currentMMR = mmr; }

	// Render
	void Render(DrawStats& drawStats);

};
