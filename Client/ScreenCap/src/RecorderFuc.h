#pragma once
#include "MediaRecordTypeDef.h"

// ��ʾ����Ϣ 
struct uMonitorInfo
{
	std::wstring wsName;								// ��ʾ������
	RECT rcMonitor;										// ��ǰ��ʾ������
	RECT rcWork;										// ��ǰ��ʾ����������
	bool bMainDisPlay;									// �Ƿ�����ʾ��
};

typedef std::vector<uMonitorInfo> VEC_MONITORMODE_INFO;  // ���е���ʾ����Ϣ 

//��ȡ��ʾ������Ϣ
void Monitor_GetAllInfo(VEC_MONITORMODE_INFO& m_vecMonitorListInfo);


struct uDeviceInfo
{
	std::wstring devid;
	std::wstring devName;
};

typedef std::vector<uDeviceInfo> VEC_DEVICE_INFO; 

void Device_GetAllInfo(VEC_DEVICE_INFO& vecDeviceListInfo, int type);