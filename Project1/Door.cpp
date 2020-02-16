/**
 * \file Door.cpp
 *
 * \author Robert Gustke
 */


#include "pch.h"
#include "Door.h"
#include<string>

using namespace Gdiplus;
using namespace std;


/**
 * Basic contructor for a door
 * \param level the level the door is in
 * \param filename the name of the door image
 */
CDoor::CDoor(CLevel* level, const std::wstring& filename) :
    CItem(level, filename)
{
}