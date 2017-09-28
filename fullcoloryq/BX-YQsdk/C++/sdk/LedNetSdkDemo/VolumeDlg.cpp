// VolumeDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "VolumeDlg.h"
#include "afxdialogex.h"


// CVolumeDlg 对话框

IMPLEMENT_DYNAMIC(CVolumeDlg, CDialogEx)

CVolumeDlg::CVolumeDlg(char* ip,CWnd* pParent /*=NULL*/)
	: CDialogEx(CVolumeDlg::IDD, pParent)
{
	card_mode=0;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
}
CVolumeDlg::CVolumeDlg(unsigned char* pid,CWnd* pParent /*=NULL*/)
	: CDialogEx(CVolumeDlg::IDD, pParent)
{
	card_mode=1;
	memcpy(card_pid,pid,sizeof(card_pid));
}
CVolumeDlg::~CVolumeDlg()
{
}

void CVolumeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_VolumeSlider);
}


BEGIN_MESSAGE_MAP(CVolumeDlg, CDialogEx)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, &CVolumeDlg::OnNMReleasedcaptureSlider1)
END_MESSAGE_MAP()


// CVolumeDlg 消息处理程序




BOOL CVolumeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_VolumeSlider.SetRange(0,100);
	BYTE volume=0;
	int err=0;
	if (card_mode==0)
	{
		err=Net_GetVolume(card_ip,&volume);
	} 
	else
	{
		err=Server_GetVolume(card_pid,&volume);
	}
	
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
	}
	else
	{
		m_VolumeSlider.SetPos(volume);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CVolumeDlg::OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	BYTE volume=m_VolumeSlider.GetPos();
	if (card_mode==0)
	{
		int err=Net_SetVolume(card_ip,volume);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	} 
	else
	{
		int err=Server_SetVolume(card_pid,volume);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}

	*pResult = 0;
}
