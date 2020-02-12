/**
 * \file Level.h
 *
 * \author Chase Lindeboom
 *
 * Class representing a level in our gamesystem
 */

#pragma once

#include <vector>
#include <memory>
#include <string>

#include "XmlNode.h"

class CItem;

/**
 * Class representing a level in the game
 */
class CLevel
{
public:
    CLevel();

    void Load(const std::wstring& filename);

    void Clear();

private:

    /// All of the items populating the level
    std::vector<std::shared_ptr<CItem>> mItems;

};

