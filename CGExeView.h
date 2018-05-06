// CGExeView.h : interface of the CCGExeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CGEXEVIEW_H__303D2CD1_D56D_425B_AAC8_BBE8DA3D5EB3__INCLUDED_)
#define AFX_CGEXEVIEW_H__303D2CD1_D56D_425B_AAC8_BBE8DA3D5EB3__INCLUDED_

#include "ConvexHull.h"	// Added by ClassView
#include "ChnCities.h"	// Added by ClassView
#include "MyLine1.h"	// Added by ClassView
#include "DDALine.h"	// Added by ClassView
#include "BezierCurve.h"	// Added by ClassView
#include "GeoMap.h"	// Added by ClassView
#include "MapProject.h"
#include "SpatialIndex.h"	// Added by ClassView
#include "SpatialObject.h"	// Added by ClassView


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCGExeView : public CView
{
protected: // create from serialization only
	CCGExeView();
	DECLARE_DYNCREATE(CCGExeView)

// Attributes
public:
	CCGExeDoc* GetDocument();
	CDDALine ddaLine;
	
	CMyLine myLine;
	
	BOOL isPressed;
	CPoint pt1,pt2;
	

	CChnCities chnCity;
	BOOL isCityLoaded;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGExeView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnPrepareDC(CDC* pDC, CPrintInfo* pInfo = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	CSpatialIndex *index;

	CGeoMap *map;
	CMapProject *mapPrj;

	CRect crWCRect;
	CConvexHull convexHull;

	CBezierCurve bezier;

	virtual ~CCGExeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCGExeView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CGExeView.cpp
inline CCGExeDoc* CCGExeView::GetDocument()
   { return (CCGExeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGEXEVIEW_H__303D2CD1_D56D_425B_AAC8_BBE8DA3D5EB3__INCLUDED_)
