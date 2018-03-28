using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 自动出题并评分
{
    public partial class Form1 : Form
    {
        Random rnd = new Random();
        char[] fs = { '+', '-', '*', '/' };
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //出题
            NewQuesion();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //初始化
            timer1.Enabled = false;
                button3.Text = "开始";
            NewQuesion();
        }
        //出题
        void NewQuesion()
        {
            label1.Text = (rnd.Next(100) + 1).ToString();
            label2.Text = fs[rnd.Next(4)].ToString();
            label3.Text = (rnd.Next(100) + 1).ToString();
            label4.Text = "=";
        }
        //判断
        void YON()
        {
            switch (label2.Text)
            {
                case "+":
                    int ans = int.Parse(label1.Text) + int.Parse(label3.Text);
                    if (ans == int.Parse(textBox1.Text))
                        Win();
                    else
                        Def();
                    break;
                case "-":
                    ans = int.Parse(label1.Text) - int.Parse(label3.Text);
                    if (ans == int.Parse(textBox1.Text))
                        Win();
                    else
                        Def();
                    break;
                case "*":
                    ans = int.Parse(label1.Text) * int.Parse(label3.Text);
                    if (ans == int.Parse(textBox1.Text))
                        Win();
                    else
                        Def();
                    break;
                case "/":
                    double ans1 = double.Parse(label1.Text) / double.Parse(label3.Text);
                    if (Math.Abs(ans1 - double.Parse(textBox1.Text)) < 0.1)
                        Win();
                    else
                        Def();
                    break;
            }
        }
        //加分
        void Win()
        {
            label6.Text = (int.Parse(label6.Text) + 1).ToString();
            textBox1.BackColor = Color.FromArgb(255, 0, 0);
            NewQuesion();
        }
        //减分
        void Def()
        {
            label6.Text = (int.Parse(label6.Text) - 1).ToString();
            textBox1.BackColor = Color.FromArgb(0, 255, 0);
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }
        //判断按钮
        private void button2_Click(object sender, EventArgs e)
        {
            YON();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            //时间截止
            if (int.Parse(label7.Text) == 0)
            {
                label8.Text = "最终得分：";
                label7.Text = label6.Text;
                timer1.Enabled = false;
            }
            //倒计时
            label7.Text = (int.Parse(label7.Text) - 1).ToString();
        }

        private void label7_Click(object sender, EventArgs e)
        {

        }
        //开始，重新开始
        private void button3_Click(object sender, EventArgs e)
        {
            label6.Text = "0";
            label7.Text = "60";
            timer1.Enabled = true;
            button3.Text = "重新开始";
            textBox1.Text = null;
            textBox1.BackColor = Color.FromArgb(255, 255, 255);
        }

        private void label8_Click(object sender, EventArgs e)
        {

        }
    }
}
