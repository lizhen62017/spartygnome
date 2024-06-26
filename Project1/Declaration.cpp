/**
 * \file Declaration.cpp
 *
 * \author Chase Lindeboom
 */

#include "pch.h"
#include<stdexcept>
#include "Declaration.h"

using namespace std;

/**
 * Adds an image to the declaration's vector of images
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
 * \returns a shared pointer to the image at the specified index
 */
shared_ptr<Gdiplus::Bitmap> CDeclaration::GetImage(int index) 
{
        shared_ptr<Gdiplus::Bitmap> image = mImages[index];
        return image;
}