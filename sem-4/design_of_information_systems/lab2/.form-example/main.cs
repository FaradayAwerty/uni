
using System;
using System.Drawing;
using System.Windows.Forms;

public class MyForm : Form
{
	Label label1 = new Label();

	public MyForm() {
		this.label1.Text = "Hello, World!";
		this.label1.Location = new Point(100, 100);
		this.Controls.Add(label1);

		this.Text = "MainForm Title!";
		this.Size = new Size(1280, 720);
		this.FormBorderStyle = FormBorderStyle.FixedSingle;
	}
}

public class MainClass
{
	public static void Main(string[] args) {
		Application.Run(new MyForm());
	}
}

