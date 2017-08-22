// ScreenCap.cpp : ����Ӧ�ó������ڵ㡣
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
		::MessageBoxA(NULL, "��ǰϵͳ�Ѿ�������һ��¼��ʵ��,�����˳��Ѿ��򿪵Ŀͻ���", "��ʾ", MB_OK);
		return 0;
	}

	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr))
		return 0;

	CPaintManagerUI::SetInstance(hInstance);
	CWndRecordMain dlg;
	dlg.Create(NULL, _T("��Ļ¼��"), WS_POPUP, WS_EX_TOOLWINDOW);
	dlg.CenterWindow();
	dlg.ShowWindow(true, true);
	CPaintManagerUI::MessageLoop();
    //�ȴ�һ����¼���߳�ֹͣ
    Sleep(1000);
	::CoUninitialize();
	return 0;
}