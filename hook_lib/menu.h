#pragma once
#include "framework.h"
#include "globals.h"
#include "sdk.h"
#include "ui.h"

extern ImFont* MainCaps;
extern ImFont* mainFeatureFBold;
extern ImFont* g_pAwesome;
extern ImFont* Main;
extern ImFont* FMenu;
extern ImFont* BigFont;
extern ImFont* mainfont;
extern ImFont* mainfontBig;
extern ImFont* icons;
extern ImFont* icons2;
extern ImFont* mainF;
extern ImFont* mainFBold;
extern ImFont* ChildTitle;

class AIO
{
public:
	void MENUSHOW();
};

void TextCentered(std::string text);
void throwImGuiError(std::string text, bool* disable);