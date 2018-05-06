// GeoPolyline.h: interface for the CGeoPolyline class.
//
//////////////////////////////////////////////////////////////////////
#include "MapProject.h"


#if !defined(AFX_GEOPOLYLINE_H__43533576_D23F_4355_87DF_1C81A4F7E736__INCLUDED_)
#define AFX_GEOPOLYLINE_H__43533576_D23F_4355_87DF_1C81A4F7E736__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include  "afxtempl.h"

class CGeoPolyline  
{
public:
	void addMyPoint(CPoint pt);
	void clipPolyline(CRect clipRect1);
	void addPoint(CPoint pt);
	CArray<CPoint,CPoint> pts;
	CArray<CPoint,CPoint> clipPts;
	CArray<CPoint,CPoint> mapPts;
	void Draw(CDC *pDC);
	//void Draw(CDC *pDC,CMapProject *mapPrj);
	CGeoPolyline();
	virtual ~CGeoPolyline();

};

#endif // !defined(AFX_GEOPOLYLINE_H__43533576_D23F_4355_87DF_1C81A4F7E736__INCLUDED_)
