// MyLine1.h: interface for the CMyLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYLINE1_H__75F9F9F7_DC2B_4C8C_A395_B3E838F1A780__INCLUDED_)
#define AFX_MYLINE1_H__75F9F9F7_DC2B_4C8C_A395_B3E838F1A780__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "afxtempl.h"

class CMyLine  
{
public:
	void FillPolygon(CDC *pDC,CPoint pt,int Color);
	CArray<CPoint,CPoint>pts;
	CArray<CPoint,CPoint>seeds;
	CString testStr;
	void setColor(int nColor);
	void setPoints(CPoint pta,CPoint ptb);
	void setPenStyle(int nPenStyle1);
	void setWidth(int nWidth);
	void Draw(CDC *pDC);
	int nWidth;
	int nPenStyle;
	int crColor;
	CPoint pt2;
	CPoint pt1;
	CMyLine();
	virtual ~CMyLine();

};

#endif // !defined(AFX_MYLINE1_H__75F9F9F7_DC2B_4C8C_A395_B3E838F1A780__INCLUDED_)
