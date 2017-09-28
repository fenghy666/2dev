using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.IO;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using LedYQNetSDKAPI;

namespace LedYQNetSdkDemo
{
    public partial class Client : Form
    {
        public Client()
        {
            InitializeComponent();
        }

        int m_ClientCount;
        LedYQNetSdk.card_unit[] ClientList = new LedYQNetSdk.card_unit[20];
        private void button1_Click(object sender, EventArgs e)//搜索
        {
            comboBox1.SelectedIndex = -1;
            //IntPtr intptr = Marshal.AllocHGlobal(4096);
            //m_ClientCount = LedYQNetSdk.Net_SearchCards(intptr, 1);
            //Marshal.PtrToStructure(intptr, typeof(LedYQNetSdk.card_unit1)); //将指针intptr指向结构体
            //m_ClientList = (LedYQNetSdk.card_unit1)Marshal.PtrToStructure(intptr, typeof(LedYQNetSdk.card_unit1));
            //Marshal.FreeHGlobal(intptr);//释放分配的非托管内存。

            byte[] str = new byte[48 * 100];
            m_ClientCount = LedYQNetSdk.Net_SearchCards(str, 1);
            for (int i = 0; i < m_ClientCount;i++ ) 
            {
                byte[] pid = new byte[16];
                byte[] barcode = new byte[16];
                byte[] ip = new byte[16];
                Array.Copy(str, i * 48, pid, 0, 16);
                Array.Copy(str, i * 48 + 16, barcode, 0, 16);
                Array.Copy(str, 32 + i * 48, ip, 0, 16);
                ClientList[i].aPID = System.Text.Encoding.ASCII.GetString(barcode);
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
                ClientList[i].barcode = System.Text.Encoding.ASCII.GetString(pid);
                ClientList[i].ip = System.Text.Encoding.ASCII.GetString(ip);
                comboBox1.Items.Add(ClientList[i].barcode);
            }

            if (m_ClientCount > 0)
            {
                comboBox1.SelectedIndex = 0;
                comboBox1_SelectedIndexChanged(null,null);
                button2.Enabled = true;
                button3.Enabled = true;
                button4.Enabled = true;
                button5.Enabled = true;
                button6.Enabled = true;
                button7.Enabled = true;
                button8.Enabled = true;
                button9.Enabled = true;
                button10.Enabled = true;
                button11.Enabled = true;
                button12.Enabled = true;
            }
            else
            {
                button2.Enabled = false;
                button3.Enabled = false;
                button4.Enabled = false;
                button5.Enabled = false;
                button6.Enabled = false;
                button7.Enabled = false;
                button8.Enabled = false;
                button9.Enabled = false;
                button10.Enabled = false;
                button11.Enabled = false;
                button12.Enabled = false;
            }
        }

        private void button2_Click(object sender, EventArgs e)//屏参
        {
            ScreenProperty pSP = new ScreenProperty(textBox1.Text);
            pSP.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)//网络
        {
            Net pN = new Net(ClientList[comboBox1.SelectedIndex]);
            pN.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e)//开关机
        {
            OnOff pOO = new OnOff(ClientList[comboBox1.SelectedIndex].ip);
            pOO.ShowDialog();
        }

        private void button5_Click(object sender, EventArgs e)//固件
        {
            FirmWarea pFW = new FirmWarea(ClientList[comboBox1.SelectedIndex].ip);
            pFW.ShowDialog();
        }

        private void button6_Click(object sender, EventArgs e)//校时
        {
            int err = LedYQNetSdk.Net_TimeCorrect(textBox1.Text);
            if (err == 0)
            {
                MessageBox.Show("校时成功!");
            }else if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
        }

        private void button7_Click(object sender, EventArgs e)//音量
        {
            Volume pV = new Volume(ClientList[comboBox1.SelectedIndex].ip);
            pV.ShowDialog();
        }

        private void button8_Click(object sender, EventArgs e)//亮度
        {
            Bright pB = new Bright(ClientList[comboBox1.SelectedIndex].ip);
            pB.ShowDialog();
        }

        private void button9_Click(object sender, EventArgs e)//节目
        {
            PlayList pPL = new PlayList(ClientList[comboBox1.SelectedIndex].ip);
            pPL.ShowDialog();
        }

        private void button10_Click(object sender, EventArgs e)//动态区
        {
            DynamicArea pDA = new DynamicArea(ClientList[comboBox1.SelectedIndex].ip);
            pDA.ShowDialog();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            int index = comboBox1.SelectedIndex;
            if (index != -1) 
            {
                textBox1.Text = ClientList[index].ip;
            }
        }

        private void button12_Click(object sender, EventArgs e)
        {
            int program_id = int.Parse(textBox5.Text);
            byte SaveLock = 1;
            if (checkBox1.Checked == true)
            {
                SaveLock = 1;
            }
            else { SaveLock = 0; }
            int err = LedYQNetSdk.Net_LockProgram(textBox1.Text, program_id, SaveLock);
            if (err == 0)
            {
                MessageBox.Show("锁定成功!");
            }
            else if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
        }

        private void button11_Click(object sender, EventArgs e)
        {
            int err = LedYQNetSdk.Net_UnLockProgram(textBox1.Text);
            if (err == 0)
            {
                MessageBox.Show("解锁成功!");
            }
            else if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
