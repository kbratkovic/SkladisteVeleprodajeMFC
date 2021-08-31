#pragma once


// DlgUrediKlijenta dialog

class DlgUrediKlijenta : public CDialogEx
{
	DECLARE_DYNAMIC(DlgUrediKlijenta)

public:
	DlgUrediKlijenta(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DlgUrediKlijenta();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PODACI_O_KLIJENTIMA_UREDI_KLIJENTA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_nazivKlijenta;
	CString m_oib;
	CString m_adresa;
	CString m_telefon;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedSpremi();
	CString nazivKlijenta;
	CString oib;
	CString adresa;
	CString telefon;
};
