
// MFCApplication3Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxeditbrowsectrl.h"
#include "dialogtigger.h"


// CMFCApplication3Dlg �Ի���
class CMFCApplication3Dlg : public CDialog
{
// ����
public:
	CMFCApplication3Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedStart();
	CString m_pszAddress;
	CString m_pszPath;
	CString m_pszText;
	CMFCEditBrowseCtrl m_Editpath;
	CDialogTigger m_dlg;
};
