/**
 * \file Declaration.h
 *
 * \author Chase Lindeboom
 *
 * Class representing a declaration
 */

#pragma once
#include <vector>
#include <string>


/**
 * Class representing a declaration used for item loading
 */
class CDeclaration
{
public:

    void AddImage(Gdiplus::Bitmap* image);

    /**  Sets declaration's type
     * \param type Declaration type */
    void SetType(std::wstring type) { mType = type; }

    Gdiplus::Bitmap* GetImage(int index);

    /** Gets declaration's type
     * \return Wstring of Declarations type*/
    std::wstring GetType() { return mType; }

private:
	/// Images for declaration
	std::vector<Gdiplus::Bitmap*> mImages;

    /// The type of item
    std::wstring mType = L"";
};

