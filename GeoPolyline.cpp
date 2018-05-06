// GeoPolyline.cpp: implementation of the CGeoPolyline class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGExe.h"
#include "GeoPolyline.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGeoPolyline::CGeoPolyline()
{

}

CGeoPolyline::~CGeoPolyline()
{

}

void CGeoPolyline::Draw(CDC *pDC)
{
	/*int size = mapPts.GetSize();
	if(mapPrj==NULL)//没有地图投影的结果
	{
		pDC->Polyline(mapPts.GetData(),size);
	}
	else
	{
		float L,B;
		for(int i=0;i<size;i++)
		{
			CPoint pt1,pt2;
			float X,Y;
			pt1 = (CPoint)mapPts.GetAt(i);
			L=pt1.x/1000000.0;
			B=pt1.y/1000000.0;   //scale=1000000
			mapPrj->getXY(L,B,&X,&Y);
			pt2.x=X;
			pt2.y=Y;
			if(i==0) 
				pDC->MoveTo(pt2);
			else 
				pDC->LineTo(pt2);
		}
	
	}*/
	/*CPoint pt;
	int size = mapPts.GetSize();
	for(int i=0;i<size;i++)
	{
		pt = (CPoint)mapPts.GetAt(i);
		if(i==0) 
			pDC->MoveTo(pt);
		else 
			pDC->LineTo(pt);
	}*/

	//图形裁切
	CPoint pt;
	int size = pts.GetSize();
	for(int i=0;i<size;i++)
	{
		pt = (CPoint)pts.GetAt(i);
		if(i==0) 
			pDC->MoveTo(pt);
		else 
			pDC->LineTo(pt);
	}
	
	CPen pen(PS_SOLID,4,RGB(255,0,0));
	CPen *oldPen=pDC->SelectObject(&pen);

	size = clipPts.GetSize();
	for(i=0;i<size;i++)
	{
		pt = (CPoint)clipPts.GetAt(i);
		if(i==0) 
			pDC->MoveTo(pt);
		else 
			pDC->LineTo(pt);
	}

	pDC->SelectObject(oldPen);
}

void CGeoPolyline::addPoint(CPoint pt)
{
	pts.Add(pt);
}

void CGeoPolyline::clipPolyline(CRect clipRect1)
{

	int size=pts.GetSize();
	CPoint pt;
	for(int j=0;j<size;j++)
	{
		pt=(CPoint)pts.GetAt(j);
		if(clipRect1.PtInRect(pt))
		{
		clipPts.Add(pt);
		}
	}
}

void CGeoPolyline::addMyPoint(CPoint pt)
{
	mapPts.Add(pt);
}
