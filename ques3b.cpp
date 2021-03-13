#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

/// Starting point for vector field (X-coordinate)
int a = 10;
/// Starting point for vector field (Y-coordinate)
int b = 10;

/// Function for drawing a point
/// @param x: describes X-coordinate
/// @param y: describes Y-coordinate
/// @param m: describes X-coordinate of varying center of circles
/// @param n: describes Y-coordinate of varying center of circles
void drawPoint(int x, int y, int m, int n)
{
	glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f((x + m) / 320.0, (y + n) / 320.0);
	glVertex2f(-(x + m) / 320.0, (y + n) / 320.0);
	glVertex2f((x + m) / 320.0, -(y + n) / 320.0);
	glVertex2f(-(x + m) / 320.0, -(y + n) / 320.0);
	glEnd();
}

void drawCircle(int m, int n, int r)
{
	int x = 0;
	int y = r;
	int d = 1 - r;
	int deltaE = 3;
	int deltaSE = (-2 * r) + 5;

	drawPoint(x, y, m, n);

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
		drawPoint(x, y, m, n);
		drawPoint(x, -y, m, n);
		drawPoint(-x, y, m, n);
		drawPoint(-x, -y, m, n);
		drawPoint(y, x, m, n);
		drawPoint(-y, x, m, n);
		drawPoint(y, -x, m, n);
		drawPoint(-y, -x, m, n);
	}

}


void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	for (int j = 1; j <= 20; j++)
	{
		int temp1 = 2 * a;
		int temp2 = 2 * b;
		drawCircle(3 * a / 2, 3 * b / 2, sqrt(a * a + b * b) / 2);
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

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Vector Field of F(x,y) = <x,y> with circles");
	glutDisplayFunc(display);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutMainLoop();
	return 0;
}
