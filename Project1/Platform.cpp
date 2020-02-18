/**
 * \file Platform.cpp
 *
 * \author Chase Lindeboom
 */

#include "pch.h"
#include "Platform.h"

using namespace Gdiplus;
using namespace std;

/// filenames 

const wstring GrassImageName = L"data/images/grass.png"; ///< Grass Image
const wstring GrassMidImageName = L"data/images/grassMid.png"; ///< Grass Mid Image
const wstring GrassLeftImageName = L"data/images/grassLeft.png"; ///< Grass Left Image
const wstring GrassRightImageName = L"data/images/grassRight.png"; ///< Grass Right Image
const wstring SnowImageName = L"data/images/snow.png"; ///< Snow Image
const wstring SnowMidImageName = L"data/images/snowMid.png"; ///< Snow Mid Image
const wstring SnowLeftImageName = L"data/images/snowLeft.png"; ///< Snow Left Image
const wstring SnowRightImageName = L"data/images/snowRight.png"; ///< Snow Right Image
const wstring IndustrialImageName = L"data/images/platformIndustrial_057.png"; ///< Industrial Image
const wstring IndustrialMidImageName = L"data/images/platformIndustrial_060.png"; ///< Industrial Mid Image
const wstring IndustrialLeftImageName = L"data/images/platformIndustrial_059.png"; ///< Industrial Left Image
const wstring IndustrialRightImageName = L"data/images/platformIndustrial_061.png"; ///< Industrial Right Image




/**
 * Constructor
 * \param level the level this Platform is a member of
 * \param filename  The filename for the image
 */
CPlatform::CPlatform(CLevel* level, const std::wstring& filename) :
    CTerrain(level, filename)
{
    mGrassImage = unique_ptr<Bitmap>(Bitmap::FromFile(GrassImageName.c_str()));
    if (mGrassImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += GrassImageName;
        AfxMessageBox(msg.c_str());
    }
    mGrassMidImage = unique_ptr<Bitmap>(Bitmap::FromFile(GrassMidImageName.c_str()));
    if (mGrassMidImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += GrassMidImageName;
        AfxMessageBox(msg.c_str());
    }
    mGrassLeftImage = unique_ptr<Bitmap>(Bitmap::FromFile(GrassLeftImageName.c_str()));
    if (mGrassLeftImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += GrassLeftImageName;
        AfxMessageBox(msg.c_str());
    }
    mGrassRightImage = unique_ptr<Bitmap>(Bitmap::FromFile(GrassRightImageName.c_str()));
    if (mGrassRightImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += GrassRightImageName;
        AfxMessageBox(msg.c_str());
    }

    mSnowImage = unique_ptr<Bitmap>(Bitmap::FromFile(SnowImageName.c_str()));
    if (mSnowImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += SnowImageName;
        AfxMessageBox(msg.c_str());
    }
    mSnowMidImage = unique_ptr<Bitmap>(Bitmap::FromFile(SnowMidImageName.c_str()));
    if (mSnowMidImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += SnowMidImageName;
        AfxMessageBox(msg.c_str());
    }
    mSnowLeftImage = unique_ptr<Bitmap>(Bitmap::FromFile(SnowLeftImageName.c_str()));
    if (mSnowLeftImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += SnowLeftImageName;
        AfxMessageBox(msg.c_str());
    }
    mSnowRightImage = unique_ptr<Bitmap>(Bitmap::FromFile(SnowRightImageName.c_str()));
    if (mSnowRightImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += SnowRightImageName;
        AfxMessageBox(msg.c_str());
    }

    mIndustrialImage = unique_ptr<Bitmap>(Bitmap::FromFile(IndustrialImageName.c_str()));
    if (mIndustrialImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += IndustrialImageName;
        AfxMessageBox(msg.c_str());
    }
    mIndustrialMidImage = unique_ptr<Bitmap>(Bitmap::FromFile(IndustrialMidImageName.c_str()));
    if (mIndustrialMidImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += IndustrialMidImageName;
        AfxMessageBox(msg.c_str());
    }
    mIndustrialLeftImage = unique_ptr<Bitmap>(Bitmap::FromFile(IndustrialLeftImageName.c_str()));
    if (mIndustrialLeftImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += IndustrialLeftImageName;
        AfxMessageBox(msg.c_str());
    }
    mIndustrialRightImage = unique_ptr<Bitmap>(Bitmap::FromFile(IndustrialRightImageName.c_str()));
    if (mIndustrialRightImage->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += IndustrialRightImageName;
        AfxMessageBox(msg.c_str());
    }
}

/**
 * Constructor for a platform when loaded from level file
 * \param level The level this platform is a part of
 * \param declaration The Declaration used to instantiate this item
 */
CPlatform::CPlatform(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CTerrain(level, declaration)
{
    //mLeftImage = unique_ptr<Bitmap>(declaration->GetImage(0)); FIXME: Redundant with mItemImage
    mMidImage = shared_ptr<Bitmap>(declaration->GetImage(1));
    mRightImage = shared_ptr<Bitmap>(declaration->GetImage(2));
}


/**
 * Draw this item
 * \param graphics Graphics device to draw on
 * \param scrollX The offset used due to screen scrolling
 */
void CPlatform::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
    double wid = 32;
    double hit = 32;

    float numMid = (GetWidth() - 64)/ 32;

    if (numMid < 0)
    {
        graphics->DrawImage(mMidImage.get(), 
            float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
            (float)mMidImage->GetWidth(), (float)mMidImage->GetHeight());
    }

    else 
    {
        float currentCenter = GetX() - (numMid / 2) * 32 - 16;
        float rightCenter = GetX() + (numMid / 2) * 32 + 16;

        graphics->DrawImage(GetImage().get(),
            float(currentCenter - wid / 2 + scrollX), float(GetY() - hit / 2),
            (float)GetImage()->GetWidth(), (float)GetImage()->GetHeight());

        currentCenter += 32;

        while (currentCenter < rightCenter)
        {
            graphics->DrawImage(mMidImage.get(),
                float(currentCenter - wid / 2 + scrollX), float(GetY() - hit / 2),
                (float)mMidImage->GetWidth(), (float)mMidImage->GetHeight());

            currentCenter += 32;
        }

        graphics->DrawImage(mRightImage.get(),
            float(currentCenter - wid / 2 + scrollX), float(GetY() - hit / 2),
            (float)mRightImage->GetWidth(), (float)mRightImage->GetHeight());

    }
    /**if (mMode == 0)
    {
        if (isEdge == 0)
        {
            graphics->DrawImage(mGrassMidImage.get(),
                float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
                (float)mGrassMidImage->GetWidth(), (float)mGrassMidImage->GetHeight());
        }

        else if (isEdge == 1)
        {
            graphics->DrawImage(mGrassLeftImage.get(),
                float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
                (float)mGrassLeftImage->GetWidth(), (float)mGrassLeftImage->GetHeight());
        }

        else if (isEdge == 2)
        {
            graphics->DrawImage(mGrassRightImage.get(),
                float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
                (float)mGrassRightImage->GetWidth(), (float)mGrassRightImage->GetHeight());
        }

        else if (isEdge == 3)
        {
            graphics->DrawImage(mGrassImage.get(),
                float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
                (float)mGrassImage->GetWidth(), (float)mGrassImage->GetHeight());
        }
    }
    else if (mMode == 1)
    {
        if (isEdge == 0)
        {
            graphics->DrawImage(mSnowMidImage.get(),
                float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
                (float)mSnowMidImage->GetWidth(), (float)mSnowMidImage->GetHeight());
        }

        else if (isEdge == 1)
        {
            graphics->DrawImage(mSnowLeftImage.get(),
                float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
                (float)mSnowLeftImage->GetWidth(), (float)mSnowLeftImage->GetHeight());
        }

        else if (isEdge == 2)
        {
            graphics->DrawImage(mSnowRightImage.get(),
                float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
                (float)mSnowRightImage->GetWidth(), (float)mSnowRightImage->GetHeight());
        }

        else if (isEdge == 3)
        {
            graphics->DrawImage(mSnowImage.get(),
                float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
                (float)mSnowImage->GetWidth(), (float)mSnowImage->GetHeight());
        }
    }
    else if (mMode == 2)
    {
        if (isEdge == 0)
        {
            graphics->DrawImage(mIndustrialMidImage.get(),
                float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
                (float)mIndustrialMidImage->GetWidth(), (float)mIndustrialMidImage->GetHeight());
        }

        else if (isEdge == 1)
        {
            graphics->DrawImage(mIndustrialLeftImage.get(),
                float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
                (float)mIndustrialLeftImage->GetWidth(), (float)mIndustrialLeftImage->GetHeight());
        }

        else if (isEdge == 2)
        {
            graphics->DrawImage(mIndustrialRightImage.get(),
                float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
                (float)mIndustrialRightImage->GetWidth(), (float)mIndustrialRightImage->GetHeight());
        }

        else if (isEdge == 3)
        {
            graphics->DrawImage(mIndustrialImage.get(),
                float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
                (float)mIndustrialImage->GetWidth(), (float)mIndustrialImage->GetHeight());
        }
    }*/
}