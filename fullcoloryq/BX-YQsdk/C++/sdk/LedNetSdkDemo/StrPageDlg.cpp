// StrPageDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "StrPageDlg.h"
#include "afxdialogex.h"
#include <sstream>

// CStrPageDlg 对话框

IMPLEMENT_DYNAMIC(CStrPageDlg, CDialogEx)

CStrPageDlg::CStrPageDlg(DynaStrPage* pPage,CWnd* pParent /*=NULL*/)
	: CDialogEx(CStrPageDlg::IDD, pParent)
{
	m_pPage=pPage;
}

CStrPageDlg::~CStrPageDlg()
{
}

void CStrPageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, m_btnTextColor);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_btnBgColor);
	DDX_Control(pDX, IDC_MFCFONTCOMBO1, m_cmbFont);
}


BEGIN_MESSAGE_MAP(CStrPageDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStrPageDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CStrPageDlg 消息处理程序

wstring short2hexw(unsigned short v)
{
	wstringstream ss;
	ss.width(4);
	ss.fill(L'0');
	ss <<hex  << v;
	return L"0x"+ss.str();
}
void CStrPageDlg::OnBnClickedOk()
{
	CString str;
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	m_pPage->m_LineSpace=_tstoi(str);
	GetDlgItem(IDC_EDIT15)->GetWindowText(str);
	m_pPage->m_fontsize=_tstoi(str);

	GetDlgItem(IDC_MFCFONTCOMBO1)->GetWindowText(m_pPage->m_font);

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


BOOL CStrPageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString str;
	str.Format(_T("%d"),m_pPage->m_LineSpace);
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
	str.Format(_T("%d"),m_pPage->m_fontsize);
	GetDlgItem(IDC_EDIT15)->SetWindowText(str);
	GetDlgItem(IDC_EDIT1)->SetWindowText(m_pPage->szTxt);
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
