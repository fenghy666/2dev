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
    public partial class LunArea : Form
    {
        public LedNetSdkDemo.PicArea picArea = new LedNetSdkDemo.PicArea();
        public List<LedNetSdkDemo.Lun_Area> mLunArea = new List<LedNetSdkDemo.Lun_Area>();
        public bool bl = false;
        public LunArea(LedNetSdkDemo.PicArea PicArea)
        {
            picArea = PicArea;
            InitializeComponent();
            textBox1.Text = Convert.ToString(picArea.m_x);
            textBox2.Text = Convert.ToString(picArea.m_y);
            textBox3.Text = Convert.ToString(picArea.m_w);
            textBox4.Text = Convert.ToString(picArea.m_h);
            trackBar1.Value = picArea.m_bBgTransparent;
            if (picArea.m_Lun_Area.multiline == true)
            {
                radioButton2.Checked = true;
            }
            else { radioButton1.Checked = true; }
            textBox9.Text = picArea.m_Lun_Area.text_font;
            textBox7.Text = picArea.m_Lun_Area.text_fontsize.ToString();
            comboBox1.SelectedIndex = picArea.m_Lun_Area.align;
            if (picArea.m_Lun_Area.text_bold == false)
            {
                checkBox1.Checked = false;
            }
            else { checkBox1.Checked = true; }
            if (picArea.m_Lun_Area.text_italic == false)
            {
                checkBox2.Checked = false;
            }
            else { checkBox2.Checked = true; }
            if (picArea.m_Lun_Area.text_underline == false)
            {
                checkBox3.Checked = false;
            }
            else { checkBox3.Checked = true; }
            if (picArea.m_Lun_Area.year_enable == false)
            {
                checkBox4.Checked = false;
            }
            else { checkBox4.Checked = true; }
            button1.ForeColor = Color.FromArgb((int)picArea.m_Lun_Area.yearcolor);
            if (picArea.m_Lun_Area.day_enable == false)
            {
                checkBox5.Checked = false;
            }
            else { checkBox5.Checked = true; }
            button2.ForeColor = Color.FromArgb((int)picArea.m_Lun_Area.daycolor);
            if (picArea.m_Lun_Area.solarterms_enable == false)
            {
                checkBox6.Checked = false;
            }
            else { checkBox6.Checked = true; }
            button3.ForeColor = Color.FromArgb((int)picArea.m_Lun_Area.solartermscolor);
            if (picArea.m_Lun_Area.text_enable == false)
            {
                checkBox7.Checked = false;
            }
            else { checkBox7.Checked = true; }
            textBox8.Text = System.Text.Encoding.Unicode.GetString(picArea.m_Lun_Area.statictext);
            button5.ForeColor = Color.FromArgb((int)picArea.m_Lun_Area.textcolor);
        }

        private void button4_Click(object sender, EventArgs e)//确定
        {
            picArea.thing = 5;
            bl = true;
            picArea.m_x = Convert.ToInt16(textBox1.Text);
            picArea.m_y = Convert.ToInt16(textBox2.Text);
            picArea.m_w = Convert.ToInt16(textBox3.Text);
            picArea.m_h = Convert.ToInt16(textBox4.Text);
            picArea.m_bBgTransparent = (byte)trackBar1.Value;

            LedNetSdkDemo.Lun_Area mLun_Area = new LedNetSdkDemo.Lun_Area();
            //是否多行
            if (radioButton2.Checked == true)
            {
                mLun_Area.multiline = true;
            } 
            if (radioButton1.Checked == true)
            {
                mLun_Area.multiline = false;
            }
            //是否使能显示农历
            if (checkBox4.Checked == true)
            {
                mLun_Area.year_enable = true;
                mLun_Area.yearcolor = (uint)button1.ForeColor.ToArgb();
            }
            else 
            {
                mLun_Area.year_enable = false;
                mLun_Area.yearcolor = (uint)button1.ForeColor.ToArgb();
            }
            //是否使能显示日期
            if (checkBox5.Checked == true)
            {
                mLun_Area.day_enable = true;
                mLun_Area.daycolor = (uint)button2.ForeColor.ToArgb();
            }
            else
            {
                mLun_Area.day_enable = false;
                mLun_Area.daycolor = (uint)button2.ForeColor.ToArgb();
            }
            //是否使能显示节气
            if (checkBox6.Checked == true)
            {
                mLun_Area.solarterms_enable = true;
                mLun_Area.solartermscolor = (uint)button3.ForeColor.ToArgb();
            }
            else
            {
                mLun_Area.solarterms_enable = false;
                mLun_Area.solartermscolor = (uint)button3.ForeColor.ToArgb();
            }
            if (checkBox7.Checked == true)
            {
                mLun_Area.text_enable = true;//是否添加自定义文本
            }
            else 
            {
                mLun_Area.text_enable = false;//是否添加自定义文本
            }
                mLun_Area.textcolor = (uint)button5.ForeColor.ToArgb();//自定义文本颜色
                mLun_Area.statictext = System.Text.Encoding.Unicode.GetBytes(textBox8.Text);//自定义文本内容

            mLun_Area.text_font = textBox9.Text;//文本字体
            mLun_Area.text_fontsize = uint.Parse(textBox7.Text);//字体大小
            mLun_Area.text_bold = checkBox1.Checked;//是否加粗
            mLun_Area.text_italic = checkBox2.Checked;//是否斜体
            mLun_Area.text_underline = checkBox3.Checked;//是否下划线
            mLun_Area.align = comboBox1.SelectedIndex;//对齐方式，0-左对齐，1-居中对齐，2-右对齐

            picArea.m_Lun_Area = mLun_Area;
            this.Close();
        }

        private void button12_Click(object sender, EventArgs e)//字体样式
        {
            FontDialog fontdia = new FontDialog();
            if (fontdia.ShowDialog() == DialogResult.OK)
            {
                textBox9.Text = fontdia.Font.Name;
                checkBox1.Checked = fontdia.Font.Bold;
                checkBox2.Checked = fontdia.Font.Italic;
                checkBox3.Checked = fontdia.Font.Underline;
            }
        }

        private void button1_Click(object sender, EventArgs e)//农历颜色
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                button1.ForeColor = col.Color;
            }
        }

        private void button2_Click(object sender, EventArgs e)//天干颜色
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                button2.ForeColor = col.Color;
            }
        }

        private void button3_Click(object sender, EventArgs e)//节气颜色
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                button3.ForeColor = col.Color;
            }
        }

        private void button5_Click(object sender, EventArgs e)//文本颜色
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                button5.ForeColor = col.Color;
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            bl = false;
            this.Close();
        }
    }
}
