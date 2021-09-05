#pragma once


// DlgUrediPrimku dialog

class DlgUrediPrimku : public CDialogEx
{
	DECLARE_DYNAMIC(DlgUrediPrimku)

public:
	DlgUrediPrimku(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DlgUrediPrimku();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PODACI_O_PRIMKAMA_UREDI_PODATAK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOdaberiKlijenta();
	afx_msg void OnBnClickedDodajNoviArtikl();
	afx_msg void OnBnClickedSpremi();
	void PrikaziListu();
	void PrikaziArtikle();
	
	long rb = 0;
	CEdit m_edit_brojRacuna;
	CString m_brojRacuna;
	CEdit m_edit_nazivKlijenta;
	CString m_nazivKlijenta;
	CString m_primkaID;
	CString m_datum;
	CListCtrl ListCtrl;

	CString m_artiklSifra;
	CString m_artiklSifraIzCListCtrl;
	CString m_artiklNaziv;

	long m_kolicina;
	double m_rabat;
	double m_fakturnaCijena;
	double m_nabavnaCijena;
	double m_vpc;
	int brojClanovaListeOnInitDialog = 0;
};
