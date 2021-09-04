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
};
