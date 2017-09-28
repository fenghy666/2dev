
/************************************************************************
 * file:	LedNetSdk.h
 * brief:	Header file of program making library for YQ card
 * author:	niu.zhimin
 * date:	2014-11-01
 ***********************************************************************/


#ifdef LEDNETSDK_EXPORTS
#define LEDPROGRAMSDK_API extern "C" __declspec(dllexport)
#else
#define LEDPROGRAMSDK_API extern "C" __declspec(dllimport)
#endif

// 函数：	YQ_CreatePlaylist
// 返回值：	指向播放列表的句柄
// 参数：	无
// 说明：	创建播放列表
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreatePlaylist();

// 函数：	YQ_DestroyPlaylist
// 返回值：	无
// 参数：	
//			DWORD hPlaylist：指向播放列表的句柄
// 说明：	销毁播放列表
LEDPROGRAMSDK_API void WINAPI YQ_DestroyPlaylist(DWORD hPlaylist);

// 函数：	YQ_CreateProgram
// 返回值：	指向节目的句柄
// 参数：	
//			short W：节目宽度，节目的宽高应与控制器的屏幕大小一致
//			short H：节目高度
// 说明：	创建节目
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateProgram(short w,short h);

// 函数：	YQ_CreateTimeArea
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
//			UCHAR dayformat：日期格式0-18
//			BOOL week_enable：是否显示星期
//			UINT weekcolor：星期颜色
//			UCHAR weekformat：星期格式0-8
//			BOOL time_enable：是否显示时间
//			UINT timecolor：时间颜色
//			UCHAR timeformat：时间格式0-18
//			BOOL text_enable：是否添加自定义文本
//			UINT textcolor：自定义文本颜色
//			LPCWSTR statictext：自定义文本内容
// 说明：	创建时间区域
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateTimeArea(short x,short y,short w,short h,UCHAR transparency,
	UCHAR timediff_flag,UCHAR timediff_hour,UCHAR timediff_min,
	LPCWSTR font,UCHAR fontsize,BOOL bold,BOOL italic,BOOL underline,UCHAR align,BOOL multiline,
	BOOL day_enable,UINT daycolor,UCHAR dayformat,
	BOOL week_enable,UINT weekcolor,UCHAR weekformat,
	BOOL time_enable,UINT timecolor,UCHAR timeformat,
	BOOL text_enable,UINT textcolor,LPCWSTR statictext);

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
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateCNTimeArea(short x,short y,short w,short h,UCHAR transparency,
	UCHAR timediff_flag,UCHAR timediff_hour,UCHAR timediff_min,
	LPCWSTR font,UCHAR fontsize,BOOL bold,BOOL italic,BOOL underline,UCHAR align,BOOL multiline,
	BOOL day_enable,UINT daycolor,
	BOOL week_enable,UINT weekcolor,
	BOOL time_enable,UINT timecolor,BOOL text_enable,UINT textcolor,LPCWSTR statictext);

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
//			LPCWSTR target_date：目标日期，格式2012-06-20
//			LPCWSTR target_time：目标时间，格式02-23-55
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
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateTimeCounterArea(short x,short y,short w,short h,UCHAR transparency,
	LPCWSTR font,UCHAR fontsize,BOOL bold,BOOL italic,BOOL underline,UCHAR align,BOOL multiline,
	LPCWSTR target_date,LPCWSTR target_time,BOOL bTimeFlag,UINT counter_color,
	BOOL day_enable,LPCWSTR daytext,BOOL hour_enable,LPCWSTR hourtext,BOOL min_enable,LPCWSTR minutetext,BOOL sec_enable,LPCWSTR secondtext,
	BOOL add_enable,BOOL unit_enable,
	BOOL text_enable,UINT textcolor,LPCWSTR statictext);

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
//			BOOL year_enable：是否使能显示年
//			UINT yearcolor：年的颜色
//			BOOL day_enable：是否使能显示日期
//			UINT daycolor：日期的颜色
//			BOOL solarterms_enable：是否使能显示节气
//			UINT solartermscolor：节气的颜色
//			BOOL text_enable：是否添加自定义文本
//			UINT textcolor：自定义文本颜色
//			LPCWSTR statictext：自定义文本内容
// 说明：	创建农历区域
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateLunarArea(short x,short y,short w,short h,UCHAR transparency,
	LPCWSTR font,UCHAR fontsize,BOOL bold,BOOL italic,BOOL underline,UCHAR align,BOOL multiline,
	BOOL year_enable,UINT yearcolor,BOOL day_enable,UINT daycolor,BOOL solarterms_enable,UINT solartermscolor,
	BOOL text_enable,UINT textcolor,LPCWSTR statictext);

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
//			short text_x：默认0
//			short text_y：默认0
//			short text_w：默认0
//			short text_h：默认0
//			BOOL ymd_enable：是否显示年月日
//			UINT ymdcolor：年月日颜色
//			UCHAR ymdformat：年月日格式0-18
//			LPCWSTR ymd_font：年月日字体
//			UCHAR ymd_fontsize：字体大小
//			BOOL ymd_bold：是否加粗
//			BOOL ymd_italic：是否斜体
//			BOOL ymd_underline：是否下划线
//			short ymd_x：默认0
//			short ymd_y：默认0
//			short ymd_w：默认0
//			short ymd_h：默认0
//			BOOL week_enable：是否显示星期
//			UINT weekcolor：星期颜色
//			UCHAR weekformat：星期格式0-8
//			LPCWSTR week_font：星期字体
//			UCHAR week_fontsize：字体大小
//			BOOL week_bold：是否加粗
//			BOOL week_italic：是否斜体
//			BOOL week_underline：是否下划线
//			short week_x：默认0
//			short week_y：默认0
//			short week_w：默认0
//			short week_h：默认0
//			UINT hourhand_color：时针颜色
//			UINT minhand_color：分针颜色
//			UINT secondhand_color：秒针颜色
//			UCHAR timediff_flag：0-正时差，1-负时差，
//			UCHAR timediff_hour：时差的小时部分
//			UCHAR timediff_min：时差的分钟部分
//			int rightangle_shape：时点形状，0-线形;1-点形;2-方形;3-数字;4-罗马
//			int rightangle_width：时点宽度，默认2
//			int rightangle_color：时点颜色
//			int integral_shape：369点形状，0-线形;1-点形;2-方形;3-数字;4-罗马
//			int integral_width,369点宽度
//			int integral_color：369点颜色
//			int minute_shape：分点形状，0-线形;1-点形;2-方形
//			int minute_width：分店宽度
//			int minute_color：分点颜色
//			LPCWSTR szClockFile：表盘刻度图片，默认风格是自定义绘制，所以默认为空
// 说明：	创建表盘区域
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateClockArea(short x,short y,short w,short h,UCHAR transparency,
	BOOL text_enable,UINT textcolor,LPCWSTR statictext,LPCWSTR text_font,UCHAR text_fontsize,BOOL text_bold,BOOL text_italic,BOOL text_underline,short text_x,short text_y,short text_w,short text_h,
	BOOL ymd_enable,UINT ymdcolor,UCHAR ymdformat,LPCWSTR ymd_font,UCHAR ymd_fontsize,BOOL ymd_bold,BOOL ymd_italic,BOOL ymd_underline,short ymd_x,short ymd_y,short ymd_w,short ymd_h,
	BOOL week_enable,UINT weekcolor,UCHAR weekformat,LPCWSTR week_font,UCHAR week_fontsize,BOOL week_bold,BOOL week_italic,BOOL week_underline,short week_x,short week_y,short week_w,short week_h,
	UINT hourhand_color,UINT minhand_color,UINT secondhand_color,
	UCHAR timediff_flag,UCHAR timediff_hour,UCHAR timediff_min,
	int rightangle_shape,int rightangle_width,int rightangle_color,
	int integral_shape,int integral_width,int integral_color,
	int minute_shape,int minute_width,int minute_color,LPCWSTR szClockFile);

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
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateClockStyleArea(short x,short y,short w,short h,UCHAR transparency,
	BOOL text_enable,UINT textcolor,LPCWSTR statictext,LPCWSTR text_font,UCHAR text_fontsize,BOOL text_bold,BOOL text_italic,BOOL text_underline,
	BOOL ymd_enable,UINT ymdcolor,
	BOOL week_enable,UINT weekcolor,
	UINT hourhand_color,UINT minhand_color,UINT secondhand_color,
	UCHAR timediff_flag,UCHAR timediff_hour,UCHAR timediff_min,
	int rightangle_color,int integral_color,int minute_color,
	UINT dwClockFormat);

// 函数：	YQ_CreateVideoArea
// 返回值：	指向节目区域的句柄
// 参数：	
//			short X：分区x坐标
//			short Y：分区y坐标
//			short W：分区宽度
//			short H：分区高度
//			BYTE Transparency：分区不透明度 0-100
// 说明：	创建视频区域
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateVideoArea(short x,short y,short w,short h,UCHAR transparency);

// 函数：	YQ_CreatePicArea
// 返回值：	指向节目区域的句柄
// 参数：	
//			short X：分区x坐标
//			short Y：分区y坐标
//			short W：分区宽度
//			short H：分区高度
//			BYTE Transparency：分区不透明度 0-100
//			UCHAR window_type：窗口类型,1：图片分区；2：文字分区；3：字幕分区；4：GIF 动态图片分区
//			BOOL bBgTransparent：背景是否透明
// 说明：	创建图文区域
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreatePicArea(short x,short y,short w,short h,UCHAR transparency,UCHAR window_type,UCHAR bBgTransparent);


// 函数：	YQ_VideoAreaAddUnit
// 返回值：	无
// 参数：	
//			DWORD hArea：区域句柄
//			LPCWSTR szVideoFile：视频文件全路径
//			UCHAR scale_mode：缩放模式，0 – 按原始比例进行缩放，1 – 按窗口比例进行缩放
//			UCHAR volume：音量
// 说明：	向视频区域的里面添加视频项
LEDPROGRAMSDK_API void WINAPI YQ_VideoAreaAddUnit(DWORD hArea,LPCWSTR szVideoFile,UCHAR scale_mode,UCHAR volume);

// 函数：	YQ_PicAreaAddImageUnit
// 返回值：	无
// 参数：	
//			DWORD hArea：区域句柄
//			LPCWSTR szRtfFile：图片文件全路径，目前可以是bmp,jpg,png,gif
//			USHORT StayTime：显示参数，停留时间
//			BYTE DisplayEffects：显示参数，特技编号
//			BYTE DisplaySpeed：显示参数，特技运行速度
// 说明：	向图文区域的里面添加图片项
LEDPROGRAMSDK_API void WINAPI YQ_PicAreaAddImageUnit(DWORD hArea,LPCWSTR szImgFile,UCHAR display_effects,UCHAR display_speed,USHORT stay_time);

// 函数：	YQ_PicAreaAddRtfUnit
// 返回值：	无
// 参数：	
//			DWORD hArea：区域句柄
//			LPCWSTR szRtfFile：rtf文件全路径
//			USHORT StayTime：显示参数，停留时间
//			BYTE DisplayEffects：显示参数，特技编号
//			BYTE DisplaySpeed：显示参数，特技运行速度
// 说明：	向图文区域的里面添加文本项
LEDPROGRAMSDK_API void WINAPI YQ_PicAreaAddRtfUnit(DWORD hArea,LPCWSTR szRtfFile,UCHAR display_effects,UCHAR display_speed,USHORT stay_time);


// 函数：	YQ_ProgramAddArea
// 返回值：	无
// 参数：	
//			DWORD hArea：区域句柄
//			DWORD hProgram：节目句柄
// 说明：	向节目添加区域
LEDPROGRAMSDK_API void WINAPI YQ_ProgramAddArea(DWORD hProgram,DWORD hArea);

// 函数：	YQ_PlaylistAddProgram
// 返回值：	无
// 参数：	
//			DWORD hPlaylist：播放列表句柄
//			DWORD hProgram：节目句柄
//			unsigned char play_mode：播放模式，0 – 定长播放，1 – 定次播放
//			unsigned int play_time：播放时长或者播放次数
//			LPCWSTR aging_start_time：播放时效的开始日期，格式2012-06-20
//			LPCWSTR aging_stop_time：播放时效结束日期
//			LPCWSTR period_ontime：播放时段开始时间,格式08:30:00
//			LPCWSTR period_offtime：播放时段结束时间
//			unsigned char play_week：bit0 ～ bit6 依次表示星期一至星期天，，0—表示该天节目不能播放，1—表示该天节目可以播放
// 说明：	向播放列表添加节目
LEDPROGRAMSDK_API void WINAPI YQ_PlaylistAddProgram(DWORD hPlaylist,DWORD hProgram,unsigned char play_mode,unsigned int play_time,LPCWSTR aging_start_time,LPCWSTR aging_stop_time,LPCWSTR period_ontime,LPCWSTR period_offtime,unsigned char play_week);

// 函数：	YQ_CreateDynamicArea
// 返回值：	指向动态区的句柄
// 参数：	
//			BYTE AreaID：
//			short X：动态区x坐标
//			short Y：动态区y坐标
//			short W：动态区宽度
//			short H：动态区高度
//			BYTE Transparency：动态区不透明度 0-100
//			BYTE ProgrmRelation：1 关联节目绑定播放；0 关联节目播放完后播放
//			USHORT RelatedProgram：所关联的节目编号，如果没有对应关联的节目应传0xffff
//			BYTE RunTime：0-绑定节目一起播放；1-与绑定节目轮播
//			BYTE RunMode：动态区运行模式
//							0— 动态区数据循环显示。
//							1— 动态区数据顺序显示，显示完最后一页后就不再显示
//							2— 动态区数据显示完成后静止显示最后一页数据。
//							3— 动态区数据循环显示，超过设定时间后数据仍未更新时删除动态区信息。
//							4--动态区数据循环显示，超过设定时间后数据仍未更新时播放 LOGO 图片
//			short Timeout：动态区数据更新超时时间，单位为秒
//			BYTE DataType：数据类型，0-图片；1-文本
//			short UriUpdateFrequency：更新频率
// 说明：	创建动态区
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateDynamicArea(BYTE AreaID,short X,short Y,short W,short H,BYTE Transparency,BYTE	ProgrmRelation,	USHORT RelatedProgram,BYTE RunTime,BYTE RunMode,short Timeout,BYTE DataType,short UriUpdateFrequency);

// 函数：	YQ_DestroyDynamic
// 返回值：	无
// 参数：	
//			DWORD hArea：区域句柄
// 说明：	销毁创建的动态区
LEDPROGRAMSDK_API void WINAPI YQ_DestroyDynamic(DWORD hArea);

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
LEDPROGRAMSDK_API void WINAPI YQ_DynamicAreaAddStrPage(DWORD hArea,USHORT StayTime,BYTE DisplayEffects,BYTE DisplaySpeed,DWORD BgColor,BYTE LinesSizes,BOOL bold,BOOL italic,BOOL underline,BOOL strikeout,BOOL antialiasing,LPCWSTR str,UINT txtcolor,LPCWSTR font,int fontsize);

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
LEDPROGRAMSDK_API void WINAPI YQ_DynamicAreaAddPicPage(DWORD hArea,USHORT StayTime,BYTE DisplayEffects,BYTE DisplaySpeed,char* Suffix,DWORD imgdatalen,BYTE* imgdata);

LEDPROGRAMSDK_API void WINAPI YQ_DynamicAreaAddPicRefPage(DWORD hArea,USHORT StayTime,BYTE DisplayEffects,BYTE DisplaySpeed,char* Suffix,char* user,char* pwd,char* url);

LEDPROGRAMSDK_API void WINAPI YQ_DynamicAreaAddStrRefPage(DWORD hArea,USHORT StayTime,BYTE DisplayEffects,BYTE DisplaySpeed,BYTE FontCode,DWORD BgColor,BYTE LinesSizes,char* user,char* pwd,char* url);