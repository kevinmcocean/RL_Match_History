#pragma once

#include "GuiBase.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "version.h"
constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);


class RL_Match_History: public BakkesMod::Plugin::BakkesModPlugin
{
private:
	
	bool scoreboardOpen = false;
	std::string GetGameTypeName(int gameType);;

public:
	virtual void onLoad();
	virtual void onUnload();
	
	void DrawStats(CanvasWrapper canvas);
};
