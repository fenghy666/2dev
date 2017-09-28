#pragma once


// CTextAreaDlg 对话框

class CTextAreaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTextAreaDlg)

public:
	CTextAreaDlg(PicArea* p,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTextAreaDlg();

// 对话框数据
	enum { IDD = IDD_TEXTAREADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	PicArea* m_pArea;
	vector<PicUnit> m_vecUnit;
public:
	CSliderCtrl m_ctrlSlider;
	CComboBox m_cmbDisplayEffect;
	CListBox m_ctrlUnitList;
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedUnitRemove();
	afx_msg void OnLbnSelchangeListUnit();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();

	afx_msg void OnCbnKillfocusCombo1();
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnKillfocusEdit31();
};
