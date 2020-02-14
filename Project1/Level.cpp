/**
 * \file Level.cpp
 *
 * \author Chase Lindeboom
 */

#include "pch.h"
#include "Level.h"

#include "MoneyDeclaration.h"

#include "Platform.h"


using namespace std;
using namespace xmlnode;
using namespace Gdiplus;


/**
 * Level Constructor
 * \param filename The name of the file the level is loaded from
 */
CLevel::CLevel(const std::wstring& filename)
{
    Load(filename);
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
 * \returns A pointer to the declaration we want to get
 */
CDeclaration CLevel::GetDeclaration(std::wstring id)
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

        // Load Level parameters

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


/**
* Handle a declaration node.
* \param node Pointer to XML node we are handling
*/
void CLevel::XmlDeclaration(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
 
    std::wstring type = node->GetName();
    std::wstring id = node->GetAttributeValue(L"id", L"");

    // Platforms have 3 images
    if (type == L"platform")
    {
        std::wstring leftFile = node->GetAttributeValue(L"left-image", L"");
        Bitmap* leftImage = ImageLoad(leftFile);

        std::wstring midFile = node->GetAttributeValue(L"mid-image", L"");
        Bitmap* midImage = ImageLoad(midFile);

        std::wstring rightFile = node->GetAttributeValue(L"right-image", L"");
        Bitmap* rightImage = ImageLoad(rightFile);

        CDeclaration declaration;
        declaration.AddImage(leftImage);
        declaration.AddImage(midImage);
        declaration.AddImage(rightImage);
        mDeclarations.insert({ id, declaration });
    }

    // Has a single image
    else 
    {
        // Get image file
        std::wstring file = node->GetAttributeValue(L"image", L"");
        
        Bitmap* image = ImageLoad(file);

        // Money has value attribute
        if (type == L"money") 
        {
            CMoneyDeclaration declaration;
            double value = node->GetAttributeDoubleValue(L"value", 0);
            declaration.SetValue(value);
            declaration.AddImage(image);
            mDeclarations.insert({ id, declaration });

        }

        // Item is basic
        else 
        {
            CDeclaration declaration;
            declaration.AddImage(image);
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

    std::wstring id = node->GetAttributeValue(L"id", L"");
    CDeclaration declaration = mDeclarations[id];
    std::wstring type = node->GetName();


    if (type == L"background")
    {
        ///TODO
    }

    else if (type == L"platform")
    {
        ///TODO
    }

    else if (type == L"wall")
    {
        ///TODO
    }

    else if (type == L"money")
    {
        ///TODO
    }

    else if (type == L"tuition-up")
    {
        ///TODO
    }

    else if (type == L"door")
    {
        ///TODO
    }

    else if (type == L"villain")
    {
        ///TODO
    }
    
    /**
    else if (type == L"TEAMITEMHERE")
    {
        /// TODO when we add teamitem
    }
    */

    if (item != nullptr)
    {
        item->XmlLoad(node);
        Add(item); /// FIX LATER
    }
}


/**
 * Loads an image for XmlDeclaration function
 * \param filename The name  file name of the specific image
 * \returns A pointer to the image we want
 */
Gdiplus::Bitmap* CLevel::ImageLoad(std::wstring filename)
{
    // Get image file path
    std::wstring path = L"data/images/" + filename;

    // Get image
    Bitmap* image = Bitmap::FromFile(path.c_str());
    if (image->GetLastStatus() != Ok)
    {
        std::wstring message = L"Failed to open" + path;
        AfxMessageBox(message.c_str()); //////FIX THIS LATER
    }
    return image;
}