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
const wstring Wall1ImageName = L"images/wall1.png";
const wstring Wall2ImageName = L"images/wall2.png";

/**
* Constructor
* \param aquarium Aquarium this fish is a member of
*/
CWall::CWall(CLevel* level, const std::wstring& filename) : CItem(level, filename)
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
 * Draw this item
 * \param graphics Graphics device to draw on
 */
void CWall::Draw(Gdiplus::Graphics* graphics)
{
    double wid = 32;
    double hit = 32;
    if (mMode == 0)
    {
        graphics->DrawImage(mWall1Image.get(),
            float(GetX() - wid / 2), float(GetY() - hit / 2),
            (float)mWall1Image->GetWidth(), (float)mWall1Image->GetHeight());
    }
    if (mMode == 1)
    {
        graphics->DrawImage(mWall2Image.get(),
            float(GetX() - wid / 2), float(GetY() - hit / 2),
            (float)mWall2Image->GetWidth(), (float)mWall2Image->GetHeight());
    }
}