#pragma once
#ifndef GLOBAL_H
#define GLOBAL_H
#include "framework.h"
#include "color.h"

typedef struct _settings
{
	bool open = true;
	bool b_map = false;
	bool b_fov = false;
	bool b_heart = false;
	bool b_unlock = false;
	bool b_camo = false;
	bool b_tut = false;
	bool b_fps = false;
	bool b_priv = false;
	bool b_no_flashbang = false;
	bool b_custom_clantag = false;
	bool b_brightmax = false;
	bool b_Thirdperson = false;
	bool b_sThirdperson = false;
	bool b_sprint = false;
	bool b_test = false;
	bool b_shield = false;
	bool b_no_fog = false;
	bool b_gun = false;
	bool b_no_stun = false;
	bool b_owner = true;
	bool b_name = false;
	bool chrosshair = false;
	bool b_dynamic3p = false;
	bool b_recoil = false;
	bool inited = false;
	bool b_ingame = false;
	bool b_fpss = false;
	bool b_testing = false;
	bool b_fuckview = false;
	bool b_multiloady = false;
	bool b_nocrosshair = false;
	bool b_spread = false;
	bool b_playlist = false;
	bool b_mploadout = false;

	bool b_box = false;
	bool b_line = false;
	bool b_names = false;
	bool b_crosshair = false;
	bool b_skeleton = false;
	bool b_friendly = false;
	bool b_distance = false;
	bool b_visible = false;
	bool b_visible_only = false;
	bool b_health = false;

	bool b_rainbowmenu = false;
	bool alwayson = true;

	unsigned char tempRainbow[4] = { 255, 0, 0, 0 };

	float f_fov = 1.0f;
	float f_map = 1.0f;
	float bone_size = 2.f; // 0 ~ 5
	float font_size = 16.f;

	int i_score = 1; //1 ~ 5555555555
	int i_timeplayed = 1;
	int i_games = 1; //1 ~ 5555555555
	int i_wins = 1; //1 ~ 5555555555
	int i_kills = 1; //1 ~ 5555555555
	int i_deaths = 1; //1 ~ 5555555555
	int i_downs = 1; //1 ~ 5555555555;
	int i_top5 = 1; //1 ~ 5555555555
	int i_top10 = 1; //1 ~ 5555555555
	int i_top25 = 1; //1 ~ 5555555555
	int i_camo = 1;
	int i_test = 1;
	int i_sndscore = 1;

	//force save
	bool slot1;
	bool slot2;
	bool slot3;
	bool slot4;
	bool slot5;
	bool deletebp;
	std::string name1;
	std::string name2;
	std::string name3;
	std::string name4;
	std::string name5;
	int gamemodeselection;
	int attachselection;
	int current_camo;
	int current_camo2;
	int current_camo3;
	int current_camo4;
	int current_camo5;
	const char* camo_list[22] = { "MW Gold", "MW Platinum", "MW Damascus", "MW Obsidian",  "CW Gold", "CW Diamond", "CW DM-Ultra", "CW ZM Gold", "CW ZM Diamond", "CW ZM Dark Aether", "CW Cherry Blossom", "VG Gold", "VG Diamond", "VG Atomic", "VG ZM Gold", "VG ZM Diamond", "VG ZM Dark Aether", "VG False Prospector", "VG Death Prospector", "VG Titanium Chrome ", "VG Liquid Metal ", "VG Skynet" };
	const char* camo_list2[22] = { "MW Gold", "MW Platinum", "MW Damascus", "MW Obsidian",  "CW Gold", "CW Diamond", "CW DM-Ultra", "CW ZM Gold", "CW ZM Diamond", "CW ZM Dark Aether", "CW Cherry Blossom", "VG Gold", "VG Diamond", "VG Atomic", "VG ZM Gold", "VG ZM Diamond", "VG ZM Dark Aether", "VG False Prospector", "VG Death Prospector", "VG Titanium Chrome ", "VG Liquid Metal ", "VG Skynet" };
	const char* camo_list3[22] = { "MW Gold", "MW Platinum", "MW Damascus", "MW Obsidian",  "CW Gold", "CW Diamond", "CW DM-Ultra", "CW ZM Gold", "CW ZM Diamond", "CW ZM Dark Aether", "CW Cherry Blossom", "VG Gold", "VG Diamond", "VG Atomic", "VG ZM Gold", "VG ZM Diamond", "VG ZM Dark Aether", "VG False Prospector", "VG Death Prospector", "VG Titanium Chrome ", "VG Liquid Metal ", "VG Skynet" };
	const char* camo_list4[22] = { "MW Gold", "MW Platinum", "MW Damascus", "MW Obsidian",  "CW Gold", "CW Diamond", "CW DM-Ultra", "CW ZM Gold", "CW ZM Diamond", "CW ZM Dark Aether", "CW Cherry Blossom", "VG Gold", "VG Diamond", "VG Atomic", "VG ZM Gold", "VG ZM Diamond", "VG ZM Dark Aether", "VG False Prospector", "VG Death Prospector", "VG Titanium Chrome ", "VG Liquid Metal ", "VG Skynet" };
	const char* camo_list5[22] = { "MW Gold", "MW Platinum", "MW Damascus", "MW Obsidian",  "CW Gold", "CW Diamond", "CW DM-Ultra", "CW ZM Gold", "CW ZM Diamond", "CW ZM Dark Aether", "CW Cherry Blossom", "VG Gold", "VG Diamond", "VG Atomic", "VG ZM Gold", "VG ZM Diamond", "VG ZM Dark Aether", "VG False Prospector", "VG Death Prospector", "VG Titanium Chrome ", "VG Liquid Metal ", "VG Skynet" };

	char c_clantag[6];

	struct cfg
	{
		//keybinds
		int i_disablekey;
		int i_menukey;
		int i_menu2key;
		int i_ejectkey;
		int i_unlockallkey;
		int i_reversekey;
		int i_200fovkey;
		int i_chamskey;

		int i_savedop;
		int i_savedexec;
	} cfg;
	//saved for startup

	struct server
	{
		bool unlockall = true;
		bool reverse = true;
		bool spread = true;
		bool recoil = true;
		bool fov = true;
		bool map = true;
		bool forcesave = true;
		bool clan = true;
		bool clanColor = true;
		bool operator1 = true;
		bool classname = true;
		bool camo = true;
		bool equip = true;
		bool dblweapon = true;
		bool modweapon = true;
		bool gesture = true;
		bool chams = true;
		bool nogun = true;
		bool noshield = true;
		bool heartcheat = true;
		bool crosshair = true;
		bool breakcam = true;
		bool fog = true;
		bool drawfps = true;
		bool devplay = true;
		bool skiptut = true;
		bool thirdperson = true;
		bool d3person = true;
		bool forcemp = true;
		bool maxbright = true;
		bool lootcheck = true;
		bool fpsboost = true;
		bool toastjoin = true;
		bool toastleft = true;
		bool chatmsg = true;
		bool charm = true;
		bool sticker = true;
		bool watch = true;
		bool reticle = true;
	} server;

	bool menuInit;

	std::string docuPath;

	utils::color_var crosshair_color = utils::color_var(C_Color(255, 255, 255));
	utils::color_var menu_color = utils::color_var(C_Color(255, 255, 255));

	bool placeholder;
	bool configConnected = true;

	bool visibleOutlines = true;
	bool chams = false;
	bool chamHooked = false;
	bool notVisibleOutlines = true;
	int rendertype = 0;
	bool chamFill = false;
	int lineWidthNum = 1;
	int chamColorRGB;
	unsigned int playerColor;
	unsigned int lootColor;
	bool initFont = false;
	bool lootChams = false;
	bool rgbChams = false;
	bool rgblootChams = false;
	int renderflags;
	int renderflags2;
	bool shellhookenable;
	bool shellhook;
	bool fovhookmenu;

	int gamemode = 0;
	int max_distance = 250;
	int player_max = 1;
	int box_options = 1;
	int bone_index = 1;

	bool fovhookenable;
	bool fovhook;
	float f_fovfunc = 1.6f;

	utils::color_var White = utils::color_var(C_Color(255, 255, 255));
	utils::color_var Black = utils::color_var(C_Color(0, 0, 0));
	utils::color_var Red = utils::color_var(C_Color(255, 0, 0));
	utils::color_var Green = utils::color_var(C_Color(0, 255, 0));
	utils::color_var Blue = utils::color_var(C_Color(0, 0, 255));
	utils::color_var visible_team_color = utils::color_var(C_Color(0, 0, 255));
	utils::color_var visible_box_color = utils::color_var(C_Color(0, 255, 0));
	utils::color_var visible_bone_color = utils::color_var(C_Color(0, 255, 0));
	utils::color_var visible_line_color = utils::color_var(C_Color(0, 255, 0));
	utils::color_var n_visilbe_team_color = utils::color_var(C_Color(255, 255, 255));
	utils::color_var n_visible_box_color = utils::color_var(C_Color(255, 0, 0));
	utils::color_var n_visible_bone_color = utils::color_var(C_Color(255, 0, 0));
	utils::color_var n_visible_line_color = utils::color_var(C_Color(255, 0, 0));
	utils::color_var name_color = utils::color_var(C_Color(255, 255, 0));
	utils::color_var dis_color = utils::color_var(C_Color(255, 255, 0));
	utils::color_var fov_color = utils::color_var(C_Color(255, 255, 255));
	utils::color_var cash_color = utils::color_var(C_Color(0, 255, 0));
	utils::color_var ammo_color = utils::color_var(C_Color(255, 255, 255));
	utils::color_var ammo_create_color = utils::color_var(C_Color(255, 255, 255));
	utils::color_var weapon_color = utils::color_var(C_Color(255, 255, 255));
	utils::color_var ncrate = utils::color_var(C_Color(0, 0, 255));
	utils::color_var lcrate = utils::color_var(C_Color(255, 128, 0));
	utils::color_var mission_color = utils::color_var(C_Color(102, 178, 255));
	utils::color_var killstreak_color = utils::color_var(C_Color(153, 51, 255));

} settings;

typedef struct _offsets
{
	uintptr_t clantag_offset;	
	uintptr_t unlock_offsets;
	uintptr_t ddl_loadasset;
	uintptr_t ddl_getrootstate;
	uintptr_t ddl_getdllbuffer;
	uintptr_t ddl_movetoname;
	uintptr_t ddl_movetopath;
	uintptr_t ddl_setint;
	uintptr_t ddl_getint;
	uintptr_t ddl_setstring;
	uintptr_t a_parse;
	uintptr_t ShowToastNotificationAfterUserJoinedParty;
	uintptr_t StringTable_GetAsset;
	uintptr_t OnlineChatManger_GetInstance;
	uintptr_t sendPlayerEvent;
	uintptr_t DDL_GetType;
	uintptr_t NavigateBlueprintDDL;
	uintptr_t Com_DDL_CreateContext;
	uintptr_t DDL_SetEnum;
	uintptr_t uploadbps;
	uintptr_t notsure;
	uintptr_t Dvar_FindVarByName;
	uintptr_t Dvar_SetBoolInternal;
	uintptr_t Dvar_SetBoolByName;
	uintptr_t Dvar_SetFloat_Internal;
	uintptr_t Dvar_RegisterFloat;
	uintptr_t Dvar_SetInt_Internal;
	uintptr_t Dvar_SetIntByName;
	uintptr_t ShowToastNotificationAfterUserLeftParty;
	uintptr_t inGameOffset;
	uintptr_t playerCountOffset;
	uintptr_t chamOffset;
	uintptr_t gamemode;
	uintptr_t wepStructOffset;
	uintptr_t initDDLState;
	uintptr_t end_bytes;
	uintptr_t ingame;
	uintptr_t logonstatus;

	// new for aimbot/esp
	uintptr_t ref_def_ptr;
	uintptr_t name_array;
	uintptr_t name_array_list;
	uintptr_t camera_base;
	uintptr_t camera_pos;
	uintptr_t local_index;
	uintptr_t local_index_pos;
	uintptr_t recoil;
	uintptr_t game_mode;
	uintptr_t weapon_definitions;
	uintptr_t distribute;
	uintptr_t visible_offset;
	uintptr_t visible;

	uintptr_t player_size;
	uintptr_t player_valid;
	uintptr_t player_pos;
	uintptr_t player_team;
	uintptr_t player_stance;
	uintptr_t player_weapon_index;
	uintptr_t player_dead_1;
	uintptr_t player_dead_2;

	uintptr_t bone_base;
	uintptr_t bone_size;

	uintptr_t client_local_index = 0x0;
	uintptr_t camera_view_x = 0x108;
	uintptr_t camera_view_y = 0x118;
	uintptr_t camera_view_z = 0x128;

	void* rbx_jmp;
	uintptr_t jmp_rbx;
	uintptr_t entitiespos_ptr;
	uintptr_t clientbase_ptr;
	uintptr_t clientinfo_ptr;

	uintptr_t xpartyOffset;
	uintptr_t CbufOffset;

	uintptr_t A_CG_GetViewFovBySpace;
	uintptr_t A_CG_StartShellShock;

	uintptr_t LUI_luaVM;
	uintptr_t LUI_BeginEvent;
	uintptr_t LUI_BeginTable;
	uintptr_t LUI_EndEvent;
	uintptr_t LUI_SetTableBool;
	uintptr_t LUI_SetTableString;
	uintptr_t LUI_SetTableInt;
	uintptr_t LUI_EndTable;

} offsets;

typedef struct _cached
{
	uintptr_t local_ptr = 0;
	uintptr_t player_ptr = 0;
	uintptr_t cached_bone_ptr = 0;
	uintptr_t cached_character_ptr = 0;
	uintptr_t cached_base_ptr = 0;
	uintptr_t cached_entity_ptr = 0;
	uintptr_t inputptr = 0;
	uintptr_t entity_ptr = 0;
	uintptr_t bone_tagPos_ptr = 0;
	uintptr_t current_visible_offset = 0;
	uintptr_t cached_visible_base = 0;
	uintptr_t last_visible_offset = 0;
	int local_team_id = 0;
	int player_team_id = 0;
	int local_index = 0;
	bool b_is_localalive = false;
	bool b_is_playeralive = false;
	bool bone_tagPos = false;
	bool is_friendly = false;

} cached;

typedef struct _global_vars
{
	DWORD procID;
	HWND hWind;
	HANDLE hProc;
	uintptr_t baseModule;
	TCHAR filePath[MAX_PATH];
	uint64_t moduleBase;
	offsets Offest;
	settings Settings;
	cached gcached;
	bool keybinds = true;
	bool steam = false;
} global_vars;

extern global_vars* var;

#endif // !GLOBAL_

