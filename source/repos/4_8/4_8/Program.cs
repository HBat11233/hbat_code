using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _4_8
{
    class First
    {
        ~First()
        {
            Console.WriteLine("First's destructor is called");
        }
    }

    class Second:First
    {
        ~Second()
        {
            Console.WriteLine("Second's destructor is called");
        }
    }

    class Third:Second
    {
        ~Third()
        {
            Console.WriteLine("Third's destructor is called");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            ru();
            int a = new int();
            int b = new int();
            string str = Console.ReadLine();
            a = int.Parse(str.Split(' ')[0]);
            b = int.Parse(str.Split(' ')[1]);
            Console.WriteLine(a + b);
        }
        static void ru()
        {
            Third test = new Third();
            return;
        }
    }
}
