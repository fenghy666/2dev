#pragma once
#include "afxcolorbutton.h"
#include "afxfontcombobox.h"


// CStrRefPageDlg 对话框

class CStrRefPageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CStrRefPageDlg)

public:
	CStrRefPageDlg(DynaStrRefPage* pPage,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStrRefPageDlg();

// 对话框数据
	enum { IDD = IDD_STRREFPAGEDLG };

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
	
	virtual BOOL OnInitDialog();
	CMFCFontComboBox m_cmbFont;
private:
	DynaStrRefPage* m_pPage;
};
