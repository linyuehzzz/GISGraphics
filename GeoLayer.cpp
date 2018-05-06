// GeoLayer.cpp: implementation of the CGeoLayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGExe.h"
#include "GeoLayer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGeoLayer::CGeoLayer()
{

}

CGeoLayer::~CGeoLayer()
{

}

void CGeoLayer::Draw(CDC *pDC)
{
	//空间索引
	/*CSpatialObject *object;
	int size=spacialObjects.GetSize();
	int r=100000;
	for(int i=0;i<size;i++)
	{
		object=spacialObjects.GetAt(i);
		pDC->Ellipse(object->lon,object->lat,object->lon+r,object->lat+r);
	}*/

	//地图填充
    /*CGeoPolygon *poly;
	int size=geoPolygons.GetSize();
	for(int i=0;i<size;i++)
	{
		poly = (CGeoPolygon*)geoPolygons.GetAt(i);
		poly->Draw(pDC,mapPrj);
	}*/

	//地图投影
    /*CGeoPolyline *poly;
	int size=geoPolylines.GetSize();
	for(int i=0;i<size;i++)
	{
		poly = (CGeoPolyline*)geoPolylines.GetAt(i);
		poly->Draw(pDC,mapPrj);
	}*/

	//图形裁切
    CGeoPolyline *poly;
	int size=geoPolylines.GetSize();
	for(int i=0;i<size;i++)
	{
		poly = (CGeoPolyline*)geoPolylines.GetAt(i);
		poly->Draw(pDC);
	}
}


void CGeoLayer::addPolyline(CGeoPolyline *poly)
{
	geoPolylines.Add(poly);
}

void CGeoLayer::clipLayer(CRect clipRect1)
{
	CGeoPolyline *poly;
	int size=geoPolylines.GetSize();
	for(int i=0;i<size;i++)
	{
		poly=(CGeoPolyline*)geoPolylines.GetAt(i);
		poly->clipPolyline(clipRect1);
	}
}

void CGeoLayer::addPolygon(CGeoPolygon *poly)
{
	geoPolygons.Add(poly);
}

void CGeoLayer::addObject(CSpatialObject *object)
{
	spacialObjects.Add(object);
}
