#include "Objetos.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void Objetos::Cuadrado() {
	glPushMatrix();
	glPointSize(10);
	glTranslatef(posX,posY,0);
	glColor3ub(r,g,b);
	glBegin(GL_POINTS);
	glVertex2d(0,0);
	glEnd();
	glPopMatrix();
}

void Objetos::Linea() {
	glPushMatrix();
	glBegin(GL_LINES);
	glVertex2f(posX,posY);
	glVertex2f(posX2,posY2);
	glEnd();
	glPopMatrix();
}

void Objetos::Actualiza() {
	glutPostRedisplay();
}