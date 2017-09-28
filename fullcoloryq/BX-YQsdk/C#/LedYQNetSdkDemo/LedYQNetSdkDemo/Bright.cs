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

namespace LedYQNetSdkDemo
{
    public partial class Bright : Form
    {
        int card_mode;
        byte[] PID;
        string ip;
        byte pMode = 0;
        byte[] pValue = new byte[48];
        short[] pValue1 = new short[48];
        public Bright(string ip)
        {
            card_mode = 0;
            this.ip = ip;
            InitializeComponent();
            int err = LedYQNetSDKAPI.LedYQNetSdk.Net_GetBrightness(ip, ref pMode, pValue);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            switch (pMode) 
            {
                case 0:
                    radioButton1.Checked = true;
                    textBox1.Text = pValue[0].ToString();
                    break;
                case 1:
                    radioButton2.Checked = true;
                    textBox2.Text = Convert.ToString(pValue[0]);
                    textBox3.Text = Convert.ToString(pValue[1]);
                    textBox4.Text = Convert.ToString(pValue[2]);
                    textBox5.Text = Convert.ToString(pValue[3]);
                    textBox6.Text = Convert.ToString(pValue[4]);
                    textBox7.Text = Convert.ToString(pValue[5]);
                    textBox8.Text = Convert.ToString(pValue[6]);
                    textBox9.Text = Convert.ToString(pValue[7]);
                    textBox10.Text = Convert.ToString(pValue[8]);
                    textBox11.Text = Convert.ToString(pValue[9]);
                    textBox12.Text = Convert.ToString(pValue[10]);
                    textBox13.Text = Convert.ToString(pValue[11]);
                    textBox14.Text = Convert.ToString(pValue[12]);
                    textBox15.Text = Convert.ToString(pValue[13]);
                    textBox16.Text = Convert.ToString(pValue[14]);
                    textBox17.Text = Convert.ToString(pValue[15]);
                    textBox18.Text = Convert.ToString(pValue[16]);
                    textBox19.Text = Convert.ToString(pValue[17]);
                    textBox20.Text = Convert.ToString(pValue[18]);
                    textBox21.Text = Convert.ToString(pValue[19]);
                    textBox22.Text = Convert.ToString(pValue[20]);
                    textBox23.Text = Convert.ToString(pValue[21]);
                    textBox24.Text = Convert.ToString(pValue[22]);
                    textBox25.Text = Convert.ToString(pValue[23]);
                    textBox26.Text = Convert.ToString(pValue[24]);
                    textBox27.Text = Convert.ToString(pValue[25]);
                    textBox28.Text = Convert.ToString(pValue[26]);
                    textBox29.Text = Convert.ToString(pValue[27]);
                    textBox30.Text = Convert.ToString(pValue[28]);
                    textBox31.Text = Convert.ToString(pValue[29]);
                    textBox32.Text = Convert.ToString(pValue[30]);
                    textBox33.Text = Convert.ToString(pValue[31]);
                    textBox34.Text = Convert.ToString(pValue[32]);
                    textBox35.Text = Convert.ToString(pValue[33]);
                    textBox36.Text = Convert.ToString(pValue[34]);
                    textBox37.Text = Convert.ToString(pValue[35]);
                    textBox38.Text = Convert.ToString(pValue[36]);
                    textBox39.Text = Convert.ToString(pValue[37]);
                    textBox40.Text = Convert.ToString(pValue[38]);
                    textBox41.Text = Convert.ToString(pValue[39]);
                    textBox42.Text = Convert.ToString(pValue[40]);
                    textBox43.Text = Convert.ToString(pValue[41]);
                    textBox44.Text = Convert.ToString(pValue[42]);
                    textBox45.Text = Convert.ToString(pValue[43]);
                    textBox46.Text = Convert.ToString(pValue[44]);
                    textBox47.Text = Convert.ToString(pValue[45]);
                    textBox48.Text = Convert.ToString(pValue[46]);
                    textBox49.Text = Convert.ToString(pValue[47]);
                    break;
                case 2:
                    break;
                case 3:
                    break;
            }
        }
        public Bright(byte[] pid)
        {
            card_mode = 1;
            PID = pid;
            InitializeComponent();
            int err = LedYQServerAPI.LedYQserver.Server_GetBrightness(PID, ref pMode, pValue);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            switch (pMode)
            {
                case 0:
                    radioButton1.Checked = true;
                    textBox1.Text = pValue[0].ToString();
                    break;
                case 1:
                    radioButton2.Checked = true;
                    textBox2.Text = Convert.ToString(pValue[0]);
                    textBox3.Text = Convert.ToString(pValue[1]);
                    textBox4.Text = Convert.ToString(pValue[2]);
                    textBox5.Text = Convert.ToString(pValue[3]);
                    textBox6.Text = Convert.ToString(pValue[4]);
                    textBox7.Text = Convert.ToString(pValue[5]);
                    textBox8.Text = Convert.ToString(pValue[6]);
                    textBox9.Text = Convert.ToString(pValue[7]);
                    textBox10.Text = Convert.ToString(pValue[8]);
                    textBox11.Text = Convert.ToString(pValue[9]);
                    textBox12.Text = Convert.ToString(pValue[10]);
                    textBox13.Text = Convert.ToString(pValue[11]);
                    textBox14.Text = Convert.ToString(pValue[12]);
                    textBox15.Text = Convert.ToString(pValue[13]);
                    textBox16.Text = Convert.ToString(pValue[14]);
                    textBox17.Text = Convert.ToString(pValue[15]);
                    textBox18.Text = Convert.ToString(pValue[16]);
                    textBox19.Text = Convert.ToString(pValue[17]);
                    textBox20.Text = Convert.ToString(pValue[18]);
                    textBox21.Text = Convert.ToString(pValue[19]);
                    textBox22.Text = Convert.ToString(pValue[20]);
                    textBox23.Text = Convert.ToString(pValue[21]);
                    textBox24.Text = Convert.ToString(pValue[22]);
                    textBox25.Text = Convert.ToString(pValue[23]);
                    textBox26.Text = Convert.ToString(pValue[24]);
                    textBox27.Text = Convert.ToString(pValue[25]);
                    textBox28.Text = Convert.ToString(pValue[26]);
                    textBox29.Text = Convert.ToString(pValue[27]);
                    textBox30.Text = Convert.ToString(pValue[28]);
                    textBox31.Text = Convert.ToString(pValue[29]);
                    textBox32.Text = Convert.ToString(pValue[30]);
                    textBox33.Text = Convert.ToString(pValue[31]);
                    textBox34.Text = Convert.ToString(pValue[32]);
                    textBox35.Text = Convert.ToString(pValue[33]);
                    textBox36.Text = Convert.ToString(pValue[34]);
                    textBox37.Text = Convert.ToString(pValue[35]);
                    textBox38.Text = Convert.ToString(pValue[36]);
                    textBox39.Text = Convert.ToString(pValue[37]);
                    textBox40.Text = Convert.ToString(pValue[38]);
                    textBox41.Text = Convert.ToString(pValue[39]);
                    textBox42.Text = Convert.ToString(pValue[40]);
                    textBox43.Text = Convert.ToString(pValue[41]);
                    textBox44.Text = Convert.ToString(pValue[42]);
                    textBox45.Text = Convert.ToString(pValue[43]);
                    textBox46.Text = Convert.ToString(pValue[44]);
                    textBox47.Text = Convert.ToString(pValue[45]);
                    textBox48.Text = Convert.ToString(pValue[46]);
                    textBox49.Text = Convert.ToString(pValue[47]);
                    break;
                case 2:
                    break;
                case 3:
                    break;
            }
        }

        private void button1_Click(object sender, EventArgs e)//调亮
        {
            if (radioButton1.Checked == true)
            {
                pMode = 0;
                pValue1[0] = Convert.ToByte(textBox1.Text);
            }
            else 
            {
                pMode = 1;
                pValue1[0] = Convert.ToByte(textBox2.Text);
                pValue1[1] = Convert.ToByte(textBox3.Text);
                pValue1[2] = Convert.ToByte(textBox4.Text);
                pValue1[3] = Convert.ToByte(textBox5.Text);
                pValue1[4] = Convert.ToByte(textBox6.Text);
                pValue1[5] = Convert.ToByte(textBox7.Text);
                pValue1[6] = Convert.ToByte(textBox8.Text);
                pValue1[7] = Convert.ToByte(textBox9.Text);
                pValue1[8] = Convert.ToByte(textBox10.Text);
                pValue1[9] = Convert.ToByte(textBox11.Text);
                pValue1[10] = Convert.ToByte(textBox12.Text);
                pValue1[11] = Convert.ToByte(textBox13.Text);
                pValue1[12] = Convert.ToByte(textBox14.Text);
                pValue1[13] = Convert.ToByte(textBox15.Text);
                pValue1[14] = Convert.ToByte(textBox16.Text);
                pValue1[15] = Convert.ToByte(textBox17.Text);
                pValue1[16] = Convert.ToByte(textBox18.Text);
                pValue1[17] = Convert.ToByte(textBox19.Text);
                pValue1[18] = Convert.ToByte(textBox20.Text);
                pValue1[19] = Convert.ToByte(textBox21.Text);
                pValue1[20] = Convert.ToByte(textBox22.Text);
                pValue1[21] = Convert.ToByte(textBox23.Text);
                pValue1[22] = Convert.ToByte(textBox24.Text);
                pValue1[23] = Convert.ToByte(textBox25.Text);
                pValue1[24] = Convert.ToByte(textBox26.Text);
                pValue1[25] = Convert.ToByte(textBox27.Text);
                pValue1[26] = Convert.ToByte(textBox28.Text);
                pValue1[27] = Convert.ToByte(textBox29.Text);
                pValue1[28] = Convert.ToByte(textBox30.Text);
                pValue1[29] = Convert.ToByte(textBox31.Text);
                pValue1[30] = Convert.ToByte(textBox32.Text);
                pValue1[31] = Convert.ToByte(textBox33.Text);
                pValue1[32] = Convert.ToByte(textBox34.Text);
                pValue1[33] = Convert.ToByte(textBox35.Text);
                pValue1[34] = Convert.ToByte(textBox36.Text);
                pValue1[35] = Convert.ToByte(textBox37.Text);
                pValue1[36] = Convert.ToByte(textBox38.Text);
                pValue1[37] = Convert.ToByte(textBox39.Text);
                pValue1[38] = Convert.ToByte(textBox40.Text);
                pValue1[39] = Convert.ToByte(textBox41.Text);
                pValue1[40] = Convert.ToByte(textBox42.Text);
                pValue1[41] = Convert.ToByte(textBox43.Text);
                pValue1[42] = Convert.ToByte(textBox44.Text);
                pValue1[43] = Convert.ToByte(textBox45.Text);
                pValue1[44] = Convert.ToByte(textBox46.Text);
                pValue1[45] = Convert.ToByte(textBox47.Text);
                pValue1[46] = Convert.ToByte(textBox48.Text);
                pValue1[47] = Convert.ToByte(textBox49.Text);
            }
            if (card_mode == 0)
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_AdjustBrightness(ip, pMode, pValue1);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
            else 
            {
                int err = LedYQServerAPI.LedYQserver.Server_AdjustBrightness(PID, pMode, pValue1);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
        }
    }
}
