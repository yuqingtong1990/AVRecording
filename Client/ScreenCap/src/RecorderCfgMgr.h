#pragma once
#include "MediaRecordTypeDef.h"

class CRecorderCfgMgr
{
public:
	CRecorderCfgMgr();
	~CRecorderCfgMgr();
public:
	static void GetDefCofig(MediaFileRecorder::RECORD_INFO& cfg);
};

