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
	enum class ImageState { Base, Left1, Left2, Right1, Right2 };

	/// The current image state
	ImageState mImageState = ImageState::Base;

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
	boolean mIsAfterDeath = false;

	/// Your ability to control gnome
	boolean isControllable = false;

	/// status of spartygnome
	boolean mIsAlive = true;

	/// Total time
	double mTimeElapsed = 0.0;

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

	/**  Sets gnome's status
	* \param status whether he is alive/dead */
	void Alive(bool status) { mIsAlive = status; mIsAfterDeath = false; };

	/**
	* Getter to playingarea
	* \returns the mAquarium private member
	*/
	// CLevel* GetLevel() { return mLevel; };

	/**
	* Getter to playingarea
	* \returns the mGameSystem private member
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
	* Get your ability to control gnome
	* \returns status
	*/
	boolean GetIsControllable() { return isControllable; }

	void ChangeLevel(CLevel* level);

	void Reset();
	
	void FallingColide(double y, double height);

	void RisingColide(double y, double height);

	void LeftColide(double x, double width);

	void RightColide(double x, double width);

	void TerrainColide(double x, double y, double width, double height);

	void MoveRight();

	void MoveLeft();

	void Stop();
	
	void SetImage(const std::wstring& file);
};

