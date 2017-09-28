
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
	unsigned char	PID[16];//������ΨһID
	char			barcode[16];//������������
}server_card;


LEDNETSDK_API int   WINAPI Server_Start(USHORT port);

LEDNETSDK_API int	WINAPI Server_GetCardList(server_card *pList);

LEDNETSDK_API void  WINAPI Server_Close();

LEDNETSDK_API int WINAPI Server_GetModeinfo(unsigned char* pid,char* ServerIPAddress,USHORT* ServerPort);


// ������	Server_GetNetinfo
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned char* pid��ͨѶ���
//			USHORT* ControllerType���������������ؿ������ͺ�
//			short* ScreenWidth����������������led��Ļ���
//			short* ScreenHeight����������������led��Ļ�߶�
//			char* FirmwareVersion���������������ؿ������̼��汾
// ˵����	��ȡ������������Ϣ����Ļ������Ϣ
LEDNETSDK_API int WINAPI Server_GetNetinfo(unsigned char* pid,unsigned char* ControlerID,char* ip,char* mask,char* gateway,BYTE* pConnectMode);
LEDNETSDK_API int WINAPI Server_GetScreeninfo(unsigned char* pid,USHORT *pControllerType,short* w,short* h);
LEDNETSDK_API int WINAPI Server_GetFirmwareinfo(unsigned char* pid,char* FirmwareTime,char* FirmwarelVersion);
LEDNETSDK_API int WINAPI Server_GetBrightness(unsigned char* pid,BYTE* pMode,BYTE* pValue);
LEDNETSDK_API int WINAPI Server_GetVolume(unsigned char* pid,BYTE* pVolume);
LEDNETSDK_API int WINAPI Server_GetOnoff(unsigned char* pid,BYTE* onoff);

// ������	Server_SetScreenSize
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned char* pid��ͨѶ���
//			short ScreenWidth��led��Ļ���
//			short ScreenHeight��led��Ļ�߶�
// ˵����	���ÿ���������Ļ������Ϣ
LEDNETSDK_API int WINAPI Server_SetScreenSize(unsigned char* pid,short ScreenWidth,short ScreenHeight);


// ������	Server_SendPrograms
// ����ֵ��	�ɹ����ط�����Ҫ�ľ����ʧ�ܷ���0
// ������	
//			unsigned char* pid��ͨѶ���
//			unsigned char media���������洢��Ŀ�Ľ���
//			DWORD hPlaylist�������б��Ӧ�ľ��
//			LPCTSTR szLocalTempDir�����ͽ�Ŀʱ��Ҫ�ڱ������ɽ�Ŀ�ļ����ò���Ϊ��ʱ�ļ��Ĵ��Ŀ¼
// ˵����	���ͽ�Ŀ��������
LEDNETSDK_API DWORD WINAPI Server_SendPrograms(unsigned char* pid,unsigned char media,DWORD hPlaylist,LPCTSTR szLocalTempDir,char* ftpIp,short ftpPort,char* ftpuser,char* ftppwd,int* pErr);

// ������	Server_GetSendProcess
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			DWORD dwSendHand�����;��
//			int* total_percent�������������ǰ���͵��ܽ���
//			int* cur_percent�������������ǰ�ļ����͵Ľ���
// ˵����	����ָ����Ŀʱ�鿴���ͽ���
LEDNETSDK_API int WINAPI Server_GetSendProcess(DWORD dwSendHand,int* total_percent,int* cur_percent);
LEDNETSDK_API int WINAPI Server_GetDownProcess(DWORD dwSendHand,int* down_percent);

// ������	Server_CancelSend
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			DWORD dwSendHand�����;��
// ˵����	���۷����Ƿ���ɣ��������ͽ�Ŀ
LEDNETSDK_API int WINAPI Server_CancelSend(DWORD dwSendHand);


// ������	Server_StopPlay
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned char* pid��ͨѶ���
// ˵����	ֹͣ���Ž�Ŀ
LEDNETSDK_API int WINAPI Server_StopPlay(unsigned char* pid);

// ������	Server_SetVolume
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned char* pid��ͨѶ���
//			BYTE bVolume������ֵ��0-100
// ˵����	��������
LEDNETSDK_API int WINAPI Server_SetVolume(unsigned char* pid,BYTE bVolume);

// ������	Server_AdjustBrightness
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned char* pid��ͨѶ���
//			BYTE mode������ģʽ��0x00�C�ֶ�������0x01�C��ʱ������0x02�C�Զ�����������Ӵ�������
//			short* bright_table�����ȱ�
// ˵����	��������
//			���ȱ���Ҫ��Զ�ʱ������ÿ30����һ��ֵ������һ��48��ֵ
//			bright_table[0]=00:00 �C 00:29 �������ֵ
//			bright_table[1]=00:30 �C 00:59 �������ֵ
//			......
//			bright_table[47]=23:30 �C 23:59 �������ֵ
//			�ֶ��������Խ�����ֵ��Ϊ��ͬ��ÿ��ֵ��Χ0-255
LEDNETSDK_API int WINAPI Server_AdjustBrightness(unsigned char* pid,BYTE mode,short* bright_table);

// ������	Server_SystemTimeCorrect
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned char* pid��ͨѶ���
// ˵����	У��������ʱ��
LEDNETSDK_API int WINAPI Server_TimeCorrect(unsigned char* pid);

// ������	Server_OpenScreen
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned char* pid��ͨѶ���
// ˵����	����Ļ
LEDNETSDK_API int WINAPI Server_OpenScreen(unsigned char* pid);

// ������	Server_CloseScreen
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned char* pid��ͨѶ���
// ˵����	����Ļ
LEDNETSDK_API int WINAPI Server_CloseScreen(unsigned char* pid);

// ������	Server_SwitchOnTime
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned char* pid��ͨѶ���
//			LPCSTR SwitchScreenFilePath����ʱ���ػ��ļ�·��
// ˵����	���ö�ʱ�ػ�
LEDNETSDK_API int WINAPI Server_SwitchOnTime(unsigned char* pid,char* OnTm1,char* OffTm1,char* OnTm2,char* OffTm2,char* OnTm3,char* OffTm3,char* OnTm4,char* OffTm4,char* ftpIp,short ftpPort,char* ftpuser,char* ftppwd);

// ������	Server_Update
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned char* pid��ͨѶ���
// ˵����	����Ļ
LEDNETSDK_API int WINAPI Server_Update(unsigned char* pid,LPCTSTR strMd5File,LPCTSTR strUpdateFile,char* ftpIp,short ftpPort,char* ftpuser,char* ftppwd);


LEDNETSDK_API int WINAPI Server_UpdateDynamicArea(unsigned char* pid,DWORD hArea);

LEDNETSDK_API int WINAPI Server_RemoveDynamicArea(unsigned char* pid,int AreaId);

LEDNETSDK_API int WINAPI Server_SaveDynamicArea(unsigned char* pid,BYTE AreaID);

LEDNETSDK_API int WINAPI Server_DelSaveDynamicArea(unsigned char* pid);