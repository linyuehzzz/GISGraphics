// MyLine1.cpp: implementation of the CMyLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CGExe.h"
#include "MyLine1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyLine::CMyLine()
{
	crColor=RGB(255,0,0);
	nPenStyle=PS_DASH;
	nWidth=1;
	pt1=CPoint(300,100);
	pt2=CPoint(500,400);
	testStr="武汉大学";

	pts.Add(CPoint(600,100));
	pts.Add(CPoint(500,300));
	pts.Add(CPoint(560,400));
	pts.Add(CPoint(800,300));
	pts.Add(CPoint(600,200));
	pts.Add(CPoint(700,150));
	pts.Add(CPoint(600,100));

}

CMyLine::~CMyLine()
{

}

void CMyLine::setWidth(int nWidth)
{
	nWidth=4;
}

void CMyLine::setPenStyle(int nPenStyle1)
{
	nPenStyle=nPenStyle1;
}

void CMyLine::setPoints(CPoint pta, CPoint ptb)
{
	
}

void CMyLine::setColor(int nColor)
{
	nColor=RGB(0,0,255);
}

void CMyLine::Draw(CDC *pDC)
{
	//构造一个CPen对象，用来绘制直线段
	CPen pen(nPenStyle,nWidth,crColor);

	//让PDC选用该对象作为绘图笔，同时把原来默认的绘图笔保存在oldPen中
	CPen *oldPen=pDC->SelectObject(&pen);

	//绘制线段
	pDC->MoveTo(pt1);
	pDC->LineTo(pt2);

	//恢复绘图笔
	pDC->SelectObject(oldPen);

	//绘制文字
	CFont font;
	//设置字体、字大、字小
	font.CreateFont(20,0,0,0,FW_MEDIUM,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,"楷体");
	//设置选用字体，并保存原有字体信息到pFont
	CFont *pFont=pDC->SelectObject(&font);

	//绘制文字
	pDC->TextOut(400,200,testStr);

	//恢复文字信息
	pDC->SelectObject(pFont);

	int size=pts.GetSize();
	for(int i=0;i<size;i++)
	{
		if(i==0)
			pDC->MoveTo(pts[i]);
		else
			pDC->LineTo(pts[i]);
	}
/*	FillPolygon(pDC,CPoint(600,120),RGB(255,0,0));*/
}


void CMyLine::FillPolygon(CDC *pDC, CPoint pt, int Color)
{
	HDC hdc;
	if (GetPixel(hdc,pt.x,pt.y) != crColor&&GetPixel(hdc,pt.x,pt.y) != Color)
	{
		SetPixel(hdc,pt.x,pt.y,Color);
	FillPolygon(pDC,(pt.x+1,pt.y),Color);
	FillPolygon(pDC,(pt.x-1,pt.y), Color);
	FillPolygon(pDC,(pt.x,pt.y+1), Color);
	FillPolygon(pDC,(pt.x,pt.y-1), Color);	
	FillPolygon(pDC,(pt.x+1,pt.y-1), Color);
	FillPolygon(pDC,(pt.x-1,pt.y-1), Color);
	FillPolygon(pDC,(pt.x+1,pt.y+1), Color);
	FillPolygon(pDC,(pt.x-1,pt.y+1), Color);
	}
}

