#pragma once
#include "afxcolorbutton.h"
#include "afxfontcombobox.h"


// CStrPageDlg 对话框

class CStrPageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStrPageDlg)

public:
	CStrPageDlg(DynaStrPage* pPage,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStrPageDlg();

// 对话框数据
	enum { IDD = IDD_STRPAGEDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	
	CMFCColorButton m_btnTextColor;
	CMFCColorButton m_btnBgColor;
public:
	UINT m_BgColor;
	int m_Linespace;
	wstring m_Content;
	virtual BOOL OnInitDialog();
	CMFCFontComboBox m_cmbFont;
private:
	DynaStrPage* m_pPage;
};
