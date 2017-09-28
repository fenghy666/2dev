using System;
using System.Collections.Generic;
//using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace LedYQNetSdkDemo
{
    public static class server_ftp
    {
        public static char[] ftp_server_ip;
        public static short ftp_server_port;
        public static char[] ftp_server_user;
        public static char[] ftp_server_pwd;
        public static bool m_bServerRun = false;
    }
    public class LedNetSdkDemo
    {
        [StructLayout(LayoutKind.Sequential)]
        public struct Program
        {
	        public short m_w;//宽
	        public short m_h;//高
	        public byte m_play_mode;//播放模式
	        public int m_play_time;//播放时长
	        public bool m_bDate;//设置日期
	        public byte[] m_aging_start_time;//开始日期
	        public byte[] m_aging_stop_time;//结束日期
	        public bool m_bTime;//时段
            public byte[] m_period_ontime;//开始时间
            public byte[] m_period_offtime;//结束时间
            public byte m_play_week;//星期
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 1024)]
            public PicArea[] m_PicArea;
        }
        public struct PicArea
        {
            public int thing;//区域类型0图文1视频2字幕3时间4表盘5农历6计时
	        public short m_x;//x
	        public short m_y;//y
	        public short m_w;//宽
	        public short m_h;//高
	        public bool m_transparency;//背景透明
	        public byte m_window_type;//窗口类型
	        public byte m_bBgTransparent;//窗口透明
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 1024)]
            public ImgText[] m_ImgText;//文件
            public Video[] m_Video;//视频
            public Time_Area m_Time_Area;//时间
            public Clock_Area m_Clock_Area;//表盘
            public Lun_Area m_Lun_Area;//农历
            public Counter_Area m_Counter_Area;//计时
        }
        //图文
        public struct ImgText
        {
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 1024)]
            public byte[] szFile;//路径
            public string FileName;//路径
            public byte display_effects;//特效
            public byte display_speed;//运行时间
            public ushort stay_time;//停留时间
	        public bool bPic;//判断图文
        };
        //视频
        public struct Video 
        {
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 1024)]
            public byte[] szFile;//路径
            public string FileName;//路径
            public byte scale_mode;//缩放模式
            public byte volume;//音量
        }
        //时间
        public struct Time_Area
        {
            public int timediff_flag;//0-正时差，1-负时差
            public int timediff_hour;//时差的小时部分
            public int timediff_min;//时差的分钟部分
            public string font;//时间区文本字体
            public uint fontsize;//字体大小
            public bool bold;//是否加粗
            public bool italic;//是否斜体
            public bool underline;//是否下划线
            public int align;//对齐方式，0-左对齐，1-居中对齐，2-右对齐
            public bool multiline;//是否多行
            public bool day_enable;//是否使能显示日期
            public uint daycolor;//日期的颜色
            public bool week_enable;//是否显示星期
            public uint weekcolor;//星期颜色
            public bool time_enable;//是否显示时间
            public uint timecolor;//时间颜色
            public bool text_enable;//是否添加自定义文本
            public uint textcolor;//自定义文本颜色
            public byte[] statictext;//自定义文本内容
        }
        //表盘
        public struct Clock_Area 
        {
            public bool text_enable;//是否添加自定义文本
            public uint textcolor;//自定义文本颜色
            public byte[] statictex;//自定义文本内容
            public string text_font;//文本字体
            public uint text_fontsize;//字体大小
            public bool text_bold;//是否加粗
            public bool text_italic;//是否斜体
            public bool text_underline;//是否下划线
            public bool ymd_enable;//是否显示年月日
            public uint ymdcolor;//年月日颜色
            public bool week_enable;//是否显示星期
            public uint weekcolor;//星期颜色
            public uint hourhand_color;//时针颜色
            public uint minhand_color;//分针颜色
            public uint secondhand_color;//秒针颜色
            public byte timediff_flag;//0-正时差，1-负时差，
            public byte timediff_hour;//时差的小时部分
            public byte timediff_min;//时差的分钟部分
            public uint rightangle_color;//时点颜色
            public uint integral_color;//369点颜色
            public uint minute_color;//分点颜色
            public uint dwClockFormat;//表盘风格，0-线形;1-点形;2-方形;3-数字;4-罗马
        }
        //农历
        public struct Lun_Area 
        {
            public string text_font;//文本字体
            public uint text_fontsize;//字体大小
            public bool text_bold;//是否加粗
            public bool text_italic;//是否斜体
            public bool text_underline;//是否下划线
            public int align;//对齐方式，0-左对齐，1-居中对齐，2-右对齐
            public bool multiline;//是否多行
            public bool year_enable;//是否使能显示农历
            public uint yearcolor;//农历的颜色
            public bool day_enable;//是否使能显示天干
            public uint daycolor;//天干的颜色
            public bool solarterms_enable;//是否使能显示节气
            public uint solartermscolor;//节气的颜色
            public bool text_enable;//是否添加自定义文本
            public uint textcolor;//自定义文本颜色
            public byte[] statictext;//自定义文本内容
        }
        //计时
        public struct Counter_Area 
        {
            public string font;//计时区文本字体
            public uint fontsize;//字体大小
            public bool bold;//是否加粗
            public bool italic;//是否斜体
            public bool underline;//是否下划线
            public int align;//对齐方式，0-左对齐，1-居中对齐，2-右对齐
            public bool multiline;//是否多行
            public byte[] target_date;//目标日期，格式2012/06/20
            public byte[] target_time;//目标时间，格式02:23:55
            public bool bTimeFlag;//0-倒计时，1-正计时
            public uint counter_color;//计时器文本对应的颜色
            public bool day_enable;//是否显示天
            public byte[] daytext;//天数对应单位的字符串，默认天，英文默认day
            public bool hour_enable;//是否显示小时
            public byte[] hourtext;//小时对应单位的字符串，默认小时，英文默认hour
            public bool min_enable;//是否显示分钟
            public byte[] minutetext;//分钟单位对应的字符串，默认分，英文默认minute
            public bool sec_enable;//是否显示秒
            public byte[] secondtext;//秒对应单位的字符串，默认秒，英文默认s
            public bool add_enable;//是否计时累计
            public bool unit_enable;//是否显示单位（天，小时，分,秒）
            public bool text_enable;//是否添加自定义文本
            public uint textcolor;//自定义文本颜色
            public byte[] statictext;//自定义文本内容
        }

        //动态区文字
        public struct StrPage
        {
            public byte display_effects;//特技编号
            public byte display_speed;//特技运行速度
            public ushort stay_time;//显示参数，停留时间
            public DynaStrPage mDynaStrPage;
        }
        public struct DynaStrPage
        {
            public int m_LineSpace;//文本行间距
            public uint m_BgColor;//文本背景色
            public string m_font;//文本字体
            public int m_fontsize;//字体大小
            public bool m_bold;//是否加粗
            public bool m_italic;//是否斜体
            public bool m_underline;//是否下划线
            public bool m_strikeout;//是否中划线
            public bool m_antialiasing;//是否反锯齿
            public byte[] szTxt;//文本内容
            public uint txtcolor;//文本颜色
        };

        //图片\文本URL
        public struct imgURL 
        {
            public byte display_effects;//特技编号
            public byte display_speed;//特技运行速度
            public ushort stay_time;//显示参数，停留时间
            public imgurl mimgurl;
            public texturl txturl;
        }
        public struct imgurl 
        {
            public string Suffix;
            public string user;
            public string pwd;
            public byte[] url;
        }
        public struct texturl 
        {
            public uint BgColor;
            public int LinesSizes;
            public string user;
            public string pwd;
            public byte[] url;
        }
    }
}
