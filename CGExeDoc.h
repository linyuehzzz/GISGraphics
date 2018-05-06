// CGExeDoc.h : interface of the CCGExeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CGEXEDOC_H__6C2423ED_5AFE_48D6_9DC2_A08B72227F19__INCLUDED_)
#define AFX_CGEXEDOC_H__6C2423ED_5AFE_48D6_9DC2_A08B72227F19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCGExeDoc : public CDocument
{
protected: // create from serialization only
	CCGExeDoc();
	DECLARE_DYNCREATE(CCGExeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGExeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCGExeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCGExeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGEXEDOC_H__6C2423ED_5AFE_48D6_9DC2_A08B72227F19__INCLUDED_)
