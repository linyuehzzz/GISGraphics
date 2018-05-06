// GeoLayer.h: interface for the CGeoLayer class.
//
//////////////////////////////////////////////////////////////////////
#include "GeoPolyline.h"	// Added by ClassView
#include "GeoPolygon.h"
#include "SpatialObject.h"
#include "MapProject.h"


#if !defined(AFX_GEOLAYER_H__8BEBCA98_CF65_450D_8757_96DDBFFB7551__INCLUDED_)
#define AFX_GEOLAYER_H__8BEBCA98_CF65_450D_8757_96DDBFFB7551__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include  "afxtempl.h"

class CGeoLayer  
{
public:
	void addObject(CSpatialObject *object);
	void addPolygon(CGeoPolygon *poly);
	void Draw(CDC *pDC);
	void clipLayer(CRect clipRect1);
	void addPolyline(CGeoPolyline *poly);
	CArray<CGeoPolyline *,CGeoPolyline *> geoPolylines;
	CArray<CGeoPolygon *,CGeoPolygon *> geoPolygons;
	CArray<CSpatialObject *,CSpatialObject *> spacialObjects;

	//void Draw(CDC *pDC,CMapProject *mapPrj);

	CGeoLayer();
	virtual ~CGeoLayer();

};

#endif // !defined(AFX_GEOLAYER_H__8BEBCA98_CF65_450D_8757_96DDBFFB7551__INCLUDED_)
