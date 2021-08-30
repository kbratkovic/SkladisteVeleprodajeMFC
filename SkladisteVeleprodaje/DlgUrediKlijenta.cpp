// DlgUrediKlijenta.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgUrediKlijenta.h"
#include "DlgKlijenti.h"
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
	//DlgKlijenti dlg;
	//m_nazivKlijenta = dlg.m_nazivKlijenta;
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
END_MESSAGE_MAP()


// DlgUrediKlijenta message handlers


BOOL DlgUrediKlijenta::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//UpdateData(TRUE);


	/*DlgKlijenti dlgKlijenti;

	if (DoModal() == IDOK)
	{
		m_nazivKlijenta = dlgKlijenti.m_nazivKlijenta;
	}*/

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
