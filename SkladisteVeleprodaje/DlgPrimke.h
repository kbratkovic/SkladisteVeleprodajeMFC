#pragma once


// DlgPrimke dialog

class DlgPrimke : public CDialogEx
{
	DECLARE_DYNAMIC(DlgPrimke)

public:
	DlgPrimke(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DlgPrimke();



// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PODACI_O_PRIMKAMA_SVE_PRIMKE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedDodajNovuPrimku();
	afx_msg void OnBnClickedUrediPrimku();
	CListCtrl ListCtrl;
	void PrikaziListu();
	void PrikaziPrimke();

	CString m_primkaID;
	CString m_datum;
	CString m_nazivKlijenta;
	CString m_brojRacuna;
};
