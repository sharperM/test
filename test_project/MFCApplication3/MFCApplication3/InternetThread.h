#pragma once



// InternetThread

class InternetThread : public CWinThread
{
	DECLARE_DYNCREATE(InternetThread)

public:
	InternetThread();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
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


