#pragma once


// CBrightDlg �Ի���

class CBrightDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBrightDlg)

public:
	CBrightDlg(char *ip,CWnd* pParent = NULL);   // ��׼���캯��
	CBrightDlg(unsigned char* pid,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBrightDlg();

// �Ի�������
	enum { IDD = IDD_BRIGHTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	int m_Mode;
	afx_msg void OnBnClickedAdjustBright();
	virtual BOOL OnInitDialog();
private:
	int card_mode;
	char card_ip[16];
	unsigned char card_pid[16];
};
