// https://docs.microsoft.com/en-us/dotnet/articles/core/tutorials/using-with-xplat-cli

namespace ConsoleApp
{
    public class Utils
    {
        public int Fibonacci(int n)
        {           
            int a = 0, b = 1, tmp;

            for (int i = 0; i < n; i++)
            {
                tmp = a;
                a = b;
                b += tmp;
            }

            return a;
        }


    }

}
