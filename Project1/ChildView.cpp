// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"

#include "Project1.h"

#include "framework.h"
#include "ChildView.h"
#include "DoubleBufferDC.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Gdiplus;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/// Horizontal character speed in pixels per second
const double HorizontalSpeed = 500.00;

// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_COMMAND(ID_LEVEL_LEVEL0, &CChildView::OnLevelLevel0)
	ON_COMMAND(ID_LEVEL_LEVEL1, &CChildView::OnLevelLevel1)
	ON_COMMAND(ID_LEVEL_LEVEL2, &CChildView::OnLevelLevel2)
	ON_COMMAND(ID_LEVEL_LEVEL3, &CChildView::OnLevelLevel3)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS,
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1), nullptr);

	return TRUE;
}

/**
 * The function for painting the window and setting up the Update function
 */
void CChildView::OnPaint()
{
	CPaintDC paintDC(this);     // device context for painting
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Graphics graphics(dc.m_hDC);

	CRect rect;
	GetClientRect(&rect);

	if (mFirstDraw)
	{
		mFirstDraw = false;
		SetTimer(1, FrameDuration, nullptr);

		/*
		* Initialize the elapsed time system
		*/
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}

	/*
	* Compute the elapsed time since the last draw
	*/
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	mGameSystem.Update(elapsed);
	mGameSystem.Draw(&graphics, rect.Width(), rect.Height());

	// Do not call CWnd::OnPaint() for painting messages
}

/**
 * A function for preventing the screen flicker on invalidate() calls
 * \param pDC the CDC object
 * \returns FALSE
 */
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}



/**
 * Handle timer events
 * \param nIDEvent The timer event ID
 */
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}


/**
 * The function for handling which key is pressed
 * \param nChar The key pressed
 * \param nRepCnt 
 * \param nFlags 
 */
void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_RIGHT:
		mGameSystem.GetGnome()->SetVelX(HorizontalSpeed);
		break;

	case VK_LEFT:
		mGameSystem.GetGnome()->SetVelX(-HorizontalSpeed);
		break;

	case VK_SPACE:
		mGameSystem.GetGnome()->Jump();
		break;
	}
}


/**
 * The function for handling when a key is no longer pressed
 * \param nChar the key being released
 * \param nRepCnt 
 * \param nFlags 
 */
void CChildView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_RIGHT:
	case VK_LEFT:
		mGameSystem.GetGnome()->SetVelX(0);
		break;
	}
}


/**
 * Play level 0 menu option handler
 */
void CChildView::OnLevelLevel0()
{
	// TODO: Add your command handler code here
}

/**
 * Play level 1 menu option handler
 */
void CChildView::OnLevelLevel1()
{
	// TODO: Add your command handler code here
}


/**
 * Play level 2 menu option handler
 */
void CChildView::OnLevelLevel2()
{
	// TODO: Add your command handler code here
}



/**
 * Play level 3 menu option handler
 */
void CChildView::OnLevelLevel3()
{
	// TODO: Add your command handler code here
}
