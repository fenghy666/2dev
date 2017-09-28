// DynamicAreaDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "DynamicAreaDlg.h"
#include "afxdialogex.h"
#include "StrPageDlg.h"
#include "StrRefPageDlg.h"
#include "PicRefDlg.h"

extern TCHAR* PIC_ShowMode[];

// CDynamicAreaDlg 对话框

IMPLEMENT_DYNAMIC(CDynamicAreaDlg, CDialogEx)

CDynamicAreaDlg::CDynamicAreaDlg(char* ip,CWnd* pParent /*=NULL*/)
	: CDialogEx(CDynamicAreaDlg::IDD, pParent)
	, m_PlayRelation(0)
	, m_RunTime(0)
	, m_PageType(0)
	, m_X(0)
	, m_Y(0)
	, m_W(128)
	, m_H(96)
	, m_RelProgram(0)
{
	card_mode=0;
	memset(card_ip,0,sizeof(card_ip));
	strcpy(card_ip,ip);
}
CDynamicAreaDlg::CDynamicAreaDlg(unsigned char* pid,CWnd* pParent /*=NULL*/)
	: CDialogEx(CDynamicAreaDlg::IDD, pParent)
	, m_PlayRelation(0)
	, m_RunTime(0)
	, m_PageType(0)
	, m_X(0)
	, m_Y(0)
	, m_W(128)
	, m_H(96)
	, m_RelProgram(0)
{
	card_mode=1;
	memcpy(card_pid,pid,sizeof(card_pid));
}
CDynamicAreaDlg::~CDynamicAreaDlg()
{
}

void CDynamicAreaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, m_cmbRunMode);
	DDX_Control(pDX, IDC_COMBO1, m_cmbAreaId);
	DDX_Control(pDX, IDC_SLIDER1, m_ctrlSlider);
	DDX_Control(pDX, IDC_LIST1, m_PageList);
	DDX_Control(pDX, IDC_COMBO8, m_cmbDisplayEffect);
	DDX_Radio(pDX,IDC_RADIO1,m_PlayRelation);
	DDX_Radio(pDX,IDC_RADIO3,m_RunTime);
	DDX_Radio(pDX,IDC_RADIO5,m_PageType);
	DDX_Text(pDX,IDC_AREA_X,m_X);
	DDX_Text(pDX,IDC_AREA_Y,m_Y);
	DDX_Text(pDX,IDC_AREA_W,m_W);
	DDX_Text(pDX,IDC_AREA_H,m_H);
	DDX_Text(pDX,IDC_EDIT1,m_RelProgram);
}


BEGIN_MESSAGE_MAP(CDynamicAreaDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CDynamicAreaDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDynamicAreaDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_CHECK1, &CDynamicAreaDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_RADIO5, &CDynamicAreaDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO6, &CDynamicAreaDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_BUTTON6, &CDynamicAreaDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON5, &CDynamicAreaDlg::OnBnClickedButton5)
	ON_LBN_SELCHANGE(IDC_LIST1, &CDynamicAreaDlg::OnLbnSelchangeList1)
	ON_CBN_KILLFOCUS(IDC_COMBO8, &CDynamicAreaDlg::OnCbnKillfocusCombo8)
	ON_EN_KILLFOCUS(IDC_EDIT31, &CDynamicAreaDlg::OnEnKillfocusEdit31)
	ON_EN_KILLFOCUS(IDC_EDIT32, &CDynamicAreaDlg::OnEnKillfocusEdit32)
	ON_BN_CLICKED(IDC_BUTTON7, &CDynamicAreaDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_RADIO7, &CDynamicAreaDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO8, &CDynamicAreaDlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_BUTTON14, &CDynamicAreaDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON19, &CDynamicAreaDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON8, &CDynamicAreaDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CDynamicAreaDlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// CDynamicAreaDlg 消息处理程序


void CDynamicAreaDlg::OnBnClickedButton3()
{
	CFileDialog dlg(TRUE,_T("bmp"),NULL,OFN_HIDEREADONLY|OFN_ALLOWMULTISELECT,_T("(*.bmp;*.jpg;*.png;*.gif)|*.bmp;*.jpg;*.png;*.gif||"));
	if(dlg.DoModal() == IDOK)
	{
		DynaPicPage unit;
		
		_tcscpy_s(unit.szFile,dlg.GetPathName());
		unit.display_effects=1;
		unit.display_speed=1;
		unit.stay_time=1;
		m_vecPicPage.push_back(unit);
		int item=m_PageList.AddString(dlg.GetPathName());
		m_PageList.SetCurSel(item);
		OnLbnSelchangeList1();
	}
}


void CDynamicAreaDlg::OnBnClickedButton4()
{
	DynaStrPage *page=new DynaStrPage;
	page->display_effects=1;
	page->display_speed=1;
	page->stay_time=1;
	page->m_LineSpace=1;
	page->m_BgColor=RGB(0,0,0);
	page->m_bAntialiasing=false;
	page->m_font=_T("宋体");
	page->m_fontsize=12;
	page->m_bold=false;
	page->m_italic=false;
	page->m_underline=false;
	page->m_strike=false;
	page->szTxt.Empty();
	page->txtcolor=RGB(0,255,0);



	CStrPageDlg dlg(page);
	if (dlg.DoModal()==IDOK)
	{
		m_vecStrPage.push_back(page);
		CString str;
		str.Format(_T("%d"),m_vecStrPage.size());
		int item=m_PageList.AddString(str);
		m_PageList.SetCurSel(item);
		OnLbnSelchangeList1();
	}
}

void CDynamicAreaDlg::OnBnClickedButton14()
{

	DynaRefPicPage unit;
	memset(&unit,0,sizeof(unit));
	unit.display_effects=1;
	unit.display_speed=1;
	unit.stay_time=1;
	CPicRefDlg dlg(&unit);
	if (dlg.DoModal()==IDOK)
	{
		m_vecPicRefPage.push_back(unit);
		int item=m_PageList.AddString(unit.szFile);
		m_PageList.SetCurSel(item);
		OnLbnSelchangeList1();
	}

}


void CDynamicAreaDlg::OnBnClickedButton19()
{
	DynaStrRefPage *page=new DynaStrRefPage;

	page->display_effects=1;
	page->display_speed=1;
	page->stay_time=1;
	page->m_LineSpace=1;
	page->m_BgColor=RGB(0,0,0);
	page->m_bAntialiasing=false;
	page->m_font=_T("宋体");
	page->m_fontsize=12;
	page->m_bold=false;
	page->m_italic=false;
	page->m_underline=false;
	page->m_strike=false;
	page->szTxt.Empty();
	page->txtcolor=RGB(0,255,0);
	memset(page->user,0,sizeof(page->user));
	memset(page->pwd,0,sizeof(page->pwd));
	page->szTxt.Empty();

	CStrRefPageDlg dlg(page);
	if (dlg.DoModal()==IDOK)
	{
		m_vecStrRefPage.push_back(page);
		CString str;
		str.Format(_T("%d"),m_vecStrRefPage.size());
		int item=m_PageList.AddString(str);
		m_PageList.SetCurSel(item);
		OnLbnSelchangeList1();
	}
}

void CDynamicAreaDlg::OnBnClickedCheck1()
{
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	if (btn->GetCheck())
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIO1)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIO2)->EnableWindow(TRUE);
	} 
	else
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
	}
}


BOOL CDynamicAreaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_cmbRunMode.AddString(_T("循环显示"));
	m_cmbRunMode.AddString(_T("顺序显示,显示完最后一页后就不再显示"));
	m_cmbRunMode.AddString(_T("显示完成后静止显示最后一页数据"));
	m_cmbRunMode.AddString(_T("循环显示,超过设定时间后数据仍未更新时删除动态区信息"));
	m_cmbRunMode.AddString(_T("循环显示,超过设定时间后数据仍未更新时播放LOGO图片"));

	for (int i=0;i<48;i++)
	{
		m_cmbDisplayEffect.AddString(PIC_ShowMode[i]);
	}

	m_ctrlSlider.SetRange(0,255);
	m_ctrlSlider.SetPos(0);

	CString str;

	for (int i=0;i<32;i++)
	{
		CString str;
		str.Format(_T("%d"),i);
		m_cmbAreaId.AddString(str);
	}
	m_cmbAreaId.SetCurSel(0);
	m_cmbRunMode.SetCurSel(0);

	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO1)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T("5"));
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON19)->EnableWindow(FALSE);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDynamicAreaDlg::OnBnClickedRadio5()
{
	GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON19)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	m_PageList.ResetContent();
	m_vecPicPage.clear();
	m_vecStrPage.clear();
	m_vecPicRefPage.clear();
	m_vecStrRefPage.clear();
	m_PageType=0;
}


void CDynamicAreaDlg::OnBnClickedRadio6()
{
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON19)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(FALSE);
	m_PageList.ResetContent();
	m_vecPicPage.clear();
	m_vecStrPage.clear();
	m_vecPicRefPage.clear();
	m_vecStrRefPage.clear();
	m_PageType=1;
}


void CDynamicAreaDlg::OnBnClickedRadio7()
{
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(TRUE);
	GetDlgItem(IDC_BUTTON19)->EnableWindow(FALSE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
	m_PageList.ResetContent();
	m_vecPicPage.clear();
	m_vecStrPage.clear();
	m_vecPicRefPage.clear();
	m_vecStrRefPage.clear();
	m_PageType=2;
}


void CDynamicAreaDlg::OnBnClickedRadio8()
{
	GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON14)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON19)->EnableWindow(TRUE);
	GetDlgItem(IDC_EDIT2)->EnableWindow(TRUE);
	m_PageList.ResetContent();
	m_vecPicPage.clear();
	m_vecStrPage.clear();
	m_vecPicRefPage.clear();
	m_vecStrRefPage.clear();
	m_PageType=3;
}

void CDynamicAreaDlg::OnBnClickedButton6()
{
	UpdateData(TRUE);
	// update
	USHORT RelatedProgram=0xffff;
	CButton* btn=(CButton*)GetDlgItem(IDC_CHECK1);
	if (btn->GetCheck())
	{
		RelatedProgram=m_RelProgram;
	} 
	CString freq;
	GetDlgItem(IDC_EDIT2)->GetWindowText(freq);
	int iFreq=_tstoi(freq);
	DWORD hDynamicArea=YQ_CreateDynamicArea(m_cmbAreaId.GetCurSel(),m_X,m_Y,m_W,m_H,255-m_ctrlSlider.GetPos(),m_PlayRelation,RelatedProgram,m_RunTime,m_cmbRunMode.GetCurSel(),5,m_PageType,iFreq);
	switch (m_PageType)
	{
	case 0:
	{
		for (int j=0;j<m_vecPicPage.size();j++)
		{
			HANDLE hFile =	::CreateFile(m_vecPicPage[j].szFile, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);
			if (hFile == INVALID_HANDLE_VALUE)
			{
				return ;
			}
			DWORD fz = GetFileSize(hFile, NULL);
			BYTE* buff=new BYTE[fz];
			DWORD RSize=0;
			ReadFile(hFile, buff, fz, &RSize, NULL);
			CloseHandle(hFile);
			CString str=m_vecPicPage[j].szFile;
			int pos=str.ReverseFind(L'.');
			str=str.Right(str.GetLength()-pos);
			char suffix[10]={0};
			CString2Char(str,suffix);
			YQ_DynamicAreaAddPicPage(hDynamicArea,m_vecPicPage[j].stay_time,m_vecPicPage[j].display_effects,m_vecPicPage[j].display_speed,suffix,fz,buff);
			delete buff;
		}
		break;
	} 
	case 1:
	{
		for (int j=0;j<m_vecStrPage.size();j++)
		{
			DynaStrPage* page=m_vecStrPage[j];
			YQ_DynamicAreaAddStrPage(hDynamicArea,page->stay_time,page->display_effects,page->display_speed,page->m_BgColor,page->m_LineSpace,page->m_bold,page->m_italic,page->m_underline,page->m_strike,page->m_bAntialiasing,page->szTxt,page->txtcolor,page->m_font,page->m_fontsize);
			
		}
		break;
	}
	case 2:
		{
			for (int j=0;j<m_vecPicRefPage.size();j++)
			{
				char url[MAX_PATH]={0};
				CString str=m_vecPicRefPage[j].szFile;
				CString2Char(str,url);
				int pos=str.ReverseFind(L'.');
				str=str.Right(str.GetLength()-pos);
				char suffix[10]={0};
				CString2Char(str,suffix);
				char user[16]={0};
				str=m_vecPicRefPage[j].user;
				CString2Char(str,user);
				char pwd[16]={0};
				str=m_vecPicRefPage[j].pwd;
				CString2Char(str,pwd);
				YQ_DynamicAreaAddPicRefPage(hDynamicArea,m_vecPicRefPage[j].stay_time,m_vecPicRefPage[j].display_effects,m_vecPicRefPage[j].display_speed,suffix,user,pwd,url);
				
			}
			break;
		} 
	case 3:
		{
			for (int j=0;j<m_vecStrRefPage.size();j++)
			{
				char url[MAX_PATH]={0};
				CString str=m_vecStrRefPage[j]->szTxt;
				CString2Char(str,url);

				char user[16]={0};
				str=m_vecStrRefPage[j]->user;
				CString2Char(str,user);
				char pwd[16]={0};
				str=m_vecStrRefPage[j]->pwd;
				CString2Char(str,pwd);
				YQ_DynamicAreaAddStrRefPage(hDynamicArea,m_vecStrRefPage[j]->stay_time,m_vecStrRefPage[j]->display_effects,m_vecStrRefPage[j]->display_speed,1,m_vecStrRefPage[j]->m_BgColor,m_vecStrRefPage[j]->m_LineSpace,user,pwd,url);

			}
		}
	}
	int err=0;
	if (card_mode==0)
	{
		err=Net_UpdateDynamicArea(card_ip,hDynamicArea);
	} 
	else
	{
		err=Server_UpdateDynamicArea(card_pid,hDynamicArea);

	}
	YQ_DestroyDynamic(hDynamicArea);
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
		return;
	}
}


void CDynamicAreaDlg::OnBnClickedButton5()
{
	int index=m_PageList.GetCurSel();
	if (index>=0)
	{
		if (m_PageType==0)
		{
			m_vecPicPage.erase(m_vecPicPage.begin()+index);
			m_PageList.DeleteString(index);
		} 
		else if(m_PageType==1)
		{
			DynaStrPage* page=m_vecStrPage[index];
			delete page;
			m_vecStrPage.erase(m_vecStrPage.begin()+index);
			m_PageList.DeleteString(index);
		}
		else if(m_PageType==2)
		{
			m_vecPicRefPage.erase(m_vecPicRefPage.begin()+index);
			m_PageList.DeleteString(index);
		}
		else if(m_PageType==3)
		{
			DynaStrRefPage* page=m_vecStrRefPage[index];
			delete page;
			m_vecStrRefPage.erase(m_vecStrRefPage.begin()+index);
			m_PageList.DeleteString(index);
		}
	}
}


void CDynamicAreaDlg::OnLbnSelchangeList1()
{
	int index=m_PageList.GetCurSel();
	if (m_PageType==0)
	{
		m_cmbDisplayEffect.SetCurSel(m_vecPicPage[index].display_effects);
		CString str;
		str.Format(_T("%d"),m_vecPicPage[index].display_speed);
		GetDlgItem(IDC_EDIT31)->SetWindowText(str);
		str.Format(_T("%d"),m_vecPicPage[index].stay_time);
		GetDlgItem(IDC_EDIT32)->SetWindowText(str);
	} 
	else if(m_PageType==1)
	{
		m_cmbDisplayEffect.SetCurSel(m_vecStrPage[index]->display_effects);
		CString str;
		str.Format(_T("%d"),m_vecStrPage[index]->display_speed);
		GetDlgItem(IDC_EDIT31)->SetWindowText(str);
		str.Format(_T("%d"),m_vecStrPage[index]->stay_time);
		GetDlgItem(IDC_EDIT32)->SetWindowText(str);
	}
	else if(m_PageType==2)
	{
		m_cmbDisplayEffect.SetCurSel(m_vecPicRefPage[index].display_effects);
		CString str;
		str.Format(_T("%d"),m_vecPicRefPage[index].display_speed);
		GetDlgItem(IDC_EDIT31)->SetWindowText(str);
		str.Format(_T("%d"),m_vecPicRefPage[index].stay_time);
		GetDlgItem(IDC_EDIT32)->SetWindowText(str);
	}
	else if(m_PageType==3)
	{
		m_cmbDisplayEffect.SetCurSel(m_vecStrRefPage[index]->display_effects);
		CString str;
		str.Format(_T("%d"),m_vecStrRefPage[index]->display_speed);
		GetDlgItem(IDC_EDIT31)->SetWindowText(str);
		str.Format(_T("%d"),m_vecStrRefPage[index]->stay_time);
		GetDlgItem(IDC_EDIT32)->SetWindowText(str);
	}
}


void CDynamicAreaDlg::OnCbnKillfocusCombo8()
{
	int index=m_PageList.GetCurSel();
	if (index>=0)
	{
		switch(m_PageType)
		{
		case 0:
			{
				m_vecPicPage[index].display_effects=m_cmbDisplayEffect.GetCurSel();
				break;
			}
		case 1:
			{
				m_vecStrPage[index]->display_effects=m_cmbDisplayEffect.GetCurSel();
				break;
			}
		case 2:
			{
				m_vecPicRefPage[index].display_effects=m_cmbDisplayEffect.GetCurSel();
				break;
			}
		case 3:
			{
				m_vecStrRefPage[index]->display_effects=m_cmbDisplayEffect.GetCurSel();
				break;
			}
		}

	}
}


void CDynamicAreaDlg::OnEnKillfocusEdit31()
{
	int index=m_PageList.GetCurSel();
	if (index>=0)
	{
		switch (m_PageType)
		{
		case 0:
			{
				CString str;
				GetDlgItem(IDC_EDIT31)->GetWindowText(str);
				m_vecPicPage[index].stay_time=_tstoi(str);
				break;
			}
		case 1:
			{
				CString str;
				GetDlgItem(IDC_EDIT31)->GetWindowText(str);
				m_vecStrPage[index]->stay_time=_tstoi(str);
				break;
			}
		case 2:
			{
				CString str;
				GetDlgItem(IDC_EDIT31)->GetWindowText(str);
				m_vecPicRefPage[index].stay_time=_tstoi(str);
				break;
			}
		case 3:
			{
				CString str;
				GetDlgItem(IDC_EDIT31)->GetWindowText(str);
				m_vecStrRefPage[index]->stay_time=_tstoi(str);
				break;
			}
		}

	}
}


void CDynamicAreaDlg::OnEnKillfocusEdit32()
{
	int index=m_PageList.GetCurSel();
	if (index>=0)
	{
		switch (m_PageType)
		{
		case 0:
		{
			CString str;
			GetDlgItem(IDC_EDIT32)->GetWindowText(str);
			m_vecPicPage[index].stay_time=_tstoi(str);
			break;
		}
		case 1:
		{
			CString str;
			GetDlgItem(IDC_EDIT32)->GetWindowText(str);
			m_vecStrPage[index]->stay_time=_tstoi(str);
			break;
		}
		case 2:
			{
				CString str;
				GetDlgItem(IDC_EDIT32)->GetWindowText(str);
				m_vecPicRefPage[index].stay_time=_tstoi(str);
				break;
			}
		case 3:
			{
				CString str;
				GetDlgItem(IDC_EDIT32)->GetWindowText(str);
				m_vecStrRefPage[index]->stay_time=_tstoi(str);
				break;
			}
		}

	}
}


void CDynamicAreaDlg::OnBnClickedButton7()
{
	int err=0;
	if (card_mode==0)
	{
		err=Net_RemoveDynamicArea(card_ip,m_cmbAreaId.GetCurSel());
	} 
	else
	{
		err=Server_RemoveDynamicArea(card_pid,m_cmbAreaId.GetCurSel());
	}
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
		return;
	}
}


void CDynamicAreaDlg::OnBnClickedButton8()
{
	int err=0;
	if (card_mode==0)
	{
		err=Net_SaveDynamicArea(card_ip,m_cmbAreaId.GetCurSel());
	} 
	else
	{
		err=Server_SaveDynamicArea(card_pid,m_cmbAreaId.GetCurSel());
	}
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
		return;
	}
}


void CDynamicAreaDlg::OnBnClickedButton9()
{
	int err=0;
	if (card_mode==0)
	{
		err=Net_DelSaveDynamicArea(card_ip);
	} 
	else
	{
		err=Server_DelSaveDynamicArea(card_pid);
	}
	if (err!=0)
	{
		AfxMessageBox(GetErrText(err));
		return;
	}
}
