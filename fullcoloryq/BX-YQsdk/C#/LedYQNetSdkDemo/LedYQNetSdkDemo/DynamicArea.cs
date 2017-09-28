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
    public partial class DynamicArea : Form
    {
        int card_mode;
        int num = 0;
        byte dataType = 0;
        string ip;
        byte[] PID;
        public DynamicArea(string ip)
        {
            card_mode = 0;
            this.ip = ip;
            InitializeComponent();
            radioButton5.Checked = true;
            textBox6.Enabled = false;
            button1.Enabled = true;
            button2.Enabled = false;
            button3.Enabled = false;
            button4.Enabled = false;
        }
        public DynamicArea(byte[] pid)
        {
            card_mode = 1;
            PID = pid;
            InitializeComponent();
            radioButton5.Checked = true;
            textBox6.Enabled = false;
            button1.Enabled = true;
            button2.Enabled = false;
            button3.Enabled = false;
            button4.Enabled = false;
        }

        public void onbon(string szFileName)
        {
            int index = listBox1.Items.IndexOf(szFileName);
            switch(num)
            {
                case 0:
                    if (listBox1.Items.Count > 0)
                    {
                        comboBox3.SelectedIndex = (int)picDT[index].display_effects;
                        textBox7.Text = picDT[index].display_speed.ToString();
                        textBox8.Text = picDT[index].stay_time.ToString();
                    }
                    break;
                case 1:
                    if (listBox1.Items.Count > 0)
                    {
                        comboBox3.SelectedIndex = (int)StrPage[index].display_effects;
                        textBox7.Text = StrPage[index].display_speed.ToString();
                        textBox8.Text = StrPage[index].stay_time.ToString();
                    }
                    break;
                case 2:
                    if (listBox1.Items.Count > 0)
                    {
                        comboBox3.SelectedIndex = (int)imgURL[index].display_effects;
                        textBox7.Text = imgURL[index].display_speed.ToString();
                        textBox8.Text = imgURL[index].stay_time.ToString();
                    }
                    break;
                case 3:
                    if (listBox1.Items.Count > 0)
                    {
                        comboBox3.SelectedIndex = (int)txtURL[index].display_effects;
                        textBox7.Text = txtURL[index].display_speed.ToString();
                        textBox8.Text = txtURL[index].stay_time.ToString();
                    }
                    break;
            }
            listBox1.SelectedIndex = index;
        }

        public List<LedNetSdkDemo.ImgText> picDT = new List<LedNetSdkDemo.ImgText>();
        LedNetSdkDemo.ImgText[] picUnitDt;
        private void button1_Click(object sender, EventArgs e)//添加图片
        {
            OpenFileDialog fileDialog = new OpenFileDialog();
            fileDialog.Filter = "*.bmp;*.jpg;*.png;|*.bmp;*.jpg;*.png;";
            string szFileName;
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
                szFileName = fileDialog.FileName;
                listBox1.Items.Add(szFileName);
                LedNetSdkDemo.ImgText picUnitDT = new LedNetSdkDemo.ImgText();
                picUnitDT.bPic = true;
                picUnitDT.FileName = szFileName;
                picUnitDT.szFile = System.Text.Encoding.Unicode.GetBytes(szFileName);
                picUnitDT.display_effects = 1;
                picUnitDT.display_speed = 1;
                picUnitDT.stay_time = 1;
                picDT.Add(picUnitDT);
                onbon(szFileName);
            }
        }

        List<LedNetSdkDemo.StrPage> StrPage = new List<LedNetSdkDemo.StrPage>();
        LedNetSdkDemo.StrPage[] m_StrPage;
        private void button2_Click(object sender, EventArgs e)//添加文字
        {
            StrPage SP = new StrPage();
            SP.ShowDialog();
            if(SP.page==true)
            {
                LedNetSdkDemo.StrPage strPage = new LedNetSdkDemo.StrPage();
                strPage.display_effects = 1;
                strPage.display_speed = 1;
                strPage.stay_time = 1;
                strPage.mDynaStrPage = SP.m_Dynastrpage;
                StrPage.Add(strPage);
                string name = "文本" + StrPage.Count.ToString();
                listBox1.Items.Add(name);
                onbon(name);
            }
        }

        List<LedNetSdkDemo.imgURL> imgURL = new List<LedNetSdkDemo.imgURL>();
        LedNetSdkDemo.imgURL[] m_imgURL;
        private void button3_Click(object sender, EventArgs e)//添加图片URL
        {
            PicRef PR = new PicRef();
            PR.ShowDialog();
            if (PR.URL == true) 
            {
                LedNetSdkDemo.imgURL mimgURL = new LedNetSdkDemo.imgURL();
                mimgURL.display_effects = 1;
                mimgURL.display_speed = 1;
                mimgURL.stay_time = 1;
                mimgURL.mimgurl = PR.m_imgurl;
                imgURL.Add(mimgURL);
                string name = "图片URL" + StrPage.Count.ToString();
                listBox1.Items.Add(name);
                onbon(name);
            }
        }

        List<LedNetSdkDemo.imgURL> txtURL = new List<LedNetSdkDemo.imgURL>();
        LedNetSdkDemo.imgURL[] m_txtURL;
        private void button4_Click(object sender, EventArgs e)//添加文字URL
        {
            StrrefPage strre = new StrrefPage();
            strre.ShowDialog();
            if(strre.page==true)
            {
                LedNetSdkDemo.imgURL mtexURL = new LedNetSdkDemo.imgURL();
                mtexURL.display_effects = 1;
                mtexURL.display_speed = 1;
                mtexURL.stay_time = 1;
                mtexURL.txturl = strre.mtexturl;
                txtURL.Add(mtexURL);
                string name = "文本URL" + StrPage.Count.ToString();
                listBox1.Items.Add(name);
                onbon(name);
            }
        }

        private void button5_Click(object sender, EventArgs e)//移除
        {
            int index = listBox1.SelectedIndex;
            switch (num)
            {
                case 0:
                    if (index != -1)
                    {
                        picDT.RemoveAt(index);
                        //移出选择的项
                        listBox1.Items.Remove(listBox1.SelectedItem);
                    }
                    break;
                case 1:
                    if (index != -1)
                    {
                        StrPage.RemoveAt(index);
                        listBox1.Items.Remove(listBox1.SelectedItem);
                    }
                    break;
                case 2:
                    if (index != -1)
                    {
                        imgURL.RemoveAt(index);
                        listBox1.Items.Remove(listBox1.SelectedItem);
                    }
                    break;
                case 3:
                    if (index != -1)
                    {
                        txtURL.RemoveAt(index);
                        listBox1.Items.Remove(listBox1.SelectedItem);
                    }
                    break;
            }
        }

        private void button6_Click(object sender, EventArgs e)//更新动态区
        {
            short x = Convert.ToInt16(textBox1.Text);
            short y = Convert.ToInt16(textBox2.Text);
            short w = Convert.ToInt16(textBox3.Text);
            short h = Convert.ToInt16(textBox4.Text);
            byte transparency = (byte)trackBar1.Value;
            byte progrmRelation = 0;
            ushort relatedProgram;
            if (checkBox1.Checked == true)
            {
                if(radioButton1.Checked == true)
                {
                    progrmRelation = 0;
                }
                else
                {
                    progrmRelation = 1;
                }
                relatedProgram = Convert.ToUInt16(textBox5.Text);
            }
            else 
            {
                relatedProgram = 0xffff;
            }
            byte runTime = 0;
            if(radioButton3.Checked == true)
            {
                runTime = 0;
            }
            if(radioButton4.Checked == true)
            {
                runTime = 1;
            }
            byte runMode = (byte)comboBox2.SelectedIndex;
            short timeout = 5;
            if(radioButton5.Checked == true)
            {
                dataType=0;
            }
            if(radioButton6.Checked == true)
            {
                dataType=1;
            }
            if(radioButton7.Checked == true)
            {
                dataType=2;
            }
            if(radioButton8.Checked == true)
            {
                dataType=3;
            }
            short uriUpdateFrequency = Convert.ToInt16(textBox6.Text);
            uint hArea = LedYQNetSdkDemo.LedProgram.YQ_CreateDynamicArea((byte)comboBox1.SelectedIndex,  x,  y,  w,  h, transparency,
             progrmRelation, relatedProgram, runTime, runMode, timeout, dataType, uriUpdateFrequency);
            switch (num) 
            {
                case 0:
                    picUnitDt = picDT.ToArray();
                    //图片
                    for(int j = 0;j < picUnitDt.Length;j++)
                    {
                        string Suffix = Path.GetExtension(picUnitDt[j].FileName);
                        FileStream file = File.OpenRead(picUnitDt[j].FileName);
                        uint imgdatalen = (uint)file.Length;
                        byte[] imgdata = new byte[imgdatalen];
                        file.Read(imgdata, 0, (int)imgdatalen); //按字节流读取 
                        file.Close();
                        LedYQNetSdkDemo.LedProgram.YQ_DynamicAreaAddPicPage(hArea, picUnitDt[j].stay_time, picUnitDt[j].display_effects, picUnitDt[j].display_speed, 
                             Suffix, imgdatalen, imgdata);
                    }
                    break;
                case 1:
                    m_StrPage = StrPage.ToArray();
                    for (int j = 0; j < m_StrPage.Length; j++) 
                    {
                        LedYQNetSdkDemo.LedProgram.YQ_DynamicAreaAddStrPage(hArea, m_StrPage[j].stay_time, m_StrPage[j].display_effects, m_StrPage[j].display_speed,
                            m_StrPage[j].mDynaStrPage.m_BgColor, m_StrPage[j].mDynaStrPage.m_LineSpace, m_StrPage[j].mDynaStrPage.m_bold, m_StrPage[j].mDynaStrPage.m_italic,
                            m_StrPage[j].mDynaStrPage.m_underline, m_StrPage[j].mDynaStrPage.m_strikeout, m_StrPage[j].mDynaStrPage.m_antialiasing,
                            m_StrPage[j].mDynaStrPage.szTxt, m_StrPage[j].mDynaStrPage.txtcolor, m_StrPage[j].mDynaStrPage.m_font, m_StrPage[j].mDynaStrPage.m_fontsize);
                    }
                    break;
                case 2:
                    m_imgURL = imgURL.ToArray();
                    for (int j = 0; j < m_imgURL.Length; j++)
                    {
                        LedYQNetSdkDemo.LedProgram.YQ_DynamicAreaAddPicRefPage( hArea, m_imgURL[j].stay_time, m_imgURL[j].display_effects, m_imgURL[j].display_speed,
                            m_imgURL[j].mimgurl.Suffix, m_imgURL[j].mimgurl.user, m_imgURL[j].mimgurl.pwd, m_imgURL[j].mimgurl.url);
                    }
                    break;
                case 3:
                    m_txtURL = txtURL.ToArray();
                    for (int j = 0; j < m_txtURL.Length; j++)
                    {
                        LedYQNetSdkDemo.LedProgram.YQ_DynamicAreaAddStrRefPage(hArea, m_txtURL[j].stay_time, m_txtURL[j].display_effects, m_txtURL[j].display_speed,
                            1, m_txtURL[j].txturl.BgColor, m_txtURL[j].txturl.LinesSizes, m_txtURL[j].txturl.user, m_txtURL[j].txturl.pwd, m_txtURL[j].txturl.url);
                    }
                    break;
            }
            if (card_mode == 0)
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_UpdateDynamicArea(ip, hArea);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
            else 
            {
                int err = LedYQServerAPI.LedYQserver.Server_UpdateDynamicArea(PID, hArea);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
            LedYQNetSdkDemo.LedProgram.YQ_DestroyDynamic(hArea);
        }

        private void button7_Click(object sender, EventArgs e)//删除动态区
        {
            if (card_mode == 0)
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_RemoveDynamicArea(ip, comboBox1.SelectedIndex);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
            else 
            {
                int err = LedYQServerAPI.LedYQserver.Server_RemoveDynamicArea(PID, comboBox1.SelectedIndex);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked == true)
            {
                textBox5.Enabled = true;
                radioButton1.Enabled = true;
                radioButton2.Enabled = true;
            }
            else 
            {
                textBox5.Enabled = false;
                radioButton1.Enabled = false;
                radioButton2.Enabled = false;
            }
        }

        private void radioButton5_CheckedChanged(object sender, EventArgs e)
        {
            if(radioButton5.Checked == true)
            {
                textBox6.Enabled = false;     
                button1.Enabled = true;
                button2.Enabled = false;
                button3.Enabled = false;
                button4.Enabled = false;
                listBox1.Items.Clear();
            }
            num = 0;
            dataType = 0;
        }

        private void radioButton6_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton6.Checked == true)
            {
                textBox6.Enabled = false;
                button1.Enabled = false;
                button2.Enabled = true;
                button3.Enabled = false;
                button4.Enabled = false;
                listBox1.Items.Clear();
            }
            num = 1;
            dataType = 1;
        }

        private void radioButton7_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton7.Checked == true)
            {
                textBox6.Enabled = true;
                button1.Enabled = false;
                button2.Enabled = false;
                button3.Enabled = true;
                button4.Enabled = false;
                listBox1.Items.Clear();
            }
            num = 2;
            dataType = 2;
        }

        private void radioButton8_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton8.Checked == true)
            {
                textBox6.Enabled = true;
                button1.Enabled = false;
                button2.Enabled = false;
                button3.Enabled = false;
                button4.Enabled = true;
                listBox1.Items.Clear();
            }
            num = 3;
            dataType = 3;
        }

        private void comboBox3_SelectionChangeCommitted(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            switch (num)
            {
                case 0:
                    if (listBox1.Items.Count > 0)
                    {
                        LedNetSdkDemo.ImgText[] picUnit = picDT.ToArray();
                        picUnit[index].display_effects = (byte)comboBox3.SelectedIndex;
                        picDT = picUnit.ToList();
                    }
                    break;
                case 1:
                    if (listBox1.Items.Count > 0)
                    {
                        LedNetSdkDemo.StrPage[] mstrpage = StrPage.ToArray();
                        mstrpage[index].display_effects = (byte)comboBox3.SelectedIndex;
                        StrPage = mstrpage.ToList();
                    }
                    break;
                case 2:
                    if (listBox1.Items.Count > 0)
                    {
                        LedNetSdkDemo.imgURL[] mimgURL = imgURL.ToArray();
                        mimgURL[index].display_effects = (byte)comboBox3.SelectedIndex;
                        imgURL = mimgURL.ToList();
                    }
                    break;
                case 3:
                    if (listBox1.Items.Count > 0)
                    {
                        LedNetSdkDemo.imgURL[] mtextURL = txtURL.ToArray();
                        mtextURL[index].display_effects = (byte)comboBox3.SelectedIndex;
                        txtURL = mtextURL.ToList();
                    }
                    break;
            }
        }

        private void textBox7_TextChanged(object sender, EventArgs e)
        { 
            int index = listBox1.SelectedIndex;
            switch (num)
            {
                case 0:
                    if (listBox1.Items.Count > 0)
                    {
                        LedNetSdkDemo.ImgText[] picUnit = picDT.ToArray();
                        picUnit[index].display_speed = Convert.ToByte(textBox7.Text);
                        picDT = picUnit.ToList();
                    }
                    break;
                case 1:
                    if (listBox1.Items.Count > 0)
                    {
                        LedNetSdkDemo.StrPage[] mstrpage = StrPage.ToArray();
                        mstrpage[index].display_speed = Convert.ToByte(textBox7.Text);
                        StrPage = mstrpage.ToList();
                    }
                    break;
                case 2:
                    if (listBox1.Items.Count > 0)
                    {
                        LedNetSdkDemo.imgURL[] mimgURL = imgURL.ToArray();
                        mimgURL[index].display_speed = Convert.ToByte(textBox7.Text);
                        imgURL = mimgURL.ToList();
                    }
                    break;
                case 3:
                    if (listBox1.Items.Count > 0)
                    {
                        LedNetSdkDemo.imgURL[] mtextURL = txtURL.ToArray();
                        mtextURL[index].display_speed = Convert.ToByte(textBox7.Text);
                        txtURL = mtextURL.ToList();
                    }
                    break;
            }
        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            switch (num)
            {
                case 0:
                    if (listBox1.Items.Count > 0)
                    {
                        LedNetSdkDemo.ImgText[] picUnit = picDT.ToArray();
                        picUnit[index].stay_time = Convert.ToByte(textBox8.Text);
                        picDT = picUnit.ToList();
                    }
                    break;
                case 1:
                    if (listBox1.Items.Count > 0)
                    {
                        LedNetSdkDemo.StrPage[] mstrpage = StrPage.ToArray();
                        mstrpage[index].stay_time = Convert.ToByte(textBox8.Text);
                        StrPage = mstrpage.ToList();
                    }
                    break;
                case 2:
                    if (listBox1.Items.Count > 0)
                    {
                        LedNetSdkDemo.imgURL[] mimgURL = imgURL.ToArray();
                        mimgURL[index].stay_time = Convert.ToByte(textBox8.Text);
                        imgURL = mimgURL.ToList();
                    }
                    break;
                case 3:
                    if (listBox1.Items.Count > 0)
                    {
                        LedNetSdkDemo.imgURL[] mtextURL = txtURL.ToArray();
                        mtextURL[index].stay_time = Convert.ToByte(textBox8.Text);
                        txtURL = mtextURL.ToList();
                    }
                    break;
            }
        }

        private void listBox1_MouseClick(object sender, MouseEventArgs e)
        {
            int index = listBox1.SelectedIndex;
            switch (num)
            {
                case 0:
                    if (listBox1.Items.Count > 0)
                    {
                        comboBox3.SelectedIndex = (int)picDT[index].display_effects;
                        textBox7.Text = picDT[index].display_speed.ToString();
                        textBox8.Text = picDT[index].stay_time.ToString();
                    }
                    break;
                case 1:
                    if (listBox1.Items.Count > 0)
                    {
                        comboBox3.SelectedIndex = (int)StrPage[index].display_effects;
                        textBox7.Text = StrPage[index].display_speed.ToString();
                        textBox8.Text = StrPage[index].stay_time.ToString();
                    }
                    break;
                case 2:
                    if (listBox1.Items.Count > 0)
                    {
                        comboBox3.SelectedIndex = (int)imgURL[index].display_effects;
                        textBox7.Text = imgURL[index].display_speed.ToString();
                        textBox8.Text = imgURL[index].stay_time.ToString();
                    }
                    break;
                case 3:
                    if (listBox1.Items.Count > 0)
                    {
                        comboBox3.SelectedIndex = (int)txtURL[index].display_effects;
                        textBox7.Text = txtURL[index].display_speed.ToString();
                        textBox8.Text = txtURL[index].stay_time.ToString();
                    }
                    break;
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            if (card_mode == 0)
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_SaveDynamicArea(ip, comboBox1.SelectedIndex);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
            else 
            {
                int err = LedYQServerAPI.LedYQserver.Server_SaveDynamicArea(PID, comboBox1.SelectedIndex);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            if (card_mode == 0)
            {
                int err = LedYQNetSDKAPI.LedYQNetSdk.Net_DelSaveDynamicArea(ip);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
            else 
            {
                int err = LedYQServerAPI.LedYQserver.Server_DelSaveDynamicArea(PID);
                if (err != 0)
                {
                    LedYQNetSDKAPI.LedYQNetSdk.GetError(err);
                }
            }
        }
    }
}
