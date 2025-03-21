#include "functions.hpp"
#include <cstdlib>

void* RtlAddVectoredExceptionHandler(LONG First, PVECTORED_EXCEPTION_HANDLER Handler) {
	utils::nt::library ntdll("ntdll.dll");
	ntdll.invoke<void*>("RtlAddVectoredExceptionHandler", First, Handler);
	return nullptr;
}

NTSTATUS NtContinue(PCONTEXT threadContext, BOOLEAN raiseAlert) {
	utils::nt::library ntdll("ntdll.dll");
	return ntdll.invoke<NTSTATUS>("NtContinue", threadContext, raiseAlert);
}

ULONG64 randomULongLong(ULONG64 min, ULONG64 max)
{
    unsigned long r = rand();
    unsigned long m = lround((double)(max - min) / ((double)RAND_MAX / 10.0)); // Calculate the ratio of RAND_MAX to 10 (to get a more even distribution)
    ULONG64 result;

    srand(r); // Seed the random number generator with the current time

    if ((min <= r && r < max) || (max - min <= r && r < max))
    {
        result = r;
    }
    else
    {
        result = rand() % (max - min + 1); // Generate a random number between min and max, inclusive
    }

    return result;
}

#pragma region //game functions



#pragma endregion

Addresses g_Addrs;