#include "kcm.h"

Vector gravity = { 0, -0.25 };

std::string fontFile = "font.ttf";
unsigned int fontSize = 12;

// Set gravity.
void setGravity(const Vector& vector)
{
	gravity = vector;
}

// Set font file.
void setFontFile(const std::string& file)
{
	fontFile = file;
}

// Set font size.
void setFontSize(int size)
{
	fontSize = size;
}

void kcmPushLocation(ILocation* location)
{
	map.locations.push_back(location);
}

void kcmSetLevelGenerator(ILevelGenerator* levGenerator)
{
	levelGenerator = levGenerator;
}

void StandartLevelGenerator::generate(void)
{
	kcmPushLocation(new ColorLocation({ 0, 150 }));
	kcmPushLocation(new ColorLocation({ 255 }));
	kcmPushLocation(new ColorLocation({ 150, 0 }));
}


TTF_Font* kcmCreateFont(const std::string& font, int size)
{
	return TTF_OpenFont(font.c_str(), size);
}

std::vector<Mod*> modList;
