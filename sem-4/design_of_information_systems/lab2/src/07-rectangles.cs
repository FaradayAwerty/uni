
using System;
using System.Drawing;
using System.Windows.Forms;

public class MainForm : Form
{
	private int mouse_last_x = 0; 
	private int mouse_last_y = 0; 

	private Graphics g;
	private Pen p;

	public MainForm() {
		this.Text = "Demo: drawing lines";
		this.Size = new Size(1280, 720);
		this.BackColor = Color.Black;
		this.MouseDown += new MouseEventHandler(MainForm_MouseDown);
		this.MouseUp += new MouseEventHandler(MainForm_MouseUp);

		g = this.CreateGraphics();

		p = new Pen(Color.Cyan, 2);
		p.DashPattern = new float[]{5, 4};
	}

	private void MainForm_MouseDown(object sender, MouseEventArgs a)
	{
		mouse_last_x = a.X;
		mouse_last_y = a.Y;
	}

	private void MainForm_MouseUp(object sender, MouseEventArgs a)
	{
		g.DrawRectangle(p,
				Math.Min(a.X, mouse_last_x),
				Math.Min(mouse_last_y, a.Y),
				Math.Abs(a.X - mouse_last_x),
				Math.Abs(a.Y - mouse_last_y));
	}

	public static void Main(string[] args) {
		Application.Run(new MainForm());
	}
}

