#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <vector>

#include <GL\glut.h>

#define WIDTH 600.0
#define HEIGHT 600.0

using namespace std;



class Point
{
public:
	float x, y;
	Point(float x, float y);
	~Point();
};

Point::Point(float x, float y) {
	x = x;
	y = y;
}
Point::~Point() {
}

vector<Point*> list;


char keyState = '0';




void draw()
{
	switch (keyState) {
		case '0':
			glBegin(GL_POLYGON);
			break;
		case '1':
			glBegin(GL_POINTS);
			break;
		case '2':
			glBegin(GL_LINES);
			break;
		case '3':
			glBegin(GL_LINE_STRIP);
			break;
		case '4':
			glBegin(GL_LINE_LOOP);
			break;
		case '5':
			glBegin(GL_TRIANGLES);
			break;
		case '6':
			glBegin(GL_TRIANGLE_STRIP);
			break;
		case '7':
			glBegin(GL_TRIANGLE_FAN);
			break;
		case '8':
			glBegin(GL_QUADS);
			break;
		case '9':
			glBegin(GL_QUAD_STRIP);
			break;
	}


	glColor3f(1.0, 0.0, 0.0);


	for (int i = 0; i < list.size(); i++)
		glVertex2f(list[i]->x, list[i]->y);

	glEnd();
}

void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	draw();
	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		list.push_back(new Point(x, y));

		list[list.size() - 1]->x = x;
		list[list.size() - 1]->y = y;

	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && list.size() > 0) {
		delete(list[list.size() - 1]);
		list.pop_back();
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	if (key >= '0' && key <= '9') {
		keyState = key;
	}
	glutPostRedisplay();
}



int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("OpenGL");
	glOrtho(0.0, WIDTH, HEIGHT, 0.0, -1.0, 1.0);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}