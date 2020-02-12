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
 */
CLevel::CLevel() 
{
//Insert Level Constructor here, MAY DISABLE NORMAL CONSTRUCTOR TO REQUIRE FILENAME
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

        //
        // Traverse the children of the root
        // node of the XML document in memory!!!!
        //
        for (auto node : root->GetChildren())
        {
            if (node->GetType() == NODE_ELEMENT && node->GetName() == L"item")
            {
                ///ADD LOADING ITEM HERE
            }
        }

    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }

}


/**
 * Clears level item vector
 */
void CLevel::Clear()
{
    mItems.clear();
}