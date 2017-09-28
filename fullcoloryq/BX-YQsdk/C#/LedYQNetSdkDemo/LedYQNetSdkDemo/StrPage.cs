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
    public partial class StrPage : Form
    {
        public LedNetSdkDemo.DynaStrPage m_Dynastrpage = new LedNetSdkDemo.DynaStrPage();
        public bool page = false;
        public StrPage()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                button2.ForeColor = col.Color;
            }
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
            m_Dynastrpage.m_LineSpace = int.Parse(textBox1.Text);
            m_Dynastrpage.m_BgColor = (uint)button1.ForeColor.ToArgb();
            m_Dynastrpage.m_font = textBox3.Text;
            m_Dynastrpage.m_fontsize = int.Parse(textBox4.Text);
            m_Dynastrpage.txtcolor = (uint)button2.ForeColor.ToArgb();
            m_Dynastrpage.m_antialiasing = checkBox1.Checked;
            m_Dynastrpage.m_bold = checkBox2.Checked;
            m_Dynastrpage.m_italic = checkBox3.Checked;
            m_Dynastrpage.m_underline = checkBox4.Checked;
            m_Dynastrpage.m_strikeout = checkBox5.Checked;
            m_Dynastrpage.szTxt = System.Text.Encoding.Unicode.GetBytes(textBox2.Text);
            page = true;
            this.Close();
        }

        private void button5_Click(object sender, EventArgs e)//字体
        {
            FontDialog fontdia = new FontDialog();
            if (fontdia.ShowDialog() == DialogResult.OK)
            {
                textBox3.Text = fontdia.Font.Name;
                checkBox2.Checked = fontdia.Font.Bold;
                checkBox3.Checked = fontdia.Font.Italic;
                checkBox4.Checked = fontdia.Font.Underline;
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            page = false;
            this.Close();
        }
    }
}
