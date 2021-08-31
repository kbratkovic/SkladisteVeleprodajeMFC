#pragma once


// DlgUrediArtikl dialog

class DlgUrediArtikl : public CDialogEx
{
	DECLARE_DYNAMIC(DlgUrediArtikl)

public:
	DlgUrediArtikl(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DlgUrediArtikl();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PODACI_O_ARTIKLIMA_UREDI_ARTIKL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
