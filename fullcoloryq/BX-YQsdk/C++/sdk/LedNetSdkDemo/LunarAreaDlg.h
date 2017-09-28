#pragma once


// CLunarAreaDlg 对话框

class CLunarAreaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CLunarAreaDlg)

public:
	CLunarAreaDlg(LunarArea* p,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLunarAreaDlg();

// 对话框数据
	enum { IDD = IDD_LUNARAREADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	LunarArea* m_pArea;
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CMFCFontComboBox m_cmbFont;
	int m_bMultiLine;
public:
	CSliderCtrl m_ctrlSlider;
	CComboBox m_cmbAlign;
	CMFCColorButton m_btnText;
	CMFCColorButton m_btnTime;
	CMFCColorButton m_btnYear;
	CMFCColorButton m_btnDate;
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnBnClickedCheck13();
	afx_msg void OnBnClickedCheck1();
};
