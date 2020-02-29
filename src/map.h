#pragma once

#include <SDL.h>
#include <vector>
#include <string>
#include <SDL_ttf.h>
#include "core.h"
class ILocation
{
public:
	virtual void display(void) {}
};

class ColorLocation : public ILocation
{
	SDL_Color color;
public:
	ColorLocation(SDL_Color col) : color{ col } {}

	virtual void display(void);
};



class Map
{
public:
	std::vector<ILocation*> locations;
	Map(const std::vector<ILocation*>& locs) : locations{ locs } {}

	size_t cur = 0;

	ILocation*& getCur(void);

	void operator+(void);

	void operator-(void);

	bool isCurLeft(void) const;

	bool isCurRight(void) const;

	void display(void);

};

#define RIGHT +
#define LEFT  -

extern Map map;