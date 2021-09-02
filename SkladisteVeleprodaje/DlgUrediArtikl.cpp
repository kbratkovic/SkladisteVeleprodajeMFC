// DlgUrediArtikl.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgUrediArtikl.h"
#include "ArtikliSet.h"
#include "afxdialogex.h"


// DlgUrediArtikl dialog

IMPLEMENT_DYNAMIC(DlgUrediArtikl, CDialogEx)

DlgUrediArtikl::DlgUrediArtikl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_ARTIKLIMA_UREDI_ARTIKL, pParent)
	, m_sifra(_T(""))
	, m_nazivArtikla(_T(""))
	, m_mjera(_T(""))
	, m_cijena(_T(""))
{

}

DlgUrediArtikl::~DlgUrediArtikl()
{
}

void DlgUrediArtikl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SIFRA, m_sifra);
	DDX_Text(pDX, IDC_EDIT_NAZIV_ARTIKLA, m_nazivArtikla);
	DDX_Text(pDX, IDC_EDIT_MJERA, m_mjera);
	DDX_Text(pDX, IDC_EDIT_CIJENA_VP, m_cijena);
}


BEGIN_MESSAGE_MAP(DlgUrediArtikl, CDialogEx)
	ON_BN_CLICKED(IDB_SPREMI, &DlgUrediArtikl::OnBnClickedSpremi)
END_MESSAGE_MAP()


// DlgUrediArtikl message handlers


BOOL DlgUrediArtikl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	sifra = m_sifra;
	nazivArtikla = m_nazivArtikla;
	mjera = m_mjera;
	cijena = m_cijena;

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void DlgUrediArtikl::OnBnClickedSpremi()
{
	ArtikliSet RecSetArtikli;

	UpdateData(TRUE);

	if (!RecSetArtikli.IsOpen())
	{
		RecSetArtikli.Open();
	}

	while (!RecSetArtikli.IsBOF() && !RecSetArtikli.IsEOF())
	{
		if (sifra == RecSetArtikli.m_sifra)
		{
			RecSetArtikli.Edit();
			
			RecSetArtikli.m_sifra = m_sifra;
			RecSetArtikli.m_nazivArtikla = m_nazivArtikla;
			RecSetArtikli.m_mjera = m_mjera;
			RecSetArtikli.m_cijena = _wtof(m_cijena);

			RecSetArtikli.Update();
			break;
		}
		RecSetArtikli.MoveNext();
	}
	EndDialog(IDOK);
}
