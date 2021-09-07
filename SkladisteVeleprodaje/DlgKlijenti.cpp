// DlgKlijenti.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgKlijenti.h"
#include "afxdialogex.h"
#include "KlijentiSet.h"
#include "DlgNoviKlijent.h"
#include "DlgUrediKlijenta.h"

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
	DDX_Text(pDX, IDC_LIST1, m_nazivKlijenta);
	DDX_Text(pDX, IDC_LIST1, m_oib);
	DDX_Text(pDX, IDC_LIST1, m_adresa);
	DDX_Text(pDX, IDC_LIST1, m_telefon);
}


BEGIN_MESSAGE_MAP(DlgKlijenti, CDialogEx)
	ON_BN_CLICKED(IDB_DODAJ_NOVOG_KLIJENTA, &DlgKlijenti::OnBnClickedDodajNovogKlijenta)
	ON_BN_CLICKED(IDC_BUTTON_UREDI_KLIJENTA, &DlgKlijenti::OnBnClickedUrediKlijenta)
END_MESSAGE_MAP()


// DlgKlijenti message handlers


BOOL DlgKlijenti::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	PrikaziListu();
	PrikaziKlijente();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void DlgKlijenti::PrikaziListu()
{
	CString s;

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
}

void DlgKlijenti::PrikaziKlijente()
{
	KlijentiSet RecSetKlijenti;
	RecSetKlijenti.Open();

	while (!RecSetKlijenti.IsEOF())
	{
		const int index = ListCtrl.GetItemCount();

		CString s;
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
}

void DlgKlijenti::OnBnClickedDodajNovogKlijenta()
{
	DlgNoviKlijent dlgNoviKlijent;
	dlgNoviKlijent.DoModal();
	ListCtrl.DeleteAllItems();
	PrikaziKlijente();
}


void DlgKlijenti::OnBnClickedUrediKlijenta()
{
	DlgUrediKlijenta dlgUrediKlijenta;
	CString s;

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
			m_nazivKlijenta = ListCtrl.GetItemText(nItem, 1);
			m_oib = ListCtrl.GetItemText(nItem, 2);
			m_adresa = ListCtrl.GetItemText(nItem, 3);
			m_telefon = ListCtrl.GetItemText(nItem, 4);
		}

		dlgUrediKlijenta.m_nazivKlijenta = m_nazivKlijenta;
		dlgUrediKlijenta.m_oib = m_oib;
		dlgUrediKlijenta.m_adresa = m_adresa;
		dlgUrediKlijenta.m_telefon = m_telefon;

		dlgUrediKlijenta.DoModal();
		ListCtrl.DeleteAllItems();
		PrikaziKlijente();
	}
}
