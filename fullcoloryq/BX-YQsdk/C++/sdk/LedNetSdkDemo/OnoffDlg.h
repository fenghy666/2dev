#pragma once


// COnoffDlg 对话框

class COnoffDlg : public CDialogEx
{
	DECLARE_DYNAMIC(COnoffDlg)

public:
	COnoffDlg(char *ip,CWnd* pParent = NULL);   // 标准构造函数
	COnoffDlg(unsigned char* pid,CWnd* pParent = NULL); 
	virtual ~COnoffDlg();

// 对话框数据
	enum { IDD = IDD_ONOFFDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	int m_Onoff;
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
private:
	int card_mode;
	char card_ip[16];
	unsigned char card_pid[16];
};
