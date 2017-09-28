using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace LedYQNetSdkDemo
{
    public partial class PicRef : Form
    {
        public LedNetSdkDemo.imgurl m_imgurl = new LedNetSdkDemo.imgurl();
        public bool URL = false;
        public PicRef()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            URL = true;
            m_imgurl.user = textBox1.Text;
            m_imgurl.pwd = textBox2.Text;
            m_imgurl.url = System.Text.Encoding.Unicode.GetBytes(textBox3.Text);
            m_imgurl.Suffix = Path.GetExtension(textBox3.Text);
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            URL = false;
            this.Close();
        }
    }
}
