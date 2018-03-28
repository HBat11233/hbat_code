using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloWorld
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 123;
            object s;
            s = (object)a;
            object f = s;
            Console.Write(s);
            a = 22;
            s = 3;
            f = s;
            Console.Write(f);
            Console.Read();
        }
    }
}
