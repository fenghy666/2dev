Attribute VB_Name = "Module1"
Private Declare Function GetWindow Lib "user32" Alias "FindWindowA" (ByVal lpClassName As String, ByVal lpWindowName As String) As Long
'������:    Initialize
'          ��ʼ����̬�⣻�ú���������ʾ��ͨѶ��
'DLLApp:              ��������
'pCallBack:           ���ط��͵���Ϣ�ͽ���
'                             ����Ϊ TCallBackFunc = procedure(szMessagge:string;nProgress:integer); stdcall;
'����ֵ:                      �������״̬���붨��?
Public Declare Function Initialize Lib "BX_IV.DLL" (ByVal DllApp As Long, ByVal pCallBack As Long) As Long

Public Declare Function Uninitialize Lib "BX_IV.DLL" () As Long


'-------------------------------------------------------------------------------
'������:      AddScreen
'  ��̬���������ʾ����Ϣ���ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��������Ϣ���á�
'����:
'    nControlType    :��ʾ���Ŀ������ͺţ�����궨�塰�������ͺŶ��塱
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
'    nScreenNo       :��ʾ�����ţ��ò�����LedshowTW 2013�����"��������"ģ���"����"����һ�¡�
'    nWidth          :��ʾ����� 16������������С64��BX-5Eϵ����СΪ80
'    nHeight         :��ʾ���߶� 16������������С16��
'    nScreenType     :��ʾ�����ͣ�1������ɫ��2��˫��ɫ��
'      3��˫��ɫ��ע�⣺����ʾ������ֻ��BX-4MC֧�֣�ͬʱ���ͺſ�������֧��������ʾ�����͡�
'      4��ȫ��ɫ��ע�⣺����ʾ������ֻ��BX-5Qϵ��֧�֣�ͬʱ���ͺſ�������֧��������ʾ�����͡�
'      5��˫��ɫ�Ҷȣ�ע�⣺����ʾ������ֻ��BX-5QS֧�֣�ͬʱ���ͺſ�������֧��������ʾ�����͡�
'    nPixelMode      :�������ͣ�1��R+G��2��G+R���ò���ֻ��˫��ɫ����Ч ��Ĭ��Ϊ2��
'    nDataDA         :���ݼ��ԣ���0x00�����ݵ���Ч��0x01�����ݸ���Ч��Ĭ��Ϊ0��
'    nDataOE         :OE���ԣ�  0x00��OE ����Ч��0x01��OE ����Ч��Ĭ��Ϊ0��
'    nRowOrder       :����ģʽ��0��������1����1�У�2����1�У�Ĭ��Ϊ0��
'    nFreqPar        :ɨ���Ƶ��0~6��Ĭ��Ϊ0��
'    pCom            :�������ƣ�����ͨѶģʽʱ��Ч����:COM1
'    nBaud           :���ڲ����ʣ�Ŀǰ֧��9600��57600��Ĭ��Ϊ57600��
'    pSocketIP       :���ƿ�IP��ַ������ͨѶģʽʱ��Ч����:192.168.0.199��
'      ����̬������ͨѶģʽʱֻ֧�̶ֹ�IPģʽ������ֱ�������������ģʽ��֧�֡�
'    nSocketPort     :���ƿ�����˿ڣ�����ͨѶģʽʱ��Ч������5005
'    pWiFiIP         :������WiFiģʽ��IP��ַ��Ϣ��WiFiͨѶģʽʱ��Ч����:192.168.100.1
'    nWiFiPort       :���ƿ�WiFi�˿ڣ�WiFiͨѶģʽʱ��Ч������5005
'    pScreenStatusFile:���ڱ����ѯ������ʾ��״̬���������INI�ļ�����
'      ֻ��ִ�в�ѯ��ʾ��״̬GetScreenStatusʱ���ò�������Ч
'����ֵ:              �������״̬���붨��?
'-------------------------------------------------------------------------------
Public Declare Function AddScreen Lib "BX_IV.DLL" (ByVal nControlType As Long, ByVal nScreenNo As Long, ByVal nSendMode As Long, _
ByVal nWidth As Long, ByVal nHeight As Long, ByVal nScreenType As Long, ByVal nPixelMode As Long, ByVal nDataDA As Long, _
ByVal nDataOE As Long, ByVal nRowOrder As Long, ByVal nDataFlow As Long, ByVal nFreqPar As Long, ByVal pCom As String, ByVal nBaud As Long, ByVal pScoketIP As String, _
ByVal nScoketPort As Long, ByVal nStaticIPMode As Long, ByVal nServerMode As Long, ByVal pBarcode As String, ByVal pNetworkID As String, _
ByVal pServerIP As String, ByVal nServerPort As Long, ByVal pServerAccessUser As String, ByVal pServerAccessPassword As String, _
ByVal pWiFiIP As String, ByVal nWiFiPort As Long, ByVal pGprsIP As String, ByVal nGprsPort As Long, ByVal pGprsID As String, ByVal pScreenStatusFile As String) As Long
'-------------------------------------------------------------------------------
'������:      AddScreenProgram
'  ��̬����ָ����ʾ����ӽ�Ŀ���ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ����Ŀ��Ϣ���á�
'����:
'    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
'    nProgramType    :��Ŀ���ͣ�0������Ŀ��
'    nPlayLength     :0:��ʾ�Զ�˳�򲥷ţ������ʾ��Ŀ���ŵĳ��ȣ���Χ1~65535����λ��
'    nStartYear      :��Ŀ���������ڣ���ʼ����ʱ����ݡ����Ϊ�����Ʋ��ŵĻ��ò���ֵΪ65535����2010
'    nStartMonth     :��Ŀ���������ڣ���ʼ����ʱ���·ݡ���11
'    nStartDay       :��Ŀ���������ڣ���ʼ����ʱ�����ڡ���26
'    nEndYear        :��Ŀ���������ڣ���������ʱ����ݡ���2011
'    nEndMonth       :��Ŀ���������ڣ���������ʱ���·ݡ���11
'    nEndDay         :��Ŀ���������ڣ���������ʱ�����ڡ���26
'    nMonPlay        :��Ŀ����������������һ�Ƿ񲥷�;0��������;1������.
'    nTuesPlay       :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
'    nWedPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
'    nThursPlay      :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
'    bFriPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
'    nSatPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
'    nSunPlay        :��Ŀ���������������ڶ��Ƿ񲥷�;0��������;1������.
'nStartHour:          ��Ŀ�ڵ��쿪ʼ����ʱ��Сʱ?��8
'nStartMinute:        ��Ŀ�ڵ��쿪ʼ����ʱ�����?��0
'nEndHour:            ��Ŀ�ڵ����������ʱ��Сʱ?��18
'nEndMinute:          ��Ŀ�ڵ����������ʱ�����?��0
'����ֵ:              �������״̬���붨��?
'-------------------------------------------------------------------------------
Public Declare Function AddScreenProgram Lib "BX_IV.DLL" (ByVal nScreenNo As Long, ByVal nProgramType As Long, _
ByVal nPlayLength As Long, ByVal nStartYear As Long, ByVal nStartMonth As Long, ByVal nStartDay As Long, ByVal nEndYear As Long, ByVal nEndMonth As Long, ByVal nEndDay As Long, _
ByVal nMonPlay As Long, ByVal nTuesPlay As Long, ByVal nWedPlay As Long, ByVal nThursPlay As Long, ByVal bFriPlay As Long, _
ByVal nSatPlay As Long, ByVal nSunPlay As Long, ByVal nStartHour As Long, ByVal nStartMinute As Long, ByVal nEndHour As Long, ByVal nEndMinute As Long) As Long
'-------------------------------------------------------------------------------
'������:      AddScreenProgramBmpTextArea:
'  ��̬����ָ����ʾ����ָ����Ŀ���ͼ�����򣻸ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ�е�ͼ��������Ϣ���á�
'����:
'    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
'    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
'    nX              :����ĺ����ꣻ��ʾ�������Ͻǵĺ�����Ϊ0����СֵΪ0
'    nY              :����������ꣻ��ʾ�������Ͻǵ�������Ϊ0����СֵΪ0
'    nWidth          :����Ŀ�ȣ����ֵ��������ʾ�����-nX
'    nHeight         :����ĸ߶ȣ����ֵ��������ʾ���߶�-nY
'����ֵ:              �������״̬���붨��?
'-------------------------------------------------------------------------------
Public Declare Function AddScreenProgramBmpTextArea Lib "BX_IV.DLL" (ByVal nScreenNo As Long, ByVal nProgramOrd As Long, _
ByVal nX As Long, ByVal nY As Long, ByVal nWidth As Long, ByVal nHeight As Long) As Long
'-------------------------------------------------------------------------------
'������:      AddScreenProgramAreaBmpTextFile
'  ��̬����ָ����ʾ����ָ����Ŀ��ָ��ͼ����������ļ���
'      �ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��ָ����Ŀ��ָ��ͼ��������ļ���Ϣ���á�
'����:
'    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
'    nProgramOrd     :��Ŀ��ţ�����Ű��ս�Ŀ���˳�򣬴�0˳���������ɾ���м�Ľ�Ŀ������Ľ�Ŀ����Զ���䡣
'    nAreaOrd        :������ţ�����Ű����������˳�򣬴�0˳���������ɾ���м�����򣬺������������Զ���䡣
'    pFileName:           �ļ����� ֧��.bmp, jpg, jpeg, rtf, txt���ļ�����?
'    nShowSingle     :����������ʾ��1��������ʾ��0��������ʾ���ò���ֻ����pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
'    nHorAlign      :������ʾ��0 ���� 1���� 2 ����.
'   nVerAlign   :������ʾ��0 ���� 1 ���� 2����
'    pFontName       :�������ƣ�֧�ֵ�ǰ����ϵͳ�Ѿ���װ��ʸ���ֿ⣻�ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
'    nFontSize       :�����ֺţ�֧�ֵ�ǰ����ϵͳ���ֺţ��ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
'    nBold           :������壻֧��1�����壻0���������ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
'    nFontColor      :������ɫ���ò���ֻ��pFileNameΪtxt�����ļ�ʱ�ò�������Ч��
'    nStunt:              ��ʾ�ؼ�?
'       0x00:     �����ʾ
'       0x01:     ��̬
'       0x02:     ���ٴ��
'       0x03:     �����ƶ�
'       0x04:     ��������
'       0x05:     �����ƶ�            3T���Ϳ��ƿ��޴��ؼ�
'       0x06:     ��������            3T���Ϳ��ƿ��޴��ؼ�
'       0x07:     ��˸                3T���Ϳ��ƿ��޴��ؼ�
'       0x08:     Ʈѩ
'       0x09:     ð��
'       0x0A:     �м��Ƴ�
'       0x0B:     ��������
'       0x0C:     ���ҽ�������
'       0x0D:     ���½�������
'       0x0E:     ����պ�
'       0x0F:     �����
'       0x10:     ��������
'       0x11:     ��������
'       0x12:     ��������
'       0x13:     ��������            3T���Ϳ��ƿ��޴��ؼ�
'       0x14:     ��������
'       0x15:     ��������
'       0x16:     ��������
'       0x17:     ��������
'       0x18:     ���ҽ�����Ļ
'       0x19:     ���½�����Ļ
'       0x1A:     ��ɢ����
'       0x1B:ˮƽ��ҳ            3T��3A��4A��3A1��3A2��4A1��4A2��4A3��4AQ���Ϳ��ƿ��޴��ؼ�
'       0x1C:��ֱ��ҳ            3T��3A��4A��3A1��3A2��4A1��4A2��4A3��4AQ��3M��4M��4M1��4MC���Ϳ��ƿ��޴��ؼ�
'       0x1D:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
'       0x1E:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
'       0x1F:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
'       0x20:������Ļ            3T��3A��4A���Ϳ��ƿ��޴��ؼ�
'       0x21:���ұպ�            3T���Ϳ��ƿ��޴��ؼ�
'       0x22:���ҶԿ�            3T���Ϳ��ƿ��޴��ؼ�
'       0x23:���±պ�            3T���Ϳ��ƿ��޴��ؼ�
'       0x24:���¶Կ�            3T���Ϳ��ƿ��޴��ؼ�
'       0x25:     ��������
'       0x26:     ��������
'       0x27:�����ƶ�            3T���Ϳ��ƿ��޴��ؼ�
'       0x28:��������            3T���Ϳ��ƿ��޴��ؼ�
'    nRunSpeed       :�����ٶȣ�0~63��ֵԽ�������ٶ�Խ����
'    nShowTime       :ͣ��ʱ�䣻0~65525����λ0.5��
'    nStretch        :����+������-
'    nShift          :����-������+
'
'����ֵ:: �������״̬���붨��?
'-------------------------------------------------------------------------------
Public Declare Function AddScreenProgramAreaBmpTextFile Lib "BX_IV.DLL" (ByVal nScreenNo As Long, ByVal nProgramOrd As Long, _
ByVal nAreaOrd As Long, ByVal pFileName As String, ByVal nShowSingle As Long, ByVal nHorAlign As Long, ByVal nVerAlign As Long, ByVal pFontName As String, ByVal nFontSize As Long, ByVal nBold As Long, _
ByVal nItalic As Long, ByVal nUnderline As Long, ByVal nFontColor As Long, ByVal nStunt As Long, ByVal nRunSpeed As Long, ByVal nShowTime As Long, ByVal nStretch As Long, ByVal nShift As Long) As Long



Public Declare Function AddScreenProgramAreaBmpTextText Lib "BX_IV.DLL" (ByVal nScreenNo As Long, ByVal nProgramOrd As Long, _
ByVal nAreaOrd As Long, ByVal pText As String, ByVal nShowSingle As Long, ByVal nHorAlign As Long, ByVal nVerAlign As Long, ByVal pFontName As String, ByVal nFontSize As Long, ByVal nBold As Long, _
ByVal nItalic As Long, ByVal nUnderline As Long, ByVal nFontColor As Long, ByVal nStunt As Long, ByVal nRunSpeed As Long, ByVal nShowTime As Long, ByVal nStretch As Long, ByVal nShift As Long) As Long
'-------------------------------------------------------------------------------
'������:      SendScreenInfo
'  ͨ��ָ����ͨѶģʽ��������Ӧ��Ϣ�������ʾ�����ú�������ʾ������ͨѶ
'����:
'    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
'    nSendMode       :����ʾ����ͨѶģʽ��
'      0:����ģʽ��BX-5A2&RF��BX-5A4&RF�ȿ�����ΪRF��������ģʽ;
'      2:����ģʽ;
'4:      WiFiģʽ
'nSendCmd:            ͨѶ����ֵ
'      SEND_CMD_PARAMETER =41471;  ������������
'      SEND_CMD_SENDALLPROGRAM = 41456;  �������н�Ŀ��Ϣ��
'      SEND_CMD_POWERON =41727; ǿ�ƿ���
'      SEND_CMD_POWEROFF = 41726; ǿ�ƹػ�
'      SEND_CMD_TIMERPOWERONOFF = 41725; ��ʱ���ػ�
'      SEND_CMD_CANCEL_TIMERPOWERONOFF = 41724; ȡ����ʱ���ػ�
'      SEND_CMD_RESIVETIME = 41723; У��ʱ�䡣
'      SEND_CMD_ADJUSTLIGHT = 41722; ���ȵ�����
'    nOtherParam1    :����������0
'����ֵ:              �������״̬���붨��?
'-------------------------------------------------------------------------------
Public Declare Function SendScreenInfo Lib "BX_IV.DLL" (ByVal nScreenNo As Long, ByVal nSendCmd As Long, _
ByVal nOtherParam1 As Long) As Long

'-------------------------------------------------------------------------------
'������:      DeleteScreen
'  ɾ��ָ����ʾ����Ϣ��ɾ����ʾ���ɹ���Ὣ����ʾ�������н�Ŀ��Ϣ�Ӷ�̬����ɾ����
'  �ú���������ʾ��ͨѶ��ֻ���ڶ�̬���е�ָ����ʾ��������Ϣ���á�
'����:
'    nScreenNo       :��ʾ�����ţ��ò�����AddScreen�����е�nScreenNo������Ӧ��
'����ֵ:              �������״̬���붨��?
'-------------------------------------------------------------------------------
Public Declare Function DeleteScreen Lib "BX_IV.DLL" (ByVal nScreenNo As Long) As Long

Public Sub CallBack(ByVal szMessagge As String, ByVal nProgress As Long)

End Sub


