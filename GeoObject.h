// GeoObject.h: interface for the CGeoObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GEOOBJECT_H__697FE647_6D06_4429_9ECF_F6C6A31DD2D6__INCLUDED_)
#define AFX_GEOOBJECT_H__697FE647_6D06_4429_9ECF_F6C6A31DD2D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include  "afxtempl.h"

class CGeoObject  
{
public:
	void addPoint(CPoint pt);
	CGeoObject();
	virtual ~CGeoObject();
	CArray<CPoint,CPoint> pts;

};

#endif // !defined(AFX_GEOOBJECT_H__697FE647_6D06_4429_9ECF_F6C6A31DD2D6__INCLUDED_)
