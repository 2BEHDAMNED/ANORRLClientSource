#pragma once

#include "V8Tree/Service.h"
#include "V8Tree/Instance.h"

namespace ARL {
	class PartInstance;

	extern const char *const sDiscordRPCService;

	class DiscordRPCService 
		: public DescribedCreatable<DiscordRPCService, Instance, sDiscordRPCService, Reflection::ClassDescriptor::INTERNAL_LOCAL>
		, public Service
	{
	private:
		typedef DescribedCreatable<DiscordRPCService, Instance, sDiscordRPCService, Reflection::ClassDescriptor::INTERNAL_LOCAL> Super;
	public:
		DiscordRPCService();

		void setState(std::string state);
		void setDetails(std::string details);
		void setStartTimestamp(int64_t timestamp);
		void setEndTimestamp(int64_t timestamp);


		/*
		int64_t startTimestamp;
		int64_t endTimestamp;
		const char* largeImageKey;   max 32 bytes
		const char* largeImageText;  max 128 bytes
		const char* smallImageKey;   max 32 bytes
		const char* smallImageText;  max 128 bytes
		const char* partyId;         max 128 bytes
		int partySize;
		int partyMax;
		const char* matchSecret;     max 128 bytes
		const char* joinSecret;      max 128 bytes
		const char* spectateSecret;  max 128 bytes
		*/
	};
}