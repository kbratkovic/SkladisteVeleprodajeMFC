// PrimkeSet.h : Implementation of the PrimkeSet class

// PrimkeSet implementation


#include "pch.h"
#include "stdafx.h"
#include "PrimkeSet.h"

IMPLEMENT_DYNAMIC(PrimkeSet, CRecordset)

PrimkeSet::PrimkeSet(CDatabase* pdb) : CRecordset(pdb)
{
	long m_rb = 0;
	CTime m_datum;
	CString m_nazivKlijenta = _T("");
	CString m_brojRacuna = _T("");
	m_nFields = 4;
	m_nDefaultType = dynaset;
}

CString PrimkeSet::GetDefaultConnect()
{
	return _T("DSN=skladiste;");
}

CString PrimkeSet::GetDefaultSQL()
{
	return _T("[primke]");
}

void PrimkeSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);

	RFX_Long(pFX, _T("[primkaID]"), m_rb);
	RFX_Date(pFX, _T("[datum]"), m_datum);
	RFX_Text(pFX, _T("[nazivKlijenta]"), m_nazivKlijenta);
	RFX_Text(pFX, _T("[brojRacuna]"), m_brojRacuna);

}
/////////////////////////////////////////////////////////////////////////////
// PrimkeSet diagnostics

#ifdef _DEBUG
void PrimkeSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void PrimkeSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


long PrimkeSet::MaxID()
{
	MoveLast();
	return m_rb;
}