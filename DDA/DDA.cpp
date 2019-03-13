#include <stdlib.h>
#include <cmath>
#include "glut.h"
#include "CoordinateXY.h"



#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

static CoordinateXY coorxy;

void setPixel(int coorX, int coorY);
void InitWindow();
void renderScene();

inline int rounda(const float a) {
	return int(a + 0.5);
}
void lineDDA(int x0, int y0, int xend, int yend);

int main() {
	InitWindow();
	glutDisplayFunc(renderScene);
	glutMainLoop();
}

void setPixel(int coorX, int coorY)
{
	coorxy.setx(coorX);
	coorxy.sety(coorY);
	glPointSize(2);
	glBegin(GL_POINTS);
	glVertex2i(coorxy.getx(), coorxy.gety());
	glEnd();
}

void InitWindow()
{
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("DDA");
	glMatrixMode(GL_PROJECTION);// sets the current matrix to projection
	glLoadIdentity();//multiply the current matrix by identity matrix
	gluOrtho2D(0.0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);//sets the parallel(orthographic) projection of the full frame buffer 
}

void renderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);
	lineDDA(0, 300, 400, 20);
	glFlush();
}

void lineDDA(int x0, int y0, int xend, int yend)
{
	int dx = xend - x0, dy = yend - y0, steps;
	double xInc, yInc, x = x0, y = y0;
	if (fabs(dx)>fabs(dy))
	{
		steps = fabs(dx);
	}
	else
	{
		steps = fabs(dy);
	}
	xInc = double(dx) / double(steps);
	yInc = double(dy) / double(steps);
	setPixel(rounda(x), rounda(y));
	for (int i = 0; i < steps; i++)
	{
		x += xInc;
		y += yInc;
		setPixel(rounda(x), rounda(y));
	}
}
