#ifndef __UITREE_H__
#define __UITREE_H__
#include <vector>

#pragma once

namespace DuiLib {
/////////////////////////////////////////////////////////////////////////////////////
// UITree

// Flags for CTreeUI Insert()
#define UITREE_INSERT_ROOT			0x0001
#define UITREE_INSERT_FIRST			0x0002
#define UITREE_INSERT_LAST			0x0004
#define UITREE_INSERT_SORT			0x0008

// Flags for CTreeUI FindSelectable()
#define UITREE_FIND_PREV			0x0001
#define UITREE_FIND_NEXT			0x0002
#define UITREE_FIND_FIRST			0x0004
#define UITREE_FIND_LAST			0x0008

typedef struct tagTTreeInfoUI
{
	int nFont;
	UINT uTextStyle;
	RECT rcTextPadding;
	DWORD dwTextColor;
	DWORD dwBkColor;
	CDuiString sBkImage;
	DWORD dwSelectedTextColor;
	DWORD dwSelectedBkColor;
	CDuiString sSelectedImage;
	DWORD dwHotTextColor;
	DWORD dwHotBkColor;
	CDuiString sHotImage;
	DWORD dwDisabledTextColor;
	DWORD dwDisabledBkColor;
	CDuiString sDisabledImage;
	bool bShowHtml;
	bool bMultiExpandable;
	CDuiString sGroupCollapseImage;
	CDuiString sGroupExpandImage;
	UINT nIndent;
} TTreeInfoUI;

typedef struct tagTTreeItemUI
{
	CControlUI* pParent;
	CControlUI* pPrevItem;
	CControlUI* pNextItem;
	tagTTreeItemUI()
	{
		pParent = NULL;
		pPrevItem = NULL;
		pNextItem = NULL;
	}
} TTreeItemUI;

typedef bool (*LPTREESORT)(CControlUI* pItem1, CControlUI* pItem2);

class ITreeUI
{
public:
	virtual CControlUI* GetCurSel() const = 0;
	virtual bool SelectItem(CControlUI* pItem, bool bTakeFocus = false) = 0;
	virtual void DoEvent(TEventUI& event) = 0;  

	virtual TTreeInfoUI* GetTreeInfo() = 0;

	virtual bool GetMultiExpandable() const = 0;
	virtual void SetMultiExpandable(bool bMultiExpand) = 0;
	virtual bool ExpandItem(CControlUI* pItem, bool bExpand) = 0;
	// �������������չ�������˺�������ֵΪ�գ������ɸ����������ƣ�
	virtual CControlUI* GetExpandedItem() const = 0;

	// ����˫��չ���Ĭ�Ͽ�����
	virtual void EnableDBClickExpand(bool bEnable) = 0;
	virtual bool IsEnableDBClickExpand() const = 0;

	// �˺������ڶ����д�����������ʱʹ�ã������Ϊ��ʾ�ģ�����һ���ڵ������ˢ��
	// ��������Ϊ�˱������ˢ�£�Ӧ�ڴ�����������ǰ�ر�ˢ�£������������ˢ��
	virtual void EnableUpdate(bool bUpdate) = 0;

	// �����ж��������ֻ�ܻ�ȡ��һ��
	virtual CControlUI* GetRoot() = 0;
};

class ITreeItemUI
{
#define SORT_KEY_COUNT		5		// ����Key����Ŀ
public:
	virtual ITreeUI* GetOwner() = 0;
	virtual void SetOwner(ITreeUI* pOwner) = 0;

	virtual bool IsSelected() const = 0;
	virtual bool Select(bool bSelect = true) = 0;

	//************************************
	// ˵��:    ���ýڵ������key,���ʹ��key��������������key��
	//			����˳������ַ����Ƚ�,ʹ�õ�һ������ȵĽ����Ϊ����ȽϽ��
	// ����:	nIndex	����ֵ��SORT_KEY_COUNT��Χ��,������ȷ��Χ���ý���Ч
	// ����:	pStrKey	Keyֵ
	// ����:	bSort	�Ƿ��������������丸�ڵ�
	// ����ֵ:  void
	//************************************
	virtual void SetSortKey(int nIndex, LPCTSTR pStrKey, bool bSort = false) = 0;
	virtual LPCTSTR GeSorttKey(int nIndex) = 0;

	// ������ͼ�꣬��ͼ���С����߶�����ɵ�һ�������Σ�������ͼ�����
	virtual void SetItemImage(STRINGorID pStrImage) = 0;
	virtual LPCTSTR GetItemImage() const = 0;
	virtual void SetShowItemImage(bool bShow) = 0;
	virtual bool IsShowItemImage() = 0;

	virtual CControlUI* GetParentItem() const = 0;

	// ��ȡǰһ���ֵ���
	virtual CControlUI* GetPrevSiblingItem() = 0;
	// ��ȡ��һ���ֵ���
	virtual CControlUI* GetNextSiblingItem() = 0;

	virtual bool IsExpanded() const = 0;
	virtual bool Expand(bool bExpand = true) = 0;

	virtual int GetCount() const = 0;
	virtual bool IsHasChildren() = 0;

	virtual int GetLevel() = 0;

	// ��ȡ��һ������
	virtual CControlUI* GetChildItem() = 0;
};

class CTreeItemUI;

class UILIB_API CTreeUI : public CVerticalLayoutUI, public ITreeUI
{
	friend class CTreeItemUI;
	DECLARE_DUICONTROL(CTreeUI)
public:
	CTreeUI(void);
	~CTreeUI(void);

	LPCTSTR GetClass() const;
	UINT GetControlFlags() const;
	LPVOID GetInterface(LPCTSTR pstrName);

	//////////////////////////////////////////////////////////////////////////
	// �̳���CVerticalLayoutUI
	int GetCount() const;
	bool Add(CControlUI* pControl);
	bool AddAt(CControlUI* pControl, int iIndex) { return false; }

	void SetVisible(bool bVisible = true);
	void SetInternVisible(bool bVisible = true);

	void SetScrollPos(SIZE szPos);
	void SetPos(RECT rc);

	void SetManager(CPaintManagerUI* pManager, CControlUI* pParent, bool bInit = true);
	CControlUI* FindControl(FINDCONTROLPROC Proc, LPVOID pData, UINT uFlags);
	
	void DoPaint(HDC hDC, const RECT& rcPaint);
	void DoEvent(TEventUI& event);

	void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

	//////////////////////////////////////////////////////////////////////////
	// �̳���ITreeUI
	CControlUI* GetCurSel() const;
	virtual bool SelectItem(CControlUI* pItem, bool bTakeFocus = false);

	TTreeInfoUI* GetTreeInfo();
	bool GetMultiExpandable() const;
	void SetMultiExpandable(bool bMultiExpand);
	bool ExpandItem(CControlUI* pItem, bool bExpand);
	CControlUI* GetExpandedItem() const;
	void EnableDBClickExpand(bool bEnable);
	bool IsEnableDBClickExpand() const;
	// �˺������ڶ����д�����������ʱʹ�ã������Ϊ��ʾ�ģ�����һ���ڵ������ˢ��
	// ��������Ϊ�˱������ˢ�£�Ӧ�ڴ�����������ǰ�ر�ˢ�£������������ˢ��
	void EnableUpdate(bool bUpdate);
	CControlUI* GetRoot();

	// nCodeֻ�����������ĸ�ֵ�е�һ��
	// UITREE_INSERT_ROOT		����һ�����ڵ㣬��ʱ������pParent����
	// UITREE_INSERT_FIRST		���뵽�����ӽڵ�֮ǰ
	// UITREE_INSERT_LAST		���뵽�����ӽڵ�֮��
	// UITREE_INSERT_SORT		�������������,Ӧ��������ָ�봫�룬�����޷�����
	bool Insert(CControlUI* pControl, CControlUI* pParent = NULL, int nCode = UITREE_INSERT_ROOT, LPTREESORT lpTreeSort = NULL);
	bool Remove(CControlUI* pControl);
	void RemoveAll();

	// ����ĳ���ڵ���ӽڵ㣬���pControlΪNULL��������������
	// bRecursive �Ƿ�ݹ��������������ӽڵ���ӽڵ㣨�е���ơ���
	bool SortChildren(CControlUI* pControl, LPTREESORT pSort, bool bRecursive = true);
	// ͨ���ڵ��Key�������pControlΪNULL��������������
	// ��Ȼû������Key��Ȼ�������򣬵��ұ�֤�����������ϣ����
	bool SortChildrenByKey(CControlUI* pControl, bool bRecursive = true);

	void EnsureVisible(CControlUI* pControl);

	void SetItemFont(int index);
	void SetItemTextStyle(UINT uStyle);
	void SetItemTextPadding(RECT rc);
	void SetItemTextColor(DWORD dwTextColor);
	void SetItemBkColor(DWORD dwBkColor);
	void SetItemBkImage(LPCTSTR pStrImage);
	void SetSelectedItemTextColor(DWORD dwTextColor);
	void SetSelectedItemBkColor(DWORD dwBkColor);
	void SetSelectedItemImage(LPCTSTR pStrImage); 
	void SetHotItemTextColor(DWORD dwTextColor);
	void SetHotItemBkColor(DWORD dwBkColor);
	void SetHotItemImage(LPCTSTR pStrImage);
	void SetDisabledItemTextColor(DWORD dwTextColor);
	void SetDisabledItemBkColor(DWORD dwBkColor);
	void SetDisabledItemImage(LPCTSTR pStrImage);
	bool IsItemShowHtml();
	void SetItemShowHtml(bool bShowHtml = true);
	RECT GetItemTextPadding() const;
	DWORD GetItemTextColor() const;
	DWORD GetItemBkColor() const;
	LPCTSTR GetItemBkImage() const;
	DWORD GetSelectedItemTextColor() const;
	DWORD GetSelectedItemBkColor() const;
	LPCTSTR GetSelectedItemImage() const;
	DWORD GetHotItemTextColor() const;
	DWORD GetHotItemBkColor() const;
	LPCTSTR GetHotItemImage() const;
	DWORD GetDisabledItemTextColor() const;
	DWORD GetDisabledItemBkColor() const;
	LPCTSTR GetDisabledItemImage() const;
	void SetGroupCollapseImage(LPCTSTR pStrImage);
	LPCTSTR GetGroupCollapseImage() const;
	// ����������ͼƬ����ͼƬ�Ĵ�С��߶�����ɵ�������
	void SetGroupExpandImage(LPCTSTR pStrImage);
	LPCTSTR GetGroupExpandImage() const;
	void SetIndent(int nIndent);
	int GetIndent() const;

protected:
	CControlUI* FindSelectable(CControlUI* pControl, UINT uFlags) const;

	bool			m_bDBClickExpand;
	bool			m_bEnableUpdate;
	CControlUI*		m_pCurSel;
	CControlUI*		m_pExpandedItem;
	TTreeInfoUI		m_TreeInfo;
	CTreeItemUI*	m_pRoot;

private:
	LONG	m_lDelayDeltaY;
	DWORD	m_dwDelayNumber;
	DWORD	m_dwDelayLeft;
};

class UILIB_API CTreeItemUI 
	: public CControlUI
	, public ITreeItemUI
	, public IContainerUI
{
	friend class CTreeUI;
public:
	DECLARE_DUICONTROL(CTreeItemUI)
	CTreeItemUI();
	~CTreeItemUI();

	LPCTSTR GetClass() const;
	UINT GetControlFlags() const;
	LPVOID GetInterface(LPCTSTR pstrName);

	//////////////////////////////////////////////////////////////////////////
	// �̳���IContainerUI
	CControlUI* GetItemAt(int iIndex) const { return NULL; }
	int GetItemIndex(CControlUI* pControl) const { return -1; }
	bool SetItemIndex(CControlUI* pControl, int iIndex) { return false; }
	bool Add(CControlUI* pControl);	
	bool AddAt(CControlUI* pControl, int iIndex) { return false; }
	bool RemoveAt(int iIndex) { return true ;}

	//////////////////////////////////////////////////////////////////////////
	// �̳���CControlUI
	void SetEnabled(bool bEnable = true);

	void Invalidate(); // ֱ��CControl::Invalidate�ᵼ�¹�����ˢ�£���д����ˢ������
	bool Activate();

	void SetPos(RECT rc);
	SIZE EstimateSize(SIZE szAvailable);
	void DoPaint(HDC hDC, const RECT& rcPaint);
	bool DrawImage(HDC hDC, LPCTSTR pStrImage, LPCTSTR pStrModify = NULL);
	void PaintGroupImage(HDC hDC);
	void PaintItemImage(HDC hDC);
	void PaintText(HDC hDC);
	void PaintItemBk(HDC hDC);
	void DoEvent(TEventUI& event);

	void SetVisible(bool bVisible = true);
	void SetInternVisible(bool bVisible = true);

	void SetManager(CPaintManagerUI* pManager, CControlUI* pParent, bool bInit = true);
	CControlUI* FindControl(FINDCONTROLPROC Proc, LPVOID pData, UINT uFlags);

	void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

	//////////////////////////////////////////////////////////////////////////
	// �̳��� ITreeItemUI
	ITreeUI* GetOwner();
	void SetOwner(ITreeUI* pOwner);

	bool IsSelected() const;
	bool Select(bool bSelect = true);

	void SetSortKey(int nIndex, LPCTSTR pStrKey, bool bSortParent = false);
	LPCTSTR GeSorttKey(int nIndex);

	// ������ͼ��
	void SetItemImage(STRINGorID pStrImage);
	LPCTSTR GetItemImage() const;
	void SetShowItemImage(bool bShow);
	bool IsShowItemImage();
	// �����Ƿ���ʾ��ͼ�ꡣnShow����0��һֱ��ʾ������0�����ӽڵ����ʾ,���ӽڵ�����ʾ
	// С��0��һֱ����ʾ��Ĭ��nShow����0
	void SetShowGroupImage(int nShow);
	int IsShowGroupImage();

	CControlUI* GetParentItem() const;
	// ��ȡǰһ���ֵ���
	CControlUI* GetPrevSiblingItem();
	// ��ȡ��һ���ֵ���
	CControlUI* GetNextSiblingItem();

	int GetCount() const;
	bool IsHasChildren();

	int GetLevel();

	// ��ȡ��һ������
	CControlUI* GetChildItem();
	CControlUI* GetLastItem();

	bool IsExpanded() const;
	bool Expand(bool bExpand = true);
protected:
	bool Insert(CControlUI* pControl, int nCode = UITREE_INSERT_LAST, LPTREESORT lpTreeSort = NULL);
	bool Remove(CControlUI* pControl);
	void RemoveAll(); 
	void SortChildren(LPTREESORT pSort, bool bRecursive = true);
	void SortChildrenByKey(bool bRecursive = true);
	// ��ʼ�������ӽڵ��������ϵ
	void InitRelation();

private:
	static bool Compare( CControlUI* pControl1, CControlUI* pControl2 );

protected:
	int m_nLevel;
	bool m_bSelected;
	bool m_bShowImage;
	int m_nShowGroupImage;
	UINT m_uButtonState;

	CDuiString m_sItemImage;
	CDuiString m_aStrSortKey[SORT_KEY_COUNT];

	ITreeUI* m_pOwner;
	TTreeItemUI m_TreeItem;

	CContainerUI* m_pContainer;
	bool m_bExpand;
	std::vector<CControlUI*> m_vecChildren;
	bool m_bDelayedDestroy;
};

} // namespace Duilib

#endif // __UITREE_H__
