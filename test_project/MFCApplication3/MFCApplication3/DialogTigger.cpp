// DialogTigger.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCApplication3.h"
#include "DialogTigger.h"
#include "afxdialogex.h"


// CDialogTigger �Ի���

IMPLEMENT_DYNAMIC(CDialogTigger, CDialog)

CDialogTigger::CDialogTigger(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogTigger::IDD, pParent)
{

}

CDialogTigger::~CDialogTigger()
{
}

void CDialogTigger::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogTigger, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDialogTigger ��Ϣ�������


void CDialogTigger::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialog::OnPaint()
	PAINTSTRUCT ps = { 0 };
	HDC hdc = ::BeginPaint( this->m_hWnd, &ps );
	MoveToEx(hdc, 1, 1, NULL);
	LineTo(hdc, 300,300);
	::EndPaint( this->m_hWnd, &ps );

}
