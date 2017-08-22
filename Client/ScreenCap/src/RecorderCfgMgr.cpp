#include "stdafx.h"
#include <Shlobj.h>
#include <time.h>
#include "RecorderCfgMgr.h"

std::wstring GetUserVideoPath()
{
	wchar_t wcPath[MAX_PATH] = { 0 };
	if (SHGetSpecialFolderPathW(NULL, wcPath, CSIDL_MYVIDEO, FALSE) == TRUE){
		return wstring(wcPath);
	}
	return L"";
}

CRecorderCfgMgr::CRecorderCfgMgr()
{
}


CRecorderCfgMgr::~CRecorderCfgMgr()
{
}

void CRecorderCfgMgr::GetDefCofig(MediaFileRecorder::RECORD_INFO& cfg)
{
	//获得
	memset(cfg.file_name, 0, MAX_PATH);
	char path[200] = {0};
	if (SHGetSpecialFolderPathA(NULL, path, CSIDL_MYVIDEO, FALSE) == TRUE){
		_snprintf_s(cfg.file_name, 200, _TRUNCATE, "%s\\%d.mp4", path, time(NULL));
	}

	//主屏大小
	cfg.video_capture_rect.left = 0;
	cfg.video_capture_rect.top = 0;
	cfg.video_capture_rect.right = GetSystemMetrics(SM_CXFULLSCREEN);
	cfg.video_capture_rect.bottom = GetSystemMetrics(SM_CYFULLSCREEN);

	cfg.video_dst_width = GetSystemMetrics(SM_CXFULLSCREEN);
	cfg.video_dst_height = GetSystemMetrics(SM_CYFULLSCREEN);

	cfg.video_frame_rate = 30;//30帧率

	cfg.quality = MediaFileRecorder::HIGH;

	cfg.is_record_video = TRUE;
	cfg.is_record_mic = TRUE;
	cfg.is_record_speaker = TRUE;

}
