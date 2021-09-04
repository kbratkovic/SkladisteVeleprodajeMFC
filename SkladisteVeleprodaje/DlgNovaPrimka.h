#pragma once


// DlgNovaPrimka dialog

class DlgNovaPrimka : public CDialogEx
{
	DECLARE_DYNAMIC(DlgNovaPrimka)

public:
	DlgNovaPrimka(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DlgNovaPrimka();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PODACI_O_PRIMKAMA_NOVI_PODATAK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedDodajNovi();
	afx_msg void OnBnClickedOdaberiKlijenta();
	afx_msg void OnBnClickedSpremi();
	CListCtrl ListCtrl;
	CEdit m_edit_datum;
	CString m_datum;
	CEdit m_edit_nazivKlijenta;
	CString m_nazivKlijenta;
	CEdit m_edit_rbPrimke;
	CEdit m_edit_brojRacuna;
	CString m_brojRacuna;

	CString m_artiklSifra;
	CString m_artiklSifraIzCListCtrl;
	CString m_artiklNaziv;

	long m_kolicina;
	double m_rabat;
	double m_fakturnaCijena;
	double m_nabavnaCijena;
	double m_vpc;

	long rb = 0;
};
