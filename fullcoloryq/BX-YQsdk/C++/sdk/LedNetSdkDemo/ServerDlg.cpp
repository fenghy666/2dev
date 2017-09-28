// ServerDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "ServerDlg.h"
#include "afxdialogex.h"

#include "ScreenProperty.h"
#include "NetDlg.h"
#include "VolumeDlg.h"
#include "BrightDlg.h"
#include "OnoffDlg.h"
#include "FirmwareDlg.h"
#include "PlaylistDlg.h"
#include "DynamicAreaDlg.h"
// CServerDlg 对话框

IMPLEMENT_DYNAMIC(CServerDlg, CDialogEx)

CServerDlg::CServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CServerDlg::IDD, pParent)
	,m_nServerPort(6005)
	,m_nFtpServerPort(8888)
{

}

CServerDlg::~CServerDlg()
{
}

void CServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO9, m_cmbCardList);
	DDX_Text(pDX,IDC_EDIT3,m_nServerPort);
	DDX_Text(pDX,IDC_EDIT5,m_nFtpServerPort);
}


BEGIN_MESSAGE_MAP(CServerDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON29, &CServerDlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON30, &CServerDlg::OnBnClickedButton30)
	ON_BN_CLICKED(IDC_BUTTON33, &CServerDlg::OnBnClickedButton33)
	ON_BN_CLICKED(IDC_BUTTON1, &CServerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CServerDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &CServerDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON7, &CServerDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON11, &CServerDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON32, &CServerDlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON10, &CServerDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON2, &CServerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON15, &CServerDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON9, &CServerDlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// CServerDlg 消息处理程序


void CServerDlg::OnBnClickedButton29()
{
	CString str;
	GetDlgItem(IDC_EDIT3)->GetWindowText(str);
	int port=_tstoi(str);
	int err=Server_Start(port);
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
	}
	else
	{
		GetDlgItem(IDC_BUTTON30)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON29)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON33)->EnableWindow(TRUE);
		theApp.m_bServerRun=true;
	}
}


void CServerDlg::OnBnClickedButton30()
{
	Server_Close();
	GetDlgItem(IDC_BUTTON30)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON29)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON33)->EnableWindow(FALSE);
	m_cmbCardList.ResetContent();

	GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON32)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	theApp.m_bServerRun=false;
}


void CServerDlg::OnBnClickedButton33()
{
	m_cmbCardList.ResetContent();
	int num=Server_GetCardList(m_Cardlist);
	for (int i=0;i<num;i++)
	{
		char tmp[17]={0};
		memcpy(tmp,m_Cardlist[i].barcode,sizeof(m_Cardlist[i].barcode));
		TCHAR barcode[17]={0};
		Char2TCHAR(barcode,sizeof(barcode),tmp);
		m_cmbCardList.AddString(barcode);
	}
	if (num>0)
	{
		m_cmbCardList.SetCurSel(0);

		GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON10)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON11)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON15)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON32)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	}
	else
	{
		GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON15)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON32)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	}
}



void CServerDlg::OnBnClickedButton1()
{
	CString str;
	GetDlgItem(IDC_IPADDRESS1)->GetWindowText(str);
	CString2Char(str,theApp.ftp_server_ip);
	GetDlgItem(IDC_EDIT5)->GetWindowText(str);
	theApp.ftp_server_port=_tstoi(str);
	GetDlgItem(IDC_EDIT7)->GetWindowText(str);
	CString2Char(str,theApp.ftp_server_user);
	GetDlgItem(IDC_EDIT14)->GetWindowText(str);
	CString2Char(str,theApp.ftp_server_pwd);
}


BOOL CServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	if (theApp.m_bServerRun)
	{
		GetDlgItem(IDC_BUTTON30)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON29)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON33)->EnableWindow(TRUE);
	} 
	else
	{
	GetDlgItem(IDC_BUTTON30)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON29)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON33)->EnableWindow(FALSE);
	}


	TCHAR szTemp[64]={0};
	Char2TCHAR(szTemp,sizeof(szTemp),theApp.ftp_server_ip);
	GetDlgItem(IDC_IPADDRESS1)->SetWindowText(szTemp);
	CString str;
	str.Format(_T("%d"),theApp.ftp_server_port);
	GetDlgItem(IDC_EDIT5)->SetWindowText(str);
	Char2TCHAR(szTemp,sizeof(szTemp),theApp.ftp_server_user);
	GetDlgItem(IDC_EDIT7)->SetWindowText(szTemp);
	Char2TCHAR(szTemp,sizeof(szTemp),theApp.ftp_server_pwd);
	GetDlgItem(IDC_EDIT14)->SetWindowText(szTemp);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CServerDlg::OnBnClickedButton5()
{
	CScreenProperty dlg(m_Cardlist[m_cmbCardList.GetCurSel()].PID);

	dlg.DoModal();

}


void CServerDlg::OnBnClickedButton8()
{
	CNetDlg dlg(m_Cardlist+m_cmbCardList.GetCurSel());

	dlg.DoModal();

}


void CServerDlg::OnBnClickedButton11()
{

	int err=Server_TimeCorrect(m_Cardlist[m_cmbCardList.GetCurSel()].PID);
	if (err!=ERR_NO)
	{
		AfxMessageBox(GetErrText(err));
	}

}


void CServerDlg::OnBnClickedButton32()
{
	CVolumeDlg dlg(m_Cardlist[m_cmbCardList.GetCurSel()].PID);

	dlg.DoModal();
}


void CServerDlg::OnBnClickedButton10()
{
	CBrightDlg dlg(m_Cardlist[m_cmbCardList.GetCurSel()].PID);

	dlg.DoModal();
}


void CServerDlg::OnBnClickedButton9()
{
	COnoffDlg dlg(m_Cardlist[m_cmbCardList.GetCurSel()].PID);

	dlg.DoModal();
}


void CServerDlg::OnBnClickedButton7()
{
	CFirmwareDlg dlg(m_Cardlist[m_cmbCardList.GetCurSel()].PID);

	dlg.DoModal();

}


void CServerDlg::OnBnClickedButton2()
{
	CPlaylistDlg dlg(m_Cardlist[m_cmbCardList.GetCurSel()].PID);

	dlg.DoModal();

}


void CServerDlg::OnBnClickedButton15()
{
	CDynamicAreaDlg dlg(m_Cardlist[m_cmbCardList.GetCurSel()].PID);

	dlg.DoModal();
}