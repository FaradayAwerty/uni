
namespace Task2
{
	class Program
	{
		// checks if d1 is before d2
		static bool isBefore(DateTime d1, DateTime d2)
		{
			if(d1.Year != d2.Year)
				return false;
			else if(d1.Month != d2.Month)
				return d1.Month < d2.Month;
			else if(d1.Day != d2.Day)
				return d1.Day < d2.Day;
			return false;
		}

		static void Main(string[] args)
		{
			DateTime date1, date2;

			try {
				date1 = Convert.ToDateTime(Console.ReadLine());
				date2 = Convert.ToDateTime(Console.ReadLine());
			} catch(System.FormatException) {
				Console.WriteLine("дата введена неправильно!");
				return;
			}


			Console.WriteLine(date1);
			Console.WriteLine(date2);

			if(isBefore(date1, date2)) {
				Console.WriteLine("в рамках года первая дата предшествует второй");
			} else {
				Console.WriteLine("в рамках года первая дата НЕ предшествует второй");
			}
		}
	}
}

