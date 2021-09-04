// DlgPrimke.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgPrimke.h"
#include "afxdialogex.h"
#include "PrimkeSet.h"
#include "DlgNovaPrimka.h"
#include "DlgUrediPrimku.h"


// DlgPrimke dialog

IMPLEMENT_DYNAMIC(DlgPrimke, CDialogEx)

DlgPrimke::DlgPrimke(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_PRIMKAMA_SVE_PRIMKE, pParent)
{

}

DlgPrimke::~DlgPrimke()
{
}

void DlgPrimke::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, ListCtrl);
}


BEGIN_MESSAGE_MAP(DlgPrimke, CDialogEx)
	ON_BN_CLICKED(IDB_DODAJ_NOVU_PRIMKU, &DlgPrimke::OnBnClickedDodajNovuPrimku)
	ON_BN_CLICKED(IDB_UREDI_PRIMKU, &DlgPrimke::OnBnClickedUrediPrimku)
END_MESSAGE_MAP()


// DlgPrimke message handlers


BOOL DlgPrimke::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	PrikaziListu();
	PrikaziPrimke();
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void DlgPrimke::OnBnClickedDodajNovuPrimku()
{
	DlgNovaPrimka dlgNovaPrimka;

	ListCtrl.DeleteAllItems();
	dlgNovaPrimka.DoModal();
	PrikaziPrimke();
}


void DlgPrimke::PrikaziListu()
{
	CString s;

	s.LoadString(IDS_STRING_ID);
	ListCtrl.InsertColumn(1, s, LVCFMT_LEFT, 60);
	s.LoadString(IDS_STRING_DATUM);
	ListCtrl.InsertColumn(2, s, LVCFMT_CENTER, 150);
	s.LoadString(IDS_STRING_NAZIV_KLIJENTA);
	ListCtrl.InsertColumn(3, s, LVCFMT_CENTER, 300);
	s.LoadString(IDS_STRING_BROJ_RACUNA);
	ListCtrl.InsertColumn(3, s, LVCFMT_CENTER, 200);
}


void DlgPrimke::PrikaziPrimke()
{
	PrimkeSet RcSetPrimke;
	RcSetPrimke.Open();

	while (!RcSetPrimke.IsEOF())
	{
		const int index = ListCtrl.GetItemCount();

		CTime datum = RcSetPrimke.m_datum;
		CString sDatum = datum.Format(_T("%d.%m.%Y."));

		CString s;
		s.Format(_T("%d"), RcSetPrimke.m_rb);
		ListCtrl.InsertItem(index, s);
		ListCtrl.SetItemText(index, 1, sDatum);
		ListCtrl.SetItemText(index, 2, RcSetPrimke.m_nazivKlijenta);
		ListCtrl.SetItemText(index, 3, RcSetPrimke.m_brojRacuna);

		RcSetPrimke.MoveNext();
	}

	RcSetPrimke.Close();

	ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
}

void DlgPrimke::OnBnClickedUrediPrimku()
{
	DlgUrediPrimku dlgUrediPrimku;
	CString s;

	POSITION pos = ListCtrl.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		s.LoadString(IDS_STRING_OBAVEZAN_ODABIR_PRIMKE);
		MessageBox(s);
	}
	else
	{
		while (pos)
		{
			int nItem = ListCtrl.GetNextSelectedItem(pos);
			m_primkaID = ListCtrl.GetItemText(nItem, 0);
			m_datum = ListCtrl.GetItemText(nItem, 1);
			m_nazivKlijenta = ListCtrl.GetItemText(nItem, 2);
			m_brojRacuna = ListCtrl.GetItemText(nItem, 3);
		}

		
		dlgUrediPrimku.DoModal();
	
	}
}
