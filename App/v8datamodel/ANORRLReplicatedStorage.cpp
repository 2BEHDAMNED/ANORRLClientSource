#include "stdafx.h"

#include "v8datamodel/ANORRLReplicatedStorage.h"

using namespace ARL;

const char* const ARL::sANORRLReplicatedStorage = "ANORRLReplicatedStorage";

ANORRLReplicatedStorage::ANORRLReplicatedStorage(void)
{
	setName(sANORRLReplicatedStorage);
	setANORRLLocked(true);
}
