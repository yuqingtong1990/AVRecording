#include "stdafx.h"
#include "IScreeAudioRecord.h"
#include "IScreenAudioRecord_C.h"
#include "log.h"
#include "strsafe.h"

using namespace MediaFileRecorder;

RECORDAPI int MR_Add(int a, int b)
{
	return a + b;
}

RECORDAPI void MR_SetLogCallBack(MediaFileRecorder::sdk_log_cb_t cb)
{
	set_log_func(cb);
}


RECORDAPI RecorderHander MR_CreateScreenAudioRecorder()
{
	return (void*)CreateScreenAudioRecorder();
}


RECORDAPI void MR_DestroyScreenAudioRecorder(RecorderHander pObject)
{
	DestroyScreenAudioRecorder((IScreenAudioRecord*)pObject);
}


RECORDAPI int MR_SetRecordInfo(RecorderHander pObject, const MediaFileRecorder::RECORD_INFO& recordInfo)
{
	IScreenAudioRecord* pRecorder = (IScreenAudioRecord*)pObject;
	if (pRecorder)
	{
		return pRecorder->SetRecordInfo(recordInfo);
	}
	return -1;
}


RECORDAPI int MR_StartRecord(RecorderHander pObject)
{
	IScreenAudioRecord* pRecorder = (IScreenAudioRecord*)pObject;
	if (pRecorder)
	{
		return pRecorder->StartRecord();
	}
	return -1;
}


RECORDAPI int MR_SuspendRecord(RecorderHander pObject)
{
	IScreenAudioRecord* pRecorder = (IScreenAudioRecord*)pObject;
	if (pRecorder)
	{
		return pRecorder->SuspendRecord();
	}
	return -1;
}


RECORDAPI int MR_ResumeRecord(RecorderHander pObject)
{
	IScreenAudioRecord* pRecorder = (IScreenAudioRecord*)pObject;
	if (pRecorder)
	{
		return pRecorder->ResumeRecord();
	}
	return -1;
}


RECORDAPI int MR_StopRecord(RecorderHander pObject)
{
	IScreenAudioRecord* pRecorder = (IScreenAudioRecord*)pObject;
	if (pRecorder)
	{
		return pRecorder->StopRecord();
	}
	return -1;
}