// StavkePrimkeSet.h : Implementation of the StavkePrimkeSet class

// StavkePrimkeSet implementation


#include "pch.h"
#include "stdafx.h"
#include "StavkePrimkeSet.h"

IMPLEMENT_DYNAMIC(StavkePrimkeSet, CRecordset)

StavkePrimkeSet::StavkePrimkeSet(CDatabase* pdb) : CRecordset(pdb)
{
	long m_brojPrimke = 0;
	CString m_sifra = _T("");
	CString m_nazivArtikla = _T("");
	long m_kolicina = 0;
	double m_fakturnaCijena = 0;
	double m_nabavnaCijena = 0;
	double m_prodajnaCijena = 0;
	m_nFields = 7;
	m_nDefaultType = dynaset;
}

CString StavkePrimkeSet::GetDefaultConnect()
{
	return _T("DSN=db;");
}

CString StavkePrimkeSet::GetDefaultSQL()
{
	return _T("[stavkePrimke]");
}

void StavkePrimkeSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);

	RFX_Long(pFX, _T("[primkaID]"), m_brojPrimke);
	RFX_Text(pFX, _T("[sifra]"), m_sifra);
	RFX_Text(pFX, _T("[nazivArtikla]"), m_nazivArtikla);
	RFX_Long(pFX, _T("[kolicina]"), m_kolicina);
	RFX_Double(pFX, _T("[fakturnaCijena]"), m_fakturnaCijena);
	RFX_Double(pFX, _T("[nabavnaCijena]"), m_nabavnaCijena);
	RFX_Double(pFX, _T("[prodajnaCijena]"), m_prodajnaCijena);

}
/////////////////////////////////////////////////////////////////////////////
// StavkePrimkeSet diagnostics

#ifdef _DEBUG
void StavkePrimkeSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void StavkePrimkeSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
