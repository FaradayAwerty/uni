
namespace Task3
{
	class Task3
	{
		static void Main(string[] args)
		{
			Int32 n = Convert.ToInt32(Console.ReadLine());
			Int32[] arr = new Int32[n];

			Random rnd = new Random();

			for(int i = 0; i < n; i++) {
				arr[i] = rnd.Next(0, 50);
			}

			for(int i = 0; i < n; i++) {
				Console.WriteLine(arr[i]);
			}
		}
	}
}

