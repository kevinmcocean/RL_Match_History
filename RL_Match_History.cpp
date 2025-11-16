#include "pch.h"
#include "RL_Match_History.h"


BAKKESMOD_PLUGIN(RL_Match_History, "RL History Viewer", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void RL_Match_History::onLoad()
{
	_globalCvarManager = cvarManager;

	// Construct members when plugin is loaded
	drawStats = std::make_unique<DrawStats>();
	session = std::make_unique<Session>();

	// Detect when scoreboard is opened
	gameWrapper->HookEvent("Function TAGame.GFxData_GameEvent_TA.OnOpenScoreboard", [this](std::string eventName) { scoreboardOpen = true; });

	// Detect when scoreboard is closed
	gameWrapper->HookEvent("Function TAGame.GFxData_GameEvent_TA.OnCloseScoreboard", [this](std::string eventName) { scoreboardOpen = false; });

	// Detect when waiting for players
	gameWrapper->HookEvent("Function OnlineGameJoinGame_X.WaitForAllPlayers.BeginState", [this](std::string eventName) {
		session->JoinedOnlineGame(gameWrapper);
	});

	// Detect when game countdown starts
	gameWrapper->HookEvent("Function GameEvent_TA.Countdown.BeginState", [this](std::string eventName) { 
		session->JoinedOnlineGame(gameWrapper); 
	});

	// Detect when game ends
	gameWrapper->HookEventPost("Function TAGame.GameEvent_Soccar_TA.EventMatchWinnerSet", [this](std::string eventName) {

	});

	// Draw Stats
	gameWrapper->RegisterDrawable([this](CanvasWrapper canvas) {
		if (scoreboardOpen)
			drawStats->Render(canvas, *session);
	});

	// Let us know this loaded
	LOG("RL_Match_History has loaded successfully!");
}

void RL_Match_History::onUnload()
{

	// Tear down
	drawStats.reset();
	session.reset();

	// Clean up code if needed
	LOG("RL_Match_History has been unloaded successfully!");
}
