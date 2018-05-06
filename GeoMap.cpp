// GeoMap.cpp: implementation of the CGeoMap class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGExe.h"
#include "GeoMap.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGeoMap::CGeoMap()
{

}

CGeoMap::~CGeoMap()
{

}

void CGeoMap::Draw(CDC *pDC)
{
	CGeoLayer *layer;
	int size=geoLayers.GetSize();
	for(int i=0;i<size;i++)
	{
		layer = (CGeoLayer*)geoLayers.GetAt(i);
		layer->Draw(pDC);
	}
}

void CGeoMap::addLayer(CGeoLayer *layer)
{
	geoLayers.Add(layer);
}

void CGeoMap::clipMap(CRect clipRect1)
{
	CGeoLayer *layer;
	int size=geoLayers.GetSize();
	for(int i=0;i<size;i++)
	{
		layer = (CGeoLayer*)geoLayers.GetAt(i);
		layer->clipLayer(clipRect1);
	}
}
