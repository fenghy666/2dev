#pragma once


// CPicRefDlg �Ի���

class CPicRefDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPicRefDlg)

public:
	CPicRefDlg(DynaRefPicPage* pPage,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPicRefDlg();

// �Ի�������
	enum { IDD = IDD_PICREFDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
private:
	DynaRefPicPage* m_pPage;
};
