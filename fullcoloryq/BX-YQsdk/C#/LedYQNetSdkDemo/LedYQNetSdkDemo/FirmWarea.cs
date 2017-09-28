using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
//using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Collections;

namespace LedYQNetSdkDemo
{
    public partial class FirmWarea : Form
    {
        int card_mode;
        string ip;
        byte[] PID;
        byte[] FirmwareTime = new byte[50];
        byte[] FirmwarelVersion = new byte[50];
        public FirmWarea(string ip)
        {
            card_mode = 0;
            this.ip = ip;
            int err = LedYQNetSDKAPI.LedYQNetSdk.Net_GetFirmwareinfo(ip, FirmwareTime, FirmwarelVersion);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            InitializeComponent();
            textBox1.Text = System.Text.Encoding.Default.GetString(FirmwarelVersion);
            textBox2.Text = System.Text.Encoding.Default.GetString(FirmwareTime);
        }
        public FirmWarea(byte[] pid)
        {
            card_mode = 1;
            PID = pid;
            int err = LedYQServerAPI.LedYQserver.Server_GetFirmwareinfo(PID, FirmwareTime, FirmwarelVersion);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            InitializeComponent();
            textBox1.Text = System.Text.Encoding.Default.GetString(FirmwarelVersion);
            textBox2.Text = System.Text.Encoding.Default.GetString(FirmwareTime);
        }


        public void UpdateFileStruct (char[] Da)
        {
            char[] backup = new char[16]; //!< 备用字
            char[] md5 = new char[32];    //!< md5校验值
	        char[] fileName = new char[64]; //!< 被校验的文件名
	        char[] updateVersion = new char[64]; //!< 升级包版本号
	        char[] appVerison = new char[64]; //!< 固件版本号
	        char[] controllerType = new char[64]; //!< 控制器型号
            char[] createdTime = new char[64]; //!< 升级包生成时间

            Array.Copy(Da, 0, backup, 0, 16);
            Array.Copy(Da, 16, md5, 0, 32);
            Array.Copy(Da, 48, fileName, 0, 64);
            Array.Copy(Da, 112, updateVersion, 0, 64);
            Array.Copy(Da, 176, appVerison, 0, 64);
            Array.Copy(Da, 240, controllerType, 0, 64);
            Array.Copy(Da, 304, createdTime, 0, 64);

            textBox6.Text = new string(createdTime);
            textBox7.Text = new string(updateVersion);
            string but5 = new string(controllerType);
            switch (int.Parse(but5)) 
            {
                case 344:
                    textBox5.Text = "YQ1_75";
                    break;
                case 600:
                    textBox5.Text = "YQ1";
                    break;
                case 856:
                    textBox5.Text = "YQ2";
                    break;
                case 1112:
                    textBox5.Text = "YQ3";
                    break;
                case 1368:
                    textBox5.Text = "YQ4";
                    break;
                case 1624:
                    textBox5.Text = "YQ2E";
                    break;
                default:
                    textBox5.Text = "YQ5";
                    break;
            }
        }
        private void button1_Click(object sender, EventArgs e)//打开固件摘要
        {
            OpenFileDialog fileDialog = new OpenFileDialog();
            fileDialog.Multiselect = true;
            fileDialog.Title = "请选择文件";
            fileDialog.Filter = "(*.tar.gz.md5)|*.tar.gz.md5";
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                textBox3.Text = fileDialog.FileName;
                FileStream fs = File.OpenRead(textBox3.Text);
                byte[] data = new byte[fs.Length]; 
                fs.Read(data, 0, data.Length);
                char[] ar = Encoding.ASCII.GetChars(data);
                UpdateFileStruct(ar);
            }
        }

        private void button3_Click(object sender, EventArgs e)//升级
        {
            byte[] strMd5File = System.Text.Encoding.Default.GetBytes(textBox3.Text);
            byte[] strUpdateFile = System.Text.Encoding.Default.GetBytes(textBox4.Text);
            if (card_mode == 0)
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_Update(ip, strMd5File, strUpdateFile);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
            else
            {
                int err = LedYQServerAPI.LedYQserver.Server_Update(PID, strMd5File, strUpdateFile, server_ftp.ftp_server_ip,
                        server_ftp.ftp_server_port, server_ftp.ftp_server_pwd, server_ftp.ftp_server_user);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            OpenFileDialog fileDialog = new OpenFileDialog();
            fileDialog.Multiselect = true;
            fileDialog.Title = "请选择文件";
            fileDialog.Filter = "*.tar.gz|*.tar.gz";
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                textBox4.Text = fileDialog.FileName;
            }
        }
    }
}
