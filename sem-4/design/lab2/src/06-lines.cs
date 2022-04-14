
using System;
using System.Drawing;
using System.Windows.Forms;

public class MainForm : Form
{
	private bool mouse_is_down = false;
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
		this.MouseMove += new MouseEventHandler(MainForm_MouseMove);

		g = this.CreateGraphics();

		p = new Pen(Color.Red, 2);
		p.DashPattern = new float[]{5, 4};
	}

	private void MainForm_MouseDown(object sender, MouseEventArgs a)
	{
		mouse_is_down = true;
	}

	private void MainForm_MouseUp(object sender, MouseEventArgs a)
	{
		mouse_is_down = false;
	}

	private void MainForm_MouseMove(object sender, MouseEventArgs a)
	{
		if(mouse_is_down)
			g.DrawLine(p, new Point(mouse_last_x, mouse_last_y), a.Location);
		mouse_last_x = a.X;
		mouse_last_y = a.Y;
	}

	public static void Main(string[] args) {
		Application.Run(new MainForm());
	}
}

