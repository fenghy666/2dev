#pragma once


// CFirmwareDlg �Ի���

class CFirmwareDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CFirmwareDlg)

public:
	CFirmwareDlg(char *ip,CWnd* pParent = NULL);   // ��׼���캯��
	CFirmwareDlg(unsigned char* pid,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CFirmwareDlg();

// �Ի�������
	enum { IDD = IDD_FIRMWAREDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton3();
private:
	int card_mode;
	char card_ip[16];
	unsigned char card_pid[16];

};
