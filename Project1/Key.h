/**
 * \file Key.h
 *
 * \author Torre Rocco
 *
 * Class the describes the key object, which is needed to open doors
 */

#pragma once
#include "Item.h"

/**
 * Class that handles the key item, needed to pass level
 */
class CKey : public CItem
{
public:
	/// default constructor (disabled)
	CKey() = delete;

	///copy constructor (disabled)
	CKey(const CKey&) = delete;

	CKey(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

	/** Accept a visitor
	 * \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor* visitor) override { visitor->VisitKey(this); }

	void Collided() override;

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	/// \return boolean if it was hit
	virtual bool Update(double elapsed) override;

	/// Get the width of the item
	/// \returns item width
	virtual double GetWidth() override { return GetImage()->GetWidth(); };

	/// Get the height of the item
	/// \returns item height
	virtual double GetHeight() override { return GetImage()->GetHeight(); };

private:
	double mVelocity = -750; ///< the speed key moves after being hit
	bool mHit = false; ///< determines when the key has been hit by spartygnome
};

