#include "pch.h"
#include "stdafx.h"
#include "KlijentiSet.h"

IMPLEMENT_DYNAMIC(KlijentiSet, CRecordset)

KlijentiSet::KlijentiSet(CDatabase* pdb) : CRecordset(pdb)
{
	long m_rb = 0;
	CString m_nazivKlijenta = _T("");
	CString m_oib = _T("");
	CString m_adresa = _T("");
	CString m_telefon = _T("");
	m_nFields = 5;
	m_nDefaultType = dynaset;
}

CString KlijentiSet::GetDefaultConnect()
{
	return _T("DSN=skladiste;");
}

CString KlijentiSet::GetDefaultSQL()
{
	return _T("[klijenti]");
}

void KlijentiSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);

	RFX_Long(pFX, _T("[ID]"), m_rb);
	RFX_Text(pFX, _T("[nazivKlijenta]"), m_nazivKlijenta);
	RFX_Text(pFX, _T("[oib]"), m_oib);
	RFX_Text(pFX, _T("[adresa]"), m_adresa);
	RFX_Text(pFX, _T("[telefon]"), m_telefon);

}
/////////////////////////////////////////////////////////////////////////////
// ArtikliSet diagnostics

#ifdef _DEBUG
void KlijentiSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void KlijentiSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


long KlijentiSet::MaxID()
{
	MoveLast();
	return m_rb;
}