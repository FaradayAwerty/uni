
using System;

public class Program {

	public static void Main(string[] args) {
		try {
			Console.WriteLine(geometric_average(
						Convert.ToDouble(args[0]),
						Convert.ToDouble(args[1])));
		} catch (System.IndexOutOfRangeException) {
			Console.WriteLine(geometric_average(
						Convert.ToDouble(Console.ReadLine()),
						Convert.ToDouble(Console.ReadLine())));
		}
	}

	public static Double geometric_average(Double a, Double b) {
		return Math.Sqrt(a * b);
	}
}

