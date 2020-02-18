/**
 * \file Background.h
 *
 * \author Chase Lindeboom
 *
 * Class representing a background item
 */

#pragma once

#include <memory>
#include "Item.h"
#include "Declaration.h"


/**
 * Class representing a background item
 */
class CBackground
	: public CItem
{
public:
    // Default constructor (disabled)
	CBackground() = delete;

    // Copy constructor (disabled)
    CBackground(const CBackground&) = delete;

    CBackground(CLevel* level, const std::shared_ptr<CDeclaration> declaration);

    /// Drawing the background
    /// \param graphics The graphics needed to draw
    /// \param scrollX The distance needed to scroll the background
	void Draw(Gdiplus::Graphics* graphics, double scrollX);
	/**double GetImageHeight() {return mImage->GetHeight(); };*/

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CItemVisitor* visitor) override { visitor->VisitBackground(this); }

    boolean IsCollidable() override;

/**private:
	Gdiplus::Bitmap* mImage;*/
};

