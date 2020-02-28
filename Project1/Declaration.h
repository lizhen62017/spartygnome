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
#include <memory>

#include "DeclarationVisitor.h"


/**
 * Class representing a declaration used for item loading
 */
class CDeclaration
{
public:

    virtual ~CDeclaration();

    void AddImage(std::shared_ptr<Gdiplus::Bitmap> image);

    /**  Sets declaration's type
     * \param type Declaration type */
    void SetType(std::wstring type) { mType = type; }

    std::shared_ptr<Gdiplus::Bitmap> GetImage(int index);

    /** Gets declaration item's type
     * \return Wstring of declaration item's type*/
    std::wstring GetType() { return mType; }

    /** Accept a visitor
     * \param visitor The visitor we accept */
    virtual void Accept(CDeclarationVisitor* visitor) {};

private:
	/// Vector of images the declaration remembers
	std::vector<std::shared_ptr<Gdiplus::Bitmap>> mImages;

    /// The type of item the declaration is for
    std::wstring mType = L"";
};

