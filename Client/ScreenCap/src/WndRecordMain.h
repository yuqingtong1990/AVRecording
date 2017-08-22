#pragma once
#include "IScreenAudioRecord_C.h"

/*
*@录制主窗口
*/

class CWndRecordMain
	:public WindowImplBase
{
public:
	CWndRecordMain();
	~CWndRecordMain();
public:
	virtual void InitWindow();
    virtual void OnFinalMessage(HWND hWnd);
	virtual CDuiString GetSkinFolder();
	virtual LPCTSTR GetWindowClassName(void) const;
	virtual CDuiString GetSkinFile();
	virtual CControlUI* CreateControl(LPCTSTR pstrClass);
	virtual void Notify(TNotifyUI& msg);
    LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
private:
	wstring formatstring(int ntime);
private:
	CLabelUI* m_pLabRecordTime;
	int nlasttime_;	//录制持续的时间
	RecorderHander hRecorder_;
    CTrayIconEx m_TrayIcon;
};

