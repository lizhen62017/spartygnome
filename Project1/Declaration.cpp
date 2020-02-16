/**
 * \file Declaration.cpp
 *
 * \author Chase Lindeboom
 */

#include<stdexcept>
#include "pch.h"
#include "Declaration.h"

using namespace std;

/**
 * Adds an image to the declaration vector of images
 * \param image The image to add
 */
void CDeclaration::AddImage(shared_ptr<Gdiplus::Bitmap> image)
{
    mImages.push_back(image);
}

CDeclaration::~CDeclaration()
{
}


/**
 * Retrieves the pointer to an image at the specified index
 * \param index The index we want the picture from
 * \returns 
 */
shared_ptr<Gdiplus::Bitmap> CDeclaration::GetImage(int index) 
{
    /// ADD Try and catch error
    return mImages[index];
}