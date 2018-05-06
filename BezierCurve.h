// BezierCurve.h: interface for the CBezierCurve class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BEZIERCURVE_H__C26C51FF_CE65_4DFB_8AFC_C1917B70F65E__INCLUDED_)
#define AFX_BEZIERCURVE_H__C26C51FF_CE65_4DFB_8AFC_C1917B70F65E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "afxtempl.h"

class CBezierCurve  
{
public:
	void addPoint_Ct(CPoint pt);
	void clearAllPoints();
	void Draw(CDC *pDC);
	void addPoint_Cu(CPoint pt);
	CArray<CPoint,CPoint>CtrlPts;
	CArray<CPoint,CPoint>CurvePts;
	CBezierCurve();
	virtual ~CBezierCurve();

};

#endif // !defined(AFX_BEZIERCURVE_H__C26C51FF_CE65_4DFB_8AFC_C1917B70F65E__INCLUDED_)
