// DlgPrimke.cpp : implementation file
//

#include "pch.h"
#include "SkladisteVeleprodaje.h"
#include "DlgPrimke.h"
#include "afxdialogex.h"
#include "PrimkeSet.h"


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
	DDX_Control(pDX, IDC_LIST1, ListCtrl);
}


BEGIN_MESSAGE_MAP(DlgPrimke, CDialogEx)
END_MESSAGE_MAP()


// DlgPrimke message handlers


BOOL DlgPrimke::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString s;

	PrimkeSet RcSetPrimke;
	RcSetPrimke.Open();

	s.LoadString(IDS_STRING_ID);
	ListCtrl.InsertColumn(1, s, LVCFMT_LEFT, 60);
	s.LoadString(IDS_STRING_DATUM);
	ListCtrl.InsertColumn(2, s, LVCFMT_CENTER, 180);
	s.LoadString(IDS_STRING_NAZIV_KLIJENTA);
	ListCtrl.InsertColumn(3, s, LVCFMT_CENTER, 350);

	while (!RcSetPrimke.IsEOF())
	{
		const int index = ListCtrl.GetItemCount();

		CTime datum = RcSetPrimke.m_datum;
		CString sDatum = datum.Format(_T("%d.%m.%Y"));

		s.Format(_T("%d"), RcSetPrimke.m_rb);
		ListCtrl.InsertItem(index, s);
		ListCtrl.SetItemText(index, 1, sDatum);
		ListCtrl.SetItemText(index, 2, RcSetPrimke.m_nazivKlijenta);

		RcSetPrimke.MoveNext();
	}

	RcSetPrimke.Close();

	//ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
