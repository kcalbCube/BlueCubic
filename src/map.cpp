#include "map.h"
#include <SDL_ttf.h>
#include <cassert>

ILocation*& Map::getCur(void)
{
	return locations[cur];
}

void Map::operator+(void)
{
	++cur;
	if (cur >= locations.size())
		cur = locations.size() - 1;
}

void Map::operator-(void)
{
	--cur;
	if (cur < 0)
		cur = 0;
}

bool Map::isCurLeft(void) const
{
	return cur == 0;
}

bool Map::isCurRight(void) const
{
	return cur == (locations.size() - 1);
}

void Map::display(void)
{
	locations[cur]->display();
}



void ColorLocation::display(void)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_RenderClear(renderer);
}



Map map({});