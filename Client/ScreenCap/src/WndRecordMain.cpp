#include "stdafx.h"
#include "RecorderCfgMgr.h"
#include "WndRecordMain.h"

#define TIMER_RECORD  WM_USER+531
#define WM_TRAYICONRECORD WM_USER+923


CWndRecordMain::CWndRecordMain()
	:m_pLabRecordTime(NULL)
	,nlasttime_(0)
	,hRecorder_(NULL)
{
}


CWndRecordMain::~CWndRecordMain()
{
}

void CWndRecordMain::InitWindow()
{
	m_pLabRecordTime = static_cast<CLabelUI*>(m_pm.FindControl(_T("LabRecordTime"))); ASSERT(m_pLabRecordTime);
	hRecorder_ = MR_CreateScreenAudioRecorder(); ASSERT(hRecorder_);
    m_TrayIcon.CreateTrayIcon(this->GetHWND(), IDI_SCREENCAP, L"屏幕录制", WM_TRAYICONRECORD);
}

void CWndRecordMain::OnFinalMessage(HWND hWnd)
{
    MR_StopRecord(hRecorder_);
    MR_DestroyScreenAudioRecorder(hRecorder_);
    DuiKillTimer(TIMER_RECORD);//关闭定时器
    m_TrayIcon.DeleteTrayIcon();
    ::PostQuitMessage(0);
}

DuiLib::CDuiString CWndRecordMain::GetSkinFolder()
{
	return _T("Skin\\");
}

LPCTSTR CWndRecordMain::GetWindowClassName(void) const
{
	return _T("RedhongseLiveWndBase");
}

DuiLib::CDuiString CWndRecordMain::GetSkinFile()
{
	return _T("WndMainRecord.xml");
}

CControlUI* CWndRecordMain::CreateControl(LPCTSTR pstrClass)
{
	return NULL;
}

void CWndRecordMain::Notify(TNotifyUI& msg)
{
	if (_tcsicmp(msg.sType, DUI_MSGTYPE_CLICK) == 0)
	{
		if (_tcsicmp(msg.pSender->GetName(), _T("BtnClose")) == 0)
		{
            Close();
		}
		else if (_tcsicmp(msg.pSender->GetName(), _T("BtnMin")) == 0)
		{
			::ShowWindow(this->GetHWND(), SW_MINIMIZE);
		}
		else if (_tcsicmp(msg.pSender->GetName(), _T("OptRecord")) == 0)
		{
			COptionUI* pOpt = (COptionUI*)(msg.pSender);
			if (pOpt->IsSelected())
			{
				MR_StopRecord(hRecorder_);
				pOpt->SetToolTip(L"开始录制");
				m_pLabRecordTime->SetVisible(false);
				m_pLabRecordTime->SetText(L"");
				DuiKillTimer(TIMER_RECORD);
			}
			else
			{
				pOpt->SetToolTip(L"停止录制");
				m_pLabRecordTime->SetVisible(true);
				DuiSetTimer(TIMER_RECORD, 1000);
				MediaFileRecorder::RECORD_INFO cfg;
				CRecorderCfgMgr::GetDefCofig(cfg);
				MR_SetRecordInfo(hRecorder_, cfg);
				MR_StartRecord(hRecorder_);
				nlasttime_ = 0;
				
			}
		}
	}
	else if (_tcsicmp(msg.sType, DUI_MSGTYPE_TIMER) == 0)
	{
		if (msg.wParam == TIMER_RECORD)
		{
			nlasttime_++;
			m_pLabRecordTime->SetText(formatstring(nlasttime_).c_str());	
		}
	}
}

LRESULT CWndRecordMain::HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
    if (WM_TRAYICONRECORD == uMsg)
    {
        bHandled = TRUE;
        if (wParam != IDI_SCREENCAP)
            return 1;
        switch (lParam)
        {
        case WM_RBUTTONUP:
            ShowWindow(true, true);
            break;
        case WM_LBUTTONUP:
            ShowWindow(true, true);
            CenterWindow();
            SetForegroundWindow(this->GetHWND());
            break;
        default:
            break;
        }
    }
    return 0;
}

std::wstring CWndRecordMain::formatstring(int tm)
{
	int nHour = tm / 3600;
	int nMinute = (tm - (3600 * nHour)) / 60;
	int nSecond = (tm - (3600 * nHour) - (60 * nMinute));
	wchar_t wch[10] = { 0 };
	_snwprintf_s(wch, 10, _TRUNCATE, L"%d:%02d:%02d", nHour, nMinute, nSecond);
	return wstring(wch);
}
