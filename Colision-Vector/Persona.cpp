#include "Persona.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void Persona::Dibuja() {
	glPushMatrix();
	glLineWidth(1);
	glTranslatef(TposX, TposY, 0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 20; i++) {
		posX = radio * cos(i);
		posY = radio * sin(i);
		glVertex2f(posX,posY);
	}
	glEnd();
	glPopMatrix();
}

void Persona::Actualiza() {
	glutPostRedisplay();
}