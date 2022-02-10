
namespace Task1
{
	class Program
	{
		static void Main(string[] args)
		{
			double x = Convert.ToDouble(Console.ReadLine());
			double y = Convert.ToDouble(Console.ReadLine());
			double z = Convert.ToDouble(Console.ReadLine());

			Console.WriteLine( (x*x*x + Math.Sqrt(Math.Pow(z, 6) - 5*x*y))/Math.Abs(-7*x*x*Math.Pow(y, 8) + z) );
		}
	}
}

