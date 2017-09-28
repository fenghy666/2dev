
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




//��������Ϣ
typedef struct _CARD_UNIT
{
	unsigned char	PID[16];//������ΨһID
	char			barcode[16];//������������
	char			ip[16];//��������ַ
}card_unit;



// ������	Sdk_Init
// ����ֵ��	��
// ������	��
// ˵����	��ʼ��SDKͨѶ��
LEDNETSDK_API void WINAPI Sdk_Init();

// ������	Sdk_Release
// ����ֵ��	��
// ������	��
// ˵����	�ͷ�SDKͨѶ��
LEDNETSDK_API void WINAPI Sdk_Release();


// ������	Net_SearchCards
// ����ֵ��	�������Ŀ���������
// ������	
//			card_unit* pCardList����ſ������б�Ļ�����
//			int ntimeout������ʱ�ĳ�ʱʱ��
// ˵����	�ھ��������������п�����
LEDNETSDK_API int WINAPI Net_SearchCards(card_unit* pCardList,int ntimeout);

// ������	Net_SetStaticip
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned char* pid��������ΨһID
//			char* ip����������ַ
//			char* mask����������
//			char* gateway�����ص�ַ
// ˵����	���ÿ������������ַ
LEDNETSDK_API int WINAPI Net_SetStaticip(unsigned char* pid,char* ip,char* mask,char* gateway);

// ������	Net_SetAutoip
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned char* pid��������ΨһID
// ˵����	���ÿ�����ͨ��DHCP��ȡ�����ַ
LEDNETSDK_API int WINAPI Net_SetAutoip(unsigned char* pid);

// ������	Net_GetIp
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			unsigned char* pid��������ΨһID
//			char* ip����������ַ
// ˵����	��ѯָ���������������ַ
LEDNETSDK_API int WINAPI Net_GetIp(unsigned char* pid,char* ip);

// ������	Net_SetServerMode
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			char* serverip��������Ҫ���ӵķ�������ip��ַ
//			unsigned short port�����������õĶ˿�
// ˵����	������ģʽ�л�Ϊ���ӷ�����ģʽ
// ����:	ִ�б�������������������
LEDNETSDK_API int WINAPI Net_SetServerMode(char* ip,char* serverip,unsigned short port);

// ������	Net_SetClientMode
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
// ˵����	������ģʽ�л�Ϊ���ӷ�����ģʽ
// ����:	ִ�б�������������������
LEDNETSDK_API int WINAPI Net_SetClientMode(char* ip);

// ������	Net_GetModeinfo
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			unsigned char* mode������������ģʽ
//			char* ServerIPAddress��������Ҫ���ӵķ�������ip��ַ
//			unsigned short port�����������õĶ˿�
// ˵����	��ѯ����������ģʽ������Ƿ�����ģʽ���ط�������ַ
LEDNETSDK_API int WINAPI Net_GetModeinfo(char* ip,unsigned char* mode,char* ServerIPAddress,unsigned short* ServerPort);

// ������	Net_GetNetinfo
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			USHORT* ControllerType���������������ؿ������ͺ�
//			short* ScreenWidth����������������led��Ļ���
//			short* ScreenHeight����������������led��Ļ�߶�
//			char* FirmwareVersion���������������ؿ������̼��汾
// ˵����	��ȡ������������Ϣ����Ļ������Ϣ
LEDNETSDK_API int WINAPI Net_GetNetinfo(char* ip,unsigned char* ControlerID,char* netip,char* mask,char* gateway,BYTE* pConnectMode);

// ������	Net_GetNetinfo
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			USHORT* ControllerType���������������ؿ������ͺ�
//			short* ScreenWidth����������������led��Ļ���
//			short* ScreenHeight����������������led��Ļ�߶�
// ˵����	��ȡ������������Ϣ����Ļ������Ϣ
LEDNETSDK_API int WINAPI Net_GetScreeninfo(char* ip,unsigned short *pControllerType,short* w,short* h);

// ������	Net_GetFirmwareinfo
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			USHORT* ControllerType���������������ؿ������ͺ�
//			char* FirmwareTime���������������ع̼�����ʱ��
//			char* FirmwareVersion���������������ؿ������̼��汾
// ˵����	��ȡ�������̼���Ϣ
LEDNETSDK_API int WINAPI Net_GetFirmwareinfo(char* ip,char* FirmwareTime,char* FirmwarelVersion);

// ������	Net_GetBrightness
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			BYTE* pMode���������������ؿ������������õ�ģʽ,0-�ֹ�����,1-��ʱ������2-������Ĭ�ϵ�����3-����������
//			BYTE* pValue��������������������ֵ����������ֹ����������ص���һ��48�ֽڳ��������б�ÿ���ֽڶ�Ӧ���Сʱ������ֵ
// ˵����	��ȡ��������ǰ������Ϣ
LEDNETSDK_API int WINAPI Net_GetBrightness(char* ip,BYTE* pMode,BYTE* pValue);

// ������	Net_GetVolume
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			BYTE* pVolume���������������ؿ���������
// ˵����	��ȡ������������Ϣ����Ļ������Ϣ
LEDNETSDK_API int WINAPI Net_GetVolume(char* ip,BYTE* pVolume);

// ������	Net_GetOnoff
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			BYTE* onoff���������������ؿ�������ǰ��Ļ����״̬��0:�ֶ��ر� 1���ֶ��� 2���Զ��ر� 3���Զ���
// ˵����	��ȡ��������Ļ������Ϣ
LEDNETSDK_API int WINAPI Net_GetOnoff(char* ip,BYTE* onoff);

// ������	Net_SetScreenSize
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			short ScreenWidth��led��Ļ���
//			short ScreenHeight��led��Ļ�߶�
// ˵����	���ÿ���������Ļ������Ϣ
LEDNETSDK_API int WINAPI Net_SetScreenSize(char* ip,short ScreenWidth,short ScreenHeight);


// ������	Net_SendProgram
// ����ֵ��	�ɹ����ط�����Ҫ�ľ����ʧ�ܷ���0
// ������	
//			char* ip��ͨѶ��ַ
//			unsigned char media���������洢��Ŀ�Ľ���
//			DWORD hPlaylist�������б��Ӧ�ľ��
//			LPCWSTR szLocalTempDir�����ͽ�Ŀʱ��Ҫ�ڱ������ɽ�Ŀ�ļ����ò���Ϊ��ʱ�ļ��Ĵ��Ŀ¼
//			int *pErr������д��󣬷��صĴ����
// ˵����	���ͽ�Ŀ��������
LEDNETSDK_API DWORD WINAPI Net_SendPrograms(char* ip,unsigned char media,DWORD hPlaylist,LPCWSTR szLocalTempDir,int *pErr);

// ������	Net_GetSendProcess
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			DWORD dwSendHand�����;��
//			int* total_percent�������������ǰ���͵��ܽ���
//			int* cur_percent�������������ǰ�ļ����͵Ľ���
// ˵����	����ָ����Ŀʱ�鿴���ͽ���
LEDNETSDK_API int WINAPI Net_GetSendProcess(DWORD dwSendHand,int* total_percent,int* cur_percent);

// ������	Net_CancelSend
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			DWORD dwSendHand�����;��
// ˵����	���۷����Ƿ���ɣ��������ͽ�Ŀ
LEDNETSDK_API int WINAPI Net_CancelSend(DWORD dwSendHand);

// ������	Net_StopPlay
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
// ˵����	ֹͣ���Ž�Ŀ
LEDNETSDK_API int WINAPI Net_StopPlay(char* ip);

// ������	Net_SetVolume
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			BYTE bVolume������ֵ��0-100
// ˵����	��������
LEDNETSDK_API int WINAPI Net_SetVolume(char* ip,BYTE bVolume);

// ������	Net_AdjustBrightness
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			BYTE mode������ģʽ��0x00�C�ֶ�������0x01�C��ʱ������0x02�C�Զ�����������Ӵ�������
//			short* bright_table�����ȱ�
// ˵����	��������
//			���ȱ���Ҫ��Զ�ʱ������ÿ30����һ��ֵ������һ��48��ֵ
//			bright_table[0]=00:00 �C 00:29 �������ֵ
//			bright_table[1]=00:30 �C 00:59 �������ֵ
//			......
//			bright_table[47]=23:30 �C 23:59 �������ֵ
//			�ֶ��������Խ�����ֵ��Ϊ��ͬ��ÿ��ֵ��Χ0-255
LEDNETSDK_API int WINAPI Net_AdjustBrightness(char* ip,BYTE mode,short* bright_table);

// ������	Net_SystemTimeCorrect
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
// ˵����	У��������ʱ��
LEDNETSDK_API int WINAPI Net_TimeCorrect(char* ip);

// ������	Net_OpenScreen
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
// ˵����	����Ļ
LEDNETSDK_API int WINAPI Net_OpenScreen(char* ip);

// ������	Net_CloseScreen
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
// ˵����	����Ļ
LEDNETSDK_API int WINAPI Net_CloseScreen(char* ip);

// ������	Net_SwitchOnTime
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			char* OnTm1����һ��ʱ��εĿ���ʱ�䣬��ʽ12:56:09
//			char* OffTm1����һ��ʱ��εĹػ�ʱ�䣬��ʽ12:56:09
//			LPCSTR SwitchScreenFilePath����ʱ���ػ��ļ�·��
// ˵����	���ö�ʱ�ػ�
LEDNETSDK_API int WINAPI Net_SwitchOnTime(char* ip,char* OnTm1,char* OffTm1,char* OnTm2,char* OffTm2,char* OnTm3,char* OffTm3,char* OnTm4,char* OffTm4);

// ������	Net_Update
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			LPCWSTR strMd5File���̼��ļ�֮һ���̼��������ļ�
//			LPCWSTR strUpdateFile���̼��ļ�֮һ���̼��ļ�
// ˵����	�����������Ĺ̼�
LEDNETSDK_API int WINAPI Net_Update(char* ip,LPCWSTR strMd5File,LPCWSTR strUpdateFile);

// ������	Net_UpdateDynamicArea
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			DWORD hArea��������
// ˵����	���¶�̬��
LEDNETSDK_API int WINAPI Net_UpdateDynamicArea(char* ip,DWORD hArea);

// ������	Net_RemoveDynamicArea
// ����ֵ��	�ɹ�����0��ʧ�ܷ��ش����
// ������	
//			char* ip����������ַ
//			int AreaId����̬������
// ˵����	ɾ���������ϵĶ�̬����
LEDNETSDK_API int WINAPI Net_RemoveDynamicArea(char* ip,int AreaId);


LEDNETSDK_API int WINAPI Net_SaveDynamicArea(char* ip,BYTE AreaID);

LEDNETSDK_API int WINAPI Net_DelSaveDynamicArea(char* ip);

//SaveLock��0���粻����  1���籣��
LEDNETSDK_API int WINAPI Net_LockProgram(char* ip,int program_id,BYTE SaveLock);

LEDNETSDK_API int WINAPI Net_UnLockProgram(char* ip);