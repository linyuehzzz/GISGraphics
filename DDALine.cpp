// DDALine.cpp: implementation of the CDDALine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGExe.h"
#include "DDALine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDDALine::CDDALine()
{

}

CDDALine::~CDDALine()
{

}

void CDDALine::Draw(CDC *pDC)
{
	int x;
	float dx,dy,k,y;
	dx=x2-x1;
	dy=y2-y1;
	k=dy/dx;
	y=y1;
	for(x=x1;x<=x2;x++)
	{
		pDC->SetPixel(x,int (y+0.5), color); 
		y=y+k;
	}
}
	

void CDDALine::setPoint(int x1, int y1, int x2, int y2)
{
	this->x1=x1;
	this->y1=y1;
	this->x2=x2;
	this->y2=y2;
}

void CDDALine::DrawM(CDC *pDC)
{
	float x,y,k;
	float dx,dy,n;
	dx=x2-x1;
	dy=y2-y1;

	int r=2;
	pDC->Ellipse(x1-r,y1-r,x1+r,y1+r);
	pDC->Ellipse(x2-r,y2-r,x2+r,y2+r);

	n=abs(dx)>abs(dy)?abs(dx):abs(dy);

	x=x1;
	y=y1;
	dx=dx/n;
	dy=dy/n;
	for(int i=0;i<n;i++)
	{
		pDC->SetPixel(x,y,RGB(255,0,0));
		Sleep(5);
		x=x+dx;
		y=y+dy;
	}
}
