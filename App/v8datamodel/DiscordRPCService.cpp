#include "stdafx.h"

#include "V8DataModel/DiscordRPCService.h"
#include "DiscordHandler.h"

namespace ARL
{
	const char* const sDiscordRPCService = "DiscordRPCService";

	static Reflection::BoundFuncDesc<DiscordRPCService, void(std::string)> func_setState(&DiscordRPCService::setState, "SetState", "state", Security::None);
	static Reflection::BoundFuncDesc<DiscordRPCService,     std::string()> func_getState(&DiscordRPCService::getState, "GetState", Security::None);

	static Reflection::BoundFuncDesc<DiscordRPCService, void(std::string)> func_setDetails(&DiscordRPCService::setDetails, "SetDetails", "details", Security::None);
	static Reflection::BoundFuncDesc<DiscordRPCService,     std::string()> func_getDetails(&DiscordRPCService::getDetails, "GetDetails", Security::None);

	DiscordRPCService::DiscordRPCService()
		:Super()
	{
#ifdef ARL_STUDIO_BUILD
		DiscordHandler::Initialise("1456345979635892400");
#else
#ifndef ARL_RCC_SECURITY
		DiscordHandler::Initialise("1456740539390230609");
#endif
#endif
		this->setName(sDiscordRPCService);
	}

	void DiscordRPCService::setState(std::string value) {
		if (state != value) {
			state = value;
			StandardOut::singleton()->printf(MESSAGE_INFO, "Setting DiscordRPCService->state to %s", state.c_str());
			DiscordHandler::SetState(state);
		}
	}

	void DiscordRPCService::setDetails(std::string value) {
		if (details != value) {
			details = value;
			StandardOut::singleton()->printf(MESSAGE_INFO, "Setting DiscordRPCService->details to %s", details.c_str());
			DiscordHandler::SetDetails(details);
		}
	}
}
