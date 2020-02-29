#pragma once

class GreenCubic : public Mod
{
public:
	GreenCubic(void)
	{
		meta.name = "GreenCubic";
		meta.version = "1.0";
		meta.description = "Return of the legend!";
	}

	virtual void load(void) override
	{
		body->color = GREEN_COLOR;
	}

} greenCubic;