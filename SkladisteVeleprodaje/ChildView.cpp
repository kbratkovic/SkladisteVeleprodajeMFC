
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "SkladisteVeleprodaje.h"
#include "ChildView.h"
#include "DlgNoviKlijent.h"
#include "DlgNoviArtikl.h"
#include "DlgArtikli.h"
#include "DlgKlijenti.h"
#include "DlgPrimke.h"
#include "DlgNovaPrimka.h"

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
	ON_COMMAND(ID_KLIJENTI_NOVIKLIJENT, &CChildView::OnKlijentiNoviklijent)
	ON_COMMAND(ID_ARTIKLI_NOVIARTIKL, &CChildView::OnArtikliNoviartikl)
	ON_COMMAND(ID_ARTIKLI_ARTIKLI, &CChildView::OnArtikliSviArtikli)
	ON_COMMAND(ID_KLIJENTI_KLIJENTI, &CChildView::OnKlijentiSviKlijenti)
	ON_COMMAND(ID_PRIMKE_PRIMKE, &CChildView::OnPrimkeSvePrimke)
	ON_COMMAND(ID_PRIMKE_NOVAPRIMKA, &CChildView::OnPrimkeNovaprimka)
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


void CChildView::OnArtikliNoviartikl()
{
	DlgNoviArtikl dlgNoviArtikl;
	dlgNoviArtikl.DoModal();
}


void CChildView::OnArtikliSviArtikli()
{
	DlgArtikli dlgArtikli;
	dlgArtikli.DoModal();
}


void CChildView::OnKlijentiNoviklijent()
{
	DlgNoviKlijent dlgKlijent;
	dlgKlijent.DoModal();
}


void CChildView::OnKlijentiSviKlijenti()
{
	DlgKlijenti dlgKlijenti;
	dlgKlijenti.DoModal();
	// TODO: Add your command handler code here
}


void CChildView::OnPrimkeNovaprimka()
{
	DlgNovaPrimka dlgNovaPrimka;
	dlgNovaPrimka.DoModal();
	// TODO: Add your command handler code here
}


void CChildView::OnPrimkeSvePrimke()
{
	DlgPrimke dlgPrimke;
	dlgPrimke.DoModal();
	// TODO: Add your command handler code here
}


