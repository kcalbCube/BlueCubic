#pragma once

#include "kcm.h"
#include "core.h"
#include <SDL.h>

class Point
{
public:
	SDL_Point point;

	Point(int x, int y);
	Point(void);
	Point(const SDL_Point& point_);

	operator const SDL_Point* (void) const;
	operator SDL_Point(void);

};

class Rect
{
public:
	SDL_Rect rect;

	Rect(int x, int y, int w, int h);
	Rect(void);
	Rect(const SDL_Rect& rectangle);

	operator const SDL_Rect* (void) const;
	operator SDL_Rect(void);
};

class Color
{
public:

	// ;(
	union
	{
		int red = 0;
		Uint8 redUint8;
	};

	union
	{
		int green = 0;
		Uint8 greenUint8;
	};

	union
	{
		int blue = 0;
		Uint8 blueUint8;
	};


	Color(unsigned long hexColor);
	Color(int r, int g, int b);
	Color(void);

	//Color& operator=(unsigned long hexColor);

	bool operator==(const Color& color) const;

	bool operator!=(const Color& color) const;
};

#define NONCOLOR (Color(-1, -1, -1))

#define BLACK_COLOR (Color(0x0));
#define RED_COLOR   (Color(0xFF0000));
#define GREEN_COLOR (Color(0x00FF00));
#define BLUE_COLOR  (Color(0x0000FF));
#define WHITE_COLOR (Color(0xFFFFFF));

// Saves the current render draw color
// When deconstructs set it to saved value.
class BackupColor
{
	Color color;
public:
	BackupColor(void);
	~BackupColor(void);
};

bool isPointInRect(const Point& point, const Rect& rect);

void renderPresent(void);

Color getRenderDrawColor(void);

void setRenderDrawColor(const Color& color);

void renderClear(const Color& color = NONCOLOR);

void fillRect(const Rect& rect, const Color& color = NONCOLOR);

void delay(unsigned int ms);