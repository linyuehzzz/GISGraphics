// SpatialIndex.h: interface for the CSpatialIndex class.
//
//////////////////////////////////////////////////////////////////////
#include "SpatialIndexArea.h"

#if !defined(AFX_SPATIALINDEX_H__02C892CA_F661_4319_B835_DB9036E17DC9__INCLUDED_)
#define AFX_SPATIALINDEX_H__02C892CA_F661_4319_B835_DB9036E17DC9__INCLUDED_

#include  "afxtempl.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSpatialIndex  
{
public:
	int m,n;
	void Draw(CDC *pDC);
	CRect wcRect;
	CArray<CSpatialIndexArea *,CSpatialIndexArea *>indexArea;
	CSpatialIndex();
	virtual ~CSpatialIndex();

};

#endif // !defined(AFX_SPATIALINDEX_H__02C892CA_F661_4319_B835_DB9036E17DC9__INCLUDED_)
