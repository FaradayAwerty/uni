
using System;
using System.Drawing;
using System.Windows.Forms;

public class MainForm : Form
{
	public MainForm() {
		this.Text = "Demo: click";
		this.Size = new Size(1280, 720);
		this.Click += new EventHandler(MainForm_Click);
		this.BackColor = Color.Black;
	}

	private void MainForm_Click(object sender, EventArgs e)
	{
		this.BackColor = Color.Blue;
	}

	public static void Main(string[] args) {
		Application.Run(new MainForm());
	}
}

