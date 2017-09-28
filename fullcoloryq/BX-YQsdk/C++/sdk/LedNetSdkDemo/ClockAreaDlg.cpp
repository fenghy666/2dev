// ClockAreaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "ClockAreaDlg.h"
#include "afxdialogex.h"


// CClockAreaDlg 对话框

IMPLEMENT_DYNAMIC(CClockAreaDlg, CDialogEx)

CClockAreaDlg::CClockAreaDlg(ClockArea* p,CWnd* pParent /*=NULL*/)
	: CDialogEx(CClockAreaDlg::IDD, pParent)
{
	m_pArea=p;
}

CClockAreaDlg::~CClockAreaDlg()
{
}

void CClockAreaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCFONTCOMBO1, m_cmbFont);
	DDX_Control(pDX, IDC_COMBO3, m_cmbStyle);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_btnDate);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON2, m_btnWeek);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON4, m_btnText);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON3, m_btnHourPt);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON5, m_btnMinPt);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON6, m_btnQuarterPt);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON7, m_btnHour);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON8, m_btnMin);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON9, m_btnSec);
	DDX_Control(pDX, IDC_COMBO2, m_cmbFlag);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSlider);
}


BEGIN_MESSAGE_MAP(CClockAreaDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CClockAreaDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, &CClockAreaDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK10, &CClockAreaDlg::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK13, &CClockAreaDlg::OnBnClickedCheck13)
END_MESSAGE_MAP()


// CClockAreaDlg 消息处理程序


void CClockAreaDlg::OnBnClickedOk()
{
	UpdateData(TRUE);
	m_pArea->m_transparency=2555-m_ctrlSlider.GetPos();
	CString str;
	GetDlgItem(IDC_AREA_X)->GetWindowText(str);
	m_pArea->m_x=_tstoi(str);

	GetDlgItem(IDC_AREA_Y)->GetWindowText(str);
	m_pArea->m_y=_tstoi(str);

	GetDlgItem(IDC_AREA_W)->GetWindowText(str);
	m_pArea->m_w=_tstoi(str);

	GetDlgItem(IDC_AREA_H)->GetWindowText(str);
	m_pArea->m_h=_tstoi(str);

	m_pArea->m_timediff_flag=m_cmbFlag.GetCurSel();
	GetDlgItem(IDC_EDIT2)->GetWindowText(str);
	m_pArea->m_timediff_hour=_tstoi(str);
	GetDlgItem(IDC_EDIT63)->GetWindowText(str);
	m_pArea->m_timediff_min=_tstoi(str);


	_tcscpy_s(m_pArea->m_font,m_cmbFont.GetSelFont()->m_strName);

	GetDlgItem(IDC_EDIT15)->GetWindowText(str);
	m_pArea->m_fontsize=_tstoi(str);

	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK2);
	m_pArea->m_bold=btn->GetCheck();
	btn=(CButton*)GetDlgItem(IDC_CHECK3);
	m_pArea->m_italic=btn->GetCheck();
	btn=(CButton*)GetDlgItem(IDC_CHECK4);
	m_pArea->m_underline=btn->GetCheck();



	btn=(CButton*)GetDlgItem(IDC_CHECK1);
	m_pArea->m_day_enable=btn->GetCheck();
	if (m_pArea->m_day_enable)
	{
		m_pArea->m_daycolor=m_btnDate.GetColor();
	} 

	btn=(CButton*)GetDlgItem(IDC_CHECK10);
	m_pArea->m_week_enable=btn->GetCheck();
	if (m_pArea->m_week_enable)
	{
		m_pArea->m_weekcolor=m_btnWeek.GetColor();
	} 



	btn=(CButton*)GetDlgItem(IDC_CHECK13);
	m_pArea->m_text_enable=btn->GetCheck();
	if (m_pArea->m_text_enable)
	{
		GetDlgItem(IDC_EDIT1)->GetWindowText(m_pArea->m_statictext,sizeof(m_pArea->m_statictext));
		m_pArea->m_textcolor=m_btnText.GetColor();
	} 
	m_pArea->m_style=m_cmbStyle.GetCurSel();
	m_pArea->m_hour_color=m_btnHourPt.GetColor();
	m_pArea->m_rightangle_color=m_btnQuarterPt.GetColor();
	m_pArea->m_minute_color=m_btnMinPt.GetColor();
	m_pArea->m_hourhand_color=m_btnHour.GetColor();
	m_pArea->m_minhand_color=m_btnMin.GetColor();
	m_pArea->m_secondhand_color=m_btnSec.GetColor();
	CDialogEx::OnOK();
}


BOOL CClockAreaDlg::OnInitDialog()
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

	m_cmbFlag.SetCurSel(m_pArea->m_timediff_flag);
	str.Format(_T("%d"),m_pArea->m_timediff_hour);
	GetDlgItem(IDC_EDIT2)->SetWindowText(str);
	str.Format(_T("%d"),m_pArea->m_timediff_min);
	GetDlgItem(IDC_EDIT63)->SetWindowText(str);

	m_cmbFont.SelectFont(m_pArea->m_font);
	str.Format(_T("%d"),m_pArea->m_fontsize);
	GetDlgItem(IDC_EDIT15)->SetWindowText(str);

	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK2);
	btn->SetCheck(m_pArea->m_bold);
	btn=(CButton*)GetDlgItem(IDC_CHECK3);
	btn->SetCheck(m_pArea->m_italic);
	btn=(CButton*)GetDlgItem(IDC_CHECK4);
	btn->SetCheck(m_pArea->m_underline);



	btn=(CButton*)GetDlgItem(IDC_CHECK1);
	btn->SetCheck(m_pArea->m_day_enable);
	if (m_pArea->m_day_enable)
	{
		m_btnDate.SetColor(m_pArea->m_daycolor);
	} 
	else
	{
		m_btnDate.EnableWindow(FALSE);
	}
	btn=(CButton*)GetDlgItem(IDC_CHECK10);
	btn->SetCheck(m_pArea->m_week_enable);
	if (m_pArea->m_week_enable)
	{
		m_btnWeek.SetColor(m_pArea->m_weekcolor);
	} 
	else
	{
		m_btnWeek.EnableWindow(FALSE);
	}

	btn=(CButton*)GetDlgItem(IDC_CHECK13);
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
	m_cmbStyle.SetCurSel(m_pArea->m_style);
	m_btnHourPt.SetColor(m_pArea->m_hour_color);
	m_btnQuarterPt.SetColor(m_pArea->m_rightangle_color);
	m_btnMinPt.SetColor(m_pArea->m_minute_color);
	m_btnHour.SetColor(m_pArea->m_hourhand_color);
	m_btnMin.SetColor(m_pArea->m_minhand_color);
	m_btnSec.SetColor(m_pArea->m_secondhand_color);
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CClockAreaDlg::OnBnClickedCheck1()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_MFCCOLORBUTTON1)->EnableWindow(TRUE);
	} 
	else
	{
		GetDlgItem(IDC_MFCCOLORBUTTON1)->EnableWindow(FALSE);
	}
}


void CClockAreaDlg::OnBnClickedCheck10()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK10);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_MFCCOLORBUTTON2)->EnableWindow(TRUE);
	} 
	else
	{
		GetDlgItem(IDC_MFCCOLORBUTTON2)->EnableWindow(FALSE);
	}
}


void CClockAreaDlg::OnBnClickedCheck13()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
		GetDlgItem(IDC_MFCCOLORBUTTON4)->EnableWindow(TRUE);
	} 
	else
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		GetDlgItem(IDC_MFCCOLORBUTTON4)->EnableWindow(FALSE);
	}
}
