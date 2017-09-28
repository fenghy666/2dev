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
    public partial class CounterArea : Form
    {
        public LedNetSdkDemo.PicArea picArea = new LedNetSdkDemo.PicArea();
        public bool bl = false;
        public CounterArea(LedNetSdkDemo.PicArea PicArea)
        {
            picArea = PicArea;
            InitializeComponent();
            textBox1.Text = Convert.ToString(picArea.m_x);
            textBox2.Text = Convert.ToString(picArea.m_y);
            textBox3.Text = Convert.ToString(picArea.m_w);
            textBox4.Text = Convert.ToString(picArea.m_h);
            trackBar1.Value = picArea.m_bBgTransparent;
            if (picArea.m_Counter_Area.multiline == true)
            {
                radioButton2.Checked = true;
            }
            else { radioButton1.Checked = true; }
            textBox9.Text = picArea.m_Counter_Area.font;
            textBox7.Text = picArea.m_Counter_Area.fontsize.ToString();
            comboBox1.SelectedIndex = picArea.m_Counter_Area.align;
            if (picArea.m_Counter_Area.bold == false)
            {
                checkBox1.Checked = false;
            }
            else { checkBox1.Checked = true; }
            if (picArea.m_Counter_Area.italic == false)
            {
                checkBox2.Checked = false;
            }
            else { checkBox2.Checked = true; }
            if (picArea.m_Counter_Area.underline == false)
            {
                checkBox3.Checked = false;
            }
            else { checkBox3.Checked = true; }
            if (picArea.m_Counter_Area.add_enable == false)
            {
                checkBox4.Checked = false;
            }
            else { checkBox4.Checked = true; }
            button1.ForeColor = Color.FromArgb((int)picArea.m_Counter_Area.counter_color);
            if (picArea.m_Counter_Area.day_enable == false)
            {
                checkBox5.Checked = false;
            }
            else { checkBox5.Checked = true; }
            if (picArea.m_Counter_Area.hour_enable == false)
            {
                checkBox6.Checked = false;
            }
            else { checkBox6.Checked = true; }
            if (picArea.m_Counter_Area.min_enable == false)
            {
                checkBox7.Checked = false;
            }
            else { checkBox7.Checked = true; }
            if (picArea.m_Counter_Area.sec_enable == false)
            {
                checkBox8.Checked = false;
            }
            else { checkBox8.Checked = true; }
            if (picArea.m_Counter_Area.text_enable == false)
            {
                checkBox9.Checked = false;
            }
            else { checkBox9.Checked = true; }
            textBox8.Text = System.Text.Encoding.Unicode.GetString(picArea.m_Counter_Area.statictext);
            button5.ForeColor = Color.FromArgb((int)picArea.m_Counter_Area.textcolor);
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

        private void button1_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                button1.ForeColor = col.Color;
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                button5.ForeColor = col.Color;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            picArea.thing = 6;
            bl = true;
            picArea.m_x = Convert.ToInt16(textBox1.Text);
            picArea.m_y = Convert.ToInt16(textBox2.Text);
            picArea.m_w = Convert.ToInt16(textBox3.Text);
            picArea.m_h = Convert.ToInt16(textBox4.Text);
            picArea.m_bBgTransparent = (byte)trackBar1.Value;
            LedNetSdkDemo.Counter_Area mCounter_Area = new LedNetSdkDemo.Counter_Area();
            mCounter_Area.font = textBox9.Text;//文本字体
            mCounter_Area.fontsize = uint.Parse(textBox7.Text);//字体大小
            mCounter_Area.bold = checkBox1.Checked;//是否加粗
            mCounter_Area.italic = checkBox2.Checked;//是否斜体
            mCounter_Area.underline = checkBox3.Checked;//是否下划线
            mCounter_Area.align = comboBox1.SelectedIndex;//对齐方式，0-左对齐，1-居中对齐，2-右对齐
            //是否多行
            if (radioButton2.Checked == true)
            {
                mCounter_Area.multiline = true;
            }
            if (radioButton1.Checked == true)
            {
                mCounter_Area.multiline = false;
            }
            mCounter_Area.target_date = System.Text.Encoding.Unicode.GetBytes(dateTimePicker1.Text);
            mCounter_Area.target_time = System.Text.Encoding.Unicode.GetBytes(dateTimePicker2.Text);
            //0-倒计时，1-正计时
            string data1 = DateTime.Now.ToString("yyyy/MM/dd");
            string data2 = DateTime.Now.ToString("hh/mm/ss");
            DateTime dt1 = Convert.ToDateTime(dateTimePicker1.Text);  
            DateTime dt2 = Convert.ToDateTime(data1); 
            DateTime dt3 = dateTimePicker2.Value;
            DateTime dt4 = DateTime.Now;
            if(dt1 > dt2) 
            {
                mCounter_Area.bTimeFlag = false;
            }
            else if (dt1 < dt2)
            {
                mCounter_Area.bTimeFlag = true;
            }
            else 
            {
                if(dt3 > dt4)
                {
                    mCounter_Area.bTimeFlag = false;
                }else
                    mCounter_Area.bTimeFlag = true;
            }
            mCounter_Area.counter_color = (uint)button1.ForeColor.ToArgb();//计时器文本对应的颜色
            //是否显示天
            if (checkBox5.Checked == true)
            {
                mCounter_Area.day_enable = true;
            }
            else { mCounter_Area.day_enable = false; }
            mCounter_Area.daytext = System.Text.Encoding.Unicode.GetBytes("天");
            //是否显示小时
            if (checkBox6.Checked == true)
            {
                mCounter_Area.hour_enable = true;
            }
            else { mCounter_Area.hour_enable = false; }
            mCounter_Area.hourtext = System.Text.Encoding.Unicode.GetBytes("小时");
            //是否显示分钟
            if (checkBox7.Checked == true)
            {
                mCounter_Area.min_enable = true;
            }
            else { mCounter_Area.min_enable = false; }
            mCounter_Area.minutetext = System.Text.Encoding.Unicode.GetBytes("分");
            //是否显示秒
            if (checkBox8.Checked == true)
            {
                mCounter_Area.sec_enable = true;
            }
            else { mCounter_Area.sec_enable = false; }
            mCounter_Area.secondtext = System.Text.Encoding.Unicode.GetBytes("秒");
            //是否计时累计
            if (checkBox4.Checked == true)
            {
                mCounter_Area.add_enable = true;
            }
            else { mCounter_Area.add_enable = false; }
            //是否显示单位（天，小时，分,秒）
            if (mCounter_Area.day_enable == true || mCounter_Area.hour_enable == true || mCounter_Area.min_enable == true || mCounter_Area.sec_enable == true)
            {
                mCounter_Area.unit_enable = true;
            }
            else { mCounter_Area.unit_enable = false; }
            //是否添加自定义文本
            if (checkBox9.Checked == true)
            {
                mCounter_Area.text_enable = true;
            }
            else { mCounter_Area.text_enable = false; }
            mCounter_Area.textcolor = (uint)button5.ForeColor.ToArgb();//自定义文本颜色
            mCounter_Area.statictext = System.Text.Encoding.Unicode.GetBytes(textBox8.Text);//自定义文本内容

            picArea.m_Counter_Area = mCounter_Area;
            this.Close();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            bl = false;
            this.Close();
        }
    }
}
