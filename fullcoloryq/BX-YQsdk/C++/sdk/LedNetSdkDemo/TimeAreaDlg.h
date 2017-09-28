#pragma once
#include "afxfontcombobox.h"
#include "afxwin.h"
#include "afxcolorbutton.h"


// CTimeAreaDlg 对话框

class CTimeAreaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTimeAreaDlg)

public:
	CTimeAreaDlg(TimeArea* p,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTimeAreaDlg();

// 对话框数据
	enum { IDD = IDD_TIMEAREADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	TimeArea* m_pArea;
public:
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnBnClickedCheck13();
	CMFCFontComboBox m_cmbFont;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	int m_bMultiLine;
public:
	CSliderCtrl m_ctrlSlider;
	CComboBox m_cmbFlag;
	CComboBox m_cmbAlign;
	CMFCColorButton m_btnText;
	CMFCColorButton m_btnTime;
	CMFCColorButton m_btnWeek;
	CMFCColorButton m_btnDate;
};
