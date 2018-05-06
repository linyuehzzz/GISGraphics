// MapProject.cpp: implementation of the CMapProject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGExe.h"
#include "MapProject.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CMapProject::CMapProject()
{

}

CMapProject::~CMapProject()
{

}

void CMapProject::getXY(float L,float B,float *x,float *y)
{
	//WGS84
	float a=6378137,b=6356863.01877;  
	float B0 =PI/6, L0 =(112/180)*PI;
	float e1=sqrt(1-pow((b/a),2)); //第一偏心率
	float e2=sqrt(pow((a/b),2)-1); //第二偏心率
	float Nb0 = (a*a/b)/sqrt(1+e2*e2*cos(B0)*cos(B0));             
	float K=Nb0*cos(B0);
	*x=K*((L/180)*PI-(L0/180)*PI);
	*y=K*log(tan(PI/4+(B/360)*PI)*pow((1-e1*sin((B/180)*PI))/(1+e1*sin((B/180)*PI)),e1/2));
}

void CMapProject::getLB(float x,float y,float *L,float *B)
{

}

void CMapProject::Draw(CDC *pDC)
{
	float i,j;
	CPoint pt;
	float x,y;
	for(i=5;i<=55;i+=10)    //绘制纬线
	{
		for(j=70;j<=140;j+=10)
		{
			getXY(j,i,&x,&y);
			pt.x=x;
			pt.y=y;
			if(j==70) 
				pDC->MoveTo(pt);
			else 
				pDC->LineTo(pt);
		}
	}


	for(j=70;j<=140;j+=10)    //绘制经线
	{
		for(i=5;i<=55;i+=10)
		{
			getXY(j,i,&x,&y);
			pt.x=x;
			pt.y=y;
			if(i==5) 
				pDC->MoveTo(pt);
			else 
				pDC->LineTo(pt);
		}
	}
}

