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
    public partial class ClockArea : Form
    {
        public LedNetSdkDemo.PicArea picArea = new LedNetSdkDemo.PicArea();
        public List<LedNetSdkDemo.Clock_Area> mClockArea = new List<LedNetSdkDemo.Clock_Area>();
        public bool bl = false;
        public ClockArea(LedNetSdkDemo.PicArea PicArea)
        {
            picArea = PicArea;
            InitializeComponent();
            textBox1.Text = Convert.ToString(picArea.m_x);
            textBox2.Text = Convert.ToString(picArea.m_y);
            textBox3.Text = Convert.ToString(picArea.m_w);
            textBox4.Text = Convert.ToString(picArea.m_h);
            trackBar1.Value = picArea.m_bBgTransparent;
            comboBox1.SelectedIndex = picArea.m_Clock_Area.timediff_flag;
            textBox5.Text = picArea.m_Clock_Area.timediff_hour.ToString();
            textBox6.Text = picArea.m_Clock_Area.timediff_min.ToString();
            textBox9.Text = picArea.m_Clock_Area.text_font;
            textBox7.Text = picArea.m_Clock_Area.text_fontsize.ToString();
            if (picArea.m_Clock_Area.text_bold == false)
            {
                checkBox1.Checked = false;
            }
            else { checkBox1.Checked = true; }
            if (picArea.m_Clock_Area.text_italic == false)
            {
                checkBox2.Checked = false;
            }
            else { checkBox2.Checked = true; }
            if (picArea.m_Clock_Area.text_underline == false)
            {
                checkBox3.Checked = false;
            }
            else { checkBox3.Checked = true; }
            if (picArea.m_Clock_Area.ymd_enable == false)
            {
                checkBox4.Checked = false;
            }
            else { checkBox4.Checked = true; }
            button3.ForeColor = Color.FromArgb((int)picArea.m_Clock_Area.ymdcolor);
            if (picArea.m_Clock_Area.week_enable == false)
            {
                checkBox5.Checked = false;
            }
            else { checkBox5.Checked = true; }
            button4.ForeColor = Color.FromArgb((int)picArea.m_Clock_Area.weekcolor);
            if (picArea.m_Clock_Area.text_enable == false)
            {
                checkBox6.Checked = false;
            }
            else { checkBox6.Checked = true; }
            textBox8.Text = System.Text.Encoding.Unicode.GetString(picArea.m_Clock_Area.statictex);
            button5.ForeColor = Color.FromArgb((int)picArea.m_Clock_Area.textcolor);
            comboBox3.SelectedIndex = (int)picArea.m_Clock_Area.dwClockFormat;
            button6.ForeColor = Color.FromArgb((int)picArea.m_Clock_Area.rightangle_color);
            button7.ForeColor = Color.FromArgb((int)picArea.m_Clock_Area.minute_color);
            button8.ForeColor = Color.FromArgb((int)picArea.m_Clock_Area.integral_color);
            button9.ForeColor = Color.FromArgb((int)picArea.m_Clock_Area.hourhand_color);
            button10.ForeColor = Color.FromArgb((int)picArea.m_Clock_Area.minhand_color);
            button11.ForeColor = Color.FromArgb((int)picArea.m_Clock_Area.secondhand_color);
        }

        private void button1_Click(object sender, EventArgs e)//确定
        {
            picArea.thing = 4;
            bl = true;
            picArea.m_x = Convert.ToInt16(textBox1.Text);
            picArea.m_y = Convert.ToInt16(textBox2.Text);
            picArea.m_w = Convert.ToInt16(textBox3.Text);
            picArea.m_h = Convert.ToInt16(textBox4.Text);
            picArea.m_bBgTransparent = (byte)trackBar1.Value;
            LedNetSdkDemo.Clock_Area mClock_Area;
            //自定义文本
            if (checkBox6.Checked == true)
            {
                mClock_Area.text_enable = true;
            }
            else 
            {
                mClock_Area.text_enable = false;
            }
            mClock_Area.textcolor = (uint)button5.ForeColor.ToArgb();
            mClock_Area.statictex = System.Text.Encoding.Unicode.GetBytes(textBox8.Text);

            mClock_Area.text_font = textBox9.Text;//文本字体
            mClock_Area.text_fontsize = uint.Parse(textBox7.Text);//字体大小
            mClock_Area.text_bold = checkBox1.Checked;// 是否加粗
            mClock_Area.text_italic = checkBox2.Checked; //是否斜体
            mClock_Area.text_underline = checkBox3.Checked;//是否下划线

            //是否显示年月日
            if (checkBox4.Checked == true)
            {
                mClock_Area.ymd_enable = true;
                mClock_Area.ymdcolor = (uint)button3.ForeColor.ToArgb();
            }
            else 
            {
                mClock_Area.ymd_enable = false;
                mClock_Area.ymdcolor = (uint)button3.ForeColor.ToArgb();
            }
            //是否显示星期
            if (checkBox5.Checked == true)
            {
                mClock_Area.week_enable = true;
                mClock_Area.weekcolor = (uint)button4.ForeColor.ToArgb();
            }
            else
            {
                mClock_Area.week_enable = false;
                mClock_Area.weekcolor = (uint)button4.ForeColor.ToArgb();
            }
            mClock_Area.hourhand_color = (uint)(button9.ForeColor.R * 256 * 256 + button9.ForeColor.G * 256 + button9.ForeColor.B);//时针颜色
            mClock_Area.minhand_color = (uint)(button10.ForeColor.R * 256 * 256 + button10.ForeColor.G * 256 + button10.ForeColor.B);//分针颜色
            mClock_Area.secondhand_color = (uint)(button11.ForeColor.R * 256 * 255 + button11.ForeColor.G * 256 + button11.ForeColor.B);//秒针颜色
            mClock_Area.timediff_flag = (byte)comboBox1.SelectedIndex;//0-正时差，1-负时差，
            mClock_Area.timediff_hour = Convert.ToByte(textBox5.Text);//时差的小时部分
            mClock_Area.timediff_min = Convert.ToByte(textBox6.Text);//时差的分钟部分
            mClock_Area.rightangle_color = (uint)button6.ForeColor.ToArgb();//时点颜色
            mClock_Area.minute_color = (uint)button7.ForeColor.ToArgb();//分点颜色
            mClock_Area.integral_color = (uint)button8.ForeColor.ToArgb();//369点颜色
            mClock_Area.dwClockFormat = (uint)comboBox3.SelectedIndex;//表盘风格，0-线形;1-点形;2-方形;3-数字;4-罗马

            picArea.m_Clock_Area = mClock_Area;
            this.Close();
        }

        private void button3_Click(object sender, EventArgs e)//日期
        {
            Color col = new Color();
            if (this.colorDialog1.ShowDialog() == DialogResult.OK)
            {
                col = colorDialog1.Color;
            }
            button3.ForeColor = col;
        }

        private void button4_Click(object sender, EventArgs e)//星期
        {
            Color col = new Color();
            if (this.colorDialog1.ShowDialog() == DialogResult.OK)
            {
                col = colorDialog1.Color;
            }
            button4.ForeColor = col;
        }

        private void button5_Click(object sender, EventArgs e)//文本
        {
            Color col = new Color();
            if (this.colorDialog1.ShowDialog() == DialogResult.OK)
            {
                col = colorDialog1.Color;
            }
            button5.ForeColor = col;
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Color col = new Color();
            if (this.colorDialog1.ShowDialog() == DialogResult.OK)
            {
                col = colorDialog1.Color;
            }
            button6.ForeColor = col;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            Color col = new Color();
            if (this.colorDialog1.ShowDialog() == DialogResult.OK)
            {
                col = colorDialog1.Color;
            }
            button7.ForeColor = col;
        }

        private void button8_Click(object sender, EventArgs e)
        {
            Color col = new Color();
            if (this.colorDialog1.ShowDialog() == DialogResult.OK)
            {
                col = colorDialog1.Color;
            }
            button8.ForeColor = col;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            Color col = new Color();
            if (this.colorDialog1.ShowDialog() == DialogResult.OK)
            {
                col = colorDialog1.Color;
            }
            button9.ForeColor = col;
        }

        private void button10_Click(object sender, EventArgs e)
        {
            Color col = new Color();
            if (this.colorDialog1.ShowDialog() == DialogResult.OK)
            {
                col = colorDialog1.Color;
            }
            button10.ForeColor = col;
        }

        private void button11_Click(object sender, EventArgs e)
        {
            Color col = new Color();
            if (this.colorDialog1.ShowDialog() == DialogResult.OK)
            {
                col = colorDialog1.Color;
            }
            button11.ForeColor = col;
        }

        private void button12_Click(object sender, EventArgs e)//文本样式
        {
            FontDialog fontdia;
            if (this.fontDialog1.ShowDialog() == DialogResult.OK)
            {
                fontdia = fontDialog1;
                textBox9.Text = fontdia.Font.Name;
                checkBox1.Checked = fontdia.Font.Bold;
                checkBox2.Checked = fontdia.Font.Italic;
                checkBox3.Checked = fontdia.Font.Underline;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            bl = false;
            this.Close();
        }
    }
}
