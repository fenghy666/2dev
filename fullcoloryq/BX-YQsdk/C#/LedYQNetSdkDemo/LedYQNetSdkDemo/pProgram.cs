using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

using System.Collections;

namespace LedYQNetSdkDemo
{
    public partial class pProgram : Form
    {
        //public List<LedNetSdkDemo.Program> mProgram = new List<LedNetSdkDemo.Program>();
        public LedNetSdkDemo.Program program = new LedNetSdkDemo.Program();
        public List<LedNetSdkDemo.PicArea> picArea = new List<LedNetSdkDemo.PicArea>();
        LedNetSdkDemo.PicArea pA = new LedNetSdkDemo.PicArea();
        public bool Tprogram = false;
        public pProgram(LedNetSdkDemo.Program P)
        {
            program = P;
            InitializeComponent();
            textBox1.Text = Convert.ToString(P.m_w);
            textBox2.Text = Convert.ToString(P.m_h);
            if (program.m_play_mode == 0)
            {
                radioButton1.Checked = true;
                textBox3.Text = program.m_play_time.ToString();
            }
            else 
            {
                radioButton2.Checked = true;
                textBox4.Text = program.m_play_time.ToString();
            }
            if (program.m_bDate == true) 
            {
                checkBox1.Checked = true;
                dateTimePicker1.Text = System.Text.Encoding.Unicode.GetString(program.m_aging_start_time);
                dateTimePicker2.Text = System.Text.Encoding.Unicode.GetString(program.m_aging_stop_time);
            }
            if (program.m_bTime == true)
            {
                checkBox2.Checked = true;
                dateTimePicker4.Text = System.Text.Encoding.Unicode.GetString(program.m_period_ontime);
                dateTimePicker3.Text = System.Text.Encoding.Unicode.GetString(program.m_period_offtime);
            }
            byte[] b = BitConverter.GetBytes(program.m_play_week);
            BitArray arr = new BitArray(b);
            if (arr[0] == true) { checkBox3.Checked = true; } else { checkBox3.Checked = false; }
            if (arr[1] == true) { checkBox4.Checked = true; } else { checkBox4.Checked = false; }
            if (arr[2] == true) { checkBox5.Checked = true; } else { checkBox5.Checked = false; }
            if (arr[3] == true) { checkBox6.Checked = true; } else { checkBox6.Checked = false; }
            if (arr[4] == true) { checkBox7.Checked = true; } else { checkBox7.Checked = false; }
            if (arr[5] == true) { checkBox8.Checked = true; } else { checkBox8.Checked = false; }
            if (arr[6] == true) { checkBox9.Checked = true; } else { checkBox9.Checked = false; }
            pA.m_x = 0;
            pA.m_y = 0;
            pA.m_w = P.m_w;
            pA.m_h = P.m_h;
            pA.m_transparency = false;
            pA.m_bBgTransparent = 100;
            #region
            //时间
            pA.m_Time_Area.timediff_flag = 0;//0-正时差，1-负
            pA.m_Time_Area.timediff_hour = 0;//时差的小时部分
            pA.m_Time_Area.timediff_min = 0;//时差的分钟部分
            pA.m_Time_Area.font = "宋体";//时间区文本字体
            pA.m_Time_Area.fontsize = 12;//字体大小
            pA.m_Time_Area.bold = false;//是否加粗
            pA.m_Time_Area.italic = false;//是否斜体
            pA.m_Time_Area.underline = false;//是否下划线
            pA.m_Time_Area.align = 1;//对齐方式，0-左对齐，1-
            pA.m_Time_Area.multiline = true;//是否多行
            pA.m_Time_Area.day_enable = true;//是否使能显示日期
            pA.m_Time_Area.daycolor = 0xFFFF0000;//日期的颜色
            pA.m_Time_Area.week_enable = true;//是否显示星期
            pA.m_Time_Area.weekcolor = 0xFFFF0000;//星期颜色
            pA.m_Time_Area.time_enable = true;//是否显示时间
            pA.m_Time_Area.timecolor = 0xFFFF0000;//时间颜色
            pA.m_Time_Area.text_enable = false;//是否添加自定义文
            pA.m_Time_Area.textcolor = 0xFFFF0000;//自定义文本颜色
            pA.m_Time_Area.statictext = new byte[0];//自定义文本内容
            //表盘
            pA.m_Clock_Area.text_enable = false;//是否添加自定义文本
            pA.m_Clock_Area.textcolor = 0xFFFF0000;//自定义文本颜色
            pA.m_Clock_Area.statictex = new byte[0];//自定义文本内容
            pA.m_Clock_Area.text_font = "宋体";//文本字体
            pA.m_Clock_Area.text_fontsize = 12;//字体大小
            pA.m_Clock_Area.text_bold = false;//是否加粗
            pA.m_Clock_Area.text_italic = false;//是否斜体
            pA.m_Clock_Area.text_underline = false;//是否下划线
            pA.m_Clock_Area.ymd_enable = true;//是否显示年月日
            pA.m_Clock_Area.ymdcolor = 0x00FFFF00;//年月日颜色
            pA.m_Clock_Area.week_enable = true;//是否显示星期
            pA.m_Clock_Area.weekcolor = 0x00FFFF00;//星期颜色
            pA.m_Clock_Area.hourhand_color = 0xFFFF0000;//时针颜色
            pA.m_Clock_Area.minhand_color = 0x00FFFF00;//分针颜色
            pA.m_Clock_Area.secondhand_color = 0x0000FFFF;//秒针颜色
            pA.m_Clock_Area.timediff_flag = 0;//0-正时差，1-负时差，
            pA.m_Clock_Area.timediff_hour = 0;//时差的小时部分
            pA.m_Clock_Area.timediff_min = 0;//时差的分钟部分
            pA.m_Clock_Area.rightangle_color = 0x0000FFFF;//时点颜色
            pA.m_Clock_Area.integral_color = 0xFFFF0000;//369点颜色
            pA.m_Clock_Area.minute_color = 0x00FFFF00;//分点颜色
            pA.m_Clock_Area.dwClockFormat = 0;//表盘风格，0-线形;1-点形;2-方形;3-数字;4-罗马
            //农历
            pA.m_Lun_Area.text_font = "宋体";//文本字体
            pA.m_Lun_Area.text_fontsize = 12;//字体大小
            pA.m_Lun_Area.text_bold = false;//是否加粗
            pA.m_Lun_Area.text_italic = false;//是否斜体
            pA.m_Lun_Area.text_underline = false;//是否下划线
            pA.m_Lun_Area.align = 1;//对齐方式，0-左对齐，1-居
            pA.m_Lun_Area.multiline = true;//是否多行
            pA.m_Lun_Area.year_enable = true;//是否使能显示农历
            pA.m_Lun_Area.yearcolor = 0x0000FFFF;//农历的颜色
            pA.m_Lun_Area.day_enable = true;//是否使能显示天干
            pA.m_Lun_Area.daycolor = 0xFFFF0000;//天干的颜色
            pA.m_Lun_Area.solarterms_enable = true;//是否使能显
            pA.m_Lun_Area.solartermscolor = 0x00FFFF00;//节气的颜色
            pA.m_Lun_Area.text_enable = false;//是否添加自定义文
            pA.m_Lun_Area.textcolor = 0xFFFF0000;//自定义文本颜色
            pA.m_Lun_Area.statictext = new byte[0];//自定义文本内容
            //计时
            pA.m_Counter_Area.font = "宋体";//计时区文本字体
            pA.m_Counter_Area.fontsize = 12;//字体大小
            pA.m_Counter_Area.bold = false;//是否加粗
            pA.m_Counter_Area.italic = false;//是否斜体
            pA.m_Counter_Area.underline = false;//是否下划线
            pA.m_Counter_Area.align = 1;//对齐方式，0-左对齐，1-居中对齐，2-右对齐
            pA.m_Counter_Area.multiline = true;//是否多行
            pA.m_Counter_Area.bTimeFlag = true;//0-倒计时，1-正计时
            pA.m_Counter_Area.counter_color = 0xFFFF0000;//计时器文本对应的颜色
            pA.m_Counter_Area.day_enable = true;//是否显示天
            pA.m_Counter_Area.hour_enable = true;//是否显示小时
            pA.m_Counter_Area.min_enable = true;//是否显示分钟
            pA.m_Counter_Area.sec_enable = true;//是否显示秒
            pA.m_Counter_Area.add_enable = true;//是否计时累计
            pA.m_Counter_Area.text_enable = false;//是否添加自定义文本
            pA.m_Counter_Area.textcolor = 0xFFFF0000;//自定义文本颜色
            pA.m_Counter_Area.statictext = new byte[0];//自定义文本内容
            #endregion
            if (program.m_PicArea != null) 
            {
                picArea = program.m_PicArea.ToList();
                for (int i = 0; i < program.m_PicArea.Length; i++) 
                {
                    switch (picArea[i].thing)
                    {
                        case 0:
                            dataGridView1.Rows.Add(new object[] { "区域" + (i + 1), "图文" });
                            break;
                        case 1:
                            dataGridView1.Rows.Add(new object[] { "区域" + (i + 1), "视频" });
                            break;
                        case 2:
                            dataGridView1.Rows.Add(new object[] { "区域" + (i + 1), "字幕" });
                            break;
                        case 3:
                            dataGridView1.Rows.Add(new object[] { "区域" + (i + 1), "时间" });
                            break;
                        case 4:
                            dataGridView1.Rows.Add(new object[] { "区域" + (i + 1), "表盘" });
                            break;
                        case 5:
                            dataGridView1.Rows.Add(new object[] { "区域" + (i + 1), "计时" });
                            break;
                        case 6:
                            dataGridView1.Rows.Add(new object[] { "区域" + (i + 1), "图文" });
                            break;
                    }
                }
            }
        }

        private void button9_Click(object sender, EventArgs e)//确定
        {
            if (radioButton1.Checked == true)
            {
                program.m_play_mode = 0;
                program.m_play_time = int.Parse(textBox3.Text);
            }
            else if (radioButton2.Checked == true)
            {
                program.m_play_mode = 1;
                program.m_play_time = int.Parse(textBox4.Text);
            }
            //日期
            if (checkBox1.Checked == true)
            {
                program.m_bDate = true;
                program.m_aging_start_time = System.Text.Encoding.Unicode.GetBytes(dateTimePicker1.Text);
                program.m_aging_stop_time = System.Text.Encoding.Unicode.GetBytes(dateTimePicker2.Text);
            }
            else
            {
                program.m_bDate = false;
                program.m_aging_start_time = new byte[0];
                program.m_aging_stop_time = new byte[0];
            }
            //时段
            if (checkBox2.Checked == true)
            {
                program.m_bTime = true;
                program.m_period_ontime = System.Text.Encoding.Unicode.GetBytes(dateTimePicker4.Text);
                program.m_period_offtime = System.Text.Encoding.Unicode.GetBytes(dateTimePicker3.Text);
            }
            else
            {
                program.m_bTime = false;
                program.m_period_ontime = new byte[0];
                program.m_period_offtime = new byte[0];
            }
            //星期
            #region
            int index;
            bool flag;
            byte BIT = 0;
            if (checkBox3.Checked == true)
            {
                index = 1;
                flag = true;
                BIT = set_bit(BIT, index, flag);
            }
            else
            {
                index = 1;
                flag = false;
                BIT = set_bit(BIT, index, flag);
            }
            if (checkBox4.Checked == true)
            {
                index = 2;
                flag = true;
                BIT = set_bit(BIT, index, flag);
            }
            else
            {
                index = 2;
                flag = false;
                BIT = set_bit(BIT, index, flag);
            }
            if (checkBox5.Checked == true)
            {
                index = 3;
                flag = true;
                BIT = set_bit(BIT, index, flag);
            }
            else
            {
                index = 3;
                flag = false;
                BIT = set_bit(BIT, index, flag);
            }
            if (checkBox6.Checked == true)
            {
                index = 4;
                flag = true;
                BIT = set_bit(BIT, index, flag);
            }
            else
            {
                index = 4;
                flag = false;
                BIT = set_bit(BIT, index, flag);
            }
            if (checkBox7.Checked == true)
            {
                index = 5;
                flag = true;
                BIT = set_bit(BIT, index, flag);
            }
            else
            {
                index = 5;
                flag = false;
                BIT = set_bit(BIT, index, flag);
            }
            if (checkBox8.Checked == true)
            {
                index = 6;
                flag = true;
                BIT = set_bit(BIT, index, flag);
            }
            else
            {
                index = 6;
                flag = false;
                BIT = set_bit(BIT, index, flag);
            }
            if (checkBox9.Checked == true)
            {
                index = 7;
                flag = true;
                BIT = set_bit(BIT, index, flag);
            }
            else
            {
                index = 7;
                flag = false;
                BIT = set_bit(BIT, index, flag);
            }
            program.m_play_week = BIT;
            #endregion
            program.m_PicArea = picArea.ToArray();
            Tprogram = true;
            this.Close();
        }
        byte set_bit(byte data, int index, bool flag)
            {
                if (index > 8 || index < 1)
                    throw new ArgumentOutOfRangeException();
                int v = index < 2 ? index : (2  << (index - 2));
                return flag ? (byte)(data | v) : (byte)(data & ~v);
            }

        private void button1_Click(object sender, EventArgs e)//图文
        {
            ImageArea pIA = new ImageArea(pA);
            pIA.ShowDialog();
            bool BL = pIA.bl;
            if (BL == true)
            {
                picArea.Add(pIA.picArea);
                int num = picArea.Count;
                dataGridView1.Rows.Add(new object[] { "区域"+num,"图文"});
            }
        }

        private void button2_Click(object sender, EventArgs e)//视频
        {
            VideoAera pVA = new VideoAera(pA);
            pVA.ShowDialog();
            bool BL = pVA.bl;
            if (BL == true)
            {
                picArea.Add(pVA.picArea);
                int num = picArea.Count;
                dataGridView1.Rows.Add(new object[] { "区域" + num, "视频" });
            }
        }

        private void button3_Click(object sender, EventArgs e)//字幕
        {
            TextArea pTA = new TextArea(pA);
            pTA.ShowDialog();
            bool BL = pTA.bl;
            if (BL == true)
            {
                picArea.Add(pTA.picArea);
                int num = picArea.Count;
                dataGridView1.Rows.Add(new object[] { "区域" + num, "字幕" });
            }
        }

        private void button4_Click(object sender, EventArgs e)//时间
        {
            TimeArea pTiA = new TimeArea(pA);
            pTiA.ShowDialog();
            bool BL = pTiA.bl;
            if (BL == true)
            {
                picArea.Add(pTiA.picArea);
                int num = picArea.Count;
                dataGridView1.Rows.Add(new object[] { "区域" + num, "时间" });
            }
        }

        private void button5_Click(object sender, EventArgs e)//表盘
        {
            ClockArea pCA = new ClockArea(pA);
            pCA.ShowDialog();
            bool BL = pCA.bl;
            if (BL == true)
            {
                picArea.Add(pCA.picArea);
                int num = picArea.Count;
                dataGridView1.Rows.Add(new object[] { "区域" + num, "表盘" });
            }
        }

        private void button6_Click(object sender, EventArgs e)//农历
        {
            LunArea pLA = new LunArea(pA);
            pLA.ShowDialog();
            bool BL = pLA.bl;
            if (BL == true)
            {
                picArea.Add(pLA.picArea);
                int num = picArea.Count;
                dataGridView1.Rows.Add(new object[] { "区域" + num, "农历" });
            }
        }

        private void button7_Click(object sender, EventArgs e)//计时
        {
            CounterArea pCoA = new CounterArea(pA);
            pCoA.ShowDialog();
            bool BL = pCoA.bl;
            if (BL == true)
            {
                picArea.Add(pCoA.picArea);
                int num = picArea.Count;
                dataGridView1.Rows.Add(new object[] { "区域" + num, "计时" });
            }
        }

        private void button8_Click(object sender, EventArgs e)//删除
        {
            int index = dataGridView1.CurrentCell.RowIndex;
            if (index != -1)
            {
                picArea.RemoveAt(index);
            }
            //移出选择的项 
            foreach (DataGridViewRow r in dataGridView1.SelectedRows)
            {
                if (!r.IsNewRow)
                {
                    dataGridView1.Rows.Remove(r);
                }
            }
        }

        private void button10_Click(object sender, EventArgs e)//取消
        {
            Tprogram = false;
            this.Close();
        }

        private void dataGridView1_MouseDoubleClick(object sender, MouseEventArgs e)
        {
            int index = dataGridView1.CurrentCell.RowIndex;
            LedNetSdkDemo.PicArea chose_pA = picArea[index];
            bool BL;
            switch (picArea[index].thing) 
            {
                case 0:
                    ImageArea pIA = new ImageArea(chose_pA);
                    pIA.ShowDialog();
                    BL = pIA.bl;
                    if (BL == true)
                    {
                        picArea[index]=pIA.picArea;
                    }
                    break;
                case 1:
                    VideoAera pVA = new VideoAera(chose_pA);
                    pVA.ShowDialog();
                    BL = pVA.bl;
                    if (BL == true)
                    {
                        picArea[index] = pVA.picArea;
                    }
                    break;
                case 2:
                    TextArea pTA = new TextArea(chose_pA);
                    pTA.ShowDialog();
                    BL = pTA.bl;
                    if (BL == true)
                    {
                        picArea[index] = pTA.picArea;
                    }
                    break;
                case 3:
                    TimeArea pTiA = new TimeArea(chose_pA);
                    pTiA.ShowDialog();
                    BL = pTiA.bl;
                    if (BL == true)
                    {
                        picArea[index] = pTiA.picArea;
                    }
                    break;
                case 4:
                    ClockArea pCA = new ClockArea(chose_pA);
                    pCA.ShowDialog();
                    BL = pCA.bl;
                    if (BL == true)
                    {
                        picArea[index] = pCA.picArea;
                    }
                    break;
                case 5: 
                    LunArea pLA = new LunArea(chose_pA);
                    pLA.ShowDialog();
                    BL = pLA.bl;
                    if (BL == true)
                    {
                        picArea[index] = pLA.picArea;
                    }
                    break;
                case 6:
                    CounterArea pCoA = new CounterArea(chose_pA);
                    pCoA.ShowDialog();
                    BL = pCoA.bl;
                    if (BL == true)
                    {
                        picArea[index] = pCoA.picArea;
                    }
                    break;
            }
        }
    }
}
