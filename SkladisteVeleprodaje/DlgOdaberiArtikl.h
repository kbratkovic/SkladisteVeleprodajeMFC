#pragma once


// DlgOdaberiArtikl dialog

class DlgOdaberiArtikl : public CDialogEx
{
	DECLARE_DYNAMIC(DlgOdaberiArtikl)

public:
	DlgOdaberiArtikl(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DlgOdaberiArtikl();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PODACI_O_ARTIKLIMA_ODABERI_ARTIKL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl ListCtrl;
	CString m_nazivArtikla;
	CString m_sifraArtikla;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOdaberi();
};
