#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include <list>

#include "core.h"

#include "vector.h"
#include "map.h"

extern Vector gravity;

extern std::string fontFile;
extern unsigned int fontSize;

void displayText(const std::string& str, SDL_Color color, const SDL_Rect& rect);

void displayText(const std::string& str, SDL_Color color, int x, int y);

void sdisplayText(TTF_Font* font, const std::string& str,
	SDL_Color color, const SDL_Rect& rect);

void sdisplayText(TTF_Font* font, const std::string& str,
	SDL_Color color, int x, int y);

class TextLocation : public ILocation
{
	SDL_Color color;
	std::string text;
	TTF_Font* font;
public:

	TextLocation(const std::string& tex, SDL_Color col, TTF_Font* fon=::font)
		: text{ tex }, color{ col }, font{ fon } {}

	virtual void display(void);

};
// Set gravity.
void setGravity(const Vector& vector);

// Set font file.
void setFontFile(const std::string& file);

// Set font size.
void setFontSize(int size);

// Push location in level(map).
// example: kcmPushLocation(new ColorLocation({255}));
void kcmPushLocation(ILocation* location);

// interface for level generators.
// see kcmSetLevelGenerator example.
class ILevelGenerator
{
public:

	// generate locations.
	// example:
	// virtual void generate(void)
	// {
	//		kcmPushLocation(new ColorLocation({}));
	// }
	virtual void generate(void) {}
};

class StandartLevelGenerator : public ILevelGenerator
{
public:
	virtual void generate(void);
};

static ILevelGenerator* levelGenerator = new StandartLevelGenerator();

// example:
// class RedLevel : public ILevelGenerator
// { ... }
// 
// * in preload function *
// kcmSetLevelGenerator(new RedLevel());
void kcmSetLevelGenerator(ILevelGenerator* levGenerator);

TTF_Font* kcmCreateFont(const std::string& font, int size);

class Mod;
extern std::vector<Mod*> modList;

// Mod class.
// example: class RedCubic : public Mod {...} redCubic; 
// !!! always make object of your mod class
class Mod
{
public:

	// Mod metainfo.
	// Init it in constructor.
	struct Metainfo
	{
		std::string
			name,
			description,
			version;
	} meta;

	Mod(void)
	{
		modList.push_back(this);
	}

	// before graphic / font initializing
	// Use for example
	// for initializing custom level generator
	virtual void preLoad(void) {}

	// before main loop.
	// Use for example for change body.
	virtual void load(void) {}

	// function FOR RENDER ONLY.
	virtual void render(void) {}

	// at main loop, after all actions.
	// Use for example for keyboard / mouse 
	// handling
	virtual void tick(void) {}

	// at destroy.
	// Use for say bye or etc.
	virtual void destroy(void) {}
};