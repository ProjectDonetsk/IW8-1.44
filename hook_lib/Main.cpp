#include "Main.hpp"
#include <fstream>
#include "game_inc.h"

//printf colors stolen from github
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define WHITEBOLD "\033[1;37m"
#define YELLUL "\033[4;33m"
#define UNDERLINERED "\033[4;31m"

//utils::hook::detour dvar_registerbool;
dvar_t* Dvar_RegisterBool_Detour(const char* dvarName, bool value, unsigned int flags, const char* description)
{
	volatile static bool onceCalled = false;
	if (onceCalled == false)
	{
		puts("it got called & detoured...");
		onceCalled = true;
	}

	if (strcmp(dvarName, "LSTQOKLTRN") == 0) {
		printf("dvar LSTQOKLTRN registered!\n");
		value = true;
	}
	if (strcmp(dvarName, "MPSSOTQQPM") == 0) {                //LSSRRSMNMR
		printf("dvar MPSSOTQQPM registered!\n");
		value = true;

	}
	if (strcmp(dvarName,"LSSRRSMNMR") == 0) {
		printf("dev cheats are enabled !");
			value = true;
	}
	dvar_t* ret = dvar_registerbool.stub<dvar_t*>(dvarName, value, flags, description);
	return ret;
}

void lua_pushboolean(uintptr_t luaState, int boolean)
{
	auto func = reinterpret_cast<void(*)(uintptr_t luaState, int boolean)>(0x6BD9C10_b);
	func(luaState, boolean);
}

uintptr_t get_bnet_class()
{
	return 0x9BF08B0_b;
}

struct XUID {
	unsigned __int64 m_id;

	XUID* RandomXUID();

	bool operator !=(const XUID* xuid);
	XUID* operator =(const XUID* xuid);
	bool operator ==(const XUID* xuid);

};

unsigned int* GetRandSeed()
{
	static unsigned int seed = 0x89ABCDEF;
	return &seed;
}

unsigned __int64 Sys_Microseconds()
{
	auto func = reinterpret_cast<unsigned __int64(*)(void)>(0x3B3F910_b);
	return func();
}

int I_irand(int min, int max)
{
	auto func = reinterpret_cast<int(*)(int min, int max)>(0x39E2BC0_b);
	return func(min, max);
}

XUID* XUID::RandomXUID()
{
	unsigned int* RandSeed;
	unsigned int BackupRandSeed;
	this->m_id = 0;
	RandSeed = GetRandSeed();
	BackupRandSeed = *RandSeed;
	*RandSeed = Sys_Microseconds();
	this->m_id = I_irand(1, 0x7FFFFFFF);
	*RandSeed = BackupRandSeed;
	return this;
}

void LUI_OpenMenu(uintptr_t localclientnum, const char* menuName, int isPopup, int isModal, int isExclusive)
{
	auto func = reinterpret_cast<void(*)(uintptr_t localclientnum, const char* menuName, int isPopup, int isModal, int isExclusive)>(0x669F9F0_b);
	func(localclientnum, menuName, isPopup, isModal, isExclusive);
}

void delayedStuff()
{
	while (1)
	{
		if (GetAsyncKeyState('H') & 0x8000)
		{
			const char* menuName = "MainMenu";
			printf("LUI_OpenMenu(0, \"%s\", true, false, false);\n", menuName);
			LUI_OpenMenu(0, menuName, true, false, false);
			Sleep(1000);
		}
	}
}

dvar_t* Dvar_RegisterBool(const char* dvarName, bool value, int flags, const char* desc)
{
	auto func = reinterpret_cast<dvar_t*(*)(const char* dvarName, bool value, int flags, const char* desc)>(0x39F4ED0_b);
	return func(dvarName, value, flags, desc);
}

bool Live_IsUserSignedIn_Detour(int unk);

int iTick = 0;
bool bFinished;
bool btoggle;
//utils::hook::detour r_endframe;
void R_EndFrame_Detour()
{
	if (!bFinished) {
		if (iTick == 500) {
			XUID xuid;
			xuid.RandomXUID();
			printf("xuid: %llu\n", xuid.m_id);

			utils::hook::set(0x9BF0B80_b, 1);

			utils::hook::set<uintptr_t>(0x1BB7F608_b, 0x11CB1243B8D7C31E | xuid.m_id * xuid.m_id);

			utils::hook::set<bool>(0x17F51812_b, true);

			utils::hook::set<uintptr_t>(0x17AF9960_b, 0x11CB1243B8D7C31E | (xuid.m_id * xuid.m_id) / 6); // s_presenceData

			utils::hook::set<int>(0x17673F00_b, 1);
			utils::hook::set(0x17AF98A0_b, 2);
			utils::hook::set(0x9BF0B80_b, 1);

			utils::hook::set<byte>(0x1935A820_b, 0); // dvar

			utils::hook::set<char>(*reinterpret_cast<uintptr_t*>(0x15DDB818_b) + 0x28, 1); // force_offline_enabled 15DDB818 //20ACEE949EB 
			utils::hook::set<char>(*reinterpret_cast<uintptr_t*>(0x15DDB820_b) + 0x28, 1);// force_offline_menus 15DDB820

			uintptr_t bnet_class = get_bnet_class();
			*(uintptr_t*)(bnet_class) = 2; // brings us to "connect to services" screen
			*(bool*)(bnet_class + 0x2D0) = true;

			*(DWORD*)(bnet_class + 0x2F4) = 0x795230F0;
			*(DWORD*)(bnet_class + 0x2FC) = 0;
			*(BYTE*)(bnet_class + 0x2F8) = 31;

			// utils::hook::jump(0x3A21F80_b, Live_IsUserSignedIn_Detour);

			printf(RESET GREEN "[+] " RESET UNDERLINERED "LOADED!\n" RESET CYAN);
			bFinished = true;

			CreateThread(0, 0x0, (LPTHREAD_START_ROUTINE)delayedStuff, 0, 0, 0);
		}
		else {
			iTick += 1;
		}
	}

	r_endframe.stub<void>();
}

bool Live_IsUserSignedIn_Detour(int unk)
{
	return true;
}

bool Live_IsUserSignedInToDemonware_Detour()
{
	return true;
}

int dwGetLogOnStatus_Detour()
{
	return 2;
}

int LiveStorage_GetActiveStatsSource_Detour()
{
	return 1;
}

int LUI_CoD_LuaCall_IsUserSignedInToLive_Detour(uintptr_t luaState) // 0x6294930_b
{
	lua_pushboolean(luaState, 1);
	return 1;
}

int LUI_CoD_LuaCall_IsUserSignedInToDemonware_Detour(uintptr_t luaState) // 0x62949F0_b
{
	lua_pushboolean(luaState, 1);
	return 1;
}

bool IsUserSignedInToBnet_Detour(int controllerIndex, int* onlinePlayFailReason) // guessed name
{
	*onlinePlayFailReason = 0; // OPFR_NONE
	return true;
}

bool GamerProfile_IsProfileLoggedIn_Detour(int unk)
{
	return true;
}

const char* username_Detour()
{
	return "Pipes";
}

const char* SEH_StringEd_GetString_Detour(const char* str)
{
	return str;
}

bool Content_DoWeHaveContentPack_Detour(int unk1)
{
	return true;
}

void entry_point()
{
	utils::hook::jump(0x3D61700_b, Live_IsUserSignedInToDemonware_Detour);
	utils::hook::jump(0x5D6ACA0_b, dwGetLogOnStatus_Detour);
	utils::hook::jump(0x4647860_b, IsUserSignedInToBnet_Detour);
	utils::hook::jump(0x425B3C0_b, GamerProfile_IsProfileLoggedIn_Detour);
	// utils::hook::jump(0x3A21F80_b, Live_IsUserSignedIn_Detour);
	utils::hook::jump(0x33E3E00_b, LiveStorage_GetActiveStatsSource_Detour);

	utils::hook::jump(0x6294930_b, LUI_CoD_LuaCall_IsUserSignedInToLive_Detour);
	utils::hook::jump(0x62949F0_b, LUI_CoD_LuaCall_IsUserSignedInToDemonware_Detour);

	r_endframe.create(0x607B240_b, R_EndFrame_Detour);
	utils::hook::jump(0x3A21B20_b, username_Detour);

	utils::hook::call(0x3414D77_b, Dvar_RegisterBool_Detour);
	utils::hook::call(0x3414D92_b, Dvar_RegisterBool_Detour);

	utils::hook::jump(0x39EA080_b, Content_DoWeHaveContentPack_Detour);

	//utils::hook::jump(0x39B2F10_b, SEH_StringEd_GetString_Detour);

	/*utils::hook::nop(0x5EFA36E_b, 6);
	utils::hook::call(0x5EFA36E_b, LoadLibraryW_Stub);*/

	puts(RESET GREEN "[+] " RESET WHITEBOLD __FUNCTION__ " done." RESET CYAN);
}

extern "C" __declspec(dllexport) int DiscordCreate()
{
	CreateThread(0, 0xA0, (LPTHREAD_START_ROUTINE)entry_point, 0, 0, 0);

	puts(RESET GREEN "[+] " RESET WHITEBOLD __FUNCTION__ " done." RESET CYAN);
	return 1;
}

BOOL IsDebuggerPresent_Detour()
{
	puts("IsDebuggerPresent()...");
	return FALSE;
}


BOOL WINAPI DllMain(HMODULE hModule, DWORD Reason, LPVOID lpVoid)
{
	g_Addrs.ModuleBase = (uintptr_t)(GetModuleHandleA(NULL));
	if (Reason == DLL_PROCESS_ATTACH)
	{
		DisableThreadLibraryCalls(hModule);
		HANDLE hCmd = createConsole();
		if (hCmd == NULL)
		{
			MessageBoxA(NULL, "Couldn't create console.", "IW8 1.44.0", MB_ICONERROR | MB_OK | MB_DEFBUTTON1);
		}
		printf(GREEN "[+]" RESET WHITEBOLD " Hello, world!\n" RESET);
		printf(GREEN "[+]" RESET WHITEBOLD " Base EXE Address: " RESET YELLUL"0x%p\n" , g_Addrs.ModuleBase);
		printf(RESET GREEN "[+]" RESET WHITEBOLD " You are playing as:" RESET MAGENTA " %s\n", username_Detour() );
		printf(RESET GREEN "[+]" RESET BLUE " Initializing...\n" RESET);
		printf(CYAN);
	}

	return TRUE;
}

std::pair<void**, void*> patch_import(const std::string& lib, const std::string& func, void* function)
{
	static const utils::nt::library game{};

	const auto game_entry = game.get_iat_entry(lib, func);
	if (!game_entry)
	{
		throw std::runtime_error("Import '" + func + "' not found!");
	}

	const auto original_import = game_entry;
	utils::hook::set(game_entry, function);
	return { game_entry, original_import };
}

uintptr_t find_pattern(const char* module_name, const char* pattern) {
	const auto get_module_size = [=](uintptr_t module_base)
		{
			return reinterpret_cast<PIMAGE_NT_HEADERS>(module_base + reinterpret_cast<PIMAGE_DOS_HEADER>(module_base)->e_lfanew)->OptionalHeader.SizeOfImage;
		};
	const auto module_start = (uintptr_t)GetModuleHandle(module_name);
	if (module_start != 0ULL)
	{
		const auto module_end = module_start + get_module_size(module_start);

		const char* pattern_current = pattern;
		uintptr_t current_match = NULL;

		MEMORY_BASIC_INFORMATION64 page_information = {};
		for (auto current_page = reinterpret_cast<unsigned char*>(module_start); current_page < reinterpret_cast<unsigned char*>(module_end); current_page = reinterpret_cast<unsigned char*>(page_information.BaseAddress + page_information.RegionSize))
		{
			VirtualQuery(reinterpret_cast<LPCVOID>(current_page), reinterpret_cast<PMEMORY_BASIC_INFORMATION>(&page_information), sizeof(MEMORY_BASIC_INFORMATION));
			if (page_information.Protect == PAGE_NOACCESS)
				continue;

			if (page_information.State != MEM_COMMIT)
				continue;

			if (page_information.Protect & PAGE_GUARD)
				continue;

			for (auto current_address = reinterpret_cast<unsigned char*>(page_information.BaseAddress); current_address < reinterpret_cast<unsigned char*>(page_information.BaseAddress + page_information.RegionSize - 0x8); current_address++)
			{
				if (*current_address != GET_BYTE(pattern_current) && *pattern_current != '\?') {
					current_match = 0ULL;
					pattern_current = pattern;
					continue;
				}

				if (!current_match)
					current_match = reinterpret_cast<uintptr_t>(current_address);

				pattern_current += 3;
				if (pattern_current[-1] == NULL)
					return current_match;
			}
		}
	}

	return 0ULL;
}

uintptr_t find_pattern(uintptr_t start, const char* module_name, const char* pattern) {
	const auto get_module_size = [=](uintptr_t module_base)
		{
			return reinterpret_cast<PIMAGE_NT_HEADERS>(module_base + reinterpret_cast<PIMAGE_DOS_HEADER>(module_base)->e_lfanew)->OptionalHeader.SizeOfImage;
		};
	const auto module_start = start;
	if (module_start != 0ULL)
	{
		const auto module_end = module_start + get_module_size(module_start);

		const char* pattern_current = pattern;
		uintptr_t current_match = NULL;

		MEMORY_BASIC_INFORMATION64 page_information = {};
		for (auto current_page = reinterpret_cast<unsigned char*>(module_start); current_page < reinterpret_cast<unsigned char*>(module_end); current_page = reinterpret_cast<unsigned char*>(page_information.BaseAddress + page_information.RegionSize))
		{
			VirtualQuery(reinterpret_cast<LPCVOID>(current_page), reinterpret_cast<PMEMORY_BASIC_INFORMATION>(&page_information), sizeof(MEMORY_BASIC_INFORMATION));
			if (page_information.Protect == PAGE_NOACCESS)
				continue;

			if (page_information.State != MEM_COMMIT)
				continue;

			if (page_information.Protect & PAGE_GUARD)
				continue;

			for (auto current_address = reinterpret_cast<unsigned char*>(page_information.BaseAddress); current_address < reinterpret_cast<unsigned char*>(page_information.BaseAddress + page_information.RegionSize - 0x8); current_address++)
			{
				if (*current_address != GET_BYTE(pattern_current) && *pattern_current != '\?') {
					current_match = 0ULL;
					pattern_current = pattern;
					continue;
				}

				if (!current_match)
					current_match = reinterpret_cast<uintptr_t>(current_address);

				pattern_current += 3;
				if (pattern_current[-1] == NULL)
					return current_match;
			}
		}
	}

	return 0ULL;
}

size_t operator"" _b(const size_t val)
{
	return base + val;
}

size_t reverse_b(const size_t val)
{
	return val - base;
}

//size_t reverse_b(const void* val)
//{
//	return reverse_b(reinterpret_cast<size_t>(val));
//}

size_t operator"" _g(const size_t val)
{
	return base + (val - 0x140000000);
}

size_t reverse_g(const size_t val)
{
	return (val - base) + 0x140000000;
}

size_t reverse_g(const void* val)
{
	return reverse_g(reinterpret_cast<size_t>(val));
}

HANDLE createConsole()
{
	AllocConsole();

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	auto a = freopen("CONOUT$", "w", stdout);
	auto b = freopen("CONOUT$", "w", stderr);
	auto c = freopen("CONIN$", "r", stdin);
	if (a == NULL || b == NULL || c == NULL)
	{
		return NULL;
	}

	SetConsoleTitleA("IW8 1.44.0 - KURVA");

	DWORD consoleMode;
	GetConsoleMode(consoleHandle, &consoleMode);
	SetConsoleMode(consoleHandle, consoleMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

	return consoleHandle;
}

void printSig(std::string name, void* address, size_t len)
{
	std::cout << name << " '";
	unsigned char* ptr = static_cast<unsigned char*>(address);
	for (size_t i = 0; i < len; ++i)
	{
		std::cout << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(ptr[i]);
		if (i < len - 1)
			std::cout << ' ';
	}
	std::cout << "'" << std::dec << std::endl;
}

bool isSubStr(std::string str, std::string subStr)
{
	size_t pos = str.find(subStr);
	if (pos != std::string::npos)
	{
		return true;
	}
	return false;
}

float strToFloat(const std::string& str)
{
	float num = 0.0f;
	float fraction = 0.1f;
	bool isNegative = false;

	size_t i = 0;
	if (str[i] == '-')
	{
		isNegative = true;
		i++;
	}

	for (; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num = num * 10.0f + static_cast<float>(str[i] - '0');
		}
		else if (str[i] == '.')
		{
			i++;
			break;
		}
		else
		{
			break;
		}
	}

	for (; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num += (str[i] - '0') * fraction;
			fraction *= 0.1f;
		}
		else
		{
			break;
		}
	}

	if (isNegative)
	{
		num = -num;
	}

	return num;
}

//stuff...