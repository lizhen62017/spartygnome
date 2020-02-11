//Test
//Test -Jeremy Cowelchuk

// ChildView.h : interface of the CChildView class
//


#pragma once


// CChildView window

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
	CGameSystem mGameSystem; ///< The GameSystem class

protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

