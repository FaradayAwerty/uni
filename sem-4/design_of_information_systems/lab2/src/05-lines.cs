
using System;
using System.Drawing;
using System.Windows.Forms;

public class MainForm : Form
{
	private Graphics g;
	private Pen p;

	public MainForm() {
		this.Text = "Demo: lines";
		this.Size = new Size(1280, 720);
		this.BackColor = Color.Black;
		this.MouseClick += new MouseEventHandler(MainForm_MouseClick);

		g = this.CreateGraphics();

		p = new Pen(Color.Red, 2);
		p.DashPattern = new float[]{5, 4};
	}

	private void MainForm_MouseClick(object sender, MouseEventArgs e)
	{
		g.DrawLine(p, new Point(25, 25), e.Location);
	}

	public static void Main(string[] args) {
		Application.Run(new MainForm());
	}
}

