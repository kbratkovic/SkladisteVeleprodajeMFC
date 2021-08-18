// DlgKlijenti.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgKlijenti.h"
#include "afxdialogex.h"
#include "KlijentiSet.h"
#include "DlgNoviKlijent.h"


// DlgKlijenti dialog

IMPLEMENT_DYNAMIC(DlgKlijenti, CDialogEx)

DlgKlijenti::DlgKlijenti(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_KLIJENTIMA_SVI_KLIJENTI, pParent)
{

}

DlgKlijenti::~DlgKlijenti()
{
}

void DlgKlijenti::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListCtrl);
}


BEGIN_MESSAGE_MAP(DlgKlijenti, CDialogEx)
	ON_BN_CLICKED(IDB_DODAJ_NOVOG_KLIJENTA, &DlgKlijenti::OnBnClickedDodajNovogKlijenta)
END_MESSAGE_MAP()


// DlgKlijenti message handlers


BOOL DlgKlijenti::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString s;

	KlijentiSet RecSetKlijenti;
	RecSetKlijenti.Open();

	s.LoadString(IDS_STRING_KLIJENT_ID);
	ListCtrl.InsertColumn(1, s, LVCFMT_LEFT, 60);
	s.LoadString(IDS_STRING_NAZIV_KLIJENTA);
	ListCtrl.InsertColumn(2, s, LVCFMT_CENTER, 250);
	s.LoadString(IDS_STRING_OIB);
	ListCtrl.InsertColumn(3, s, LVCFMT_CENTER, 130);
	s.LoadString(IDS_STRING_ADRESA);
	ListCtrl.InsertColumn(4, s, LVCFMT_CENTER, 160);
	s.LoadString(IDS_STRING_TELEFON);
	ListCtrl.InsertColumn(5, s, LVCFMT_CENTER, 160);


	while (!RecSetKlijenti.IsEOF())
	{
		const int index = ListCtrl.GetItemCount();

		s.Format(_T("%d"), RecSetKlijenti.m_rb);
		ListCtrl.InsertItem(index, s);
		ListCtrl.SetItemText(index, 1, RecSetKlijenti.m_nazivKlijenta);
		ListCtrl.SetItemText(index, 2, RecSetKlijenti.m_oib);
		ListCtrl.SetItemText(index, 3, RecSetKlijenti.m_adresa);
		ListCtrl.SetItemText(index, 4, RecSetKlijenti.m_telefon);

		RecSetKlijenti.MoveNext();
	}

	RecSetKlijenti.Close();

	ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void DlgKlijenti::OnBnClickedDodajNovogKlijenta()
{
	DlgKlijenti dlg;

	DlgNoviKlijent dlgNoviKlijent;
	dlgNoviKlijent.DoModal();

	EndDialog(1);
	dlg.DoModal();
	// TODO: Add your control notification handler code here
}
