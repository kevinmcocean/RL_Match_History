#include "pch.h"
#include "RL_Match_History.h"


BAKKESMOD_PLUGIN(RL_Match_History, "RL History Viewer", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void RL_Match_History::onLoad()
{
	_globalCvarManager = cvarManager;

	// Detect when scoreboard is opened
	gameWrapper->HookEvent("Function TAGame.GFxData_GameEvent_TA.OnOpenScoreboard", [this](std::string eventName) { scoreboardOpen = true; });

	// Detect when scoreboard is closed
	gameWrapper->HookEvent("Function TAGame.GFxData_GameEvent_TA.OnCloseScoreboard", [this](std::string eventName) { scoreboardOpen = false; });

	// Detect when Online Game is waiting for players
	gameWrapper->HookEvent("Function GameEvent_TA.Countdown.BeginState", [this](std::string eventName) { 
		session.JoinedOnlineGame(gameWrapper); 
	});

	// Draw Stats
	gameWrapper->RegisterDrawable([this](CanvasWrapper canvas) {
		if (scoreboardOpen)
			drawStats.Render(canvas, session);
	});

	// Let us know this loaded
	LOG("RL_Match_History has loaded successfully!");
}

void RL_Match_History::onUnload()
{
	// Clean up code if needed
	LOG("RL_Match_History has been unloaded successfully!");
}
