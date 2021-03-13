#include <iostream>
#include <stdio.h>
#include <GL/glut.h>

using namespace std;
/// Starting point for vector field (X-coordinate)
int a = 10;
/// Starting point for vector field (Y-coordinate)
int b = 10;

/// Function for drawing a point
/// @param x: describes X-coordinate
/// @param y: describes Y-coordinate
void drawPoint(int x, int y) {
	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f((x / 320.0), (y / 320.0));
	glEnd();
}
/// Function for drawing a line between two points
///
/// Line is drawn by using **Midpoint Line Drawing algorithm** for a line with any slope
/// @param x1,y1: Describe the first point
/// @param x2,y2: Describe the second point
void drawLine(int x1, int y1, int x2, int y2) {
	int dx, dy, i, e;
	int incx = 1, incy = 1, inc1, inc2;
	int x, y;
	dx = x2 - x1;
	dy = y2 - y1;

	if (dx < 0)
		dx = -dx;
	if (dy < 0) dy = -dy;
	if (x2 < x1)
		incx = -1;
	if (y2 < y1)
		incy = -1;
	x = x1; y = y1;
	if (dx > dy) {
		drawPoint(x, y);
		drawPoint(-x, y);
		drawPoint(x, -y);
		drawPoint(-x, -y);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++) {
			if (e >= 0) {
				y = y + incy;
				e = e + inc1;
			}
			else
				e = e + inc2;
			x = x + incx;
			drawPoint(x, y);
			drawPoint(-x, y);
			drawPoint(x, -y);
			drawPoint(-x, -y);
		}

	}
	else {
		drawPoint(x, y);
		drawPoint(-x, y);
		drawPoint(x, -y);
		drawPoint(-x, -y);
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++) {
			if (e >= 0) {
				x = x + incx;
				e = e + inc1;
			}
			else
				e = e + inc2;
			y = y + incy;
			drawPoint(x, y);
			drawPoint(-x, y);
			drawPoint(x, -y);
			drawPoint(-x, -y);
		}
	}
}
/// Function to display the output
///
/// First clears the output viewport, calls the drawLine() function in a loop and displays it
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	for (int j = 1; j <= 20; j++)
	{
		drawLine(a, b, 2 * a, 2 * b);
		if (a < 320)
			a = 2.5*a;
		else
		{
			b = 2.5 * b;
			a = 10;
		}
	}
	glFlush();
}
/// main Function
/// @see https://mathinsight.org/vector_field_overview
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Vector Field of F(x,y) = <x,y>"); // Referred from https://mathinsight.org/vector_field_overview

	glutDisplayFunc(display);

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutMainLoop();

	return 0;
}
