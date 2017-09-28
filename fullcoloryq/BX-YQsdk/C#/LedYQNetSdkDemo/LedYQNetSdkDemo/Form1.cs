using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using LedYQNetSDKAPI;

namespace LedYQNetSdkDemo
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            LedYQNetSdk.Sdk_Init();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Client PC = new Client();
            PC.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Server pS = new Server();
            pS.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Van van = new Van();
            van.ShowDialog();
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            LedYQNetSdk.Sdk_Release();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
