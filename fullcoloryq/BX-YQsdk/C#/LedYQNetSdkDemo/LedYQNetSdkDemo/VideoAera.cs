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
    public partial class VideoAera : Form
    {
        public LedNetSdkDemo.PicArea picArea = new LedNetSdkDemo.PicArea();
        public List<LedNetSdkDemo.Video> video = new List<LedNetSdkDemo.Video>();
        public bool bl = false;
        public VideoAera(LedNetSdkDemo.PicArea PicArea)
        {
            picArea = PicArea;
            InitializeComponent();
            textBox1.Text = Convert.ToString(picArea.m_x);
            textBox2.Text = Convert.ToString(picArea.m_y);
            textBox3.Text = Convert.ToString(picArea.m_w);
            textBox4.Text = Convert.ToString(picArea.m_h);
            if (picArea.m_Video != null)
            {
                video = picArea.m_Video.ToList();
                for (int i = 0; i < picArea.m_Video.Length; i++)
                {
                    listBox1.Items.Add(video[i].FileName);
                    comboBox1.SelectedIndex = video[i].scale_mode;
                    trackBar2.Value = video[i].volume;
                }
                listBox1.SelectedIndex = 0;
            }
        }

        private void button1_Click(object sender, EventArgs e)//添加视频
        {
            OpenFileDialog fileDialog = new OpenFileDialog();
            fileDialog.Multiselect = true;
            fileDialog.Title = "请选择文件";
            fileDialog.Filter = "视频文件(*.*)|*.mp4";
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                string file = fileDialog.FileName;
                listBox1.Items.Add(file);
                LedNetSdkDemo.Video videoes;
                videoes.FileName = file;
                videoes.szFile = System.Text.Encoding.Unicode.GetBytes(file);
                videoes.scale_mode = 1;
                videoes.volume = 50;
                video.Add(videoes);
                onbon(file);
            }
        }
        public void onbon(string szFileName)
        {
            int index = listBox1.Items.IndexOf(szFileName);
            if (listBox1.Items.Count > 0)
            {
                comboBox1.SelectedIndex = video[index].scale_mode;
                trackBar2.Value = video[index].volume;
            }
            listBox1.SelectedIndex = index;
        }

        private void button2_Click(object sender, EventArgs e)//移除
        {
            int index = listBox1.SelectedIndex;
            if (index != -1)
            {
                video.RemoveAt(index);
                //移出选择的项
                listBox1.Items.Remove(listBox1.SelectedItem);
            }
        }

        private void button3_Click(object sender, EventArgs e)//确定
        {
            picArea.thing = 1;
            bl = true;
            picArea.m_x = Convert.ToInt16(textBox1.Text);
            picArea.m_y = Convert.ToInt16(textBox2.Text);
            picArea.m_w = Convert.ToInt16(textBox3.Text);
            picArea.m_h = Convert.ToInt16(textBox4.Text);
            picArea.m_bBgTransparent = (byte)trackBar1.Value;
            picArea.m_Video = video.ToArray();
            this.Close();
        }

        private void button4_Click(object sender, EventArgs e)//取消
        {
            bl = false;
            this.Close();
        }

        private void comboBox1_SelectionChangeCommitted(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1)
            {
                LedNetSdkDemo.Video[] viode = video.ToArray();
                viode[index].scale_mode = (byte)comboBox1.SelectedIndex;
                video = viode.ToList();
            }
        }

        private void trackBar2_ValueChanged(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1)
            {
                LedNetSdkDemo.Video[] viode = video.ToArray();
                viode[index].volume = (byte)trackBar2.Value;
                video = viode.ToList();
            }
        }

        private void listBox1_MouseClick(object sender, MouseEventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1)
            {
                comboBox1.SelectedIndex = video[index].scale_mode;
                trackBar2.Value = video[index].volume;
            }
        }
    }
}
