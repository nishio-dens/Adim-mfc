// AdimSampleDoc.cpp : CAdimSampleDoc �N���X�̎���
//

#include "stdafx.h"
#include "AdimSample.h"

#include "AdimSampleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAdimSampleDoc

IMPLEMENT_DYNCREATE(CAdimSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CAdimSampleDoc, CDocument)
END_MESSAGE_MAP()


// CAdimSampleDoc �R���X�g���N�V����/�f�X�g���N�V����

CAdimSampleDoc::CAdimSampleDoc()
{
	// TODO: ���̈ʒu�ɂP�x�����Ă΂��\�z�p�̃R�[�h��ǉ����Ă��������B

}

CAdimSampleDoc::~CAdimSampleDoc()
{
}

BOOL CAdimSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���̈ʒu�ɍď�����������ǉ����Ă��������B
	// (SDI �h�L�������g�͂��̃h�L�������g���ė��p���܂��B)

	return TRUE;
}




// CAdimSampleDoc �V���A����

void CAdimSampleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �i�[����R�[�h�������ɒǉ����Ă��������B
	}
	else
	{
		// TODO: �ǂݍ��ރR�[�h�������ɒǉ����Ă��������B
	}
}


// CAdimSampleDoc �f�f

#ifdef _DEBUG
void CAdimSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAdimSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CAdimSampleDoc �R�}���h
