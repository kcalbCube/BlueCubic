#include "kcm_sdl.h"

Point::Point(int x, int y)
	: point{ x, y } {}

Point::Point(void) {}

Point::Point(const SDL_Point& point_)
	: point{ point_ } {}

Point::operator const SDL_Point* (void) const
{
	return &point;
}

Point::operator SDL_Point(void)
{
	return point;
}

Rect::Rect(int x, int y, int w, int h)
	: rect{ x, y, w, h } {}

Rect::Rect(void) {}

Rect::Rect(const SDL_Rect& rectangle)
	: rect{ rectangle } {}

Rect::operator const SDL_Rect* (void) const
{
	return &rect;
}

Rect::operator SDL_Rect(void)
{
	return rect;
}

bool isPointInRect(const Point& point, const Rect& rect)
{
	return SDL_PointInRect(point, rect);
}

void renderPresent(void)
{
	SDL_RenderPresent(renderer);
}

Color::Color(unsigned long hexColor)
{
	red   = ((hexColor >> 16) & 0xFF);
	green = ((hexColor >> 8) & 0xFF);
	blue  = (hexColor & 0xFF);
}

Color::Color(int r, int g, int b)
	: red{ r }, green{ g }, blue{ b } {}

Color::Color(void) {}

/*
Color& Color::operator=(unsigned long hexColor)
{
	red = hexColor & 0xFF0000;
	green = hexColor & 0x00FF00;
	blue = hexColor & 0x0000FF;

	red >> (8 << 2 << 2);
	green >> (8 << 2);
}
*/

bool Color::operator==(const Color& color) const
{
	return red == color.red
		&& green == color.green
		&& blue == color.blue;
}

bool Color::operator!=(const Color& color) const
{
	return !(*this == color);
}

BackupColor::BackupColor(void)
{
	color = getRenderDrawColor();
}

BackupColor::~BackupColor(void)
{
	setRenderDrawColor(color);
}

Color getRenderDrawColor(void)
{
	Color toReturn; Uint8 ook;

	SDL_GetRenderDrawColor(renderer, &toReturn.redUint8,
		&toReturn.greenUint8, &toReturn.blueUint8, &ook);

	return toReturn;
}

void setRenderDrawColor(const Color& color)
{
	SDL_SetRenderDrawColor(renderer, color.red,
		color.green, color.blue, SDL_ALPHA_OPAQUE);
}

void renderClear(const Color& color)
{
	BackupColor backupColor;

	if (color != NONCOLOR)
		setRenderDrawColor(color);

	SDL_RenderClear(renderer);
}

void fillRect(const Rect& rect, const Color& color)
{
	BackupColor backupColor;

	if (color != NONCOLOR)
		setRenderDrawColor(color);

	SDL_RenderFillRect(renderer, rect);
}

void delay(unsigned int ms)
{
	SDL_Delay(ms);
}