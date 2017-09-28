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
    public partial class PlayList : Form
    {
        public List<LedNetSdkDemo.Program> ProGram = new List<LedNetSdkDemo.Program>();
        LedNetSdkDemo.Program[] proGram;
        int card_mode;
        string ip;
        byte[] PID;
        uint m_hSend;
        public PlayList(string ip)
        {
            card_mode = 0;
            this.ip = ip;
            InitializeComponent();
            button6.Enabled = false;
            comboBox1.SelectedIndex = 1;
            string str = Application.StartupPath;
            textBox1.Text = str;
        }
        public PlayList(byte[] pid)
        {
            card_mode = 1;
            PID = pid;
            InitializeComponent();
            button6.Enabled = false;
            comboBox1.SelectedIndex = 1;
            string str = Application.StartupPath;
            textBox1.Text = str;
        }

        private void button1_Click(object sender, EventArgs e)//添加节目
        {
            short w = 0;
            short h = 0;
            ushort type = 0;
            if (card_mode == 0)
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_GetScreeninfo(ip, ref type, ref w, ref h);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
            else 
            {
                int err = LedYQServerAPI.LedYQserver.Server_GetScreeninfo(PID, ref type, ref w, ref h);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
            LedNetSdkDemo.Program P = new LedNetSdkDemo.Program();
            P.m_w = w;
            P.m_h = h;
            P.m_play_mode = 1;
            P.m_play_time = 1;
            P.m_bDate = false;
            P.m_aging_start_time = new byte[0];
            P.m_aging_stop_time = new byte[0];
            P.m_bTime = false;
            P.m_period_ontime = new byte[0];
            P.m_period_offtime = new byte[0];
            P.m_play_week = 127;
            pProgram ppP = new pProgram(P);
            ppP.ShowDialog();
            bool tprogram = ppP.Tprogram;
            if (tprogram == true)
            {
                ProGram.Add(ppP.program);
                proGram = ProGram.ToArray();
                int num = ProGram.Count;
                listBox1.Items.Add(num);
            }
        }

        private void button2_Click(object sender, EventArgs e)//编辑节目
        {
            int index = listBox1.SelectedIndex;
            if (index != -1)
            {
                LedNetSdkDemo.Program chose_P= ProGram[index];
                pProgram ppP = new pProgram(chose_P);
                ppP.ShowDialog();
                bool tprogram = ppP.Tprogram;
                if (tprogram == true)
                {
                    ProGram[index] = ppP.program;
                    proGram = ProGram.ToArray();
                }
            }
            else { MessageBox.Show("请选择节目!"); }
        }

        private void button3_Click(object sender, EventArgs e)//删除节目
        {
            int index = listBox1.SelectedIndex;
            if (index != -1)
            {
                ProGram.RemoveAt(index);
                proGram = ProGram.ToArray();
                //移出选择的项
                listBox1.Items.Remove(listBox1.SelectedItem);
            }
            else { MessageBox.Show("请选择节目!"); }
        }

        private void button4_Click(object sender, EventArgs e)//浏览
        {
            FolderBrowserDialog dialog = new FolderBrowserDialog();
            if (dialog.ShowDialog() == DialogResult.OK)
            {
                textBox1.Text = dialog.SelectedPath;           
            }
        }

        private void button5_Click(object sender, EventArgs e)//发送界目
        {
            //列表
            uint hPlaylist = LedYQNetSdkDemo.LedProgram.YQ_CreatePlaylist();
            for (int a = 0; a < proGram.Length; a++)
            {
                //节目
                uint hProgram = LedYQNetSdkDemo.LedProgram.YQ_CreateProgram(proGram[a].m_w, proGram[a].m_h);
                for (int b = 0; b < proGram[a].m_PicArea.Length; b++)
                {
                    switch (proGram[a].m_PicArea[b].thing)
                    {
                        case 0:
                            {
                                LedNetSdkDemo.PicArea picArea = proGram[a].m_PicArea[b];
                                uint hArea = LedYQNetSdkDemo.LedProgram.YQ_CreatePicArea(picArea.m_x, picArea.m_y, picArea.m_w, picArea.m_h,
                                        picArea.m_bBgTransparent, picArea.m_window_type, picArea.m_transparency);
                                for (int i = 0; i < picArea.m_ImgText.Length; i++)
                                {
                                    if (picArea.m_ImgText[i].bPic == true)
                                    {
                                        LedYQNetSdkDemo.LedProgram.YQ_PicAreaAddImageUnit(hArea, picArea.m_ImgText[i].szFile, picArea.m_ImgText[i].display_effects, picArea.m_ImgText[i].display_speed, picArea.m_ImgText[i].stay_time);
                                    }
                                    else
                                    {
                                        LedYQNetSdkDemo.LedProgram.YQ_PicAreaAddRtfUnit(hArea, picArea.m_ImgText[i].szFile, picArea.m_ImgText[i].display_effects, picArea.m_ImgText[i].display_speed, picArea.m_ImgText[i].stay_time);
                                    }
                                }
                                LedYQNetSdkDemo.LedProgram.YQ_ProgramAddArea(hProgram, hArea);
                                break;
                            }
                        case 1:
                            {
                                LedNetSdkDemo.PicArea picArea = proGram[a].m_PicArea[b];
                                uint hArea = LedYQNetSdkDemo.LedProgram.YQ_CreateVideoArea(picArea.m_x, picArea.m_y, picArea.m_w, picArea.m_h, picArea.m_bBgTransparent);
                                for (int c = 0; c < picArea.m_Video.Length; c++)
                                {
                                    LedYQNetSdkDemo.LedProgram.YQ_VideoAreaAddUnit(hArea, picArea.m_Video[c].szFile, picArea.m_Video[c].scale_mode, picArea.m_Video[c].volume);
                                }
                                LedYQNetSdkDemo.LedProgram.YQ_ProgramAddArea(hProgram, hArea);
                                break;
                            }
                        case 2:
                            {
                                LedNetSdkDemo.PicArea picArea = proGram[a].m_PicArea[b];
                                uint hArea = LedYQNetSdkDemo.LedProgram.YQ_CreatePicArea(picArea.m_x, picArea.m_y, picArea.m_w, picArea.m_h,
                                        picArea.m_bBgTransparent, picArea.m_window_type, picArea.m_transparency);
                                for (int i = 0; i < picArea.m_ImgText.Length; i++)
                                {
                                    LedYQNetSdkDemo.LedProgram.YQ_PicAreaAddRtfUnit(hArea, picArea.m_ImgText[i].szFile, picArea.m_ImgText[i].display_effects, picArea.m_ImgText[i].display_speed, picArea.m_ImgText[i].stay_time);
                                }
                                LedYQNetSdkDemo.LedProgram.YQ_ProgramAddArea(hProgram, hArea);
                                break;
                            }
                        case 3:
                            {
                                LedNetSdkDemo.PicArea picArea = proGram[a].m_PicArea[b];
                                uint hArea = LedYQNetSdkDemo.LedProgram.YQ_CreateCNTimeArea(picArea.m_x, picArea.m_y, picArea.m_w, picArea.m_h, picArea.m_bBgTransparent,
                                        picArea.m_Time_Area.timediff_flag, picArea.m_Time_Area.timediff_hour, picArea.m_Time_Area.timediff_min,
                                        picArea.m_Time_Area.font, picArea.m_Time_Area.fontsize, picArea.m_Time_Area.bold, picArea.m_Time_Area.italic, picArea.m_Time_Area.underline,
                                        picArea.m_Time_Area.align, picArea.m_Time_Area.multiline,
                                        picArea.m_Time_Area.day_enable, picArea.m_Time_Area.daycolor,
                                        picArea.m_Time_Area.week_enable, picArea.m_Time_Area.weekcolor,
                                        picArea.m_Time_Area.time_enable, picArea.m_Time_Area.timecolor,
                                        picArea.m_Time_Area.text_enable, picArea.m_Time_Area.textcolor, picArea.m_Time_Area.statictext);
                                LedYQNetSdkDemo.LedProgram.YQ_ProgramAddArea(hProgram, hArea);
                                break;
                            }
                        case 4:
                            {
                                LedNetSdkDemo.PicArea picArea = proGram[a].m_PicArea[b];
                                uint hArea = LedYQNetSdkDemo.LedProgram.YQ_CreateClockStyleArea(picArea.m_x, picArea.m_y, picArea.m_w, picArea.m_h, picArea.m_bBgTransparent,
                                    picArea.m_Clock_Area.text_enable, picArea.m_Clock_Area.textcolor, picArea.m_Clock_Area.statictex,
                                    picArea.m_Clock_Area.text_font, picArea.m_Clock_Area.text_fontsize, picArea.m_Clock_Area.text_bold, picArea.m_Clock_Area.text_italic, picArea.m_Clock_Area.text_underline,
                                    picArea.m_Clock_Area.ymd_enable, picArea.m_Clock_Area.ymdcolor,
                                    picArea.m_Clock_Area.week_enable, picArea.m_Clock_Area.weekcolor,
                                    picArea.m_Clock_Area.hourhand_color, picArea.m_Clock_Area.minhand_color, picArea.m_Clock_Area.secondhand_color,
                                    picArea.m_Clock_Area.timediff_flag, picArea.m_Clock_Area.timediff_hour, picArea.m_Clock_Area.timediff_min,
                                    picArea.m_Clock_Area.rightangle_color, picArea.m_Clock_Area.integral_color, picArea.m_Clock_Area.minute_color, picArea.m_Clock_Area.dwClockFormat);
                                LedYQNetSdkDemo.LedProgram.YQ_ProgramAddArea(hProgram, hArea);
                                break;
                            }
                        case 5:
                            {
                                LedNetSdkDemo.PicArea picArea = proGram[a].m_PicArea[b];
                                uint hArea = LedYQNetSdkDemo.LedProgram.YQ_CreateLunarArea(picArea.m_x, picArea.m_y, picArea.m_w, picArea.m_h, picArea.m_bBgTransparent,
                                picArea.m_Lun_Area.text_font, picArea.m_Lun_Area.text_fontsize, picArea.m_Lun_Area.text_bold, picArea.m_Lun_Area.text_italic, picArea.m_Lun_Area.text_underline,
                                picArea.m_Lun_Area.align, picArea.m_Lun_Area.multiline, picArea.m_Lun_Area.year_enable, picArea.m_Lun_Area.yearcolor,
                                picArea.m_Lun_Area.day_enable, picArea.m_Lun_Area.daycolor, picArea.m_Lun_Area.solarterms_enable, picArea.m_Lun_Area.solartermscolor,
                                picArea.m_Lun_Area.text_enable, picArea.m_Lun_Area.textcolor, picArea.m_Lun_Area.statictext);
                                LedYQNetSdkDemo.LedProgram.YQ_ProgramAddArea(hProgram, hArea);
                                break;
                            }
                        case 6:
                            {
                                LedNetSdkDemo.PicArea picArea = proGram[a].m_PicArea[b];
                                uint hArea = LedYQNetSdkDemo.LedProgram.YQ_CreateTimeCounterArea(picArea.m_x, picArea.m_y, picArea.m_w, picArea.m_h, picArea.m_bBgTransparent,
                                picArea.m_Counter_Area.font, picArea.m_Counter_Area.fontsize, picArea.m_Counter_Area.bold, picArea.m_Counter_Area.italic, picArea.m_Counter_Area.underline,
                                picArea.m_Counter_Area.align, picArea.m_Counter_Area.multiline,
                                picArea.m_Counter_Area.target_date, picArea.m_Counter_Area.target_time, picArea.m_Counter_Area.bTimeFlag, picArea.m_Counter_Area.counter_color,
                                picArea.m_Counter_Area.day_enable, picArea.m_Counter_Area.daytext, picArea.m_Counter_Area.hour_enable, picArea.m_Counter_Area.hourtext,
                                picArea.m_Counter_Area.min_enable, picArea.m_Counter_Area.minutetext, picArea.m_Counter_Area.sec_enable, picArea.m_Counter_Area.secondtext,
                                picArea.m_Counter_Area.add_enable, picArea.m_Counter_Area.unit_enable,
                                picArea.m_Counter_Area.text_enable, picArea.m_Counter_Area.textcolor, picArea.m_Counter_Area.statictext);
                                LedYQNetSdkDemo.LedProgram.YQ_ProgramAddArea(hProgram, hArea);
                                break;
                            }
                    }
                }
                LedYQNetSdkDemo.LedProgram.YQ_PlaylistAddProgram(hPlaylist, hProgram, proGram[a].m_play_mode, proGram[a].m_play_time,
                            proGram[a].m_aging_start_time, proGram[a].m_aging_stop_time, proGram[a].m_period_ontime, proGram[a].m_period_offtime, proGram[a].m_play_week);
            }

            int pErr = 0;
            byte media = (byte)comboBox1.SelectedIndex;
            byte[] szLocalTempDir = System.Text.Encoding.Unicode.GetBytes(textBox1.Text);

            uint A = 0;
            if (card_mode == 0)
            {
                A = LedYQNetSDKAPI.LedYQNetSdk.Net_SendPrograms(ip, media, hPlaylist, szLocalTempDir, ref pErr);
            }
            else
            {
                A = LedYQServerAPI.LedYQserver.Server_SendPrograms(PID, media, hPlaylist, szLocalTempDir, server_ftp.ftp_server_ip,
                        server_ftp.ftp_server_port, server_ftp.ftp_server_pwd, server_ftp.ftp_server_user, ref pErr);
            }
            if (pErr == 0)
            {
                m_hSend = A;
                timer1.Enabled = true;
                button5.Enabled = false;
                button6.Enabled = true;
            }
            else { LedYQNetSDKAPI.LedYQNetSdk.GetError(pErr); }
            LedYQNetSdkDemo.LedProgram.YQ_DestroyPlaylist(hPlaylist);
        }

        private void button6_Click(object sender, EventArgs e)//停止发送
        {
            timer1.Enabled = false;
            if (card_mode == 0)
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_CancelSend(m_hSend);
                if (err != 0) { LedYQNetSDKAPI.LedYQNetSdk.GetError(err); }
            }
            else 
            {
                int err = LedYQServerAPI.LedYQserver.Server_CancelSend(m_hSend);
                if (err != 0) { LedYQNetSDKAPI.LedYQNetSdk.GetError(err); }
            }
            button5.Enabled = true;
            button6.Enabled = false;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (timer1.Interval == 100)
            {
                int err = 0;
                int total = 0, cur = 0;
                int down_percent = 0;
                if (card_mode == 0)
                {
                    err = LedYQNetSDKAPI.LedYQNetSdk.Net_GetSendProcess(m_hSend, ref total, ref cur);
                }
                else 
                {
                    err = LedYQServerAPI.LedYQserver.Server_GetSendProcess(m_hSend, ref total, ref cur);
                    err = LedYQServerAPI.LedYQserver.Server_GetDownProcess(m_hSend, ref down_percent);
                }
                if (err == 0)
                {
                    progressBar1.Value = total;
                    progressBar2.Value = cur;
                    progressBar3.Value = down_percent;
                }
                else 
                {
                    timer1.Enabled = false;
                    if (err == LedYQNetSDKAPI.LedYQNetSdk.bxyq_err.ERR_SENDHAND)
                    {
                        MessageBox.Show("发送完成！");
                    }
                    else { LedYQNetSDKAPI.LedYQNetSdk.GetError(err); }
                    button5.Enabled = true;
                    button6.Enabled = false;
                }
            }
            
        }
    }
}
