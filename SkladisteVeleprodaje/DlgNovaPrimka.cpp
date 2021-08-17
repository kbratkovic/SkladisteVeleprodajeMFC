// DlgNovaPrimka.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgNovaPrimka.h"
#include "afxdialogex.h"
#include "DlgStavkeNoviPodatak.h"
#include "DlgKlijenti.h"


// DlgNovaPrimka dialog

IMPLEMENT_DYNAMIC(DlgNovaPrimka, CDialogEx)

DlgNovaPrimka::DlgNovaPrimka(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_PRIMKAMA_NOVI_PODATAK, pParent)
{

}

DlgNovaPrimka::~DlgNovaPrimka()
{
}

void DlgNovaPrimka::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgNovaPrimka, CDialogEx)
	ON_BN_CLICKED(IDB_DODAJ_NOVI, &DlgNovaPrimka::OnBnClickedDodajNovi)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgNovaPrimka::OnBnClickedOdaberiKlijenta)
END_MESSAGE_MAP()


// DlgNovaPrimka message handlers


void DlgNovaPrimka::OnBnClickedDodajNovi()
{
	DlgStavkeNoviPodatak dlg;
	dlg.DoModal();
	// TODO: Add your control notification handler code here
}


void DlgNovaPrimka::OnBnClickedOdaberiKlijenta()
{
	DlgKlijenti dlg;
	dlg.DoModal();
	// TODO: Add your control notification handler code here
}
