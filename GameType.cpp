#include "pch.h"
#include "GameType.h"
#include "DrawStats.h"


GameType::GameType(int playlist, float startingMMR)
{
	this->playlist = playlist;
	this->startingMMR = startingMMR;
	this->currentMMR = startingMMR;
	this->previousMMR = startingMMR;
	this->currentStreakMMR = startingMMR;
	this->currentStreak = 0;
}

void GameType::GameEnded(std::shared_ptr<class GameWrapper> gameWrapper) {
	LOG("I DID THIS");
}

std::string GameType::GetGameTypeName(int gameType)
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
	default:	return "Game Type - Playlist #" + std::to_string(gameType);
	}
}

void GameType::Render(DrawStats& drawStats)
{

	// Draw Game Type and Current MMR
	drawStats.DrawWhiteString(GetGameTypeName(playlist) + " (" + std::format("{:.2f}", currentMMR) + ")");

	// Draw MMR Gain/Loss
	drawStats.AddLine();
	drawStats.AdjustDrawPos(38, 0);
	drawStats.DrawWhiteString("MMR:");
	drawStats.AdjustDrawPos(40, 0);
	drawStats.DrawColorStringFloat(currentMMR - startingMMR, std::format("{:.2f}", currentMMR - startingMMR));
	drawStats.AdjustDrawPos(-40 - 38, 0);

	// Draw Last Game MMR Change
	drawStats.AddLine();
	drawStats.DrawWhiteString("Last game:");
	drawStats.AdjustDrawPos(78, 0);
	drawStats.DrawColorStringFloat(currentMMR - previousMMR, std::format("{:.2f}", currentMMR - previousMMR));
	drawStats.AdjustDrawPos(-78, 0);

	// Draw Wins
	drawStats.AddLine();
	drawStats.AdjustDrawPos(37, 0);
	drawStats.DrawWhiteString("Wins:");
	drawStats.AdjustDrawPos(41, 0);
	drawStats.DrawColorStringInt(1, "1");
	drawStats.AdjustDrawPos(-37 - 41, 0);

	// Draw Losses
	drawStats.AddLine();
	drawStats.AdjustDrawPos(24, 0);
	drawStats.DrawWhiteString("Losses:");
	drawStats.AdjustDrawPos(54, 0);
	drawStats.DrawColorStringInt(-1, "1");
	drawStats.AdjustDrawPos(-24 - 54, 0);

	// Draw Streak
	drawStats.AddLine();
	drawStats.AdjustDrawPos(25, 0);
	drawStats.DrawWhiteString("Streak:");
	drawStats.AdjustDrawPos(53, 0);
	drawStats.DrawColorStringInt(currentStreak, std::to_string(currentStreak) + " (" + std::format("{:.2f}", currentMMR - currentStreakMMR) + ")");

	/*
	drawPos.X += 38;
	canvas.SetPosition(drawPos);
	canvas.DrawString("MMR:", 1, 1);
	drawPos.X += 40;
	canvas.SetPosition(drawPos);
	SetColorByValueFloat()
	*/

}