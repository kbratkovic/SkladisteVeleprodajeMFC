// DlgNoviArtikl.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgNoviArtikl.h"
#include "afxdialogex.h"


// DlgNoviArtikl dialog

IMPLEMENT_DYNAMIC(DlgNoviArtikl, CDialogEx)

DlgNoviArtikl::DlgNoviArtikl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_ARTIKLIMA_NOVI_PODATAK, pParent)
{

}

DlgNoviArtikl::~DlgNoviArtikl()
{
}

void DlgNoviArtikl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgNoviArtikl, CDialogEx)
END_MESSAGE_MAP()


// DlgNoviArtikl message handlers
