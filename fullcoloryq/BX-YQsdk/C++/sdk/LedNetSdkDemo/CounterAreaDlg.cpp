// CounterAreaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "CounterAreaDlg.h"
#include "afxdialogex.h"


// CCounterAreaDlg 对话框

IMPLEMENT_DYNAMIC(CCounterAreaDlg, CDialogEx)

CCounterAreaDlg::CCounterAreaDlg(CounterArea* p,CWnd* pParent /*=NULL*/)
	: CDialogEx(CCounterAreaDlg::IDD, pParent)
	, m_bMultiLine(0)
{
	m_pArea=p;
}

CCounterAreaDlg::~CCounterAreaDlg()
{
}

void CCounterAreaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_ctrlDate);
	DDX_Control(pDX, IDC_DATETIMEPICKER2, m_ctrlTime);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_btnCounter);
	DDX_Control(pDX, IDC_MFCFONTCOMBO1, m_cmbFont);
	DDX_Radio(pDX,IDC_RADIO1,m_bMultiLine);
	DDX_Control(pDX, IDC_COMBO5, m_cmbAlign);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, m_btnText);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSlider);
}


BEGIN_MESSAGE_MAP(CCounterAreaDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCounterAreaDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, &CCounterAreaDlg::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CCounterAreaDlg 消息处理程序


void CCounterAreaDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	m_pArea->m_transparency=255-m_ctrlSlider.GetPos();
	CString str;
	GetDlgItem(IDC_AREA_X)->GetWindowText(str);
	m_pArea->m_x=_tstoi(str);

	GetDlgItem(IDC_AREA_Y)->GetWindowText(str);
	m_pArea->m_y=_tstoi(str);

	GetDlgItem(IDC_AREA_W)->GetWindowText(str);
	m_pArea->m_w=_tstoi(str);

	GetDlgItem(IDC_AREA_H)->GetWindowText(str);
	m_pArea->m_h=_tstoi(str);


	m_pArea->m_multiline=m_bMultiLine;
	_tcscpy_s(m_pArea->m_font,m_cmbFont.GetSelFont()->m_strName);

	GetDlgItem(IDC_EDIT15)->GetWindowText(str);
	m_pArea->m_fontsize=_tstoi(str);

	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK2);
	m_pArea->m_bold=btn->GetCheck();
	btn=(CButton*)GetDlgItem(IDC_CHECK3);
	m_pArea->m_italic=btn->GetCheck();
	btn=(CButton*)GetDlgItem(IDC_CHECK4);
	m_pArea->m_underline=btn->GetCheck();

	m_pArea->m_align=m_cmbAlign.GetCurSel();

	btn=(CButton*)GetDlgItem(IDC_CHECK7);
	m_pArea->m_day_enable=btn->GetCheck();
	if (m_pArea->m_day_enable)
	{
		_tcscpy_s(m_pArea->m_daytext,_T("天"));
	}
	btn=(CButton*)GetDlgItem(IDC_CHECK8);
	m_pArea->m_hour_enable=btn->GetCheck();
	if (m_pArea->m_hour_enable)
	{
		_tcscpy_s(m_pArea->m_hourtext,_T("小时"));
	}
	btn=(CButton*)GetDlgItem(IDC_CHECK9);
	m_pArea->m_min_enable=btn->GetCheck();
	if (m_pArea->m_min_enable)
	{
		_tcscpy_s(m_pArea->m_minutetext,_T("分"));
	}
	btn=(CButton*)GetDlgItem(IDC_CHECK12);
	m_pArea->m_sec_enable=btn->GetCheck();
	if (m_pArea->m_sec_enable)
	{
		_tcscpy_s(m_pArea->m_secondtext,_T("秒"));
	}

	btn=(CButton*)GetDlgItem(IDC_CHECK1);
	m_pArea->m_text_enable=btn->GetCheck();
	if (m_pArea->m_text_enable)
	{
		GetDlgItem(IDC_EDIT1)->GetWindowText(m_pArea->m_statictext,sizeof(m_pArea->m_statictext));
		m_pArea->m_textcolor=m_btnText.GetColor();
	} 
	CTime t;
	m_ctrlDate.GetTime(t);
	CString strTime=t.Format("%Y-%m-%d");
	::lstrcpy(m_pArea->m_target_date,(LPCTSTR)strTime);
	m_ctrlTime.GetWindowText(m_pArea->m_target_time,sizeof(m_pArea->m_target_time));
	CTime tmDate,tmTime;
	m_ctrlDate.GetTime(tmDate);
	m_ctrlTime.GetTime(tmTime);
	btn=(CButton*)GetDlgItem(IDC_CHECK5);
	m_pArea->m_add_enable=btn->GetCheck();
	if (CTime(tmDate.GetYear(),tmDate.GetMonth(),tmDate.GetDay(),tmTime.GetHour(),tmTime.GetMinute(),tmTime.GetSecond())>CTime::GetCurrentTime())
	{
		m_pArea->m_bTimeFlag=0;
	} 
	else
	{
		m_pArea->m_bTimeFlag=1;
	}
	
	m_pArea->m_counter_color=m_btnCounter.GetColor();
	if (m_pArea->m_day_enable||m_pArea->m_sec_enable||m_pArea->m_min_enable||m_pArea->m_hour_enable)
	{
		m_pArea->m_unit_enable=true;
	}
	else
	{
		m_pArea->m_unit_enable=false;
	}
	CDialogEx::OnOK();
}


BOOL CCounterAreaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	m_ctrlSlider.SetRange(0,255);
	m_ctrlSlider.SetPos(255-m_pArea->m_transparency);

	CString str;
	str.Format(_T("%d"),m_pArea->m_x);
	GetDlgItem(IDC_AREA_X)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_y);
	GetDlgItem(IDC_AREA_Y)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_w);
	GetDlgItem(IDC_AREA_W)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_h);
	GetDlgItem(IDC_AREA_H)->SetWindowText(str);

	m_bMultiLine=m_pArea->m_multiline;
	m_cmbFont.SelectFont(m_pArea->m_font);
	str.Format(_T("%d"),m_pArea->m_fontsize);
	GetDlgItem(IDC_EDIT15)->SetWindowText(str);

	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK2);
	btn->SetCheck(m_pArea->m_bold);
	btn=(CButton*)GetDlgItem(IDC_CHECK3);
	btn->SetCheck(m_pArea->m_italic);
	btn=(CButton*)GetDlgItem(IDC_CHECK4);
	btn->SetCheck(m_pArea->m_underline);

	m_cmbAlign.SetCurSel(m_pArea->m_align);

	btn=(CButton*)GetDlgItem(IDC_CHECK1);
	btn->SetCheck(m_pArea->m_text_enable);
	if (m_pArea->m_text_enable)
	{
		GetDlgItem(IDC_EDIT1)->SetWindowText(m_pArea->m_statictext);
		m_btnText.SetColor(m_pArea->m_textcolor);
	} 
	else
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		m_btnText.EnableWindow(FALSE);
	}

	m_ctrlDate.SetWindowText(m_pArea->m_target_date);
	m_ctrlTime.SetWindowText(m_pArea->m_target_time);

	btn=(CButton*)GetDlgItem(IDC_CHECK5);
	btn->SetCheck(m_pArea->m_add_enable);
	m_btnCounter.SetColor(m_pArea->m_counter_color);

	btn=(CButton*)GetDlgItem(IDC_CHECK7);
	btn->SetCheck(m_pArea->m_day_enable);

	btn=(CButton*)GetDlgItem(IDC_CHECK8);
	btn->SetCheck(m_pArea->m_hour_enable);

	btn=(CButton*)GetDlgItem(IDC_CHECK9);
	btn->SetCheck(m_pArea->m_min_enable);

	btn=(CButton*)GetDlgItem(IDC_CHECK12);
	btn->SetCheck(m_pArea->m_sec_enable);


	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CCounterAreaDlg::OnBnClickedCheck1()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);

	if (btn->GetCheck())
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
		m_btnText.EnableWindow(TRUE);
	} 
	else
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		m_btnText.EnableWindow(FALSE);
	}
}
