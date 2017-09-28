using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace LedYQNetSdkDemo
{
    public class LedProgram
    {
        #region 节目API YQ_开头
        /// <summary>
        /// 创建播放列表
        /// </summary>
        /// <returns>指向播放列表的句柄</returns>
        [DllImport("LedNetSdk.dll")]
        public static extern uint YQ_CreatePlaylist();

        /// <summary>
        /// 销毁播放列表
        /// </summary>
        /// <param name="hPlaylist">指向播放列表的句柄</param>
        [DllImport("LedNetSdk.dll")]
        public static extern void YQ_DestroyPlaylist(uint hPlaylist);

        /// <summary>
        /// 创建节目
        /// </summary>
        /// <param name="w">节目宽度</param>
        /// <param name="h">节目高度</param>
        /// <returns>指向节目的句柄</returns>
        /// <remarks>节目的宽高应与控制器的屏幕大小一致</remarks>
        [DllImport("LedNetSdk.dll")]
        public static extern uint YQ_CreateProgram(short w, short h);

        /// <summary>
        /// 创建图文区域
        /// </summary>
        /// <param name="x">分区x坐标</param>
        /// <param name="y">分区y坐标</param>
        /// <param name="w">分区宽度</param>
        /// <param name="h">分区高度</param>
        /// <param name="transparency">分区不透明度 0-100</param>
        /// <param name="windowType">窗口类型,1：图片分区；2：文字分区；3：字幕分区；4：GIF 动态图片分区</param>
        /// <param name="bgTransparency">背景是否透明</param>
        /// <returns>指向节目区域的句柄</returns>
        [DllImport("LedNetSdk.dll")]
        public static extern uint YQ_CreatePicArea(short x, short y, short w, short h, byte transparency , int windowType = 1, bool bgTransparency = false);

        /// <summary>
        /// 向图文区域的里面添加图片项
        /// </summary>
        /// <param name="hArea">区域句柄</param>
        /// <param name="szImgFile">图片文件全路径，目前可以是bmp,jpg,png,gif</param>
        /// <param name="displayEffects">显示参数，特技编号</param>
        /// <param name="displaySpeed">显示参数，特技运行速度</param>
        /// <param name="stayTime">显示参数，停留时间</param>
        [DllImport("LedNetSdk.dll")]
        public static extern uint YQ_PicAreaAddImageUnit(uint hArea, byte[] szImgFile, byte displayEffects, byte displaySpeed, ushort stayTime);

        /// <summary>
        /// 向图文区域的里面添加文本项
        /// </summary>
        /// <param name="hArea">区域句柄</param>
        /// <param name="szImgFile">rtf文件全路径</param>
        /// <param name="displayEffects">显示参数，特技编号</param>
        /// <param name="displaySpeed">显示参数，特技运行速度</param>
        /// <param name="stayTime">显示参数，停留时间</param>
        [DllImport("LedNetSdk.dll")]
        public static extern uint YQ_PicAreaAddRtfUnit(uint hArea, byte[] szImgFile, byte displayEffects, byte displaySpeed, ushort stayTime);

        // 函数：	YQ_CreateVideoArea
        // 返回值：	指向节目区域的句柄
        // 参数：	
        //			short X：分区x坐标
        //			short Y：分区y坐标
        //			short W：分区宽度
        //			short H：分区高度
        //			BYTE Transparency：分区不透明度 0-100
        // 说明：	创建视频区域
        [DllImport("LedNetSdk.dll")]
        public static extern uint YQ_CreateVideoArea(short x, short y, short w, short h, byte transparency);

        // 函数：	YQ_VideoAreaAddUnit
        // 返回值：	无
        // 参数：	
        //			DWORD hArea：区域句柄
        //			LPCWSTR szVideoFile：视频文件全路径
        //			UCHAR scale_mode：缩放模式，0 – 按原始比例进行缩放，1 – 按窗口比例进行缩放
        //			UCHAR volume：音量
        // 说明：	向视频区域的里面添加视频项
        [DllImport("LedNetSdk.dll")]
        public static extern uint YQ_VideoAreaAddUnit(uint hArea, byte[] szVideoFile, byte scale_mode, byte volume);

       
        // 函数：	YQ_CreateCNTimeArea
        // 返回值：	指向节目区域的句柄
        // 参数：	
        //			short X：分区x坐标
        //			short Y：分区y坐标
        //			short W：分区宽度
        //			short H：分区高度
        //			BYTE Transparency：分区不透明度 0-100		
        //			UCHAR timediff_flag：0-正时差，1-负时差，
        //			UCHAR timediff_hour：时差的小时部分
        //			UCHAR timediff_min：时差的分钟部分
        //			LPCWSTR font：时间区文本字体
        //			int fontsize：字体大小
        //			BOOL bold：是否加粗
        //			BOOL italic：是否斜体
        //			BOOL underline：是否下划线
        //			UCHAR align：对齐方式，0-左对齐，1-居中对齐，2-右对齐
        //			BOOL multiline：是否多行
        //			BOOL day_enable：是否使能显示日期
        //			UINT daycolor：日期的颜色
        //			BOOL week_enable：是否显示星期
        //			UINT weekcolor：星期颜色
        //			BOOL time_enable：是否显示时间
        //			UINT timecolor：时间颜色
        //			BOOL text_enable：是否添加自定义文本
        //			UINT textcolor：自定义文本颜色
        //			LPCWSTR statictext：自定义文本内容
        // 说明：	创建简单时间区域
        [DllImport("LedNetSdk.dll")]
        public static extern uint YQ_CreateCNTimeArea(short x, short y, short w, short h, byte transparency,
            int timediff_flag, int timediff_hour, int timediff_min,
            string font, uint fontsize, bool bold, bool italic, bool underline, int align, bool multiline,
            bool day_enable, uint daycolor,
            bool week_enable, uint weekcolor,
	        bool time_enable,uint timecolor,
            bool text_enable, uint textcolor, byte[] statictext);

        // 函数：	YQ_CreateClockArea
        // 返回值：	指向节目区域的句柄
        // 参数：	
        //			short X：分区x坐标
        //			short Y：分区y坐标
        //			short W：分区宽度
        //			short H：分区高度
        //			BYTE Transparency：分区不透明度 0-100
        //			BOOL text_enable：是否添加自定义文本
        //			UINT textcolor：自定义文本颜色
        //			LPCWSTR statictext：自定义文本内容
        //			LPCWSTR text_font：文本字体
        //			int text_fontsize：字体大小
        //			BOOL text_bold：是否加粗
        //			BOOL text_italic：是否斜体
        //			BOOL text_underline：是否下划线
        //			BOOL ymd_enable：是否显示年月日
        //			UINT ymdcolor：年月日颜色
        //			BOOL week_enable：是否显示星期
        //			UINT weekcolor：星期颜色
        //			UINT hourhand_color：时针颜色
        //			UINT minhand_color：分针颜色
        //			UINT secondhand_color：秒针颜色
        //			UCHAR timediff_flag：0-正时差，1-负时差，
        //			UCHAR timediff_hour：时差的小时部分
        //			UCHAR timediff_min：时差的分钟部分
        //			int rightangle_color：时点颜色
        //			int integral_color：369点颜色
        //			int minute_color：分点颜色
        //			UINT dwClockFormat：表盘风格，0-线形;1-点形;2-方形;3-数字;4-罗马
        // 说明：	创建特定风格的表盘区域
        [DllImport("LedNetSdk.dll")]
        public static extern uint YQ_CreateClockStyleArea(short x, short y, short w, short h, byte transparency,
	        bool text_enable,uint textcolor,byte[] statictext,string text_font,uint text_fontsize,bool text_bold,bool text_italic,bool text_underline,
	        bool ymd_enable,uint ymdcolor,
	        bool week_enable,uint weekcolor,
            uint hourhand_color, uint minhand_color, uint secondhand_color,
            byte timediff_flag, byte timediff_hour, byte timediff_min,
	        uint rightangle_color,uint integral_color,uint minute_color,
	        uint dwClockFormat);

        // 函数：	YQ_CreateLunarArea
        // 返回值：	指向节目区域的句柄
        // 参数：	
        //			short X：分区x坐标
        //			short Y：分区y坐标
        //			short W：分区宽度
        //			short H：分区高度
        //			BYTE Transparency：分区不透明度 0-100
        //			LPCWSTR font：文本字体
        //			int fontsize：字体大小
        //			BOOL bold：是否加粗
        //			BOOL italic：是否斜体
        //			BOOL underline：是否下划线
        //			UCHAR align：对齐方式，0-左对齐，1-居中对齐，2-右对齐
        //			BOOL multiline：是否多行
        //			BOOL year_enable：是否使能显示农历
        //			UINT yearcolor：农历的颜色
        //			BOOL day_enable：是否使能显示天干
        //			UINT daycolor：天干的颜色
        //			BOOL solarterms_enable：是否使能显示节气
        //			UINT solartermscolor：节气的颜色
        //			BOOL text_enable：是否添加自定义文本
        //			UINT textcolor：自定义文本颜色
        //			LPCWSTR statictext：自定义文本内容
        // 说明：	创建农历区域
        [DllImport("LedNetSdk.dll")]
        public static extern uint YQ_CreateLunarArea(short x, short y, short w, short h, byte transparency,
	        string font,uint fontsize,bool bold,bool italic,bool underline,int align,bool multiline,
	        bool year_enable,uint yearcolor,bool day_enable,uint daycolor,bool solarterms_enable,uint solartermscolor,
            bool text_enable, uint textcolor, byte[] statictext);

        // 函数：	YQ_CreateTimeCounterArea
        // 返回值：	指向节目区域的句柄
        // 参数：	
        //			short X：分区x坐标
        //			short Y：分区y坐标
        //			short W：分区宽度
        //			short H：分区高度
        //			BYTE Transparency：分区不透明度 0-100
        //			LPCWSTR font：计时区文本字体
        //			int fontsize：字体大小
        //			BOOL bold：是否加粗
        //			BOOL italic：是否斜体
        //			BOOL underline：是否下划线
        //			UCHAR align：对齐方式，0-左对齐，1-居中对齐，2-右对齐
        //			BOOL multiline：是否多行
        //			LPCWSTR target_date：目标日期，格式2012/06/20
        //			LPCWSTR target_time：目标时间，格式02:23:55
        //			BOOL bTimeFlag：0-倒计时，1-正计时
        //			UINT counter_color：计时器文本对应的颜色
        //			BOOL day_enable：是否显示天
        //			LPCWSTR daytext：天数对应单位的字符串，默认天，英文默认day
        //			BOOL hour_enable：是否显示小时
        //			LPCWSTR hourtext：小时对应单位的字符串，默认小时，英文默认hour
        //			BOOL min_enable：是否显示分钟
        //			LPCWSTR minutetext：分钟单位对应的字符串，默认分，英文默认minute
        //			BOOL sec_enable：是否显示秒
        //			LPCWSTR secondtext：秒对应单位的字符串，默认秒，英文默认s
        //			BOOL add_enable：是否计时累计
        //			BOOL unit_enable：是否显示单位（天，小时，分,秒）
        //			BOOL text_enable：是否添加自定义文本
        //			UINT textcolor：自定义文本颜色
        //			LPCWSTR statictext：自定义文本内容
        // 说明：	创建计时时间区域
        [DllImport("LedNetSdk.dll")]
        public static extern uint YQ_CreateTimeCounterArea(short x, short y, short w, short h, byte transparency,
           string font,uint fontsize,bool bold,bool italic,bool underline,int align,bool multiline,
           byte[] target_date, byte[] target_time, bool bTimeFlag, uint counter_color,
           bool day_enable, byte[] daytext, bool hour_enable, byte[] hourtext, bool min_enable, byte[] minutetext, bool sec_enable, byte[] secondtext,
           bool add_enable,bool unit_enable,
           bool text_enable,uint textcolor,byte[] statictext);


        /// <summary>
        /// 向节目添加区域
        /// </summary>
        /// <param name="hProgram">节目句柄</param>
        /// <param name="hArea">区域句柄</param>
        [DllImport("LedNetSdk.dll")]
        public static extern uint YQ_ProgramAddArea(uint hProgram, uint hArea);

        /// <summary>
        /// 向播放列表添加节目
        /// </summary>
        /// <param name="hPlaylist">播放列表句柄</param>
        /// <param name="hProgram">节目句柄</param>
        /// <param name="playMode">播放模式，0 – 定长播放，1 – 定次播放</param>
        /// <param name="playTime">播放时长或者播放次数</param>
        /// <param name="agingStartTime">播放时效的开始日期，格式2012-06-20</param>
        /// <param name="agingStopTime">播放时效结束日期</param>
        /// <param name="periodOntime">播放时段开始时间,格式08:30:00</param>
        /// <param name="periodOfftime">播放时段结束时间</param>
        /// <param name="playWeek">bit0 ～ bit6 依次表示星期一至星期天，，0—表示该天节目不能播放，1—表示该天节目可以播放</param>
        [DllImport("LedNetSdk.dll")]
        public static extern uint YQ_PlaylistAddProgram(uint hPlaylist, uint hProgram, byte playMode, int playTime, byte[] agingStartTime,
            byte[] agingStopTime, byte[] periodOntime, byte[] periodOfftime, byte playWeek = 255);


        /// <summary>
        /// 创建动态区域
        /// </summary>
        /// <param name="areaID"></param>
        /// <param name="x">动态区x坐标</param>
        /// <param name="y">动态区y坐标</param>
        /// <param name="w">动态区宽度</param>
        /// <param name="h">动态区高度</param>
        /// <param name="transparency">动态区不透明度 0-100</param>
        /// <param name="progrmRelation">1 关联节目绑定播放；0 关联节目播放完后播放</param>
        /// <param name="relatedProgram">所关联的节目编号，如果没有对应关联的节目应传0xffff</param>
        /// <param name="runTime">0-绑定节目一起播放；1-与绑定节目轮播</param>
        /// <param name="runMode">动态区运行模式
        ///							0— 动态区数据循环显示。
        ///							1— 动态区数据顺序显示，显示完最后一页后就不再显示
        ///							2— 动态区数据显示完成后静止显示最后一页数据。
        ///							3— 动态区数据循环显示，超过设定时间后数据仍未更新时删除动态区信息。
        ///							4--动态区数据循环显示，超过设定时间后数据仍未更新时播放 LOGO 图片</param>
        /// <param name="timeout">动态区数据更新超时时间，单位为秒</param>
        /// <param name="dataType">数据类型，0-图片；1-文本</param>
        /// short UriUpdateFrequency：更新频率
        /// <returns>指向动态区的句柄</returns>
        [DllImport("LedNetSdk.dll")]
        public static extern uint YQ_CreateDynamicArea(byte areaID, short x, short y, short w, short h, byte transparency,
            byte progrmRelation, ushort relatedProgram, byte runTime, byte runMode, short timeout, byte dataType, short uriUpdateFrequency);

        // 函数：	YQ_DynamicAreaAddPicPage
        // 返回值：	无
        // 参数：	
        //			DWORD hArea：区域句柄
        //			USHORT StayTime：显示参数，停留时间
        //			BYTE DisplayEffects：显示参数，特技编号
        //			BYTE DisplaySpeed：显示参数，特技运行速度
        //			char* Suffix：图片格式后缀名,限”jpg” ”bmp” ”png”三种;必须为小写
        //			DWORD imgdatalen：图片数据长度
        //			BYTE* imgdata：图片数据内容
        // 说明：	动态区添加图片分页
        [DllImport("LedNetSdk.dll")]
        public static extern void YQ_DynamicAreaAddPicPage(uint hArea, ushort StayTime, byte DisplayEffects, byte DisplaySpeed,
            string Suffix, uint imgdatalen, byte[] imgdata);

        
        // 函数：	YQ_DynamicAreaAddStrPage
        // 返回值：	无
        // 参数：	
        //			DWORD hArea：区域句柄
        //			USHORT StayTime：显示参数，停留时间
        //			BYTE DisplayEffects：显示参数，特技编号
        //			BYTE DisplaySpeed：显示参数，特技运行速度
        //			DWORD BgColor：文本背景色
        //			BYTE LinesSizes：文本行间距
        //			BOOL bold：是否加粗
        //			BOOL italic：是否斜体
        //			BOOL underline：是否下划线
        //			BOOL strikeout：是否中划线
        //			BOOL antialiasing：是否反锯齿
        //			LPCWSTR str：文本内容
        //			UINT txtcolor：文本颜色
        //			LPCWSTR font：文本字体
        //			int fontsize：字体大小
        // 说明：	动态区添加文本分页
        [DllImport("LedNetSdk.dll")]
        public static extern void YQ_DynamicAreaAddStrPage(uint hArea, ushort StayTime, byte DisplayEffects, byte DisplaySpeed,
            uint BgColor, int LinesSizes, bool bold, bool italic, bool underline, bool strikeout, bool antialiasing,
            byte[] str, uint txtcolor, string font, int fontsize);
        
        [DllImport("LedNetSdk.dll")]
        public static extern void YQ_DynamicAreaAddPicRefPage(uint hArea, ushort StayTime, byte DisplayEffects, byte DisplaySpeed,
            string Suffix, string user, string pwd, byte[] url);

        // 函数：	YQ_DynamicAreaAddStrRefPage
        // 返回值：	无
        // 参数：	
        //			DWORD hArea：区域句柄
        //			USHORT StayTime：显示参数，停留时间
        //			BYTE DisplayEffects：显示参数，特技编号
        //			BYTE DisplaySpeed：显示参数，特技运行速度
        //          BYTE FontCode
        //			DWORD BgColor：文本背景色
        //			BYTE LinesSizes：文本行间距
        // 说明：	动态区添加文本分页
        [DllImport("LedNetSdk.dll")]
        public static extern void YQ_DynamicAreaAddStrRefPage(uint hArea, ushort StayTime, byte DisplayEffects, byte DisplaySpeed,
            byte FontCode, uint BgColor, int LinesSizes, string user, string pwd, byte[] url);

        /// <summary>
        /// 销毁创建的动态区
        /// </summary>
        /// <param name="hArea">区域句柄</param>
        [DllImport("LedNetSdk.dll")]
        public static extern int YQ_DestroyDynamic(uint hArea);
        #endregion
    }   
}
