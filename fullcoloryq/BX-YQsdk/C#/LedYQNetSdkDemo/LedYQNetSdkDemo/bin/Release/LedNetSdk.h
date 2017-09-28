
/************************************************************************
 * file:	LedNetSdk.h
 * brief:	Header file of Network communication library in network part
 * author:	niu.zhimin
 * date:	2014-11-01
 ***********************************************************************/


#ifdef LEDNETSDK_EXPORTS
#define LEDNETSDK_API extern "C" __declspec(dllexport)
#else
#define LEDNETSDK_API extern "C" __declspec(dllimport)
#endif




//控制器信息
typedef struct _CARD_UNIT
{
	unsigned char	PID[16];//控制器唯一ID
	char			barcode[16];//控制器条形码
	char			ip[16];//控制器地址
}card_unit;



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


// 函数：	Net_SearchCards
// 返回值：	搜索到的控制器个数
// 参数：	
//			card_unit* pCardList：存放控制器列表的缓冲区
//			int ntimeout：查找时的超时时间
// 说明：	在局域网内搜索所有控制器
LEDNETSDK_API int WINAPI Net_SearchCards(card_unit* pCardList,int ntimeout);

// 函数：	Net_SetStaticip
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned char* pid：控制器唯一ID
//			char* ip：控制器地址
//			char* mask：子网掩码
//			char* gateway：网关地址
// 说明：	设置控制器的网络地址
LEDNETSDK_API int WINAPI Net_SetStaticip(unsigned char* pid,char* ip,char* mask,char* gateway);

// 函数：	Net_SetAutoip
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned char* pid：控制器唯一ID
// 说明：	设置控制器通过DHCP获取网络地址
LEDNETSDK_API int WINAPI Net_SetAutoip(unsigned char* pid);

// 函数：	Net_GetIp
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned char* pid：控制器唯一ID
//			char* ip：控制器地址
// 说明：	查询指定控制器的网络地址
LEDNETSDK_API int WINAPI Net_GetIp(unsigned char* pid,char* ip);

// 函数：	Net_SetServerMode
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			char* serverip：控制器要连接的服务器的ip地址
//			unsigned short port：服务器所用的端口
// 说明：	将工作模式切换为连接服务器模式
// 警告:	执行本函数将会重启控制器
LEDNETSDK_API int WINAPI Net_SetServerMode(char* ip,char* serverip,unsigned short port);

// 函数：	Net_SetClientMode
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
// 说明：	将工作模式切换为连接服务器模式
// 警告:	执行本函数将会重启控制器
LEDNETSDK_API int WINAPI Net_SetClientMode(char* ip);

// 函数：	Net_GetModeinfo
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			unsigned char* mode：控制器工作模式
//			char* ServerIPAddress：控制器要连接的服务器的ip地址
//			unsigned short port：服务器所用的端口
// 说明：	查询控制器工作模式，如果是服务器模式返回服务器地址
LEDNETSDK_API int WINAPI Net_GetModeinfo(char* ip,unsigned char* mode,char* ServerIPAddress,unsigned short* ServerPort);

// 函数：	Net_GetNetinfo
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			USHORT* ControllerType：传出参数，返回控制器型号
//			short* ScreenWidth：传出参数，返回led屏幕宽度
//			short* ScreenHeight：传出参数，返回led屏幕高度
//			char* FirmwareVersion：传出参数，返回控制器固件版本
// 说明：	获取控制器参数信息和屏幕参数信息
LEDNETSDK_API int WINAPI Net_GetNetinfo(char* ip,unsigned char* ControlerID,char* netip,char* mask,char* gateway,BYTE* pConnectMode);

// 函数：	Net_GetNetinfo
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			USHORT* ControllerType：传出参数，返回控制器型号
//			short* ScreenWidth：传出参数，返回led屏幕宽度
//			short* ScreenHeight：传出参数，返回led屏幕高度
// 说明：	获取控制器参数信息和屏幕参数信息
LEDNETSDK_API int WINAPI Net_GetScreeninfo(char* ip,unsigned short *pControllerType,short* w,short* h);

// 函数：	Net_GetFirmwareinfo
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			USHORT* ControllerType：传出参数，返回控制器型号
//			char* FirmwareTime：传出参数，返回固件创建时间
//			char* FirmwareVersion：传出参数，返回控制器固件版本
// 说明：	获取控制器固件信息
LEDNETSDK_API int WINAPI Net_GetFirmwareinfo(char* ip,char* FirmwareTime,char* FirmwarelVersion);

// 函数：	Net_GetBrightness
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			BYTE* pMode：传出参数，返回控制器亮度所用的模式,0-手工调亮,1-定时调亮，2-传感器默认调亮，3-传感器调亮
//			BYTE* pValue：传出参数，返回亮度值，如果不是手工调亮，返回的是一个48字节长的亮度列表，每个字节对应半个小时的亮度值
// 说明：	获取控制器当前亮度信息
LEDNETSDK_API int WINAPI Net_GetBrightness(char* ip,BYTE* pMode,BYTE* pValue);

// 函数：	Net_GetVolume
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			BYTE* pVolume：传出参数，返回控制器音量
// 说明：	获取控制器参数信息和屏幕参数信息
LEDNETSDK_API int WINAPI Net_GetVolume(char* ip,BYTE* pVolume);

// 函数：	Net_GetOnoff
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			BYTE* onoff：传出参数，返回控制器当前屏幕开关状态，0:手动关闭 1：手动打开 2：自动关闭 3：自动打开
// 说明：	获取控制器屏幕开关信息
LEDNETSDK_API int WINAPI Net_GetOnoff(char* ip,BYTE* onoff);

// 函数：	Net_SetScreenSize
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			short ScreenWidth：led屏幕宽度
//			short ScreenHeight：led屏幕高度
// 说明：	设置控制器的屏幕参数信息
LEDNETSDK_API int WINAPI Net_SetScreenSize(char* ip,short ScreenWidth,short ScreenHeight);


// 函数：	Net_SendProgram
// 返回值：	成功返回发送需要的句柄；失败返回0
// 参数：	
//			char* ip：通讯地址
//			unsigned char media：控制器存储节目的介质
//			DWORD hPlaylist：播放列表对应的句柄
//			LPCWSTR szLocalTempDir：发送节目时需要在本地生成节目文件，该参数为临时文件的存放目录
//			int *pErr：如果有错误，返回的错误号
// 说明：	发送节目到控制器
LEDNETSDK_API DWORD WINAPI Net_SendPrograms(char* ip,unsigned char media,DWORD hPlaylist,LPCWSTR szLocalTempDir,int *pErr);

// 函数：	Net_GetSendProcess
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			DWORD dwSendHand：发送句柄
//			int* total_percent：传入参数，当前发送的总进度
//			int* cur_percent：传入参数，当前文件发送的进度
// 说明：	发送指定节目时查看发送进度
LEDNETSDK_API int WINAPI Net_GetSendProcess(DWORD dwSendHand,int* total_percent,int* cur_percent);

// 函数：	Net_CancelSend
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			DWORD dwSendHand：发送句柄
// 说明：	无论发送是否完成，结束发送节目
LEDNETSDK_API int WINAPI Net_CancelSend(DWORD dwSendHand);

// 函数：	Net_StopPlay
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
// 说明：	停止播放节目
LEDNETSDK_API int WINAPI Net_StopPlay(char* ip);

// 函数：	Net_SetVolume
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			BYTE bVolume：音量值，0-100
// 说明：	设置音量
LEDNETSDK_API int WINAPI Net_SetVolume(char* ip,BYTE bVolume);

// 函数：	Net_AdjustBrightness
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			BYTE mode：调整模式，0x00–手动调亮；0x01–定时调亮；0x02–自动调亮（需外接传感器）
//			short* bright_table：亮度表
// 说明：	设置亮度
//			亮度表主要针对定时调亮，每30分钟一个值，所以一天48个值
//			bright_table[0]=00:00 – 00:29 间的亮度值
//			bright_table[1]=00:30 – 00:59 间的亮度值
//			......
//			bright_table[47]=23:30 – 23:59 间的亮度值
//			手动调亮可以将所有值设为相同，每个值范围0-255
LEDNETSDK_API int WINAPI Net_AdjustBrightness(char* ip,BYTE mode,short* bright_table);

// 函数：	Net_SystemTimeCorrect
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
// 说明：	校正控制器时间
LEDNETSDK_API int WINAPI Net_TimeCorrect(char* ip);

// 函数：	Net_OpenScreen
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
// 说明：	开屏幕
LEDNETSDK_API int WINAPI Net_OpenScreen(char* ip);

// 函数：	Net_CloseScreen
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
// 说明：	关屏幕
LEDNETSDK_API int WINAPI Net_CloseScreen(char* ip);

// 函数：	Net_SwitchOnTime
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			char* OnTm1：第一个时间段的开机时间，格式12:56:09
//			char* OffTm1：第一个时间段的关机时间，格式12:56:09
//			LPCSTR SwitchScreenFilePath：定时开关机文件路径
// 说明：	设置定时关机
LEDNETSDK_API int WINAPI Net_SwitchOnTime(char* ip,char* OnTm1,char* OffTm1,char* OnTm2,char* OffTm2,char* OnTm3,char* OffTm3,char* OnTm4,char* OffTm4);

// 函数：	Net_Update
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			LPCWSTR strMd5File：固件文件之一，固件的描述文件
//			LPCWSTR strUpdateFile：固件文件之一，固件文件
// 说明：	升级控制器的固件
LEDNETSDK_API int WINAPI Net_Update(char* ip,LPCWSTR strMd5File,LPCWSTR strUpdateFile);

// 函数：	Net_UpdateDynamicArea
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			DWORD hArea：区域句柄
// 说明：	更新动态区
LEDNETSDK_API int WINAPI Net_UpdateDynamicArea(char* ip,DWORD hArea);

// 函数：	Net_RemoveDynamicArea
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			char* ip：控制器地址
//			int AreaId：动态区域编号
// 说明：	删除控制器上的动态区域
LEDNETSDK_API int WINAPI Net_RemoveDynamicArea(char* ip,int AreaId);


LEDNETSDK_API int WINAPI Net_SaveDynamicArea(char* ip,BYTE AreaID);

LEDNETSDK_API int WINAPI Net_DelSaveDynamicArea(char* ip);

//SaveLock：0掉电不保存  1掉电保存
LEDNETSDK_API int WINAPI Net_LockProgram(char* ip,int program_id,BYTE SaveLock);

LEDNETSDK_API int WINAPI Net_UnLockProgram(char* ip);