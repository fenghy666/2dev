#pragma once


// CTextAreaDlg �Ի���

class CTextAreaDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTextAreaDlg)

public:
	CTextAreaDlg(PicArea* p,CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTextAreaDlg();

// �Ի�������
	enum { IDD = IDD_TEXTAREADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
