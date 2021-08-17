#pragma once


// DlgStavkeNoviPodatak dialog

class DlgStavkeNoviPodatak : public CDialogEx
{
	DECLARE_DYNAMIC(DlgStavkeNoviPodatak)

public:
	DlgStavkeNoviPodatak(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DlgStavkeNoviPodatak();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STAVKE_NOVI_PODATAK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOdaberiArtikl();
};
