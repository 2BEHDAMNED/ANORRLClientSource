#include "stdafx.h"

#include "DiscordHandler.h"

namespace ARL {

	bool DiscordHandler::initialized = false;
	std::string DiscordHandler::state = std::string("[[ state here ]]");
	std::string DiscordHandler::details = std::string("[[ details here ]]");

	void DiscordHandler::SetDetails(std::string value) {
		//ARL::StandardOut::singleton()->printf(MESSAGE_INFO, "(SetDetails) Initialised -> %s", (initialized ? "true" : "false"));
		if (!initialized)
			return;

		details = value;

		UpdateActivity();
	}

	void DiscordHandler::SetState(std::string value) {
		//ARL::StandardOut::singleton()->printf(MESSAGE_INFO, "(SetState) Initialised -> %s", (initialized ? "true" : "false"));
		if (!initialized)
			return;

		state = value;

		UpdateActivity();
	}

	void DiscordHandler::Initialise(const char* applicationID)
	{
		if (initialized)
			return;

		DiscordEventHandlers handlers;
		memset(&handlers, 0, sizeof(handlers));
		
		Discord_Initialize(applicationID, &handlers, 0, NULL);

		// This is really unsafe but works anyway
		initialized = true;
		UpdateActivity();
	}

	void DiscordHandler::UpdateActivity()
	{
		//ARL::StandardOut::singleton()->printf(MESSAGE_INFO, "(UpdateActivity) Initialised -> %s", (initialized ? "true" : "false"));

		if (!initialized)
			return;

		DiscordRichPresence discordPresence;
		memset(&discordPresence, 0, sizeof(discordPresence));
		discordPresence.state = state.c_str();
		discordPresence.details = details.c_str();
		discordPresence.startTimestamp = std::time(0);
		discordPresence.instance = 1;
		Discord_UpdatePresence(&discordPresence);

		/*discordPresence.endTimestamp = time(0) + 5 * 60;
		discordPresence.largeImageKey = "canary-large";
		discordPresence.smallImageKey = "ptb-small";*/
		
	}

	void DiscordHandler::Shutdown()
	{
		if (!initialized)
			return;

		Discord_ClearPresence();
		Discord_Shutdown();

		initialized = false;
	}
}