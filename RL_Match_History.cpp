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

	// Draw Stats
	gameWrapper->RegisterDrawable([this](CanvasWrapper canvas) {
		if (scoreboardOpen)
			drawStats.Render(canvas);
	});

	// Let us know this loaded
	LOG("RL_Match_History has loaded successfully!");
}

void RL_Match_History::onUnload()
{
	// Clean up code if needed
	LOG("RL_Match_History has been unloaded successfully!");
}

std::string RL_Match_History::GetGameTypeName(int gameType)
{
	switch (gameType)
	{
	case 1:		return "Casual Duel";
	case 2:		return "Casual Doubles";
	case 3:		return "Casual Standard";
	case 4:		return "Casual 4s";
	case 8:		return "Exhibition";
	case 10:	return "Ranked Duel";
	case 11:	return "Ranked Doubles";
	case 12:	return "Ranked Solo Standard";
	case 13:	return "Ranked Standard";
	case 27:	return "Ranked Hooops";
	case 28:	return "Ranked Rumble";
	case 29:	return "Ranked Drop Shot";
	case 30:	return "Ranked Snow Day";
	default:	return "Wait Until Game Starts";
	}
}
