#pragma once

#include "ArtikliSet.h"
#include "DlgNoviArtikl.h"

// DlgArtikli dialog

class DlgArtikli : public CDialogEx
{
	DECLARE_DYNAMIC(DlgArtikli)

public:
	DlgArtikli(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DlgArtikli();

	CListCtrl ListCtrl;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PODACI_O_ARTIKLIMA_SVI_ARTIKLI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedDodajNoviArtikl();
	afx_msg void OnBnClickedIzmijeniArtikl();
	CButton m_btnDodajArtikl;
};
