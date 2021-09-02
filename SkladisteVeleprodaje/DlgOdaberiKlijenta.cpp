// DlgOdaberiKlijenta.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgOdaberiKlijenta.h"
#include "afxdialogex.h"
#include "DlgKlijenti.h"
#include "KlijentiSet.h"
#include "DlgNovaPrimka.h"



// DlgOdaberiKlijenta dialog

IMPLEMENT_DYNAMIC(DlgOdaberiKlijenta, CDialogEx)

DlgOdaberiKlijenta::DlgOdaberiKlijenta(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_KLIJENTIMA_ODABERI_KLIJENTA, pParent)
{

}

DlgOdaberiKlijenta::~DlgOdaberiKlijenta()
{
}

void DlgOdaberiKlijenta::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListCtrl);
	DDX_Text(pDX, IDC_LIST1, m_nazivKlijenta);
}


BEGIN_MESSAGE_MAP(DlgOdaberiKlijenta, CDialogEx)
	ON_BN_CLICKED(IDB_ODABERI, &DlgOdaberiKlijenta::OnBnClickedOdaberi)
END_MESSAGE_MAP()


// DlgOdaberiKlijenta message handlers


BOOL DlgOdaberiKlijenta::OnInitDialog()
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

	ListCtrl.SetExtendedStyle(ListCtrl.GetExtendedStyle() | LVS_EX_FULLROWSELECT);

	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void DlgOdaberiKlijenta::OnBnClickedOdaberi()
{
	CString nazivKlijenta, s;
	
	POSITION pos = ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		s.LoadString(IDS_STRING_OBAVEZAN_UNOS_KLIJENTA);
		MessageBox(s);
	}
	else
	{
		while (pos)
		{
			int nItem = ListCtrl.GetNextSelectedItem(pos);
			nazivKlijenta = ListCtrl.GetItemText(nItem, 1);
		}
	}
	m_nazivKlijenta = nazivKlijenta;
	EndDialog(IDOK);
}
