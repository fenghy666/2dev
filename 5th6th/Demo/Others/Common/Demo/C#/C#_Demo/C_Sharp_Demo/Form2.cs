using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace C_Sharp_Demo
{
    public partial class Form2 : Form
    {
        string[] s;
        public Form2(string str)
        {
            s = str.Split(new char[2]{';',','});
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            DataTable dt = new DataTable();
            dt.Columns.Add(new DataColumn("name"));
            dt.Columns.Add(new DataColumn("BarCode"));
            dt.Columns.Add(new DataColumn("NetworkID"));
            dt.Columns.Add(new DataColumn("TransitType"));
            dt.Columns.Add(new DataColumn("Status"));
            for (int i = 0; i < s.Length-1;i++ ) 
            {
                dt.Rows.Add(new object[] { s[i], s[i + 1], s[i + 2], s[i + 3],s[i + 4]  });
                i = i + 4;
            }
            dataGridView1.AutoGenerateColumns = false;
            dataGridView1.DataSource = dt;
        }

        public string bar;
        public string bai;
        private void dataGridView1_CellDoubleClick(object sender, DataGridViewCellEventArgs e)
        {
            bar = this.dataGridView1.SelectedCells[1].Value.ToString();
            bai = this.dataGridView1.SelectedCells[2].Value.ToString();
            this.Close();
        }
    }
}
