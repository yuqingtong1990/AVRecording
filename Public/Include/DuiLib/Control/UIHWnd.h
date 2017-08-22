#ifndef __UIHWND_H__
#define __UIHWND_H__

#pragma once

namespace DuiLib
{
	class UILIB_API CHWndUI 
		: public CControlUI
	{
	public:
		DECLARE_DUICONTROL(CHWndUI)
		CHWndUI();
		~CHWndUI();
		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

		void SetManager(CPaintManagerUI* pManager, CControlUI* pParent, bool bInit = true);

		void SetVisible(bool bVisible = true);
		void SetInternVisible(bool bVisible = true);
		void SetPos(RECT rc,bool bNeedInvalidate = true);

		RECT GetInset() const;
		void SetInset(RECT rcInset);

		bool Attach(HWND hWnd);
		// Detach后会隐藏绑定窗口
		HWND Detach(void);
		HWND GetHWND() const;

	protected:
		HWND		m_hWnd;
		HWND		m_hOldParent;
		RECT		m_rcInset;
	};
}
#endif