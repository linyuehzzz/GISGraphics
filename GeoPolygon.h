// GeoPolygon.h: interface for the CGeoPolygon class.
//
//////////////////////////////////////////////////////////////////////
#include "GeoObject.h"
#include "MapProject.h"

#if !defined(AFX_GEOPOLYGON_H__8A3B21A2_FB53_49EC_82F7_A36D1A688D42__INCLUDED_)
#define AFX_GEOPOLYGON_H__8A3B21A2_FB53_49EC_82F7_A36D1A688D42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include  "afxtempl.h"

class CGeoPolygon
{
public:
	void addCtPts(CPoint pt);
	float dist(CPoint pt1, CPoint pt2);
	float crossProduct(CPoint pt1, CPoint pt2,CPoint pt);
	bool InsideConvexPolygon(CPoint p1,CPoint p0,CPoint p2,CPoint q);
	CPoint getCenterPt();
	void addPts(CPoint pt);
	void Draw(CDC *pDC,CMapProject *mapPrj);
	CArray<CPoint,CPoint> pts;
	CArray<CPoint,CPoint> ctPts;
	CArray<CPoint,CPoint> prjPts;
	CPoint pt;
	CGeoPolygon();
	virtual ~CGeoPolygon();

};

#endif // !defined(AFX_GEOPOLYGON_H__8A3B21A2_FB53_49EC_82F7_A36D1A688D42__INCLUDED_)
