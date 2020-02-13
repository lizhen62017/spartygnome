#include "Background.h"
#include "SpartyGnome.h"
#include "Level.h"
#include <string>
#pragma once


class CGameSystem
{
public:
	CGameSystem() {};
	void OnDraw(Gdiplus::Graphics* graphics, int width, int height);

private:
	CBackground mBackground;
	CSpartyGnome mGnome;
	float mScale;
	CLevel mLevel0 = CLevel(L"../Project1/data/levels/level0.xml");
};
