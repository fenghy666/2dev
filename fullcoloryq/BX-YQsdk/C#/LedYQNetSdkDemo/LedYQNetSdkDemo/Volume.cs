using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace LedYQNetSdkDemo
{
    public partial class Volume : Form
    {
        int card_mode;
        string ip;
        byte[] PID;
        System.Byte nVolume = 0;
        public Volume(string ip)
        {
            card_mode = 0;
            this.ip = ip;
            int err = LedYQNetSDKAPI.LedYQNetSdk.Net_GetVolume(ip, ref nVolume);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            InitializeComponent();
            if (nVolume>100)
            {
                nVolume = 100;
            }
            trackBar1.Value = nVolume;
            label1.Text = nVolume.ToString();
        }
        public Volume(byte[] pid)
        {
            card_mode = 1;
            PID = pid;
            int err = LedYQServerAPI.LedYQserver.Server_GetVolume(PID, ref nVolume);
            if (err != 0)
            {
                LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
            }
            InitializeComponent();
            if (nVolume > 100)
            {
                nVolume = 100;
            }
            trackBar1.Value = nVolume;
            label1.Text = nVolume.ToString();
        }

        private void trackBar1_MouseCaptureChanged(object sender, EventArgs e)
        {
            nVolume = (System.Byte)trackBar1.Value;
            if (card_mode == 0)
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_SetVolume(ip, nVolume);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
            else 
            {
                int err = LedYQServerAPI.LedYQserver.Server_SetVolume(PID, nVolume);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
            label1.Text = trackBar1.Value.ToString();
        }
    }
}
