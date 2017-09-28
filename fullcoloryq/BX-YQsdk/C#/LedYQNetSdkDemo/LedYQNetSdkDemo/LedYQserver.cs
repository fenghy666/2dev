using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace LedYQServerAPI
{
    public class LedYQserver
    {
        [StructLayout(LayoutKind.Sequential)]
        public struct server_card
        {
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
            public byte[] PID;	//控制器唯一ID
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
            public byte[] barcode;	//控制器条形码
        }

        // 函数：	Server_Start
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			USHORT* port：服务器端口
        // 说明：	启动服务器
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_Start(ushort port);

        // 函数：	Server_GetCardList
        // 返回值：	搜索到的控制器个数
        // 参数：	
        //			server_card *pList：存放控制器列表的缓冲区
        // 说明：	获取控制器
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_GetCardList(byte[] pList);

        // 函数：	Server_Close
        // 返回值：	
        // 说明：	关闭服务器
        [DllImport("LedNetSdk.dll")]
        public static extern void Server_Close();

        // 函数：	Net_GetScreeninfo
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			USHORT* ControllerType：传出参数，返回控制器型号
        //			short* ScreenWidth：传出参数，返回led屏幕宽度
        //			short* ScreenHeight：传出参数，返回led屏幕高度
        // 说明：	获取控制器参数信息和屏幕参数信息
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_GetScreeninfo(byte[] pid, ref ushort pControllerType, ref short w, ref short h);

        // 函数：	Server_SetScreenSize
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			unsigned char* pid：通讯句柄
        //			short ScreenWidth：led屏幕宽度
        //			short ScreenHeight：led屏幕高度
        // 说明：	设置控制器的屏幕参数信息
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_SetScreenSize(byte[] pid, short ScreenWidth, short ScreenHeight);

        // 函数：	Server_GetOnoff
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			unsigned char* pid：控制器地址
        //			BYTE* onoff：传出参数，返回控制器当前屏幕开关状态，0:手动关闭 1：手动打开 2：自动关闭 3：自动打开
        // 说明：	定时开关
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_GetOnoff(byte[] pid, ref byte onoff);

        // 函数：	Server_SwitchOnTime
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			unsigned char* pid：通讯句柄
        //			char* OnTm1：第一个时间段的开机时间，格式12:56:09
        //			char* OffTm1：第一个时间段的关机时间，格式12:56:09
        //			LPCSTR SwitchScreenFilePath：定时开关机文件路径
        // 说明：	设置定时关机
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_SwitchOnTime(byte[] pid, string OnTm1, string OffTm1, string OnTm2, string OffTm2,
            string OnTm3, string OffTm3, string OnTm4, string OffTm4, char[] ftpIp, short ftpPort, char[] ftpuser, char[] ftppwd);

        // 函数：	Server_OpenScreen
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			unsigned char* pid：通讯句柄
        // 说明：	开屏幕
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_OpenScreen(byte[] pid);

        // 函数：	Server_CloseScreen
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			unsigned char* pid：通讯句柄
        // 说明：	关屏幕
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_CloseScreen(byte[] pid);

        [DllImport("LedNetSdk.dll")]
        public static extern int Server_GetFirmwareinfo(byte[] pid, byte[] FirmwareTime, byte[] FirmwarelVersion);

        [DllImport("LedNetSdk.dll")]
        public static extern int Server_Update(byte[] pid, byte[] strMd5File, byte[] strUpdateFile, char[] ftpIp, short ftpPort, char[] ftpuser, char[] ftppwd);

        // 函数：	Server_SystemTimeCorrect
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			unsigned char* pid：通讯句柄
        // 说明：	校正控制器时间
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_TimeCorrect(byte[] pid);

        [DllImport("LedNetSdk.dll")]
        public static extern int Server_GetVolume(byte[] pid, ref byte pVolume);

        // 函数：	Server_SetVolume
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			unsigned char* pid：通讯句柄
        //			BYTE bVolume：音量值，0-100
        // 说明：	设置音量
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_SetVolume(byte[] pid, byte bVolume);

        [DllImport("LedNetSdk.dll")]
        public static extern int Server_GetBrightness(byte[] pid, ref byte pMode, byte[] pValue);

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
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_AdjustBrightness(byte[] pid, byte mode, short[] bright_table);

        // 函数：	Net_GetScreeninfo
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			USHORT* ControllerType：传出参数，返回控制器型号
        //			short* ScreenWidth：传出参数，返回led屏幕宽度
        //			short* ScreenHeight：传出参数，返回led屏幕高度
        // 说明：	获取控制器参数信息和屏幕参数信息
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_GetModeinfo(byte[] pid, byte[] ServerIPAddress, ref ushort ServerPort);

        // 函数：	Server_GetNetinfo
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			unsigned char* pid：通讯句柄
        //			USHORT* ControllerType：传出参数，返回控制器型号
        //			short* ScreenWidth：传出参数，返回led屏幕宽度
        //			short* ScreenHeight：传出参数，返回led屏幕高度
        //			char* FirmwareVersion：传出参数，返回控制器固件版本
        // 说明：	获取控制器参数信息和屏幕参数信息
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_GetNetinfo(byte[] pid, byte[] ControlerID, byte[] netip, byte[] mask,
                byte[] gateway, ref byte pConnectMode);

        // 函数：	Server_SendPrograms
        // 返回值：	成功返回发送需要的句柄；失败返回0
        // 参数：	
        //			unsigned char* pid：通讯句柄
        //			unsigned char media：控制器存储节目的介质
        //			DWORD hPlaylist：播放列表对应的句柄
        //			LPCTSTR szLocalTempDir：发送节目时需要在本地生成节目文件，该参数为临时文件的存放目录
        // 说明：	发送节目到控制器
        [DllImport("LedNetSdk.dll")]
        public static extern uint Server_SendPrograms(byte[] pid, byte media, uint hPlaylist, byte[] szLocalTempDir, char[] ftpIp, short ftpPort, char[] ftpuser, char[] ftppwd, ref int pErr);

        // 函数：	Server_GetSendProcess
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			DWORD dwSendHand：发送句柄
        //			int* total_percent：传入参数，当前发送的总进度
        //			int* cur_percent：传入参数，当前文件发送的进度
        // 说明：	发送指定节目时查看发送进度
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_GetSendProcess(uint dwSendHand, ref int totalPercent, ref int curPercent);

        [DllImport("LedNetSdk.dll")]
        public static extern int Server_GetDownProcess(uint dwSendHand, ref int down_percent);

        // 函数：	Server_CancelSend
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			DWORD dwSendHand：发送句柄
        // 说明：	无论发送是否完成，结束发送节目
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_CancelSend(uint dwSendHand);

        // 函数：	Server_StopPlay
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			unsigned char* pid：通讯句柄
        // 说明：	停止播放节目
        [DllImport("LedNetSdk.dll")]
        public static extern int Server_StopPlay(byte[] pid);

        [DllImport("LedNetSdk.dll")]
        public static extern int Server_UpdateDynamicArea(byte[] pid, uint hArea);

        [DllImport("LedNetSdk.dll")]
        public static extern int Server_RemoveDynamicArea(byte[] pid, int AreaId);

        [DllImport("LedNetSdk.dll")]
        public static extern int Server_SaveDynamicArea(byte[] pid, int AreaID);

        [DllImport("LedNetSdk.dll")]
        public static extern int Server_DelSaveDynamicArea(byte[] pid);
    }
}
