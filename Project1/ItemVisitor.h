/**
 * \file CItemVisitor.h
 *
 * \author Chase Lindeboom
 *
 * Item Visitor base class
 */

#pragma once

class CBackground;
class CPlatform;
class CWall;
class CItemPickup;
//class CMoney;
//class CTuitionUp;
//class CWings;
//class CVillain;
//class CDoor;

/**
 * Item visitor base class
 */
class CItemVisitor
{
public:
    virtual ~CItemVisitor() {}

    /** Visit a CBackground object
     * \param background Background we are visiting */
    virtual void VisitBackground(CBackground* background) {}

    /** Visit a CPlatform object
     * \param platform Platform we are visiting */
    virtual void VisitPlatform(CPlatform* platform) {}

    /** Visit a CWall object
     * \param wall Wall we are visiting */
    virtual void VisitWall(CWall* wall) {}

    /** Visit a CItemPickup object
     * \param itemPickup ItemPickup we are visiting */
    virtual void VisitItemPickup(CItemPickup* itemPickup) {}

    //ADD MORE DOWN HERE
};

