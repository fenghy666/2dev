﻿using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using ONNONLed5KSDKD;

namespace Led5KSDKDemoCSharp
{
    public partial class Area : Form
    {
        public Area()
        {
            InitializeComponent();
            comboBox1.SelectedIndex = 0;
            comboBox2.SelectedIndex = 0;
            comboBox3.SelectedIndex = 0;
            comboBox4.SelectedIndex = 0;
            comboBox5.SelectedIndex = 0;
        }
            
        //public uint i;
        public static byte[] AreaText;
       
        public Led5kSDK.bx_5k_area_header bx_5k;
        private void button1_Click(object sender, EventArgs e)
        {
            bx_5k.AreaType = 0x06;
            bx_5k.AreaX = Convert.ToInt16(textBox1.Text);
            bx_5k.AreaX /= 8;
            bx_5k.AreaY = Convert.ToInt16(textBox2.Text);
            bx_5k.AreaWidth = Convert.ToInt16(textBox3.Text);
            bx_5k.AreaWidth /= 8;
            bx_5k.AreaHeight = Convert.ToInt16(textBox4.Text);

            bx_5k.Lines_sizes = Convert.ToByte(textBox5.Text);

            byte[] RunMode_list = new byte[3];
            RunMode_list[0] = 0;
            RunMode_list[1] = 1;
            RunMode_list[2] = 2;
            int rl = comboBox3.SelectedIndex;
            bx_5k.RunMode = RunMode_list[rl];
            //bx_5k.RunMode = Convert.ToByte(comboBox3.SelectedIndex+1);

            bx_5k.Timeout = Convert.ToInt16(textBox7.Text);


            bx_5k.Reserved1 = 0;
            bx_5k.Reserved2 = 0;
            bx_5k.Reserved3 = 0;

            byte[] SingleLine_list = new byte[2];
            SingleLine_list[0] = 0x01;
            SingleLine_list[1] = 0x02;
            int sll = comboBox1.SelectedIndex;
            bx_5k.SingleLine = SingleLine_list[sll];
            //bx_5k.SingleLine = Convert.ToByte(comboBox1.SelectedIndex);

            byte []NewLine_list=new byte[2];
            NewLine_list[0] = 0x01;
            NewLine_list[1] = 0x02;
            int nl = comboBox2.SelectedIndex;
            bx_5k.NewLine = NewLine_list[nl];
            //bx_5k.NewLine = Convert.ToByte(comboBox2.SelectedIndex);


            byte[] DisplayMode_list=new byte[6];
            DisplayMode_list[0] = 0x01;
            DisplayMode_list[1] = 0x02;
            DisplayMode_list[2] = 0x03;
            DisplayMode_list[3] = 0x04;
            DisplayMode_list[4] = 0x05;
            DisplayMode_list[5] = 0x06;
            int dml = comboBox4.SelectedIndex;
            bx_5k.DisplayMode = DisplayMode_list[dml];
            //bx_5k.DisplayMode = Convert.ToByte(comboBox4.SelectedIndex);

            bx_5k.ExitMode = 0x00;


            bx_5k.Speed =(byte) comboBox5.SelectedIndex;
            //bx_5k.Speed=Convert.ToByte(comboBox5.SelectedIndex);

            bx_5k.StayTime = Convert.ToByte(textBox8.Text);
            
            AreaText = System.Text.Encoding.Default.GetBytes(textBox6.Text.Trim());
            bx_5k.DataLen = AreaText.Length;
            this.Close();
        }
        private void Area_Load(object sender, EventArgs e)
        {
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
            this.Dispose();
        }
    }
}
