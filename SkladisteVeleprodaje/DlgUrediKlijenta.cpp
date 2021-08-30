// DlgUrediKlijenta.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgUrediKlijenta.h"
#include "afxdialogex.h"


// DlgUrediKlijenta dialog

IMPLEMENT_DYNAMIC(DlgUrediKlijenta, CDialogEx)

DlgUrediKlijenta::DlgUrediKlijenta(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_KLIJENTIMA_UREDI_KLIJENTA, pParent)
{

}

DlgUrediKlijenta::~DlgUrediKlijenta()
{
}

void DlgUrediKlijenta::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgUrediKlijenta, CDialogEx)
END_MESSAGE_MAP()


// DlgUrediKlijenta message handlers
