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

	CString str;

	//RcSetArtikli = new ArtikliSet;
	ArtikliSet RcSetArtikli;
	
	RcSetArtikli.Open();
	
	ListCtrl.InsertColumn(0, _T("ID"), LVCFMT_CENTER, 60);
	ListCtrl.InsertColumn(1, _T("Naziv"), LVCFMT_CENTER, 349);
	ListCtrl.InsertColumn(2, _T("Jedinica"), LVCFMT_CENTER, 100);
	ListCtrl.InsertColumn(3, _T("Stanje"), LVCFMT_CENTER, 100);
	ListCtrl.InsertColumn(4, _T("Cijena VPC"), LVCFMT_CENTER, 120);

	ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	while (!RcSetArtikli.IsEOF())
	{
		str.Format(_T("%d"), RcSetArtikli.m_ID);
		const int index = ListCtrl.InsertItem(0, str);

		ListCtrl.SetItemText(index, 1, RcSetArtikli.m_nazivArtikla);
		ListCtrl.SetItemText(index, 2, RcSetArtikli.m_jedinica);

		str.Format(_T("%d"), RcSetArtikli.m_stanje);
		ListCtrl.SetItemText(index, 3, str);

		str.Format(_T("%.2f"), RcSetArtikli.m_cijena);
		ListCtrl.SetItemText(index, 4, str);

		RcSetArtikli.MoveNext();
	}
	RcSetArtikli.Close();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
