using System;
using System.Collections.Generic;
using System.Text;

namespace BXEDemoC
{
    class LedApiControl
    {


        public int SetScreenParameter(int nWidth, int nHeight, int nScreenType, int nMkType, int nDataDA, int nDataOE, string fileName)
        {
            unsafe
            {
                byte[] fileNameBytes = Encoding.Default.GetBytes(fileName);
                fixed (byte* pFileName = fileNameBytes)
                {
                    return LedApi_1.SetScreenParameter(nWidth, nHeight, nScreenType, nMkType, nDataDA, nDataOE, pFileName);
                }
            }
        }

        public int SetScreenOn(bool bScreenState, string fileName)
        {
            unsafe
            {
                byte[] fileNameBytes = Encoding.Default.GetBytes(fileName);
                fixed (byte* pFileName = fileNameBytes)
                {
                    return LedApi_1.SetScreenState(true, pFileName);
                }
            }
        }

        public int SetScreenOff(bool bScreenState, string fileName)
        {
            unsafe
            {
                byte[] fileNameBytes = Encoding.Default.GetBytes(fileName);
                fixed (byte* pFileName = fileNameBytes)
                {
                    return LedApi_1.SetScreenState(false, pFileName);
                }
            }
        }

        public int SetScreenDial(int nX, int nY, int nWidth, int nHeight, int nAllDotRadius, int n369DotRadius, int nHourPointerWidth, int nMinutePointerWidth,
                                                   int nAllDotColor, int n369DotColor, int nHourPointerColor, int nMinutePointerColor, int nSecondPointerColor, string fileName)
        {
            unsafe
            {
                byte[] fileNameBytes = Encoding.Default.GetBytes(fileName);
                fixed (byte* pFileName = fileNameBytes)
                {
                    return LedApi_1.SetScreenDial(nX, nY, nWidth, nHeight, nAllDotRadius, n369DotRadius, nHourPointerWidth, nMinutePointerWidth,
                                                    nAllDotColor, n369DotColor, nHourPointerColor, nMinutePointerColor, nSecondPointerColor, pFileName);
                }
            }
        }

        public int SendTCPIPData(string pTCPAddress, int nPort, int nSendType, int nWidth, int nHeight, int nScreenType, string fileName)
        {

            byte[] fileNameBytes = Encoding.Default.GetBytes(fileName);
            byte[] IPBytes = Encoding.Default.GetBytes(pTCPAddress);
            unsafe
            {
                fixed (byte* TCPAddress = IPBytes, pFileName = fileNameBytes)
                {
                    int nReturn=LedApi_1.SendTCPIPData(TCPAddress, nPort, nSendType, nWidth, nHeight, nScreenType, pFileName);
                    return  nReturn;
                }
            }
        }

        public int SetDynamicAttrib(int nX, int nY, int nWidth, int nHeight, int nScreenType, int nMkType,
                                                int bShowExceptPic, int nExceptTime, string ExceptPic, string FileName)
        {
            byte[] ExceptPicBytes = Encoding.Default.GetBytes(ExceptPic);
            byte[] FileNameBytes = Encoding.Default.GetBytes(FileName);
            unsafe
            {
                fixed (byte* pFileName = FileNameBytes, pExceptPic = ExceptPicBytes)
                {
                    return LedApi_1.SetDynamicAttrib(nX, nY, nWidth, nHeight, nScreenType,  nMkType,
                                                 bShowExceptPic,  nExceptTime,  pExceptPic,  pFileName);
                }
            }
        }

        public int TranDynamicData(int nOrdArea, int nX, int nY, int nWidth, int nHeight, int nScreenType,
                                        int nMkType, int nPage, int nStunt, int nRunSpeed, int nShowTime, string pSourceName,int nSourceType,
                                           string pDataFileName, bool bNew)
        {
            byte[] dataFileNameBytes = Encoding.Default.GetBytes(pDataFileName);
            byte[] sourceNameBytes = Encoding.Default.GetBytes(pSourceName);
            unsafe
            {
                fixed (byte* DataFileName = dataFileNameBytes, SourceName = sourceNameBytes)
                {
                    return LedApi_1.TranDynamicData(nOrdArea, nX, nY, nWidth, nHeight, nScreenType, nMkType, nPage,
                                                     nStunt, nRunSpeed, nShowTime, SourceName,nSourceType, DataFileName, bNew);
                }
            }
        }

        public int GetAllDataHead(int nAreaCount, int nWidth, int nHeight, int nScreenType, string fileName)
        {
            byte[] fileNameBytes = Encoding.Default.GetBytes(fileName);
            unsafe
            {
                fixed (byte* pFileName = fileNameBytes)
                {
                    return LedApi_1.GetAllDataHead(nAreaCount, nWidth, nHeight, nScreenType, pFileName);
                }
            }
        }

        public int GetCurDataTime(string fileName)
        {
            byte[] fileNameBytes = Encoding.Default.GetBytes(fileName);
            unsafe
            {
                fixed (byte* pFileName = fileNameBytes)
                {
                    return LedApi_1.GetCurDataTime(pFileName);
                }
            }
        }

        public int ResiveCurTime(string fileName)
        {
            byte[] fileNameBytes = Encoding.Default.GetBytes(fileName);
            unsafe
            {
                fixed (byte* pFileName = fileNameBytes)
                {
                    return LedApi_1.ResiveCurTime(pFileName);
                }
            }
        }

        public int SetScreenBmpText(int nX, int nY, int nWidth, int nHeight, int nScreenType, int nMkType, string pSourceFile,
                                                int nSourceType, int nStunt, int nRunSpeed, int nShowTime, string pFileName, bool bDeleted)
        {
            byte[] fileNameBytes = Encoding.Default.GetBytes(pFileName);
            byte[] sourceNameBytes = Encoding.Default.GetBytes(pSourceFile);
            unsafe
            {
                fixed (byte* DataFileName = fileNameBytes, SourceName = sourceNameBytes)
                {
                    return LedApi_1.SetScreenBmpText(nX, nY, nWidth, nHeight, nScreenType, nMkType, SourceName, nSourceType, nStunt, nRunSpeed, nShowTime, DataFileName, bDeleted);
                }
            }
        }

        public int UnionAreaDataToFile(string pSourceFile, string pUnionedFile, bool bDeleted)
        {
            byte[] sourceFileBytes = Encoding.Default.GetBytes(pSourceFile);
            byte[] unionedFileBytes = Encoding.Default.GetBytes(pUnionedFile);
            unsafe
            {
                fixed (byte* SourceFile = sourceFileBytes, UnionedFile = unionedFileBytes)
                {
                    return LedApi_1.UnionAreaDataToFile(SourceFile, UnionedFile,bDeleted);
                }
            }
        }
    }
}
