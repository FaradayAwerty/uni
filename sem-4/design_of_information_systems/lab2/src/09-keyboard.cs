
using System;
using System.Drawing;
using System.Windows.Forms;

public class MainForm : Form
{
	public MainForm() {
		this.Text = "Demo: keyboard | Нажмите <Ctrl + пробел>";
		this.Size = new Size(1280, 720);
		this.BackColor = Color.Black;
		this.KeyDown += new KeyEventHandler(MainForm_KeyDown);
	}

	private void MainForm_KeyDown(object sender, KeyEventArgs e) {
		if(e.Control && this.Size.Width == 1280 && this.Size.Height == 720)
			this.Size = new Size(640, 360);
		else if(e.Control && this.Size.Width == 640 && this.Size.Height == 360)
			this.Size = new Size(1280, 720);
		else if(e.Control && e.KeyCode == Keys.Space)
			this.Size = new Size(640, 360);
	}


	public static void Main(string[] args) {
		Application.Run(new MainForm());
	}
}

