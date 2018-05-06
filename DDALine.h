// DDALine.h: interface for the CDDALine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDALINE_H__6A389E3F_1EFF_4BA4_8D03_979687C4AD00__INCLUDED_)
#define AFX_DDALINE_H__6A389E3F_1EFF_4BA4_8D03_979687C4AD00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDDALine  
{
public:
	void DrawM(CDC *pDC);
	int color;
	void setPoint(int x1,int y1,int x2,int y2);
	void Draw(CDC*pDC);
	int x2,y2;
	int x1,y1;
	CDDALine();
	virtual ~CDDALine();

};

#endif // !defined(AFX_DDALINE_H__6A389E3F_1EFF_4BA4_8D03_979687C4AD00__INCLUDED_)
