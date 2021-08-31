// DlgArtikli.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgArtikli.h"
#include "afxdialogex.h"
#include <string> 

// DlgArtikli dialog

IMPLEMENT_DYNAMIC(DlgArtikli, CDialogEx)

DlgArtikli::DlgArtikli(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_ARTIKLIMA_SVI_ARTIKLI, pParent)
{

}

DlgArtikli::~DlgArtikli()
{
}

void DlgArtikli::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListCtrl);
	DDX_Control(pDX, IDB_DODAJ_NOVI_ARTIKL, m_btnDodajArtikl);
}


BEGIN_MESSAGE_MAP(DlgArtikli, CDialogEx)
	ON_BN_CLICKED(IDB_DODAJ_NOVI_ARTIKL, &DlgArtikli::OnBnClickedDodajNoviArtikl)
END_MESSAGE_MAP()


// DlgArtikli message handlers


BOOL DlgArtikli::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	PrikaziListu();
	PrikaziArtikle();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void DlgArtikli::PrikaziListu()
{
	CString s;

	s.LoadString(IDS_STRING_ID);
	ListCtrl.InsertColumn(1, s, LVCFMT_LEFT, 60);
	s.LoadString(IDS_STRING_SIFRA);
	ListCtrl.InsertColumn(2, s, LVCFMT_CENTER, 120);
	s.LoadString(IDS_STRING_NAZIV_ARTIKLA);
	ListCtrl.InsertColumn(3, s, LVCFMT_CENTER, 300);
	s.LoadString(IDS_STRING_JEDINICA);
	ListCtrl.InsertColumn(4, s, LVCFMT_CENTER, 100);
	s.LoadString(IDS_STRING_STANJE);
	ListCtrl.InsertColumn(5, s, LVCFMT_CENTER, 100);
	s.LoadString(IDS_STRING_CIJENA);
	ListCtrl.InsertColumn(6, s, LVCFMT_CENTER, 120);
}


void DlgArtikli::PrikaziArtikle()
{
	ArtikliSet RcSetArtikli;
	RcSetArtikli.Open();

	while (!RcSetArtikli.IsEOF())
	{
		const int index = ListCtrl.GetItemCount();

		CString s;
		s.Format(_T("%d"), RcSetArtikli.m_rb);
		ListCtrl.InsertItem(index, s);
		ListCtrl.SetItemText(index, 1, RcSetArtikli.m_sifra);
		ListCtrl.SetItemText(index, 2, RcSetArtikli.m_nazivArtikla);
		ListCtrl.SetItemText(index, 3, RcSetArtikli.m_mjera);
		s.Format(_T("%d"), RcSetArtikli.m_stanje);
		ListCtrl.SetItemText(index, 4, s);
		s.Format(_T("%.2f"), RcSetArtikli.m_cijena);
		ListCtrl.SetItemText(index, 5, s);

		RcSetArtikli.MoveNext();
	}

	RcSetArtikli.Close();

	ListCtrl.SetExtendedStyle(ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
}

void DlgArtikli::OnBnClickedDodajNoviArtikl()
{
	DlgNoviArtikl dlgNoviArtikl;

	ListCtrl.DeleteAllItems();
	dlgNoviArtikl.DoModal();
	PrikaziArtikle();
}
