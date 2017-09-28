Attribute VB_Name = "Module1"
Private Declare Function GetWindow Lib "user32" Alias "FindWindowA" (ByVal lpClassName As String, ByVal lpWindowName As String) As Long
'过程名:    Initialize
'          初始化动态库；该函数不与显示屏通讯。
'DLLApp:              主程序句柄
'pCallBack:           返回发送的消息和进度
'                             类型为 TCallBackFunc = procedure(szMessagge:string;nProgress:integer); stdcall;
'返回值:                      详见返回状态代码定义?
Public Declare Function Initialize Lib "BX_IV.DLL" (ByVal DllApp As Long, ByVal pCallBack As Long) As Long

Public Declare Function Uninitialize Lib "BX_IV.DLL" () As Long


'-------------------------------------------------------------------------------
'过程名:      AddScreen
'  向动态库中添加显示屏信息；该函数不与显示屏通讯，只用于动态库中的指定显示屏参数信息配置。
'参数:
'    nControlType    :显示屏的控制器型号；详见宏定义“控制器型号定义”
'      Controller_BX_5AT = 0x0051;
'      Controller_BX_5A0 = 0x0151;
'      Controller_BX_5A1 = 0x0251;
'      Controller_BX_5A2 = 0x0351;
'      Controller_BX_5A3 = 0x0451;
'      Controller_BX_5A4 = 0x0551;
'      Controller_BX_5A1_WIFI = 0x0651;
'      Controller_BX_5A2_WIFI = 0x0751;
'      Controller_BX_5A4_WIFI = 0x0851;
'      Controller_BX_5A  = 0x0951;
'      Controller_BX_5A2_RF = 0x1351;
'      Controller_BX_5A4_RF = 0x1551;
'      Controller_BX_5AT_WIFI = 0x1651;
'      Controller_BX_5AL = 0x1851;

'      Controller_AX_AT  = 0x2051;
'      Controller_AX_A0  = 0x2151;

'      Controller_BX_5M1 = 0x0052;
'      Controller_BX_5M1X = 0x0152;
'      Controller_BX_5M2 = 0x0252;
'      Controller_BX_5M3 = 0x0352;
'      Controller_BX_5M4 = 0x0452;

'      Controller_BX_5E1 = 0x0154;
'      Controller_BX_5E2 = 0x0254;
'      Controller_BX_5E3 = 0x0354;

'      Controller_BX_5UT = 0x0055;
'      Controller_BX_5U0 = 0x0155;
'      Controller_BX_5U1 = 0x0255;
'      Controller_BX_5U2 = 0x0355;
'      Controller_BX_5U3 = 0x0455;
'      Controller_BX_5U4 = 0x0555;
'      Controller_BX_5U5 = 0x0655;
'      Controller_BX_5U  = 0x0755;
'      Controller_BX_5UL = 0x0855;

'      Controller_AX_UL  = 0x2055;
'      Controller_AX_UT  = 0x2155;
'      Controller_AX_U0  = 0x2255;
'      Controller_AX_U1  = 0x2355;
'      Controller_AX_U2  = 0x2455;

'      Controller_BX_5Q0 = 0x0056;
'      Controller_BX_5Q1 = 0x0156;
'      Controller_BX_5Q2 = 0x0256;
'      Controller_BX_5Q0P = 0x1056;
'      Controller_BX_5Q1P = 0x1156;
'      Controller_BX_5Q2P = 0x1256;
'      Controller_BX_5QL = 0x1356;

'      Controller_BX_5QS1 = 0x0157;
'      Controller_BX_5QS2 = 0x0257;
'      Controller_BX_5QS = 0x0357;
'      Controller_BX_5QS1P = 0x1157;
'      Controller_BX_5QS2P = 0x1257;
'      Controller_BX_5QSP = 0x1357;
'
'        Controller_BX_6E1 = $0174;
'       Controller_BX_6E2 = $0274;
'        Controller_BX_6E3 = $0374;
'
'         Controller_BX_6Q1 = $0166;
'         Controller_BX_6Q2 = $0266;
'         Controller_BX_6Q2L = $0466;
'         Controller_BX_6Q3 = $0366;
'         Controller_BX_6Q3L = $0566;
'    nScreenNo       :显示屏屏号；该参数与LedshowTW 2013软件中"设置屏参"模块的"屏号"参数一致。
'    nWidth          :显示屏宽度 16的整数倍；最小64；BX-5E系列最小为80
'    nHeight         :显示屏高度 16的整数倍；最小16；
'    nScreenType     :显示屏类型；1：单基色；2：双基色；
'      3：双基色；注意：该显示屏类型只有BX-4MC支持；同时该型号控制器不支持其它显示屏类型。
'      4：全彩色；注意：该显示屏类型只有BX-5Q系列支持；同时该型号控制器不支持其它显示屏类型。
'      5：双基色灰度；注意：该显示屏类型只有BX-5QS支持；同时该型号控制器不支持其它显示屏类型。
'    nPixelMode      :点阵类型；1：R+G；2：G+R；该参数只对双基色屏有效 ；默认为2；
'    nDataDA         :数据极性；，0x00：数据低有效，0x01：数据高有效；默认为0；
'    nDataOE         :OE极性；  0x00：OE 低有效；0x01：OE 高有效；默认为0；
'    nRowOrder       :行序模式；0：正常；1：加1行；2：减1行；默认为0；
'    nFreqPar        :扫描点频；0~6；默认为0；
'    pCom            :串口名称；串口通讯模式时有效；例:COM1
'    nBaud           :串口波特率：目前支持9600、57600；默认为57600；
'    pSocketIP       :控制卡IP地址，网络通讯模式时有效；例:192.168.0.199；
'      本动态库网络通讯模式时只支持固定IP模式，单机直连和网络服务器模式不支持。
'    nSocketPort     :控制卡网络端口；网络通讯模式时有效；例：5005
'    pWiFiIP         :控制器WiFi模式的IP地址信息；WiFi通讯模式时有效；例:192.168.100.1
'    nWiFiPort       :控制卡WiFi端口；WiFi通讯模式时有效；例：5005
'    pScreenStatusFile:用于保存查询到的显示屏状态参数保存的INI文件名；
'      只有执行查询显示屏状态GetScreenStatus时，该参数才有效
'返回值:              详见返回状态代码定义?
'-------------------------------------------------------------------------------
Public Declare Function AddScreen Lib "BX_IV.DLL" (ByVal nControlType As Long, ByVal nScreenNo As Long, ByVal nSendMode As Long, _
ByVal nWidth As Long, ByVal nHeight As Long, ByVal nScreenType As Long, ByVal nPixelMode As Long, ByVal nDataDA As Long, _
ByVal nDataOE As Long, ByVal nRowOrder As Long, ByVal nDataFlow As Long, ByVal nFreqPar As Long, ByVal pCom As String, ByVal nBaud As Long, ByVal pScoketIP As String, _
ByVal nScoketPort As Long, ByVal nStaticIPMode As Long, ByVal nServerMode As Long, ByVal pBarcode As String, ByVal pNetworkID As String, _
ByVal pServerIP As String, ByVal nServerPort As Long, ByVal pServerAccessUser As String, ByVal pServerAccessPassword As String, _
ByVal pWiFiIP As String, ByVal nWiFiPort As Long, ByVal pGprsIP As String, ByVal nGprsPort As Long, ByVal pGprsID As String, ByVal pScreenStatusFile As String) As Long
'-------------------------------------------------------------------------------
'过程名:      AddScreenProgram
'  向动态库中指定显示屏添加节目；该函数不与显示屏通讯，只用于动态库中的指定显示屏节目信息配置。
'参数:
'    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
'    nProgramType    :节目类型；0正常节目。
'    nPlayLength     :0:表示自动顺序播放；否则表示节目播放的长度；范围1~65535；单位秒
'    nStartYear      :节目的生命周期；开始播放时间年份。如果为无限制播放的话该参数值为65535；如2010
'    nStartMonth     :节目的生命周期；开始播放时间月份。如11
'    nStartDay       :节目的生命周期；开始播放时间日期。如26
'    nEndYear        :节目的生命周期；结束播放时间年份。如2011
'    nEndMonth       :节目的生命周期；结束播放时间月份。如11
'    nEndDay         :节目的生命周期；结束播放时间日期。如26
'    nMonPlay        :节目在生命周期内星期一是否播放;0：不播放;1：播放.
'    nTuesPlay       :节目在生命周期内星期二是否播放;0：不播放;1：播放.
'    nWedPlay        :节目在生命周期内星期二是否播放;0：不播放;1：播放.
'    nThursPlay      :节目在生命周期内星期二是否播放;0：不播放;1：播放.
'    bFriPlay        :节目在生命周期内星期二是否播放;0：不播放;1：播放.
'    nSatPlay        :节目在生命周期内星期二是否播放;0：不播放;1：播放.
'    nSunPlay        :节目在生命周期内星期二是否播放;0：不播放;1：播放.
'nStartHour:          节目在当天开始播放时间小时?如8
'nStartMinute:        节目在当天开始播放时间分钟?如0
'nEndHour:            节目在当天结束播放时间小时?如18
'nEndMinute:          节目在当天结束播放时间分钟?如0
'返回值:              详见返回状态代码定义?
'-------------------------------------------------------------------------------
Public Declare Function AddScreenProgram Lib "BX_IV.DLL" (ByVal nScreenNo As Long, ByVal nProgramType As Long, _
ByVal nPlayLength As Long, ByVal nStartYear As Long, ByVal nStartMonth As Long, ByVal nStartDay As Long, ByVal nEndYear As Long, ByVal nEndMonth As Long, ByVal nEndDay As Long, _
ByVal nMonPlay As Long, ByVal nTuesPlay As Long, ByVal nWedPlay As Long, ByVal nThursPlay As Long, ByVal bFriPlay As Long, _
ByVal nSatPlay As Long, ByVal nSunPlay As Long, ByVal nStartHour As Long, ByVal nStartMinute As Long, ByVal nEndHour As Long, ByVal nEndMinute As Long) As Long
'-------------------------------------------------------------------------------
'过程名:      AddScreenProgramBmpTextArea:
'  向动态库中指定显示屏的指定节目添加图文区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中的图文区域信息配置。
'参数:
'    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
'    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
'    nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
'    nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
'    nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
'    nHeight         :区域的高度；最大值不大于显示屏高度-nY
'返回值:              详见返回状态代码定义?
'-------------------------------------------------------------------------------
Public Declare Function AddScreenProgramBmpTextArea Lib "BX_IV.DLL" (ByVal nScreenNo As Long, ByVal nProgramOrd As Long, _
ByVal nX As Long, ByVal nY As Long, ByVal nWidth As Long, ByVal nHeight As Long) As Long
'-------------------------------------------------------------------------------
'过程名:      AddScreenProgramAreaBmpTextFile
'  向动态库中指定显示屏的指定节目的指定图文区域添加文件；
'      该函数不与显示屏通讯，只用于动态库中的指定显示屏指定节目中指定图文区域的文件信息配置。
'参数:
'    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
'    nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
'    nAreaOrd        :区域序号；该序号按照区域添加顺序，从0顺序递增，如删除中间的区域，后面的区域序号自动填充。
'    pFileName:           文件名称 支持.bmp, jpg, jpeg, rtf, txt等文件类型?
'    nShowSingle     :单、多行显示；1：单行显示；0：多行显示；该参数只有在pFileName为txt类型文件时该参数才有效。
'    nHorAlign      :居中显示：0 居左 1居中 2 居右.
'   nVerAlign   :居中显示：0 居中 1 居上 2居下
'    pFontName       :字体名称；支持当前操作系统已经安装的矢量字库；该参数只有pFileName为txt类型文件时该参数才有效。
'    nFontSize       :字体字号；支持当前操作系统的字号；该参数只有pFileName为txt类型文件时该参数才有效。
'    nBold           :字体粗体；支持1：粗体；0：正常；该参数只有pFileName为txt类型文件时该参数才有效。
'    nFontColor      :字体颜色；该参数只有pFileName为txt类型文件时该参数才有效。
'    nStunt:              显示特技?
'       0x00:     随机显示
'       0x01:     静态
'       0x02:     快速打出
'       0x03:     向左移动
'       0x04:     向左连移
'       0x05:     向上移动            3T类型控制卡无此特技
'       0x06:     向上连移            3T类型控制卡无此特技
'       0x07:     闪烁                3T类型控制卡无此特技
'       0x08:     飘雪
'       0x09:     冒泡
'       0x0A:     中间移出
'       0x0B:     左右移入
'       0x0C:     左右交叉移入
'       0x0D:     上下交叉移入
'       0x0E:     画卷闭合
'       0x0F:     画卷打开
'       0x10:     向左拉伸
'       0x11:     向右拉伸
'       0x12:     向上拉伸
'       0x13:     向下拉伸            3T类型控制卡无此特技
'       0x14:     向左镭射
'       0x15:     向右镭射
'       0x16:     向上镭射
'       0x17:     向下镭射
'       0x18:     左右交叉拉幕
'       0x19:     上下交叉拉幕
'       0x1A:     分散左拉
'       0x1B:水平百页            3T、3A、4A、3A1、3A2、4A1、4A2、4A3、4AQ类型控制卡无此特技
'       0x1C:垂直百页            3T、3A、4A、3A1、3A2、4A1、4A2、4A3、4AQ、3M、4M、4M1、4MC类型控制卡无此特技
'       0x1D:向左拉幕            3T、3A、4A类型控制卡无此特技
'       0x1E:向右拉幕            3T、3A、4A类型控制卡无此特技
'       0x1F:向上拉幕            3T、3A、4A类型控制卡无此特技
'       0x20:向下拉幕            3T、3A、4A类型控制卡无此特技
'       0x21:左右闭合            3T类型控制卡无此特技
'       0x22:左右对开            3T类型控制卡无此特技
'       0x23:上下闭合            3T类型控制卡无此特技
'       0x24:上下对开            3T类型控制卡无此特技
'       0x25:     向右连移
'       0x26:     向右连移
'       0x27:向下移动            3T类型控制卡无此特技
'       0x28:向下连移            3T类型控制卡无此特技
'    nRunSpeed       :运行速度；0~63；值越大运行速度越慢。
'    nShowTime       :停留时间；0~65525；单位0.5秒
'    nStretch        :拉伸+；收缩-
'    nShift          :上移-；下移+
'
'返回值:: 详见返回状态代码定义?
'-------------------------------------------------------------------------------
Public Declare Function AddScreenProgramAreaBmpTextFile Lib "BX_IV.DLL" (ByVal nScreenNo As Long, ByVal nProgramOrd As Long, _
ByVal nAreaOrd As Long, ByVal pFileName As String, ByVal nShowSingle As Long, ByVal nHorAlign As Long, ByVal nVerAlign As Long, ByVal pFontName As String, ByVal nFontSize As Long, ByVal nBold As Long, _
ByVal nItalic As Long, ByVal nUnderline As Long, ByVal nFontColor As Long, ByVal nStunt As Long, ByVal nRunSpeed As Long, ByVal nShowTime As Long, ByVal nStretch As Long, ByVal nShift As Long) As Long



Public Declare Function AddScreenProgramAreaBmpTextText Lib "BX_IV.DLL" (ByVal nScreenNo As Long, ByVal nProgramOrd As Long, _
ByVal nAreaOrd As Long, ByVal pText As String, ByVal nShowSingle As Long, ByVal nHorAlign As Long, ByVal nVerAlign As Long, ByVal pFontName As String, ByVal nFontSize As Long, ByVal nBold As Long, _
ByVal nItalic As Long, ByVal nUnderline As Long, ByVal nFontColor As Long, ByVal nStunt As Long, ByVal nRunSpeed As Long, ByVal nShowTime As Long, ByVal nStretch As Long, ByVal nShift As Long) As Long
'-------------------------------------------------------------------------------
'过程名:      SendScreenInfo
'  通过指定的通讯模式，发送相应信息、命令到显示屏。该函数与显示屏进行通讯
'参数:
'    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
'    nSendMode       :与显示屏的通讯模式；
'      0:串口模式、BX-5A2&RF、BX-5A4&RF等控制器为RF串口无线模式;
'      2:网络模式;
'4:      WiFi模式
'nSendCmd:            通讯命令值
'      SEND_CMD_PARAMETER =41471;  加载屏参数。
'      SEND_CMD_SENDALLPROGRAM = 41456;  发送所有节目信息。
'      SEND_CMD_POWERON =41727; 强制开机
'      SEND_CMD_POWEROFF = 41726; 强制关机
'      SEND_CMD_TIMERPOWERONOFF = 41725; 定时开关机
'      SEND_CMD_CANCEL_TIMERPOWERONOFF = 41724; 取消定时开关机
'      SEND_CMD_RESIVETIME = 41723; 校正时间。
'      SEND_CMD_ADJUSTLIGHT = 41722; 亮度调整。
'    nOtherParam1    :保留参数；0
'返回值:              详见返回状态代码定义?
'-------------------------------------------------------------------------------
Public Declare Function SendScreenInfo Lib "BX_IV.DLL" (ByVal nScreenNo As Long, ByVal nSendCmd As Long, _
ByVal nOtherParam1 As Long) As Long

'-------------------------------------------------------------------------------
'过程名:      DeleteScreen
'  删除指定显示屏信息，删除显示屏成功后会将该显示屏下所有节目信息从动态库中删除。
'  该函数不与显示屏通讯，只用于动态库中的指定显示屏参数信息配置。
'参数:
'    nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
'返回值:              详见返回状态代码定义?
'-------------------------------------------------------------------------------
Public Declare Function DeleteScreen Lib "BX_IV.DLL" (ByVal nScreenNo As Long) As Long

Public Sub CallBack(ByVal szMessagge As String, ByVal nProgress As Long)

End Sub


