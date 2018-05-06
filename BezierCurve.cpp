// BezierCurve.cpp: implementation of the CBezierCurve class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGExe.h"
#include "BezierCurve.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CBezierCurve::CBezierCurve()
{

}

CBezierCurve::~CBezierCurve()
{

}

void CBezierCurve::addPoint_Cu(CPoint pt)
{
	CurvePts.Add(pt);
}

void CBezierCurve::Draw(CDC *pDC)
{
	CPoint pt;
	float t;
	int i;
	float step=0.01;
	for(t=0.0;t<=1.0;t+=step)
	{
		pt.x=(float)pow(1-t,3)*CtrlPts[0].x+(float)3*t*pow(1-t,2)*CtrlPts[1].x+(float)3*pow(t,2)*(1-t)*CtrlPts[2].x+(float)pow(t,3)*CtrlPts[3].x;
		pt.y=(float)pow(1-t,3)*CtrlPts[0].y+(float)3*t*pow(1-t,2)*CtrlPts[1].y+(float)3*pow(t,2)*(1-t)*CtrlPts[2].y+(float)pow(t,3)*CtrlPts[3].y;
		addPoint_Cu(pt);
	}
	int nCount=CurvePts.GetSize();
	for(i=0;i<=nCount;i++)
	{
		if(i==0)
			pDC->MoveTo(CtrlPts[0]);
		else if(i<nCount)
			pDC->LineTo(CurvePts[i-1]);
		else
			pDC->LineTo(CtrlPts[3]);
	}
}

void CBezierCurve::clearAllPoints()
{
	CtrlPts.RemoveAll();
}

void CBezierCurve::addPoint_Ct(CPoint pt)
{
	CtrlPts.Add(pt);
}
