using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
//using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace LedYQNetSdkDemo
{
    public partial class OnOff : Form
    {
        int card_mode;
        byte[] PID;
        string ip;
        public OnOff(string ip)
        {
            card_mode = 0;
            this.ip = ip;
            InitializeComponent();
            System.Byte OnOff = 0;
            int err = LedYQNetSDKAPI.LedYQNetSdk.Net_GetOnoff(ip,ref OnOff);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            switch (OnOff) 
            {
                case 0:
                    radioButton2.Checked = true;
                    break;
                case 1:
                    radioButton1.Checked = true;
                    break;
                case 2:
                    radioButton4.Checked = true;
                    break;
                case 3:
                    radioButton3.Checked = true;
                    break;
            }
        }
        public OnOff(byte[] pid)
        {
            card_mode = 1;
            PID = pid;
            InitializeComponent();
            System.Byte OnOff = 0;
            int err = LedYQServerAPI.LedYQserver.Server_GetOnoff(PID, ref OnOff);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            switch (OnOff)
            {
                case 0:
                    radioButton2.Checked = true;
                    break;
                case 1:
                    radioButton1.Checked = true;
                    break;
                case 2:
                    radioButton4.Checked = true;
                    break;
                case 3:
                    radioButton3.Checked = true;
                    break;
            }
        }

        private void button1_Click(object sender, EventArgs e)//定时
        {
            string OnTm1 = "";
            string OffTm1 = ""; 
            string OnTm2 = "";
            string OffTm2 = "";
            string OnTm3 = "";
            string OffTm3 = "";
            string OnTm4 = "";
            string OffTm4 = "";
            if (checkBox1.Checked == true)
            {
                DateTime date = DateTime.Parse(dateTimePicker1.Text);
                OnTm1 = date.TimeOfDay.ToString();
                date = DateTime.Parse(dateTimePicker2.Text);
                OffTm1 = date.TimeOfDay.ToString();
            }
            if (checkBox2.Checked == true)
            {
                DateTime date = DateTime.Parse(dateTimePicker3.Text);
                OnTm2 = date.TimeOfDay.ToString();
                date = DateTime.Parse(dateTimePicker4.Text);
                OffTm2 = date.TimeOfDay.ToString();
            }
            if (checkBox3.Checked == true)
            {
                DateTime date = DateTime.Parse(dateTimePicker5.Text);
                OnTm3 = date.TimeOfDay.ToString();
                date = DateTime.Parse(dateTimePicker6.Text);
                OffTm3 = date.TimeOfDay.ToString();
            }
            if (checkBox4.Checked == true)
            {
                DateTime date = DateTime.Parse(dateTimePicker7.Text);
                OnTm4 = date.TimeOfDay.ToString();
                date = DateTime.Parse(dateTimePicker8.Text);
                OffTm4 = date.TimeOfDay.ToString();
            }
            if (card_mode == 0)
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_SwitchOnTime(ip, OnTm1, OffTm1, OnTm2, OffTm2, OnTm3, OffTm3, OnTm4, OffTm4);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }else if(card_mode == 1)
            {
                int err = LedYQServerAPI.LedYQserver.Server_SwitchOnTime(PID, OnTm1, OffTm1, OnTm2, OffTm2, OnTm3, OffTm3, OnTm4, OffTm4,
                        server_ftp.ftp_server_ip, server_ftp.ftp_server_port, server_ftp.ftp_server_pwd, server_ftp.ftp_server_user);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)//开屏
        {
            if (card_mode == 0)
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_OpenScreen(ip);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
            else if (card_mode == 1)
            {
                int err = LedYQServerAPI.LedYQserver.Server_OpenScreen(PID);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)//关屏
        {
            if (card_mode == 0)
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_CloseScreen(ip);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
            else 
            {
                int err = LedYQServerAPI.LedYQserver.Server_CloseScreen(PID);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)//时段1
        {
            if (checkBox1.Checked == true)
            {
                dateTimePicker1.Enabled = true;
                dateTimePicker2.Enabled = true;
            }
            else 
            {
                dateTimePicker1.Enabled = false;
                dateTimePicker2.Enabled = false;
            }
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)//时段2
        {
            if (checkBox2.Checked == true)
            {
                dateTimePicker3.Enabled = true;
                dateTimePicker4.Enabled = true;
            }
            else
            {
                dateTimePicker3.Enabled = false;
                dateTimePicker4.Enabled = false;
            }
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)//时段3
        {
            if (checkBox3.Checked == true)
            {
                dateTimePicker5.Enabled = true;
                dateTimePicker6.Enabled = true;
            }
            else
            {
                dateTimePicker5.Enabled = false;
                dateTimePicker6.Enabled = false;
            }
        }

        private void checkBox4_CheckedChanged(object sender, EventArgs e)//时段4
        {
            if (checkBox4.Checked == true)
            {
                dateTimePicker7.Enabled = true;
                dateTimePicker8.Enabled = true;
            }
            else
            {
                dateTimePicker7.Enabled = false;
                dateTimePicker8.Enabled = false;
            }
        }
    }
}
