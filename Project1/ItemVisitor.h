/**
 * \file ItemVisitor.h
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
class CMoney;
class CTuitionUp;
class CWings;
class CVillain;
class CDoor;
class CMessage;

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

    /** Visit a CDoor object
     * \param door Door we are visiting */
    virtual void VisitDoor(CDoor* door) {}

    /** Visit a CMoney object
     * \param money Money we are visiting */
    virtual void VisitMoney(CMoney* money) {}

    /** Visit a CTuitionUp object
     * \param tuition TuitionUp we are visiting */
    virtual void VisitTuitionUp(CTuitionUp* tuition) {}

    /** Visit a CWings object
     * \param wings Wings we are visiting */
    virtual void VisitWings(CWings* wings) {}

    /** Visit a CVillain object
    * \param villain Villain we are visiting */
    virtual void VisitVillain(CVillain* villain) {}

	/** Visit a CMessage object
	* \param message message we are visiting */
	virtual void VisitMessage(CMessage* message) {}

    //ADD MORE DOWN HERE
};

