// CGExe.h : main header file for the CGEXE application
//

#if !defined(AFX_CGEXE_H__904F43DF_9B48_4AE8_8083_9CB861AF0248__INCLUDED_)
#define AFX_CGEXE_H__904F43DF_9B48_4AE8_8083_9CB861AF0248__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCGExeApp:
// See CGExe.cpp for the implementation of this class
//

class CCGExeApp : public CWinApp
{
public:
	CCGExeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGExeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCGExeApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGEXE_H__904F43DF_9B48_4AE8_8083_9CB861AF0248__INCLUDED_)
