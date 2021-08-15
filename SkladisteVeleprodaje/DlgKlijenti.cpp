// DlgKlijenti.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgKlijenti.h"
#include "afxdialogex.h"


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
}


BEGIN_MESSAGE_MAP(DlgKlijenti, CDialogEx)
END_MESSAGE_MAP()


// DlgKlijenti message handlers


BOOL DlgKlijenti::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
