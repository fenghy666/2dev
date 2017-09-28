// StrPageDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "StrRefPageDlg.h"
#include "afxdialogex.h"
#include <sstream>

// CStrRefPageDlg 对话框

IMPLEMENT_DYNAMIC(CStrRefPageDlg, CDialogEx)

CStrRefPageDlg::CStrRefPageDlg(DynaStrRefPage* pPage,CWnd* pParent /*=NULL*/)
	: CDialogEx(CStrRefPageDlg::IDD, pParent)
{
	m_pPage=pPage;
}

CStrRefPageDlg::~CStrRefPageDlg()
{
}

void CStrRefPageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, m_btnTextColor);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_btnBgColor);
	DDX_Control(pDX, IDC_MFCFONTCOMBO1, m_cmbFont);
}


BEGIN_MESSAGE_MAP(CStrRefPageDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStrRefPageDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CStrRefPageDlg 消息处理程序

extern wstring short2hexw(unsigned short v);

void CStrRefPageDlg::OnBnClickedOk()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	m_pPage->m_LineSpace=_tstoi(str);
	GetDlgItem(IDC_EDIT15)->GetWindowText(str);
	m_pPage->m_fontsize=_tstoi(str);

	GetDlgItem(IDC_MFCFONTCOMBO1)->GetWindowText(m_pPage->m_font);
	GetDlgItem(IDC_EDIT3)->GetWindowText(m_pPage->user,sizeof(m_pPage->user));
	GetDlgItem(IDC_EDIT64)->GetWindowText(m_pPage->pwd,sizeof(m_pPage->pwd));

	m_pPage->m_bold=((CButton*)GetDlgItem(IDC_CHECK2))->GetCheck();
	m_pPage->m_italic=((CButton*)GetDlgItem(IDC_CHECK3))->GetCheck();
	m_pPage->m_underline=((CButton*)GetDlgItem(IDC_CHECK4))->GetCheck();
	m_pPage->m_strike=((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck();
	m_pPage->m_bAntialiasing=((CButton*)GetDlgItem(IDC_CHECK5))->GetCheck();

	m_pPage->m_BgColor=m_btnBgColor.GetColor();
	m_pPage->txtcolor=m_btnTextColor.GetColor();
	GetDlgItem(IDC_EDIT1)->GetWindowText(m_pPage->szTxt);
	CDialogEx::OnOK();
}


BOOL CStrRefPageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString str;
	str.Format(_T("%d"),m_pPage->m_LineSpace);
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
	str.Format(_T("%d"),m_pPage->m_fontsize);
	GetDlgItem(IDC_EDIT15)->SetWindowText(str);
	GetDlgItem(IDC_EDIT1)->SetWindowText(m_pPage->szTxt);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_pPage->user);
	GetDlgItem(IDC_EDIT64)->SetWindowText(m_pPage->pwd);
	m_cmbFont.SelectFont(m_pPage->m_font);
	m_btnBgColor.SetColor(m_pPage->m_BgColor);
	m_btnTextColor.SetColor(m_pPage->txtcolor);
	((CButton*)GetDlgItem(IDC_CHECK2))->SetCheck(m_pPage->m_bold);
	((CButton*)GetDlgItem(IDC_CHECK3))->SetCheck(m_pPage->m_italic);
	((CButton*)GetDlgItem(IDC_CHECK4))->SetCheck(m_pPage->m_underline);
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(m_pPage->m_strike);
	((CButton*)GetDlgItem(IDC_CHECK5))->SetCheck(m_pPage->m_bAntialiasing);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
