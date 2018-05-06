// SpatialObject.h: interface for the CSpatialObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPATIALOBJECT_H__4ED866D1_6ECB_4F00_8400_E2C00C3156F7__INCLUDED_)
#define AFX_SPATIALOBJECT_H__4ED866D1_6ECB_4F00_8400_E2C00C3156F7__INCLUDED_

#include "afxtempl.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CSpatialObject  
{
public:
	void Draw(CDC *pDC);
	void getDistance(float x,float y);
	int Id;
	float lon,lat;
	CString name;
	

	CSpatialObject();
	virtual ~CSpatialObject();

};

#endif // !defined(AFX_SPATIALOBJECT_H__4ED866D1_6ECB_4F00_8400_E2C00C3156F7__INCLUDED_)
