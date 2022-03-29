
public class Animal : AnimalBase {

	private string name, diet;

	public string Name {
		get { return name; }
		set { name = value; }
	}

	public string Diet {
		get { return diet; }
		set { diet = value; }
	}

	public Animal(double x, double y, double z, double weight) : base (x, y, z, weight) {
	}

	public Animal(double x, double y, double z, double weight, string name, string diet) : base (x, y, z, weight){
		this.name = name;
		this.diet = diet;
	}

	public override string ToString() {
		return base.ToString() + ", " + name + ", " + diet;
	}

	public override bool Compare(AnimalBase ab) {

		if(ab.GetType() != this.GetType())
			return false;
		Animal a = (Animal)ab;

		return base.Compare(a) && (a.name == name) && (a.diet == diet);
	}
}

