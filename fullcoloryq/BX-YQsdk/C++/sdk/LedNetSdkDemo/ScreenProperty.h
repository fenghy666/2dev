#pragma once


// CScreenProperty �Ի���

class CScreenProperty : public CDialogEx
{
	DECLARE_DYNAMIC(CScreenProperty)

public:
	CScreenProperty(char *ip,CWnd* pParent = NULL);   // ��׼���캯��
	CScreenProperty(unsigned char* pid,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CScreenProperty();

// �Ի�������
	enum { IDD = IDD_SCREENPROPERTY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSetScreeninfo();
public:
	CComboBox m_cmbCardType;
	virtual BOOL OnInitDialog();
private:
	int card_mode;
	char card_ip[16];
	unsigned char card_pid[16];
};
