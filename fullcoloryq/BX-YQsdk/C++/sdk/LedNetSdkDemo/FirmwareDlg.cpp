// FirmwareDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "FirmwareDlg.h"
#include "afxdialogex.h"


// CFirmwareDlg �Ի���

IMPLEMENT_DYNAMIC(CFirmwareDlg, CDialogEx)

CFirmwareDlg::CFirmwareDlg(char *ip,CWnd* pParent /*=NULL*/)
	: CDialogEx(CFirmwareDlg::IDD, pParent)
{
	card_mode=0;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
}
CFirmwareDlg::CFirmwareDlg(unsigned char* pid,CWnd* pParent /*=NULL*/)
	: CDialogEx(CFirmwareDlg::IDD, pParent)
{
	card_mode=1;
	memcpy(card_pid,pid,sizeof(card_pid));

}
CFirmwareDlg::~CFirmwareDlg()
{
}

void CFirmwareDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CFirmwareDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CFirmwareDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON12, &CFirmwareDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON3, &CFirmwareDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CFirmwareDlg ��Ϣ�������

struct UpdateFileStruct{
	char _backup[16]; //!< ������
	char _md5[32];    //!< md5У��ֵ
	char _fileName[64]; //!< ��У����ļ���
	char _updateVersion[64]; //!< �������汾��
	char _appVerison[64]; //!< �̼��汾��
	char _controllerType[64]; //!< �������ͺ�
	char _createdTime[64]; //!< ����������ʱ��
};
void CFirmwareDlg::OnBnClickedButton2()
{
	CFileDialog dlg(TRUE,_T("tar.gz.md5"),NULL,OFN_HIDEREADONLY|OFN_ALLOWMULTISELECT,_T("(*.tar.gz.md5)|*.tar.gz.md5||"));
	if(dlg.DoModal() == IDOK)
	{
		CString path=dlg.GetPathName();
		GetDlgItem(IDC_EDIT4)->SetWindowText(path);
		CFile file;
		if (file.Open(path,CFile::modeRead))
		{
			UpdateFileStruct tmp;
			file.Read(&tmp,sizeof(UpdateFileStruct));
			file.Close();
			TCHAR str[64]={0};
			Char2TCHAR(str,sizeof(str),tmp._controllerType);
			USHORT type=_tstoi(str);
			switch(type)
			{
			case ONBON_BX_YQ1_75:GetDlgItem(IDC_EDIT5)->SetWindowText(_T("BX_YQ1_75"));break;
			case ONBON_BX_YQ2:GetDlgItem(IDC_EDIT5)->SetWindowText(_T("BX_YQ2"));break;
			case ONBON_BX_YQ3:GetDlgItem(IDC_EDIT5)->SetWindowText(_T("BX_YQ3"));break;
			case ONBON_BX_YQ4:GetDlgItem(IDC_EDIT5)->SetWindowText(_T("BX_YQ4"));break;
			case ONBON_BX_YQ2E:GetDlgItem(IDC_EDIT5)->SetWindowText(_T("BX_YQ2E"));break;
			case ONBON_BX_YQ5:GetDlgItem(IDC_EDIT5)->SetWindowText(_T("BX_YQ5"));break;
			default:GetDlgItem(IDC_EDIT5)->SetWindowText(_T("δ֪����"));break;
			}
			
			memset(str,0,sizeof(str));
			Char2TCHAR(str,sizeof(str),tmp._createdTime);
			GetDlgItem(IDC_EDIT6)->SetWindowText(str);
			memset(str,0,sizeof(str));
			Char2TCHAR(str,sizeof(str),tmp._updateVersion);
			GetDlgItem(IDC_EDIT7)->SetWindowText(str);
		}
	}
}


BOOL CFirmwareDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	char firmwaretime[64]={0};
	char firmwareversion[64]={0};
	int err=0;
	if (card_mode==0)
	{
		err=Net_GetFirmwareinfo(card_ip,firmwaretime,firmwareversion);
	}
	else
	{
		err=Server_GetFirmwareinfo(card_pid,firmwaretime,firmwareversion);
	}
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
	}
	else
	{
		TCHAR tmp[64]={0};
		Char2TCHAR(tmp,sizeof(tmp),firmwareversion);
		GetDlgItem(IDC_EDIT1)->SetWindowText(tmp);
		memset(tmp,0,sizeof(tmp));
		Char2TCHAR(tmp,sizeof(tmp),firmwaretime);
		GetDlgItem(IDC_EDIT2)->SetWindowText(tmp);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CFirmwareDlg::OnBnClickedButton12()
{
	CFileDialog dlg(TRUE,_T("tar.gz"),NULL,OFN_HIDEREADONLY|OFN_ALLOWMULTISELECT,_T("(*.tar.gz)|*.tar.gz||"));
	if(dlg.DoModal() == IDOK)
	{
		GetDlgItem(IDC_EDIT13)->SetWindowText(dlg.GetPathName());
	}
}


void CFirmwareDlg::OnBnClickedButton3()
{
	CString strMd5,strUpdate;
	GetDlgItem(IDC_EDIT4)->GetWindowText(strMd5);
	GetDlgItem(IDC_EDIT13)->GetWindowText(strUpdate);
	if (!strMd5.IsEmpty() && !strUpdate.IsEmpty())
	{
		if (card_mode==0)
		{
			int err=Net_Update(card_ip,strMd5,strUpdate);
			if (err!=0)
			{
				AfxMessageBox(GetErrText(err));
			}
		}
		else
		{
			int err=Server_Update(card_pid,strMd5,strUpdate,theApp.ftp_server_ip,theApp.ftp_server_port,theApp.ftp_server_user,theApp.ftp_server_pwd);
			if (err!=0)
			{
				AfxMessageBox(GetErrText(err));
			}
		}
	}

}
