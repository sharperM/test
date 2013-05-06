#pragma once



// InternetThread

class InternetThread : public CWinThread
{
	DECLARE_DYNCREATE(InternetThread)

public:
	InternetThread();           // 动态创建所使用的受保护的构造函数
	virtual ~InternetThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual int Run();

public:
//	protobuf::field* m_pProtobufFields;
	DWORD m_nProtobufFields;
	CString m_pszAddress;
	CString m_pszPath;
};


