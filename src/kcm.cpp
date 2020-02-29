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
	kcmPushLocation(new TextLocation("BlueCubic!", { 255, 255, 255 }, 
		kcmCreateFont(fontFile, fontSize*4)));

	kcmPushLocation(new ColorLocation({ 150, 0 }));
}

void displayText(const std::string& str, SDL_Color color, const SDL_Rect& rect)
{
	SDL_Surface* surf = TTF_RenderText_Blended(font, str.c_str(), color);
	SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_RenderCopy(renderer, text, nullptr, &rect);

	SDL_DestroyTexture(text);
	SDL_FreeSurface(surf);
}

void displayText(const std::string& str, SDL_Color color, int x, int y)
{
	SDL_Surface* surf = TTF_RenderText_Blended(font, str.c_str(), color);
	SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, surf);


	zAssert(surf, SDL_GetError());
	zAssert(text, SDL_GetError());
	SDL_Rect rect = { x, y };
	SDL_QueryTexture(text, nullptr, nullptr, &rect.w, &rect.h);

	SDL_RenderCopy(renderer, text, nullptr, &rect);

	SDL_DestroyTexture(text);
	SDL_FreeSurface(surf);
}

void sdisplayText(TTF_Font* font, const std::string& str, 
	SDL_Color color, const SDL_Rect& rect)
{
	SDL_Surface* surf = TTF_RenderText_Blended(font, str.c_str(), color);
	SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, surf);

	SDL_RenderCopy(renderer, text, nullptr, &rect);

	SDL_DestroyTexture(text);
	SDL_FreeSurface(surf);
}

void sdisplayText(TTF_Font* font, const std::string& str, 
	SDL_Color color, int x, int y)
{
	SDL_Surface* surf = TTF_RenderText_Blended(font, str.c_str(), color);
	SDL_Texture* text = SDL_CreateTextureFromSurface(renderer, surf);


	zAssert(surf, SDL_GetError());
	zAssert(text, SDL_GetError());
	SDL_Rect rect = { x, y };
	SDL_QueryTexture(text, nullptr, nullptr, &rect.w, &rect.h);

	SDL_RenderCopy(renderer, text, nullptr, &rect);

	SDL_DestroyTexture(text);
	SDL_FreeSurface(surf);
}

void TextLocation::display(void)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);


	sdisplayText(font, text, color, 300, 300);
}

TTF_Font* kcmCreateFont(const std::string& font, int size)
{
	return TTF_OpenFont(font.c_str(), size);
}

std::vector<Mod*> modList;
