// MapProject.h: interface for the CMapProject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAPPROJECT_H__E02D5215_9AA0_464A_B486_5A40E466D9BD__INCLUDED_)
#define AFX_MAPPROJECT_H__E02D5215_9AA0_464A_B486_5A40E466D9BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include  "afxtempl.h"

#define PI 3.141592
#define	E 2.71828

class CMapProject  
{
public:
	void Draw(CDC *pDC);
	void getLB(float x,float y,float *L,float *B);
	void getXY(float L,float B,float *x,float *y);
	CMapProject();
	virtual ~CMapProject();
};

#endif // !defined(AFX_MAPPROJECT_H__E02D5215_9AA0_464A_B486_5A40E466D9BD__INCLUDED_)
