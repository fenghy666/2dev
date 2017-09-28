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
    public partial class StrrefPage : Form
    {
        public LedNetSdkDemo.texturl mtexturl = new LedNetSdkDemo.texturl();
        public bool page = false;
        public StrrefPage()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                button1.ForeColor = col.Color;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            page = false;
            this.Close();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            mtexturl.BgColor = (uint)button1.ForeColor.ToArgb();
            mtexturl.LinesSizes = int.Parse(textBox1.Text);
            mtexturl.user = textBox6.Text;
            mtexturl.pwd = textBox5.Text;
            mtexturl.url = System.Text.Encoding.Unicode.GetBytes(textBox2.Text);

            page = true;
            this.Close();
        }
    }
}
