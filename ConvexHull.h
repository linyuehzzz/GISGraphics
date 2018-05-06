// ConvexHull.h: interface for the CConvexHull class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONVEXHULL_H__B6427AF0_2D52_4A4F_B05B_A820629DF9D7__INCLUDED_)
#define AFX_CONVEXHULL_H__B6427AF0_2D52_4A4F_B05B_A820629DF9D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include  "afxtempl.h"

class CConvexHull  
{
public:

	float getAngle(CPoint p1,CPoint p2,CPoint p3);

	CRect crWCRect;

	CArray<CPoint,CPoint>pts;
	CArray<CPoint,CPoint>Chpts;

	void Draw(CDC *pDC);
	void getConvexHull();
	CConvexHull();
	virtual ~CConvexHull();

};

#endif // !defined(AFX_CONVEXHULL_H__B6427AF0_2D52_4A4F_B05B_A820629DF9D7__INCLUDED_)
