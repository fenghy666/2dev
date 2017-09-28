#ifndef _LEDCOMMON_H

// 错误码
typedef enum SDK_ERR
{
	ERR_NO						=0x00,	//命令正确完成，没有错误

	ERR_OUTOFGROUP				=0x01,	//命令组错误 
	ERR_NOCMD					=0x02,	//此命令不存在 
	ERR_BUSY					=0x03,	//控制器忙 
	ERR_MEMORYVOLUME			=0x04,	//存储器容量越界 
	ERR_CHECKSUM				=0x05,	//数据包 CRC 校验错误 
	ERR_FILENOTEXIST			=0x06,	//此文件不存在 
	ERR_FLASH					=0x07,	//Flash访问错误 
	ERR_FILE_DOWNLOAD			=0x08,	//文件下载错误 
	ERR_FILE_NAME				=0x09,	//文件名错误 
	ERR_FILE_TYPE				=0x0a,	//文件类型错误 
	ERR_FILE_CRC16				=0x0b,	//文件校验错误 
	ERR_FONT_NOT_EXIST			=0x0c,	//字库文件不存在 
	ERR_FIRMWARE_TYPE			=0x0d,	//Firmware 与控制器类型不匹配 
	ERR_DATE_TIME_FORMAT		=0x0e,	//日期时间格式错误 
	ERR_FILE_EXIST				=0x0f,	//此文件已存在 
	ERR_FILE_BLOCK_NUM			=0x10,	//文件 Block 号错误 
	ERR_CONTROLLER_TYPE			=0x11,	//控制器类型不匹配 
	ERR_SCREEN_PARA				=0x12,	//控制器参数越界或错误 
	ERR_CONTROLLER_ID			=0x13,	//读取控制器 ID 错误 
	ERR_USER_SECRET				=0x14,	//通讯时用户密码错误 
	ERR_OLD_SECRET				=0x15,	//修改密码时输入的老密码错误 
	ERR_PHY1_NO_SECRET			=0x16,	//通讯时以加密 2 方式运行提示物理层 PHY1 没有设定过密码
	ERR_PHY_USE_SECTET			=0x17,	//通讯时以固定加密 1 方式运行提示物理层 PHY1 没有设定过密码
	ERR_FILE_READ				=0x18,	//读取文件失败 
	ERR_XML_TOP					=0x19,	//提取 XML 文件顶层元素失败 
	ERR_DIR_NULL				=0x1a,	//路径错误,空路径 
	ERR_DIR_MK					=0x1b,	//创建路径失败 
	ERR_DIR_NOT_EXIST			=0x1c,	//此路径不存在 
	ERR_NOHEAD					=0x1d,	//报文无头部 ，包头错误  
	ERR_DISK_NAME				=0x1e,	//驱动器名称错误 
	ERR_DISK_NOT_EXIST			=0x1f,	//驱动器不存在(被拔除或者卸载了)
	ERR_OPEN_FILE				=0x20,	//打开文件失败 
	ERR_FILE_SEEK				=0x21,	//文件偏移错误 
	ERR_CMD_UNFINISHED			=0x22,	//命令未能正常完成 ,但是原因不详
	ERR_CMD_DBG					=0x23,	//命令尚未设计完成 ，还处于调试阶段
	ERR_CMD_NOT_SUPPORT			=0x24,	//命令不被支持 
	ERR_PERMISSIONS				=0x25,	//权限不够 
	ERR_UNLAWFUL_OPERATION		=0x26,	//非法操作 
	ERR_NO_RTC_CHIP				=0x27,	//找不到 RTC 芯片 
	ERR_APP_NUM					=0x28,	//已经安装有 5 个 app ，必须先卸载一
	ERR_APP_NOT_EXIST			=0x29,	//不存在这个程序 
	ERR_APP_EXIST				=0x2a,	//已经安装这个程序 
	ERR_CMD_BUSY				=0x2b,	//控制器忙 (这个命令暂时
	ERR_NO_LIST_PLAYING			=0x2c,	//播放列表未加载 
	ERR_NO_PROGRAM_PLAYING		=0x2d,	//当前无节目播放 
	ERR_APP_PATH				=0x2e,	//路径出错 
	ERR_MEMRY_USEOUT			=0x2f,	//控制器内存耗尽 
	ERR_FTP_IP					=0x30,	//ftp 的 ip 不可达 
	ERR_USER_EXIST				=0x31,	//已经有此用户 
	ERR_NOT_LOGIN				=0x32,	//未登录 
	ERR_USER_NOT_EXIST			=0x33,	//无此用户 
	ERR_USER_PASSWORD			=0x34,	//密码错误 
	ERR_USER_ALREADY_LOGIN		=0x35,	//已经有用户登录 
	ERR_PASSWORD_INCONSISTENT	=0x36,	//密码不一致 
	ERR_USER_NUM_MAX			=0x37,	//用户已满 
	ERR_USER_NAME_NULL			=0x38,	//用户名为空 
	ERR_LOG_MODE				=0x39,	//非法日志模式 
	ERR_READ_DIR				=0x3a,	//读目录失败 
	ERR_IP_FORMAT				=0x3b,	//ip 格式错误
	ERR_NULL_TARGET				=0x3c,	//FTP 下载  目标名称为空 
	ERR_NULL_PATH				=0x3d,	//FTP 下载 目标路径为空 
	ERR_NULL_USER				=0x3e,	//FTP 下载 用户为空 
	ERR_NULL_IP					=0x3f,	//FTP 下载 用户为空 
	ERR_FONT_FORMAT				=0x40,	//字库格式错误 
	ERR_PROPERTY_NOT_EXIST		=0x41,	//访问的属性不存在 
	ERR_PROPERTY_READONLY		=0x42,	//只读属性，不能修改

	ERR_Unknow					=0x0100,//未知错误
	ERR_TIMEOUT					=0x0101,//通讯超时,可能网络故障
	ERR_DiskSpace				=0x0102,//控制器工作目录空间不足
	ERR_Hand					=0x0103,//未建立通讯连接
	ERR_SCREENSIZE				=0x0104,//屏幕宽或高不合理
	ERR_PATH					=0x0105,//错误的文件路径
	ERR_CMD						=0x0106,//错误的命令
	ERR_PROPERTY				=0x0107,//错误的属性类型
	ERR_UPLOAD					=0x0108,//上传失败
	ERR_TASKEXIST				=0x0109,//任务队列非空
	ERR_PARAM					=0x010a,//参数不合理
	ERR_CANCEL					=0x010b,//发送被取消
	ERR_DOWNLOAD				=0x010c,//控制器下载失败
	ERR_PROGRAM_SIZE			=0x010d,//节目大小超出控制器最大容量
	ERR_SENDHAND				=0x010e,//无效的发送句柄，发送已结束或为开始

}sdk_err;


typedef enum ONBON_YQ_CARD_TYPE:USHORT
{
	ONBON_BX_YQ1_75=0x0158,
	ONBON_BX_YQ1=0x0258,
	ONBON_BX_YQ2=0x0358,
	ONBON_BX_YQ3=0x0458,
	ONBON_BX_YQ4=0x0558,
	ONBON_BX_YQ2E=0x0658,
	ONBON_BX_YQ5=0x758,
}onbon_yq_card_type;

//特技种类
enum TransitionMode {
	eNone=0,					//快速打出		
	eRandom, 					//随机			
	eStatic, 					//静止显示		
	ePushUp, 					//向上推入		
	ePushDown, 					//向下推入		
	ePushLeft, 					//向左推入		
	ePushRight, 				//向右推入		
	eSlideInFromTop, 			//从上移入		
	eSlideInFromBottom, 		//从下移入		
	eSlideInFromLeft,			//从左移入		
	eSlideInFromRight, 			//从右移入		
	eBuildUpFromUp, 			//向上堆积		
	eBuildUpFromDown, 			//向下堆积		
	eBuildUpFromLeft, 			//向左堆积		
	eBuildUpFromRight,			//向右堆积		
	eRevealFromBottom, 			//向上拉幕		
	eRevealFromUp, 				//向下拉幕		
	eRevealFromRight,			//向左拉幕		
	eRevealFromLeft, 			//向右拉幕
	eRevealFromTopLeft, 		//左上角拉幕		
	eRevealFromTopRight,		//右上角拉幕		
	eRevealFromBottomLeft,		//左下角拉幕		
	eRevealFromBottomRight,		//右下角拉幕		
	eRevealInToCentre,			//四周往中心拉幕	
	eFourCornerIn,				//从四角拉幕进入	
	eFourCornerOut,				//从四角拉幕退出	
	eBarsFromBothSides,			//左右交叉拉幕	
	eBarsFromTopAndBottom, 		//上下交叉拉幕			
	eBlindVertically,			//垂直百叶		
	eBlindHorizontally,			//水平百叶		
	eSlindInFromTopAndBottom,	//上下闭合		
	eRevealFromMiddle,			//上下对开		
	eRevealOutFromMiddle,		//左右开幕		
	eRevealInFromSides, 		//左右闭合		
	eExpandOutFromCentre,		//中心放大			
	eRandomSquaresAppear, 		//马赛克	
	eFade,						//淡入淡出		
	eExpandFromLeft, 			//从左拉伸		
	eBoxLineWipe,				//箱盒擦除		
	eWipeBox,					//盒子擦除		
	eZoomOut,					//比例缩小		
	eZoomOut_tail,				//中心缩小			
	eLeftRollIn,				//左滚入			
	eRightRollIn, 				//右滚入		
	eContinuousPushUp,			//向上连移		
	eContinuousPushDown,		//向下连移		
	eContinuousPushLeft, 		//向左连移		
	eContinuousPushRight, 		//向右连移	

};
#ifdef LEDNETSDK_EXPORTS
#define LEDNETSDK_API extern "C" __declspec(dllexport)
#else
#define LEDNETSDK_API extern "C" __declspec(dllimport)
#endif

// 函数：	Sdk_Init
// 返回值：	无
// 参数：	无
// 说明：	初始化SDK通讯库
LEDNETSDK_API void WINAPI Sdk_Init();

// 函数：	Sdk_Release
// 返回值：	无
// 参数：	无
// 说明：	释放SDK通讯库
LEDNETSDK_API void WINAPI Sdk_Release();

#endif

