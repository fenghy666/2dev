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
    public partial class TextArea : Form
    {
        public LedNetSdkDemo.PicArea picArea = new LedNetSdkDemo.PicArea();
        public List<LedNetSdkDemo.ImgText> pic = new List<LedNetSdkDemo.ImgText>();
        public bool bl = false;
        public TextArea(LedNetSdkDemo.PicArea PicArea)
        {
            picArea = PicArea;
            InitializeComponent();
            textBox1.Text = Convert.ToString(picArea.m_x);
            textBox2.Text = Convert.ToString(picArea.m_y);
            textBox3.Text = Convert.ToString(picArea.m_w);
            textBox4.Text = Convert.ToString(picArea.m_h);
            trackBar1.Value = picArea.m_bBgTransparent;
            if (picArea.m_transparency == true)
            {
                checkBox1.Checked = true;
            }
            else { checkBox1.Checked = false; }
            if (picArea.m_ImgText != null)
            {
                pic = picArea.m_ImgText.ToList();
                for (int i = 0; i < picArea.m_ImgText.Length; i++)
                {
                    listBox1.Items.Add(pic[i].FileName);
                    comboBox1.SelectedIndex = (int)pic[i].display_effects;
                    textBox5.Text = pic[i].display_speed.ToString();
                    textBox6.Text = pic[i].stay_time.ToString();
                }
                listBox1.SelectedIndex = 0;
            }
        }

        private void button1_Click(object sender, EventArgs e)//添加文字
        {
            string szFileName;
            OpenFileDialog fileDialog = new OpenFileDialog();
            fileDialog.Multiselect = true;
            fileDialog.Title = "请选择文件";
            fileDialog.Filter = "(*.rtf;*.doc*)|*.rtf;";
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                szFileName = fileDialog.FileName;
                listBox1.Items.Add(szFileName);
                LedNetSdkDemo.ImgText picUnit;
                picUnit.bPic = false;
                picUnit.FileName = szFileName;
                picUnit.szFile = System.Text.Encoding.Unicode.GetBytes(szFileName);
                picUnit.display_effects = 1;
                picUnit.display_speed = 1;
                picUnit.stay_time = 1;
                pic.Add(picUnit);
                onbon(szFileName);
            }
        }
        public void onbon(string szFileName)
        {
            int index = listBox1.Items.IndexOf(szFileName);
            if (listBox1.Items.Count > 0)
            {
                comboBox1.SelectedIndex = (int)pic[index].display_effects;
                textBox5.Text = pic[index].display_speed.ToString();
                textBox6.Text = pic[index].stay_time.ToString();
            }
            listBox1.SelectedIndex = index;
        }

        private void button2_Click(object sender, EventArgs e)//移除
        {
            int index = listBox1.SelectedIndex;
            if (index != -1)
            {
                pic.RemoveAt(index);
                //移出选择的项
                listBox1.Items.Remove(listBox1.SelectedItem);
            }
        }

        private void button3_Click(object sender, EventArgs e)//确定
        {
            picArea.thing = 2;
            bl = true;
            picArea.m_x = Convert.ToInt16(textBox1.Text);
            picArea.m_y = Convert.ToInt16(textBox2.Text);
            picArea.m_w = Convert.ToInt16(textBox3.Text);
            picArea.m_h = Convert.ToInt16(textBox4.Text);
            picArea.m_bBgTransparent = (byte)trackBar1.Value;
            picArea.m_window_type = 3;
            if (checkBox1.Checked == true)
            {
                picArea.m_transparency = true;
            }
            else
            {
                picArea.m_transparency = false;
            }
            picArea.m_ImgText = pic.ToArray();
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
                LedNetSdkDemo.ImgText[] picUnit = pic.ToArray();
                picUnit[index].display_effects = (byte)comboBox1.SelectedIndex;
                pic = picUnit.ToList();
            }
        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1)
            {
                LedNetSdkDemo.ImgText[] picUnit = pic.ToArray();
                picUnit[index].display_speed = Convert.ToByte(textBox5.Text);
                pic = picUnit.ToList();
            }
        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1)
            {
                LedNetSdkDemo.ImgText[] picUnit = pic.ToArray();
                picUnit[index].stay_time = Convert.ToByte(textBox6.Text);
                pic = picUnit.ToList();
            }
        }

        private void listBox1_MouseClick(object sender, MouseEventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index != -1)
            {
                comboBox1.SelectedIndex = (int)pic[index].display_effects;
                textBox5.Text = pic[index].display_speed.ToString();
                textBox6.Text = pic[index].stay_time.ToString();
            }
        }
    }
}
