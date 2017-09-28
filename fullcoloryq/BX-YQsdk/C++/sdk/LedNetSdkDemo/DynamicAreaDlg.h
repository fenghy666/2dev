#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDynamicAreaDlg 对话框

class CDynamicAreaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CDynamicAreaDlg)

public:
	CDynamicAreaDlg(char* ip,CWnd* pParent = NULL);   // 标准构造函数
	CDynamicAreaDlg(unsigned char* pid,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDynamicAreaDlg();

// 对话框数据
	enum { IDD = IDD_DYNAMICAREADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
private:
	int card_mode;
	char card_ip[16];
	unsigned char card_pid[16];
public:
	afx_msg void OnBnClickedCheck1();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnCbnKillfocusCombo8();
	afx_msg void OnEnKillfocusEdit31();
	afx_msg void OnEnKillfocusEdit32();
	afx_msg void OnBnClickedButton5();	
	CComboBox m_cmbRunMode;
	CListBox m_PageList;
	CComboBox m_cmbDisplayEffect;
	CComboBox m_cmbAreaId;
	CSliderCtrl m_ctrlSlider;
	int m_PlayRelation;
	int m_RunTime;
	int m_PageType;
	short m_X;
	short m_Y;
	short m_W;
	short m_H;
	int m_RelProgram;
	vector<DynaPicPage> m_vecPicPage;
	vector<DynaStrPage*> m_vecStrPage;
	vector<DynaRefPicPage> m_vecPicRefPage;
	vector<DynaStrRefPage*> m_vecStrRefPage;
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnBnClickedRadio8();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
};
