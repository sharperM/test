#pragma once


// CDialogTigger �Ի���

class CDialogTigger : public CDialog
{
	DECLARE_DYNAMIC(CDialogTigger)

public:
	CDialogTigger(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDialogTigger();

// �Ի�������
	enum { IDD = IDD_tigger };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
