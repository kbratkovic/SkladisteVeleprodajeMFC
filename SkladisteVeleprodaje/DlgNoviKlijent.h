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
};
