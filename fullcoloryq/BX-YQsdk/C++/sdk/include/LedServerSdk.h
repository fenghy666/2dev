
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


typedef struct _CARD_SERVER
{
	unsigned char	PID[16];//控制器唯一ID
	char			barcode[16];//控制器条形码
}server_card;


LEDNETSDK_API int   WINAPI Server_Start(USHORT port);

LEDNETSDK_API int	WINAPI Server_GetCardList(server_card *pList);

LEDNETSDK_API void  WINAPI Server_Close();

LEDNETSDK_API int WINAPI Server_GetModeinfo(unsigned char* pid,char* ServerIPAddress,USHORT* ServerPort);


// 函数：	Server_GetNetinfo
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned char* pid：通讯句柄
//			USHORT* ControllerType：传出参数，返回控制器型号
//			short* ScreenWidth：传出参数，返回led屏幕宽度
//			short* ScreenHeight：传出参数，返回led屏幕高度
//			char* FirmwareVersion：传出参数，返回控制器固件版本
// 说明：	获取控制器参数信息和屏幕参数信息
LEDNETSDK_API int WINAPI Server_GetNetinfo(unsigned char* pid,unsigned char* ControlerID,char* ip,char* mask,char* gateway,BYTE* pConnectMode);
LEDNETSDK_API int WINAPI Server_GetScreeninfo(unsigned char* pid,USHORT *pControllerType,short* w,short* h);
LEDNETSDK_API int WINAPI Server_GetFirmwareinfo(unsigned char* pid,char* FirmwareTime,char* FirmwarelVersion);
LEDNETSDK_API int WINAPI Server_GetBrightness(unsigned char* pid,BYTE* pMode,BYTE* pValue);
LEDNETSDK_API int WINAPI Server_GetVolume(unsigned char* pid,BYTE* pVolume);
LEDNETSDK_API int WINAPI Server_GetOnoff(unsigned char* pid,BYTE* onoff);

// 函数：	Server_SetScreenSize
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned char* pid：通讯句柄
//			short ScreenWidth：led屏幕宽度
//			short ScreenHeight：led屏幕高度
// 说明：	设置控制器的屏幕参数信息
LEDNETSDK_API int WINAPI Server_SetScreenSize(unsigned char* pid,short ScreenWidth,short ScreenHeight);


// 函数：	Server_SendPrograms
// 返回值：	成功返回发送需要的句柄；失败返回0
// 参数：	
//			unsigned char* pid：通讯句柄
//			unsigned char media：控制器存储节目的介质
//			DWORD hPlaylist：播放列表对应的句柄
//			LPCTSTR szLocalTempDir：发送节目时需要在本地生成节目文件，该参数为临时文件的存放目录
// 说明：	发送节目到控制器
LEDNETSDK_API DWORD WINAPI Server_SendPrograms(unsigned char* pid,unsigned char media,DWORD hPlaylist,LPCTSTR szLocalTempDir,char* ftpIp,short ftpPort,char* ftpuser,char* ftppwd,int* pErr);

// 函数：	Server_GetSendProcess
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			DWORD dwSendHand：发送句柄
//			int* total_percent：传入参数，当前发送的总进度
//			int* cur_percent：传入参数，当前文件发送的进度
// 说明：	发送指定节目时查看发送进度
LEDNETSDK_API int WINAPI Server_GetSendProcess(DWORD dwSendHand,int* total_percent,int* cur_percent);
LEDNETSDK_API int WINAPI Server_GetDownProcess(DWORD dwSendHand,int* down_percent);

// 函数：	Server_CancelSend
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			DWORD dwSendHand：发送句柄
// 说明：	无论发送是否完成，结束发送节目
LEDNETSDK_API int WINAPI Server_CancelSend(DWORD dwSendHand);


// 函数：	Server_StopPlay
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned char* pid：通讯句柄
// 说明：	停止播放节目
LEDNETSDK_API int WINAPI Server_StopPlay(unsigned char* pid);

// 函数：	Server_SetVolume
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned char* pid：通讯句柄
//			BYTE bVolume：音量值，0-100
// 说明：	设置音量
LEDNETSDK_API int WINAPI Server_SetVolume(unsigned char* pid,BYTE bVolume);

// 函数：	Server_AdjustBrightness
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned char* pid：通讯句柄
//			BYTE mode：调整模式，0x00–手动调亮；0x01–定时调亮；0x02–自动调亮（需外接传感器）
//			short* bright_table：亮度表
// 说明：	设置亮度
//			亮度表主要针对定时调亮，每30分钟一个值，所以一天48个值
//			bright_table[0]=00:00 – 00:29 间的亮度值
//			bright_table[1]=00:30 – 00:59 间的亮度值
//			......
//			bright_table[47]=23:30 – 23:59 间的亮度值
//			手动调亮可以将所有值设为相同，每个值范围0-255
LEDNETSDK_API int WINAPI Server_AdjustBrightness(unsigned char* pid,BYTE mode,short* bright_table);

// 函数：	Server_SystemTimeCorrect
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned char* pid：通讯句柄
// 说明：	校正控制器时间
LEDNETSDK_API int WINAPI Server_TimeCorrect(unsigned char* pid);

// 函数：	Server_OpenScreen
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned char* pid：通讯句柄
// 说明：	开屏幕
LEDNETSDK_API int WINAPI Server_OpenScreen(unsigned char* pid);

// 函数：	Server_CloseScreen
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned char* pid：通讯句柄
// 说明：	关屏幕
LEDNETSDK_API int WINAPI Server_CloseScreen(unsigned char* pid);

// 函数：	Server_SwitchOnTime
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned char* pid：通讯句柄
//			LPCSTR SwitchScreenFilePath：定时开关机文件路径
// 说明：	设置定时关机
LEDNETSDK_API int WINAPI Server_SwitchOnTime(unsigned char* pid,char* OnTm1,char* OffTm1,char* OnTm2,char* OffTm2,char* OnTm3,char* OffTm3,char* OnTm4,char* OffTm4,char* ftpIp,short ftpPort,char* ftpuser,char* ftppwd);

// 函数：	Server_Update
// 返回值：	成功返回0；失败返回错误号
// 参数：	
//			unsigned char* pid：通讯句柄
// 说明：	关屏幕
LEDNETSDK_API int WINAPI Server_Update(unsigned char* pid,LPCTSTR strMd5File,LPCTSTR strUpdateFile,char* ftpIp,short ftpPort,char* ftpuser,char* ftppwd);


LEDNETSDK_API int WINAPI Server_UpdateDynamicArea(unsigned char* pid,DWORD hArea);

LEDNETSDK_API int WINAPI Server_RemoveDynamicArea(unsigned char* pid,int AreaId);

LEDNETSDK_API int WINAPI Server_SaveDynamicArea(unsigned char* pid,BYTE AreaID);

LEDNETSDK_API int WINAPI Server_DelSaveDynamicArea(unsigned char* pid);