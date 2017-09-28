
// LedNetSdkDemo.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号



// CLedNetSdkDemoApp:
// 有关此类的实现，请参阅 LedNetSdkDemo.cpp
//

class CLedNetSdkDemoApp : public CWinApp
{
public:
	CLedNetSdkDemoApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
public:
	char ftp_server_ip[16];
	USHORT ftp_server_port;
	char ftp_server_user[64];
	char ftp_server_pwd[64];
	bool m_bServerRun;
};

extern CLedNetSdkDemoApp theApp;
//////////////////////////////////////////////////////////////////////////
//功能：  转换通用字符串为ansi字符串
//参数：
//        pwstr：源字符串
//        str：目标字符串
//Example:
//        
//////////////////////////////////////////////////////////////////////////

void Char2TCHAR(TCHAR *pwstr,size_t len,const char *str);
void CString2Char(CString str, char ch[]);

CString GetErrText(int err);


#include <vector>
using namespace std;

struct PicUnit
{
	TCHAR szFile[MAX_PATH];
	UCHAR display_effects;
	UCHAR display_speed;
	USHORT stay_time;
	bool bPic;
};
struct VideoUnit
{
	TCHAR szVideoFile[MAX_PATH];
	UCHAR scale_mode;
	UCHAR volume;
};

class Area
{
public:
	Area(){}
	virtual ~Area(){};
public:
	int m_AreaType;
};
class VideoArea:public Area
{
public:
	VideoArea(int type){m_AreaType=type;}
	virtual ~VideoArea(){};
	short m_x;
	short m_y;
	short m_w;
	short m_h;
	UCHAR m_transparency;
	struct VideoUnit m_Videolist[256];
	int m_VideoCount;
};


class PicArea:public Area
{
public:
	PicArea(int type){m_AreaType=type;}
	virtual ~PicArea(){};
	short m_x;
	short m_y;
	short m_w;
	short m_h;
	UCHAR m_transparency;
	UCHAR m_window_type;
	bool  m_bBgTransparent;
	PicUnit m_Piclist[256];
	int m_PicCount;
};


class TimeArea:public Area
{
public:
	TimeArea(int type){m_AreaType=type;}
	virtual ~TimeArea(){};
	short m_x;
	short m_y;
	short m_w;
	short m_h;
	UCHAR m_transparency;
	UCHAR m_timediff_flag;
	UCHAR m_timediff_hour;
	UCHAR m_timediff_min;
	TCHAR m_font[32];
	UCHAR   m_fontsize;
	bool m_bold;
	bool m_italic;
	bool m_underline;
	UCHAR m_align;
	bool m_multiline;
	bool m_day_enable;
	UINT m_daycolor;

	bool m_week_enable;
	UINT m_weekcolor;

	bool m_time_enable;
	UINT m_timecolor;

	bool m_text_enable;
	UINT m_textcolor;
	TCHAR m_statictext[256];
};

class LunarArea:public Area
{
public:
	LunarArea(int type){m_AreaType=type;}
	virtual ~LunarArea(){};
	short		m_x;
	short		m_y;
	short		m_w;
	short		m_h;
	UCHAR		m_transparency;
	TCHAR		m_font[32];
	UCHAR		m_fontsize;
	bool		m_bold;
	bool		m_italic;
	bool		m_underline;
	UCHAR		m_align;
	bool		m_multiline;
	bool		m_year_enable;
	UINT		m_yearcolor;
	bool		m_day_enable;
	UINT		m_daycolor;
	bool		m_solarterms_enable;
	UINT		m_solartermscolor;
	bool		m_text_enable;
	UINT		m_textcolor;
	TCHAR		m_statictext[256];

};

class CounterArea:public Area
{
public:
	CounterArea(int type){m_AreaType=type;}
	virtual ~CounterArea(){};
	short m_x;
	short m_y;
	short m_w;
	short m_h;
	UCHAR m_transparency;
	TCHAR m_font[32];
	UCHAR   m_fontsize;
	bool m_bold;
	bool m_italic;
	bool m_underline;
	UCHAR m_align;
	bool m_multiline;
	TCHAR m_target_date[32];
	TCHAR m_target_time[32];
	UINT m_counter_color;
	bool m_day_enable;
	TCHAR m_daytext[32];
	bool m_hour_enable;
	TCHAR m_hourtext[32];
	bool m_min_enable;
	TCHAR m_minutetext[32];
	bool m_sec_enable;
	TCHAR m_secondtext[32];
	bool m_add_enable;
	bool m_unit_enable;
	bool m_text_enable;
	UINT m_textcolor;
	TCHAR m_statictext[256];
	bool m_bTimeFlag;

};
class ClockArea:public Area
{
public:
	ClockArea(int type){m_AreaType=type;}
	virtual ~ClockArea(){};
	short		m_x;
	short		m_y;
	short		m_w;
	short		m_h;
	UCHAR		m_transparency;

	TCHAR m_font[32];
	UCHAR   m_fontsize;
	bool m_bold;
	bool m_italic;
	bool m_underline;

	bool		m_day_enable;
	UINT		m_daycolor;

	bool		m_week_enable;
	UINT		m_weekcolor;

	bool		m_text_enable;
	UINT		m_textcolor;
	TCHAR		m_statictext[256];

	UINT		m_hourhand_color;
	UINT		m_minhand_color;
	UINT		m_secondhand_color;

	UCHAR		m_timediff_flag;
	UCHAR		m_timediff_hour;
	UCHAR		m_timediff_min;


	UINT m_rightangle_color; // 3,6,9点颜色

	UINT m_hour_color; // 整点颜色

	UINT m_minute_color; //分点颜色

	UCHAR m_style;
};


class Program
{
public:
	virtual ~Program(){
		for (int i=0;i<m_Arealist.size();i++)
		{
			delete m_Arealist[i];
		}
	};
	short m_w;
	short m_h;
	unsigned char	m_play_mode;
	unsigned int	m_play_time;
	bool			m_bDate;
	CTime			m_aging_start_time;
	CTime			m_aging_stop_time;
	bool			m_bTime;
	CTime			m_period_ontime;
	CTime			m_period_offtime;
	unsigned char	m_play_week;
	vector<Area*> m_Arealist;
};

struct DynaPicPage
{
	TCHAR szFile[MAX_PATH];
	UCHAR display_effects;
	UCHAR display_speed;
	USHORT stay_time;
};

struct DynaStrPage
{
	UCHAR display_effects;
	UCHAR display_speed;
	USHORT stay_time;
	int  m_LineSpace;
	UINT m_BgColor;
	bool m_bAntialiasing;
	CString m_font;
	UCHAR m_fontsize;
	bool m_bold;
	bool m_italic;
	bool m_underline;
	bool m_strike;
	CString szTxt;
	UINT txtcolor;
};
struct DynaRefPicPage
{
	TCHAR szFile[MAX_PATH];
	UCHAR display_effects;
	UCHAR display_speed;
	USHORT stay_time;
	TCHAR user[16];
	TCHAR pwd[16];
};
struct DynaStrRefPage
{
	UCHAR display_effects;
	UCHAR display_speed;
	USHORT stay_time;
	int  m_LineSpace;
	UINT m_BgColor;
	bool m_bAntialiasing;
	CString m_font;
	UCHAR m_fontsize;
	bool m_bold;
	bool m_italic;
	bool m_underline;
	bool m_strike;
	CString szTxt;
	UINT txtcolor;
	TCHAR user[16];
	TCHAR pwd[16];
};