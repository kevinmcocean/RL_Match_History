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
			DrawStats(canvas);
	});

	// Let us know this loaded
	LOG("RL_Match_History has loaded successfully!");
}

void RL_Match_History::onUnload()
{
	// Clean up code if needed
	LOG("RL_Match_History has been unloaded successfully!");
}

void RL_Match_History::DrawStats(CanvasWrapper canvas)
{

    // Variables
    int alphaBox = 190;
    int alphaText = 190;

    // Screen size
    float screenW = static_cast<float>(canvas.GetSize().X);
    float screenH = static_cast<float>(canvas.GetSize().Y);

    // Scoreboard parameters
    const float scoreboardRatio = 0.60f;
    float scoreboardWidth = scoreboardRatio * screenW;
    float scoreboardLeft = (screenW - scoreboardWidth) / 2.0f;
    float scoreboardRight = scoreboardLeft + scoreboardWidth;
    float scoreboardTop = screenH * 0.275f;

    // Box dimensions (relative to screen size)
    float boxWidth = screenW * 0.18f;
    float boxHeight = screenH * 0.45f;
    float boxGap = screenW * 0.01f;

    // Use int explicitly for Vector2
    Vector2 boxStart(static_cast<int>(scoreboardRight + boxGap),
        static_cast<int>(scoreboardTop));
    Vector2 boxEnd(static_cast<int>(boxStart.X + boxWidth),
        static_cast<int>(boxStart.Y + boxHeight));

    // Draw box
    canvas.SetColor(0, 0, 0, alphaBox);
    canvas.DrawRect(boxStart, boxEnd);

    // Draw Playlist and current MMR
    Vector2 drawPos;
    drawPos.X = boxStart.X + 5;
    drawPos.Y = boxStart.Y + 5;
    canvas.SetColor(255, 255, 255, alphaText);
    canvas.SetPosition(drawPos);
	canvas.DrawString("Test");

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
