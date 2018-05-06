// SpatialIndexArea.h: interface for the CSpatialIndexArea class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPATIALINDEXAREA_H__BC5A9B97_90FA_40DC_A850_0BCD6753048D__INCLUDED_)
#define AFX_SPATIALINDEXAREA_H__BC5A9B97_90FA_40DC_A850_0BCD6753048D__INCLUDED_

#include  "afxtempl.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSpatialIndexArea  
{
public:
	void Draw(CDC *pDC);
	float x1,y1,x2,y2;
	CArray<int,int> objIDs;
	CSpatialIndexArea();
	virtual ~CSpatialIndexArea();

};

#endif // !defined(AFX_SPATIALINDEXAREA_H__BC5A9B97_90FA_40DC_A850_0BCD6753048D__INCLUDED_)
