
public class Mammal : AnimalBase {

	private double breastSize, milkAmount;

	public double BreastSize {
		get { return breastSize; }
		set { breastSize = value; }
	}

	public double MilkAmount {
		get { return milkAmount; }
		set { milkAmount = value; }
	}

	public Mammal(double x, double y, double z, double weight) : base(x, y, z, weight) {
	}

	public Mammal(double x, double y, double z, double weight, double breastSize, double milkAmount) : base(x, y, z, weight) {
		this.breastSize = breastSize;
		this.milkAmount = milkAmount;
	}

	public override string ToString() {
		return base.ToString() + ", " + breastSize + ", " + milkAmount;
	}

	public override bool Compare(AnimalBase ab) {

		if(ab.GetType() != this.GetType())
			return false;
		Mammal m = (Mammal)ab;

		return base.Compare(m) && (m.breastSize == breastSize) && (m.milkAmount == milkAmount);
	}
}

