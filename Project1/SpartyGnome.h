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
	/// X velocity
	double mVx = 0;
	/// Y velocity
	double mVy = 0;



public:
	CSpartyGnome();

	void Draw(Gdiplus::Graphics* graphics);

	void SetLocation(double x, double y);

	/**  Finds gnome's x location
	* \reutrn x location */
	double GetX() { return mX; }

	/**  Finds gnome's y location
	* \reutrn y location */
	double GetY() { return mY; }

	void Update(double elapsed);

	void SetVel(double x, double y);

	/**  Finds gnome's x velocity
	* \reutrn x velocity */
	double GetX() { return mVx; }

	/**  Finds gnome's y velocity
	* \reutrn y velocity */
	double GetY() { return mVy; }

};

