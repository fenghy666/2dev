using System;
using System.Collections.Generic;
//using System.Linq;
using System.Text;
using System.IO;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace LedYQNetSDKAPI
{
    public class LedYQNetSdk
    {
        [StructLayout(LayoutKind.Sequential)]
        public struct card_unit
        {
            public string aPID;	//控制器唯一ID
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
            public string barcode;	//控制器条形码
            [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 16)]
            public string ip;	//控制器地址
        }
        #region
        public static void GetError(int err)
        {
            switch(err)
            {
                case bxyq_err.ERR_Unknow:
                    MessageBox.Show("未知错误！");
                    break;
                case bxyq_err.ERR_TIMEOUT:
                    MessageBox.Show("通讯超时，可能网络故障！");
                    break;
                case bxyq_err.ERR_DiskSpace:
                    MessageBox.Show("控制器工作目录空间不足！");
                    break;
                case bxyq_err.ERR_Hand:
                    MessageBox.Show("未建立通讯连接！");
                    break;
                case bxyq_err.ERR_SCREENSIZE:
                    MessageBox.Show("屏幕宽或高不合理！");
                    break;
                case bxyq_err.ERR_PATH:
                    MessageBox.Show("错误的文件路径！");
                    break;
                case bxyq_err.ERR_CMD:
                    MessageBox.Show("错误的命令！");
                    break;
                case bxyq_err.ERR_PROPERTY:
                    MessageBox.Show("错误的属性类型！");
                    break;
                case bxyq_err.ERR_UPLOAD:
                    MessageBox.Show("上传失败！");
                    break;
                case bxyq_err.ERR_TASKEXIST:
                    MessageBox.Show("任务队列为空！");
                    break;
                case bxyq_err.ERR_PARAM:
                    MessageBox.Show("参数不合理！");
                    break;
                case bxyq_err.ERR_CANCEL:
                    MessageBox.Show("发送被取消！");
                    break;
                case bxyq_err.ERR_DOWNLOAD:
                    MessageBox.Show("控制器下载失败！");
                    break;
                case bxyq_err.ERR_PROGRAM_SIZE:
                    MessageBox.Show("节目大小超出控制器最大容量！");
                    break;
                case bxyq_err.ERR_SENDHAND:
                    MessageBox.Show("无效的发送句柄，发送已结束或为开始！");
                    break;
                case bxyq_err.ERR_OUTDFGROUP:
                    MessageBox.Show("命令组错误！");
                    break;
                case bxyq_err.ERR_NOCMD:
                    MessageBox.Show("此命令不存在！");
                    break;
                case bxyq_err.ERR_BUSY:
                    MessageBox.Show("控制器忙！");
                    break;
                case bxyq_err.ERR_MEMORYVOLUME:
                    MessageBox.Show("存储器容量越界！");
                    break;
                case bxyq_err.ERR_CHECKSUM:
                    MessageBox.Show("数据包CRC校验错误！");
                    break;
                case bxyq_err.ERR_FILENOTEXIST:
                    MessageBox.Show("此文件不存在！");
                    break;
                case bxyq_err.ERR_FLASH:
                    MessageBox.Show("Flash访问错误！");
                    break;
                case bxyq_err.ERR_FILE_DOWNLOAD:
                    MessageBox.Show("文件下载错误！");
                    break;
                case bxyq_err.ERR_FILE_NAME:
                    MessageBox.Show("文件名错误！");
                    break;
                case bxyq_err.ERR_FILE_TYPE:
                    MessageBox.Show("文件类型错误！");
                    break;
                case bxyq_err.ERR_FILE_CRC16:
                    MessageBox.Show("文件校验错误！");
                    break;
                case bxyq_err.ERR_FONT_NOT_EXIST:
                    MessageBox.Show("字库文件不存在！");
                    break;
                case bxyq_err.ERR_FIRMWARE_TYPE:
                    MessageBox.Show("Firmware与控制器类型不匹配！");
                    break;
                case bxyq_err.ERR_DATE_TIME_FORMAT:
                    MessageBox.Show("日期时间格式错误！");
                    break;
                case bxyq_err.ERR_FILE_EXIST:
                    MessageBox.Show("此文件已存在！");
                    break;
                case bxyq_err.ERR_FILE_BLOCK_NUM:
                    MessageBox.Show("文件Black号错误！");
                    break;
                case bxyq_err.ERR_CONTROLLER_TYPE:
                    MessageBox.Show("控制器类型不匹配！");
                    break;
                case bxyq_err.ERR_SCREEN_PARA:
                    MessageBox.Show("控制器参数越界或错误！");
                    break;
                case bxyq_err.ERR_CONTROLLER_ID:
                    MessageBox.Show("读取控制器ID错误！");
                    break;
                case bxyq_err.ERR_USER_SECRET:
                    MessageBox.Show("通讯时用户密码错误！");
                    break;
                case bxyq_err.ERR_OLD_SECRET:
                    MessageBox.Show("修改密码时输入的老密码错误！");
                    break;
                case bxyq_err.ERR_PHY1_NO_SECRET:
                    MessageBox.Show("通讯时以加密2方式运行，提示物理层PHY1没有设定过密码！");
                    break;
                case bxyq_err.ERR_PHY_USE_SECRET:
                    MessageBox.Show("通讯时以固定加密1方式运行，提示物理层PHY1没有设定过密码！");
                    break;
                case bxyq_err.ERR_FILE_READ:
                    MessageBox.Show("读取文件失败！");
                    break;
                case bxyq_err.ERR_XML_TOP:
                    MessageBox.Show("提取XML文件顶层元素失败！");
                    break;
                case bxyq_err.ERR_DIR_NULL:
                    MessageBox.Show("路径错误，空路径！");
                    break;
                case bxyq_err.ERR_DIR_MK:
                    MessageBox.Show("创建路径失败！");
                    break;
                case bxyq_err.ERR_DIR_NOT_EXIST:
                    MessageBox.Show("此路径不存在！");
                    break;
                case bxyq_err.ERR_NOHEAD:
                    MessageBox.Show("报文无头部，包头错误！");
                    break;
                case bxyq_err.ERR_DISK_NAME:
                    MessageBox.Show("驱动器名称错误！");
                    break;
                case bxyq_err.ERR_DISK_NOT_EXIST:
                    MessageBox.Show("驱动器不存在（被拔除或者卸载了）！");
                    break;
                case bxyq_err.ERR_OPEN_FILE:
                    MessageBox.Show("打开文件失败！");
                    break;
                case bxyq_err.ERR_FILE_SEEK:
                    MessageBox.Show("文件偏移错误！");
                    break;
                case bxyq_err.ERR_CMD_UNFINISHED:
                    MessageBox.Show("命令未能正常完成，但是原因不详！");
                    break;
                case bxyq_err.ERR_CMD_DBG:
                    MessageBox.Show("命令尚未设计完成，还处于调试阶段！");
                    break;
                case bxyq_err.ERR_CMD_NOT_SUPPORT:
                    MessageBox.Show("命令不被支持！");
                    break;
                case bxyq_err.ERR_PERMISSIONS:
                    MessageBox.Show("权限不够！");
                    break;
                case bxyq_err.ERR_UNIAWFUL_OPERATION:
                    MessageBox.Show("非法操作！");
                    break;
                case bxyq_err.ERR_NO_RTC_CHIP:
                    MessageBox.Show("找不到RCP芯片！");
                    break;
                case bxyq_err.ERR_APP_NUM:
                    MessageBox.Show("已经安装有5个APP，必须先卸载1个！");
                    break;
                case bxyq_err.ERR_APP_NOT_EXIST:
                    MessageBox.Show("不存在这个程序！");
                    break;
                case bxyq_err.ERR_APP_EXIST:
                    MessageBox.Show("已经安装这个程序！");
                    break;
                case bxyq_err.ERR_CMD_BUSY:
                    MessageBox.Show("控制器忙（这个命令暂时阻塞）！");
                    break;
                case bxyq_err.ERR_NO_LIST_PLAYING:
                    MessageBox.Show("播放列表未加载！");
                    break;
                case bxyq_err.ERR_NO_PROGRAM_PLAYING:
                    MessageBox.Show("当前无节目播放！");
                    break;
                case bxyq_err.ERR_APP_PATH:
                    MessageBox.Show("路径出错！");
                    break;
                case bxyq_err.ERR_MEMRY_USEOUT:
                    MessageBox.Show("控制器内存耗尽！");
                    break;
                case bxyq_err.ERR_FTP_IP:
                    MessageBox.Show("ftp的ip不可达！");
                    break;
                case bxyq_err.ERR_USER_EXIST:
                    MessageBox.Show("已经有此用户！");
                    break;
                case bxyq_err.ERR_NOT_LOGIN:
                    MessageBox.Show("未登录！");
                    break;
                case bxyq_err.ERR_USER_NOT_EXIST:
                    MessageBox.Show("无此用户！");
                    break;
                case bxyq_err.ERR_USER_PASSWORD:
                    MessageBox.Show("密码错误！");
                    break;
                case bxyq_err.ERR_USER_ALREADY_LOGIN:
                    MessageBox.Show("已经有用户登录！");
                    break;
                case bxyq_err.ERR_PASSWORD_INCONSISTENT:
                    MessageBox.Show("密码不一致！");
                    break;
                case bxyq_err.ERR_USER_NUM_MAX:
                    MessageBox.Show("用户已满！");
                    break;
                case bxyq_err.ERR_USER_NAMME_NULL:
                    MessageBox.Show("用户名为空！");
                    break;
                case bxyq_err.ERR_LOG_MODE:
                    MessageBox.Show("非法日志模式！");
                    break;
                case bxyq_err.ERR_READ_DIR:
                    MessageBox.Show("读目录失败！");
                    break;
                case bxyq_err.ERR_IP_FORMAT:
                    MessageBox.Show("ip格式错误！");
                    break;
                case bxyq_err.ERR_NULL_TARGET:
                    MessageBox.Show("FTP下载，目标名称为空！");
                    break;
                case bxyq_err.ERR_NULL_PATH:
                    MessageBox.Show("FTP下载，目标路径为空！");
                    break;
                case bxyq_err.ERR_NULL_USER:
                    MessageBox.Show("FTP下载，用户为空！");
                    break;
                case bxyq_err.ERR_NULL_IP:
                    MessageBox.Show("FTP下载，用户为空！");
                    break;
                case bxyq_err.ERR_FONT_FORMAT:
                    MessageBox.Show("字库格式错误！");
                    break;
                case bxyq_err.ERR_PROPERTY_NOT_EXIST:
                    MessageBox.Show("访问的属性不存在！");
                    break;
                case bxyq_err.ERR_PROPERTY_READONLY:
                    MessageBox.Show("只读属性，不能修改！");
                    break;
            }
        }
        public class bxyq_err
        {
            public const int ERR_Unknow = 0x0100;//未知错误
            public const int ERR_TIMEOUT = 0x0101;//通讯超时，可能网络故障
            public const int ERR_DiskSpace = 0x0102;//控制器工作目录空间不足
            public const int ERR_Hand = 0x0103;//未建立通讯连接
            public const int ERR_SCREENSIZE = 0x0104;//屏幕宽或高不合理
            public const int ERR_PATH = 0x0105;//错误的文件路径
            public const int ERR_CMD = 0x0106;//错误的命令
            public const int ERR_PROPERTY = 0x0107;//错误的属性类型
            public const int ERR_UPLOAD = 0x0108;//上传失败
            public const int ERR_TASKEXIST = 0x0109;//任务队列为空
            public const int ERR_PARAM = 0x010a;//参数不合理
            public const int ERR_CANCEL = 0x010b;//发送被取消
            public const int ERR_DOWNLOAD = 0x010c;//控制器下载失败
            public const int ERR_PROGRAM_SIZE = 0x010d;//节目大小超出控制器最大容量
            public const int ERR_SENDHAND = 0x010e;//无效的发送句柄，发送已结束或为开始

            public const int ERR_OUTDFGROUP = 0x01;//命令组错误
            public const int ERR_NOCMD = 0x02;//此命令不存在
            public const int ERR_BUSY = 0x03;//控制器忙
            public const int ERR_MEMORYVOLUME = 0x04;//存储器容量越界
            public const int ERR_CHECKSUM = 0x05;//数据包CRC校验错误
            public const int ERR_FILENOTEXIST = 0x06;//此文件不存在
            public const int ERR_FLASH = 0x07;//Flash访问错误
            public const int ERR_FILE_DOWNLOAD = 0x08;//文件下载错误
            public const int ERR_FILE_NAME = 0x09;//文件名错误
            public const int ERR_FILE_TYPE = 0x0a;//文件类型错误
            public const int ERR_FILE_CRC16 = 0x0b;//文件校验错误
            public const int ERR_FONT_NOT_EXIST = 0x0c;//字库文件不存在
            public const int ERR_FIRMWARE_TYPE = 0x0d;//Firmware与控制器类型不匹配
            public const int ERR_DATE_TIME_FORMAT = 0x0e;//日期时间格式错误
            public const int ERR_FILE_EXIST = 0x0f;//此文件已存在
            public const int ERR_FILE_BLOCK_NUM = 0x10;//文件Black号错误
            public const int ERR_CONTROLLER_TYPE = 0x11;//控制器类型不匹配
            public const int ERR_SCREEN_PARA = 0x12;//控制器参数越界或错误
            public const int ERR_CONTROLLER_ID = 0x13;//读取控制器ID错误
            public const int ERR_USER_SECRET = 0x14;//通讯时用户密码错误
            public const int ERR_OLD_SECRET = 0x15;//修改密码时输入的老密码错误
            public const int ERR_PHY1_NO_SECRET = 0x16;//通讯时以加密2方式运行，提示物理层PHY1没有设定过密码
            public const int ERR_PHY_USE_SECRET = 0x17;//通讯时以固定加密1方式运行，提示物理层PHY1没有设定过密码
            public const int ERR_FILE_READ = 0x18;//读取文件失败
            public const int ERR_XML_TOP = 0x19;//提取XML文件顶层元素失败
            public const int ERR_DIR_NULL = 0x1a;//路径错误，空路径
            public const int ERR_DIR_MK = 0x1b;//创建路径失败
            public const int ERR_DIR_NOT_EXIST = 0x1c;//此路径不存在
            public const int ERR_NOHEAD = 0x1d;//报文无头部，包头错误
            public const int ERR_DISK_NAME = 0x1e;//驱动器名称错误
            public const int ERR_DISK_NOT_EXIST = 0x1f;//驱动器不存在（被拔除或者卸载了）
            public const int ERR_OPEN_FILE = 0x20;//打开文件失败
            public const int ERR_FILE_SEEK = 0x21;//文件偏移错误
            public const int ERR_CMD_UNFINISHED = 0x22;//命令未能正常完成，但是原因不详
            public const int ERR_CMD_DBG = 0x23;//命令尚未设计完成，还处于调试阶段
            public const int ERR_CMD_NOT_SUPPORT = 0x24;//命令不被支持
            public const int ERR_PERMISSIONS = 0x25;//权限不够
            public const int ERR_UNIAWFUL_OPERATION = 0x26;//非法操作
            public const int ERR_NO_RTC_CHIP = 0x27;//找不到RCP芯片
            public const int ERR_APP_NUM = 0x28;//已经安装有5个APP，必须先卸载1个
            public const int ERR_APP_NOT_EXIST = 0x29;//不存在这个程序
            public const int ERR_APP_EXIST = 0x2a;//已经安装这个程序
            public const int ERR_CMD_BUSY = 0x2b;//控制器忙（这个命令暂时阻塞）
            public const int ERR_NO_LIST_PLAYING = 0x2c;//播放列表未加载
            public const int ERR_NO_PROGRAM_PLAYING = 0x2d;//当前无节目播放
            public const int ERR_APP_PATH = 0x2e;//路径出错
            public const int ERR_MEMRY_USEOUT = 0x2f;//控制器内存耗尽
            public const int ERR_FTP_IP = 0x30;//ftp的ip不可达
            public const int ERR_USER_EXIST = 0x31;//已经有此用户
            public const int ERR_NOT_LOGIN = 0x32;//未登录
            public const int ERR_USER_NOT_EXIST = 0x33;//无此用户
            public const int ERR_USER_PASSWORD = 0x34;//密码错误
            public const int ERR_USER_ALREADY_LOGIN = 0x35;//已经有用户登录
            public const int ERR_PASSWORD_INCONSISTENT = 0x36;//密码不一致
            public const int ERR_USER_NUM_MAX = 0x37;//用户已满
            public const int ERR_USER_NAMME_NULL = 0x38;//用户名为空
            public const int ERR_LOG_MODE = 0x39;//非法日志模式
            public const int ERR_READ_DIR = 0x3a;//读目录失败
            public const int ERR_IP_FORMAT = 0x3b;//ip格式错误
            public const int ERR_NULL_TARGET = 0x3c;//FTP下载，目标名称为空
            public const int ERR_NULL_PATH = 0x3d;//FTP下载，目标路径为空
            public const int ERR_NULL_USER = 0x3e;//FTP下载，用户为空
            public const int ERR_NULL_IP = 0x3f;//FTP下载，用户为空
            public const int ERR_FONT_FORMAT = 0x40;//字库格式错误
            public const int ERR_PROPERTY_NOT_EXIST = 0x41;//访问的属性不存在
            public const int ERR_PROPERTY_READONLY = 0x42;//只读属性，不能修改
        }
        #endregion

        // 函数：	Sdk_Init
        // 返回值：	无
        // 参数：	无
        // 说明：	初始化SDK通讯库
        [DllImport("LedNetSdk.dll")]
        public static extern void Sdk_Init();

        // 函数：	Sdk_Release
        // 返回值：	无
        // 参数：	无
        // 说明：	释放SDK通讯库
        [DllImport("LedNetSdk.dll")]
        public static extern void Sdk_Release();

        // 函数：	Net_SearchCards
        // 返回值：	搜索到的控制器个数
        // 参数：	
        //			card_unit* pCardList：存放控制器列表的缓冲区
        //			int ntimeout：查找时的超时时间
        // 说明：	在局域网内搜索所有控制器
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_SearchCards(byte[] pCardList, int ntimeout);


        // 函数：	Net_GetScreeninfo
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			USHORT* ControllerType：传出参数，返回控制器型号
        //			short* ScreenWidth：传出参数，返回led屏幕宽度
        //			short* ScreenHeight：传出参数，返回led屏幕高度
        // 说明：	获取控制器参数信息和屏幕参数信息
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_GetScreeninfo(string ip, ref ushort pControllerType, ref short w, ref short h);

        // 函数：	Net_SetScreenSize
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			short ScreenWidth：led屏幕宽度
        //			short ScreenHeight：led屏幕高度
        // 说明：	设置控制器的屏幕参数信息
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_SetScreenSize(string ip,short ScreenWidth,short ScreenHeight);
         
        // 函数：	Net_SystemTimeCorrect
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        // 说明：	校正控制器时间
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_TimeCorrect(string ip);

        // 函数：	Net_GetNetinfo
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //          unsigned char* ControlerID
        //			char* netip：传出参数，返回ip地址
        //			char* mask：传出参数，返回子网掩码
        //			char* gateway：传出参数，返回默认网关
        //			char* FirmwareVersion：传出参数，返回控制器固件版本
        //          BYTE* pConnectMode: 0:DHCP 1:固定ip
        // 说明：	获取修改控制器ip信息
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_GetNetinfo(string ip, string ControlerID, byte[] netip, byte[] mask,
                byte[] gateway, ref byte pConnectMode);

        // 函数：	Net_SetAutoip
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			unsigned char* pid：控制器唯一ID
        // 说明：	设置控制器通过DHCP获取网络地址
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_SetAutoip(string pid);

        // 函数：	Net_GetIp
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			unsigned char* pid：控制器唯一ID
        //			char* ip：控制器地址
        // 说明：	查询指定控制器的网络地址
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_GetIp(string pid, byte[] ip);
    
        // 函数：	Net_SetStaticip
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			unsigned string pid：控制器唯一ID
        //			string ip：控制器地址
        //			string mask：子网掩码
        //			string gateway：网关地址
        // 说明：	设置控制器的网络地址
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_SetStaticip(string pid, byte[] ip, byte[] mask, byte[] gateway);

        // 函数：	Net_SetClientMode
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        // 说明：	将工作模式切换为连接服务器模式
        // 警告:	执行本函数将会重启控制器
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_SetClientMode(byte[] ip);
        
        // 函数：	Net_SetServerMode
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			char* serverip：控制器要连接的服务器的ip地址
        //			unsigned short port：服务器所用的端口
        // 说明：	将工作模式切换为连接服务器模式
        // 警告:	执行本函数将会重启控制器
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_SetServerMode(byte[] ip, byte[] serverip, ushort port);


        // 函数：	Net_GetModeinfo
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			unsigned char* mode：控制器工作模式
        //			char* ServerIPAddress：控制器要连接的服务器的ip地址
        //			unsigned short port：服务器所用的端口
        // 说明：	查询控制器工作模式，如果是服务器模式返回服务器地址
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_GetModeinfo(byte[] ip,ref byte mode,byte[] ServerIPAddress,ref ushort ServerPort);

        // 函数：	Net_GetOnoff
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			BYTE* onoff：传出参数，返回控制器当前屏幕开关状态，0:手动关闭 1：手动打开 2：自动关闭 3：自动打开
        // 说明：	获取控制器屏幕开关信息
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_GetOnoff(string ip, ref System.Byte onoff);
                // 函数：	Net_OpenScreen
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        // 说明：	开屏幕
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_OpenScreen(string ip);

        // 函数：	Net_CloseScreen
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        // 说明：	关屏幕
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_CloseScreen(string ip);

        // 函数：	Net_SwitchOnTime
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			char* OnTm1：第一个时间段的开机时间，格式12:56:09
        //			char* OffTm1：第一个时间段的关机时间，格式12:56:09
        //			LPCSTR SwitchScreenFilePath：定时开关机文件路径
        // 说明：	设置定时关机
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_SwitchOnTime(string ip, string OnTm1, string OffTm1, string OnTm2, string OffTm2, 
            string OnTm3, string OffTm3, string OnTm4, string OffTm4);

        
        // 函数：	Net_GetFirmwareinfo
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			USHORT* ControllerType：传出参数，返回控制器型号
        //			char* FirmwareTime：传出参数，返回固件创建时间
        //			char* FirmwareVersion：传出参数，返回控制器固件版本
        // 说明：	获取控制器固件信息
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_GetFirmwareinfo(string ip, byte[] FirmwareTime, byte[] FirmwarelVersion);

        // 函数：	Net_Update
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			LPCWSTR strMd5File：固件文件之一，固件的描述文件
        //			LPCWSTR strUpdateFile：固件文件之一，固件文件
        // 说明：	升级控制器的固件
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_Update(string ip, byte[] strMd5File, byte[] strUpdateFile);
        
        // 函数：	Net_GetVolume
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			BYTE* pVolume：传出参数，返回控制器音量
        // 说明：	获取控制器参数信息和屏幕参数信息
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_GetVolume(string ip, ref System.Byte pVolume);

        // 函数：	Net_SetVolume
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			BYTE bVolume：音量值，0-100
        // 说明：	设置音量
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_SetVolume(string ip, System.Byte bVolume);

        // 函数：	Net_GetBrightness
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			BYTE* pMode：传出参数，返回控制器亮度所用的模式,0-手工调亮,1-定时调亮，2-传感器默认调亮，3-传感器调亮
        //			BYTE* pValue：传出参数，返回亮度值，如果不是手工调亮，返回的是一个48字节长的亮度列表，每个字节对应半个小时的亮度值
        // 说明：	获取控制器当前亮度信息
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_GetBrightness(string ip,ref byte pMode, byte[] pValue);

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
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_AdjustBrightness(string ip, byte mode, short[] bright_table);

        /// <summary>
        /// 发送节目到控制器
        /// ip tempDir 需要用Encoding.ASCII.GetBytes获取字节流
        /// media 取 1
        /// </summary>
        /// <param name="ip">通讯地址</param>
        /// <param name="media">控制器存储节目的介质</param>
        /// <param name="hPlaylist">播放列表对应的句柄</param>
        /// <param name="szLocalTempDir">发送节目时需要在本地生成节目文件，该参数为临时文件的存放目录</param>
        /// <param name="pErr">如果有错误，返回的错误号</param>
        /// <returns>成功返回发送需要的句柄；失败返回0</returns>
        [DllImport("LedNetSdk.dll")]
        public static extern uint Net_SendPrograms( string ip, byte media, uint hPlaylist,  byte[] szLocalTempDir, ref int pErr);

        /// <summary>
        /// 发送指定节目时查看发送进度
        /// </summary>
        /// <param name="dwSendHand">发送句柄</param>
        /// <param name="totalPercent">传入参数，当前发送的总进度</param>
        /// <param name="curPercent">传入参数，当前文件发送的进度</param>
        /// <returns>成功返回0；失败返回错误号</returns>
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_GetSendProcess(uint dwSendHand, ref int totalPercent, ref int curPercent);

        /// <summary>
        /// 无论发送是否完成，结束发送节目
        /// </summary>
        /// <param name="dwSendHand">发送句柄</param>
        /// <returns>成功返回0；失败返回错误号</returns>
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_CancelSend(uint dwSendHand);

        /// <summary>
        /// 停止播放节目
        /// </summary>
        /// <param name="ip">控制器地址</param>
        /// <returns>成功返回0；失败返回错误号</returns>
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_StopPlay(string ip);

        // 函数：	Net_UpdateDynamicArea
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			DWORD hArea：区域句柄
        // 说明：	更新动态区
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_UpdateDynamicArea(string ip,uint hArea);

        // 函数：	Net_RemoveDynamicArea
        // 返回值：	成功返回0；失败返回错误号
        // 参数：	
        //			char* ip：控制器地址
        //			int AreaId：动态区域编号
        // 说明：	删除控制器上的动态区域
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_RemoveDynamicArea(string ip, int AreaId);

        [DllImport("LedNetSdk.dll")]
        public static extern int Net_SaveDynamicArea(string ip, int AreaID);

        [DllImport("LedNetSdk.dll")]
        public static extern int Net_DelSaveDynamicArea(string ip);

        //SaveLock：0掉电不保存  1掉电保存
        [DllImport("LedNetSdk.dll")]
        public static extern int Net_LockProgram(string ip, int program_id, byte SaveLock);

        [DllImport("LedNetSdk.dll")]
        public static extern int Net_UnLockProgram(string ip);
    }
}
