
// SkladisteVeleprodaje.h : main header file for the SkladisteVeleprodaje application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSkladisteVeleprodajeApp:
// See SkladisteVeleprodaje.cpp for the implementation of this class
//

class CSkladisteVeleprodajeApp : public CWinApp
{
public:
	CSkladisteVeleprodajeApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSkladisteVeleprodajeApp theApp;
