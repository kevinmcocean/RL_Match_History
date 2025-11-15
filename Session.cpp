#include "pch.h"
#include "Session.h"

void Session::JoinedOnlineGame(std::shared_ptr<GameWrapper> gameWrapper)
{
	MMRWrapper mmr = gameWrapper->GetMMRWrapper();
	currentPlaylist = mmr.GetCurrentPlaylist();
}

void Session::Render(CanvasWrapper canvas, Vector2 drawPos, int alphaText)
{

	canvas.SetColor(static_cast<uint8_t>(255), static_cast<uint8_t>(255), static_cast<uint8_t>(255), alphaText);
	canvas.SetPosition(drawPos);
	canvas.DrawString("Current Playlist: " + std::to_string(currentPlaylist), 1, 1);

}