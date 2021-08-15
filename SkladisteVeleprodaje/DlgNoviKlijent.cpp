// DlgNoviKlijent.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgNoviKlijent.h"
#include "afxdialogex.h"
#include "KlijentiSet.h"



// DlgNoviKlijent dialog

IMPLEMENT_DYNAMIC(DlgNoviKlijent, CDialogEx)

DlgNoviKlijent::DlgNoviKlijent(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_KLIJENTIMA_NOVI_PODATAK, pParent)
	, m_oib(_T(""))
{

}

DlgNoviKlijent::~DlgNoviKlijent()
{
}

void DlgNoviKlijent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_NAZIV_KLIJENTA, m_nazivKlijenta);
	DDX_Text(pDX, IDC_EDIT_OIB, m_oib);
	DDV_MaxChars(pDX, m_oib, 11);
	DDX_Control(pDX, IDC_EDIT_ADRESA, m_adresa);
	DDX_Control(pDX, IDC_EDIT_TELEFON, m_telefon);
	DDX_Control(pDX, IDC_EDIT_OIB, m_edit_oib);
}


BEGIN_MESSAGE_MAP(DlgNoviKlijent, CDialogEx)
	ON_BN_CLICKED(IDB_SPREMI, &DlgNoviKlijent::OnBnClickedSpremi)
END_MESSAGE_MAP()


// DlgNoviKlijent message handlers


void DlgNoviKlijent::OnBnClickedSpremi()
{
	UnesiNovogKlijenta();
	EndDialog(1);
	// TODO: Add your control notification handler code here
}


void DlgNoviKlijent::UnesiNovogKlijenta() 
{

	KlijentiSet RecSetKlijenti;
	long iduciID = 1;

	UpdateData(TRUE);

	CString nazivKlijenta;
	m_nazivKlijenta.GetWindowText(nazivKlijenta);
	CString oib;
	m_edit_oib.GetWindowText(oib);
	CString adresa;
	m_adresa.GetWindowText(adresa);
	CString telefon;
	m_telefon.GetWindowText(telefon);

	if (!RecSetKlijenti.IsOpen())
	{
		RecSetKlijenti.Open();
	}

	if (!RecSetKlijenti.IsBOF() && !RecSetKlijenti.IsEOF())
	{
		iduciID = RecSetKlijenti.MaxID() + 1;
	}

	RecSetKlijenti.AddNew();

	RecSetKlijenti.m_rb = iduciID;
	RecSetKlijenti.m_nazivKlijenta = nazivKlijenta;
	RecSetKlijenti.m_oib = oib;
	RecSetKlijenti.m_adresa = adresa;
	RecSetKlijenti.m_telefon = telefon;

	RecSetKlijenti.Update();
	RecSetKlijenti.Close();
}