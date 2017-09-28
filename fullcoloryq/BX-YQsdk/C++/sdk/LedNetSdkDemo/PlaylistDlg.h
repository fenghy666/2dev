#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CPlaylistDlg 对话框

class CPlaylistDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CPlaylistDlg)

public:
	CPlaylistDlg(char *ip,CWnd* pParent = NULL);   // 标准构造函数
	CPlaylistDlg(unsigned char* pid,CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPlaylistDlg();

// 对话框数据
	enum { IDD = IDD_PLAYLISTDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSend();
public:
	CComboBox m_WorkDir;
	CProgressCtrl m_TotalProgress;
	CProgressCtrl m_CurProgress;

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBrowse();
public:
	afx_msg void OnBnClickedButton31();
private:
	int card_mode;
	char card_ip[16];
	unsigned char card_pid[16];
	vector<Program*>m_vecProgram;
	DWORD m_hSend;
public:
	afx_msg void OnBnClickedButton3();
	CListBox m_ctrlProgramList;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton1();
	CProgressCtrl m_DownProgress;
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButton2();
};
