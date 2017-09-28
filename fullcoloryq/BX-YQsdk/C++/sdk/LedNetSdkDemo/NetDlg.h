#pragma once


// CNetDlg 对话框

class CNetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNetDlg)

public:
	CNetDlg(card_unit* pUnit,CWnd* pParent = NULL);   // 标准构造函数
	CNetDlg(server_card* pCard,CWnd* pParent = NULL);
	virtual ~CNetDlg();

// 对话框数据
	enum { IDD = IDD_NETDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_IpMode;
	int m_ClientMode;
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();

	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio1();
private:
	int card_mode;
	card_unit* m_pUnit;
	server_card* m_pServerCard;
public:
	afx_msg void OnBnClickedRadio4();
};
