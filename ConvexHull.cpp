// ConvexHull.cpp: implementation of the CConvexHull class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGExe.h"
#include "ConvexHull.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CConvexHull::CConvexHull()
{

}

CConvexHull::~CConvexHull()
{

}


void CConvexHull::Draw(CDC *pDC)
{
	CPoint pt;
	int r = 2;
	int size = pts.GetSize();
	for(int i=0;i<size;i++)
	{
		pt = (CPoint)pts.GetAt(i);
		pDC->Ellipse(pt.x-r,pt.y-r,pt.x+r,pt.y+r);
	}
	
	r = 1;
	size = Chpts.GetSize();
	for(i=0;i<size;i++)
	{
		pt = (CPoint)Chpts.GetAt(i);
		pDC->Ellipse(pt.x-r,pt.y-r,pt.x+r,pt.y+r);
		if(i==0) pDC->MoveTo(pt);
		else pDC->LineTo(pt);
	}

}


float CConvexHull::getAngle(CPoint p1, CPoint p2, CPoint p3)
{
	return((p2.x-p1.x)*(p3.x-p2.x) + (p2.y-p1.y)*(p3.y-p2.y))/sqrt((p3.x-p2.x)*(p3.x-p2.x)+(p3.y-p2.y)*(p3.y-p2.y));  
}


void CConvexHull::getConvexHull()
{
	CPoint prept=(CPoint)pts.GetAt(0),inpt;
	int size = pts.GetSize();
	int temp=0;
	
	for(int i=1;i<size;i++)
	{
		inpt = (CPoint)pts.GetAt(i);
		if(prept.y>inpt.y||(prept.y==inpt.y&&prept.x>inpt.x))
		{
			prept = inpt;
			temp = i;
		}				
	}
	prept=(CPoint)pts.GetAt(temp);
	Chpts.Add(prept); 
	
	inpt=prept;  
	prept.x=prept.x-1; 
	CPoint pt=inpt;
	
	do{
		float cos0=-1;
		int id=0;
		for(i=0;i<size;i++)
		{
			CPoint p0=(CPoint)pts.GetAt(i);
			if(getAngle(prept,inpt,p0)>=cos0)
			{
				cos0=getAngle(prept,inpt,p0);
				id=i;
			}
		}
		prept = inpt; 
		inpt = (CPoint)pts.GetAt(id);  
		Chpts.Add(inpt);
	}while(pt!=inpt);


    /*CPoint pt;
	int size=pts.GetSize();
    int i,temp=0;
	if(size<1) return;

	CPoint minpt=(CPoint)pts.GetAt(0);
	for(i=1;i<size;i++) 
	{
		pt=(CPoint)pts.GetAt(i);
		if(pt.y<minpt.y)  
        {  
			minpt=pt;
            temp=i;  
        }
    }
	pt=(CPoint)pts.GetAt(temp);      //找出最下偏左的点
	Chpts.Add(pt);
	
	CPoint inpt=pt,originPt=pt;
	pt.x=pt.x-1;
	int id;
	do{
		float cosA=-1.0;
		for(i=0;i<size;i++)
		{
			CPoint p0=(CPoint)pts.GetAt(i);
			if(getAngle(inpt,pt,p0)>=cosA)
			{
				cosA=getAngle(inpt,pt,p0);
				id=i;
			}
		}
		pt=inpt;
		pt=(CPoint)pts.GetAt(id);
		Chpts.Add(pt);
	}while(pt!=originPt);*/

}


