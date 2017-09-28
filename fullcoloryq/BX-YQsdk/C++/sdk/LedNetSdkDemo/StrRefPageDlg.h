#pragma once
#include "afxcolorbutton.h"
#include "afxfontcombobox.h"


// CStrRefPageDlg �Ի���

class CStrRefPageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStrRefPageDlg)

public:
	CStrRefPageDlg(DynaStrRefPage* pPage,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CStrRefPageDlg();

// �Ի�������
	enum { IDD = IDD_STRREFPAGEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	
	CMFCColorButton m_btnTextColor;
	CMFCColorButton m_btnBgColor;
public:
	UINT m_BgColor;
	int m_Linespace;
	
	virtual BOOL OnInitDialog();
	CMFCFontComboBox m_cmbFont;
private:
	DynaStrRefPage* m_pPage;
};
