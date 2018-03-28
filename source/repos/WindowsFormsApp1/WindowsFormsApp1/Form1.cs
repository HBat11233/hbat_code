using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("hello!");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Random rnd = new Random();
            this.Text = DateTime.Now.ToString();
            this.label1.BackColor = Color.FromArgb(rnd.Next(255), rnd.Next(255), rnd.Next(255));
            this.BackColor = Color.FromArgb(255, 255, 0);
            this.label1.SetBounds(100, 100, 100, 100);
            this.label1.Left += 200;
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            this.label1.Text = e.X + "," + e.Y;
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            textBox2.Text = textBox1.Text;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Random rnd = new Random();
            this.Text = DateTime.Now.ToString();
            this.label1.BackColor = Color.FromArgb(rnd.Next(255), rnd.Next(255), rnd.Next(255));
            this.BackColor = Color.FromArgb(255, 255, 0);
            this.label1.SetBounds(100, 100, 100, 100);
            this.label1.Left += 200;
        }
    }
}
