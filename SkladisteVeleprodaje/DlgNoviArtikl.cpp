// DlgNoviArtikl.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgNoviArtikl.h"
#include "DlgArtikli.h"
#include "afxdialogex.h"


// DlgNoviArtikl dialog

IMPLEMENT_DYNAMIC(DlgNoviArtikl, CDialogEx)

DlgNoviArtikl::DlgNoviArtikl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_ARTIKLIMA_NOVI_PODATAK, pParent)
{

}

DlgNoviArtikl::~DlgNoviArtikl()
{
}

void DlgNoviArtikl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_EDIT_SIFRA_ARTIKLA, m_sifra);
	DDX_Control(pDX, IDC_EDIT_NAZIV_ARTIKLA, m_nazivArtikla);
	DDX_Control(pDX, IDC_EDIT_MJERA, m_mjera);
	DDX_Text(pDX, IDC_EDIT_CIJENA_VP, m_cijena);
	DDX_Control(pDX, IDC_EDIT_CIJENA_VP, m_edit_cijena);
}


BEGIN_MESSAGE_MAP(DlgNoviArtikl, CDialogEx)
	ON_BN_CLICKED(IDB_SPREMI, &DlgNoviArtikl::OnBnClickedSpremi)
END_MESSAGE_MAP()


// DlgNoviArtikl message handlers


void DlgNoviArtikl::OnBnClickedSpremi()
{
	UnesiNoviArtikl();
	//EndDialog(1);
}

void DlgNoviArtikl::UnesiNoviArtikl()
{
	ArtikliSet RecSetArtikli;
	long iduciID = 1;

	UpdateData(TRUE);

	CString sifra;
	m_sifra.GetWindowText(sifra);
	CString nazivArtikla;
	m_nazivArtikla.GetWindowText(nazivArtikla);
	CString mjera;
	m_mjera.GetWindowText(mjera);
	CString cijena;
	m_edit_cijena.GetWindowText(cijena);
	m_cijena = _wtof(cijena);


	if (!RecSetArtikli.IsOpen())
	{
		RecSetArtikli.Open();
	}

	if (!RecSetArtikli.IsBOF() && !RecSetArtikli.IsEOF())
	{
		iduciID = RecSetArtikli.MaxID() + 1;
	}

	long brojac = 0;
	RecSetArtikli.MoveFirst();
	
	while (!RecSetArtikli.IsBOF() && !RecSetArtikli.IsEOF())
	{
		if (sifra == RecSetArtikli.m_sifra)
		{
			brojac++;
		}
		RecSetArtikli.MoveNext();
	}

	if (brojac != 0)
	{
		CString s;
		s.LoadString(IDS_STRING_SIFRA_POSTOJI);
		MessageBox(s);
	}
	else
	{
		RecSetArtikli.AddNew();

		RecSetArtikli.m_rb = iduciID;
		RecSetArtikli.m_sifra = sifra;
		RecSetArtikli.m_nazivArtikla = nazivArtikla;
		RecSetArtikli.m_mjera = mjera;
		RecSetArtikli.m_cijena = m_cijena;

		RecSetArtikli.Update();
		RecSetArtikli.Close();

		EndDialog(IDOK);
	}

}