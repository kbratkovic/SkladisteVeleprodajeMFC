// DlgUrediPrimku.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgUrediPrimku.h"
#include "afxdialogex.h"


// DlgUrediPrimku dialog

IMPLEMENT_DYNAMIC(DlgUrediPrimku, CDialogEx)

DlgUrediPrimku::DlgUrediPrimku(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_PRIMKAMA_UREDI_PODATAK, pParent)
{

}

DlgUrediPrimku::~DlgUrediPrimku()
{
}

void DlgUrediPrimku::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgUrediPrimku, CDialogEx)
END_MESSAGE_MAP()


// DlgUrediPrimku message handlers


BOOL DlgUrediPrimku::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
