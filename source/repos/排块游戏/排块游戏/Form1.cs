using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 排块游戏
{
    public partial class Form1 : Form
    {
        const int N = 4;
        Button[,] buttons = new Button[N, N];
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //打乱顺序
            Shuffle();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //产生按钮
            GenerateAllButtons();
        }

        void Shuffle()
        {
            Random rnd = new Random();
            for(int i=0;i<100;++i)
            {
                int a = rnd.Next(N);
                int b = rnd.Next(N);
                int c = rnd.Next(N);
                int d = rnd.Next(N);
                Swap(buttons[a, b], buttons[c, d]);
            }
        }

        private void Swap(Button button1, Button button2)
        {
            string str = button1.Text;
            button1.Text = button2.Text;
            button2.Text = str;

            bool v = button1.Visible;
            button1.Visible = button2.Visible;
            button2.Visible = v;
        }

        void GenerateAllButtons()
        {
            int x0 = 50, y0 = 10, w = 45, d = 50;
            for(int r=0;r<N;++r)
            {
                for(int c=0;c<N;++c)
                {
                    int num = r * N + c;
                    Button btn = new Button();
                    btn.Text = (num + 1).ToString();
                    btn.Top = y0 + r * d;
                    btn.Left = x0 + c * d;
                    btn.Width = w;
                    btn.Height = w;
                    btn.Visible = true;
                    btn.Tag = r * N + c;//表示所在行，列

                    //注册事件
                    btn.Click += Btn_Click;
                    buttons[r, c] = btn;//放到数组
                    this.Controls.Add(btn);//加到界面
                }
            }
            buttons[N - 1, N - 1].Visible = false;//隐藏最后一个
        }

        private void Btn_Click(object sender, EventArgs e)
        {
            Button btn = sender as Button;//当前点击按钮
            Button blank = FindHiddenButton();//空白按钮

            //判断是否相邻，是就交换
            if(IsNeighbor(btn,blank))
            {
                Swap(btn, blank);
                blank.Focus();
            }
            //判断是否完成
            if(ResultIsOk())
            {
                MessageBox.Show("ok");
            }
        }

        private bool ResultIsOk()
        {
            for (int r = 0; r < N; ++r)
            {
                for (int c = 0; c < N; ++c)
                {
                    if ((r * N + c) == int.Parse(buttons[r, c].Text)-1);
                    else return false;
                }
            }
            return true;
        }

        private bool IsNeighbor(Button btn, Button blank)
        {
            int a = (int)btn.Tag;
            int b = (int)blank.Tag;
            int r1 = a / N;
            int c1 = a % N;
            int r2 = b / N;
            int c2 = b % N;
            if ((r1 == r2 && Abs(c1 - c2) == 1) || (c1 == c2 && Abs(r1 - r2) == 1)) return true;
            return false;
        }

        private int Abs(int v)
        {
            if(v<0)return -v;
            return v;
        }

        private Button FindHiddenButton()
        {
            for(int r=0;r<N;++r)
            {
                for(int c=0;c<N;++c)
                {
                    if (buttons[r, c].Visible) continue;
                    else return buttons[r, c];
                }
            }
            return null;
        }
    }
}
