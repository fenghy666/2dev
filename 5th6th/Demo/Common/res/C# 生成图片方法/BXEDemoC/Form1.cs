using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace BXEDemoC
{
    public partial class Form1 : Form
    {
        LedApiControl con = new LedApiControl();
        
        public Form1()
        {
            InitializeComponent();
            Timer controlTime = new Timer();
            controlTime.Interval = 1000;
            controlTime.Tick += new EventHandler(controlTime_Tick);
            controlTime.Start();
        }

        void controlTime_Tick(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            con.SetScreenParameter(128, 32, 2, 1, 0, 0, " ");
            int getresult = con.SendTCPIPData("192.168.10.123", 5005, 852, 128, 32, 2, "SetScreenParameter.bmp");
            if (getresult == 1)
            {
                MessageBox.Show("发送成功");
            }
            else
            {
                MessageBox.Show("发送失败");
            }


        }

        private void button2_Click(object sender, EventArgs e)
        {
            con.SetScreenOn(true, "SetScreenParameter");
            int getresult = con.SendTCPIPData("192.168.10.123", 5005, 852, 128, 32, 2, "SetScreenParameter");
            if (getresult == 1)
            {
                MessageBox.Show("发送成功");
            }
            else
            {
                MessageBox.Show("发送失败");
            }

        }

        private void button3_Click(object sender, EventArgs e)
        {
            con.SetScreenOff(false, "SetScreenParameter");
            int getresult = con.SendTCPIPData("192.168.0.235", 5005, 196, 384, 96, 2, "SetScreenParameter");
            if (getresult == 1)
            {
                MessageBox.Show("发送成功");
            }
            else
            {
                MessageBox.Show("发送失败");
            }
 
        }

        private void button4_Click(object sender, EventArgs e)
        {
            con.GetAllDataHead(3, 384, 96, 2, "GetAllDataHead");
            con.UnionAreaDataToFile("GetAllDataHead", "UnionAreaDataToFile", true);
            con.SetDynamicAttrib(96, 0, 288, 48,2,2,0,2,"", "SetDynamicAttrib");
            con.UnionAreaDataToFile("SetDynamicAttrib", "UnionAreaDataToFile", false);
            con.SetScreenDial(0, 0, 96, 96, 4, 5, 4, 3, 1, 2, 3, 1, 1, "SetScreenDial");
            con.UnionAreaDataToFile("SetScreenDial", "UnionAreaDataToFile", false);
            con.SetScreenBmpText(96, 48, 288, 48, 2, 1, "2.bmp", 0, 18, 1, 0, "SetScreenBmpText", true);
            con.UnionAreaDataToFile("SetScreenBmpText", "UnionAreaDataToFile", false);
            con.GetCurDataTime("GetCurDataTime");
            con.UnionAreaDataToFile("GetCurDataTime", "UnionAreaDataToFile", false);
            int getresult = con.SendTCPIPData("192.168.0.235", 5005, 209, 384, 96, 2, "UnionAreaDataToFile");
           if (getresult == 1)
            {
                MessageBox.Show("发送成功");
            }
            else
            {
                MessageBox.Show("发送失败");
            }

        }

        private void button6_Click(object sender, EventArgs e)
        {
            con.ResiveCurTime("CurTime");
            int getresult = con.SendTCPIPData("192.168.0.235", 5005, 205, 384, 96, 2, "CurTime");
            if (getresult == 1)
            {
                MessageBox.Show("发送成功");
            }
            else
            {
                MessageBox.Show("发送失败");
            }

        }
        private bool Timer_Ticket(int nInterVal)
        {
            bool mcheck = false;
            int i = DateTime.Now.Millisecond;
            while (!mcheck)
            {
                //dosomething here 

                if (DateTime.Now.Millisecond - i > nInterVal)
                    mcheck = true;
                else
                    mcheck = false;
            }

            return mcheck;
        }
        public struct RayTimer
        {
            public string szConstStr1;
            public string szTimerValue;
            public string szConstStr2;
           // public string szFontName;
           // public int nFontSize;
            public Color clFontClr;
            public Color clValueClr;
            public RayTimer(string pszConstStr1, string pszTimerValue, string pszConstStr2, string pszFontName, int pnFontSize,
                Color pclFontClr, Color pclValueClr)
            { 
                szConstStr1=pszConstStr1;
                szTimerValue=pszTimerValue;
                szConstStr2=pszConstStr2;
                //szFontName=pszFontName;
                //nFontSize=pnFontSize;
                clFontClr=pclFontClr;
                clValueClr=pclValueClr;
            }
        }
        private void RefReshTimerScreenData(string szIPAddress, int nPort, int nX, int nY, int nAreaWidth, int nAreaHeight, int nWidth,
            int nHeight, int nScreenType, int nMkStyle, int nStunt, int nRunSpeed, int nShowTime, int nReSendCount)
        /*
         * szIPAddress：显示屏的IP地址信息
         * nPort：显示屏的地址信息。
         * nX：实时计时区域的横坐标
         * nY：实时计时区域的纵坐标
         * nAreaWidth：实时计时区域的宽度
         * nAreaHeight：实时计时区域的高度
         * nWidth：显示屏的宽度
         * nHeight：显示屏的高度
         * nScreenType：显示屏类型；1：单色；2：双基色
         * nMkStyle：1：R+G；2：G+R；如果显示屏显示的颜色与程序颜色红绿反向时，取另外一个值。
         * nStunt：实时计时区域显示的特技方式。详见说明文档。
         * nRunSpeed：实时计时区域显示的运行速度。
         * nShowTime：实时计时区域显示的停留时间。单位为0.5s
         * szFileName：实时计时区域数据的文件名称。
         * nReSendCount：一幕信息的发送遍数。
        */
        {
            Dictionary<int, RayTimer> RayTimerDictionary = new Dictionary<int, RayTimer>();
            RayTimer tmpRayTimer = new RayTimer();

            //test
            text_TimerValue1.Text = "50秒";
            int tmpTimerValue = 50;


            for (int j = 1; j <= nReSendCount; j++)
            {
                ///test
                if (tmpTimerValue > 1)
                    tmpTimerValue = tmpTimerValue - 1;
                else
                    tmpTimerValue = 50;
                text_TimerValue1.Text = tmpTimerValue.ToString() + "秒";

                
                tmpRayTimer.szConstStr1 = "第一趟列车在";
                tmpRayTimer.szConstStr2 = "后进入本站";
                tmpRayTimer.szTimerValue = text_TimerValue1.Text;
                tmpRayTimer.clFontClr = Color.Yellow;
                tmpRayTimer.clValueClr = Color.Red;
                RayTimerDictionary.Add(1, tmpRayTimer);//每页的第一行显示第一趟列车计时信息

                tmpRayTimer.szConstStr1 = "第二趟列车在";
                tmpRayTimer.szConstStr2 = "后进入本站";
                tmpRayTimer.szTimerValue = text_TimerValue2.Text;
                tmpRayTimer.clFontClr = Color.Lime;
                tmpRayTimer.clValueClr = Color.Yellow;
                RayTimerDictionary.Add(2, tmpRayTimer);//每页的第一行显示第一趟列车计时信息

                tmpRayTimer.szConstStr1 = "第三趟列车在";
                tmpRayTimer.szConstStr2 = "后进入本站";
                tmpRayTimer.szTimerValue = text_TimerValue3.Text;
                tmpRayTimer.clFontClr = Color.Lime;
                tmpRayTimer.clValueClr = Color.Yellow;
                RayTimerDictionary.Add(3, tmpRayTimer);//每页的第一行显示第一趟列车计时信息
                //保存并且转换第一幕计时数据
                RefReshTimerAreaPic(nX, nY, nAreaWidth, nAreaHeight, nScreenType, nMkStyle, RayTimerDictionary,"宋体",
                    12, nStunt, nRunSpeed, nShowTime, szIPAddress + "_1.bmp");
                con.TranDynamicData(0, nX, nY, nAreaWidth, nAreaHeight, nScreenType, nMkStyle, 1, nStunt, nRunSpeed,
                    nShowTime, szIPAddress + "_1.bmp",0, szIPAddress, true);
                con.SendTCPIPData(szIPAddress, nPort, 210, nWidth, nHeight, nScreenType, szIPAddress);
                //此处可添加延时。
               // Timer_Ticket(500);
               RayTimerDictionary.Clear();
            }
            for (int j = 1; j <= nReSendCount; j++)
            {
                ///test
                if (tmpTimerValue > 1)
                    tmpTimerValue = tmpTimerValue - 1;
                else
                    tmpTimerValue = 50;
                text_TimerValue1.Text = tmpTimerValue.ToString() + "秒";

                
                tmpRayTimer.szConstStr1 = "第一趟列车在";
                tmpRayTimer.szConstStr2 = "后进入本站";
                tmpRayTimer.szTimerValue = text_TimerValue1.Text;
                tmpRayTimer.clFontClr = Color.Yellow;
                tmpRayTimer.clValueClr = Color.Red;
                RayTimerDictionary.Add(1, tmpRayTimer);//每页的第一行显示第一趟列车计时信息

                tmpRayTimer.szConstStr1 = "第四趟列车在";
                tmpRayTimer.szConstStr2 = "后进入本站";
                tmpRayTimer.szTimerValue = text_TimerValue4.Text;
                tmpRayTimer.clFontClr = Color.Lime;
                tmpRayTimer.clValueClr = Color.Yellow;
                RayTimerDictionary.Add(2, tmpRayTimer);//每页的第一行显示第一趟列车计时信息

                tmpRayTimer.szConstStr1 = "第五趟列车在";
                tmpRayTimer.szConstStr2 = "后进入本站";
                tmpRayTimer.szTimerValue = text_TimerValue5.Text;
                tmpRayTimer.clFontClr = Color.Lime;
                tmpRayTimer.clValueClr = Color.Yellow;
                RayTimerDictionary.Add(3, tmpRayTimer);//每页的第一行显示第一趟列车计时信息
                //保存并且转换第二幕计时数据
                RefReshTimerAreaPic(nX, nY, nAreaWidth, nAreaHeight, nScreenType, nMkStyle, RayTimerDictionary, "宋体",
                    12, nStunt, nRunSpeed, nShowTime, szIPAddress + "_2.bmp");
                con.TranDynamicData(0, nX, nY, nAreaWidth, nAreaHeight, nScreenType, nMkStyle, 1, nStunt, nRunSpeed, 
                    nShowTime, szIPAddress + "_2.bmp",0, szIPAddress,true);
                con.SendTCPIPData(szIPAddress, nPort, 210, nWidth, nHeight, nScreenType, szIPAddress );
                //此处可添加延时。
               // Timer_Ticket(500);
                RayTimerDictionary.Clear();
            }
            for (int j = 1; j <= nReSendCount; j++)//页内记录循环
            {
                ///test
                if (tmpTimerValue > 1)
                    tmpTimerValue = tmpTimerValue - 1;
                else
                    tmpTimerValue = 50;
                text_TimerValue1.Text = tmpTimerValue.ToString() + "秒";


                tmpRayTimer.szConstStr1 = "第一趟列车在";
                tmpRayTimer.szConstStr2 = "后进入本站";
                tmpRayTimer.szTimerValue = text_TimerValue1.Text;
                tmpRayTimer.clFontClr = Color.Yellow;
                tmpRayTimer.clValueClr = Color.Red;
                RayTimerDictionary.Add(1, tmpRayTimer);//每页的第一行显示第一趟列车计时信息

                tmpRayTimer.szConstStr1 = "第六趟列车在";
                tmpRayTimer.szConstStr2 = "后进入本站";
                tmpRayTimer.szTimerValue = text_TimerValue6.Text;
                tmpRayTimer.clFontClr = Color.Lime;
                tmpRayTimer.clValueClr = Color.Yellow;
                RayTimerDictionary.Add(2, tmpRayTimer);//每页的第一行显示第一趟列车计时信息
                //保存并且转换第三幕计时数据
                RefReshTimerAreaPic(nX, nY, nAreaWidth, nAreaHeight, nScreenType, nMkStyle, RayTimerDictionary, "宋体",
                    12, nStunt, nRunSpeed, nShowTime, szIPAddress + "_3.bmp");
                con.TranDynamicData(0, nX, nY, nAreaWidth, nAreaHeight, nScreenType, nMkStyle, 1, nStunt, nRunSpeed,
                    nShowTime, szIPAddress + "_3.bmp",0, szIPAddress, true);
                con.SendTCPIPData(szIPAddress, nPort, 210, nWidth, nHeight, nScreenType, szIPAddress);
                //此处可添加延时。
               // Timer_Ticket(500);
                RayTimerDictionary.Clear();
                
                }
                
        }

        private void RefReshTimerAreaPic(int nX,int nY,int nAreaWidth,int nAreaHeight,int nScreenType,int nMkStyle,
            Dictionary<int, RayTimer> RayTimerDictionary,string szFontName,int nFontSize,int nStunt,int nRunSpeed,
            int nShowTime,string szFileName)
        /*
         * nX：实时计时区域的横坐标
         * nY：实时计时区域的纵坐标
         * nAreaWidth：实时计时区域的宽度
         * nAreaHeight：实时计时区域的高度
         * nScreenType：显示屏类型；1：单色；2：双基色
         * nMkStyle：1：R+G；2：G+R；如果显示屏显示的颜色与程序颜色红绿反向时，取另外一个值。
         * RayTimerDictionary：列车信息结构体。
         * szFontName：实时计时区域显示的字体名称。
         * nFontSize：实时计时区域显示的字体字号。
         * nStunt：实时计时区域显示的特技方式。详见说明文档。
         * nRunSpeed：实时计时区域显示的运行速度。
         * nShowTime：实时计时区域显示的停留时间。单位为0.5s
         * szFileName：实时计时区域数据的文件名称。
        */
        {
            
            int nRayCount;
            nRayCount = RayTimerDictionary.Count;
            RayTimer tmpRayTimer = new RayTimer();
            
            Bitmap imgArea = new Bitmap(nAreaWidth, nAreaHeight);
            Graphics ghArea = Graphics.FromImage(imgArea);
            Brush brhArea = new SolidBrush(Color.FromArgb(0, 0, 0));
            ghArea.FillRectangle(brhArea, 0, 0, nAreaWidth, nAreaHeight);
            Font fntArea = new Font(szFontName, nFontSize, FontStyle.Regular);                                              //计算出该种字体的相关属性。
            
            Size size = TextRenderer.MeasureText(ghArea,"字体高度", fntArea);
            int nFontHeight = size.Height;                                                                                  //字体高度
           
            int nLineSpace = nAreaHeight / (nFontHeight * 4);                                                               //计算出行间距，此处以显示3行列车信息计算，行间距多一行。
            Size sizeConststr1;
            int nConststr1Length, nValueLength;
            Size sizeValue;
            
            

            if (RayTimerDictionary.ContainsKey(1))//画第一趟车
            {
                RayTimerDictionary.TryGetValue(1, out tmpRayTimer);
                ghArea.DrawString(tmpRayTimer.szConstStr1, fntArea, new SolidBrush(tmpRayTimer.clFontClr), 0, nLineSpace);
                sizeConststr1 = TextRenderer.MeasureText(ghArea, tmpRayTimer.szConstStr1, fntArea);//得到"第一趟列车在"字符串所占的尺寸
                nConststr1Length = sizeConststr1.Width;
                ghArea.DrawString(tmpRayTimer.szTimerValue, fntArea, new SolidBrush(tmpRayTimer.clValueClr), nConststr1Length, nLineSpace);
                sizeValue = TextRenderer.MeasureText(ghArea, tmpRayTimer.szTimerValue, fntArea);//得到计时信息字符串所占的尺寸
                nValueLength = sizeValue.Width;
                ghArea.DrawString(tmpRayTimer.szConstStr2, fntArea, new SolidBrush(tmpRayTimer.clFontClr), nConststr1Length+nValueLength, nLineSpace);
            }
            if (RayTimerDictionary.ContainsKey(2))//画第二趟车
            {
                RayTimerDictionary.TryGetValue(2, out tmpRayTimer);
                ghArea.DrawString(tmpRayTimer.szConstStr1, fntArea, new SolidBrush(tmpRayTimer.clFontClr), 0, nLineSpace * 2 + nFontHeight);
                sizeConststr1 = TextRenderer.MeasureText(ghArea, tmpRayTimer.szConstStr1, fntArea);
                nConststr1Length = (int)sizeConststr1.Width;
                ghArea.DrawString(tmpRayTimer.szTimerValue, fntArea, new SolidBrush(tmpRayTimer.clValueClr), nConststr1Length, nLineSpace * 2 + nFontHeight);
                sizeValue = TextRenderer.MeasureText(ghArea, tmpRayTimer.szTimerValue, fntArea);
                nValueLength = sizeValue.Width;
                ghArea.DrawString(tmpRayTimer.szConstStr2, fntArea, new SolidBrush(tmpRayTimer.clFontClr), nConststr1Length + nValueLength, nLineSpace * 2 + nFontHeight);
            }
            if (RayTimerDictionary.ContainsKey(3))//画第三趟车
            {
                RayTimerDictionary.TryGetValue(3, out tmpRayTimer);
                ghArea.DrawString(tmpRayTimer.szConstStr1, fntArea, new SolidBrush(tmpRayTimer.clFontClr), 0, nLineSpace * 3 + nFontHeight * 2);
                sizeConststr1 = TextRenderer.MeasureText(ghArea, tmpRayTimer.szConstStr1, fntArea);
                nConststr1Length = sizeConststr1.Width;
                ghArea.DrawString(tmpRayTimer.szTimerValue, fntArea, new SolidBrush(tmpRayTimer.clValueClr), nConststr1Length,nLineSpace * 3 + nFontHeight * 2);
                sizeValue = TextRenderer.MeasureText(ghArea, tmpRayTimer.szTimerValue, fntArea);
                nValueLength = sizeValue.Width;
                ghArea.DrawString(tmpRayTimer.szConstStr2, fntArea, new SolidBrush(tmpRayTimer.clFontClr), nConststr1Length+nValueLength, nLineSpace * 3 + nFontHeight * 2);
            }
            imgArea.Save(szFileName, System.Drawing.Imaging.ImageFormat.Bmp);
            ghArea.Dispose();
            fntArea.Dispose();
            brhArea.Dispose();
            imgArea.Dispose();
                     
        }

        private void button5_Click(object sender, EventArgs e)
        {
            RefReshTimerScreenData("192.168.0.235", 5005, 96, 0, 288, 48, 384, 96, 2, 2, 1, 0,10,100);
        }

  
    }
}