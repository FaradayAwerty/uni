
using System;

public class Program {

	public static void Main(string[] args) {
		try {
			Console.WriteLine(average(
						Convert.ToDouble(args[0]),
						Convert.ToDouble(args[1])));
		} catch (System.IndexOutOfRangeException) {
			Console.WriteLine(average(
						Convert.ToDouble(Console.ReadLine()),
						Convert.ToDouble(Console.ReadLine())));
		}
	}

	public static Double average(Double a, Double b) {
		return (a + b) / 2;
	}
}

