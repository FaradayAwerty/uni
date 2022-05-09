
using System;
using System.Drawing;
using System.Windows.Forms;

public class MainForm : Form
{
	private bool is_drawing = false;

	private Point mouse_last_point = new Point(0, 0); 

	private Graphics g;
	private Pen p;

	public MainForm() {
		this.Text = "Demo: drawing lines";
		this.Size = new Size(1280, 720);
		this.BackColor = Color.Black;
		this.MouseDoubleClick += new MouseEventHandler(MainForm_MouseDoubleClick);
		this.MouseDown += new MouseEventHandler(MainForm_MouseDown);

		g = this.CreateGraphics();

		p = new Pen(Color.Red, 2);
		p.DashPattern = new float[]{5, 4};
	}

	private void MainForm_MouseDoubleClick(object sender, MouseEventArgs a)
	{
		is_drawing = !is_drawing;
	}

	private void MainForm_MouseDown(object sender, MouseEventArgs a)
	{
		if(is_drawing)
			g.DrawLine(p, mouse_last_point, a.Location);
		mouse_last_point = a.Location;
	}

	public static void Main(string[] args) {
		Application.Run(new MainForm());
	}
}

