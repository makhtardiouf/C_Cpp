using System;
using static System.Console;

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
            Utils ut = new Utils();
             for (int i = 0; i < 15; i++)
            {
                WriteLine($"{i+1}: {ut.Fibonacci(i)}");
            }
        }
    }
}
