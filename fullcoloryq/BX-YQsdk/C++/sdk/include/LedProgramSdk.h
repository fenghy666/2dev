
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

// ������	YQ_CreatePlaylist
// ����ֵ��	ָ�򲥷��б�ľ��
// ������	��
// ˵����	���������б�
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreatePlaylist();

// ������	YQ_DestroyPlaylist
// ����ֵ��	��
// ������	
//			DWORD hPlaylist��ָ�򲥷��б�ľ��
// ˵����	���ٲ����б�
LEDPROGRAMSDK_API void WINAPI YQ_DestroyPlaylist(DWORD hPlaylist);

// ������	YQ_CreateProgram
// ����ֵ��	ָ���Ŀ�ľ��
// ������	
//			short W����Ŀ��ȣ���Ŀ�Ŀ��Ӧ�����������Ļ��Сһ��
//			short H����Ŀ�߶�
// ˵����	������Ŀ
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateProgram(short w,short h);

// ������	YQ_CreateTimeArea
// ����ֵ��	ָ���Ŀ����ľ��
// ������	
//			short X������x����
//			short Y������y����
//			short W���������
//			short H�������߶�
//			BYTE Transparency��������͸���� 0-100		
//			UCHAR timediff_flag��0-��ʱ�1-��ʱ�
//			UCHAR timediff_hour��ʱ���Сʱ����
//			UCHAR timediff_min��ʱ��ķ��Ӳ���
//			LPCWSTR font��ʱ�����ı�����
//			int fontsize�������С
//			BOOL bold���Ƿ�Ӵ�
//			BOOL italic���Ƿ�б��
//			BOOL underline���Ƿ��»���
//			UCHAR align�����뷽ʽ��0-����룬1-���ж��룬2-�Ҷ���
//			BOOL multiline���Ƿ����
//			BOOL day_enable���Ƿ�ʹ����ʾ����
//			UINT daycolor�����ڵ���ɫ
//			UCHAR dayformat�����ڸ�ʽ0-18
//			BOOL week_enable���Ƿ���ʾ����
//			UINT weekcolor��������ɫ
//			UCHAR weekformat�����ڸ�ʽ0-8
//			BOOL time_enable���Ƿ���ʾʱ��
//			UINT timecolor��ʱ����ɫ
//			UCHAR timeformat��ʱ���ʽ0-18
//			BOOL text_enable���Ƿ�����Զ����ı�
//			UINT textcolor���Զ����ı���ɫ
//			LPCWSTR statictext���Զ����ı�����
// ˵����	����ʱ������
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateTimeArea(short x,short y,short w,short h,UCHAR transparency,
	UCHAR timediff_flag,UCHAR timediff_hour,UCHAR timediff_min,
	LPCWSTR font,UCHAR fontsize,BOOL bold,BOOL italic,BOOL underline,UCHAR align,BOOL multiline,
	BOOL day_enable,UINT daycolor,UCHAR dayformat,
	BOOL week_enable,UINT weekcolor,UCHAR weekformat,
	BOOL time_enable,UINT timecolor,UCHAR timeformat,
	BOOL text_enable,UINT textcolor,LPCWSTR statictext);

// ������	YQ_CreateCNTimeArea
// ����ֵ��	ָ���Ŀ����ľ��
// ������	
//			short X������x����
//			short Y������y����
//			short W���������
//			short H�������߶�
//			BYTE Transparency��������͸���� 0-100		
//			UCHAR timediff_flag��0-��ʱ�1-��ʱ�
//			UCHAR timediff_hour��ʱ���Сʱ����
//			UCHAR timediff_min��ʱ��ķ��Ӳ���
//			LPCWSTR font��ʱ�����ı�����
//			int fontsize�������С
//			BOOL bold���Ƿ�Ӵ�
//			BOOL italic���Ƿ�б��
//			BOOL underline���Ƿ��»���
//			UCHAR align�����뷽ʽ��0-����룬1-���ж��룬2-�Ҷ���
//			BOOL multiline���Ƿ����
//			BOOL day_enable���Ƿ�ʹ����ʾ����
//			UINT daycolor�����ڵ���ɫ
//			BOOL week_enable���Ƿ���ʾ����
//			UINT weekcolor��������ɫ
//			BOOL time_enable���Ƿ���ʾʱ��
//			UINT timecolor��ʱ����ɫ
//			BOOL text_enable���Ƿ�����Զ����ı�
//			UINT textcolor���Զ����ı���ɫ
//			LPCWSTR statictext���Զ����ı�����
// ˵����	������ʱ������
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateCNTimeArea(short x,short y,short w,short h,UCHAR transparency,
	UCHAR timediff_flag,UCHAR timediff_hour,UCHAR timediff_min,
	LPCWSTR font,UCHAR fontsize,BOOL bold,BOOL italic,BOOL underline,UCHAR align,BOOL multiline,
	BOOL day_enable,UINT daycolor,
	BOOL week_enable,UINT weekcolor,
	BOOL time_enable,UINT timecolor,BOOL text_enable,UINT textcolor,LPCWSTR statictext);

// ������	YQ_CreateTimeCounterArea
// ����ֵ��	ָ���Ŀ����ľ��
// ������	
//			short X������x����
//			short Y������y����
//			short W���������
//			short H�������߶�
//			BYTE Transparency��������͸���� 0-100
//			LPCWSTR font����ʱ���ı�����
//			int fontsize�������С
//			BOOL bold���Ƿ�Ӵ�
//			BOOL italic���Ƿ�б��
//			BOOL underline���Ƿ��»���
//			UCHAR align�����뷽ʽ��0-����룬1-���ж��룬2-�Ҷ���
//			BOOL multiline���Ƿ����
//			LPCWSTR target_date��Ŀ�����ڣ���ʽ2012-06-20
//			LPCWSTR target_time��Ŀ��ʱ�䣬��ʽ02-23-55
//			BOOL bTimeFlag��0-����ʱ��1-����ʱ
//			UINT counter_color����ʱ���ı���Ӧ����ɫ
//			BOOL day_enable���Ƿ���ʾ��
//			LPCWSTR daytext��������Ӧ��λ���ַ�����Ĭ���죬Ӣ��Ĭ��day
//			BOOL hour_enable���Ƿ���ʾСʱ
//			LPCWSTR hourtext��Сʱ��Ӧ��λ���ַ�����Ĭ��Сʱ��Ӣ��Ĭ��hour
//			BOOL min_enable���Ƿ���ʾ����
//			LPCWSTR minutetext�����ӵ�λ��Ӧ���ַ�����Ĭ�Ϸ֣�Ӣ��Ĭ��minute
//			BOOL sec_enable���Ƿ���ʾ��
//			LPCWSTR secondtext�����Ӧ��λ���ַ�����Ĭ���룬Ӣ��Ĭ��s
//			BOOL add_enable���Ƿ��ʱ�ۼ�
//			BOOL unit_enable���Ƿ���ʾ��λ���죬Сʱ����,�룩
//			BOOL text_enable���Ƿ�����Զ����ı�
//			UINT textcolor���Զ����ı���ɫ
//			LPCWSTR statictext���Զ����ı�����
// ˵����	������ʱʱ������
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateTimeCounterArea(short x,short y,short w,short h,UCHAR transparency,
	LPCWSTR font,UCHAR fontsize,BOOL bold,BOOL italic,BOOL underline,UCHAR align,BOOL multiline,
	LPCWSTR target_date,LPCWSTR target_time,BOOL bTimeFlag,UINT counter_color,
	BOOL day_enable,LPCWSTR daytext,BOOL hour_enable,LPCWSTR hourtext,BOOL min_enable,LPCWSTR minutetext,BOOL sec_enable,LPCWSTR secondtext,
	BOOL add_enable,BOOL unit_enable,
	BOOL text_enable,UINT textcolor,LPCWSTR statictext);

// ������	YQ_CreateLunarArea
// ����ֵ��	ָ���Ŀ����ľ��
// ������	
//			short X������x����
//			short Y������y����
//			short W���������
//			short H�������߶�
//			BYTE Transparency��������͸���� 0-100
//			LPCWSTR font���ı�����
//			int fontsize�������С
//			BOOL bold���Ƿ�Ӵ�
//			BOOL italic���Ƿ�б��
//			BOOL underline���Ƿ��»���
//			UCHAR align�����뷽ʽ��0-����룬1-���ж��룬2-�Ҷ���
//			BOOL multiline���Ƿ����
//			BOOL year_enable���Ƿ�ʹ����ʾ��
//			UINT yearcolor�������ɫ
//			BOOL day_enable���Ƿ�ʹ����ʾ����
//			UINT daycolor�����ڵ���ɫ
//			BOOL solarterms_enable���Ƿ�ʹ����ʾ����
//			UINT solartermscolor����������ɫ
//			BOOL text_enable���Ƿ�����Զ����ı�
//			UINT textcolor���Զ����ı���ɫ
//			LPCWSTR statictext���Զ����ı�����
// ˵����	����ũ������
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateLunarArea(short x,short y,short w,short h,UCHAR transparency,
	LPCWSTR font,UCHAR fontsize,BOOL bold,BOOL italic,BOOL underline,UCHAR align,BOOL multiline,
	BOOL year_enable,UINT yearcolor,BOOL day_enable,UINT daycolor,BOOL solarterms_enable,UINT solartermscolor,
	BOOL text_enable,UINT textcolor,LPCWSTR statictext);

// ������	YQ_CreateClockArea
// ����ֵ��	ָ���Ŀ����ľ��
// ������	
//			short X������x����
//			short Y������y����
//			short W���������
//			short H�������߶�
//			BYTE Transparency��������͸���� 0-100
//			BOOL text_enable���Ƿ�����Զ����ı�
//			UINT textcolor���Զ����ı���ɫ
//			LPCWSTR statictext���Զ����ı�����
//			LPCWSTR text_font���ı�����
//			int text_fontsize�������С
//			BOOL text_bold���Ƿ�Ӵ�
//			BOOL text_italic���Ƿ�б��
//			BOOL text_underline���Ƿ��»���
//			short text_x��Ĭ��0
//			short text_y��Ĭ��0
//			short text_w��Ĭ��0
//			short text_h��Ĭ��0
//			BOOL ymd_enable���Ƿ���ʾ������
//			UINT ymdcolor����������ɫ
//			UCHAR ymdformat�������ո�ʽ0-18
//			LPCWSTR ymd_font������������
//			UCHAR ymd_fontsize�������С
//			BOOL ymd_bold���Ƿ�Ӵ�
//			BOOL ymd_italic���Ƿ�б��
//			BOOL ymd_underline���Ƿ��»���
//			short ymd_x��Ĭ��0
//			short ymd_y��Ĭ��0
//			short ymd_w��Ĭ��0
//			short ymd_h��Ĭ��0
//			BOOL week_enable���Ƿ���ʾ����
//			UINT weekcolor��������ɫ
//			UCHAR weekformat�����ڸ�ʽ0-8
//			LPCWSTR week_font����������
//			UCHAR week_fontsize�������С
//			BOOL week_bold���Ƿ�Ӵ�
//			BOOL week_italic���Ƿ�б��
//			BOOL week_underline���Ƿ��»���
//			short week_x��Ĭ��0
//			short week_y��Ĭ��0
//			short week_w��Ĭ��0
//			short week_h��Ĭ��0
//			UINT hourhand_color��ʱ����ɫ
//			UINT minhand_color��������ɫ
//			UINT secondhand_color��������ɫ
//			UCHAR timediff_flag��0-��ʱ�1-��ʱ�
//			UCHAR timediff_hour��ʱ���Сʱ����
//			UCHAR timediff_min��ʱ��ķ��Ӳ���
//			int rightangle_shape��ʱ����״��0-����;1-����;2-����;3-����;4-����
//			int rightangle_width��ʱ���ȣ�Ĭ��2
//			int rightangle_color��ʱ����ɫ
//			int integral_shape��369����״��0-����;1-����;2-����;3-����;4-����
//			int integral_width,369����
//			int integral_color��369����ɫ
//			int minute_shape���ֵ���״��0-����;1-����;2-����
//			int minute_width���ֵ���
//			int minute_color���ֵ���ɫ
//			LPCWSTR szClockFile�����̶̿�ͼƬ��Ĭ�Ϸ�����Զ�����ƣ�����Ĭ��Ϊ��
// ˵����	������������
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateClockArea(short x,short y,short w,short h,UCHAR transparency,
	BOOL text_enable,UINT textcolor,LPCWSTR statictext,LPCWSTR text_font,UCHAR text_fontsize,BOOL text_bold,BOOL text_italic,BOOL text_underline,short text_x,short text_y,short text_w,short text_h,
	BOOL ymd_enable,UINT ymdcolor,UCHAR ymdformat,LPCWSTR ymd_font,UCHAR ymd_fontsize,BOOL ymd_bold,BOOL ymd_italic,BOOL ymd_underline,short ymd_x,short ymd_y,short ymd_w,short ymd_h,
	BOOL week_enable,UINT weekcolor,UCHAR weekformat,LPCWSTR week_font,UCHAR week_fontsize,BOOL week_bold,BOOL week_italic,BOOL week_underline,short week_x,short week_y,short week_w,short week_h,
	UINT hourhand_color,UINT minhand_color,UINT secondhand_color,
	UCHAR timediff_flag,UCHAR timediff_hour,UCHAR timediff_min,
	int rightangle_shape,int rightangle_width,int rightangle_color,
	int integral_shape,int integral_width,int integral_color,
	int minute_shape,int minute_width,int minute_color,LPCWSTR szClockFile);

// ������	YQ_CreateClockArea
// ����ֵ��	ָ���Ŀ����ľ��
// ������	
//			short X������x����
//			short Y������y����
//			short W���������
//			short H�������߶�
//			BYTE Transparency��������͸���� 0-100
//			BOOL text_enable���Ƿ�����Զ����ı�
//			UINT textcolor���Զ����ı���ɫ
//			LPCWSTR statictext���Զ����ı�����
//			LPCWSTR text_font���ı�����
//			int text_fontsize�������С
//			BOOL text_bold���Ƿ�Ӵ�
//			BOOL text_italic���Ƿ�б��
//			BOOL text_underline���Ƿ��»���
//			BOOL ymd_enable���Ƿ���ʾ������
//			UINT ymdcolor����������ɫ
//			BOOL week_enable���Ƿ���ʾ����
//			UINT weekcolor��������ɫ
//			UINT hourhand_color��ʱ����ɫ
//			UINT minhand_color��������ɫ
//			UINT secondhand_color��������ɫ
//			UCHAR timediff_flag��0-��ʱ�1-��ʱ�
//			UCHAR timediff_hour��ʱ���Сʱ����
//			UCHAR timediff_min��ʱ��ķ��Ӳ���
//			int rightangle_color��ʱ����ɫ
//			int integral_color��369����ɫ
//			int minute_color���ֵ���ɫ
//			UINT dwClockFormat�����̷��0-����;1-����;2-����;3-����;4-����
// ˵����	�����ض����ı�������
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateClockStyleArea(short x,short y,short w,short h,UCHAR transparency,
	BOOL text_enable,UINT textcolor,LPCWSTR statictext,LPCWSTR text_font,UCHAR text_fontsize,BOOL text_bold,BOOL text_italic,BOOL text_underline,
	BOOL ymd_enable,UINT ymdcolor,
	BOOL week_enable,UINT weekcolor,
	UINT hourhand_color,UINT minhand_color,UINT secondhand_color,
	UCHAR timediff_flag,UCHAR timediff_hour,UCHAR timediff_min,
	int rightangle_color,int integral_color,int minute_color,
	UINT dwClockFormat);

// ������	YQ_CreateVideoArea
// ����ֵ��	ָ���Ŀ����ľ��
// ������	
//			short X������x����
//			short Y������y����
//			short W���������
//			short H�������߶�
//			BYTE Transparency��������͸���� 0-100
// ˵����	������Ƶ����
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateVideoArea(short x,short y,short w,short h,UCHAR transparency);

// ������	YQ_CreatePicArea
// ����ֵ��	ָ���Ŀ����ľ��
// ������	
//			short X������x����
//			short Y������y����
//			short W���������
//			short H�������߶�
//			BYTE Transparency��������͸���� 0-100
//			UCHAR window_type����������,1��ͼƬ������2�����ַ�����3����Ļ������4��GIF ��̬ͼƬ����
//			BOOL bBgTransparent�������Ƿ�͸��
// ˵����	����ͼ������
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreatePicArea(short x,short y,short w,short h,UCHAR transparency,UCHAR window_type,UCHAR bBgTransparent);


// ������	YQ_VideoAreaAddUnit
// ����ֵ��	��
// ������	
//			DWORD hArea��������
//			LPCWSTR szVideoFile����Ƶ�ļ�ȫ·��
//			UCHAR scale_mode������ģʽ��0 �C ��ԭʼ�����������ţ�1 �C �����ڱ�����������
//			UCHAR volume������
// ˵����	����Ƶ��������������Ƶ��
LEDPROGRAMSDK_API void WINAPI YQ_VideoAreaAddUnit(DWORD hArea,LPCWSTR szVideoFile,UCHAR scale_mode,UCHAR volume);

// ������	YQ_PicAreaAddImageUnit
// ����ֵ��	��
// ������	
//			DWORD hArea��������
//			LPCWSTR szRtfFile��ͼƬ�ļ�ȫ·����Ŀǰ������bmp,jpg,png,gif
//			USHORT StayTime����ʾ������ͣ��ʱ��
//			BYTE DisplayEffects����ʾ�������ؼ����
//			BYTE DisplaySpeed����ʾ�������ؼ������ٶ�
// ˵����	��ͼ��������������ͼƬ��
LEDPROGRAMSDK_API void WINAPI YQ_PicAreaAddImageUnit(DWORD hArea,LPCWSTR szImgFile,UCHAR display_effects,UCHAR display_speed,USHORT stay_time);

// ������	YQ_PicAreaAddRtfUnit
// ����ֵ��	��
// ������	
//			DWORD hArea��������
//			LPCWSTR szRtfFile��rtf�ļ�ȫ·��
//			USHORT StayTime����ʾ������ͣ��ʱ��
//			BYTE DisplayEffects����ʾ�������ؼ����
//			BYTE DisplaySpeed����ʾ�������ؼ������ٶ�
// ˵����	��ͼ���������������ı���
LEDPROGRAMSDK_API void WINAPI YQ_PicAreaAddRtfUnit(DWORD hArea,LPCWSTR szRtfFile,UCHAR display_effects,UCHAR display_speed,USHORT stay_time);


// ������	YQ_ProgramAddArea
// ����ֵ��	��
// ������	
//			DWORD hArea��������
//			DWORD hProgram����Ŀ���
// ˵����	���Ŀ�������
LEDPROGRAMSDK_API void WINAPI YQ_ProgramAddArea(DWORD hProgram,DWORD hArea);

// ������	YQ_PlaylistAddProgram
// ����ֵ��	��
// ������	
//			DWORD hPlaylist�������б���
//			DWORD hProgram����Ŀ���
//			unsigned char play_mode������ģʽ��0 �C �������ţ�1 �C ���β���
//			unsigned int play_time������ʱ�����߲��Ŵ���
//			LPCWSTR aging_start_time������ʱЧ�Ŀ�ʼ���ڣ���ʽ2012-06-20
//			LPCWSTR aging_stop_time������ʱЧ��������
//			LPCWSTR period_ontime������ʱ�ο�ʼʱ��,��ʽ08:30:00
//			LPCWSTR period_offtime������ʱ�ν���ʱ��
//			unsigned char play_week��bit0 �� bit6 ���α�ʾ����һ�������죬��0����ʾ�����Ŀ���ܲ��ţ�1����ʾ�����Ŀ���Բ���
// ˵����	�򲥷��б���ӽ�Ŀ
LEDPROGRAMSDK_API void WINAPI YQ_PlaylistAddProgram(DWORD hPlaylist,DWORD hProgram,unsigned char play_mode,unsigned int play_time,LPCWSTR aging_start_time,LPCWSTR aging_stop_time,LPCWSTR period_ontime,LPCWSTR period_offtime,unsigned char play_week);

// ������	YQ_CreateDynamicArea
// ����ֵ��	ָ��̬���ľ��
// ������	
//			BYTE AreaID��
//			short X����̬��x����
//			short Y����̬��y����
//			short W����̬�����
//			short H����̬���߶�
//			BYTE Transparency����̬����͸���� 0-100
//			BYTE ProgrmRelation��1 ������Ŀ�󶨲��ţ�0 ������Ŀ������󲥷�
//			USHORT RelatedProgram���������Ľ�Ŀ��ţ����û�ж�Ӧ�����Ľ�ĿӦ��0xffff
//			BYTE RunTime��0-�󶨽�Ŀһ�𲥷ţ�1-��󶨽�Ŀ�ֲ�
//			BYTE RunMode����̬������ģʽ
//							0�� ��̬������ѭ����ʾ��
//							1�� ��̬������˳����ʾ����ʾ�����һҳ��Ͳ�����ʾ
//							2�� ��̬��������ʾ��ɺ�ֹ��ʾ���һҳ���ݡ�
//							3�� ��̬������ѭ����ʾ�������趨ʱ���������δ����ʱɾ����̬����Ϣ��
//							4--��̬������ѭ����ʾ�������趨ʱ���������δ����ʱ���� LOGO ͼƬ
//			short Timeout����̬�����ݸ��³�ʱʱ�䣬��λΪ��
//			BYTE DataType���������ͣ�0-ͼƬ��1-�ı�
//			short UriUpdateFrequency������Ƶ��
// ˵����	������̬��
LEDPROGRAMSDK_API DWORD WINAPI YQ_CreateDynamicArea(BYTE AreaID,short X,short Y,short W,short H,BYTE Transparency,BYTE	ProgrmRelation,	USHORT RelatedProgram,BYTE RunTime,BYTE RunMode,short Timeout,BYTE DataType,short UriUpdateFrequency);

// ������	YQ_DestroyDynamic
// ����ֵ��	��
// ������	
//			DWORD hArea��������
// ˵����	���ٴ����Ķ�̬��
LEDPROGRAMSDK_API void WINAPI YQ_DestroyDynamic(DWORD hArea);

// ������	YQ_DynamicAreaAddStrPage
// ����ֵ��	��
// ������	
//			DWORD hArea��������
//			USHORT StayTime����ʾ������ͣ��ʱ��
//			BYTE DisplayEffects����ʾ�������ؼ����
//			BYTE DisplaySpeed����ʾ�������ؼ������ٶ�
//			DWORD BgColor���ı�����ɫ
//			BYTE LinesSizes���ı��м��
//			BOOL bold���Ƿ�Ӵ�
//			BOOL italic���Ƿ�б��
//			BOOL underline���Ƿ��»���
//			BOOL strikeout���Ƿ��л���
//			BOOL antialiasing���Ƿ񷴾��
//			LPCWSTR str���ı�����
//			UINT txtcolor���ı���ɫ
//			LPCWSTR font���ı�����
//			int fontsize�������С
// ˵����	��̬������ı���ҳ
LEDPROGRAMSDK_API void WINAPI YQ_DynamicAreaAddStrPage(DWORD hArea,USHORT StayTime,BYTE DisplayEffects,BYTE DisplaySpeed,DWORD BgColor,BYTE LinesSizes,BOOL bold,BOOL italic,BOOL underline,BOOL strikeout,BOOL antialiasing,LPCWSTR str,UINT txtcolor,LPCWSTR font,int fontsize);

// ������	YQ_DynamicAreaAddPicPage
// ����ֵ��	��
// ������	
//			DWORD hArea��������
//			USHORT StayTime����ʾ������ͣ��ʱ��
//			BYTE DisplayEffects����ʾ�������ؼ����
//			BYTE DisplaySpeed����ʾ�������ؼ������ٶ�
//			char* Suffix��ͼƬ��ʽ��׺��,�ޡ�jpg�� ��bmp�� ��png������;����ΪСд
//			DWORD imgdatalen��ͼƬ���ݳ���
//			BYTE* imgdata��ͼƬ��������
// ˵����	��̬�����ͼƬ��ҳ
LEDPROGRAMSDK_API void WINAPI YQ_DynamicAreaAddPicPage(DWORD hArea,USHORT StayTime,BYTE DisplayEffects,BYTE DisplaySpeed,char* Suffix,DWORD imgdatalen,BYTE* imgdata);

LEDPROGRAMSDK_API void WINAPI YQ_DynamicAreaAddPicRefPage(DWORD hArea,USHORT StayTime,BYTE DisplayEffects,BYTE DisplaySpeed,char* Suffix,char* user,char* pwd,char* url);

LEDPROGRAMSDK_API void WINAPI YQ_DynamicAreaAddStrRefPage(DWORD hArea,USHORT StayTime,BYTE DisplayEffects,BYTE DisplaySpeed,BYTE FontCode,DWORD BgColor,BYTE LinesSizes,char* user,char* pwd,char* url);