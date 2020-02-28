/**
 * \file ChildView.h
 *
 * \author 
 *
 * Class that implements the child window in which the program draws.
 *
 * The window is a child of the main frame which holds the window,
 * the menu bar, and the status bar
 */

#pragma once

#include "GameSystem.h"


/**
 * Class implementing the child window in which the program draws
 */
class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions

// Member Variables	
private:
	CGameSystem mGameSystem;    ///< The GameSystem class

	bool mFirstDraw = true;     ///< True until the first time we draw

	long long mLastTime = 0;    ///< Last time we read the timer
	double mTimeFreq = 0;       ///< Rate the timer updates

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLevelLevel0();
	afx_msg void OnLevelLevel1();
	afx_msg void OnLevelLevel2();
	afx_msg void OnLevelLevel3();
};

