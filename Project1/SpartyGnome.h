/**
 * \file SpartyGnome.h
 *
 * \author Robert Gustke
 *
 * Class for the game's SpartyGnome
 */

#pragma once
#include<memory>

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
	/// X velocity
	double mVx = 0;
	/// Y velocity
	double mVy = 0;
	/// The supported image states
	enum class ImageStates { Base, Left1, Left2, Right1, Right2 };



public:
	CSpartyGnome();

	void Draw(Gdiplus::Graphics* graphics);

	/**  Sets gnome's x location
	* \param New x location */
	void SetLocX(double x) { mX = x; }

	/**  Sets gnome's y location
	* \param New y location */
	void SetLocY(double y) { mY = y; }

	/**  Finds gnome's x location
	* \reutrn x location */
	double GetX() { return mX; }

	/**  Finds gnome's y location
	* \reutrn y location */
	double GetY() { return mY; }

	/**  Sets gnome's x velocity
	* \param New x velocity */
	void SetVelX(double x) { mVx = x; }

	/**  Sets gnome's y velocity
	* \param New y velocity */
	void SetVelY(double y) { mVy = y; }

	/**  Finds gnome's x velocity
	* \reutrn x velocity */
	double GetVelX() { return mVx; }

	/**  Finds gnome's y velocity
	* \reutrn y velocity */
	double GetVelY() { return mVy; }

	void Update(double elapsed);

};

