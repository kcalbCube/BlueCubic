#pragma once

class FastFall : public Mod
{
public:
	FastFall(void)
	{
		meta.name = "FastFall";
		meta.version = "1.0";
		meta.description = "Press S to fall faster!";
	}

	virtual void tick(void) override
	{
		auto state = kcmGetKeyboardState();

		static clock_t last = clock();

		if (state[SDL_SCANCODE_S] && clock() - last > 500)
		{
			if (body->pos.y < 100)
			{
				body->pos.y = 0;
				body->a.y = 0;
			}
			else
				if (body->a.y > 0.0 && body->a.y < 20)
					body->a.y /= 2,
					last = clock();

				else if (body->a.y < 0.0)
					body->a.y *= 2,
					last = clock();
		}
		else if (state[SDL_SCANCODE_S] && body->pos.y < 100)
		{
			body->pos.y = 0;
			body->a.y = 0;
		}
	}

} fastFall;