// DlgPrimke.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgPrimke.h"
#include "afxdialogex.h"


// DlgPrimke dialog

IMPLEMENT_DYNAMIC(DlgPrimke, CDialogEx)

DlgPrimke::DlgPrimke(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PODACI_O_PRIMKAMA_SVE_PRIMKE, pParent)
{

}

DlgPrimke::~DlgPrimke()
{
}

void DlgPrimke::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DlgPrimke, CDialogEx)
END_MESSAGE_MAP()


// DlgPrimke message handlers


BOOL DlgPrimke::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
