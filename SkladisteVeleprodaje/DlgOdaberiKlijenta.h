#pragma once


// DlgOdaberiKlijenta dialog

class DlgOdaberiKlijenta : public CDialogEx
{
	DECLARE_DYNAMIC(DlgOdaberiKlijenta)

public:
	DlgOdaberiKlijenta(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DlgOdaberiKlijenta();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PODACI_O_KLIJENTIMA_ODABERI_KLIJENTA };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl ListCtrl;
	CString m_nazivKlijenta;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOdaberi();
};
