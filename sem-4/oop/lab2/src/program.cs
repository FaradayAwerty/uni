
using System;
using System.Collections.Generic;

public class Program {
	public static void Main(string[] args) {

		List<AnimalBase> animals = new List<AnimalBase>();

		Console.WriteLine("Доступные команды:");
		Console.WriteLine("\tanimal - добавить животное");
		Console.WriteLine("\tbird - добавить птицу");
		Console.WriteLine("\tartiodactyl - добавить парнокопытное");
		Console.WriteLine("\tmammal - добавить млекопитающее");
		Console.WriteLine("\tprint - напечатать всех животных");
		Console.WriteLine("\texit - выход");
	
		bool isRunning = true;
		while(isRunning) {
			switch(Console.ReadLine()) {
				case "exit":
					isRunning = false;
					break;
				case "print":
					foreach(AnimalBase ab in animals) {
						Console.WriteLine(ab.GetType().ToString()
								+ ": " + ab.ToString());
					}
					break;
				case "animal":
					Animal a = new Animal(ReadDouble("x = "),
								ReadDouble("y = "),
								ReadDouble("z = "),
								ReadDouble("weight = "),
								ReadString("name = "),
								ReadString("diet = "));
					if(IsPresent(animals, a))
						Console.WriteLine("такая штучка уже имеется в списке!");
					else
						animals.Add(a);
					break;
				case "bird":
					Bird b = new Bird(ReadDouble("x = "),
								ReadDouble("y = "),
								ReadDouble("z = "),
								ReadDouble("weight = "),
								ReadString("name = "),
								ReadString("diet = "),
								ReadDouble("flight height = "),
								ReadDouble("wing size = "));
					if(IsPresent(animals, b))
						Console.WriteLine("такая штучка уже имеется в списке!");
					else
						animals.Add(b);
					break;
				case "mammal":
					Mammal m = new Mammal(ReadDouble("x = "),
								ReadDouble("y = "),
								ReadDouble("z = "),
								ReadDouble("weight = "),
								ReadString("name = "),
								ReadString("diet = "),
								ReadDouble("breast size = "),
								ReadDouble("milk amount = "));
					if(IsPresent(animals, m))
						Console.WriteLine("такая штучка уже имеется в списке!");
					else
						animals.Add(m);
					break;
				case "artiodactyl":
					Artiodactyl ar = new Artiodactyl(ReadDouble("x = "),
								ReadDouble("y = "),
								ReadDouble("z = "),
								ReadDouble("weight = "),
								ReadString("name = "),
								ReadString("diet = "),
								ReadDouble("breast size = "),
								ReadDouble("milk amount = "),
								ReadDouble("hoof size = "),
								ReadDouble("strength = "));
					if(IsPresent(animals, ar))
						Console.WriteLine("такая штучка уже имеется в списке!");
					else
						animals.Add(ar);
					break;
				default:
					break;
			}
		}

	}

	public static bool IsPresent(List<AnimalBase> list, AnimalBase elem) {
			foreach(AnimalBase ab in list)
				if(ab.Compare(elem))
					return true;
			return false;
	}

	public static double ReadDouble(string message) {
		Console.Write(message);
		try {
			return double.Parse(Console.ReadLine());
		} catch (System.Exception) {
			return 0.0;
		}
	}

	public static string ReadString(string message) {
		Console.Write(message);
		return Console.ReadLine();
	}
}

