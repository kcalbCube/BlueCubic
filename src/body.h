#pragma once

#include <ctime>
#include "map.h"
#include "vector.h"
#include <functional>
#include "kcm.h"
#include "kcm_sdl.h"

class Body
{
	clock_t lastJump = 0;

	void check(void);

public:

	Vector pos, a;
	Rect  rect = { 0, 0, 50, 50 };
	Color color = { 0, 0, 255 },
		lColor = { 0, 0, 100 };

	double
		groundedSlideCoefficent = 0.25,
		inFlySlideCoefficent = 0.125,

		jumpPower = 12,

		speed = 4;

	// Events
	std::function<void(void)> on_passing_left = [&](void) {};
	std::function<void(void)> on_passing_right = [&](void) {};

	std::function<void(void)> before_display = [&](void) {};
	std::function<void(void)> post_display = [&](void) {};

	std::function<void(void)> on_jump = [&](void) {};
	std::function<void(void)> on_turn_left = [&](void) {};
	std::function<void(void)> on_turn_right = [&](void) {};

	Rect lRect = rect;

	virtual void display(void);

	virtual void calc(void);

	virtual void jump(void);

	virtual void turnLeft(void);

	virtual void turnRight(void);

};

extern Body* body;