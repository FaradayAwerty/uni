
public abstract class AnimalBase : IHasGuid {

	private double x, y, z, weight;

	public double X {
		get { return x; }
		set { x = value; }
	}

	public double Y {
		get { return y; }
		set { y = value; }
	}

	public double Z {
		get { return z; }
		set { z = value; }
	}

	public double Weight {
		get { return weight; }
	}

	public AnimalBase(double x, double y, double z, double weight) {
		this.x = x;
		this.y = y;
		this.z = z;
		this.weight = weight;
	}

	public virtual bool Compare(AnimalBase a) {
		return (a.x == x) && (a.y == y) && (a.z == z) && (a.weight == weight);
	}

	public override string ToString() {
		return "x: " + x.ToString() + ", y:" + y.ToString() + ", z:" + z.ToString() + ", weight:" + weight.ToString();
	}

	public virtual string ShortDescription() {
		return x.ToString() + ", " + y.ToString() + ", " + z.ToString() + ", " + weight.ToString();
	}

	public virtual string ItemName() {
		return "Unknown";
	}
}

