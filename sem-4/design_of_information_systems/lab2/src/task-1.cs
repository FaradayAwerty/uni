
using System;
using System.Drawing;
using System.Windows.Forms;

public class MainForm : Form
{
	private bool is_drawing = false, first_touch = true;
	private Point mouse_last_point = new Point(0, 0); 
	private Graphics g;
	private Pen red_pen, cyan_pen;

	public MainForm() {
		this.Text = "Demo: drawing lines";
		this.Size = new Size(1280, 720);
		this.BackColor = Color.Black;
		this.MouseDoubleClick += new MouseEventHandler(MainForm_MouseDoubleClick);
		this.MouseDown += new MouseEventHandler(MainForm_MouseDown);

		g = this.CreateGraphics();

		red_pen = new Pen(Color.Red, 2);
		red_pen.DashPattern = new float[]{5, 4};

		cyan_pen = new Pen(Color.Cyan, 2);
		cyan_pen.DashPattern = new float[]{5, 4};
	}

	private void MainForm_MouseDoubleClick(object sender, MouseEventArgs a)
	{
		if(!is_drawing && !first_touch)
			g.DrawLine(cyan_pen, mouse_last_point, a.Location);
		first_touch = false;
		is_drawing = !is_drawing;
		mouse_last_point = a.Location;
	}

	private void MainForm_MouseDown(object sender, MouseEventArgs a)
	{
		if(is_drawing) {
			g.DrawLine(red_pen, mouse_last_point, a.Location);
			mouse_last_point = a.Location;
		}
	}

	public static void Main(string[] args) {
		Application.Run(new MainForm());
	}
}

