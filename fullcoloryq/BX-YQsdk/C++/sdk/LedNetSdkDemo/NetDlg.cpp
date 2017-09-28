// NetDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "NetDlg.h"
#include "afxdialogex.h"


// CNetDlg 对话框

IMPLEMENT_DYNAMIC(CNetDlg, CDialogEx)

CNetDlg::CNetDlg(card_unit* pUnit,CWnd* pParent /*=NULL*/)
	: CDialogEx(CNetDlg::IDD, pParent)
	, m_IpMode(0)
	,m_ClientMode(0)
{
	card_mode=0;
	m_pUnit=pUnit;
}
CNetDlg::CNetDlg(server_card* pCard,CWnd* pParent /*= NULL*/)
	: CDialogEx(CNetDlg::IDD, pParent)
	, m_IpMode(0)
	,m_ClientMode(1)
{
	card_mode=1;
	m_pServerCard=pCard;
}
CNetDlg::~CNetDlg()
{
}

void CNetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX,IDC_RADIO1,m_IpMode);
	DDX_Radio(pDX,IDC_RADIO3,m_ClientMode);
}


BEGIN_MESSAGE_MAP(CNetDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CNetDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CNetDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO2, &CNetDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO1, &CNetDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO4, &CNetDlg::OnBnClickedRadio4)
END_MESSAGE_MAP()


// CNetDlg 消息处理程序


void CNetDlg::OnBnClickedButton1()
{
	CString str;
	GetDlgItem(IDC_IPADDRESS1)->GetWindowText(str);
	char ip[16]={0};
	CString2Char(str,ip);
	GetDlgItem(IDC_IPADDRESS2)->GetWindowText(str);
	char mask[16]={0};
	CString2Char(str,mask);
	GetDlgItem(IDC_IPADDRESS3)->GetWindowText(str);
	char gate[16]={0};
	CString2Char(str,gate);


	CButton* btn=(CButton*)GetDlgItem(IDC_RADIO1);
	if (btn->GetCheck())
	{
		//modify mode
		int err=Net_SetAutoip(m_pUnit->PID);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
		else
		{
			char ip[16]={0};
			char mask[16]={0};
			char gate[16]={0};
			BYTE ipmode;
			unsigned char pid[16]={0};
			int err=Net_GetIp(m_pUnit->PID,ip);
			if (err!=ERR_NO)
			{
				AfxMessageBox(GetErrText(err));
			}
			err=Net_GetNetinfo(ip,pid,m_pUnit->ip,mask,gate,&ipmode);
			strcpy(m_pUnit->ip,ip);
			if (err==0)
			{
				m_IpMode=ipmode;
				
				TCHAR tmp[16]={0};
				Char2TCHAR(tmp,sizeof(tmp),ip);
				GetDlgItem(IDC_IPADDRESS1)->SetWindowText(tmp);
				memset(tmp,0,sizeof(tmp));
				Char2TCHAR(tmp,sizeof(tmp),mask);
				GetDlgItem(IDC_IPADDRESS2)->SetWindowText(tmp);
				memset(tmp,0,sizeof(tmp));
				Char2TCHAR(tmp,sizeof(tmp),gate);
				GetDlgItem(IDC_IPADDRESS3)->SetWindowText(tmp);
		
			}
		}
	}
	else
	{
		//modify ip only
		int err=Net_SetStaticip(m_pUnit->PID,ip,mask,gate);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
		else
		{
			strcpy(m_pUnit->ip,ip);
		}
	}
	

}


BOOL CNetDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	GetDlgItem(IDC_EDIT1)->SetWindowText(_T("6005"));
	char serverip[16]={0};
	USHORT port=0;

	char ip[16]={0};
	char mask[16]={0};
	char gate[16]={0};
	BYTE ipmode;
	unsigned char pid[16]={0};
	if(card_mode==0)
	{
		int err=Net_GetNetinfo(m_pUnit->ip,m_pUnit->PID,ip,mask,gate,&ipmode);
		if (err!=ERR_NO)
		{
			//AfxMessageBox(GetErrText(err));
		}
		else
		{
			m_IpMode=ipmode;
			TCHAR tmp[16]={0};
			Char2TCHAR(tmp,sizeof(tmp),ip);
			GetDlgItem(IDC_IPADDRESS1)->SetWindowText(tmp);
			memset(tmp,0,sizeof(tmp));
			Char2TCHAR(tmp,sizeof(tmp),mask);
			GetDlgItem(IDC_IPADDRESS2)->SetWindowText(tmp);
			memset(tmp,0,sizeof(tmp));
			Char2TCHAR(tmp,sizeof(tmp),gate);
			GetDlgItem(IDC_IPADDRESS3)->SetWindowText(tmp);
		}

		BYTE mode=0;
		err=Net_GetModeinfo(m_pUnit->ip,&mode,serverip,&port);
		if (err!=ERR_NO)
		{
			//AfxMessageBox(GetErrText(err));
		}
		else
		{
			if (mode==1)
			{
				TCHAR tmp[16]={0};
				Char2TCHAR(tmp,sizeof(tmp),serverip);
				GetDlgItem(IDC_IPADDRESS4)->SetWindowText(tmp);
				CString str;
				str.Format(_T("%d"),port);
				GetDlgItem(IDC_EDIT1)->SetWindowText(str);
				m_ClientMode=mode;
			}

		}
	}
	else if(card_mode==1)
	{
		int err=Server_GetNetinfo(m_pServerCard->PID,pid,ip,mask,gate,&ipmode);
		if (err!=ERR_NO)
		{
			AfxMessageBox(GetErrText(err));
			return FALSE;
		}
		else
		{
			m_IpMode=ipmode;
			TCHAR tmp[16]={0};
			Char2TCHAR(tmp,sizeof(tmp),ip);
			GetDlgItem(IDC_IPADDRESS1)->SetWindowText(tmp);
			memset(tmp,0,sizeof(tmp));
			Char2TCHAR(tmp,sizeof(tmp),mask);
			GetDlgItem(IDC_IPADDRESS2)->SetWindowText(tmp);
			memset(tmp,0,sizeof(tmp));
			Char2TCHAR(tmp,sizeof(tmp),gate);
			GetDlgItem(IDC_IPADDRESS3)->SetWindowText(tmp);
		}
		err=Server_GetModeinfo(m_pServerCard->PID,serverip,&port);
		if (err!=ERR_NO)
		{
			AfxMessageBox(GetErrText(err));
		}
		else
		{
			TCHAR tmp[16]={0};
			Char2TCHAR(tmp,sizeof(tmp),serverip);
			GetDlgItem(IDC_IPADDRESS4)->SetWindowText(tmp);
			CString str;
			str.Format(_T("%d"),port);
			GetDlgItem(IDC_EDIT1)->SetWindowText(str);

		}
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	}

		if (m_IpMode==0)
		{
			GetDlgItem(IDC_IPADDRESS1)->EnableWindow(FALSE);
			GetDlgItem(IDC_IPADDRESS2)->EnableWindow(FALSE);
			GetDlgItem(IDC_IPADDRESS3)->EnableWindow(FALSE);
		}
		if (m_ClientMode==0)
		{
			GetDlgItem(IDC_IPADDRESS4)->EnableWindow(FALSE);
			GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		}
		UpdateData(FALSE);



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CNetDlg::OnBnClickedButton2()
{

		CButton* btn=(CButton*)GetDlgItem(IDC_RADIO3);
		if (btn->GetCheck())
		{
			//no change
			int err=Net_SetClientMode(m_pUnit->ip);
			if (err!=0)
			{
				AfxMessageBox(GetErrText(err));
			}
		}
		else
		{
			CString str;
			GetDlgItem(IDC_IPADDRESS4)->GetWindowText(str);
			char ip[16]={0};
			CString2Char(str,ip);
			GetDlgItem(IDC_EDIT1)->GetWindowText(str);
			short port=_tstoi(str);

			int err=Net_SetServerMode(m_pUnit->ip,ip,port);
			if (err!=0)
			{
				AfxMessageBox(GetErrText(err));
			}

		}


}




void CNetDlg::OnBnClickedRadio2()
{
	GetDlgItem(IDC_IPADDRESS1)->EnableWindow(TRUE);
	GetDlgItem(IDC_IPADDRESS2)->EnableWindow(TRUE);
	GetDlgItem(IDC_IPADDRESS3)->EnableWindow(TRUE);
}


void CNetDlg::OnBnClickedRadio1()
{
	GetDlgItem(IDC_IPADDRESS1)->EnableWindow(FALSE);
	GetDlgItem(IDC_IPADDRESS2)->EnableWindow(FALSE);
	GetDlgItem(IDC_IPADDRESS3)->EnableWindow(FALSE);
}


void CNetDlg::OnBnClickedRadio4()
{
	GetDlgItem(IDC_IPADDRESS4)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
}
