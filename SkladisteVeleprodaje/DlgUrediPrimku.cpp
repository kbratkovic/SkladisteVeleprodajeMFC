// DlgUrediPrimku.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgUrediPrimku.h"
#include "afxdialogex.h"
#include "DlgOdaberiKlijenta.h"
#include "StavkePrimkeSet.h"
#include "ArtikliSet.h"
#include "DlgStavkeNoviPodatak.h"


// DlgUrediPrimku dialog

IMPLEMENT_DYNAMIC(DlgUrediPrimku, CDialogEx)

DlgUrediPrimku::DlgUrediPrimku(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_PRIMKAMA_UREDI_PODATAK, pParent)
	, m_primkaID(_T(""))
	, m_datum(_T(""))
	, m_nazivKlijenta(_T(""))
	, m_brojRacuna(_T(""))
{

}

DlgUrediPrimku::~DlgUrediPrimku()
{
}

void DlgUrediPrimku::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BROJ_PRIMKE, m_primkaID);
	DDX_Text(pDX, IDC_EDIT_DATUM_PRIMKE, m_datum);
	DDX_Text(pDX, IDC_EDIT_KLIJENT, m_nazivKlijenta);
	DDX_Text(pDX, IDC_EDIT_BROJ_RACUNA, m_brojRacuna);
	DDX_Control(pDX, IDC_LIST1, ListCtrl);
}


BEGIN_MESSAGE_MAP(DlgUrediPrimku, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &DlgUrediPrimku::OnBnClickedOdaberiKlijenta)
	ON_BN_CLICKED(IDB_DODAJ, &DlgUrediPrimku::OnBnClickedDodajNoviArtikl)
	ON_BN_CLICKED(IDB_SPREMI, &DlgUrediPrimku::OnBnClickedSpremi)
END_MESSAGE_MAP()


// DlgUrediPrimku message handlers


BOOL DlgUrediPrimku::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	PrikaziListu();
	PrikaziArtikle();
	brojClanovaListeOnInitDialog = ListCtrl.GetItemCount();
	CString s;
	s.Format(_T("%d"), brojClanovaListeOnInitDialog);
	MessageBox(s);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void DlgUrediPrimku::OnBnClickedOdaberiKlijenta()
{
	UpdateData(TRUE);

	DlgOdaberiKlijenta dlgOdaberiKlijenta;
	dlgOdaberiKlijenta.m_nazivKlijenta = m_nazivKlijenta;

	if (dlgOdaberiKlijenta.DoModal() == IDOK)
	{
		m_nazivKlijenta = dlgOdaberiKlijenta.m_nazivKlijenta;
		UpdateData(FALSE);
	}
}


void DlgUrediPrimku::PrikaziListu()
{
	CString s;

	s.LoadString(IDS_STRING_ID);
	ListCtrl.InsertColumn(1, s, LVCFMT_LEFT, 60);
	s.LoadString(IDS_STRING_SIFRA);
	ListCtrl.InsertColumn(2, s, LVCFMT_CENTER, 130);
	s.LoadString(IDS_STRING_NAZIV);
	ListCtrl.InsertColumn(3, s, LVCFMT_CENTER, 200);
	s.LoadString(IDS_STRING_KOLICINA);
	ListCtrl.InsertColumn(4, s, LVCFMT_CENTER, 100);
	s.LoadString(IDS_STRING_FAKTURNA);
	ListCtrl.InsertColumn(5, s, LVCFMT_CENTER, 150);
	s.LoadString(IDS_STRING_NABAVNA);
	ListCtrl.InsertColumn(6, s, LVCFMT_CENTER, 150);
	s.LoadString(IDS_STRING_PRODAJNA);
	ListCtrl.InsertColumn(7, s, LVCFMT_CENTER, 150);
}


void DlgUrediPrimku::PrikaziArtikle()
{
	StavkePrimkeSet RecSetStavkePrimke;

	if (!RecSetStavkePrimke.IsOpen())
	{
		RecSetStavkePrimke.Open();
	}

	while (!RecSetStavkePrimke.IsEOF())
	{
		long primkaID = _wtol(m_primkaID);

		if (RecSetStavkePrimke.m_primkaID == primkaID )
		{
			rb++;
			const int index = ListCtrl.GetItemCount();
			CString s;

			s.Format(_T("%d"), rb);
			ListCtrl.InsertItem(index, s);
			ListCtrl.SetItemText(index, 1, RecSetStavkePrimke.m_sifra);
			ListCtrl.SetItemText(index, 2, RecSetStavkePrimke.m_nazivArtikla);
			s.Format(_T("%d"), RecSetStavkePrimke.m_kolicina);
			ListCtrl.SetItemText(index, 3, s);
			s.Format(_T("%.2f"), RecSetStavkePrimke.m_fakturnaCijena);
			ListCtrl.SetItemText(index, 4, s);
			s.Format(_T("%.2f"), RecSetStavkePrimke.m_nabavnaCijena);
			ListCtrl.SetItemText(index, 5, s);
			s.Format(_T("%.2f"), RecSetStavkePrimke.m_prodajnaCijena);
			ListCtrl.SetItemText(index, 6, s);
		}
		RecSetStavkePrimke.MoveNext();
	}
	RecSetStavkePrimke.Close();
}

void DlgUrediPrimku::OnBnClickedDodajNoviArtikl()
{
	DlgStavkeNoviPodatak dlg;

	if (dlg.DoModal() == IDOK)
	{
		m_artiklSifra = dlg.m_artiklSifra;
		m_artiklNaziv = dlg.m_artiklNaziv;
		m_kolicina = dlg.m_kolicina;
		m_rabat = dlg.m_rabat;
		m_fakturnaCijena = dlg.m_fakturnaCijena;
		m_nabavnaCijena = dlg.m_nabavnaCijena;
		m_vpc = dlg.m_vpc;
	}

	if (!m_artiklSifra.IsEmpty() && !m_artiklNaziv.IsEmpty())
	{
		rb++;
		const int index = ListCtrl.GetItemCount();

		CString s;

		s.Format(_T("%d"), rb);
		ListCtrl.InsertItem(index, s);
		ListCtrl.SetItemText(index, 1, m_artiklSifra);
		ListCtrl.SetItemText(index, 2, m_artiklNaziv);
		s.Format(_T("%d"), m_kolicina);
		ListCtrl.SetItemText(index, 3, s);
		s.Format(_T("%.2f"), m_fakturnaCijena);
		ListCtrl.SetItemText(index, 4, s);
		s.Format(_T("%.2f"), m_nabavnaCijena);
		ListCtrl.SetItemText(index, 5, s);
		s.Format(_T("%.2f"), m_vpc);
		ListCtrl.SetItemText(index, 6, s);
	}
}


void DlgUrediPrimku::OnBnClickedSpremi()
{
	ArtikliSet RecSetArtikli;
	StavkePrimkeSet RecSetStavkePrimke;

	long primkaID = _wtol(m_primkaID);

	if (!RecSetArtikli.IsOpen())
	{
		RecSetArtikli.Open();
	}

	if (!RecSetStavkePrimke.IsOpen())
	{
		RecSetStavkePrimke.Open();
	}
	
	for (int i = brojClanovaListeOnInitDialog; i < ListCtrl.GetItemCount(); i++)
	{
		CString sifraCListCtrl = ListCtrl.GetItemText(i, 1);
		CString nazivCListCtrl = ListCtrl.GetItemText(i, 2);
		CString kolicinaCListCtrl = ListCtrl.GetItemText(i, 3);
		CString fakturnaCijenaCListCtrl = ListCtrl.GetItemText(i, 4);
		CString nabavnaCijenaCListCtrl = ListCtrl.GetItemText(i, 5);
		CString prodajnaCijenaCListCtrl = ListCtrl.GetItemText(i, 6);

		long longKolicinaCListCtrl = _wtol(kolicinaCListCtrl);
		double doubleFakturnaCijenaCListCtrl = _wtof(fakturnaCijenaCListCtrl);
		double doubleNabavnaCijenaCListCtrl = _wtof(nabavnaCijenaCListCtrl);
		double doubleProdajnaCijenaCListCtrl = _wtof(prodajnaCijenaCListCtrl);

		while (!RecSetArtikli.IsBOF() && !RecSetArtikli.IsEOF())
		{
			if (sifraCListCtrl == RecSetArtikli.m_sifra)
			{
				RecSetArtikli.Edit();
				RecSetArtikli.m_stanje += longKolicinaCListCtrl;
				RecSetArtikli.m_cijena = doubleProdajnaCijenaCListCtrl;
				RecSetArtikli.Update();
			}
			RecSetArtikli.MoveNext();
		}
		RecSetArtikli.MoveFirst();


		RecSetStavkePrimke.AddNew();
		RecSetStavkePrimke.m_primkaID = primkaID;
		RecSetStavkePrimke.m_sifra = sifraCListCtrl;
		RecSetStavkePrimke.m_nazivArtikla = nazivCListCtrl;
		RecSetStavkePrimke.m_kolicina = longKolicinaCListCtrl;
		RecSetStavkePrimke.m_fakturnaCijena = doubleFakturnaCijenaCListCtrl;
		RecSetStavkePrimke.m_nabavnaCijena = doubleNabavnaCijenaCListCtrl;
		RecSetStavkePrimke.m_prodajnaCijena = doubleProdajnaCijenaCListCtrl;
		RecSetStavkePrimke.Update();		
	}
	RecSetArtikli.Close();
	RecSetStavkePrimke.Close();
	EndDialog(IDOK);
}
