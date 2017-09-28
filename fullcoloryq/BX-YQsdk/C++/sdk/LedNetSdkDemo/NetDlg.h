#pragma once


// CNetDlg �Ի���

class CNetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CNetDlg)

public:
	CNetDlg(card_unit* pUnit,CWnd* pParent = NULL);   // ��׼���캯��
	CNetDlg(server_card* pCard,CWnd* pParent = NULL);
	virtual ~CNetDlg();

// �Ի�������
	enum { IDD = IDD_NETDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
