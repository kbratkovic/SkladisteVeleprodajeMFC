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
	CButton m_btnDodajArtikl;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedDodajNoviArtikl();
	void PrikaziListu();
	void PrikaziArtikle();
	afx_msg void OnBnClickedUrediArtikl();

	CString m_sifra;
	CString m_nazivArtikla;
	CString m_mjera;
	CString m_cijena;
};
