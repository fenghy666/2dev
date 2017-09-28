
// LedNetSdkDemo.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "LedNetSdkDemo.h"
#include "LedNetSdkDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLedNetSdkDemoApp

BEGIN_MESSAGE_MAP(CLedNetSdkDemoApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CLedNetSdkDemoApp 构造

CLedNetSdkDemoApp::CLedNetSdkDemoApp()
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CLedNetSdkDemoApp 对象

CLedNetSdkDemoApp theApp;


// CLedNetSdkDemoApp 初始化

BOOL CLedNetSdkDemoApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 创建 shell 管理器，以防对话框包含
	// 任何 shell 树视图控件或 shell 列表视图控件。
	CShellManager *pShellManager = new CShellManager;

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));

	strcpy(ftp_server_ip,"222.66.141.11");
	ftp_server_port=8888;
	strcpy(ftp_server_user,"guest");
	strcpy(ftp_server_pwd,"guest");
	m_bServerRun=false;
	CLedNetSdkDemoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: 在此放置处理何时用
		//  “确定”来关闭对话框的代码
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置处理何时用
		//  “取消”来关闭对话框的代码
	}

	// 删除上面创建的 shell 管理器。
	if (pShellManager != NULL)
	{
		delete pShellManager;
	}

	// 由于对话框已关闭，所以将返回 FALSE 以便退出应用程序，
	//  而不是启动应用程序的消息泵。
	return FALSE;
}

void CString2Char(CString str, char ch[])
{
#ifdef _UNICODE
	int i;
	char *tmpch;
	int wLen = WideCharToMultiByte(CP_ACP, 0, str, -1, NULL, 0, NULL, NULL);//得到Char的长度
	tmpch = new char[wLen + 1];                                             //分配变量的地址大小
	WideCharToMultiByte(CP_ACP, 0, str, -1, tmpch, wLen, NULL, NULL);       //将CString转换成char*

	for(i = 0; tmpch[i] != '\0'; i++) ch[i] = tmpch[i];
	ch[i] = '\0';
	delete tmpch;
#else
	strcpy(ch,str.GetBuffer());
#endif
}
/*/////
pwstr 输入缓冲
len   输入缓冲长度
*/////
void Char2TCHAR(TCHAR *pwstr,size_t len,const char *str)
{
#ifdef _UNICODE
	if(str)
	{
		size_t nu = strlen(str);
		size_t n =(size_t)MultiByteToWideChar(CP_ACP,0,(const char *)str,(int)nu,NULL,0);
		if(n>=len)
			n=len-1;
		memset(pwstr,0,len);
		MultiByteToWideChar(CP_ACP,0,(const char *)str,(int)nu,pwstr,(int)n);
	}
#else
	strcpy(pwstr,str);
#endif
}
CString GetErrText(int err)
{
	switch (err)
	{
	case ERR_OUTOFGROUP				:return _T("命令组错误 ");
	case ERR_NOCMD					:return _T("此命令不存在 ");
	case ERR_BUSY					:return _T("控制器忙 ");
	case ERR_MEMORYVOLUME			:return _T("存储器容量越界 ");
	case ERR_CHECKSUM				:return _T("数据包 CRC 校验错误 ");
	case ERR_FILENOTEXIST			:return _T("此文件不存在 ");
	case ERR_FLASH					:return _T("Flash访问错误 ");
	case ERR_FILE_DOWNLOAD			:return _T("文件下载错误 ");
	case ERR_FILE_NAME				:return _T("文件名错误 ");
	case ERR_FILE_TYPE				:return _T("文件类型错误 ");
	case ERR_FILE_CRC16				:return _T("文件校验错误 ");
	case ERR_FONT_NOT_EXIST			:return _T("字库文件不存在 ");
	case ERR_FIRMWARE_TYPE			:return _T("Firmware 与控制器类型不匹配 ");
	case ERR_DATE_TIME_FORMAT		:return _T("日期时间格式错误 ");
	case ERR_FILE_EXIST				:return _T("此文件已存在 ");
	case ERR_FILE_BLOCK_NUM			:return _T("文件 Block 号错误 ");
	case ERR_CONTROLLER_TYPE		:return _T("控制器类型不匹配 ");
	case ERR_SCREEN_PARA			:return _T("控制器参数越界或错误 ");
	case ERR_CONTROLLER_ID			:return _T("读取控制器 ID 错误 ");
	case ERR_USER_SECRET			:return _T("通讯时用户密码错误 ");
	case ERR_OLD_SECRET				:return _T("修改密码时输入的老密码错误 ");
	case ERR_PHY1_NO_SECRET			:return _T("通讯时以加密 2 方式运行提示物理层 PHY1 没有设定过密码");
	case ERR_PHY_USE_SECTET			:return _T("通讯时以固定加密 1 方式运行提示物理层 PHY1 没有设定过密码");
	case ERR_FILE_READ				:return _T("读取文件失败 ");
	case ERR_XML_TOP				:return _T("提取 XML 文件顶层元素失败 ");
	case ERR_DIR_NULL				:return _T("路径错误,空路径 ");
	case ERR_DIR_MK					:return _T("创建路径失败 ");
	case ERR_DIR_NOT_EXIST			:return _T("此路径不存在 ");
	case ERR_NOHEAD					:return _T("报文无头部 ，包头错误  ");
	case ERR_DISK_NAME				:return _T("驱动器名称错误 ");
	case ERR_DISK_NOT_EXIST			:return _T("驱动器不存在(被拔除或者卸载了)");
	case ERR_OPEN_FILE				:return _T("打开文件失败 ");
	case ERR_FILE_SEEK				:return _T("文件偏移错误 ");
	case ERR_CMD_UNFINISHED			:return _T("命令未能正常完成 ,但是原因不详");
	case ERR_CMD_DBG				:return _T("命令尚未设计完成 ，还处于调试阶段");
	case ERR_CMD_NOT_SUPPORT		:return _T("命令不被支持 ");
	case ERR_PERMISSIONS			:return _T("权限不够 ");
	case ERR_UNLAWFUL_OPERATION		:return _T("非法操作 ");
	case ERR_NO_RTC_CHIP			:return _T("找不到 RTC 芯片 ");
	case ERR_APP_NUM				:return _T("已经安装有 5 个 app ，必须先卸载一");
	case ERR_APP_NOT_EXIST			:return _T("不存在这个程序 ");
	case ERR_APP_EXIST				:return _T("已经安装这个程序 ");
	case ERR_CMD_BUSY				:return _T("控制器忙 (这个命令暂时");
	case ERR_NO_LIST_PLAYING		:return _T("播放列表未加载 ");
	case ERR_NO_PROGRAM_PLAYING		:return _T("当前无节目播放 ");
	case ERR_APP_PATH				:return _T("路径出错 ");
	case ERR_MEMRY_USEOUT			:return _T("控制器内存耗尽 ");
	case ERR_FTP_IP					:return _T("ftp 的 ip 不可达 ");
	case ERR_USER_EXIST				:return _T("已经有此用户 ");
	case ERR_NOT_LOGIN				:return _T("未登录 ");
	case ERR_USER_NOT_EXIST			:return _T("无此用户 ");
	case ERR_USER_PASSWORD			:return _T("密码错误 ");
	case ERR_USER_ALREADY_LOGIN		:return _T("已经有用户登录 ");
	case ERR_PASSWORD_INCONSISTENT	:return _T("密码不一致 ");
	case ERR_USER_NUM_MAX			:return _T("用户已满 ");
	case ERR_USER_NAME_NULL			:return _T("用户名为空 ");
	case ERR_LOG_MODE				:return _T("非法日志模式 ");
	case ERR_READ_DIR				:return _T("读目录失败 ");
	case ERR_IP_FORMAT				:return _T("ip 格式错误");
	case ERR_NULL_TARGET			:return _T("FTP 下载  目标名称为空 ");
	case ERR_NULL_PATH				:return _T("FTP 下载 目标路径为空 ");
	case ERR_NULL_USER				:return _T("FTP 下载 用户为空 ");
	case ERR_NULL_IP				:return _T("FTP 下载 用户为空 ");
	case ERR_FONT_FORMAT			:return _T("字库格式错误 ");
	case ERR_PROPERTY_NOT_EXIST		:return _T("访问的属性不存在 ");
	case ERR_PROPERTY_READONLY		:return _T("只读属性，不能修改");
	
	case ERR_TIMEOUT				:return _T("通讯超时,可能网络故障");
	case ERR_DiskSpace				:return _T("控制器工作目录空间不足");
	case ERR_Hand					:return _T("未建立通讯连接");
	case ERR_SCREENSIZE				:return _T("屏幕宽或高不合理");
	case ERR_PATH					:return _T("错误的文件路径");
	case ERR_CMD					:return _T("错误的命令");
	case ERR_PROPERTY				:return _T("错误的属性类型");
	case ERR_UPLOAD					:return _T("上传失败");
	case ERR_TASKEXIST				:return _T("任务队列非空");
	case ERR_PARAM					:return _T("参数不合理");
	case ERR_CANCEL					:return _T("发送被取消");
	case ERR_DOWNLOAD				:return _T("控制器下载失败");
	case ERR_PROGRAM_SIZE			:return _T("节目大小超出控制器最大容量");
	case ERR_SENDHAND				:return _T("无效的发送句柄，发送已结束或为开始");
	default:return _T("未知错误");
	}
}
