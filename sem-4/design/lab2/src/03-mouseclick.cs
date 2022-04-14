
using System;
using System.Drawing;
using System.Windows.Forms;

public class MainForm : Form
{
	public MainForm() {
		this.Text = "Demo: mouse click";
		this.Size = new Size(1280, 720);
		this.MouseClick += new MouseEventHandler(MainForm_MouseClick);
	}

	private void MainForm_MouseClick(object sender, MouseEventArgs e)
	{
		if (e.Button == MouseButtons.Left) {
			Random rnd = new Random();
			this.BackColor = Color.FromArgb(0xff,
					rnd.Next(0x100), rnd.Next(0x100), rnd.Next(0x100));
		}
	}

	public static void Main(string[] args) {
		Application.Run(new MainForm());
	}
}

