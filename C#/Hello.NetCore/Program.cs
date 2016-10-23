using System;
using static System.Console;
using System.Collections.Generic;

namespace ConsoleApp
{
    public class Tryit
    {
        public static void Main(string[] args)
        {
            Console.Beep();
            Console.WriteLine("Hello World!");
            WriteLine("It's " + System.DateTime.Now);

            WriteLine("\nCalculating Fibonacci numbers");
           
            List<string> times = new List<string>();
            List<int> fiboNums = new List<int>();
            int i = 0;
             Utils ut = new Utils(); 
            
            for (; i < 15; i++)
            {
                // WriteLine($"{i+1}: {ut.Fibonacci(i)}");
                fiboNums.Add(ut.Fibonacci(i));
                 var dt = DateTime.Now;
System.Threading.Thread.Sleep(500);
                times.Add(dt.Hour + ":" + dt.Minute + ":" + dt.Second);
            }

            i = 0;
            foreach (var t in times)
            {
                WriteLine(t + "ms: " + fiboNums[i]);
                i++;
            }
        }
    }
}
