#ifdef CPPUTIL_EXPORTS
#define CPPUTIL_API __declspec(dllexport)
#else
#define CPPUTIL_API __declspec(dllimport)
#endif



#include <list>
#include <string>
#include <vector>
#include <list>
#include <ShellAPI.h>
#pragma warning(disable:4251)


#define SafeDelete(p)   if(p) { delete (p); (p) = NULL;}  
#define SafeDelArry(p)  if(p) { delete []p; (p) = NULL;}  
#define SafeFree(p)   if(p) { free (p); (p) = NULL;}  
#define NELEMS(arr) (sizeof(arr) / sizeof(arr[0]))

enum{GBK = 936};
//----------------------------------------字符串转化----------------------------------------------------------
CPPUTIL_API std::wstring str2wstr(const std::string& str, unsigned int codepage = GBK);
CPPUTIL_API std::string wstr2str(const std::wstring& wstr, unsigned int codepage = GBK);
CPPUTIL_API std::string gbktoUtf8(const std::string& stransi);
CPPUTIL_API std::string utf8togbk(const std::string& strutf8);
CPPUTIL_API std::string delutf8Bom(const std::string& strutf8);
CPPUTIL_API std::string inttostr(int n, int radix = 10);
CPPUTIL_API std::wstring inttowstr(int n, int radix = 10);
CPPUTIL_API std::string int64tostr(long long n, int radix = 10);
CPPUTIL_API std::wstring int64towstr(long long n, int radix = 10);
CPPUTIL_API std::string upperStr(const std::string &sIn);
CPPUTIL_API std::string lowerStr(const std::string &sIn);
CPPUTIL_API std::wstring upperStr(const std::wstring &wsIn);
CPPUTIL_API std::wstring lowerStr(const std::wstring &wsIn);
CPPUTIL_API std::string bin2hex(const std::string &in, int size = 0);
CPPUTIL_API std::string hex2bin(const std::string &in);


//字符串转换宏
#define _A2W_  str2wstr
#define _W2A_  wstr2str
#define _U2G_  utf8togbk
#define _G2U_  gbktoUtf8
#define _I2A_  inttostr
#define _I2W_  inttowstr
#define _I642A_  int64tostr
#define _I642W_  int64towstr

//----------------------------------------字符串替换----------------------------------------------------------
CPPUTIL_API std::string& ReplaceString(std::string &s, const std::string &OldPattern, const std::string &NewPattern);
CPPUTIL_API std::wstring& ReplaceStringW(std::wstring &s, const std::wstring &OldPattern, const std::wstring &NewPattern);
CPPUTIL_API std::string& ReplaceStringI(std::string &s, const std::string &OldPattern, const std::string &NewPattern);
CPPUTIL_API std::wstring& ReplaceStringIW(std::wstring &s, const std::wstring &OldPattern, const std::wstring &NewPattern);
CPPUTIL_API void SplitString(const std::string &AString, const std::string &ASplitStr, std::vector<std::string> &AStrings);
CPPUTIL_API void SplitStringW(const std::wstring &AString, const std::wstring &ASplitStr, std::vector<std::wstring> &AStrings);
CPPUTIL_API void SplitString(const std::string &AString, const std::string &ASplitStr, std::string &ALeft, std::string &ARight);
CPPUTIL_API void SplitStringW(const std::wstring &AString, const std::wstring &ASplitStr, std::wstring &ALeft, std::wstring &ARight);

CPPUTIL_API std::string IntList2String(const std::vector<int> &AStringList, const std::string &AConnectStr);
CPPUTIL_API std::wstring IntList2StringW(const std::vector<int> &AStringList, const std::wstring &AConnectStr);
CPPUTIL_API std::string StringList2String(const std::vector<std::string> &AStringList, const std::string &AConnectStr);
CPPUTIL_API std::wstring StringList2StringW(const std::vector<std::wstring> &AStringList, const std::wstring &AConnectStr);
CPPUTIL_API std::string StringList2String(const std::list<std::string> &AStringList, const std::string &AConnectStr);
CPPUTIL_API std::wstring StringList2StringW(const std::list<std::wstring> &AStringList, const std::wstring &AConnectStr);

CPPUTIL_API std::string ConcatString(std::vector<std::string> vecStr);
CPPUTIL_API std::wstring ConcatStringW(std::vector<std::wstring> vecStr);
CPPUTIL_API std::string StrFormat(const char *fmt,...);
CPPUTIL_API std::wstring StrFormatW(const wchar_t *fmt,...);

CPPUTIL_API void GetCommandLineList(std::vector<std::string> &lst);
CPPUTIL_API int ParamCount();
CPPUTIL_API std::string ParamStr(size_t i);
CPPUTIL_API std::wstring ParamStrW(size_t i);

//---------------------------------获取系统操作---------------------------------------------—--
CPPUTIL_API std::wstring GetAppDataPath();//获取系统Appdata路径变量
CPPUTIL_API std::wstring GetDesktopPath();//获取系统当前用户桌面路径变量
CPPUTIL_API std::wstring GetAllUserDesktopPath();//获取系统全部用户桌面路径
CPPUTIL_API std::wstring GetQuickLaunckPath();//获取系统快速启动栏路径
CPPUTIL_API std::wstring GeTaskbarPath();//获取任务栏路径

//---------------------------------文件路径操作---------------------------------------------—--
CPPUTIL_API std::wstring trimW(const std::wstring &str);//去除两端的空格
CPPUTIL_API std::wstring ExcludeTrailingPathDelimiterW(const std::wstring &path);//去除文件路径末端的//
CPPUTIL_API std::wstring IncludeTrailingPathDelimiterW(const std::wstring &path);//在文件路径末端的加上//
CPPUTIL_API std::wstring ExtractFilePathW(const std::wstring &filestr, bool IncludeBackslash);//从文件路径中分离出文件所在的目录
CPPUTIL_API std::wstring ExtractFileNameW(const std::wstring &filestr);//从文件路径中分离出文件名
CPPUTIL_API	std::wstring ExtractUrlNameW(const std::wstring &urlstr); //从url中分离文件名
CPPUTIL_API std::wstring ExtractExtensionsW(const std::wstring &filestr, bool IncludePoint = true);
CPPUTIL_API bool FileExistsW(const std::wstring &fn);//判断文件是否存在
CPPUTIL_API bool DirectoryExistsW(const std::wstring &fn);//判断文件夹路径是否存在
CPPUTIL_API bool ForceDirectoryW(const std::wstring &fn);//强制文件路径(不存在会递归创建)


//----------------------------------------注册表操作----------------------------------------------------------
CPPUTIL_API bool RegKeyExists(HKEY key, std::wstring subkey);
CPPUTIL_API bool RegNewKey(HKEY key, std::wstring subkey);
CPPUTIL_API bool RegValueExists(HKEY key, std::wstring subkey, std::wstring valuname);
CPPUTIL_API DWORD RegGetValueSize(HKEY key, std::wstring subkey, std::wstring valuename);
CPPUTIL_API std::wstring RegReadStringValue(HKEY key, std::wstring subkey, std::wstring valuename, std::wstring defaultret);
CPPUTIL_API bool RegReadBinaryValue(HKEY key, std::wstring subkey, std::wstring valuename,unsigned char *ret, DWORD &retsize);
CPPUTIL_API DWORD RegReadDWORDValue(HKEY key, std::wstring subkey, std::wstring valuename, DWORD defaultret);
CPPUTIL_API bool RegWriteStringValue(HKEY key, std::wstring subkey, std::wstring valuename, std::wstring valuedata);
CPPUTIL_API bool RegWriteBinaryValue(HKEY key, std::wstring subkey, std::wstring valuename, unsigned char *valuedata, DWORD datasize);
CPPUTIL_API bool RegWriteDWORDValue(HKEY key, std::wstring subkey, std::wstring valuename, DWORD valuedata);
CPPUTIL_API bool RegRemoveValue(HKEY key, std::wstring subkey, std::wstring valuename);
CPPUTIL_API bool RegRemoveKey(HKEY key, std::wstring subkey);
CPPUTIL_API bool RegEnumKeys(HKEY key, std::wstring subkey,std::vector<std::wstring> &keys,std::vector<std::wstring> &values);


//----------------------------------------时间日期操作----------------------------------------------------------
CPPUTIL_API bool Str2Datetime(const std::string &str, SYSTEMTIME &ret);
CPPUTIL_API bool IsLeapYear(WORD p_year);
CPPUTIL_API bool IsValidateDate(SYSTEMTIME &dt);
CPPUTIL_API bool IsValidateDateTime(SYSTEMTIME &dt);
CPPUTIL_API int YearsBetween(SYSTEMTIME &p_now, SYSTEMTIME &p_then);
CPPUTIL_API int MonthsBetween(SYSTEMTIME &p_now, SYSTEMTIME &p_then);
CPPUTIL_API int DaysBetween(SYSTEMTIME &p_now, SYSTEMTIME &p_then);
CPPUTIL_API int HoursBetween(SYSTEMTIME &p_now, SYSTEMTIME &p_then);
CPPUTIL_API int MinutesBetween(SYSTEMTIME &p_now, SYSTEMTIME &p_then);
CPPUTIL_API long long SecondsBetween(SYSTEMTIME &p_now, SYSTEMTIME &p_then);
CPPUTIL_API int WeeksBetween(SYSTEMTIME &p_now, SYSTEMTIME &p_then);
CPPUTIL_API void IncYear(SYSTEMTIME &dt, int years);
CPPUTIL_API void IncMonth(SYSTEMTIME &dt, int months);
CPPUTIL_API void IncDay(SYSTEMTIME &dt, int days);
CPPUTIL_API void IncHour(SYSTEMTIME &dt, int hours);
CPPUTIL_API void IncMinute(SYSTEMTIME &dt, int minutes);
CPPUTIL_API void IncSecond(SYSTEMTIME &dt, int seconds);
CPPUTIL_API void IncWeek(SYSTEMTIME &dt, int weeks);
CPPUTIL_API int DayOfWeek(SYSTEMTIME &dt);//0 sunday 1 monday 2 tuesday ...6 saturday 
CPPUTIL_API std::string FormatDatetime(const SYSTEMTIME &st);//以yyyy-mm-dd hh:nn:ss的格式返回一个日期的字符串格式
CPPUTIL_API std::wstring FormatDatetimeW(const SYSTEMTIME &st);
CPPUTIL_API std::string FormatDate(const SYSTEMTIME &st);//以yyyy-mm-dd的格式返回一个日期的字符串格式
CPPUTIL_API std::wstring FormatDateW(const SYSTEMTIME &st);
CPPUTIL_API std::string FormatTime(const SYSTEMTIME &st);//以hh:nn:ss的格式返回一个日期的字符串格式
CPPUTIL_API std::wstring FormatTimeW(const SYSTEMTIME &st);
CPPUTIL_API bool ParseDataTime(const std::wstring ws, SYSTEMTIME& st);
CPPUTIL_API void GetUTCTime( std::wstring& wsTime);
CPPUTIL_API void t2tm(long long time, SYSTEMTIME& st);
CPPUTIL_API void tm2t(long long& time, const SYSTEMTIME& st);



CPPUTIL_API BOOL UrlEncode( const char* szSrc, char* pBuf, int cbBufLen, BOOL bUpperCase );
CPPUTIL_API BOOL UrlDecode( const char* szSrc, char* pBuf, int cbBufLen );
CPPUTIL_API bool SaveBufferToFile(const std::wstring &file, const void *buf, DWORD bufsize);
CPPUTIL_API bool LoadFileToBuffer(const std::wstring &file, void **buf, DWORD &bufsize);

typedef void (*HTTPCALLCB)(void* buf,int size,void* param);
CPPUTIL_API int winhttp_get(const wchar_t *url, const wchar_t *headers_crlf, void **response, int &response_size, std::wstring *response_header, HTTPCALLCB cb = NULL,void* customdata = NULL);
CPPUTIL_API int winhttp_post(const wchar_t *url, const wchar_t *headers_crlf, void **response, int &response_size, std::wstring *response_header, void *postdata, int postdata_size);

CPPUTIL_API int winhttp_ex(const wchar_t *url, void **response, int &response_size, const wchar_t *headers_crlf = NULL, const wchar_t* sMode = NULL, std::wstring* response_header = NULL, void *postdata = NULL, int postdata_size = NULL);

CPPUTIL_API void FreeMemory(void* pFree);

CPPUTIL_API std::string GetWinOSVersion();


class CPPUTIL_API MemoryStream
{
public:
	enum SeekOrigin{soBegin,soEnd,soCurrent};
	MemoryStream(void);
	virtual ~MemoryStream(void);

public:
	long Read(MemoryStream &dest, long bytes);
	long Read(void *dest, long bytes);
	bool Write(const MemoryStream &from, long bytes = -1);
	bool Write(const void *from, long bytes);
	long GetSize() const { return m_size; }
	long GetPos() const { return m_pos; }
	long GetCapacity() const { return m_capacity; }
	void* GetBuffer() const { return m_buffer; }
	void Seek(SeekOrigin so, long offset);
	void Clear();
	bool SaveToFile(const std::wstring &file);
	bool LoadFromFile(const std::wstring &file);
	bool Expand(long new_capacity = -1);//-1 默认为当前容量的两倍
	void SetInitCapacity(long cc){ m_init_capacity = cc; }
private:
	MemoryStream(const MemoryStream&);
	MemoryStream& operator=(const MemoryStream&);
private:
	void* m_buffer;
	long m_size;
	long m_pos;
	long m_capacity;
	long m_init_capacity;
};


class CPPUTIL_API TThread
{
public:
	TThread();
	virtual ~TThread(){};
	void Start();
	void SetTerminated(bool v){ m_Stopped = v; }
	bool GetTerminated(){ return m_Stopped; }
	void SetFreeOnTerminate(bool v){ m_FreeOnTerminate = v; } //
	bool GetFreeOnTerminate(){ return m_FreeOnTerminate; }
	HANDLE GetThreadHandle(){ return m_ThreadHandle; }
	unsigned int GetThreadID(){ return m_ThreadID; }
protected:
	virtual void Run() = 0;
private:
	HANDLE m_ThreadHandle;
	unsigned int m_ThreadID;
	bool m_FreeOnTerminate;
	bool m_Stopped; //标记停止
	static unsigned int __stdcall Wrapper(void *Param);
	TThread(const TThread&);
	TThread& operator=(const TThread&);
};

//RAII操作封装类
class CPPUTIL_API AutoCriticalSection
{
public:
	AutoCriticalSection(){};
	//cri要先调用InitializeCriticalSection初始化，不使用要了调用DeleteCriticalSection
	explicit AutoCriticalSection(CRITICAL_SECTION* cri){ f_lock = cri; EnterCriticalSection(f_lock); }
	~AutoCriticalSection(){ LeaveCriticalSection(f_lock); }
private:
	CRITICAL_SECTION *f_lock;
	AutoCriticalSection(const AutoCriticalSection&);
	AutoCriticalSection& operator=(const AutoCriticalSection&);
};

class CPPUTIL_API AutoSetEvent
{
private:
	HANDLE m_Event;
public:
	AutoSetEvent(HANDLE evt) :m_Event(evt){}
	~AutoSetEvent(){ SetEvent(m_Event); }
};

class CPPUTIL_API AutoCloseHandle
{
private:
	HANDLE m_Handle;
public:
	AutoCloseHandle(const HANDLE &h) :m_Handle(h){}
	~AutoCloseHandle(){ if (m_Handle) CloseHandle(m_Handle); }
};


enum TrayMessageType
{
	mtInfo,
	mtWarning,
	mtError
};

struct CPPUTIL_API TrayMessageInfo
{
	std::wstring msg;
	std::wstring title;
	TrayMessageType msg_type;
	DWORD timeout;
};

class CPPUTIL_API CTrayIconEx
{
public:
	CTrayIconEx(void);
	virtual ~CTrayIconEx(void);
public:
	static DWORD GetTrayIconDataSize();//适应不同的操作系统
	bool CreateTrayIcon(HWND _RecvHwnd, UINT _IconIDResource, LPCTSTR _ToolTipText = NULL, UINT _Message = NULL);
	bool DeleteTrayIcon();
	bool SetTooltipText(LPCTSTR _ToolTipText);
	LPCTSTR GetTooltipText() const;
	bool SetIcon(HICON _Hicon);
	bool SetIcon(LPCTSTR _IconFile);
	bool SetIcon(UINT _IDResource);
	HICON GetIcon() const;
	NOTIFYICONDATA* GetTrayIcon(){ return &m_trayData; }
	bool IsVisible();
	void SetVisible(bool bVisible);
	bool IsTwinkling();
	void SetTwinkling(bool bTwinkling);
	void TrayMessage(const std::wstring &msg, std::wstring title, TrayMessageType mt, DWORD timeout);
	void OnTimerTray();
private:
	bool m_bTwinkling;
	bool m_bVisible;
	HICON m_hIcon;
	NOTIFYICONDATA	m_trayData;
	std::vector<TrayMessageInfo*> m_TrayMsglist;
	RTL_CRITICAL_SECTION *m_pTrayMsglistLock;
public:
	static CTrayIconEx *pCTrayIconEx;
};