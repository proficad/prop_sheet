// prop_sheetView.h : interface of the Cprop_sheetView class
//


#pragma once


class Cprop_sheetView : public CView
{
protected: // create from serialization only
	Cprop_sheetView();
	DECLARE_DYNCREATE(Cprop_sheetView)

// Attributes
public:
	Cprop_sheetDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Cprop_sheetView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnContextMenu(CWnd*, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnNcPaint();
	afx_msg void OnFilePrintPreview();
	afx_msg LRESULT OnPrintClient(WPARAM wp, LPARAM lp);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in prop_sheetView.cpp
inline Cprop_sheetDoc* Cprop_sheetView::GetDocument() const
	{ return reinterpret_cast<Cprop_sheetDoc*>(m_pDocument); }
#endif

