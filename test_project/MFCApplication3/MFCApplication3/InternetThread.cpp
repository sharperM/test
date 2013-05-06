// InternetThread.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "InternetThread.h"


// InternetThread

IMPLEMENT_DYNCREATE(InternetThread, CWinThread)

InternetThread::InternetThread()
: m_pszAddress(_T(""))
, m_pszPath(_T(""))
{
}

InternetThread::~InternetThread()
{
}

BOOL InternetThread::InitInstance()
{
	// TODO: 在此执行任意逐线程初始化
	return TRUE;
}

int InternetThread::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(InternetThread, CWinThread)
END_MESSAGE_MAP()


// InternetThread 消息处理程序


int InternetThread::Run()
{

	// TODO: 在此添加专用代码和/或调用基类
// 	   HINTERNET hOpen = NULL;
//        HINTERNET hConnect = NULL;
//        HINTERNET hReq = NULL;
// 
//        char* pszURL = "https://login.live.com/login.srf?vv=1450&mkt=ZH-CN&lc=2052&bk=1366271051" ;
// 
//        INTERNET_PORT dwPort     = NULL;
//        /*flags required to connect and request for secure socket layer*/
//        DWORD dwFlags = INTERNET_FLAG_RELOAD |
//              INTERNET_FLAG_NO_CACHE_WRITE |
//              INTERNET_FLAG_KEEP_CONNECTION;      
//        DWORD dwError      = NULL;
//        DWORD dwSize       = NULL;
//        DWORD dwCode       = NULL;
//        CHAR szAccept[] = ( "*/*");
//        LPSTR AcceptTypes[2]    = {0};
//        AcceptTypes[0]     = szAccept ;      
//        CString strURL     = L"" ;
//        CString strServerName   = L"";
//        CString strObject  = L"" ;
//        DWORD dwServiceType     = NULL ;
// 
//        // to read response we required some bytes.
//        TCHAR szBuffer[4096];
//        DWORD dwNumberOfBytesToRead;
//        DWORD dwNumberOfBytesRead;
//        dwNumberOfBytesToRead= sizeof (szBuffer );
// 
//        //Assign the URL to string variable
//        strURL = pszURL;
// 
//        AfxParseURL((LPCTSTR )strURL ,//将网址转换
//              dwServiceType,
//              strServerName,     //"logiin.live.com"
//              strObject,           //"/login.srf?vv=1450&mkt=ZH-CN&lc=2052&bk=1366271051"
//              dwPort);          //443
// 
//        hOpen = :: InternetOpen(NULL ,  // app name
//              INTERNET_OPEN_TYPE_PRECONFIG, // access type
//              NULL,  // proxy server
//              INTERNET_INVALID_PORT_NUMBER, // proxy port
//             0);
//        /*Store the return Handel in variable type HINTERNET hOpen.*/
// 
//        hConnect = :: InternetConnect (hOpen ,
//              strServerName,
//              dwPort,
//              L"" ,
//              L"" ,
//              INTERNET_SERVICE_HTTP,
//             0,
//             0);
// 
//        //prepare the flag for secure socket layer
//        dwFlags |= INTERNET_FLAG_SECURE |
//              INTERNET_FLAG_IGNORE_CERT_CN_INVALID |
//              INTERNET_FLAG_IGNORE_CERT_DATE_INVALID;
// 
//        //Open internet request
//        hReq = :: HttpOpenRequest (hConnect ,
//              L"POST" ,
//              strObject,
//              HTTP_VERSION,
//              L"" ,
//             ( LPCTSTR*) AcceptTypes,
//              dwFlags,
//             0 );
//        //Send the http request
//       :: HttpSendRequest (hReq ,
//              L"" , //header information required to send
//             0, //length of header if any
//              L"" , //body information required to send
//             0 //length of body information
//             );
// 
//        //Query the https port regarding status
//       :: HttpQueryInfo (hReq ,
//              HTTP_QUERY_STATUS_CODE |
//              HTTP_QUERY_FLAG_NUMBER,
//             & dwCode,
//             & dwSize,
//              NULL);
// 
//       :: InternetReadFile (hReq ,
//              szBuffer,
//              dwNumberOfBytesToRead,
//             & dwNumberOfBytesRead
//             );

	//通过 http GET 协议来获取并保存文件
	CInternetSession session;
	session.SetOption(INTERNET_OPTION_CONNECT_TIMEOUT, 1000 * 20);
	session.SetOption(INTERNET_OPTION_CONNECT_BACKOFF, 1000);
	session.SetOption(INTERNET_OPTION_CONNECT_RETRIES, 1);
	session.SetOption(INTERNET_OPTION_SECURITY_FLAGS,
		SECURITY_FLAG_IGNORE_REVOCATION|
		SECURITY_FLAG_IGNORE_CERT_CN_INVALID|
		SECURITY_FLAG_IGNORE_UNKNOWN_CA|
		SECURITY_FLAG_IGNORE_REVOCATION);

	// 	CHttpConnection* pConnection = session.GetHttpConnection(TEXT("www.evangelion.co.jp"),(INTERNET_PORT)443,NULL,NULL);
	// 	CHttpFile* pFile = pConnection->OpenRequest( CHttpConnection::HTTP_VERB_GET,
	// 		TEXT("/final.html"),NULL, 1,NULL,NULL, INTERNET_FLAG_SECURE);	

// 	CHttpConnection* pConnection = session.GetHttpConnection(TEXT("www.flickr.com"),(INTERNET_PORT)80,NULL,NULL);
// 	CHttpFile* pFile = pConnection->OpenRequest( CHttpConnection::HTTP_VERB_GET,
// 		TEXT("/search/?q=china"),NULL, 1,NULL,NULL);

	DWORD dwServiceType;
	CString strServerName;
	CString strObject;
	INTERNET_PORT nPort;
	CHttpFile* pFile = NULL;
//	InternetSetOption(NULL,SECURITY_FLAG_IGNORE_UNKNOWN_CA|SECURITY_FLAG_IGNORE_REVOCATION, NULL, 0);
	AfxParseURL(m_pszAddress,dwServiceType, strServerName, strObject,nPort);

	CHttpConnection* pConnection = session.GetHttpConnection(strServerName,INTERNET_FLAG_SECURE,nPort,NULL,NULL);
	if ( nPort == 80 )
	{
		pFile = pConnection->OpenRequest( CHttpConnection::HTTP_VERB_GET,
		strObject,NULL, 1, NULL, NULL);
	}
	if ( nPort == 443 )
	{
		pFile = pConnection->OpenRequest( CHttpConnection::HTTP_VERB_GET,
			strObject,NULL, 1, NULL, NULL, INTERNET_FLAG_EXISTING_CONNECT |
			INTERNET_FLAG_RELOAD |
			INTERNET_FLAG_NO_CACHE_WRITE |
			INTERNET_FLAG_SECURE |
			INTERNET_FLAG_IGNORE_CERT_DATE_INVALID |
			INTERNET_FLAG_IGNORE_CERT_CN_INVALID
// 			SECURITY_FLAG_IGNORE_UNKNOWN_CA|
// 			SECURITY_FLAG_IGNORE_REVOCATION
			);

	}
	
	// 	CString szHeaders = L"Accept: audio/x-aiff, audio/basic, audio/midi,\
	// 						 audio/mpeg, audio/wav, image/jpeg, image/gif, image/jpg, image/png,\
	// 						 image/mng, image/bmp, text/plain, text/html, text/htm\r\n";

	// 	pFile->AddRequestHeaders(szHeaders);
	try
	{
		pFile->SendRequest();
	}
	catch (CException* e)
	{
// 		AfxMessageBox(L"send Request error!");
		e->ReportError();
//		return false;
	}
	

	DWORD dwRet;
	pFile->QueryInfoStatusCode(dwRet);

	if(dwRet != HTTP_STATUS_OK)
	{
		CString errText;
		errText.Format(L"POST出错，错误码：%d", dwRet);
		AfxMessageBox(errText);
	}
	else
	{
		int len = pFile->GetLength();
		char buf[2000];
		int numread;
		CString filepath;
		CString strFile = L"response.txt";
//		filepath.Format(L".\\%s", strFile);

		filepath.Format(L"%s", m_pszPath);

		CFile myfile( filepath,
			CFile::modeCreate|CFile::modeWrite|CFile::typeBinary);
		while ((numread = pFile->Read(buf,sizeof(buf)-1)) > 0)
		{
			buf[numread] = '\0';
	/*		strFile += buf;*/
			myfile.Write(buf, numread);
		}
		myfile.Close();
		AfxMessageBox(strFile);
	}

	session.Close();
	pFile->Close(); 
	delete pFile;




	return CWinThread::Run();
}
