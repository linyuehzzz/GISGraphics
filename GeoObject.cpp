// GeoObject.cpp: implementation of the CGeoObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGExe.h"
#include "GeoObject.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGeoObject::CGeoObject()
{

}

CGeoObject::~CGeoObject()
{

}

void CGeoObject::addPoint(CPoint pt)
{
	pts.Add(pt);
}
