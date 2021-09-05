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
	
	long rb = 0;
	CString m_primkaID;
	CString m_datum;
	CString m_nazivKlijenta;
	CString m_brojRacuna;
	CListCtrl ListCtrl;
	void PrikaziListu();
	void PrikaziArtikle();
};
