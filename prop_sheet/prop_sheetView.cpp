// prop_sheetView.cpp : implementation of the Cprop_sheetView class
//

#include "stdafx.h"
#include "prop_sheet.h"

#include "prop_sheetDoc.h"
#include "prop_sheetView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cprop_sheetView

IMPLEMENT_DYNCREATE(Cprop_sheetView, CView)

BEGIN_MESSAGE_MAP(Cprop_sheetView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_ERASEBKGND()
	ON_WM_NCPAINT()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cprop_sheetView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_MESSAGE(WM_PRINTCLIENT, &Cprop_sheetView::OnPrintClient)
END_MESSAGE_MAP()

// Cprop_sheetView construction/destruction

Cprop_sheetView::Cprop_sheetView()
{
	// TODO: add construction code here

}

Cprop_sheetView::~Cprop_sheetView()
{
}

BOOL Cprop_sheetView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cprop_sheetView drawing

void Cprop_sheetView::OnDraw(CDC* pDC)
{
	Cprop_sheetDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
	if (!pDC->IsPrinting())
	{
		CRect rectClient;
		GetClientRect(rectClient);

		pDC->FillSolidRect(rectClient, CBCGPVisualManager::GetInstance()->GetControlFillColor());
	}
}


// Cprop_sheetView printing

void Cprop_sheetView::OnFilePrintPreview()
{
	BCGPPrintPreview (this);
}

BOOL Cprop_sheetView::OnPreparePrinting(CPrintInfo* pInfo)
{
	return BCGPPreparePrinting(this, pInfo);
}

void Cprop_sheetView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cprop_sheetView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Cprop_sheetView diagnostics

#ifdef _DEBUG
void Cprop_sheetView::AssertValid() const
{
	CView::AssertValid();
}

void Cprop_sheetView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cprop_sheetDoc* Cprop_sheetView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cprop_sheetDoc)));
	return (Cprop_sheetDoc*)m_pDocument;
}
#endif //_DEBUG


// Cprop_sheetView message handlers

BOOL Cprop_sheetView::OnEraseBkgnd(CDC* /*pDC*/)
{
	return TRUE;
}

LRESULT Cprop_sheetView::OnPrintClient(WPARAM wp, LPARAM lp)
{
	if ((lp & PRF_CLIENT) == PRF_CLIENT)
	{
		CDC* pDC = CDC::FromHandle((HDC)wp);
		ASSERT_VALID(pDC);

		OnDraw(pDC);
	}

	return 0;
}

void Cprop_sheetView::OnNcPaint()
{
	if (!CBCGPVisualManager::GetInstance()->OnDrawViewBorder(this))
	{
		Default();
	}
}

void Cprop_sheetView::OnContextMenu(CWnd*, CPoint point)
{
	if (CBCGPPopupMenu::GetSafeActivePopupMenu() != NULL)
	{
		return;
	}

	theApp.ShowPopupMenu(IDR_CONTEXT_MENU, point, this);
}
