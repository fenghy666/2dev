// ProgramDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "ProgramDlg.h"
#include "afxdialogex.h"

#include "TextAreaDlg.h"
#include "ImageAreaDlg.h"
#include "VideoAreaDlg.h"
#include "TimeAreaDlg.h"
#include "CounterAreaDlg.h"
#include "ClockAreaDlg.h"
#include "LunarAreaDlg.h"


// CProgramDlg 对话框

IMPLEMENT_DYNAMIC(CProgramDlg, CDialogEx)

CProgramDlg::CProgramDlg(Program* p,CWnd* pParent /*=NULL*/)
	: CDialogEx(CProgramDlg::IDD, pParent)
	, m_Playmode(0)
{
	m_Program=p;
}

CProgramDlg::~CProgramDlg()
{
}

void CProgramDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctrlAreaList);
	DDX_Radio(pDX,IDC_RADIO1,m_Playmode);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_ctrlDate1);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_ctrlDate2);
	DDX_Control(pDX, IDC_DATETIMEPICKER3, m_ctrlTime1);
	DDX_Control(pDX, IDC_DATETIMEPICKER4, m_ctrlTime2);
}


BEGIN_MESSAGE_MAP(CProgramDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CProgramDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CProgramDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON12, &CProgramDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CProgramDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON16, &CProgramDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CProgramDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CProgramDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON3, &CProgramDlg::OnBnClickedButton3)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CProgramDlg::OnNMDblclkList1)
	ON_BN_CLICKED(IDOK, &CProgramDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CProgramDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CHECK1, &CProgramDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK6, &CProgramDlg::OnBnClickedCheck6)
END_MESSAGE_MAP()


// CProgramDlg 消息处理程序


void CProgramDlg::OnBnClickedButton1()
{
	PicArea* p=new PicArea(1);

	p->m_x=0;
	p->m_y=0;
	p->m_w=m_Program->m_w;
	p->m_h=m_Program->m_h;
	p->m_transparency=255;
	p->m_bBgTransparent=false;
	p->m_window_type=1;
	p->m_PicCount=0;
	memset(p->m_Piclist,0,sizeof(p->m_Piclist));
	CImageAreaDlg dlg(p);
	if (dlg.DoModal()==IDOK)
	{
		m_vecArea.push_back(p);
		CString str;
		str.Format(_T("区域%d"),m_vecArea.size());
		int item=m_ctrlAreaList.InsertItem(m_ctrlAreaList.GetItemCount(),str);
		m_ctrlAreaList.SetItemText(item,1,_T("图文"));
	}
	else
	{
		delete p;
	}
}


void CProgramDlg::OnBnClickedButton2()
{
	VideoArea* p=new VideoArea(7);

	p->m_x=0;
	p->m_y=0;
	p->m_w=m_Program->m_w;
	p->m_h=m_Program->m_h;
	p->m_transparency=255;
	p->m_VideoCount=0;
	memset(p->m_Videolist,0,sizeof(p->m_Videolist));
	CVideoAreaDlg dlg(p);
	if (dlg.DoModal()==IDOK)
	{
		m_vecArea.push_back(p);
		CString str;
		str.Format(_T("区域%d"),m_vecArea.size());
		int item=m_ctrlAreaList.InsertItem(m_ctrlAreaList.GetItemCount(),str);
		m_ctrlAreaList.SetItemText(item,1,_T("视频"));
	}
	else
	{
		delete p;
	}
}


void CProgramDlg::OnBnClickedButton12()
{
	PicArea* p=new PicArea(2);

	p->m_x=0;
	p->m_y=0;
	p->m_w=m_Program->m_w;
	p->m_h=m_Program->m_h;
	p->m_transparency=255;
	p->m_bBgTransparent=false;
	p->m_window_type=3;
	CTextAreaDlg dlg(p);
	if (dlg.DoModal()==IDOK)
	{
		m_vecArea.push_back(p);
		CString str;
		str.Format(_T("区域%d"),m_vecArea.size());
		int item=m_ctrlAreaList.InsertItem(m_ctrlAreaList.GetItemCount(),str);
		m_ctrlAreaList.SetItemText(item,1,_T("字幕"));
	}
	else
	{
		delete p;
	}
}


void CProgramDlg::OnBnClickedButton13()
{
	TimeArea* p=new TimeArea(3);

	p->m_x=0;
	p->m_y=0;
	p->m_w=m_Program->m_w;
	p->m_h=m_Program->m_h;
	p->m_transparency=255;
	p-> m_timediff_flag=1;
	p-> m_timediff_hour=0;
	p-> m_timediff_min=0;
	_tcscpy_s(p->m_font,_T("宋体"));
	p->m_fontsize=12;
	p->m_bold=1;
	p->m_italic=0;
	p->m_underline=0;
	p-> m_align=1;//0:1:2;左中右
	p->m_multiline=true;
	p->m_day_enable=true;
	p->m_daycolor=RGB(0,0,255);

	p->m_week_enable=true;
	p->m_weekcolor=RGB(255,255,255);

	p->m_time_enable=true;
	p->m_timecolor=RGB(255,255,255);

	p->m_text_enable=false;
	p->m_textcolor=RGB(255,255,255);


	CTimeAreaDlg dlg(p);
	if (dlg.DoModal()==IDOK)
	{
		m_vecArea.push_back(p);
		CString str;
		str.Format(_T("区域%d"),m_vecArea.size());
		int item=m_ctrlAreaList.InsertItem(m_ctrlAreaList.GetItemCount(),str);
		m_ctrlAreaList.SetItemText(item,1,_T("时间"));
	}
	else
	{
		delete p;
	}
}


void CProgramDlg::OnBnClickedButton16()
{
	ClockArea* p=new ClockArea(4);
	p->m_x=0;
	p->m_y=0;
	p->m_w=m_Program->m_w;
	p->m_h=m_Program->m_h;
	p->m_transparency=255;
	p->m_text_enable=false;


	p->m_day_enable=true;
	p->m_daycolor=RGB(255,255,255);


	p->m_week_enable=true;
	p->m_weekcolor=RGB(255,255,255);

	_tcscpy_s(p->m_font,_T("宋体"));

	p->m_fontsize=12;
	p->m_bold=true;
	p->m_italic=false;
	p->m_underline=false;

	p->m_hourhand_color=RGB(255,255,0);
	p->m_minhand_color=RGB(0,255,0);
	p->m_secondhand_color=RGB(255,0,0);
	p->m_timediff_flag=1;
	p->m_timediff_hour=0;
	p->m_timediff_min=0;
	p->m_hour_color=RGB(255,255,255);
	p->m_rightangle_color=RGB(255,255,255);
	p->m_minute_color=RGB(255,0,0);
	p->m_style=1;
	CClockAreaDlg dlg(p);
	if (dlg.DoModal()==IDOK)
	{
		m_vecArea.push_back(p);
		CString str;
		str.Format(_T("区域%d"),m_vecArea.size());
		int item=m_ctrlAreaList.InsertItem(m_ctrlAreaList.GetItemCount(),str);
		m_ctrlAreaList.SetItemText(item,1,_T("表盘"));
	}
	else
	{
		delete p;
	}
}


void CProgramDlg::OnBnClickedButton17()
{
	LunarArea* p=new LunarArea(5);
	p->m_x=0;
	p->m_y=0;
	p->m_w=m_Program->m_w;
	p->m_h=m_Program->m_h;
	p->m_transparency=255;
	_tcscpy_s(p->m_font,_T("宋体"));

	p->m_fontsize=12;
	p->m_bold=false;
	p->m_italic=false;
	p->m_underline=false;
	p->m_align=1;
	p->m_multiline=true;
	p->m_year_enable=true;
	p->m_yearcolor=RGB(255,255,255);
	p->m_day_enable=true;
	p->m_daycolor=RGB(255,255,255);
	p->m_solarterms_enable=true;
	p->m_solartermscolor=RGB(255,255,255);

	p->m_text_enable=false;


	CLunarAreaDlg dlg(p);
	if (dlg.DoModal()==IDOK)
	{
		m_vecArea.push_back(p);
		CString str;
		str.Format(_T("区域%d"),m_vecArea.size());
		int item=m_ctrlAreaList.InsertItem(m_ctrlAreaList.GetItemCount(),str);
		m_ctrlAreaList.SetItemText(item,1,_T("农历"));
	}
	else
	{
		delete p;
	}
}


void CProgramDlg::OnBnClickedButton18()
{
	CounterArea* p=new CounterArea(6);
	p->m_x=0;
	p->m_y=0;
	p->m_w=m_Program->m_w;
	p->m_h=m_Program->m_h;
	p->m_transparency=255;
	_tcscpy_s(p->m_font,_T("宋体"));
	p->m_fontsize=12;
	p->m_bold=false;
	p->m_italic=false;
	p->m_underline=false;
	p->m_align=1;
	p->m_multiline=true;
	_tcscpy_s(p->m_target_date,_T("2016-07-01"));
	_tcscpy_s(p->m_target_time,_T("01:01:01"));

	p->m_counter_color=RGB(255,255,255);
	p->m_day_enable=true;
	_tcscpy_s(p->m_daytext,_T("天"));
	
	p->m_hour_enable=true;
	_tcscpy_s(p->m_hourtext,_T("小时"));

	p->m_min_enable=true;
	_tcscpy_s(p->m_minutetext,_T("分"));
	p->m_sec_enable=true;
	_tcscpy_s(p->m_secondtext,_T("秒"));
	p->m_add_enable=true;
	p->m_unit_enable=true;
	p->m_text_enable=false;
	p->m_bTimeFlag=0;//倒计时

	CCounterAreaDlg dlg(p);
	if (dlg.DoModal()==IDOK)
	{
		m_vecArea.push_back(p);
		CString str;
		str.Format(_T("区域%d"),m_vecArea.size());
		int item=m_ctrlAreaList.InsertItem(m_ctrlAreaList.GetItemCount(),str);
		m_ctrlAreaList.SetItemText(item,1,_T("计时"));
	}
	else
	{
		delete p;
	}
}


void CProgramDlg::OnBnClickedButton3()
{
	POSITION pos=m_ctrlAreaList.GetFirstSelectedItemPosition();
	int index=m_ctrlAreaList.GetNextSelectedItem(pos);
	CString strType=m_ctrlAreaList.GetItemText(index,1);

	m_ctrlAreaList.DeleteItem(index);
	delete m_vecArea[index];
	m_vecArea.erase(m_vecArea.begin()+index);

}


BOOL CProgramDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CRect rect;
	m_ctrlAreaList.GetWindowRect(&rect);
	m_ctrlAreaList.InsertColumn(0, _T("名称"), LVCFMT_LEFT,rect.Width() * 3/4, 0);
	m_ctrlAreaList.InsertColumn(1, _T("类型"), LVCFMT_LEFT,rect.Width() * 1/4-50, 1);

	for (int i=0;i<m_Program->m_Arealist.size();i++)
	{
		switch(m_Program->m_Arealist[i]->m_AreaType)
		{
		case 1:
			{
				PicArea* n=(PicArea*)m_Program->m_Arealist[i];
				PicArea* p=new PicArea(1);
				*p=*n;
				m_vecArea.push_back(p);
				CString str;
				str.Format(_T("区域%d"),m_vecArea.size());
				int item=m_ctrlAreaList.InsertItem(m_ctrlAreaList.GetItemCount(),str);
				m_ctrlAreaList.SetItemText(item,1,_T("图文"));
				break;
			} 
		case 2:
			{
				PicArea* n=(PicArea*)m_Program->m_Arealist[i];
				PicArea* p=new PicArea(2);
				*p=*n;
				m_vecArea.push_back(p);
				CString str;
				str.Format(_T("区域%d"),m_vecArea.size());
				int item=m_ctrlAreaList.InsertItem(m_ctrlAreaList.GetItemCount(),str);
				m_ctrlAreaList.SetItemText(item,1,_T("字幕"));
				break;
			} 
		case 3:
			{
				TimeArea* n=(TimeArea*)m_Program->m_Arealist[i];
				TimeArea* p=new TimeArea(3);
				*p=*n;
				m_vecArea.push_back(p);
				CString str;
				str.Format(_T("区域%d"),m_vecArea.size());
				int item=m_ctrlAreaList.InsertItem(m_ctrlAreaList.GetItemCount(),str);
				m_ctrlAreaList.SetItemText(item,1,_T("时间"));
				break;
			} 
		case 4:
			{
				ClockArea* n=(ClockArea*)m_Program->m_Arealist[i];
				ClockArea* p=new ClockArea(4);
				*p=*n;
				m_vecArea.push_back(p);
				CString str;
				str.Format(_T("区域%d"),m_vecArea.size());
				int item=m_ctrlAreaList.InsertItem(m_ctrlAreaList.GetItemCount(),str);
				m_ctrlAreaList.SetItemText(item,1,_T("表盘"));
				break;
			} 	
		case 5:
			{
				LunarArea* n=(LunarArea*)m_Program->m_Arealist[i];
				LunarArea* p=new LunarArea(5);
				*p=*n;
				m_vecArea.push_back(p);
				CString str;
				str.Format(_T("区域%d"),m_vecArea.size());
				int item=m_ctrlAreaList.InsertItem(m_ctrlAreaList.GetItemCount(),str);
				m_ctrlAreaList.SetItemText(item,1,_T("农历"));
				break;
			} 
		case 6:
			{
				CounterArea* n=(CounterArea*)m_Program->m_Arealist[i];
				CounterArea* p=new CounterArea(6);
				*p=*n;
				m_vecArea.push_back(p);
				CString str;
				str.Format(_T("区域%d"),m_vecArea.size());
				int item=m_ctrlAreaList.InsertItem(m_ctrlAreaList.GetItemCount(),str);
				m_ctrlAreaList.SetItemText(item,1,_T("计时"));
				break;
			} 
		case 7:
			{
				VideoArea* n=(VideoArea*)m_Program->m_Arealist[i];
				VideoArea* p=new VideoArea(7);
				*p=*n;
				m_vecArea.push_back(p);
				CString str;
				str.Format(_T("区域%d"),m_vecArea.size());
				int item=m_ctrlAreaList.InsertItem(m_ctrlAreaList.GetItemCount(),str);
				m_ctrlAreaList.SetItemText(item,1,_T("视频"));
				break;
			} 
		}

	}
	m_Playmode=m_Program->m_play_mode;
	CString str;
	str.Format(_T("%d"),m_Program->m_w);
	GetDlgItem(IDC_EDIT3)->SetWindowText(str);
	str.Format(_T("%d"),m_Program->m_h);
	GetDlgItem(IDC_EDIT15)->SetWindowText(str);
	str.Format(_T("%d"),m_Program->m_play_time);
	if (m_Playmode==0)
	{
		GetDlgItem(IDC_EDIT2)->SetWindowText(str);
	} 
	else
	{
		GetDlgItem(IDC_EDIT8)->SetWindowText(str);
	}
	if (!m_Program->m_bDate)
	{
		CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
		btn->SetCheck(0);
	}
	else
	{
		CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
		btn->SetCheck(1);
		m_ctrlDate1.SetTime(&m_Program->m_aging_start_time);
		m_ctrlDate2.SetTime(&m_Program->m_aging_stop_time);
	}

	if (!m_Program->m_bTime)
	{
		CButton* btn=(CButton*)GetDlgItem(IDC_CHECK6);
		btn->SetCheck(0);
	}
	else
	{
		CButton* btn=(CButton*)GetDlgItem(IDC_CHECK6);
		btn->SetCheck(1);
		m_ctrlTime1.SetTime(&m_Program->m_period_ontime);
		m_ctrlTime2.SetTime(&m_Program->m_period_offtime);
	}
	UINT ids[]=
	{
		IDC_CHECK2,IDC_CHECK3,IDC_CHECK4,IDC_CHECK5,IDC_CHECK7,IDC_CHECK8,IDC_CHECK9,
	};
	for (int i=0;i<7;i++)
	{
		CButton* btn=(CButton*)GetDlgItem(ids[i]);
		btn->SetCheck(m_Program->m_play_week&(1<<i));
	}
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CProgramDlg::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	int index=pNMItemActivate->iItem;
	CString strType=m_ctrlAreaList.GetItemText(index,1);

	if (strType==_T("图文"))
	{
		PicArea* p=(PicArea*)m_vecArea[index];
		
		CImageAreaDlg dlg(p);
		dlg.DoModal();

	} 
	if (strType==_T("字幕"))
	{
		PicArea* p=(PicArea*)m_vecArea[index];
		
		CTextAreaDlg dlg(p);
		dlg.DoModal();
	} 
	if (strType==_T("时间"))
	{
		TimeArea* p=(TimeArea*)m_vecArea[index];
		
		CTimeAreaDlg dlg(p);
		dlg.DoModal();
	} 
	if (strType==_T("表盘"))
	{
		ClockArea* p=(ClockArea*)m_vecArea[index];
		
		CClockAreaDlg dlg(p);
		dlg.DoModal();
	} 	
	if (strType==_T("农历"))
	{
		LunarArea* p=(LunarArea*)m_vecArea[index];
		
		CLunarAreaDlg dlg(p);
		dlg.DoModal();

	} 
	if (strType==_T("计时"))
	{
		CounterArea* p=(CounterArea*)m_vecArea[index];
		
		CCounterAreaDlg dlg(p);
		dlg.DoModal();
	} 
	if (strType==_T("视频"))
	{
		VideoArea* p=(VideoArea*)m_vecArea[index];
		
		CVideoAreaDlg dlg(p);
		dlg.DoModal();
	} 
	*pResult = 0;
}


void CProgramDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	for (int i=0;i<m_Program->m_Arealist.size();i++)
	{
		delete m_Program->m_Arealist[i];
	}
	m_Program->m_Arealist.clear();
	CString str;
	GetDlgItem(IDC_EDIT3)->GetWindowText(str);
	m_Program->m_w=_tstoi(str);
	GetDlgItem(IDC_EDIT15)->GetWindowText(str);
	m_Program->m_h=_tstoi(str);
	m_Program->m_play_mode=m_Playmode;
	if (m_Playmode==0)
	{
		GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	} 
	else
	{
		GetDlgItem(IDC_EDIT8)->GetWindowText(str);
	}
	m_Program->m_play_time=_tstoi(str);
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);

	if (btn->GetCheck())
	{
		m_Program->m_bDate=true;
		m_ctrlDate1.GetTime(m_Program->m_aging_start_time);
		m_ctrlDate2.GetTime(m_Program->m_aging_stop_time);
	}
	else
	{
		m_Program->m_bDate=false;
		
	}
	btn=(CButton*)GetDlgItem(IDC_CHECK6);

	if (btn->GetCheck())
	{
		m_ctrlTime1.GetTime(m_Program->m_period_ontime);
		m_ctrlTime2.GetTime(m_Program->m_period_offtime);
		m_Program->m_bTime=true;
	}
	else
	{
		m_Program->m_bTime=false;

	}
	UINT ids[]=
	{
		IDC_CHECK2,IDC_CHECK3,IDC_CHECK4,IDC_CHECK5,IDC_CHECK7,IDC_CHECK8,IDC_CHECK9,
	};
	BYTE week=0;
	for (int i=0;i<7;i++)
	{
		CButton* btn=(CButton*)GetDlgItem(ids[i]);
		if (btn->GetCheck())
		{
			week+=(1<<i);
		}
	}
	m_Program->m_play_week=week;
	for (int index=0;index<m_ctrlAreaList.GetItemCount();index++)
	{
		m_Program->m_Arealist.push_back(m_vecArea[index]);
	}
	CDialogEx::OnOK();
}


void CProgramDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CProgramDlg::OnBnClickedCheck1()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
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


void CProgramDlg::OnBnClickedCheck6()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK6);
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
