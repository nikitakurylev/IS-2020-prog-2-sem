#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "RubiksCube.hpp"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

//Screen constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;
const float CUBESIZE = 30.f;

bool initGL(int argc, char* args[])
{
	//Initialize FreeGLUT
	glutInit(&argc, args);

	//Create OpenGL 2.1 context
	glutInitContextVersion(2, 1);

	//Create Double Buffered Window
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("OpenGL");

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0);

	//Initialize Modelview Matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Initialize clear color
	glClearColor(0.f, 0.f, 0.f, 1.f);

	//Check for error
	GLenum error = glGetError();
	if (error != GL_NO_ERROR)
	{
		printf("Error initializing OpenGL! %s\n", gluErrorString(error));
		return false;
	}

	return true;
}

void DrawCube(RubiksCube rc) {
	//Clear color buffer
	glClear(GL_COLOR_BUFFER_BIT);

	//Reset modelview matrix
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Move to center of the screen
	glTranslatef(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			glBegin(GL_QUADS);
			if (rc.faces[1][i][j] == 'G')
				glColor3f(0.f, 1.f, 0.f);
			else if (rc.faces[1][i][j] == 'R')
				glColor3f(1.f, 0.f, 0.f);
			else if (rc.faces[1][i][j] == 'G')
				glColor3f(0.f, 1.f, 0.f);
			else if (rc.faces[1][i][j] == 'B')
				glColor3f(0.f, 0.f, 1.f);
			else if (rc.faces[1][i][j] == 'O')
				glColor3f(1.f, 0.5f, 0.f);
			else if (rc.faces[1][i][j] == 'W')
				glColor3f(1.f, 1.f, 1.f);
			else
				glColor3f(1.f, 1.f, 0.f);
			int xoffset = i * CUBESIZE;
			int yoffset = j * CUBESIZE;
			glVertex2f(xoffset, yoffset);
			glVertex2f(xoffset + CUBESIZE, yoffset);
			glVertex2f(xoffset + CUBESIZE, yoffset + CUBESIZE);
			glVertex2f(xoffset, yoffset + CUBESIZE);
			glEnd();
		}
	glTranslatef(-3.f * CUBESIZE, -3.f * CUBESIZE, 0.f);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			glBegin(GL_QUADS);
			if (rc.faces[0][i][j] == 'G')
				glColor3f(0.f, 1.f, 0.f);
			else if (rc.faces[0][i][j] == 'R')
				glColor3f(1.f, 0.f, 0.f);
			else if (rc.faces[0][i][j] == 'G')
				glColor3f(0.f, 1.f, 0.f);
			else if (rc.faces[0][i][j] == 'B')
				glColor3f(0.f, 0.f, 1.f);
			else if (rc.faces[0][i][j] == 'O')
				glColor3f(1.f, 0.5f, 0.f);
			else if (rc.faces[0][i][j] == 'W')
				glColor3f(1.f, 1.f, 1.f);
			else
				glColor3f(1.f, 1.f, 0.f);
			int xoffset = i * CUBESIZE;
			int yoffset = xoffset + j * CUBESIZE;
			glVertex2f(xoffset, yoffset);
			glVertex2f(xoffset + CUBESIZE, yoffset + CUBESIZE);
			glVertex2f(xoffset + CUBESIZE, yoffset + CUBESIZE + CUBESIZE);
			glVertex2f(xoffset, yoffset + CUBESIZE);
			glEnd();
		}

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			glBegin(GL_QUADS);
			if (rc.faces[4][i][j] == 'G')
				glColor3f(0.f, 1.f, 0.f);
			else if (rc.faces[4][i][j] == 'R')
				glColor3f(1.f, 0.f, 0.f);
			else if (rc.faces[4][i][j] == 'G')
				glColor3f(0.f, 1.f, 0.f);
			else if (rc.faces[4][i][j] == 'B')
				glColor3f(0.f, 0.f, 1.f);
			else if (rc.faces[4][i][j] == 'O')
				glColor3f(1.f, 0.5f, 0.f);
			else if (rc.faces[4][i][j] == 'W')
				glColor3f(1.f, 1.f, 1.f);
			else
				glColor3f(1.f, 1.f, 0.f);
			int yoffset = j * CUBESIZE;
			int xoffset = yoffset + i * CUBESIZE;
			glVertex2f(xoffset, yoffset);
			glVertex2f(xoffset + CUBESIZE, yoffset);
			glVertex2f(xoffset + CUBESIZE + CUBESIZE, yoffset + CUBESIZE);
			glVertex2f(xoffset + CUBESIZE, yoffset + CUBESIZE);
			glEnd();
		}

	//Update screen
	glutSwapBuffers();
}

#endif