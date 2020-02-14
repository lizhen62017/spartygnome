/**
 * \file Declaration.h
 *
 * \author Chase Lindeboom
 *
 * Class representing a declaration
 */

#pragma once
#include <vector>


/**
 * Class representing a declaration used for item loading
 */
class CDeclaration
{
public:
    void AddImage(Gdiplus::Bitmap* image);

    Gdiplus::Bitmap* GetImage(int index);

private:
	/// Images for declaration
	std::vector<Gdiplus::Bitmap*> mImages;
};

