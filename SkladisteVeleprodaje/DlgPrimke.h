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
	CListCtrl ListCtrl;
};