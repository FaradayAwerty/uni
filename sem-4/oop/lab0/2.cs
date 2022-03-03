
using System;

public class Program {

	public static void Main(string[] args) {
		try {
			Console.WriteLine(difference_of_squares(
						Convert.ToInt32(args[0]),
						Convert.ToInt32(args[1])));
		} catch (System.IndexOutOfRangeException) {
			Console.WriteLine(difference_of_squares(
						Convert.ToInt32(Console.ReadLine()),
						Convert.ToInt32(Console.ReadLine())));
		}
	}

	public static Int32 difference_of_squares(Int32 a, Int32 b) {
		return a*a - b*b;
	}
}

