
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
					animals.Add(new Animal(ReadDouble("x = "),
								ReadDouble("y = "),
								ReadDouble("z = "),
								ReadDouble("weight = "),
								ReadString("name = "),
								ReadString("diet = ")));
					break;
				case "bird":
					animals.Add(new Bird(ReadDouble("x = "),
								ReadDouble("y = "),
								ReadDouble("z = "),
								ReadDouble("weight = "),
								ReadDouble("flight height = "),
								ReadDouble("wing size = ")));
					break;
				case "mammal":
					animals.Add(new Bird(ReadDouble("x = "),
								ReadDouble("y = "),
								ReadDouble("z = "),
								ReadDouble("weight = "),
								ReadDouble("breast size = "),
								ReadDouble("milk amount = ")));
					break;
				case "artiodactyl":
					animals.Add(new Artiodactyl(ReadDouble("x = "),
								ReadDouble("y = "),
								ReadDouble("z = "),
								ReadDouble("weight = "),
								ReadDouble("hoof size = "),
								ReadDouble("strength = ")));
					break;
				default:
					break;
			}
		}

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

