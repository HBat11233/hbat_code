using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 屏保
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        int deltx = 5;
        int delty = 5;

        private void timer1_Tick(object sender, EventArgs e)
        {
            this.label1.Left += deltx;
            this.label1.Top += delty;
            if (this.label1.Top < 0 || this.label1.Top + this.label1.Height > this.Height)
                delty = -delty;
            if (this.label1.Left < 0 || this.label1.Left + this.label1.Width > this.Width)
                deltx = -deltx;
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            Application.Exit();
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            //Application.Exit();
        }
    }
}
