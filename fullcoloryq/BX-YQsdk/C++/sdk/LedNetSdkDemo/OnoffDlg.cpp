// OnoffDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "OnoffDlg.h"
#include "afxdialogex.h"


// COnoffDlg 对话框

IMPLEMENT_DYNAMIC(COnoffDlg, CDialogEx)

COnoffDlg::COnoffDlg(char *ip,CWnd* pParent /*=NULL*/)
	: CDialogEx(COnoffDlg::IDD, pParent)
	, m_Onoff(0)
{
	card_mode=0;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
}
COnoffDlg::COnoffDlg(unsigned char* pid,CWnd* pParent /*= NULL*/)
	: CDialogEx(COnoffDlg::IDD, pParent)
	, m_Onoff(0)
{
	card_mode=1;
	memcpy(card_pid,pid,sizeof(card_pid));
}
COnoffDlg::~COnoffDlg()
{
}

void COnoffDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX,IDC_RADIO1,m_Onoff);
}


BEGIN_MESSAGE_MAP(COnoffDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &COnoffDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &COnoffDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &COnoffDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_CHECK2, &COnoffDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &COnoffDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &COnoffDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &COnoffDlg::OnBnClickedCheck5)
END_MESSAGE_MAP()


// COnoffDlg 消息处理程序


BOOL COnoffDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetDlgItem(IDC_RADIO3)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO4)->EnableWindow(FALSE);
	BYTE onoff=0;
	int err=0;
	if (card_mode==0)
	{
		err=Net_GetOnoff(card_ip,&onoff);
	} 
	else
	{
		err=Server_GetOnoff(card_pid,&onoff);
	}

	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
	}
	else
	{
		m_Onoff=onoff;
	}
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void COnoffDlg::OnBnClickedButton2()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK2);
	char tm1start[20]={0};
	char tm1end[20]={0};
	if (btn->GetCheck())
	{
		CString str;
		GetDlgItem(IDC_DATETIMEPICKER1)->GetWindowText(str);
		CString2Char(str,tm1start);
		GetDlgItem(IDC_DATETIMEPICKER2)->GetWindowText(str);
		CString2Char(str,tm1end);
	}
		char tm2start[20]={0};
	char tm2end[20]={0};
	btn=(CButton*)GetDlgItem(IDC_CHECK3);
	if (btn->GetCheck())
	{
		CString str;
		GetDlgItem(IDC_DATETIMEPICKER3)->GetWindowText(str);
		CString2Char(str,tm2start);
		GetDlgItem(IDC_DATETIMEPICKER4)->GetWindowText(str);
		CString2Char(str,tm2end);
	}
		char tm3start[20]={0};
	char tm3end[20]={0};
	btn=(CButton*)GetDlgItem(IDC_CHECK4);
	if (btn->GetCheck())
	{
		CString str;
		GetDlgItem(IDC_DATETIMEPICKER5)->GetWindowText(str);
		CString2Char(str,tm3start);
		GetDlgItem(IDC_DATETIMEPICKER6)->GetWindowText(str);
		CString2Char(str,tm3end);
	}
		char tm4start[20]={0};
	char tm4end[20]={0};
	btn=(CButton*)GetDlgItem(IDC_CHECK5);
	if (btn->GetCheck())
	{
		CString str;
		GetDlgItem(IDC_DATETIMEPICKER7)->GetWindowText(str);
		CString2Char(str,tm4start);
		GetDlgItem(IDC_DATETIMEPICKER8)->GetWindowText(str);
		CString2Char(str,tm4end);
	}
	if (card_mode==0)
	{
		int err=Net_SwitchOnTime(card_ip,tm1start,tm1end,tm2start,tm2end,tm3start,tm3end,tm4start,tm4end);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	} 
	else
	{
		int err=Server_SwitchOnTime(card_pid,tm1start,tm1end,tm2start,tm2end,tm3start,tm3end,tm4start,tm4end,theApp.ftp_server_ip,theApp.ftp_server_port,theApp.ftp_server_user,theApp.ftp_server_pwd);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}

}


void COnoffDlg::OnBnClickedRadio1()
{
	CButton *btn=(CButton*)GetDlgItem(IDC_RADIO3);
	btn->SetCheck(0);
	btn=(CButton*)GetDlgItem(IDC_RADIO4);
	btn->SetCheck(0);
	if (card_mode==0)
	{
		int err=Net_CloseScreen(card_ip);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	} 
	else
	{
		int err=Server_CloseScreen(card_pid);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}

}


void COnoffDlg::OnBnClickedRadio2()
{
	CButton *btn=(CButton*)GetDlgItem(IDC_RADIO3);
	btn->SetCheck(0);
	btn=(CButton*)GetDlgItem(IDC_RADIO4);
	btn->SetCheck(0);
	if (card_mode==0)
	{
		int err=Net_OpenScreen(card_ip);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	} 
	else
	{
		int err=Server_OpenScreen(card_pid);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}

}


void COnoffDlg::OnBnClickedCheck2()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK2);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_DATETIMEPICKER1)->EnableWindow(TRUE);
		GetDlgItem(IDC_DATETIMEPICKER2)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_DATETIMEPICKER1)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATETIMEPICKER2)->EnableWindow(FALSE);
	}
}


void COnoffDlg::OnBnClickedCheck3()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK3);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_DATETIMEPICKER3)->EnableWindow(TRUE);
		GetDlgItem(IDC_DATETIMEPICKER4)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_DATETIMEPICKER3)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATETIMEPICKER4)->EnableWindow(FALSE);
	}
}


void COnoffDlg::OnBnClickedCheck4()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK4);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_DATETIMEPICKER5)->EnableWindow(TRUE);
		GetDlgItem(IDC_DATETIMEPICKER6)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_DATETIMEPICKER5)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATETIMEPICKER6)->EnableWindow(FALSE);
	}
}


void COnoffDlg::OnBnClickedCheck5()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK5);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_DATETIMEPICKER7)->EnableWindow(TRUE);
		GetDlgItem(IDC_DATETIMEPICKER8)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_DATETIMEPICKER7)->EnableWindow(FALSE);
		GetDlgItem(IDC_DATETIMEPICKER8)->EnableWindow(FALSE);
	}
}
