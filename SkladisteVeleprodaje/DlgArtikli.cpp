// DlgArtikli.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgArtikli.h"
#include "afxdialogex.h"


// DlgArtikli dialog

IMPLEMENT_DYNAMIC(DlgArtikli, CDialogEx)

DlgArtikli::DlgArtikli(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_ARTIKLIMA_ARTIKLI, pParent)
{

}

DlgArtikli::~DlgArtikli()
{
}

void DlgArtikli::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListCtrl);
}


BEGIN_MESSAGE_MAP(DlgArtikli, CDialogEx)
END_MESSAGE_MAP()


// DlgArtikli message handlers


BOOL DlgArtikli::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString s;

	ArtikliSet RcSetArtikli;
	RcSetArtikli.Open();
	
	s.LoadString(IDS_STRING_ID);
	ListCtrl.InsertColumn(0, s, LVCFMT_CENTER, 60);
	s.LoadString(IDS_STRING_NAZIV_ARTIKLA);
	ListCtrl.InsertColumn(1, s, LVCFMT_CENTER, 349);
	s.LoadString(IDS_STRING_JEDINICA);
	ListCtrl.InsertColumn(2, s, LVCFMT_CENTER, 100);
	s.LoadString(IDS_STRING_STANJE);
	ListCtrl.InsertColumn(3, s, LVCFMT_CENTER, 100);
	s.LoadString(IDS_STRING_CIJENA);
	ListCtrl.InsertColumn(4, s, LVCFMT_CENTER, 120);


	while (!RcSetArtikli.IsEOF())
	{
		const int index = ListCtrl.GetItemCount();

		s.Format(_T("%d"), RcSetArtikli.m_rb);
		ListCtrl.InsertItem(index, s);
		ListCtrl.SetItemText(index, 1, RcSetArtikli.m_nazivArtikla);
		ListCtrl.SetItemText(index, 2, RcSetArtikli.m_jedinica);
		s.Format(_T("%d"), RcSetArtikli.m_stanje);
		ListCtrl.SetItemText(index, 3, s);
		s.Format(_T("%.2f"), RcSetArtikli.m_cijena);
		ListCtrl.SetItemText(index, 4, s);

		RcSetArtikli.MoveNext();
	}

	RcSetArtikli.Close();

	ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
