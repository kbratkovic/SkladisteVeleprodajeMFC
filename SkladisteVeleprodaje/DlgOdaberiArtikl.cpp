// DlgOdaberiArtikl.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgOdaberiArtikl.h"
#include "afxdialogex.h"
#include "ArtikliSet.h"


// DlgOdaberiArtikl dialog

IMPLEMENT_DYNAMIC(DlgOdaberiArtikl, CDialogEx)

DlgOdaberiArtikl::DlgOdaberiArtikl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_ARTIKLIMA_ODABERI_ARTIKL, pParent)
{

}

DlgOdaberiArtikl::~DlgOdaberiArtikl()
{
}

void DlgOdaberiArtikl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListCtrl);
	DDX_Text(pDX, IDC_LIST1, m_nazivArtikla);
	DDX_Text(pDX, IDC_LIST1, m_sifraArtikla);
}


BEGIN_MESSAGE_MAP(DlgOdaberiArtikl, CDialogEx)
	ON_BN_CLICKED(IDB_ODABERI, &DlgOdaberiArtikl::OnBnClickedOdaberi)
END_MESSAGE_MAP()


// DlgOdaberiArtikl message handlers


BOOL DlgOdaberiArtikl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString s;

	ArtikliSet RcSetArtikli;
	RcSetArtikli.Open();

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


	while (!RcSetArtikli.IsEOF())
	{
		const int index = ListCtrl.GetItemCount();

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

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void DlgOdaberiArtikl::OnBnClickedOdaberi()
{
	CString nazivArtikla, sifraArtikla;

	POSITION pos = ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		MessageBox(_T("Molim odaberite artikl.\n"));
	}
	else
	{
		while (pos)
		{
			int nItem = ListCtrl.GetNextSelectedItem(pos);
			sifraArtikla = ListCtrl.GetItemText(nItem, 1);
			nazivArtikla = ListCtrl.GetItemText(nItem, 2);
		}
	}
	m_sifraArtikla = sifraArtikla;
	m_nazivArtikla = nazivArtikla;
	EndDialog(1);
	// TODO: Add your control notification handler code here
}
