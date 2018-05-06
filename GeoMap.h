// GeoMap.h: interface for the CGeoMap class.
//
//////////////////////////////////////////////////////////////////////
#include "GeoLayer.h"	// Added by ClassView
#include "MapProject.h"


#if !defined(AFX_GEOMAP_H__276A460E_BA5A_4B3D_9A28_08676907EDF1__INCLUDED_)
#define AFX_GEOMAP_H__276A460E_BA5A_4B3D_9A28_08676907EDF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include  "afxtempl.h"

class CGeoMap  
{
public:
	void clipMap(CRect clipRect1);
	void addLayer(CGeoLayer *layer);
	void Draw(CDC *pDC);
	/*void Draw(CDC *pDC,CMapProject *mapPrj);*/
	CRect clipRect;
	CRect wcRect;

	CArray<CGeoLayer *, CGeoLayer *> geoLayers;

	CGeoMap();
	virtual ~CGeoMap();

};

#endif // !defined(AFX_GEOMAP_H__276A460E_BA5A_4B3D_9A28_08676907EDF1__INCLUDED_)
