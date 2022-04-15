
using System;
using System.Collections.Generic;

public class AnimalStorage {

	private List<Animal> animals;
	private List<Artiodactyl> artiodactyls;
	private List<Mammal> mammals;
	private List<Bird> birds;

	public AnimalStorage() {
		animals = new List<Animal>();
		artiodactyls = new List<Artiodactyl>();
		mammals = new List<Mammal>();
		birds = new List<Bird>();
	}
}
