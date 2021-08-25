#pragma once


// DlgStavkeNoviPodatak dialog

class DlgStavkeNoviPodatak : public CDialogEx
{
	DECLARE_DYNAMIC(DlgStavkeNoviPodatak)

public:
	DlgStavkeNoviPodatak(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DlgStavkeNoviPodatak();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STAVKE_NOVI_PODATAK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOdaberiArtikl();
	afx_msg void OnBnClickedSpremi();
	afx_msg void OnEnKillfocusEditRabat();
	double IzracunNabavneCijene();
	CString m_artiklSifra;
	CString m_artiklNaziv;

	long m_kolicina;
	double m_rabat;
	double m_fakturnaCijena;
	double m_nabavnaCijena;
	double m_vpc;
	CEdit m_edit_nabavnaCijena;
};
