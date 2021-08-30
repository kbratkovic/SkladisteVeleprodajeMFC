// DlgNovaPrimka.cpp : implementation file

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgNovaPrimka.h"
#include "afxdialogex.h"
#include "DlgStavkeNoviPodatak.h"
#include "DlgKlijenti.h"
#include "DlgOdaberiKlijenta.h"
#include "PrimkeSet.h"
#include "ArtikliSet.h"


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
	DDX_Control(pDX, IDC_EDIT_DATUM, m_edit_datum);
	DDX_Control(pDX, IDC_EDIT_KLIJENT, m_edit_nazivKlijenta);
	DDX_Text(pDX, IDC_EDIT_KLIJENT, m_nazivKlijenta);
	DDX_Control(pDX, IDC_EDIT_BROJ_PRIMKE, m_edit_rbPrimke);
	DDX_Control(pDX, IDC_LIST1, ListCtrl);
}


BEGIN_MESSAGE_MAP(DlgNovaPrimka, CDialogEx)
	ON_BN_CLICKED(IDB_DODAJ_NOVI, &DlgNovaPrimka::OnBnClickedDodajNovi)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgNovaPrimka::OnBnClickedOdaberiKlijenta)
	ON_BN_CLICKED(IDB_SPREMI, &DlgNovaPrimka::OnBnClickedSpremi)
END_MESSAGE_MAP()


// DlgNovaPrimka message handlers


BOOL DlgNovaPrimka::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	PrimkeSet RecSetPrimke;
	long iduciID = 1;

	UpdateData(TRUE);

	if (!RecSetPrimke.IsOpen())
	{
		RecSetPrimke.Open();
	}

	if (!RecSetPrimke.IsBOF() && !RecSetPrimke.IsEOF())
	{
		iduciID = RecSetPrimke.MaxID() + 1;
	}

	CString iduci;
	iduci.Format(_T("%d"), iduciID);
	m_edit_rbPrimke.SetWindowTextW(iduci);

	RecSetPrimke.Close();

	CTime t = CTime::GetCurrentTime();
	m_datum = t.Format("%d.%m.%Y.");
	m_edit_datum.SetWindowTextW(m_datum);

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

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void DlgNovaPrimka::OnBnClickedOdaberiKlijenta()
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


void DlgNovaPrimka::OnBnClickedDodajNovi()
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

	m_artiklSifraIzCListCtrl = m_artiklSifra;
	m_artiklSifra = _T("");
	m_artiklNaziv = _T("");
}


void DlgNovaPrimka::OnBnClickedSpremi()
{
	if (!m_nazivKlijenta.IsEmpty() && ListCtrl.GetItemCount() != 0)
	{
		PrimkeSet RecSetPrimke;
		long iduciID = 1;
		CTime datum = CTime::GetCurrentTime();

		if (!RecSetPrimke.IsOpen())
		{
			RecSetPrimke.Open();
		}

		if (!RecSetPrimke.IsBOF() && !RecSetPrimke.IsEOF())
		{
			iduciID = RecSetPrimke.MaxID() + 1;
		}

		RecSetPrimke.AddNew();

		RecSetPrimke.m_rb = iduciID;
		RecSetPrimke.m_datum = datum;
		RecSetPrimke.m_nazivKlijenta = m_nazivKlijenta;

		RecSetPrimke.Update();
		RecSetPrimke.Close();
		


		ArtikliSet RecSetArtikli;

		if (!RecSetArtikli.IsOpen())
		{
			RecSetArtikli.Open();
		}

		for (int i = 0; i < ListCtrl.GetItemCount(); i++)
		{
			CString sifraCListCtrl = ListCtrl.GetItemText(i, 1);
			CString kolicinaCListCtrl = ListCtrl.GetItemText(i, 3);

			long longKolicinaCListCtrl = _wtol(kolicinaCListCtrl);

			while (!RecSetArtikli.IsBOF() && !RecSetArtikli.IsEOF())
			{
				if (sifraCListCtrl == RecSetArtikli.m_sifra)
				{
					RecSetArtikli.Edit();
					RecSetArtikli.m_stanje += longKolicinaCListCtrl;
					RecSetArtikli.Update();
				}
				RecSetArtikli.MoveNext();
			}
			RecSetArtikli.MoveFirst();
		}
		RecSetArtikli.Close();
		EndDialog(1);
	}
	else
	{
		CString s;
		s.LoadString(IDS_STRING_OBAVEZAN_UNOS_PODATAKA);
		MessageBox(s);
	}

}
