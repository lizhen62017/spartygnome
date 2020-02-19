/**
 * \file SpartyGnome.h
 *
 * \author Robert Gustke
 *
 * Class for the game's SpartyGnome
 */

#pragma once
#include<memory>
#include "Vector.h"
#include "Level.h"
#include "Item.h"
#include "GameSystem.h"

/**
 * SpartyGnome to play the game
 */
class CSpartyGnome
{
private:

	/// Check to see if gnome has already jumped
	boolean misJumping = false;
	/// Image for gnome
	std::unique_ptr<Gdiplus::Bitmap> mImage;

	/// speed vectors, contains all the getters and setters
	CVector mV = CVector(0, 0);
	/// position vectors contains all the getters and setters
	CVector mP = CVector(850, 550);
	/// The supported image states
	enum class ImageStates { Base, Left1, Left2, Right1, Right2 };

	/* The level this gnome is contained in
	CLevel Temp = CLevel(L"data/levels/level0.xml");
	CLevel Temp1 = CLevel(L"data/levels/level1.xml"); ///< The level the gnome starts on
	CLevel* mLevel = &Temp1; ///< The level spartygnome is currently on???  */

	/// Boolean if gnome has wings
	boolean mWings = false;

	/// Boolean if gnome has used double jump
	boolean mDoubleJump = false;

	/// The game this item is contained in
	CGameSystem* mGameSystem;

	/// Trace if gnome is really falling or falling after killed by villan
	boolean isAfterDeath = false;

public:
	/// Default constructor (deleted)
	CSpartyGnome() = delete;

	CSpartyGnome(CGameSystem* game);

	void Draw(Gdiplus::Graphics* graphics, int scrollX);

	/**  Sets gnome's x location
	* \param x X location */
	void SetLocX(double x) { mP.SetX(x); }

	/**  Sets gnome's y location
	* \param y Y location */
	void SetLocY(double y) { mP.SetY(y); }

	/**  Finds gnome's x location
	* \return x location */
	double GetX() { return mP.X(); }

	/**  Finds gnome's y location
	* \return y location */
	double GetY() { return mP.Y(); }

	/**  Sets gnome's x velocity
	* \param x X velocity */
	void SetVelX(double x) { mV.SetX(x); }

	/**  Sets gnome's y velocity
	* \param y Y velocity */
	void SetVelY(double y) { mV.SetY(y); }

	/**  Finds gnome's x velocity
	* \return x velocity */
	double GetVelX() { return mV.X(); }

	/**  Finds gnome's y velocity
	* \return y velocity */
	double GetVelY() { return mV.Y(); }

	/// Get the width of the item
	/// \returns item width
	int GetWidth() const { return mImage->GetWidth(); }

	/// Get the height of the item
	/// \returns item height
	int GetHeight() const { return mImage->GetHeight(); }

	void Update(double elapsed);

	/**
	* Getter to playingarea
	* \returns the mAquarium private member
	*/
	// CLevel* GetLevel() { return mLevel; };

	/**
	* Getter to playingarea
	* \returns the mAquarium private member
	*/
	CGameSystem* GetGame() { return mGameSystem; };

	/**
	* Function for handling the death of SpartyGnome
	*/
	void Death(boolean villain);

	/**
	* Function for processing a jump
	*/
	void Jump();

	/**
	* Set death condition so won't collide anymore while dropping after hitting a villain. 
	* \param temp Whether SpartyGnome was killed or not
	*/
	void SetIsAfterDeath(boolean temp) { isAfterDeath = temp; };

	void ChangeLevel(CLevel* level);

	void Reset();
};

