#include "pch.h"
#include "Session.h"
#include "DrawStats.h"

Session::Session(std::shared_ptr<GameWrapper> gameWrapper) {
	std::string path = gameWrapper->GetDataFolder().string() + "/match_history.db";
	db = std::make_shared<Database>(path);
}

GameType& Session::getOrCreateGameType(int playlist, float currentMMR)
{
	for (auto& gameType : gameTypes)
	{
		if (gameType.getPlaylist() == playlist)
		{
			gameType.SetCurrentMMR(currentMMR);
			return gameType;
		}
	}
	gameTypes.emplace_back(playlist, currentMMR);
	return gameTypes.back();
}

void Session::GameEnded(std::shared_ptr<GameWrapper> gameWrapper)
{

	currentGameType.GameEnded(gameWrapper, db);
}

void Session::JoinedOnlineGame(std::shared_ptr<GameWrapper> gameWrapper)
{
	MMRWrapper mmr = gameWrapper->GetMMRWrapper();
	currentPlaylist = mmr.GetCurrentPlaylist();
	float currentMMR = mmr.GetPlayerMMR(gameWrapper->GetUniqueID(), currentPlaylist);
	currentGameType = getOrCreateGameType(currentPlaylist, currentMMR);
}

void Session::Render(DrawStats& drawStats)
{
	
	currentGameType.Render(drawStats);

}