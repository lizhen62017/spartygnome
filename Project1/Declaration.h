/**
 * \file Declaration.h
 *
 * \author Chase Lindeboom
 *
 * Class representing a declaration
 */

#pragma once
#include <vector>

class CDeclaration
{
public:
    void AddImage(Gdiplus::Bitmap* image);

    Gdiplus::Bitmap* GetImage(int index);

private:
	/// Images for declaration
	std::vector<Gdiplus::Bitmap*> mImages;
};

