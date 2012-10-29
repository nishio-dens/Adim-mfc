// AdimSampleView.h : CAdimSampleView クラスのインターフェイス
//


#pragma once
#include "AdimBase.h"
#include "Adim.h"


class CAdimSampleView : public CView
{
private:
	Adim adimSampleClass;
protected: // シリアル化からのみ作成します。
	CAdimSampleView();
	DECLARE_DYNCREATE(CAdimSampleView)

// 属性
public:
	CAdimSampleDoc* GetDocument() const;

// 操作
public:

// オーバーライド
	public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 実装
public:
	virtual ~CAdimSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // AdimSampleView.cpp のデバッグ バージョン
inline CAdimSampleDoc* CAdimSampleView::GetDocument() const
   { return reinterpret_cast<CAdimSampleDoc*>(m_pDocument); }
#endif

