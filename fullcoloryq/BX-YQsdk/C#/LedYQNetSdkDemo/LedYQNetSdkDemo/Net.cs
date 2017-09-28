using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace LedYQNetSdkDemo
{
    public partial class Net : Form
    {
        //int card_mode;
        byte[] PID;
        byte[] ip;
        string pid;
        LedYQNetSDKAPI.LedYQNetSdk.card_unit Unit;
        public Net(LedYQNetSDKAPI.LedYQNetSdk.card_unit pUnit)
        {
            //card_mode = 0;
            Unit = pUnit;
            ip = System.Text.Encoding.ASCII.GetBytes(Unit.ip);
            pid = Unit.aPID;
            byte[] netip = new byte[16];
            byte[] mask = new byte[16];
            byte[] gate = new byte[16];
            byte[] serverip = new byte[16];
            System.Byte ipmode = 0;
            InitializeComponent();
            textBox5.Text = "6005";
	        ushort port=0;
            radioButton3.Checked = true;
            string str = System.Text.Encoding.ASCII.GetString(ip);
            int err = LedYQNetSDKAPI.LedYQNetSdk.Net_GetNetinfo(str, pid, netip, mask, gate, ref ipmode);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            else 
            {
                textBox1.Text = System.Text.Encoding.ASCII.GetString(netip);
                textBox2.Text = System.Text.Encoding.ASCII.GetString(mask);
                textBox3.Text = System.Text.Encoding.ASCII.GetString(gate);
                if(ipmode == 0)
                {
                    radioButton1.Checked = true;
                    textBox1.Enabled = false;
                    textBox2.Enabled = false;
                    textBox3.Enabled = false;
                }else if(ipmode == 1)
                {
                    radioButton2.Checked = true;
                    textBox1.Enabled = true;
                    textBox2.Enabled = true;
                    textBox3.Enabled = true;
                }
            }
            byte mode = 0;
            err = LedYQNetSDKAPI.LedYQNetSdk.Net_GetModeinfo(ip,ref mode, serverip,ref port);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            else
            {
                if (mode == 1)
                {
                    radioButton4.Checked = true;
                    textBox4.Text = System.Text.Encoding.ASCII.GetString(serverip);
                    textBox5.Text = port.ToString();
                }
                else
                {
                    radioButton3.Checked = true;
                }
            }
        }
        public Net(byte[] id)
        {
            //card_mode = 1;
            PID = id;
            byte[] Pid = new byte[16];
            byte[] IP = new byte[16];
            byte[] mask = new byte[16];
            byte[] gate = new byte[16];
            byte[] serverip = new byte[16];
            System.Byte ipmode = 0;
            InitializeComponent();
            textBox5.Text = "6005";
            ushort port = 0;
            radioButton3.Checked = true;
            int err = LedYQServerAPI.LedYQserver.Server_GetNetinfo(PID, Pid, IP, mask, gate, ref ipmode);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            else
            {
                textBox1.Text = System.Text.Encoding.ASCII.GetString(IP);
                textBox2.Text = System.Text.Encoding.ASCII.GetString(mask);
                textBox3.Text = System.Text.Encoding.ASCII.GetString(gate);
                if (ipmode == 0)
                {
                    radioButton1.Checked = true;
                    textBox1.Enabled = false;
                    textBox2.Enabled = false;
                    textBox3.Enabled = false;
                }
                else if (ipmode == 1)
                {
                    radioButton2.Checked = true;
                    textBox1.Enabled = true;
                    textBox2.Enabled = true;
                    textBox3.Enabled = true;
                }
            }
            err = LedYQServerAPI.LedYQserver.Server_GetModeinfo(PID, serverip, ref port);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            else
            {
                radioButton4.Checked = true;
                textBox4.Text = System.Text.Encoding.ASCII.GetString(serverip);
                textBox5.Text = port.ToString();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            byte[] IP = System.Text.Encoding.ASCII.GetBytes(textBox1.Text);
            byte[] mask = System.Text.Encoding.ASCII.GetBytes(textBox2.Text);
            byte[] gate = System.Text.Encoding.ASCII.GetBytes(textBox3.Text);
            if (radioButton1.Checked == true) 
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_SetAutoip(pid);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
                else 
                {
                    byte[] IPx = new byte[16];
                    byte[] maskx = new byte[16];
                    byte[] gatex = new byte[16];
			        byte ipmodex = 0;
                    byte[] pidx = new byte[16];
			        err = LedYQNetSDKAPI.LedYQNetSdk.Net_GetIp(pid,IPx);
			        if (err != 0)
			        {
				        LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
			        }
			        err = LedYQNetSDKAPI.LedYQNetSdk.Net_GetNetinfo(IPx.ToString(),pid.ToString(),ip,maskx,gatex,ref ipmodex);
			        Unit.ip = System.Text.Encoding.ASCII.GetString(IPx);
			        if (err==0)
			        {
                        textBox1.Text = System.Text.Encoding.ASCII.GetString(IP);
                        textBox2.Text = System.Text.Encoding.ASCII.GetString(mask);
                        textBox3.Text = System.Text.Encoding.ASCII.GetString(gate);
                        if (ipmodex == 0)
                        {
                            radioButton1.Checked = true;
                            textBox1.Enabled = false;
                            textBox2.Enabled = false;
                            textBox3.Enabled = false;
                        }
                        else if (ipmodex == 1)
                        {
                            radioButton2.Checked = true;
                            textBox1.Enabled = true;
                            textBox2.Enabled = true;
                            textBox3.Enabled = true;
                        }
			        }
		        }
            }
            else if (radioButton2.Checked == true)
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_SetStaticip(pid, IP, mask, gate);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
                else
                {
                    Unit.ip = System.Text.Encoding.ASCII.GetString(IP);
                }
            }
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton1.Checked == true)
            {
                textBox1.Enabled = false;
                textBox2.Enabled = false;
                textBox3.Enabled = false;
            }
        }

        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton2.Checked == true)
            {
                textBox1.Enabled = true;
                textBox2.Enabled = true;
                textBox3.Enabled = true;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (radioButton3.Checked == true) 
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_SetClientMode(ip);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
                else { MessageBox.Show("设置成功！"); }
            }
            if (radioButton4.Checked == true)
            {
                byte[] IP = System.Text.Encoding.ASCII.GetBytes(textBox4.Text);
                ushort port = ushort.Parse(textBox5.Text);
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_SetServerMode(ip, IP, port);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
                else { MessageBox.Show("设置成功！"); }
            }
        }
    }
}