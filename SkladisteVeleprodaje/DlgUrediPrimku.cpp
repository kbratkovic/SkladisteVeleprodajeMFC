// DlgUrediPrimku.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgUrediPrimku.h"
#include "afxdialogex.h"
#include "DlgOdaberiKlijenta.h"
#include "StavkePrimkeSet.h"


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
END_MESSAGE_MAP()


// DlgUrediPrimku message handlers


BOOL DlgUrediPrimku::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	PrikaziListu();
	PrikaziArtikle();

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