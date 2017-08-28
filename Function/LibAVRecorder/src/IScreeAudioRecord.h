#ifndef ISCREENAUDIORECORD_H
#define ISCREENAUDIORECORD_H

/*
*屏幕录制功能函数C++导出接口
*/

#include "MediaRecordTypeDef.h"

namespace MediaFileRecorder
{
	class RECORDAPI IScreenAudioRecord
	{
	public:
		virtual int SetRecordInfo(const RECORD_INFO& recordInfo) = 0;
		virtual int StartRecord() = 0;
		virtual int SuspendRecord() = 0;
		virtual int ResumeRecord() = 0;
		virtual int StopRecord() = 0;

		virtual ~IScreenAudioRecord(){}
	};


	RECORDAPI void SetLogCallback(sdk_log_cb_t cb);
	RECORDAPI IScreenAudioRecord* CreateScreenAudioRecorder();
	RECORDAPI void DestroyScreenAudioRecorder(IScreenAudioRecord* pRecorder);
}

#endif