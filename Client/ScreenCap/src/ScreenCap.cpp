// ScreenCap.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "WndRecordMain.h"
#include "RecorderFuc.h"

#define MUTEXONLYONE	_T("live_client_isrunning_Recording")


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	HANDLE hMutex = NULL;
	hMutex = CreateMutex(NULL, TRUE, MUTEXONLYONE);
	if (ERROR_ALREADY_EXISTS == GetLastError())
	{
		::MessageBoxA(NULL, "当前系统已经运行了一个录屏实例,请先退出已经打开的客户端", "提示", MB_OK);
		return 0;
	}

	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr))
		return 0;

	CPaintManagerUI::SetInstance(hInstance);
	CWndRecordMain dlg;
	dlg.Create(NULL, _T("屏幕录制"), WS_POPUP, WS_EX_TOOLWINDOW);
	dlg.CenterWindow();
	dlg.ShowWindow(true, true);
	CPaintManagerUI::MessageLoop();
    //等待一秒让录制线程停止
    Sleep(1000);
	::CoUninitialize();
	return 0;
}