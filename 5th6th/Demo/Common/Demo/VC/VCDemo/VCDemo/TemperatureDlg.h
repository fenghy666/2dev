#pragma once

/*------------------------------------------------------------------------------------
         过程名:    AddScreenProgramTemperatureArea
         向动态库中指定显示屏的指定节目添加温度区域；该函数不与显示屏通讯，只用于动态库中的指定显示屏节目中的温度区域信息配置。
              参数:
                  nScreenNo       :显示屏屏号；该参数与AddScreen函数中的nScreenNo参数对应。
                  nProgramOrd     :节目序号；该序号按照节目添加顺序，从0顺序递增，如删除中间的节目，后面的节目序号自动填充。
                  nX              :区域的横坐标；显示屏的左上角的横坐标为0；最小值为0
                  nY              :区域的纵坐标；显示屏的左上角的纵坐标为0；最小值为0
                  nWidth          :区域的宽度；最大值不大于显示屏宽度-nX
                  nHeight         :区域的高度；最大值不大于显示屏高度-nY
                  nSensorType     :温度传感器类型；
                  0:"Temp sensor S-T1";
                  1:"Temp and hum sensor S-RHT 1";
                  2:"Temp and hum sensor S-RHT 2"
                  nTemperatureUnit:温度显示单位；0:摄氏度(℃);1:华氏度(℉);2:摄氏度(无)
                  nTemperatureMode:温度显示模式；0:整数型；1:小数型。
                  nTemperatureUnitScale:温度单位显示比例；50~100;默认为100.
                  nTemperatureValueWidth:温度数值字符显示宽度；
                  nTemperatureCorrectionPol:温度值误差修正值极性；0；正；1：负
                  nTemperatureCondition:温度值误差修正值；
                  nTemperatureThreshPol:温度阈值条件；0:表示小于此值触发事情;1:表示大于此值触发条件
                  nTemperatureThresh:温度阈值
                  nTemperatureColor:正常温度颜色
                  nTemperatureErrColor:温度超过阈值时显示的颜色
                  pStaticText     :温度区域前缀固定文本;该参数可为空
                  pStaticFont     :字体名称；支持当前操作系统已经安装的矢量字库；
                  nStaticSize     :字体字号；支持当前操作系统的字号；
                  nStaticColor    :字体颜色；
                  nStaticBold     :字体粗体；支持1：粗体；0：正常；
             返回值            :详见返回状态代码定义。
        ---------------------------------------------------------------------------}
        ---------------------------------------------------------------------------* */
        typedef int (__stdcall *pAddScreenProgramTemperatureArea)(int nScreenNo, int nProgramOrd,
            int nX, int nY, int nWidth, int nHeight,
            int nSensorType,
            int nTemperatureUnit,
            int nTemperatureMode,
            int nTemperatureUnitScale,
            int nTemperatureValueWidth,
            int nTemperatureCorrectionPol,
            int nTemperatureCondition,
            int nTemperatureThreshPol,
            int nTemperatureThresh,
            int  nTemperatureColor,
            int  nTemperatureErrColor,
            char* pStaticText,
            char* pStaticFont,
            int nStaticSize,
            int  intnStaticColor,
            int nStaticBold);

// CTemperatureDlg 对话框

class CTemperatureDlg : public CDialog
{
	DECLARE_DYNAMIC(CTemperatureDlg)

public:
	CTemperatureDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTemperatureDlg();

	HINSTANCE hInst;
	BOOL m_bSendBusy;//此变量在数据更新中非常重要，请务必保留。
	pAddScreenProgramTemperatureArea AddScreenProgramTemperatureArea;

// 对话框数据
	enum { IDD = IDD_Temperature_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	void CTemperatureDlg::GetErrorMessage(char* szfunctionName, int nResult);
};
