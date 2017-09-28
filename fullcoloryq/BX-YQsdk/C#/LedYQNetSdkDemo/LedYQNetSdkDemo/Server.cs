using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
//using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Runtime.InteropServices;
using LedYQServerAPI;

namespace LedYQNetSdkDemo
{
    public partial class Server : Form
    {
        public Server()
        {
            InitializeComponent();
            if (server_ftp.m_bServerRun == false)
            {
                button1.Enabled = true;
                button2.Enabled = false;
                button3.Enabled = false;
            }
            else
            {
                button1.Enabled = false;
                button2.Enabled = true;
                button3.Enabled = true;
            }
        }

        private void button1_Click(object sender, EventArgs e)//启动服务器
        {
            ushort port = ushort.Parse(textBox1.Text);
            int err = LedYQserver.Server_Start(port);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            else 
            {
                button1.Enabled = false;
                button2.Enabled = true;
                button3.Enabled = true;
                server_ftp.m_bServerRun = true;
            }
        }

        private void button2_Click(object sender, EventArgs e)//关闭服务器
        {
            LedYQserver.Server_Close();
            button1.Enabled = true;
            button2.Enabled = false;
            button3.Enabled = false;
            server_ftp.m_bServerRun = false;

            button5.Enabled = false;
            button6.Enabled = false;
            button7.Enabled = false;
            button8.Enabled = false;
            button9.Enabled = false;
            button10.Enabled = false;
            button11.Enabled = false;
            button12.Enabled = false;
            button13.Enabled = false;
        }

        int m_ClientCount;
        LedYQserver.server_card[] m_ClientList = new LedYQserver.server_card[20];
        private void button3_Click(object sender, EventArgs e)//搜索
        {
            comboBox1.SelectedIndex = -1;
            //IntPtr intptr = Marshal.AllocHGlobal(4096);
            //m_ClientCount = LedYQserver.Server_GetCardList(intptr);
            //Marshal.PtrToStructure(intptr, typeof(LedYQserver.server_card)); //将指针intptr指向结构体
            //m_ClientList = (LedYQserver.server_card)Marshal.PtrToStructure(intptr, typeof(LedYQserver.server_card));
            //Marshal.FreeHGlobal(intptr);//释放分配的非托管内存。

            byte[] str = new byte[48 * 100];
            m_ClientCount = LedYQserver.Server_GetCardList(str);
            for (int i = 0; i < m_ClientCount; i++)
            {
                byte[] pid = new byte[16];
                byte[] barcode = new byte[16];
                byte[] ip = new byte[16];
                Array.Copy(str, i * 32, pid, 0, 16);
                Array.Copy(str, i * 32 + 16, barcode, 0, 16);
                m_ClientList[i].PID = pid;
                int t = 0;
                while (barcode[t] == 0)
                {
                    if (t == 15)
                    {
                        barcode = System.BitConverter.GetBytes(i + 1);
                        break;
                    }
                    t++;
                }
                m_ClientList[i].barcode = barcode;
                comboBox1.Items.Add(m_ClientList[i].barcode.ToString());
            }

            if (m_ClientCount > 0)
            {
                comboBox1.SelectedIndex = 0;
                button5.Enabled = true;
                button6.Enabled = true;
                button7.Enabled = true;
                button8.Enabled = true;
                button9.Enabled = true;
                button10.Enabled = true;
                button11.Enabled = true;
                button12.Enabled = true;
                button13.Enabled = true;
            }
            else
            {
                button5.Enabled = false;
                button6.Enabled = false;
                button7.Enabled = false;
                button8.Enabled = false;
                button9.Enabled = false;
                button10.Enabled = false;
                button11.Enabled = false;
                button12.Enabled = false;
                button13.Enabled = false;
            }
        }

        private void button4_Click(object sender, EventArgs e)//保存参数
        {
            server_ftp.ftp_server_ip = textBox2.Text.ToCharArray();
            server_ftp.ftp_server_port = short.Parse(textBox3.Text);
            server_ftp.ftp_server_user = textBox4.Text.ToCharArray();
            server_ftp.ftp_server_pwd = textBox5.Text.ToCharArray();
            //server_ftp.ftp_server_ip = System.Text.Encoding.Unicode.GetBytes(textBox2.Text);
            //server_ftp.ftp_server_port = short.Parse(textBox3.Text);
            //server_ftp.ftp_server_user = System.Text.Encoding.Unicode.GetBytes(textBox4.Text);
            //server_ftp.ftp_server_pwd = System.Text.Encoding.Unicode.GetBytes(textBox5.Text);
        }

        private void button5_Click(object sender, EventArgs e)//屏参
        {
            ScreenProperty pSP = new ScreenProperty(m_ClientList[comboBox1.SelectedIndex].PID);
            pSP.ShowDialog();
        }

        private void button6_Click(object sender, EventArgs e)//网络
        {
            Net pN = new Net(m_ClientList[comboBox1.SelectedIndex].PID);
            pN.ShowDialog();
        }

        private void button7_Click(object sender, EventArgs e)//开关机
        {
            OnOff pOO = new OnOff(m_ClientList[comboBox1.SelectedIndex].PID);
            pOO.ShowDialog();
        }

        private void button8_Click(object sender, EventArgs e)//固件
        {
            FirmWarea pFW = new FirmWarea(m_ClientList[comboBox1.SelectedIndex].PID);
            pFW.ShowDialog();
        }

        private void button9_Click(object sender, EventArgs e)//校时
        {
            int err = LedYQserver.Server_TimeCorrect(m_ClientList[comboBox1.SelectedIndex].PID);
            if (err == 0)
            {
                MessageBox.Show("校时成功!");
            }
            else if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
        }

        private void button10_Click(object sender, EventArgs e)//音量
        {
            Volume pV = new Volume(m_ClientList[comboBox1.SelectedIndex].PID);
            pV.ShowDialog();
        }

        private void button11_Click(object sender, EventArgs e)//亮度
        {
            Bright pB = new Bright(m_ClientList[comboBox1.SelectedIndex].PID);
            pB.ShowDialog();
        }

        private void button12_Click(object sender, EventArgs e)//节目
        {
            PlayList pPL = new PlayList(m_ClientList[comboBox1.SelectedIndex].PID);
            pPL.ShowDialog();
        }

        private void button13_Click(object sender, EventArgs e)//动态区
        {
            DynamicArea pDA = new DynamicArea(m_ClientList[comboBox1.SelectedIndex].PID);
            pDA.ShowDialog();
        }
    }
}
