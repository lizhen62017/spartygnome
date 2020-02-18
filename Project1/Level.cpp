/**
 * \file Level.cpp
 *
 * \author Chase Lindeboom
 */

#include "pch.h"
#include "Item.h"
#include "Level.h"
#include "MoneyDeclaration.h"
#include "SpartyGnome.h"
#include "Background.h"
#include "Platform.h"
#include "Wall.h"
#include "ItemVisitor.h"
#include "Door.h"


using namespace std;
using namespace xmlnode;
using namespace Gdiplus;

/// Small value to ensure we do not stay in collision
const double Epsilon = 0.01;

/// For manually pushing things to mItems
const double initCoord = 500;

/**
 * Level Constructor
 * \param filename The name of the file the level is loaded from
 */
CLevel::CLevel(const std::wstring& filename)
{
    
    Load(filename);

    /**
    const int NumRows = 20; ///Hey Chase, feel free to change these things below whenever you feel like necessary
    const int NumCols = 8;
    for (int r = 0; r < NumRows; r++)
    {
        // There is a row every 64 pixels and
        // we start 150 pixels from the top
        int y = initCoord;

        // The number of columns starts at 1 and increases as we
        // go down in the Y direction until half way, then decreases.
        // If we had 5 rows, the number of columns for each row
        // will be:  1 2 3 4 1

        // We center the columns on the screen
        const int xStart = 372;

        // Each column is 128 pixels to the right.
        int x = r * 31 + xStart;

        // Create a new fish.
        // This creates a shared pointer pointing at this fish
        shared_ptr<CPlatform> platform = make_shared<CPlatform>(this, L"data/images/grass.png");

        platform->SetMode(2);

        if (r == 0)
        {
            platform->SetIsEdge(1);
        }

        if (r == NumRows - 1)
        {
            platform->SetIsEdge(2);
        }

        // Set the location
        platform->SetLocation(x, y);

        // Add to the list of fish.
        Add(platform);
    }

    for (int r = 0; r < NumRows; r++)
    {
        // There is a row every 64 pixels and
        // we start 150 pixels from the top
        int y = initCoord - 250;

        // The number of columns starts at 1 and increases as we
        // go down in the Y direction until half way, then decreases.
        // If we had 5 rows, the number of columns for each row
        // will be:  1 2 3 4 1

        // We center the columns on the screen
        const int xStart = 872;

        // Each column is 128 pixels to the right.
        int x = r * 31 + xStart;

        // Create a new fish.
        // This creates a shared pointer pointing at this fish
        shared_ptr<CPlatform> platform = make_shared<CPlatform>(this, L"data/images/grass.png");

        platform->SetMode(2);

        if (r == 0)
        {
            platform->SetIsEdge(1);
        }

        if (r == NumRows - 1)
        {
            platform->SetIsEdge(2);
        }

        // Set the location
        platform->SetLocation(x, y);

        // Add to the list of fish.
        Add(platform);
    }

    for (int r = 0; r < NumCols; r++)
    {
        // There is a row every 64 pixels and
        // we start 150 pixels from the top
        int x = 372;

        // The number of columns starts at 1 and increases as we
        // go down in the Y direction until half way, then decreases.
        // If we had 5 rows, the number of columns for each row
        // will be:  1 2 3 4 1

        // We center the columns on the screen
        const int yStart = 251;

        // Each column is 128 pixels to the right.
        int y = r * 31 + yStart;

        // Create a new fish.
        // This creates a shared pointer pointing at this fish
        shared_ptr<CWall> wall = make_shared<CWall>(this, L"data/images/grass.png");

        wall->SetMode(0);

        // Set the location
        wall->SetLocation(x, y);

        // Add to the list of fish.
        Add(wall);

    }*/
}

/** Add an item to the level
 * \param item New item to add
 */
void CLevel::Add(std::shared_ptr<CItem> item)
{
    mItems.push_back(item);
}


/**
 * Getter for a declaration
 * \param id The ID for the declaration we want to get
 * \returns A shared pointer to the declaration we want to get
 */
shared_ptr<CDeclaration> CLevel::GetDeclaration(std::wstring id)
{
    return mDeclarations[id];
}

/**
 * Clears the level
 */
void CLevel::Clear()
{
    mWidth = 0;
    mHeight = 0;
    mStartX = 0;
    mStartY = 0;
    mItems.clear();
}

/**
 * Loads a level from an Xml file
 * \param filename The name of the file the level is loaded from
 */
void CLevel::Load(const std::wstring& filename)
{
    // We surround with a try/catch to handle errors
    try
    {
        // Open the document to read
        shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

        // Once we know it is open, clear the existing data
        Clear();

        // Load Level attributes

        // Load level width
        mWidth = root->GetAttributeDoubleValue(L"width", 0);
        // Load level height
        mHeight = root->GetAttributeDoubleValue(L"height", 0);
        // Load level starting X-position
        mStartX = root->GetAttributeDoubleValue(L"start-x", 0);
        //Load level starting Y-position
        mStartY = root->GetAttributeDoubleValue(L"start-y", 0);


        //
        // Traverse the children of the root
        // node of the XML document in memory!!!!
        //
        for (auto node : root->GetChildren())
        {
            if (node->GetType() == NODE_ELEMENT && node->GetName() == L"declarations")
            {
                // Traverse item declarations
                for (auto declaration : node->GetChildren())
                {
                    XmlDeclaration(declaration);
                }
            }

            if (node->GetType() == NODE_ELEMENT && node->GetName() == L"items")
            {
                // Traverse items
                for (auto item : node->GetChildren())
                {
                    XmlItem(item);
                }
            }
        }

    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }

}

std::vector<std::shared_ptr<CItem>> CLevel::CollisionTest(CSpartyGnome* gnome)
{
    std::vector<std::shared_ptr<CItem>> mOut;
    for (int i = 0; i < mItems.size(); i++)
    {
        if (abs(mItems[i]->GetX() - gnome->GetX()) <=
            mItems[i]->GetWidth() / 2.0 + gnome->GetWidth() / 2.0 + Epsilon &&
            abs(mItems[i]->GetY() - gnome->GetY()) <=
            mItems[i]->GetHeight() / 2.0 + gnome->GetHeight() / 2.0 + Epsilon)
        {
            mOut.push_back(mItems[i]);
        }
    }
    return mOut;
}

/**
* Handle a declaration node.
* \param node Pointer to XML node we are handling
*/
void CLevel::XmlDeclaration(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    // What is the type of this declaration?
    wstring type = node->GetName();
    // What is the declaration's id?
    wstring id = node->GetAttributeValue(L"id", L"");

    // Platforms have 3 images
    if (type == L"platform")
    {
        // Left platform image
        wstring leftFile = node->GetAttributeValue(L"left-image", L"");
        shared_ptr<Bitmap> leftImage = ImageLoad(leftFile);

        // Middle platform image
        wstring midFile = node->GetAttributeValue(L"mid-image", L"");
        shared_ptr<Bitmap> midImage = ImageLoad(midFile);

        // Right platform image
        wstring rightFile = node->GetAttributeValue(L"right-image", L"");
        shared_ptr<Bitmap> rightImage = ImageLoad(rightFile);

        // Make the platform declaration
        auto declaration = make_shared<CDeclaration>();
        declaration->SetType(type);
        declaration->AddImage(leftImage);
        declaration->AddImage(midImage);
        declaration->AddImage(rightImage);

        // Insert declaration into map
        mDeclarations.insert({ id, declaration });
    }

    // Has a single image
    else 
    {
        // Get image file
        wstring file = node->GetAttributeValue(L"image", L"");
        // Load image file
        shared_ptr<Bitmap> image = ImageLoad(file);

        // Money has value attribute
        if (type == L"money") 
        {
            // Make the declaration
            auto declaration = make_shared<CMoneyDeclaration>();
            declaration->SetType(type);
            double value = node->GetAttributeDoubleValue(L"value", 0);
            declaration->SetValue(value);
            declaration->AddImage(image);

            // Insert declaration into map
            mDeclarations.insert({ id, declaration });

        }

        // Item is basic
        else 
        {
            // Make the declaration
            auto declaration = make_shared<CDeclaration>();
            declaration->SetType(type);
            declaration->AddImage(image);

            // Insert declaration into map
            mDeclarations.insert({ id, declaration });
        }

    }
}

/**
* Handle an item node.
* \param node Pointer to XML node we are handling
*/
void CLevel::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    // A pointer for the item we are loading
    shared_ptr<CItem> item;

    // What type is the node?
    std::wstring type = node->GetName();

    // what is the declaration associated with item's id?
    std::wstring id = node->GetAttributeValue(L"id", L"");
    shared_ptr<CDeclaration> declaration = mDeclarations[id];

    // If it is a background
    if (type == L"background")
    {
        //item = make_shared<CBackground>(this, declaration);
    }

    // If it is a platform
    else if (type == L"platform")
    {
        item = make_shared<CPlatform>(this, declaration);
    }

    // If it is a wall
    else if (type == L"wall")
    {
        ///TODO
    }

    // If it is money
    else if (type == L"money")
    {
        ///TODO
    }

    // If it is a tuition-up
    else if (type == L"tuition-up")
    {
        ///TODO
    }

    // If it is a door
    else if (type == L"door")
    {
        ///TODO
    }
    
    //If it is a villain
    else if (type == L"villain")
    {
        ///TODO
    }
    
    // If it is wings
    else if (type == L"wings")
    {
        /// TODO when we add teamitem
    }
    

    if (item != nullptr)
    {
        item->XmlLoad(node);
        Add(item);
    }
}


/**
 * Loads an image for XmlDeclaration function
 * \param filename The name  file name of the specific image
 * \returns A pointer to the image we want
 */
shared_ptr<Bitmap> CLevel::ImageLoad(wstring filename)
{
    // Get image file path
    std::wstring path = L"data/images/" + filename;

    shared_ptr<Bitmap> image;

    // Get image
     image = shared_ptr<Bitmap>(Bitmap::FromFile(path.c_str()));
    if (image->GetLastStatus() != Ok)
    {
        wstring message = L"Failed to open" + path;
        AfxMessageBox(message.c_str()); //////FIX THIS LATER
    }
    return image;
}

void CLevel::Draw(Gdiplus::Graphics* graphics, int scrollX)
{
    for (auto item : mItems)
    {
        item->Draw(graphics, scrollX);
    }
}

/** Accept a visitor for the collection of items
 * \param visitor The visitor for the collection
 */
void CLevel::Accept(CItemVisitor* visitor)
{
    for (auto item : mItems)
    {
        item->Accept(visitor);
    }
}