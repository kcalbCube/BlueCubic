#include "body.h"

Body* body = new Body;

void Body::check(void)
{
	if (pos.x < 0)
	{
		pos.x = 599;

		if (map.isCurLeft())
		{
			pos.x = 0;
			a.x = -a.x + 5;
		}
		else
			LEFT map,
			on_passing_left();

	}
	else if (pos.x > 600)
	{
		pos.x = 0;

		if (map.isCurRight())
		{
			pos.x = 599;
			a.x = -a.x - 5;
		}
		else
			RIGHT map,
			on_passing_right();
	}

	if (pos.y < 0)
		pos.y = 0;
	if (pos.y > 600)
		pos.y = 600;
}

void Body::display(void)
{
	before_display();

	fillRect(lRect, lColor);

	setRenderDrawColor(color);

	rect.rect.x = pos.x;
	rect.rect.y = 600-pos.y;
	SDL_RenderFillRect(renderer, rect);



	post_display();
}


void Body::calc(void) 
{
	check();

	pos += a;

	if (pos.y > 0)
		a += gravity;
	else
		a.y = abs(a.y) - 2.0;

	if (a.x < 1 && a.x > -1)
		a.x = 0;

	else
	{
		double coef = 0;

		if (pos.y < 0.1)
			coef = groundedSlideCoefficent;
		else
			coef = inFlySlideCoefficent;

		if (a.x < 0)
			a.x += coef;
		if (a.x > 0)
			a.x -= coef;
	}


	check();
}

void Body::jump(void)
{
	if ((clock() - lastJump) > 25)
		if (pos.y <= 5 && a.y <= 1.0)
		{
			a.y += jumpPower;
			lastJump = clock();

			on_jump();
		}
}

void Body::turnLeft(void)
{
	if (a.x >= -speed)
		a.x -= speed;
	else
		if (a.x < -speed)
			a.x = -(speed + 1);

	on_turn_left();
}

void Body::turnRight(void)
{
	if (a.x <= speed)
		a.x += speed;
	else
		if (a.x > speed)
			a.x = speed + 1;

	on_turn_right();
}