// ChnCities.cpp: implementation of the CChnCities class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGExe.h"
#include "ChnCities.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChnCities::CChnCities()
{

}

CChnCities::~CChnCities()
{

}

void CChnCities::addCity(CITY city)
{
	cities.Add(city);
}

void CChnCities::Draw(CDC *pDC)
{
	int size=cities.GetSize();
	CITY ocity;
	int r=100000;
	for(int i=0;i<size;i++)
	{
		ocity=cities.GetAt(i);
		pDC->Ellipse(ocity.lon,ocity.lat,ocity.lon+r,ocity.lat+r);
	}
}
