#ifndef  SCREENGDIGRABBER_H
#define  SCREENGDIGRABBER_H

#include "IScreenGrabber.h"
#include <vector>
#include <windows.h>

namespace MediaFileRecorder
{
	class CScreenGdiGrabber : public IScreenGrabber
	{
	public:
		CScreenGdiGrabber();
		~CScreenGdiGrabber();

		int RegisterDataCb(IScreenGrabberDataCb* cb) override;
		int UnRegisterDataCb(IScreenGrabberDataCb* cb) override;

		int SetGrabRect(const RECT& rect) override;
		int SetGrabFrameRate(int frame_rate) override;

		int StartGrab() override;
		int StopGrab() override;

	private:
		void CleanUp();
		int StartGrabThread();
		int StopGrabThread();
        static unsigned int WINAPI GrabThreadProc(void* Param);
		void GrabThreadProc();

	private:
		bool started_;
		bool run_;
		std::vector<IScreenGrabberDataCb*> vec_data_cb_;
		CRITICAL_SECTION m_sectionDataCb;
		RECT grab_rect_;
		int frame_rate_;
		VIDEO_INFO video_info_;
		HDC src_dc_;
		HDC dst_dc_;
		BITMAPINFO bmi_;
		HBITMAP hbmp_;
		void* bmp_buffer_;
		HANDLE grab_thread_;
	};
}


#endif