// TextAreaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "TextAreaDlg.h"
#include "afxdialogex.h"

TCHAR* TXT_ShowMode[]=
{
	_T("快速打出		"),
	_T("随机			"),
	_T("静止显示		"),
	_T("向上推入		"),
	_T("向下推入		"),
	_T("向左推入		"),
	_T("向右推入		"),
	_T("向上连移		"),
	_T("向下连移		"),
	_T("向左连移		"),
	_T("向右连移		"),

};
extern TCHAR* PIC_ShowMode[];
// CTextAreaDlg 对话框

IMPLEMENT_DYNAMIC(CTextAreaDlg, CDialogEx)

CTextAreaDlg::CTextAreaDlg(PicArea* p,CWnd* pParent /*=NULL*/)
	: CDialogEx(CTextAreaDlg::IDD, pParent)
{
	m_pArea=p;
}

CTextAreaDlg::~CTextAreaDlg()
{
}

void CTextAreaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSlider);
	DDX_Control(pDX, IDC_COMBO1, m_cmbDisplayEffect);
	DDX_Control(pDX, IDC_LIST_UNIT, m_ctrlUnitList);
}


BEGIN_MESSAGE_MAP(CTextAreaDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTextAreaDlg::OnBnClickedOk)
	ON_LBN_SELCHANGE(IDC_LIST_UNIT, &CTextAreaDlg::OnLbnSelchangeListUnit)
	ON_BN_CLICKED(IDC_UNIT_REMOVE, &CTextAreaDlg::OnBnClickedUnitRemove)
	ON_BN_CLICKED(IDC_BUTTON3, &CTextAreaDlg::OnBnClickedButton3)
	ON_CBN_KILLFOCUS(IDC_COMBO1, &CTextAreaDlg::OnCbnKillfocusCombo1)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CTextAreaDlg::OnEnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT31, &CTextAreaDlg::OnEnKillfocusEdit31)
END_MESSAGE_MAP()


// CTextAreaDlg 消息处理程序


void CTextAreaDlg::OnBnClickedButton3()
{
	CFileDialog dlg(TRUE,_T("txt"),NULL,OFN_HIDEREADONLY|OFN_ALLOWMULTISELECT,_T("(*.txt;*.rtf;*.doc)|*.txt;*.rtf;*.doc||"));
	if(dlg.DoModal() == IDOK)
	{
		PicUnit unit;
		unit.bPic=false;
		_tcscpy_s(unit.szFile,dlg.GetPathName());
		unit.display_effects=1;
		unit.display_speed=1;
		unit.stay_time=1;
		m_vecUnit.push_back(unit);
		int item=m_ctrlUnitList.AddString(dlg.GetPathName());
		m_ctrlUnitList.SetCurSel(item);
		OnLbnSelchangeListUnit();
	}
}


void CTextAreaDlg::OnBnClickedUnitRemove()
{
	int index=m_ctrlUnitList.GetCurSel();
	if (index>=0)
	{
		m_vecUnit.erase(m_vecUnit.begin()+index);
		m_ctrlUnitList.DeleteString(index);
	}
}

void CTextAreaDlg::OnCbnKillfocusCombo1()
{
	int index=m_ctrlUnitList.GetCurSel();
	if (index>=0)
	{
		CString str;
		m_cmbDisplayEffect.GetWindowText(str);
		for (int i=0;i<48;i++)
		{
			if (str==PIC_ShowMode[i])
			{
				m_vecUnit[index].display_effects=i;
				break;
			}
		}
	}
}


void CTextAreaDlg::OnEnKillfocusEdit1()
{
	int index=m_ctrlUnitList.GetCurSel();
	if (index>=0)
	{
		CString str;
		GetDlgItem(IDC_EDIT1)->GetWindowText(str);
		m_vecUnit[index].display_speed=_tstoi(str);
	}
}


void CTextAreaDlg::OnEnKillfocusEdit31()
{
	int index=m_ctrlUnitList.GetCurSel();
	if (index>=0)
	{
		CString str;
		GetDlgItem(IDC_EDIT31)->GetWindowText(str);
		m_vecUnit[index].stay_time=_tstoi(str);
	}
}


void CTextAreaDlg::OnLbnSelchangeListUnit()
{
	int index=m_ctrlUnitList.GetCurSel();
	m_cmbDisplayEffect.SelectString(-1,PIC_ShowMode[m_vecUnit[index].display_effects]);
	CString str;
	str.Format(_T("%d"),m_vecUnit[index].display_speed);
	GetDlgItem(IDC_EDIT1)->SetWindowText(str);
	str.Format(_T("%d"),m_vecUnit[index].stay_time);
	GetDlgItem(IDC_EDIT31)->SetWindowText(str);
}
void CTextAreaDlg::OnBnClickedOk()
{
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

	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	m_pArea->m_bBgTransparent=btn->GetCheck();

	for (int i=0;i<m_vecUnit.size();i++)
	{
		m_pArea->m_Piclist[i]=m_vecUnit[i];
	}
	m_pArea->m_PicCount=m_vecUnit.size();
	CDialogEx::OnOK();
}


BOOL CTextAreaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	for (int i=0;i<11;i++)
	{
		m_cmbDisplayEffect.AddString(TXT_ShowMode[i]);
	}

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
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	btn->SetCheck(m_pArea->m_bBgTransparent);

	for (int i=0;i<m_pArea->m_PicCount;i++)
	{
		m_vecUnit.push_back(m_pArea->m_Piclist[i]);
		m_ctrlUnitList.AddString(m_pArea->m_Piclist[i].szFile);
	}
	if (m_vecUnit.size()>0)
	{
		m_ctrlUnitList.SetCurSel(0);
		OnLbnSelchangeListUnit();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
