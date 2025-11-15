#include "pch.h"
#include "GameType.h"

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
	default:	return "Game Type: " + std::to_string(gameType);
	}
}