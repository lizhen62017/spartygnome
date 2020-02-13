/**
 * \file Level.cpp
 *
 * \author Chase Lindeboom
 */

#include "pch.h"
#include "Level.h"


using namespace std;
using namespace xmlnode;


/**
 * Level Constructor
 * \param flename The name of the file the level is loaded from
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
                for (auto declaration : node->GetChildren())
                {
                    
                }
            }

            if (node->GetType() == NODE_ELEMENT && node->GetName() == L"items")
            {
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
* Handle an item node.
* \param node Pointer to XML node we are handling
*/
void CLevel::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    // A pointer for the item we are loading
    shared_ptr<CItem> item;

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
        ///item->XmlLoad(node);
       /// Add(item); /// FIX LATER
    }
}