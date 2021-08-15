#pragma once


// DlgNoviKlijent dialog

class DlgNoviKlijent : public CDialogEx
{
	DECLARE_DYNAMIC(DlgNoviKlijent)

public:
	DlgNoviKlijent(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DlgNoviKlijent();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PODACI_O_KLIJENTIMA_NOVI_PODATAK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSpremi();
	CEdit m_nazivKlijenta;
	CEdit m_edit_oib;
	CString m_oib;
	CEdit m_adresa;
	CEdit m_telefon;
	void UnesiNovogKlijenta();
};
