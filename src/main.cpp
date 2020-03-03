#include <iostream>
#include <ctime>
#include <functional>
#include <vector>
#include <string>

#include "core.h"

#include "vector.h"
#include "map.h"

#include "kcm.h"
#include "kcm_sdl.h"

#include "body.h"

#include "mods_list.h"

#define MAJOR_VERSION     0
#define MINOR_VERSION     4
#define SUB_MINOR_VERSION 6


#define FOR_ALL_MODS(x) for (auto& mod : modList) x

#undef main
int main(void)
{
	std::cout << "BlueCubic v" << MAJOR_VERSION <<
		'.' << MINOR_VERSION;

#if SUB_MINOR_VERSION != 0
	std::cout << '.' << SUB_MINOR_VERSION;
#endif

	std::cout << std::endl << std::endl;


	if (modList.empty() == false)
	{
		std::vector<Mod*> nModList;

		std::cout << '\a' <<
			"BlueCubic ModLoader v1.0\n"
			"There is a " << modList.size() << " mods.\n";

		for(register size_t i = 0; i < modList.size(); ++i)
		{
			auto& mod = modList[i];
			std::cout <<
				"[*] " << mod->meta.name <<
				' ' << mod->meta.version << ": " << mod->meta.description << '\n';
			std::cout << "\tLoad it? (Y/N): ";

			char entered;
			std::cin >> entered;

			if (tolower(entered) == 'y')
				nModList.push_back(mod);
		}

		modList = nModList;
	}

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	FOR_ALL_MODS(mod->preLoad());

	levelGenerator->generate();

	font     = kcmCreateFont(fontFile, fontSize);
	
	window   = SDL_CreateWindow("BlueCubic", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 650, 650, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	zAssert(font,     TTF_GetError());
	zAssert(window,   SDL_GetError());
	zAssert(renderer, SDL_GetError());

	FOR_ALL_MODS(mod->load());

	while (true)
	{
		map.display();
		body->display();

		FOR_ALL_MODS(mod->render());

		renderPresent();
		delay(100 / 6);

		auto state = kcmGetKeyboardState();
	
		if (state[SDL_SCANCODE_SPACE])
			body->jump();

		if (state[SDL_SCANCODE_A] || state[SDL_SCANCODE_LEFT])
			body->turnLeft();

		if (state[SDL_SCANCODE_D] || state[SDL_SCANCODE_RIGHT])
			body->turnRight();

		SDL_Event event;

		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				FOR_ALL_MODS(mod->destroy());
				return 0;
				break;

			default:
				break;
			}
		}

		body->lRect = body->rect;
		body->calc();

		FOR_ALL_MODS(mod->tick());
	}

    std::cout << "Hello World!\n";
}