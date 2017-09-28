// PlaylistDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "PlaylistDlg.h"
#include "afxdialogex.h"

#include "ProgramDlg.h"

// CPlaylistDlg 对话框

IMPLEMENT_DYNAMIC(CPlaylistDlg, CDialogEx)

CPlaylistDlg::CPlaylistDlg(char *ip,CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlaylistDlg::IDD, pParent)
{
	card_mode=0;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
}
CPlaylistDlg::CPlaylistDlg(unsigned char* pid,CWnd* pParent /*=NULL*/)
	: CDialogEx(CPlaylistDlg::IDD, pParent)
{
	card_mode=1;
	memcpy(card_pid,pid,sizeof(card_pid));
}
CPlaylistDlg::~CPlaylistDlg()
{
}

void CPlaylistDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_TotalProgress);
	DDX_Control(pDX, IDC_PROGRESS2, m_CurProgress);
	DDX_Control(pDX, IDC_COMBO2, m_WorkDir);
	DDX_Control(pDX, IDC_LIST1, m_ctrlProgramList);
	DDX_Control(pDX, IDC_PROGRESS3, m_DownProgress);
}


BEGIN_MESSAGE_MAP(CPlaylistDlg, CDialogEx)
	ON_BN_CLICKED(IDC_SEND, &CPlaylistDlg::OnBnClickedSend)
	ON_BN_CLICKED(IDC_BROWSE, &CPlaylistDlg::OnBnClickedBrowse)
	ON_BN_CLICKED(IDC_BUTTON31, &CPlaylistDlg::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON3, &CPlaylistDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CPlaylistDlg::OnBnClickedButton6)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CPlaylistDlg::OnBnClickedButton1)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON2, &CPlaylistDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CPlaylistDlg 消息处理程序


void CPlaylistDlg::OnBnClickedSend()
{
	DWORD dwPl=YQ_CreatePlaylist();
	for (int j=0;j<m_vecProgram.size();j++)
	{
		Program* p=m_vecProgram[j];
		DWORD dwProgram=YQ_CreateProgram(p->m_w,p->m_h);
		for (int i=0;i<p->m_Arealist.size();i++)
		{
			switch(p->m_Arealist[i]->m_AreaType)
			{
			case 1:
			case 2:
				{
					PicArea* n=(PicArea*)p->m_Arealist[i];
					DWORD dwArea=YQ_CreatePicArea(n->m_x,n->m_y,n->m_w,n->m_h,n->m_transparency,n->m_window_type,n->m_bBgTransparent);
					for (int t=0;t<n->m_PicCount;t++)
					{
						if (n->m_Piclist[t].bPic)
						{
							YQ_PicAreaAddImageUnit(dwArea,n->m_Piclist[t].szFile,n->m_Piclist[t].display_effects,n->m_Piclist[t].display_speed,n->m_Piclist[t].stay_time);
						} 
						else
						{
							YQ_PicAreaAddRtfUnit(dwArea,n->m_Piclist[t].szFile,n->m_Piclist[t].display_effects,n->m_Piclist[t].display_speed,n->m_Piclist[t].stay_time);
						}
					}
					YQ_ProgramAddArea(dwProgram,dwArea);
					break;
				} 
			case 3:
				{
					TimeArea* n=(TimeArea*)p->m_Arealist[i];
					DWORD dwArea=YQ_CreateCNTimeArea(n->m_x,n->m_y,n->m_w,n->m_h,n->m_transparency,n->m_timediff_flag,n->m_timediff_hour,n->m_timediff_min,
						n->m_font,n->m_fontsize,n->m_bold,n->m_italic,n->m_underline,n->m_align,n->m_multiline,n->m_day_enable,n->m_daycolor,n->m_week_enable,n->m_weekcolor,n->m_time_enable,n->m_timecolor,n->m_text_enable,n->m_textcolor,n->m_statictext);
					YQ_ProgramAddArea(dwProgram,dwArea);
					break;
				} 
			case 4:
				{
					ClockArea* n=(ClockArea*)p->m_Arealist[i];
					DWORD dwArea=YQ_CreateClockStyleArea(n->m_x,n->m_y,n->m_w,n->m_h,n->m_transparency,n->m_text_enable,n->m_textcolor,n->m_statictext,
						n->m_font,n->m_fontsize,n->m_bold,n->m_italic,n->m_underline,n->m_day_enable,n->m_daycolor,n->m_week_enable,n->m_weekcolor,n->m_hourhand_color,n->m_minhand_color,n->m_secondhand_color,
						n->m_timediff_flag,n->m_timediff_hour,n->m_timediff_min,n->m_rightangle_color,n->m_hour_color,n->m_minute_color,n->m_style);
					YQ_ProgramAddArea(dwProgram,dwArea);
					break;
				} 	
			case 5:
				{
					LunarArea* n=(LunarArea*)p->m_Arealist[i];
					DWORD dwArea=YQ_CreateLunarArea(n->m_x,n->m_y,n->m_w,n->m_h,n->m_transparency,
						n->m_font,n->m_fontsize,n->m_bold,n->m_italic,n->m_underline,n->m_align,n->m_multiline,n->m_year_enable,n->m_yearcolor,n->m_day_enable,n->m_daycolor,n->m_solarterms_enable,n->m_solartermscolor,n->m_text_enable,n->m_textcolor,n->m_statictext);
					YQ_ProgramAddArea(dwProgram,dwArea);
					break;
				} 
			case 6:
				{
					CounterArea* n=(CounterArea*)p->m_Arealist[i];
					DWORD dwArea=YQ_CreateTimeCounterArea(n->m_x,n->m_y,n->m_w,n->m_h,n->m_transparency,
						n->m_font,n->m_fontsize,n->m_bold,n->m_italic,n->m_underline,n->m_align,n->m_multiline,
						n->m_target_date,n->m_target_time,n->m_bTimeFlag,n->m_counter_color,
						n->m_day_enable,n->m_daytext,n->m_hour_enable,n->m_hourtext,n->m_min_enable,n->m_minutetext,n->m_sec_enable,n->m_secondtext,n->m_add_enable,n->m_unit_enable,n->m_text_enable,n->m_textcolor,n->m_statictext);
					YQ_ProgramAddArea(dwProgram,dwArea);
					break;
				} 
			case 7:
				{
					VideoArea* n=(VideoArea*)p->m_Arealist[i];
					DWORD dwArea=YQ_CreateVideoArea(n->m_x,n->m_y,n->m_w,n->m_h,n->m_transparency);
					for (int t=0;t<n->m_VideoCount;t++)
					{
						YQ_VideoAreaAddUnit(dwArea,n->m_Videolist[t].szVideoFile,n->m_Videolist[t].scale_mode,n->m_Videolist[t].volume);
					}
					YQ_ProgramAddArea(dwProgram,dwArea);
					break;
				} 
			}
		}
		CString str1,str2,str3,str4;
		if (p->m_bDate)
		{
			str1=p->m_aging_start_time.Format("%y-%m-%d");
			str2=p->m_aging_stop_time.Format("%y-%m-%d");
		}
		if (p->m_bTime)
		{
			str3=p->m_period_ontime.Format("%H:%M:%S");
			str4=p->m_period_offtime.Format("%H:%M:%S");
		}
		YQ_PlaylistAddProgram(dwPl,dwProgram,p->m_play_mode,p->m_play_time,str1,str2,str3,str4,p->m_play_week);
	}
	CString szLocal;
	GetDlgItem(IDC_EDIT2)->GetWindowText(szLocal);
	if (szLocal.IsEmpty())
	{
		MessageBox(_T("本地路径不能为空"));
		return;
	}
	int err=0;
	DWORD dwSend=0;
	if (card_mode==0)
	{
		dwSend=Net_SendPrograms(card_ip,m_WorkDir.GetCurSel(),dwPl,szLocal,&err);
	} 
	else
	{
		dwSend=Server_SendPrograms(card_pid,m_WorkDir.GetCurSel(),dwPl,szLocal,theApp.ftp_server_ip,theApp.ftp_server_port,theApp.ftp_server_user,theApp.ftp_server_pwd,&err);
	}
	YQ_DestroyPlaylist(dwPl);
	if (err==0)
	{
		m_hSend=dwSend;
		SetTimer(100,50,NULL);
		GetDlgItem(IDC_SEND)->EnableWindow(FALSE);
		GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
	}
	else
	{
		AfxMessageBox(GetErrText(err));
		return;
	}

}


BOOL CPlaylistDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_WorkDir.SetCurSel(1);
	m_TotalProgress.SetRange(0,100);
	m_CurProgress.SetRange(0,100);

	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	TCHAR szFilePath[MAX_PATH + 1]={0};
	GetModuleFileName(NULL, szFilePath, MAX_PATH);
	(_tcsrchr(szFilePath, _T('\\')))[1] = 0;
	GetDlgItem(IDC_EDIT2)->SetWindowText(szFilePath);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CPlaylistDlg::OnBnClickedBrowse()
{
	// 浏览节目文件夹
	BROWSEINFO bi;
	TCHAR Buffer[MAX_PATH];
	//初始化入口参数bi开始
	bi.hwndOwner = NULL;
	bi.pidlRoot =NULL;//初始化制定的root目录很不容易
	bi.pszDisplayName = Buffer;//此参数如为NULL则不能显示对话框
	bi.lpszTitle =_T( "选择节目文件夹路径");
	bi.ulFlags = BIF_EDITBOX;//带编辑框的风格
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage=IDR_MAINFRAME;

	//初始化入口参数bi结束
	LPITEMIDLIST pIDList = SHBrowseForFolder(&bi);//调用显示选择对话框

	if(pIDList)
	{
		SHGetPathFromIDList(pIDList, Buffer);

		//取得文件夹路径到Buffer里

		CString program_dir = Buffer;//将路径保存在一个CString对象里

		GetDlgItem(IDC_EDIT2)->SetWindowText(program_dir);
	}
}


void CPlaylistDlg::OnBnClickedButton31()
{
	short w=128;
	short h=96;
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
		return;
	}
	Program* p=new Program;
	p->m_w=w;
	p->m_h=h;
	p->m_play_mode=1;
	p->m_play_time=1;
	p->m_bDate=false;
	p->m_bTime=false;
	p->m_play_week=127;
	CProgramDlg dlg(p);
	if (dlg.DoModal()==IDOK)
	{
		m_vecProgram.push_back(p);
		CString str;
		str.Format(_T("%d"),m_vecProgram.size());
		m_ctrlProgramList.AddString(str);
	}
	else
	{
		delete p;
	}
}


void CPlaylistDlg::OnBnClickedButton3()
{
	int index=m_ctrlProgramList.GetCurSel();
	if (index>=0)
	{
		Program* p=m_vecProgram[index];
		CProgramDlg dlg(p);
		dlg.DoModal();
	}
}


void CPlaylistDlg::OnBnClickedButton6()
{
	int index=m_ctrlProgramList.GetCurSel();
	if (index>=0)
	{
		Program* p=m_vecProgram[index];
		delete p;
		m_vecProgram.erase(m_vecProgram.begin()+index);
		m_ctrlProgramList.DeleteString(index);
	}
}


void CPlaylistDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent==100)
	{
		int err=0;
		int total=0,cur=0;
		int down_percent=0;
		if (card_mode==0)
		{
			err=Net_GetSendProcess(m_hSend,&total,&cur);
		} 
		else
		{
			err=Server_GetSendProcess(m_hSend,&total,&cur);

			err=Server_GetDownProcess(m_hSend,&down_percent);
		}
		if (err==0)
		{
			m_TotalProgress.SetPos(total);
			m_CurProgress.SetPos(cur);
			m_DownProgress.SetPos(down_percent);
		}
		else
		{
			KillTimer(nIDEvent);
			if (err==ERR_SENDHAND)
			{
				AfxMessageBox(_T("发送完毕"));
			} 
			else
			{
				AfxMessageBox(GetErrText(err));
			}
			GetDlgItem(IDC_SEND)->EnableWindow(TRUE);
			GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
		}
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CPlaylistDlg::OnBnClickedButton1()
{
	KillTimer(100);
	if (card_mode==0)
	{
		Net_CancelSend(m_hSend);
	}
	else
	{
		Server_CancelSend(m_hSend);
	}
	GetDlgItem(IDC_SEND)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
}


void CPlaylistDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	for (int i=0;i<m_vecProgram.size();i++)
	{
		delete m_vecProgram[i];
	}
}


void CPlaylistDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
}
