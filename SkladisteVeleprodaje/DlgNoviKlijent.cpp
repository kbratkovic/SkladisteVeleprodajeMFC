// DlgNoviKlijent.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgNoviKlijent.h"
#include "afxdialogex.h"



// DlgNoviKlijent dialog

IMPLEMENT_DYNAMIC(DlgNoviKlijent, CDialogEx)

DlgNoviKlijent::DlgNoviKlijent(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_KLIJENTIMA_NOVI_PODATAK, pParent)
{

}

DlgNoviKlijent::~DlgNoviKlijent()
{
}

void DlgNoviKlijent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgNoviKlijent, CDialogEx)
END_MESSAGE_MAP()


// DlgNoviKlijent message handlers
