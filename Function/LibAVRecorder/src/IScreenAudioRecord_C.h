#ifndef ISCREENAUDIORECORD_C_H
#define ISCREENAUDIORECORD_C_H

#ifdef LIBAVRECORDER_EXPORTS
#define RECORDAPI __declspec(dllexport)
#else
#define RECORDAPI __declspec(dllimport)
#endif

#include "MediaRecordTypeDef.h"

typedef void* RecorderHander;

extern "C"
{
	RECORDAPI int  MR_Add(int a, int b);

	RECORDAPI void MR_SetLogCallBack(MediaFileRecorder::sdk_log_cb_t cb);

	RECORDAPI RecorderHander MR_CreateScreenAudioRecorder();
	
	RECORDAPI void MR_DestroyScreenAudioRecorder(void* pObject);

	RECORDAPI int MR_SetRecordInfo(RecorderHander pObject, const MediaFileRecorder::RECORD_INFO& recordInfo);

	RECORDAPI int MR_StartRecord(RecorderHander pObject);

	RECORDAPI int MR_SuspendRecord(RecorderHander pObject);

	RECORDAPI int MR_ResumeRecord(RecorderHander pObject);

	RECORDAPI int MR_StopRecord(RecorderHander pObject);
}
#endif