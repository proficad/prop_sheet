// prop_sheet.h : main header file for the prop_sheet application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// Cprop_sheetApp:
// See prop_sheet.cpp for the implementation of this class
//

class Cprop_sheetApp : public CBCGPWinApp
{
public:
	Cprop_sheetApp();

	// Override from CBCGPWorkspace
	virtual void PreLoadState();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	virtual BOOL SaveAllModified();


// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cprop_sheetApp theApp;
