#include "glut.h"
#include "CoordinateXY.h"

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 400

static CoordinateXY coorxy;

void setPixel(int coorX, int coorY);
void InitWindow();

int main() {
	InitWindow();
	setPixel(10, 10);
}

void InitWindow()
{
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("DDA");
	glMatrixMode(GL_PROJECTION);// sets the current matrix to projection
	glLoadIdentity();//multiply the current matrix by identity matrix
	gluOrtho2D(0.0, WINDOW_WIDTH, WINDOW_HEIGHT, 0);//sets the parallel(orthographic) projection of the full frame buffer 
}
