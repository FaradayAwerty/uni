
using System;

public class Program {

	public static void Main(string[] args) {
		try {
			Console.WriteLine(sum_of_squares(
						Convert.ToDouble(args[0]),
						Convert.ToDouble(args[1])));
		} catch (System.IndexOutOfRangeException) {
			Console.WriteLine(sum_of_squares(
						Convert.ToDouble(Console.ReadLine()),
						Convert.ToDouble(Console.ReadLine())));
		}
	}

	public static Double sum_of_squares(Double a, Double b) {
		return (a*a) + (b*b);
	}
}

