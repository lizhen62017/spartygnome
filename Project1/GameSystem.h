#include "Background.h"

#pragma once
class CGameSystem
{
public:
	CGameSystem() {};
	void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

private:
	CBackground mBackground;
	float mScale;
};

