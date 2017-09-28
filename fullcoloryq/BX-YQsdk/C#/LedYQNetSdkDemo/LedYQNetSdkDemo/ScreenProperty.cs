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
    public partial class ScreenProperty : Form
    {
        int card_mode; 
        string card_ip;
        byte[] PID;
        short w = 0;
        short h = 0;
        ushort type = 0;
        public ScreenProperty(string ip)
        {
            card_mode = 0;
            card_ip = ip;
            ushort[] card_type_list = new ushort[8];
            card_type_list[0] = 0x0158;//BX-YQ1-75
            card_type_list[1] = 0x0258;//BX-YQ1
            card_type_list[2] = 0x0358;//BX-YQ2
            card_type_list[3] = 0x0458;//BX-YQ3
            card_type_list[4] = 0x0558;//BX-YQ4
            card_type_list[5] = 0x0658;//BX-YQ2E
            card_type_list[6] = 0x0758;//BX-YQ5E
            card_type_list[7] = 0xF58;//BX-YQ2A
            InitializeComponent();

            int err = LedYQNetSDKAPI.LedYQNetSdk.Net_GetScreeninfo(card_ip,ref type, ref w, ref h);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            else
            {
                short str = w;
                width.Text = Convert.ToString(str);

                str = h;
                height.Text = Convert.ToString(str);

                int i = Convert.ToInt32(type);
                switch (i)
                {
                    case 344:
                        comboBox1.SelectedIndex = 0;
                        break;
                    case 600:
                        comboBox1.SelectedIndex = 1;
                        break;
                    case 856:
                        comboBox1.SelectedIndex = 2;
                        break;
                    case 1112:
                        comboBox1.SelectedIndex = 3;
                        break;
                    case 1368:
                        comboBox1.SelectedIndex = 4;
                        break;
                    case 1624:
                        comboBox1.SelectedIndex = 5;
                        break;
                    case 1880:
                        comboBox1.SelectedIndex = 6;
                        break;
                    default:
                        comboBox1.SelectedIndex = 7;
                        break;
                }
            }
        }
        public ScreenProperty(byte[] pid)
        {
            card_mode = 1;
            PID = pid;
            InitializeComponent();

            int err = LedYQServerAPI.LedYQserver.Server_GetScreeninfo(PID, ref type, ref w, ref h);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            else
            {
                short str = w;
                width.Text = Convert.ToString(str);

                str = h;
                height.Text = Convert.ToString(str);

                int i = Convert.ToInt32(type);
                switch (i)
                {
                    case 344:
                        comboBox1.SelectedIndex = 0;
                        break;
                    case 600:
                        comboBox1.SelectedIndex = 1;
                        break;
                    case 856:
                        comboBox1.SelectedIndex = 2;
                        break;
                    case 1112:
                        comboBox1.SelectedIndex = 3;
                        break;
                    case 1368:
                        comboBox1.SelectedIndex = 4;
                        break;
                    case 1624:
                        comboBox1.SelectedIndex = 5;
                        break;
                    case 1880:
                        comboBox1.SelectedIndex = 6;
                        break;
                    default:
                        comboBox1.SelectedIndex = 7;
                        break;
                }
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            short w = Convert.ToInt16(width.Text);
            short h = Convert.ToInt16(height.Text);
            switch (comboBox1.SelectedIndex)
            {
                case 0://BX_YQ1_75
                    {
                        if (w > 384 || h > 384)
                        {
                            MessageBox.Show("YQ1-75 的宽高超出范围！");
                            return;
                        }
                        break;
                    }
                case 1://BX_YQ1
                    {
                        if (w > 384 || h > 256)
                        {
                            MessageBox.Show("YQ1 的宽高超出范围！");
                            return;
                        }
                        break;
                    }
                case 2://BX_YQ2
                    {
                        if (w > 2048 || h > 1024 || w * h > 480000)
                        {
                            MessageBox.Show("YQ2 的宽高超出范围！");
                            return;
                        }
                        break;
                    }
                default:
                    break;
            }
            if (card_mode == 0)
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_SetScreenSize(card_ip, w, h);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
            else if (card_mode == 1)
            {
                int err = LedYQServerAPI.LedYQserver.Server_SetScreenSize(PID, w, h);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }

        }
    }
}
