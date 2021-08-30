#pragma once


// DlgKlijenti dialog

class DlgKlijenti : public CDialogEx
{
	DECLARE_DYNAMIC(DlgKlijenti)

public:
	DlgKlijenti(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DlgKlijenti();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PODACI_O_KLIJENTIMA_SVI_KLIJENTI };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedDodajNovogKlijenta();
	void PrikaziKlijente();
	CListCtrl ListCtrl;
	afx_msg void OnBnClickedUrediKlijenta();
};
