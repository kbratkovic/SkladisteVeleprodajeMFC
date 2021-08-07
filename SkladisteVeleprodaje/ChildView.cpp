
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "SkladisteVeleprodaje.h"
#include "ChildView.h"
#include "DlgNoviKlijent.h"
#include "DlgNoviArtikl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	//ON_WM_PAINT() NAKNADNO IZBRISATI !!!!!!!!!!!!!!
	ON_COMMAND(ID_KLIJENTI_NOVIKLIJENT, &CChildView::OnKlijentiNoviklijent)
	ON_COMMAND(ID_ARTIKLI_NOVIARTIKL, &CChildView::OnArtikliNoviartikl)
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}


// NAKNADNO IZBRISATI !!!!!!!!!!!!!!
//void CChildView::OnPaint() 
//{
//	CPaintDC dc(this); // device context for painting
//	CRect rc;
//	GetClientRect(&rc);
//	dc.Ellipse(rc);
//	// TODO: Add your message handler code here
//	
//	// Do not call CWnd::OnPaint() for painting messages
//}


void CChildView::OnKlijentiNoviklijent()
{
	DlgNoviKlijent dlgKlijent;
	dlgKlijent.DoModal();
	// TODO: Add your command handler code here
}


void CChildView::OnArtikliNoviartikl()
{
	DlgNoviArtikl dlgArtikl;
	dlgArtikl.DoModal();
	// TODO: Add your command handler code here
}
