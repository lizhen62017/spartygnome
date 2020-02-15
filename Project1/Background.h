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

	void OnDraw(Gdiplus::Graphics* graphics, double scrollX);
	double GetImageHeight() {return mImage->GetHeight(); };

private:
	Gdiplus::Bitmap* mImage;
};

