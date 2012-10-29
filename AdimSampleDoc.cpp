// AdimSampleDoc.cpp : CAdimSampleDoc クラスの実装
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


// CAdimSampleDoc コンストラクション/デストラクション

CAdimSampleDoc::CAdimSampleDoc()
{
	// TODO: この位置に１度だけ呼ばれる構築用のコードを追加してください。

}

CAdimSampleDoc::~CAdimSampleDoc()
{
}

BOOL CAdimSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CAdimSampleDoc シリアル化

void CAdimSampleDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 格納するコードをここに追加してください。
	}
	else
	{
		// TODO: 読み込むコードをここに追加してください。
	}
}


// CAdimSampleDoc 診断

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


// CAdimSampleDoc コマンド
