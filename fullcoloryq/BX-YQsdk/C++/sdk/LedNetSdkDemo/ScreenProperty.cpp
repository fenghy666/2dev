// ScreenProperty.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "ScreenProperty.h"
#include "afxdialogex.h"


// CScreenProperty 对话框

IMPLEMENT_DYNAMIC(CScreenProperty, CDialogEx)

CScreenProperty::CScreenProperty(char *ip,CWnd* pParent /*=NULL*/)
	: CDialogEx(CScreenProperty::IDD, pParent)
{
	card_mode=0;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
}
CScreenProperty::CScreenProperty(unsigned char* pid,CWnd* pParent /*=NULL*/)
	: CDialogEx(CScreenProperty::IDD, pParent)
{
	card_mode=1;
	memcpy(card_pid,pid,sizeof(card_pid));
}

CScreenProperty::~CScreenProperty()
{
}

void CScreenProperty::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO4, m_cmbCardType);
}


BEGIN_MESSAGE_MAP(CScreenProperty, CDialogEx)
	ON_BN_CLICKED(IDC_SET_SCREENINFO, &CScreenProperty::OnBnClickedSetScreeninfo)
END_MESSAGE_MAP()


// CScreenProperty 消息处理程序


void CScreenProperty::OnBnClickedSetScreeninfo()
{
	CString str;
	GetDlgItem(IDC_EDIT12)->GetWindowText(str);
	short w=_tstoi(str);
	GetDlgItem(IDC_EDIT9)->GetWindowText(str);
	short h=_tstoi(str);

	switch(m_cmbCardType.GetCurSel())
	{
	case 0://BX_YQ1_75
		{
			if (w>384||h>384)
			{
				MessageBox(_T("YQ1-75 的宽高超出范围！"));
				return;
			} 
			break;
		}
	case 1://BX_YQ1
		{
			if (w>384||h>256)
			{
				MessageBox(_T("YQ1 的宽高超出范围！"));
				return;
			} 
			break;
		}
	case 2://BX_YQ2
		{
			if (w>2048||h>1024||w*h>480000)
			{
				MessageBox(_T("YQ2 的宽高超出范围！"));
				return;
			} 
			break;
		}
	default:
		break;
	}
	if (card_mode==0)
	{
		int err=Net_SetScreenSize(card_ip,w,h);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	} 
	else
	{
		int err=Server_SetScreenSize(card_pid,w,h);
		if (err!=0)
		{
			AfxMessageBox(GetErrText(err));
		}
	}

}


BOOL CScreenProperty::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	
	short w;
	short h;
	USHORT type;

	int err=0;
	if (card_mode==0)
	{
		err=Net_GetScreeninfo(card_ip,&type,&w,&h);
	} 
	else
	{
		err=Server_GetScreeninfo(card_pid,&type,&w,&h);
	}
	
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
	}
	else
	{
		CString str;
		str.Format(_T("%d"),w);
		GetDlgItem(IDC_EDIT12)->SetWindowText(str);

		str.Format(_T("%d"),h);
		GetDlgItem(IDC_EDIT9)->SetWindowText(str);

		switch(type)
		{
		case ONBON_BX_YQ1_75:
			m_cmbCardType.SetCurSel(0);
			break;
		case ONBON_BX_YQ1:
			m_cmbCardType.SetCurSel(1);
			break;
		case ONBON_BX_YQ2:
			m_cmbCardType.SetCurSel(2);
			break;
		case ONBON_BX_YQ3:
			m_cmbCardType.SetCurSel(3);
			break;
		case ONBON_BX_YQ4:
			m_cmbCardType.SetCurSel(4);
			break;
		case ONBON_BX_YQ2E:
			m_cmbCardType.SetCurSel(5);
			break;
		default:
			m_cmbCardType.SetCurSel(6);
			break;
		}
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
