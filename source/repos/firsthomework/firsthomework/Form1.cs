using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace firsthomework
{
    public partial class Form1 : Form
    {
        private string ans = "";
        public Form1()
        {
            InitializeComponent();
        }

        private void Erjs(int num)
        {
            if (num == 0) return;
            else
            {
                int tempnum = num % 2;
                Erjs(num / 2);
                ans += tempnum.ToString();
                return;
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
        }

        private void button1_Click(object sender, EventArgs e)
        {
            ans = "";
            int num = int.Parse(textBox1.Text);
            Erjs(num);
            textBox2.Text = ans;
        }
    }
}
