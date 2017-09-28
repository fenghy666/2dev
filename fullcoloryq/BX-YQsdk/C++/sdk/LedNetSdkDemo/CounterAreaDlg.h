#pragma once
#include "afxdtctl.h"
#include "afxcolorbutton.h"


// CCounterAreaDlg 对话框

class CCounterAreaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCounterAreaDlg)

public:
	CCounterAreaDlg(CounterArea* p,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCounterAreaDlg();

// 对话框数据
	enum { IDD = IDD_COUNTERAREADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CounterArea* m_pArea;
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CDateTimeCtrl m_ctrlDate;
	CDateTimeCtrl m_ctrlTime;
	CMFCColorButton m_btnCounter;
	CSliderCtrl m_ctrlSlider;

	CComboBox m_cmbAlign;
	CMFCColorButton m_btnText;
	int m_bMultiLine;
	CMFCFontComboBox m_cmbFont;
	afx_msg void OnBnClickedCheck1();
};
