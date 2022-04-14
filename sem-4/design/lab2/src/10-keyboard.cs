
using System;
using System.Drawing;
using System.Windows.Forms;

public class MainForm : Form
{
	private Graphics g;
	private bool is_running = false;

	public MainForm() {
		this.Text = "Demo: keyboard | Клавиатурный тренажер";
		this.Size = new Size(1280, 720);
		this.BackColor = Color.Black;
		this.KeyPress += new KeyEventHandler(MainForm_KeyPress);
		this.FormClosing += new EventHandler(MainForm_FormClosing);
		g = this.CreateGraphics();
	}

	private void MainForm_KeyPress(object sender, KeyEventArgs e) {
		if(!is_running && e.KeyCode == Keys.Return)
			is_running = true;

	}

	private void MainForm_FormClosing(object sender, FormClosingEventArgs e) {
		g.Dispose();
	}

	public static void Main(string[] args) {
		Application.Run(new MainForm());
	}
}

