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
                MessageBox.Show("���ͳɹ�");
            }
            else
            {
                MessageBox.Show("����ʧ��");
            }


        }

        private void button2_Click(object sender, EventArgs e)
        {
            con.SetScreenOn(true, "SetScreenParameter");
            int getresult = con.SendTCPIPData("192.168.10.123", 5005, 852, 128, 32, 2, "SetScreenParameter");
            if (getresult == 1)
            {
                MessageBox.Show("���ͳɹ�");
            }
            else
            {
                MessageBox.Show("����ʧ��");
            }

        }

        private void button3_Click(object sender, EventArgs e)
        {
            con.SetScreenOff(false, "SetScreenParameter");
            int getresult = con.SendTCPIPData("192.168.0.235", 5005, 196, 384, 96, 2, "SetScreenParameter");
            if (getresult == 1)
            {
                MessageBox.Show("���ͳɹ�");
            }
            else
            {
                MessageBox.Show("����ʧ��");
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
                MessageBox.Show("���ͳɹ�");
            }
            else
            {
                MessageBox.Show("����ʧ��");
            }

        }

        private void button6_Click(object sender, EventArgs e)
        {
            con.ResiveCurTime("CurTime");
            int getresult = con.SendTCPIPData("192.168.0.235", 5005, 205, 384, 96, 2, "CurTime");
            if (getresult == 1)
            {
                MessageBox.Show("���ͳɹ�");
            }
            else
            {
                MessageBox.Show("����ʧ��");
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
         * szIPAddress����ʾ����IP��ַ��Ϣ
         * nPort����ʾ���ĵ�ַ��Ϣ��
         * nX��ʵʱ��ʱ����ĺ�����
         * nY��ʵʱ��ʱ�����������
         * nAreaWidth��ʵʱ��ʱ����Ŀ��
         * nAreaHeight��ʵʱ��ʱ����ĸ߶�
         * nWidth����ʾ���Ŀ��
         * nHeight����ʾ���ĸ߶�
         * nScreenType����ʾ�����ͣ�1����ɫ��2��˫��ɫ
         * nMkStyle��1��R+G��2��G+R�������ʾ����ʾ����ɫ�������ɫ���̷���ʱ��ȡ����һ��ֵ��
         * nStunt��ʵʱ��ʱ������ʾ���ؼ���ʽ�����˵���ĵ���
         * nRunSpeed��ʵʱ��ʱ������ʾ�������ٶȡ�
         * nShowTime��ʵʱ��ʱ������ʾ��ͣ��ʱ�䡣��λΪ0.5s
         * szFileName��ʵʱ��ʱ�������ݵ��ļ����ơ�
         * nReSendCount��һĻ��Ϣ�ķ��ͱ�����
        */
        {
            Dictionary<int, RayTimer> RayTimerDictionary = new Dictionary<int, RayTimer>();
            RayTimer tmpRayTimer = new RayTimer();

            //test
            text_TimerValue1.Text = "50��";
            int tmpTimerValue = 50;


            for (int j = 1; j <= nReSendCount; j++)
            {
                ///test
                if (tmpTimerValue > 1)
                    tmpTimerValue = tmpTimerValue - 1;
                else
                    tmpTimerValue = 50;
                text_TimerValue1.Text = tmpTimerValue.ToString() + "��";

                
                tmpRayTimer.szConstStr1 = "��һ���г���";
                tmpRayTimer.szConstStr2 = "����뱾վ";
                tmpRayTimer.szTimerValue = text_TimerValue1.Text;
                tmpRayTimer.clFontClr = Color.Yellow;
                tmpRayTimer.clValueClr = Color.Red;
                RayTimerDictionary.Add(1, tmpRayTimer);//ÿҳ�ĵ�һ����ʾ��һ���г���ʱ��Ϣ

                tmpRayTimer.szConstStr1 = "�ڶ����г���";
                tmpRayTimer.szConstStr2 = "����뱾վ";
                tmpRayTimer.szTimerValue = text_TimerValue2.Text;
                tmpRayTimer.clFontClr = Color.Lime;
                tmpRayTimer.clValueClr = Color.Yellow;
                RayTimerDictionary.Add(2, tmpRayTimer);//ÿҳ�ĵ�һ����ʾ��һ���г���ʱ��Ϣ

                tmpRayTimer.szConstStr1 = "�������г���";
                tmpRayTimer.szConstStr2 = "����뱾վ";
                tmpRayTimer.szTimerValue = text_TimerValue3.Text;
                tmpRayTimer.clFontClr = Color.Lime;
                tmpRayTimer.clValueClr = Color.Yellow;
                RayTimerDictionary.Add(3, tmpRayTimer);//ÿҳ�ĵ�һ����ʾ��һ���г���ʱ��Ϣ
                //���沢��ת����һĻ��ʱ����
                RefReshTimerAreaPic(nX, nY, nAreaWidth, nAreaHeight, nScreenType, nMkStyle, RayTimerDictionary,"����",
                    12, nStunt, nRunSpeed, nShowTime, szIPAddress + "_1.bmp");
                con.TranDynamicData(0, nX, nY, nAreaWidth, nAreaHeight, nScreenType, nMkStyle, 1, nStunt, nRunSpeed,
                    nShowTime, szIPAddress + "_1.bmp",0, szIPAddress, true);
                con.SendTCPIPData(szIPAddress, nPort, 210, nWidth, nHeight, nScreenType, szIPAddress);
                //�˴��������ʱ��
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
                text_TimerValue1.Text = tmpTimerValue.ToString() + "��";

                
                tmpRayTimer.szConstStr1 = "��һ���г���";
                tmpRayTimer.szConstStr2 = "����뱾վ";
                tmpRayTimer.szTimerValue = text_TimerValue1.Text;
                tmpRayTimer.clFontClr = Color.Yellow;
                tmpRayTimer.clValueClr = Color.Red;
                RayTimerDictionary.Add(1, tmpRayTimer);//ÿҳ�ĵ�һ����ʾ��һ���г���ʱ��Ϣ

                tmpRayTimer.szConstStr1 = "�������г���";
                tmpRayTimer.szConstStr2 = "����뱾վ";
                tmpRayTimer.szTimerValue = text_TimerValue4.Text;
                tmpRayTimer.clFontClr = Color.Lime;
                tmpRayTimer.clValueClr = Color.Yellow;
                RayTimerDictionary.Add(2, tmpRayTimer);//ÿҳ�ĵ�һ����ʾ��һ���г���ʱ��Ϣ

                tmpRayTimer.szConstStr1 = "�������г���";
                tmpRayTimer.szConstStr2 = "����뱾վ";
                tmpRayTimer.szTimerValue = text_TimerValue5.Text;
                tmpRayTimer.clFontClr = Color.Lime;
                tmpRayTimer.clValueClr = Color.Yellow;
                RayTimerDictionary.Add(3, tmpRayTimer);//ÿҳ�ĵ�һ����ʾ��һ���г���ʱ��Ϣ
                //���沢��ת���ڶ�Ļ��ʱ����
                RefReshTimerAreaPic(nX, nY, nAreaWidth, nAreaHeight, nScreenType, nMkStyle, RayTimerDictionary, "����",
                    12, nStunt, nRunSpeed, nShowTime, szIPAddress + "_2.bmp");
                con.TranDynamicData(0, nX, nY, nAreaWidth, nAreaHeight, nScreenType, nMkStyle, 1, nStunt, nRunSpeed, 
                    nShowTime, szIPAddress + "_2.bmp",0, szIPAddress,true);
                con.SendTCPIPData(szIPAddress, nPort, 210, nWidth, nHeight, nScreenType, szIPAddress );
                //�˴��������ʱ��
               // Timer_Ticket(500);
                RayTimerDictionary.Clear();
            }
            for (int j = 1; j <= nReSendCount; j++)//ҳ�ڼ�¼ѭ��
            {
                ///test
                if (tmpTimerValue > 1)
                    tmpTimerValue = tmpTimerValue - 1;
                else
                    tmpTimerValue = 50;
                text_TimerValue1.Text = tmpTimerValue.ToString() + "��";


                tmpRayTimer.szConstStr1 = "��һ���г���";
                tmpRayTimer.szConstStr2 = "����뱾վ";
                tmpRayTimer.szTimerValue = text_TimerValue1.Text;
                tmpRayTimer.clFontClr = Color.Yellow;
                tmpRayTimer.clValueClr = Color.Red;
                RayTimerDictionary.Add(1, tmpRayTimer);//ÿҳ�ĵ�һ����ʾ��һ���г���ʱ��Ϣ

                tmpRayTimer.szConstStr1 = "�������г���";
                tmpRayTimer.szConstStr2 = "����뱾վ";
                tmpRayTimer.szTimerValue = text_TimerValue6.Text;
                tmpRayTimer.clFontClr = Color.Lime;
                tmpRayTimer.clValueClr = Color.Yellow;
                RayTimerDictionary.Add(2, tmpRayTimer);//ÿҳ�ĵ�һ����ʾ��һ���г���ʱ��Ϣ
                //���沢��ת������Ļ��ʱ����
                RefReshTimerAreaPic(nX, nY, nAreaWidth, nAreaHeight, nScreenType, nMkStyle, RayTimerDictionary, "����",
                    12, nStunt, nRunSpeed, nShowTime, szIPAddress + "_3.bmp");
                con.TranDynamicData(0, nX, nY, nAreaWidth, nAreaHeight, nScreenType, nMkStyle, 1, nStunt, nRunSpeed,
                    nShowTime, szIPAddress + "_3.bmp",0, szIPAddress, true);
                con.SendTCPIPData(szIPAddress, nPort, 210, nWidth, nHeight, nScreenType, szIPAddress);
                //�˴��������ʱ��
               // Timer_Ticket(500);
                RayTimerDictionary.Clear();
                
                }
                
        }

        private void RefReshTimerAreaPic(int nX,int nY,int nAreaWidth,int nAreaHeight,int nScreenType,int nMkStyle,
            Dictionary<int, RayTimer> RayTimerDictionary,string szFontName,int nFontSize,int nStunt,int nRunSpeed,
            int nShowTime,string szFileName)
        /*
         * nX��ʵʱ��ʱ����ĺ�����
         * nY��ʵʱ��ʱ�����������
         * nAreaWidth��ʵʱ��ʱ����Ŀ��
         * nAreaHeight��ʵʱ��ʱ����ĸ߶�
         * nScreenType����ʾ�����ͣ�1����ɫ��2��˫��ɫ
         * nMkStyle��1��R+G��2��G+R�������ʾ����ʾ����ɫ�������ɫ���̷���ʱ��ȡ����һ��ֵ��
         * RayTimerDictionary���г���Ϣ�ṹ�塣
         * szFontName��ʵʱ��ʱ������ʾ���������ơ�
         * nFontSize��ʵʱ��ʱ������ʾ�������ֺš�
         * nStunt��ʵʱ��ʱ������ʾ���ؼ���ʽ�����˵���ĵ���
         * nRunSpeed��ʵʱ��ʱ������ʾ�������ٶȡ�
         * nShowTime��ʵʱ��ʱ������ʾ��ͣ��ʱ�䡣��λΪ0.5s
         * szFileName��ʵʱ��ʱ�������ݵ��ļ����ơ�
        */
        {
            
            int nRayCount;
            nRayCount = RayTimerDictionary.Count;
            RayTimer tmpRayTimer = new RayTimer();
            
            Bitmap imgArea = new Bitmap(nAreaWidth, nAreaHeight);
            Graphics ghArea = Graphics.FromImage(imgArea);
            Brush brhArea = new SolidBrush(Color.FromArgb(0, 0, 0));
            ghArea.FillRectangle(brhArea, 0, 0, nAreaWidth, nAreaHeight);
            Font fntArea = new Font(szFontName, nFontSize, FontStyle.Regular);                                              //��������������������ԡ�
            
            Size size = TextRenderer.MeasureText(ghArea,"����߶�", fntArea);
            int nFontHeight = size.Height;                                                                                  //����߶�
           
            int nLineSpace = nAreaHeight / (nFontHeight * 4);                                                               //������м�࣬�˴�����ʾ3���г���Ϣ���㣬�м���һ�С�
            Size sizeConststr1;
            int nConststr1Length, nValueLength;
            Size sizeValue;
            
            

            if (RayTimerDictionary.ContainsKey(1))//����һ�˳�
            {
                RayTimerDictionary.TryGetValue(1, out tmpRayTimer);
                ghArea.DrawString(tmpRayTimer.szConstStr1, fntArea, new SolidBrush(tmpRayTimer.clFontClr), 0, nLineSpace);
                sizeConststr1 = TextRenderer.MeasureText(ghArea, tmpRayTimer.szConstStr1, fntArea);//�õ�"��һ���г���"�ַ�����ռ�ĳߴ�
                nConststr1Length = sizeConststr1.Width;
                ghArea.DrawString(tmpRayTimer.szTimerValue, fntArea, new SolidBrush(tmpRayTimer.clValueClr), nConststr1Length, nLineSpace);
                sizeValue = TextRenderer.MeasureText(ghArea, tmpRayTimer.szTimerValue, fntArea);//�õ���ʱ��Ϣ�ַ�����ռ�ĳߴ�
                nValueLength = sizeValue.Width;
                ghArea.DrawString(tmpRayTimer.szConstStr2, fntArea, new SolidBrush(tmpRayTimer.clFontClr), nConststr1Length+nValueLength, nLineSpace);
            }
            if (RayTimerDictionary.ContainsKey(2))//���ڶ��˳�
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
            if (RayTimerDictionary.ContainsKey(3))//�������˳�
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