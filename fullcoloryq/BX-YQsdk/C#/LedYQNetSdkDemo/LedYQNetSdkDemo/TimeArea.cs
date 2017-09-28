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
    public partial class TimeArea : Form
    {
        public LedNetSdkDemo.PicArea picArea = new LedNetSdkDemo.PicArea();
        public List<LedNetSdkDemo.Time_Area> mTime = new List<LedNetSdkDemo.Time_Area>();
        public bool bl = false;
        public TimeArea(LedNetSdkDemo.PicArea PicArea)
        {
            picArea = PicArea;
            InitializeComponent();
            textBox1.Text = Convert.ToString(picArea.m_x);
            textBox2.Text = Convert.ToString(picArea.m_y);
            textBox3.Text = Convert.ToString(picArea.m_w);
            textBox4.Text = Convert.ToString(picArea.m_h);
            trackBar1.Value = picArea.m_bBgTransparent;
            comboBox1.SelectedIndex = picArea.m_Time_Area.timediff_flag;
            textBox5.Text = picArea.m_Time_Area.timediff_hour.ToString();
            textBox6.Text = picArea.m_Time_Area.timediff_min.ToString();
            if (picArea.m_Time_Area.multiline == true)
            {
                radioButton2.Checked = true;
            }
            else { radioButton1.Checked = true; }
            textBox9.Text = picArea.m_Time_Area.font;
            textBox7.Text = picArea.m_Time_Area.fontsize.ToString();
            if (picArea.m_Time_Area.bold == false)
            {
                checkBox1.Checked = false;
            }
            else { checkBox1.Checked = true; }
            if (picArea.m_Time_Area.italic == false)
            {
                checkBox2.Checked = false;
            }
            else { checkBox2.Checked = true; }
            if (picArea.m_Time_Area.underline == false)
            {
                checkBox3.Checked = false;
            }
            else { checkBox3.Checked = true; }
            comboBox3.SelectedIndex = picArea.m_Time_Area.align;
            if (picArea.m_Time_Area.day_enable == false)
            {
                checkBox4.Checked = false;
            }
            else { checkBox4.Checked = true; }
            button4.ForeColor = Color.FromArgb((int)picArea.m_Time_Area.daycolor);
            if (picArea.m_Time_Area.week_enable == false)
            {
                checkBox5.Checked = false;
            }
            else { checkBox5.Checked = true; }
            button5.ForeColor = Color.FromArgb((int)picArea.m_Time_Area.weekcolor);
            if (picArea.m_Time_Area.time_enable == false)
            {
                checkBox6.Checked = false;
            }
            else { checkBox6.Checked = true; }
            button6.ForeColor = Color.FromArgb((int)picArea.m_Time_Area.timecolor);
            if (picArea.m_Time_Area.text_enable == false)
            {
                checkBox7.Checked = false;
            }
            else { checkBox7.Checked = true; }
            textBox8.Text = System.Text.Encoding.Unicode.GetString(picArea.m_Time_Area.statictext);
            button7.ForeColor = Color.FromArgb((int)picArea.m_Time_Area.textcolor);
            
        }

        private void button1_Click(object sender, EventArgs e)//确定
        {
            picArea.thing = 3;
            bl = true;
            picArea.m_x = Convert.ToInt16(textBox1.Text);
            picArea.m_y = Convert.ToInt16(textBox2.Text);
            picArea.m_w = Convert.ToInt16(textBox3.Text);
            picArea.m_h = Convert.ToInt16(textBox4.Text);
            picArea.m_bBgTransparent = (byte)trackBar1.Value;

            LedNetSdkDemo.Time_Area mtimearea = new LedNetSdkDemo.Time_Area();
            //是否多行
            if (radioButton2.Checked == true)
            {
                mtimearea.multiline = true;
            }
            if (radioButton1.Checked == true)
            {
                mtimearea.multiline = false;
            }
            //是否使能显示日期
            if (checkBox4.Checked == true)
            {
                mtimearea.day_enable = true;
                mtimearea.daycolor = (uint)button4.ForeColor.ToArgb();
            }
            else
            {
                mtimearea.day_enable = false;
                mtimearea.daycolor = (uint)button4.ForeColor.ToArgb();
            }
            //是否显示星期
            if (checkBox5.Checked == true)
            {
                mtimearea.week_enable = true;
                mtimearea.weekcolor = (uint)button5.ForeColor.ToArgb();
            }
            else
            {
                mtimearea.week_enable = false;
                mtimearea.weekcolor = (uint)button5.ForeColor.ToArgb();
            }
            //是否显示时间
            if (checkBox6.Checked == true)
            {
                mtimearea.time_enable = true;
                mtimearea.timecolor = (uint)button6.ForeColor.ToArgb();
            }
            else
            {
                mtimearea.time_enable = false;
                mtimearea.timecolor = (uint)button6.ForeColor.ToArgb();
            }
            if (checkBox7.Checked == true)
            {
                mtimearea.text_enable = true;//是否添加自定义文本
            }
            else
            {
                mtimearea.text_enable = false;//是否添加自定义文本
            }
            mtimearea.textcolor = (uint)button7.ForeColor.ToArgb();//自定义文本颜色
            mtimearea.statictext = System.Text.Encoding.Unicode.GetBytes(textBox8.Text);//自定义文本内容

            mtimearea.timediff_flag = comboBox1.SelectedIndex;//0-正时差，1-负
            mtimearea.timediff_hour = int.Parse(textBox5.Text);//时差的小时部分
            mtimearea.timediff_min = int.Parse(textBox6.Text);//时差的分钟部分

            mtimearea.font = textBox9.Text;//文本字体
            mtimearea.fontsize = uint.Parse(textBox7.Text);//字体大小
            mtimearea.bold = checkBox1.Checked;//是否加粗
            mtimearea.italic = checkBox2.Checked;//是否斜体
            mtimearea.underline = checkBox3.Checked;//是否下划线
            mtimearea.align = comboBox3.SelectedIndex;//对齐方式，0-左对齐，1-居中对齐，2-右对齐

            picArea.m_Time_Area = mtimearea;
            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            bl = false;
            this.Close();
        }

        private void button3_Click(object sender, EventArgs e)
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

        private void button4_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                button4.ForeColor = col.Color;
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

        private void button6_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                button6.ForeColor = col.Color;
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            ColorDialog col = new ColorDialog();
            if (col.ShowDialog() == DialogResult.OK)
            {
                button7.ForeColor = col.Color;
            }
        }
    }
}
