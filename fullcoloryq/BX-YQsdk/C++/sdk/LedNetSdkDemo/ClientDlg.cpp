// ClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "ClientDlg.h"
#include "afxdialogex.h"

#include "ScreenProperty.h"
#include "NetDlg.h"
#include "VolumeDlg.h"
#include "BrightDlg.h"
#include "OnoffDlg.h"
#include "FirmwareDlg.h"
#include "PlaylistDlg.h"
#include "DynamicAreaDlg.h"

// CClientDlg 对话框

IMPLEMENT_DYNAMIC(CClientDlg, CDialogEx)

CClientDlg::CClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CClientDlg::IDD, pParent)
{

}

CClientDlg::~CClientDlg()
{
}

void CClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO7, m_cmbClientCardList);
}


BEGIN_MESSAGE_MAP(CClientDlg, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON28, &CClientDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON5, &CClientDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &CClientDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON11, &CClientDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON32, &CClientDlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON10, &CClientDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON9, &CClientDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON7, &CClientDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON2, &CClientDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON15, &CClientDlg::OnBnClickedButton15)
	ON_CBN_SELCHANGE(IDC_COMBO7, &CClientDlg::OnCbnSelchangeCombo7)
	ON_BN_CLICKED(IDC_BUTTON1, &CClientDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CClientDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CClientDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CClientDlg 消息处理程序





void CClientDlg::OnCbnSelchangeCombo7()
{
	int index=m_cmbClientCardList.GetCurSel();
	TCHAR ip[16]={0};
	Char2TCHAR(ip,sizeof(ip),m_ClientList[index].ip);
	GetDlgItem(IDC_IPADDRESS3)->SetWindowText(ip);
}

void CClientDlg::OnBnClickedButton28()
{
	m_cmbClientCardList.ResetContent();
	m_ClientCount=Net_SearchCards(m_ClientList,1);
	//m_ClientCount=1;
	//strcpy(m_ClientList->ip,"127.0.0.1");
	//m_cmbClientCardList.AddString(_T(""));
	for (int i=0;i<m_ClientCount;i++)
	{
		char tmp[17]={0};
		memcpy(tmp,m_ClientList[i].barcode,sizeof(m_ClientList[i].barcode));
		TCHAR barcode[17]={0};
		Char2TCHAR(barcode,sizeof(barcode),tmp);
		m_cmbClientCardList.AddString(barcode);
	}
	
	if (m_ClientCount>0)
	{
		m_cmbClientCardList.SetCurSel(0);
		OnCbnSelchangeCombo7();
		GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON10)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON11)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON15)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON32)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
		GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON7)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON8)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON9)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON10)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON11)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON15)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON32)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	}
}


void CClientDlg::OnBnClickedButton5()
{
	int t=m_cmbClientCardList.GetCurSel();
	CScreenProperty dlg(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);

	dlg.DoModal();

}


void CClientDlg::OnBnClickedButton8()
{
	CNetDlg dlg(m_ClientList+m_cmbClientCardList.GetCurSel());

	dlg.DoModal();

}


void CClientDlg::OnBnClickedButton11()
{
	int err=Net_TimeCorrect(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);
	if (err!=ERR_NO)
	{
		AfxMessageBox(GetErrText(err));
	}

}


void CClientDlg::OnBnClickedButton32()
{
	CVolumeDlg dlg(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);

	dlg.DoModal();
}


void CClientDlg::OnBnClickedButton10()
{
	CBrightDlg dlg(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);

	dlg.DoModal();
}


void CClientDlg::OnBnClickedButton9()
{
	COnoffDlg dlg(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);

	dlg.DoModal();
}


void CClientDlg::OnBnClickedButton7()
{
	CFirmwareDlg dlg(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);

	dlg.DoModal();

}


void CClientDlg::OnBnClickedButton2()
{
	CPlaylistDlg dlg(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);

	dlg.DoModal();

}


void CClientDlg::OnBnClickedButton15()
{
	CDynamicAreaDlg dlg(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);

	dlg.DoModal();
}
BOOL CClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	m_ClientList=new card_unit[1024];
	m_ClientCount=0;

	
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T("0"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
void CClientDlg::OnClose()
{

	if (m_ClientCount>0)
	{
		delete[] m_ClientList;
	}
	CDialogEx::OnClose();
}

void CClientDlg::OnBnClickedButton1()
{
	CString str;
	GetDlgItem(IDC_IPADDRESS3)->GetWindowText(str);
	char ip[16]={0};
	CString2Char(str,ip);
	m_ClientCount=1;
	memset(m_ClientList[0].ip,0,sizeof(m_ClientList[0].ip));
	strcpy(m_ClientList[0].ip,ip);
	m_cmbClientCardList.AddString(_T(""));
	m_cmbClientCardList.SetCurSel(0);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON7)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON8)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON9)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON10)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON11)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON15)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON32)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
}


void CClientDlg::OnBnClickedButton3()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	BYTE SaveLock;
	CString freq;
	GetDlgItem(IDC_EDIT1)->GetWindowText(freq);
	int program_id=_tstoi(freq);
	if (btn->GetCheck())
	{
		SaveLock = 1;
	} 
	else
	{
		SaveLock = 0;
	}
	int err=Net_LockProgram(m_ClientList[m_cmbClientCardList.GetCurSel()].ip, program_id, SaveLock);
	if (err!=ERR_NO)
	{
		AfxMessageBox(GetErrText(err));
	}
}


void CClientDlg::OnBnClickedButton4()
{
	int err=Net_UnLockProgram(m_ClientList[m_cmbClientCardList.GetCurSel()].ip);
	if (err!=ERR_NO)
	{
		AfxMessageBox(GetErrText(err));
	}
}
