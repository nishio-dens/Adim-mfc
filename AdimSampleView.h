// AdimSampleView.h : CAdimSampleView �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "AdimBase.h"
#include "Adim.h"


class CAdimSampleView : public CView
{
private:
	Adim adimSampleClass;
protected: // �V���A��������̂ݍ쐬���܂��B
	CAdimSampleView();
	DECLARE_DYNCREATE(CAdimSampleView)

// ����
public:
	CAdimSampleDoc* GetDocument() const;

// ����
public:

// �I�[�o�[���C�h
	public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h����܂��B
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ����
public:
	virtual ~CAdimSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // AdimSampleView.cpp �̃f�o�b�O �o�[�W����
inline CAdimSampleDoc* CAdimSampleView::GetDocument() const
   { return reinterpret_cast<CAdimSampleDoc*>(m_pDocument); }
#endif

