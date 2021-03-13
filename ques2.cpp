#include <iostream>
#include <stdio.h>
#include <GL/glut.h>

using namespace std;
/// Circle center X-coordinate
int x0;
/// Circle center Y-coordinate
int y0;
/// Circle radius
int r;

/// Function for drawing a point
/// @param x: describes X-coordinate
/// @param y: describes Y-coordinate
void drawPoint(int x, int y) {
	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(((x + x0) / 320.0), ((y + y0) / 320.0));
	glEnd();
}

/// Function for drawing a circle 
///
/// Circle is drawn using the **Midpoint Circle Drawing algorithm**
/// Uses global variables x0, y0 and r
void drawCircle()
{
	int x = 0;
	int y = r;
	int d = 1 - r;
	int deltaE = 3;
	int deltaSE = (-2 * r) + 5;

	drawPoint(x, y);

	while (y > x) {
		if (d < 0) {
			d += deltaE;
			deltaE += 2;
			deltaSE += 2;
		}
		else {
			d += deltaSE;
			deltaE += 2;
			deltaSE += 4;
			y--;
		}
		x++;
		//because circle is symmetrical:
		drawPoint(x, y);
		drawPoint(x, -y);
		drawPoint(-x, y);
		drawPoint(-x, -y);
		drawPoint(y, x);
		drawPoint(-y, x);
		drawPoint(y, -x);
		drawPoint(-y, -x);
	}

}
/// Function to display the output
///
/// First clears the output viewport, calls the drawLine() function and displays it
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawCircle();
	glFlush();
}
/// main function
int main(int argc, char** argv)
{
	cout << "Enter the coordinates of the center of the circle:" << endl;

	cout << "x0 : "; cin >> x0;
	cout << "y0 : "; cin >> y0;
	cout << "radius : "; cin >> r;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Midpoint Circle Drawing Algorithm");

	glutDisplayFunc(display);

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutMainLoop();

	return 0;
}
