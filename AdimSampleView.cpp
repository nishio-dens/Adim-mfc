// AdimSampleView.cpp : CAdimSampleView �N���X�̎���
//

#include "stdafx.h"
#include "AdimSample.h"

#include "AdimSampleDoc.h"
#include "AdimSampleView.h"

#include "AdimBase.h"
#include "Adim.h"
#include ".\adimsampleview.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAdimSampleView

IMPLEMENT_DYNCREATE(CAdimSampleView, CView)

BEGIN_MESSAGE_MAP(CAdimSampleView, CView)
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CAdimSampleView �R���X�g���N�V����/�f�X�g���N�V����

CAdimSampleView::CAdimSampleView()
{
	// TODO: �\�z�R�[�h�������ɒǉ����܂��B
	//ADIM��������������
	adimSampleClass.initAdim("keycode.txt","word.txt","Candidate_Number.txt",
		3,true,0,2);
}

CAdimSampleView::~CAdimSampleView()
{
}

BOOL CAdimSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C������ Window �N���X�܂��̓X�^�C����
	//  �C�����Ă��������B

	return CView::PreCreateWindow(cs);
}

// CAdimSampleView �`��

void CAdimSampleView::OnDraw(CDC* pDC)
{
	CAdimSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���̏ꏊ�Ƀl�C�e�B�u �f�[�^�p�̕`��R�[�h��ǉ����܂��B
	if( !adimSampleClass.isFinishTyping() ) {
		pDC->SetTextColor( RGB(0,0,0) );
		pDC->TextOut(20,20,CString(adimSampleClass.GetNowSentenceOfQuestion().c_str()) );
		pDC->TextOut(20,40,adimSampleClass.GetNowSentenceOfAgateQuestion().c_str() );
		pDC->TextOut(20,60,adimSampleClass.GetNowSentenceOfConvertQuestion().c_str() );

		pDC->SetTextColor( RGB(255,0,0) ); //��
		pDC->TextOut(20,60,adimSampleClass.GetNowSentenceOfInputtedConvertQuestionRed().c_str() );
		pDC->TextOut(20,40,adimSampleClass.GetNowSentenceOfInputtedAgateQuestionRed().c_str() );

		pDC->SetTextColor( RGB(0,0,255) ); //��
		pDC->TextOut(20,60,adimSampleClass.GetNowSentenceOfInputtedConvertQuestionBlue().c_str() );
		pDC->TextOut(20,40,adimSampleClass.GetNowSentenceOfInputtedAgateQuestionBlue().c_str() );
	}else {
		pDC->TextOut(20,40,"�����ꂳ�܂ł���");
	}
}


// CAdimSampleView �f�f

#ifdef _DEBUG
void CAdimSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CAdimSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAdimSampleDoc* CAdimSampleView::GetDocument() const // �f�o�b�O�ȊO�̃o�[�W�����̓C�����C���ł��B
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAdimSampleDoc)));
	return (CAdimSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CAdimSampleView ���b�Z�[�W �n���h��

void CAdimSampleView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO : �����Ƀ��b�Z�[�W �n���h�� �R�[�h��ǉ����邩�A����̏������Ăяo���܂��B
	//do{
	//int result = adimSampleClass.InputTypewordFromKeyboard(nChar);

	//if( result == 2 ) {
	//	questionNumber++;
	//	adimSampleClass.SetQuestion( questionNumber );
	//	adimSampleClass.SaveKeycodeTableCandidateNumber(); //�L�[�R�[�h�e�[�u���̕ۑ�
	//	if( adimSampleClass.GetNumberOfWorkbookElement() <= questionNumber ){
	//		bComplete = true;
	//	}
	//}
	//if( !adimSampleClass.isFinishTyping() )
	adimSampleClass.InputCharacter((char)nChar);

	InvalidateRect(NULL);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
