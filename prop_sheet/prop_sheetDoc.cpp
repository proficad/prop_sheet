// prop_sheetDoc.cpp : implementation of the Cprop_sheetDoc class
//

#include "stdafx.h"
#include "prop_sheet.h"

#include "prop_sheetDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cprop_sheetDoc

IMPLEMENT_DYNCREATE(Cprop_sheetDoc, CDocument)

BEGIN_MESSAGE_MAP(Cprop_sheetDoc, CDocument)
END_MESSAGE_MAP()


// Cprop_sheetDoc construction/destruction

Cprop_sheetDoc::Cprop_sheetDoc()
{
	// TODO: add one-time construction code here

}

Cprop_sheetDoc::~Cprop_sheetDoc()
{
}

BOOL Cprop_sheetDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

// Cprop_sheetDoc serialization

void Cprop_sheetDoc::Serialize(CArchive& ar)
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


// Cprop_sheetDoc diagnostics

#ifdef _DEBUG
void Cprop_sheetDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cprop_sheetDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cprop_sheetDoc commands
