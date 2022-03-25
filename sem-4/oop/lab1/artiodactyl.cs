
public class Artiodactyl : AnimalBase {

	private double hoofSize, strength;

	public double HoofSize {
		get { return hoofSize; }
		set { hoofSize = value; }
	}

	public double Strength {
		get { return strength; }
		set { strength = value; }
	}

	public Artiodactyl(double x, double y, double z, double weight) : base(x, y, z, weight) {
		this.hoofSize = 0;
		this.strength = 0;
	}

	public Artiodactyl(double x, double y, double z, double weight, double hoofSize, double strength) : base(x, y, z, weight) {
		this.hoofSize = hoofSize;
		this.strength = strength;
	}

	public override string ToString() {
		return base.ToString() + ", " + hoofSize.ToString() + ", " + strength.ToString();
	}

	public override bool Compare(AnimalBase ab) {

		if(ab.GetType() != this.GetType())
			return false;
		Artiodactyl a = (Artiodactyl)ab;

		return base.Compare(a) && (a.hoofSize == hoofSize) && (a.strength == strength);
	}
}

