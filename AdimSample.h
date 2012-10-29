// AdimSample.h : AdimSample アプリケーションのメイン ヘッダー ファイル
//
#pragma once

#ifndef __AFXWIN_H__
	#error このファイルを PCH に含める前に、'stdafx.h' を含めてください。
#endif

#include "resource.h"       // メイン シンボル


// CAdimSampleApp:
// このクラスの実装については、AdimSample.cpp を参照してください。
//

class CAdimSampleApp : public CWinApp
{
public:
	CAdimSampleApp();


// オーバーライド
public:
	virtual BOOL InitInstance();

// 実装
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CAdimSampleApp theApp;
