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

	/// Vector for gnome's velocity
	CVector mV = CVector(0, 0);

	/// Vector for gnome's position
	CVector mP = CVector(850, 550);

	/// The supported image states
	enum class ImageState { Base, Left1, Left2, Right1, Right2, Sad};

	/// The current image state
	ImageState mImageState = ImageState::Base;

	/// Boolean if gnome has wings
	boolean mWings = false;

	/// Boolean if gnome has the key
	bool mKey = false;

	/// Boolean if gnome has used double jump
	boolean mDoubleJump = false;

	/// The game the gnome is contained in
	CGameSystem* mGameSystem;

	/// Trace if gnome is really falling or falling after being killed by villan
	boolean mIsAfterDeath = false;

	/// Ability to control gnome
	boolean isControllable = false;

	/// Status of spartygnome
	boolean mIsAlive = true;

	/// Total time
	double mTimeElapsed = 0.0;

	/// Time spent in a partcilar image, used for SpartyGnome animation
	double mImageTime = 0.0;

public:
	/// Default constructor (deleted)
	CSpartyGnome() = delete;

	///copy constructor (disabled)
	CSpartyGnome(const CSpartyGnome&) = delete;

	CSpartyGnome(CGameSystem* game);

	void Draw(Gdiplus::Graphics* graphics, float scrollX);

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

	/// Get the width of the gnome
	/// \returns item width
	int GetWidth() const { return mImage->GetWidth(); }

	/// Get the height of the gnome
	/// \returns item height
	int GetHeight() const { return mImage->GetHeight(); }

	void Update(double elapsed);

	/**  Sets gnome's status
	* \param status whether he is alive or dead */
	void Alive(bool status) { mIsAlive = status; mIsAfterDeath = false; };

	/**
	* Getter to the game the gnome is apart of
	* \returns The game th egnome is apart of
	*/
	CGameSystem* GetGame() { return mGameSystem; };

	void Death(boolean villain);

	void Jump();

	/**
	* Get your ability to control gnome
	* \returns The gnomes control status
	*/
	boolean GetIsControllable() { return isControllable; }

	/// Function for handling if the gnome is controllable
	/// \param temp A bool for switching controllable
	void SetIsControllable(boolean control) { isControllable = control; }
	
	void FallingColide(double y, double height);

	void RisingColide(double y, double height);

	void LeftColide(double x, double width);

	void RightColide(double x, double width);

	void TerrainColide(double x, double y, double width, double height);

	void MoveRight();

	void MoveLeft();

	void Stop();
	
	void SetImage(const std::wstring& file);

	/**
	* A function for setting how much the time has elapsed for spartygnome
	* \param temp The time that has elapsed
	*/
	void SetTimeElapsed(double temp) { mTimeElapsed = temp; }

	/**
	* Updates the imagetime variable
	* \param elapsed The elapsed time
	*/
	void UpdateImageTime(double elapsed) { mImageTime += elapsed; }

	/**
	* Updates the mWings variable
	* \param wings If gnome is gaining or losing wings
	*/
	void Wings(boolean wings) { mWings = wings; }

	/**
	* Updates the mKey variable
	* \param key If gnome can go to the next level
	*/
	void Key(bool key) { mKey = key; }

	/**
	* Gets the key boolean
	* \returns mKey if the gnome has it or not
	*/
	bool GetKey() { return mKey; }
};

