// AdimSampleView.cpp : CAdimSampleView クラスの実装
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

// CAdimSampleView コンストラクション/デストラクション

CAdimSampleView::CAdimSampleView()
{
	// TODO: 構築コードをここに追加します。
	//ADIM初期化ここから
	adimSampleClass.initAdim("keycode.txt","word.txt","Candidate_Number.txt",
		3,true,0,2);
}

CAdimSampleView::~CAdimSampleView()
{
}

BOOL CAdimSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CAdimSampleView 描画

void CAdimSampleView::OnDraw(CDC* pDC)
{
	CAdimSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
	if( !adimSampleClass.isFinishTyping() ) {
		pDC->SetTextColor( RGB(0,0,0) );
		pDC->TextOut(20,20,CString(adimSampleClass.GetNowSentenceOfQuestion().c_str()) );
		pDC->TextOut(20,40,adimSampleClass.GetNowSentenceOfAgateQuestion().c_str() );
		pDC->TextOut(20,60,adimSampleClass.GetNowSentenceOfConvertQuestion().c_str() );

		pDC->SetTextColor( RGB(255,0,0) ); //赤
		pDC->TextOut(20,60,adimSampleClass.GetNowSentenceOfInputtedConvertQuestionRed().c_str() );
		pDC->TextOut(20,40,adimSampleClass.GetNowSentenceOfInputtedAgateQuestionRed().c_str() );

		pDC->SetTextColor( RGB(0,0,255) ); //青
		pDC->TextOut(20,60,adimSampleClass.GetNowSentenceOfInputtedConvertQuestionBlue().c_str() );
		pDC->TextOut(20,40,adimSampleClass.GetNowSentenceOfInputtedAgateQuestionBlue().c_str() );
	}else {
		pDC->TextOut(20,40,"おつかれさまでした");
	}
}


// CAdimSampleView 診断

#ifdef _DEBUG
void CAdimSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CAdimSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAdimSampleDoc* CAdimSampleView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAdimSampleDoc)));
	return (CAdimSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CAdimSampleView メッセージ ハンドラ

void CAdimSampleView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO : ここにメッセージ ハンドラ コードを追加するか、既定の処理を呼び出します。
	//do{
	//int result = adimSampleClass.InputTypewordFromKeyboard(nChar);

	//if( result == 2 ) {
	//	questionNumber++;
	//	adimSampleClass.SetQuestion( questionNumber );
	//	adimSampleClass.SaveKeycodeTableCandidateNumber(); //キーコードテーブルの保存
	//	if( adimSampleClass.GetNumberOfWorkbookElement() <= questionNumber ){
	//		bComplete = true;
	//	}
	//}
	//if( !adimSampleClass.isFinishTyping() )
	adimSampleClass.InputCharacter((char)nChar);

	InvalidateRect(NULL);
	CView::OnChar(nChar, nRepCnt, nFlags);
}
