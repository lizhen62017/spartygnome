/**
 * \file Declaration.cpp
 *
 * \author Chase Lindeboom
 */

#include<stdexcept>
#include "pch.h"
#include "Declaration.h"


/**
 * Adds an image to the declaration vector of images
 * \param image The image to add
 */
void CDeclaration::AddImage(Gdiplus::Bitmap* image)
{
    mImages.push_back(image);
}


/**
 * Retrieves the pointer to an image at the specified index
 * \param index The index we want the picture from
 * \returns 
 */
Gdiplus::Bitmap* CDeclaration::GetImage(int index) 
{
    /// ADD Try ad catch error
    return mImages[index];
}