#pragma once

#include "../include/SDL.h"
#include "../include/SDL_ttf.h"
#include <string>

extern SDL_Window*   window;
extern SDL_Renderer* renderer;
extern TTF_Font*     font;

// this is not graphics but.........
static auto zAssert = [&](bool isOk, const std::string& what)
{
	if (isOk == false)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error!", what.c_str(), nullptr);
		throw std::string(what);
	}
};