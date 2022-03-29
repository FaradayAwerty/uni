
public class Mammal : Animal {

	private double breastSize, milkAmount;

	public double BreastSize {
		get { return breastSize; }
		set { breastSize = value; }
	}

	public double MilkAmount {
		get { return milkAmount; }
		set { milkAmount = value; }
	}

	public Mammal(double x, double y, double z, double weight, string name,
			string diet, double breastSize, double milkAmount) :
		base(x, y, z, weight, name, diet) {
		this.breastSize = breastSize;
		this.milkAmount = milkAmount;
	}

	public Mammal(string name, string diet,
			double breastSize, double milkAmount) :
		base(0, 0, 0, 0, name, diet) {
		this.breastSize = breastSize;
		this.milkAmount = milkAmount;
	}

	public Mammal(Mammal m) : base(m.X, m.Y, m.Z, m.Weight, m.Name, m.Diet) {
		this.breastSize = m.breastSize;
		this.milkAmount = m.milkAmount;
	}

	public override string ToString() {
		return base.ToString() + ", breast size:" + breastSize + ", milk amount:" + milkAmount;
	}

	public override string ShortDescription() {
		return base.ShortDescription() + ", " + breastSize + ", " + milkAmount;
	}

	public override bool Compare(AnimalBase ab) {

		if(ab.GetType() != this.GetType())
			return false;
		Mammal m = (Mammal)ab;

		return base.Compare(m) && (m.breastSize == breastSize) && (m.milkAmount == milkAmount);
	}

	public override string ItemName() {
		return Name;
	}
}

