// prop_sheetDoc.h : interface of the Cprop_sheetDoc class
//


#pragma once


class Cprop_sheetDoc : public CDocument
{
protected: // create from serialization only
	Cprop_sheetDoc();
	DECLARE_DYNCREATE(Cprop_sheetDoc)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~Cprop_sheetDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};


