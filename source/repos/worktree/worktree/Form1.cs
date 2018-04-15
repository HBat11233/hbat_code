using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace worktree
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private Graphics graphics;
        const double PI = Math.PI;
        double th1 = 35 * Math.PI / 180;
        double th2 = 25 * Math.PI / 180;
        double per1 = 0.6;
        double per2 = 0.7;

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            graphics = e.Graphics;
            drawTree(10, 200, 380, 100, -PI / 2);
        }

        Random rnd = new Random();
        double rand()
        {
            return rnd.NextDouble();
        }

        void drawTree(int n,
                double x0, double y0, double leng, double th)
        {
            if (n == 0) return;

            double x1 = x0 + leng * Math.Cos(th);
            double y1 = y0 + leng * Math.Sin(th);

            drawLine(x0, y0, x1, y1);

            drawTree(n - 1, (x1 + x0) / 2, (y1 + y0) / 2, per1 * leng * (0.5 + rand()), th + th1 * (0.5 + rand()));
            drawTree(n - 1, x1, y1, per2 * leng * (0.4 + rand()), th - th2 * (0.5 + rand()));
            if (rand() > 0.6)
                drawTree(n - 1, x1, y1, per2 * leng * (0.4 + rand()), th - th2 * (0.5 + rand()));
        }
        void drawLine(double x0, double y0, double x1, double y1)
        {
            graphics.DrawLine(
                Pens.Blue,
                (int)x0, (int)y0, (int)x1, (int)y1);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void Form1_Click(object sender, EventArgs e)
        {
            this.Invalidate();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            per1 = double.Parse(textBox1.Text.Length != 0 ? textBox1.Text : "0.6");
        }

        private void label1_Click(object sender, EventArgs e)
        {
        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {
            per2 = double.Parse(textBox2.Text.Length != 0 ? textBox2.Text : "0.6");
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {
            th1 = double.Parse(textBox4.Text.Length != 0 ? textBox4.Text : "35")* Math.PI / 180;
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            th2 = double.Parse(textBox3.Text.Length!=0? textBox3.Text:"25" )* Math.PI / 180;
        }
    }
}
