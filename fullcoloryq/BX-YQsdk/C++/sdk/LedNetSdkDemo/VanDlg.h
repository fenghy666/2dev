#pragma once


// CVanDlg 对话框

class CVanDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CVanDlg)

public:
	CVanDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CVanDlg();

// 对话框数据
	enum { IDD = IDD_VANDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton22();
};
