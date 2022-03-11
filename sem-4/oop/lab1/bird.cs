
public class Bird : AnimalBase {

	private double flightHeight, wingSize;

	public double FlightHeight {
		get { return flightHeight; }
		set { flightHeight = value; }
	}

	public double WingSize {
		get { return wingSize; }
		set { wingSize = value; }
	}

	public Bird(double x, double y, double z, double weight) : base(x, y, z, weight) {
		this.flightHeight = 0;
		this.wingSize = 0;
	}

	public Bird(double x, double y, double z, double weight, double flightHeight, double wingSize) : base(x, y, z, weight) {
		this.flightHeight = flightHeight;
		this.wingSize = wingSize;
	}

	new public string ToString() {
		return base.ToString() + ", " + flightHeight.ToString() + ", " + wingSize.ToString();
	}

	public bool Compare(Bird b) {
		return base.Compare(b) && (b.flightHeight == flightHeight) && (b.wingSize == wingSize);
	}

}

