// DlgStavkeNoviPodatak.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgStavkeNoviPodatak.h"
#include "DlgArtikli.h"
#include "afxdialogex.h"
#include "DlgOdaberiArtikl.h"


// DlgStavkeNoviPodatak dialog

IMPLEMENT_DYNAMIC(DlgStavkeNoviPodatak, CDialogEx)

DlgStavkeNoviPodatak::DlgStavkeNoviPodatak(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STAVKE_NOVI_PODATAK, pParent)
	, m_kolicina(0)
	, m_rabat(0)
{

}

DlgStavkeNoviPodatak::~DlgStavkeNoviPodatak()
{
}

void DlgStavkeNoviPodatak::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ARTIKL_SIFRA, m_artiklSifra);
	DDX_Text(pDX, IDC_STATIC_ARTIKL_OPIS, m_artiklNaziv);
	DDX_Text(pDX, IDC_EDIT_KOLICINA, m_kolicina);
	DDX_Text(pDX, IDC_EDIT_RABAT, m_rabat);
	DDX_Text(pDX, IDC_EDIT_FAKTURNA_CIJENA, m_fakturnaCijena);
	DDX_Text(pDX, IDC_EDIT_NABAVNA_CIJENA, m_nabavnaCijena);
	DDX_Text(pDX, IDC_EDIT_VPC, m_vpc);
}


BEGIN_MESSAGE_MAP(DlgStavkeNoviPodatak, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgStavkeNoviPodatak::OnBnClickedOdaberiArtikl)
	ON_BN_CLICKED(IDB_SPREMI, &DlgStavkeNoviPodatak::OnBnClickedSpremi)
END_MESSAGE_MAP()


// DlgStavkeNoviPodatak message handlers


void DlgStavkeNoviPodatak::OnBnClickedOdaberiArtikl()
{
	UpdateData(TRUE);

	DlgOdaberiArtikl dlgOdaberiArtikl;

	dlgOdaberiArtikl.m_sifraArtikla = m_artiklSifra;
	dlgOdaberiArtikl.m_nazivArtikla = m_artiklNaziv;

	if (dlgOdaberiArtikl.DoModal() == IDOK)
	{
		m_artiklSifra = dlgOdaberiArtikl.m_sifraArtikla;
		m_artiklNaziv = dlgOdaberiArtikl.m_nazivArtikla;
		UpdateData(FALSE);
	}
	// TODO: Add your control notification handler code here
}


void DlgStavkeNoviPodatak::OnBnClickedSpremi()
{
	// TODO: Add your control notification handler code here
}
