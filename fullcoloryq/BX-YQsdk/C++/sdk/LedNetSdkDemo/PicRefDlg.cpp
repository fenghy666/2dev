// PicRefDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "PicRefDlg.h"
#include "afxdialogex.h"


// CPicRefDlg �Ի���

IMPLEMENT_DYNAMIC(CPicRefDlg, CDialogEx)

CPicRefDlg::CPicRefDlg(DynaRefPicPage* pPage,CWnd* pParent /*=NULL*/)
	: CDialogEx(CPicRefDlg::IDD, pParent)
{
	m_pPage=pPage;
}

CPicRefDlg::~CPicRefDlg()
{
}

void CPicRefDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPicRefDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CPicRefDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CPicRefDlg ��Ϣ�������


void CPicRefDlg::OnBnClickedOk()
{
	GetDlgItem(IDC_EDIT1)->GetWindowText(m_pPage->user,sizeof(m_pPage->user));
	GetDlgItem(IDC_EDIT2)->GetWindowText(m_pPage->pwd,sizeof(m_pPage->pwd));
	GetDlgItem(IDC_EDIT3)->GetWindowText(m_pPage->szFile,sizeof(m_pPage->szFile));
	CDialogEx::OnOK();
}


BOOL CPicRefDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	GetDlgItem(IDC_EDIT1)->SetWindowText(m_pPage->user);
	GetDlgItem(IDC_EDIT2)->SetWindowText(m_pPage->pwd);
	GetDlgItem(IDC_EDIT3)->SetWindowText(m_pPage->szFile);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
