#pragma once


// CPicRefDlg 对话框

class CPicRefDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPicRefDlg)

public:
	CPicRefDlg(DynaRefPicPage* pPage,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPicRefDlg();

// 对话框数据
	enum { IDD = IDD_PICREFDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
private:
	DynaRefPicPage* m_pPage;
};
