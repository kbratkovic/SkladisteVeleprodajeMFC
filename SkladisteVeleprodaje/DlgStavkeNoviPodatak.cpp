// DlgStavkeNoviPodatak.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgStavkeNoviPodatak.h"
#include "DlgArtikli.h"
#include "afxdialogex.h"


// DlgStavkeNoviPodatak dialog

IMPLEMENT_DYNAMIC(DlgStavkeNoviPodatak, CDialogEx)

DlgStavkeNoviPodatak::DlgStavkeNoviPodatak(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STAVKE_NOVI_PODATAK, pParent)
{

}

DlgStavkeNoviPodatak::~DlgStavkeNoviPodatak()
{
}

void DlgStavkeNoviPodatak::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgStavkeNoviPodatak, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgStavkeNoviPodatak::OnBnClickedOdaberiArtikl)
END_MESSAGE_MAP()


// DlgStavkeNoviPodatak message handlers


void DlgStavkeNoviPodatak::OnBnClickedOdaberiArtikl()
{
	DlgArtikli dlg;
	dlg.DoModal();
	// TODO: Add your control notification handler code here
}
