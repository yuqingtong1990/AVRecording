#pragma once

namespace DuiLib
{
	class UILIB_API CChildWndBase
		: public IDialogBuilderCallback
		, public IMessageFilterUI
		, public INotifyUI
	{
	public:
		CChildWndBase(CPaintManagerUI& PaintManager);
		virtual ~CChildWndBase(void);
		virtual void Create(HWND hParent);
		virtual void Release(void);
		virtual CControlUI* GetRoot(void);
		virtual void Init(){};
		virtual void DuiSetTimer(UINT_PTR nIDEvent, UINT uElapse);
		virtual void DuiKillTimer(UINT_PTR nIDEvent);
		virtual LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled);
		virtual void Notify(TNotifyUI& msg){};
		virtual CControlUI* CreateControl(LPCTSTR pstrClass);
		HWND GetParentHWND() const;
		CControlUI* GetControlByName(LPCTSTR pstrName);
	protected:
		virtual CDuiString GetSkinFolder() = 0;
		virtual CDuiString GetSkinFile() = 0;
		virtual bool OnRootInit(void* param);
		virtual bool OnRootDestroy(void* param);
	protected:
		CPaintManagerUI& m_pm;
		HWND			m_hParent;
		CControlUI* m_pRoot;
	};
}
