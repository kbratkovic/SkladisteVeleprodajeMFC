// ArtikliSet.h : Implementation of the ArtikliSet class

// ArtikliSet implementation


#include "pch.h"
#include "stdafx.h"
#include "ArtikliSet.h"

IMPLEMENT_DYNAMIC(ArtikliSet, CRecordset)

ArtikliSet::ArtikliSet(CDatabase* pdb) : CRecordset(pdb)
{
	long m_rb = 0;
	CStringW m_nazivArtikla = _T("");
	CStringW m_jedinica = _T("");
	CStringW m_cijena = _T("");
	CStringW m_stanje = _T("");
	m_nFields = 5;
	m_nDefaultType = snapshot;
}

CString ArtikliSet::GetDefaultConnect()
{
	return _T("DSN=db;");
}

CString ArtikliSet::GetDefaultSQL()
{
	return _T("[artikli]");
}

void ArtikliSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);

	RFX_Long(pFX, _T("[ID]"), m_rb);
	RFX_Text(pFX, _T("[nazivArtikla]"), m_nazivArtikla);
	RFX_Text(pFX, _T("[jedinica]"), m_jedinica);
	RFX_Double(pFX, _T("[cijena]"), m_cijena);
	RFX_Long(pFX, _T("[stanje]"), m_stanje);

}
/////////////////////////////////////////////////////////////////////////////
// ArtikliSet diagnostics

#ifdef _DEBUG
void ArtikliSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void ArtikliSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
