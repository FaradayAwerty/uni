
using System;
using System.Drawing;
using System.Windows.Forms;

public class MainForm : Form
{
	public static int WINDOW_WIDTH = 1280;
	public static int WINDOW_HEIGHT = 720;

	private Graphics g;
	private bool is_running = false;
	private char current_character = '0';

	public MainForm() {
		this.Text = "Demo: keyboard | Клавиатурный тренажер";
		this.Size = new Size(WINDOW_WIDTH, WINDOW_HEIGHT);
		this.BackColor = Color.Black;
		this.KeyPress += new KeyPressEventHandler(MainForm_KeyPress);
		this.FormClosing += new FormClosingEventHandler(MainForm_FormClosing);
		g = this.CreateGraphics();

	}

	private void MainForm_KeyPress(object sender, KeyPressEventArgs e) {

		g.FillEllipse(new SolidBrush(Color.White),
				WINDOW_WIDTH / 4, WINDOW_HEIGHT / 4,
				WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		g.DrawEllipse(new Pen(Color.White),
				WINDOW_WIDTH / 4, WINDOW_HEIGHT / 4,
				WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

		if(!is_running && e.KeyChar == (char)Keys.Return)
			is_running = true;
		else if(is_running && e.KeyChar == (char)Keys.Return)
			is_running = false;

		if(is_running) {
			current_character = GetRandomCharacter(
					"абвгдеёжзийклмнопрстуфхцчшщъыьэюя",
					new Random());
			g.DrawString(current_character.ToString(),
					new Font("Times", 32),
					new SolidBrush(Color.Black),
					WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		}

	}

	private void MainForm_FormClosing(object sender, FormClosingEventArgs e) {
		g.Dispose();
	}

	public static void Main(string[] args) {
		Application.Run(new MainForm());
	}

	private static char GetRandomCharacter(string str, Random rng)
	{
	    int index = rng.Next(str.Length);
	    return str[index];
	}
}

