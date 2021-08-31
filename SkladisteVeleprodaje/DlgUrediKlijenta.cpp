// DlgUrediKlijenta.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgUrediKlijenta.h"
#include "DlgKlijenti.h"
#include "KlijentiSet.h"
#include "afxdialogex.h"


// DlgUrediKlijenta dialog

IMPLEMENT_DYNAMIC(DlgUrediKlijenta, CDialogEx)

DlgUrediKlijenta::DlgUrediKlijenta(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_KLIJENTIMA_UREDI_KLIJENTA, pParent)
	, m_nazivKlijenta(_T(""))
	, m_oib(_T(""))
	, m_adresa(_T(""))
	, m_telefon(_T(""))
{
}

DlgUrediKlijenta::~DlgUrediKlijenta()
{
}

void DlgUrediKlijenta::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAZIV_KLIJENTA, m_nazivKlijenta);
	DDX_Text(pDX, IDC_EDIT_OIB, m_oib);
	DDX_Text(pDX, IDC_EDIT_ADRESA, m_adresa);
	DDX_Text(pDX, IDC_EDIT_TELEFON, m_telefon);
}


BEGIN_MESSAGE_MAP(DlgUrediKlijenta, CDialogEx)
	ON_BN_CLICKED(IDB_SPREMI, &DlgUrediKlijenta::OnBnClickedSpremi)
END_MESSAGE_MAP()


// DlgUrediKlijenta message handlers


BOOL DlgUrediKlijenta::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	nazivKlijenta = m_nazivKlijenta;
	oib = m_oib;
	adresa = m_adresa;
	telefon = m_telefon;

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void DlgUrediKlijenta::OnBnClickedSpremi()
{
	KlijentiSet RecSetKlijenti;

	UpdateData(TRUE);

	if (!RecSetKlijenti.IsOpen())
	{
		RecSetKlijenti.Open();
	}

	while (!RecSetKlijenti.IsBOF() && !RecSetKlijenti.IsEOF())
	{
		if (nazivKlijenta == RecSetKlijenti.m_nazivKlijenta)
		{
			RecSetKlijenti.Edit();

			RecSetKlijenti.m_nazivKlijenta = m_nazivKlijenta;
			RecSetKlijenti.m_oib = m_oib;
			RecSetKlijenti.m_adresa = m_adresa;
			RecSetKlijenti.m_telefon = m_telefon;

			RecSetKlijenti.Update();
			break;
		}
		RecSetKlijenti.MoveNext();
	}
	EndDialog(1);
}
