
using System;
using System.Drawing;
using System.Windows.Forms;

public class MainForm : Form
{
	public MainForm() {
		this.Text = "Demo: double click";
		this.Size = new Size(1280, 720);
		this.MouseDoubleClick
			+= new MouseEventHandler(MainForm_MouseDoubleClick);
		this.BackColor = Color.Black;
	}

	private void MainForm_MouseDoubleClick(object sender, MouseEventArgs e)
	{
		if (e.Button != MouseButtons.Left)
			return;
     	if (Cursor == Cursors.Cross)
			Cursor = Cursors.Hand;
          else
			Cursor = Cursors.Cross;
	}

	public static void Main(string[] args) {
		Application.Run(new MainForm());
	}
}

