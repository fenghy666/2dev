#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CImageAreaDlg 对话框

class CImageAreaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CImageAreaDlg)

public:
	CImageAreaDlg(PicArea* a,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CImageAreaDlg();

// 对话框数据
	enum { IDD = IDD_IMAGEAREADLG };

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
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnLbnSelchangeListUnit();
	afx_msg void OnBnClickedUnitAdd();
	afx_msg void OnBnClickedUnitRemove();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnCbnKillfocusCombo1();
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnKillfocusEdit31();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
};
