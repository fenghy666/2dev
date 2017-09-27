using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace BXEDemoC
{
    public class LedApi_1
    {
        [DllImport("BxEDLL.dll", CallingConvention = CallingConvention.StdCall)]
        public unsafe static extern int SetScreenParameter(int nWidth, int nHeight, int nScreenType, int nMkType, int nDataDA, int nDataOE, byte* pFileName);

        [DllImport("BxEDLL.dll", CallingConvention = CallingConvention.StdCall)]
        public unsafe static extern int SetScreenState(bool bScreenState, byte* pFileName);

        [DllImport("BxEDLL.dll", CallingConvention = CallingConvention.StdCall)]
        public unsafe static extern int SetScreenDial(int nX, int nY, int nWidth, int nHeight, int nAllDotRadius, int n369DotRadius, int nHourPointerWidth, int nMinutePointerWidth,
                                                   int nAllDotColor, int n369DotColor, int nHourPointerColor, int nMinutePointerColor, int nSecondPointerColor, byte* pFileName);

        [DllImport("BxEDLL.dll", CallingConvention = CallingConvention.StdCall)]
        public unsafe static extern int SetScreenBmpText(int nX, int nY, int nWidth, int nHeight, int nScreenType, int nMkType, byte* pSourceFile,
                                                int nSourceType, int nStunt, int nRunSpeed, int nShowTime, byte* pFileName, bool bDeleted);


        [DllImport("BxEDLL.dll", CallingConvention = CallingConvention.StdCall)]
        public unsafe static extern int SetDynamicAttrib(int nX, int nY, int nWidth, int nHeight,int nScreenType,int nMkType,
                                                int bShowExceptPic,int nExceptTime,byte* pExceptPic, byte* pFileName);

        [DllImport("BxEDLL.dll", CallingConvention = CallingConvention.StdCall)]
        public unsafe static extern int TranDynamicData(int nOrdArea, int nX, int nY, int nWidth, int nHeight, int nScreenType,
                                        int nMkType, int nPage, int nStunt, int nRunSpeed, int nShowTime, byte* pSourceName,int nSourceType,
                                           byte* pDataFileName, bool bNew);

        [DllImport("BxEDLL.dll", CallingConvention = CallingConvention.StdCall)]
        public unsafe static extern int GetAllDataHead(int nAreaCount, int nWidth, int nHeight, int nScreenType, byte* pFileName);

        [DllImport("BxEDLL.dll", CallingConvention = CallingConvention.StdCall)]
        public unsafe static extern int GetCurDataTime(byte* pFileName);

        [DllImport("BxEDLL.dll", CallingConvention = CallingConvention.StdCall)]
        public unsafe static extern int SendTCPIPData(byte* pTCPAddress, int nPort, int nSendType, int nWidth, int nHeight, int nScreenType,  byte* pSendBufFile);

        [DllImport("BxEDLL.dll", CallingConvention = CallingConvention.StdCall)]
        public unsafe static extern int ResiveCurTime(byte* pFileName); 

        [DllImport("BxEDLL.dll", CallingConvention = CallingConvention.StdCall)]
        public unsafe static extern int UnionAreaDataToFile(byte* pSourceFile,byte* pUnionedFile,bool bDeleted); 
    }
}
