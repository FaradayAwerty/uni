
public class Artiodactyl : Mammal {

	private double hoofSize, strength;

	public double HoofSize {
		get { return hoofSize; }
		set { hoofSize = value; }
	}

	public double Strength {
		get { return strength; }
		set { strength = value; }
	}

	public Artiodactyl(double x, double y, double z, double weight,
			string name, string diet,
			double breastSize, double milkAmount,
			double hoofSize, double strength) :
		base(x, y, z, weight, name, diet, breastSize, milkAmount) {
		this.hoofSize = hoofSize;
		this.strength = strength;
	}

	public Artiodactyl(string name, string diet,
			double breastSize, double milkAmount,
			double hoofSize, double strength) :
		base(0, 0, 0, 0, name, diet, breastSize, milkAmount) {
		this.hoofSize = hoofSize;
		this.strength = strength;
	}

	public Artiodactyl(Artiodactyl a) :
		base(a.X, a.Y, a.Z, a.Weight, a.Name, a.Diet,
				a.BreastSize, a.MilkAmount) {
		this.hoofSize = a.hoofSize;
		this.strength = a.strength;
	}

	public override string ToString() {
		return base.ToString() + ", hoof size:" + hoofSize.ToString() + ", strength:" + strength.ToString();
	}

	public override string ShortDescription() {
		return base.ShortDescription() + ", " + hoofSize.ToString() + ", " + strength.ToString();
	}

	public override bool Compare(AnimalBase ab) {

		if(ab.GetType() != this.GetType())
			return false;
		Artiodactyl a = (Artiodactyl)ab;

		return base.Compare(a) && (a.hoofSize == hoofSize) && (a.strength == strength);
	}

	public override string ItemName() {
		return Name;
	}
}

