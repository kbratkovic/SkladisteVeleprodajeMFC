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
	afx_msg void OnBnClickedDodajNovi();
	afx_msg void OnBnClickedOdaberiKlijenta();
};
