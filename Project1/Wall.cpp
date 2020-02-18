/**
 * \file Platform.cpp
 *
 * \author Zhen Li
 */

#include "pch.h"
#include <string>
#include "Wall.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring Wall1ImageName = L"data/images/wall1.png";
const wstring Wall2ImageName = L"data/images/wall2.png";

/**
* Constructor
* \param level The level the wall is a part of
( \param filename The filename of the wall image
*/
CWall::CWall(CLevel* level, const std::wstring& filename) : CTerrain(level, filename)
{
    mWall1Image = unique_ptr<Bitmap>(Bitmap::FromFile(Wall1ImageName.c_str()));
    if (mWall1Image->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += Wall1ImageName;
        AfxMessageBox(msg.c_str());
    }
    mWall2Image = unique_ptr<Bitmap>(Bitmap::FromFile(Wall2ImageName.c_str()));
    if (mWall2Image->GetLastStatus() != Ok)
    {
        wstring msg(L"Failed to open ");
        msg += Wall2ImageName;
        AfxMessageBox(msg.c_str());
    }
}

/**
 * Constructor for a platform when loaded from level file
 * \param level The level this platform is a part of
 * \param declaration The Declaration used to instantiate this item
 */
CWall::CWall(CLevel* level, const std::shared_ptr<CDeclaration> declaration) :
    CTerrain(level, declaration)
{
}

/**
 * Draw this item
 * \param graphics Graphics device to draw on
 * \param scrollX The offset used due to screen scrolling
 */
void CWall::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
    double wid = 32;
    double hit = 32;
    if (mMode == 0)
    {
        graphics->DrawImage(mWall1Image.get(),
            float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
            (float)mWall1Image->GetWidth(), (float)mWall1Image->GetHeight());
    }
    if (mMode == 1)
    {
        graphics->DrawImage(mWall2Image.get(),
            float(GetX() - wid / 2 + scrollX), float(GetY() - hit / 2),
            (float)mWall2Image->GetWidth(), (float)mWall2Image->GetHeight());
    }
}