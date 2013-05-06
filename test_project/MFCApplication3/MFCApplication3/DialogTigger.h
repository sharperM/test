#pragma once


// CDialogTigger 对话框

class CDialogTigger : public CDialog
{
	DECLARE_DYNAMIC(CDialogTigger)

public:
	CDialogTigger(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDialogTigger();

// 对话框数据
	enum { IDD = IDD_tigger };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};
