#pragma once

#include <vector>
#include "kcm_sdl.h"

class Scores : public Mod
{
	TTF_Font* font = nullptr;

public:

	struct Score
	{
		Color color = Color(rand() % 256, rand() % 256, rand() % 256);
		int x = 0, y = 0;
	};

	std::vector<Score> scores;
	int score = 0;

	Scores(void)
	{
		meta.name = "Score";
		meta.version = "1.0";
		meta.description = "Collect scores on all level!";
	}

	virtual void preLoad(void) override
	{
		this->font = kcmCreateFont(fontFile, fontSize * 2);
	}

	virtual void render(void) override
	{
		kcmDisplayText(std::to_string(score),
			Color(255, 255, 255), 20, 20, this->font);
		for (auto& c : scores)
			fillRect(Rect(c.x, c.y, 16, 16), c.color);
	}

	virtual void tick(void) override
	{
		for (register size_t i = 0; i < scores.size(); ++i)
		{
			Score& c = scores[i];
			if (isPointInRect(Point(c.x, c.y), body->rect))
			{
				score += 100;
				scores.erase(scores.begin() + i--);
			}
		}

		static clock_t last = clock();
		if (clock() - last > 1000)
		{
			Score score;
			score.x = rand() % 600;
			score.y = 600 - (rand() % 200);

			scores.push_back(score);

			last = clock();
		}
	}

} scores;