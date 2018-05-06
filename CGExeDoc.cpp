// CGExeDoc.cpp : implementation of the CCGExeDoc class
//

#include "stdafx.h"
#include "CGExe.h"

#include "CGExeDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCGExeDoc

IMPLEMENT_DYNCREATE(CCGExeDoc, CDocument)

BEGIN_MESSAGE_MAP(CCGExeDoc, CDocument)
	//{{AFX_MSG_MAP(CCGExeDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCGExeDoc construction/destruction

CCGExeDoc::CCGExeDoc()
{
	// TODO: add one-time construction code here

}

CCGExeDoc::~CCGExeDoc()
{
}

BOOL CCGExeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCGExeDoc serialization

void CCGExeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCGExeDoc diagnostics

#ifdef _DEBUG
void CCGExeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCGExeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCGExeDoc commands
