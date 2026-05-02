#include "util/MemoryStats.h"

#if defined(_WIN32) // should only be used with Microsoft platforms
#include <Windows.h>

#include <psapi.h>

using namespace ARL;
using namespace ARL::MemoryStats;

namespace ARL {
	namespace MemoryStats {
		MEMORYSTATUSEX globalMemoryStatusEx() {
			MEMORYSTATUSEX statex;
			statex.dwLength = sizeof(statex);
			GlobalMemoryStatusEx(&statex);
			return statex;
		}

		DWORDLONG usedMemoryBytes() {
			PROCESS_MEMORY_COUNTERS pmc;
			GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
			return pmc.WorkingSetSize;
		}

		DWORDLONG freeMemoryBytes() {
			MEMORYSTATUSEX statex = globalMemoryStatusEx();
			return statex.ullAvailPhys;
		}

		DWORDLONG totalMemoryBytes() {
            MEMORYSTATUSEX statex = globalMemoryStatusEx();
            return statex.ullTotalPhys;
		}
	}
}
#endif // defined(_WIN32)
