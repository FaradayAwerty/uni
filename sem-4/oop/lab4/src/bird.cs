
public class Bird : Animal {

	private double flightHeight, wingSize;

	public double FlightHeight {
		get { return flightHeight; }
		set { flightHeight = value; }
	}

	public double WingSize {
		get { return wingSize; }
		set { wingSize = value; }
	}

	public Bird(double x, double y, double z, double weight, string name,
			string diet, double flightHeight, double wingSize) :
		base(x, y, z, weight, name, diet) {
		this.flightHeight = flightHeight;
		this.wingSize = wingSize;
	}

	public Bird(string name, string diet,
			double flightHeight, double wingSize) :
		base(0, 0, 0, 0, name, diet) {
		this.flightHeight = flightHeight;
		this.wingSize = wingSize;
	}

	public Bird(Bird b) : base(b.X, b.Y, b.Z, b.Weight, b.Name, b.Diet) {
		this.flightHeight = b.flightHeight;
		this.wingSize = b.wingSize;
	}

	public override string ToString() {
		return base.ToString() + ", flight height:" + flightHeight.ToString() + ", wing size:" + wingSize.ToString();
	}

	public override string ShortDescription() {
		return base.ShortDescription() + ", " + flightHeight.ToString() + ", " + wingSize.ToString();
	}

	public override bool Compare(AnimalBase ab) {

		if(ab.GetType() != this.GetType())
			return false;
		Bird b = (Bird)ab;

		return base.Compare(b) && (b.flightHeight == flightHeight) && (b.wingSize == wingSize);
	}

	public override string ItemName() {
		return Name;
	}
}

