// DlgNovaPrimka.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgNovaPrimka.h"
#include "afxdialogex.h"
#include "DlgStavkeNoviPodatak.h"
#include "DlgKlijenti.h"
#include "DlgOdaberiKlijenta.h"
#include "PrimkeSet.h"


// DlgNovaPrimka dialog

IMPLEMENT_DYNAMIC(DlgNovaPrimka, CDialogEx)

DlgNovaPrimka::DlgNovaPrimka(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_PRIMKAMA_NOVI_PODATAK, pParent)
	, m_nazivKlijenta(_T(""))
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
}


BEGIN_MESSAGE_MAP(DlgNovaPrimka, CDialogEx)
	ON_BN_CLICKED(IDB_DODAJ_NOVI, &DlgNovaPrimka::OnBnClickedDodajNovi)
	ON_BN_CLICKED(IDC_BUTTON2, &DlgNovaPrimka::OnBnClickedOdaberiKlijenta)
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
	CString s = t.Format("%d.%m.%Y.");
	m_edit_datum.SetWindowTextW(s);



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

	// TODO: Add your control notification handler code here
}


void DlgNovaPrimka::OnBnClickedDodajNovi()
{
	if (!m_nazivKlijenta.IsEmpty())
	{
		DlgStavkeNoviPodatak dlg;
		dlg.DoModal();
	}
	else
	{
		CString s;
		s.LoadStringW(IDS_STRING_ODABERI_KLIJENTA);
		MessageBox(s);
	}
	// TODO: Add your control notification handler code here
}




