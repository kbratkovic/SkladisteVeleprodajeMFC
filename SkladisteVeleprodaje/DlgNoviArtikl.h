#pragma once

#include "ArtikliSet.h"

// DlgNoviArtikl dialog

class DlgNoviArtikl : public CDialogEx
{
	DECLARE_DYNAMIC(DlgNoviArtikl)

public:
	DlgNoviArtikl(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DlgNoviArtikl();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PODACI_O_ARTIKLIMA_NOVI_PODATAK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedSpremi();
	void UnesiNoviArtikl();
	CEdit m_sifra;
	CEdit m_nazivArtikla;
	CEdit m_mjera;
	double m_cijena;
	CEdit m_edit_cijena;
};