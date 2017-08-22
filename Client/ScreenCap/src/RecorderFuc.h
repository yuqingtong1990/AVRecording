#pragma once
#include "MediaRecordTypeDef.h"

// 显示器信息 
struct uMonitorInfo
{
	std::wstring wsName;								// 显示器名称
	RECT rcMonitor;										// 当前显示器区域
	RECT rcWork;										// 当前显示器工作区域
	bool bMainDisPlay;									// 是否主显示器
};

typedef std::vector<uMonitorInfo> VEC_MONITORMODE_INFO;  // 所有的显示器信息 

//获取显示器的信息
void Monitor_GetAllInfo(VEC_MONITORMODE_INFO& m_vecMonitorListInfo);


struct uDeviceInfo
{
	std::wstring devid;
	std::wstring devName;
};

typedef std::vector<uDeviceInfo> VEC_DEVICE_INFO; 

void Device_GetAllInfo(VEC_DEVICE_INFO& vecDeviceListInfo, int type);