#pragma once

/**
 * SpartyGnome to play the game
 */
class CSpartyGnome
{
private:
	/// X location of gnome
	double mX;
	/// Y location of gnome
	double mY;
	/// Check to see if gnome has already jumped
	boolean isJumping = false;
	/// Image for gnome
	Gdiplus::Bitmap* mImage;


public:
	CSpartyGnome();

	void OnDraw(Gdiplus::Graphics* graphics);
};

