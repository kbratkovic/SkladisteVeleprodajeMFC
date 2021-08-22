// ArtikliSet.h : Implementation of the ArtikliSet class

// ArtikliSet implementation


#include "pch.h"
#include "stdafx.h"
#include "ArtikliSet.h"

IMPLEMENT_DYNAMIC(ArtikliSet, CRecordset)

ArtikliSet::ArtikliSet(CDatabase* pdb) : CRecordset(pdb)
{
	long m_rb = 0;
	CString m_sifra = _T("");
	CString m_nazivArtikla = _T("");
	CString m_mjera = _T("");
	CString m_stanje = _T("");
	double m_cijena = 0;
	m_nFields = 6;
	m_nDefaultType = dynaset;
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
	RFX_Text(pFX, _T("[sifra]"), m_sifra);
	RFX_Text(pFX, _T("[nazivArtikla]"), m_nazivArtikla);
	RFX_Text(pFX, _T("[mjera]"), m_mjera);
	RFX_Long(pFX, _T("[stanje]"), m_stanje);
	RFX_Double(pFX, _T("[cijena]"), m_cijena);

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


long ArtikliSet::MaxID()
{
	MoveLast();
	return m_rb;
}