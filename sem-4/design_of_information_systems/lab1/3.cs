
using System;

class Task3 {
	public static void Main(string[] args) {

		Int32 n = Convert.ToInt32(Console.ReadLine());
		Int32[] arr = new Int32[n];
		Random r = new Random();

		for(int i = 0; i < n; i++) {
			arr[i] = r.Next() % 10;
			Console.Write("\t");
			Console.Write(Convert.ToString(arr[i]));
		}
		Console.WriteLine();

		Int32 ifm = 0, ilm = 0; // index first maximum, index last minimum
		
		for(int i = 0; i < n; i++) {
			if(arr[ifm] < arr[i])
				ifm = i;
		}

		for(int i = 0; i < n; i++) {
			if(arr[ilm] >= arr[i])
				ilm = i;
		}

		Console.WriteLine(Convert.ToString(ifm));
		Console.WriteLine(Convert.ToString(ilm));

		while(ifm < ilm) {
			
		}
	}
}

