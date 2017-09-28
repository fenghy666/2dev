// VideoAreaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "VideoAreaDlg.h"
#include "afxdialogex.h"


// CVideoAreaDlg 对话框

IMPLEMENT_DYNAMIC(CVideoAreaDlg, CDialogEx)

CVideoAreaDlg::CVideoAreaDlg(VideoArea* p,CWnd* pParent /*=NULL*/)
	: CDialogEx(CVideoAreaDlg::IDD, pParent)
{
	m_pArea=p;
}

CVideoAreaDlg::~CVideoAreaDlg()
{
}

void CVideoAreaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSlider);
	DDX_Control(pDX, IDC_COMBO1, m_cmbDisplayScale);
	DDX_Control(pDX, IDC_LIST_UNIT, m_ctrlUnitList);
	DDX_Control(pDX, IDC_SLIDER2, m_VolumeSlider);
}


BEGIN_MESSAGE_MAP(CVideoAreaDlg, CDialogEx)
	ON_BN_CLICKED(IDC_UNIT_ADD, &CVideoAreaDlg::OnBnClickedUnitAdd)
	ON_BN_CLICKED(IDC_UNIT_REMOVE, &CVideoAreaDlg::OnBnClickedUnitRemove)
	ON_CBN_KILLFOCUS(IDC_COMBO1, &CVideoAreaDlg::OnCbnKillfocusCombo1)
	ON_BN_CLICKED(IDOK, &CVideoAreaDlg::OnBnClickedOk)
	ON_LBN_SELCHANGE(IDC_LIST_UNIT, &CVideoAreaDlg::OnLbnSelchangeListUnit)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER2, &CVideoAreaDlg::OnNMReleasedcaptureSlider2)
END_MESSAGE_MAP()


// CVideoAreaDlg 消息处理程序


void CVideoAreaDlg::OnBnClickedUnitAdd()
{
	CFileDialog dlg(TRUE,_T("mp4"),NULL,OFN_HIDEREADONLY|OFN_ALLOWMULTISELECT,_T("(*.mp4)|*.mp4||"));
	if(dlg.DoModal() == IDOK)
	{
		VideoUnit unit;
		_tcscpy_s(unit.szVideoFile,dlg.GetPathName());
		unit.scale_mode=1;
		unit.volume=50;
		m_vecUnit.push_back(unit);
		int item=m_ctrlUnitList.AddString(dlg.GetPathName());
		m_ctrlUnitList.SetCurSel(item);
		OnLbnSelchangeListUnit();
	}
}


BOOL CVideoAreaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_cmbDisplayScale.AddString(_T("原始比例"));
	m_cmbDisplayScale.AddString(_T("窗口比例"));
	m_VolumeSlider.SetRange(0,100);

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

	for (int i=0;i<m_pArea->m_VideoCount;i++)
	{
		m_vecUnit.push_back(m_pArea->m_Videolist[i]);
		m_ctrlUnitList.AddString(m_pArea->m_Videolist[i].szVideoFile);
	}
	if (m_vecUnit.size()>0)
	{
		m_ctrlUnitList.SetCurSel(0);
		OnLbnSelchangeListUnit();
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CVideoAreaDlg::OnBnClickedUnitRemove()
{
	int index=m_ctrlUnitList.GetCurSel();
	if (index>=0)
	{
		m_vecUnit.erase(m_vecUnit.begin()+index);
		m_ctrlUnitList.DeleteString(index);
	}
}


void CVideoAreaDlg::OnCbnKillfocusCombo1()
{
	int index=m_ctrlUnitList.GetCurSel();
	if (index>=0)
	{
		m_vecUnit[index].scale_mode=m_cmbDisplayScale.GetCurSel();
	}
}



void CVideoAreaDlg::OnBnClickedOk()
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


	for (int i=0;i<m_vecUnit.size();i++)
	{
		m_pArea->m_Videolist[i]=m_vecUnit[i];
	}
	m_pArea->m_VideoCount=m_vecUnit.size();
	CDialogEx::OnOK();
}


void CVideoAreaDlg::OnLbnSelchangeListUnit()
{
	int index=m_ctrlUnitList.GetCurSel();
	m_cmbDisplayScale.SetCurSel(m_vecUnit[index].scale_mode);
	m_VolumeSlider.SetPos(m_vecUnit[index].volume);
}


void CVideoAreaDlg::OnNMReleasedcaptureSlider2(NMHDR *pNMHDR, LRESULT *pResult)
{
		int index=m_ctrlUnitList.GetCurSel();
	if (index>=0)
	{
		m_vecUnit[index].volume=m_VolumeSlider.GetPos();
	}
	*pResult = 0;
}
