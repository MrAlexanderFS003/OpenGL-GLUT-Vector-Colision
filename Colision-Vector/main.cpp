/*
	Hecho por Max Flores Saldaña , Usando la programación orientada a Objetos en C++.
	Si desea ver la documentacion de GLUT: https://www.opengl.org/resources/libraries/glut/spec3/spec3.html
*/

#include "Objetos.h"
#include "Persona.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

//Tamaño de la ventana
#define ANCHO 800
#define ALTO 600

//Objetos
Objetos obj; vector<Objetos> gen;
Persona per;

//Variables usadas para almacenar los calculos obtenidos
float objX = 20.0f, objY = 20.0f, MobjX = 0.0f, MobjY = 0.0f;
float velocidad = 0.01f;
int valor = 0, cont = 0, val = 0, win = 0;

typedef struct {
	int w, a, d, s;
}BotonTeclas; BotonTeclas tecla;

void Init() {
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-50, 50, -50, 50);
}

void CrearCudrado() {
	for (int i = 0; i < gen.size(); i++) {
		gen[i].Cuadrado();
	}
}


void DistanciaLine() {
	glPushMatrix();
	for (int i = 0; i < gen.size(); i++) {
		glLineWidth(1);
		glBegin(GL_LINES);
		glVertex2f(gen[i].getPosX(), gen[i].getPosY());
		glVertex2f(per.getPosX(), per.getPosY());
		glEnd();
	}
	glPopMatrix();
}


void Colision() {
	for (int i = 0; i < gen.size(); i++) {
		float distancia = sqrt(pow(gen[i].getPosX() - per.getPosX(), 2) + pow(gen[i].getPosY() - per.getPosY(), 2));
		if (distancia <= 2) {
			gen[i].setRGB(255, 0, 0); // El color del objeto cambia a rojo
			// Al invertir los signos/operadores del movimiento del jugador/Persona
			// Obtenemos un movimiento nulo, con esto tendremos una colision un poco mas limpia.
			if (tecla.w == 1) { per.setPosY(per.getPosY() - velocidad); }
			if (tecla.s == 1) { per.setPosY(per.getPosY() + velocidad); }
			if (tecla.d == 1) { per.setPosX(per.getPosX() - velocidad); }
			if (tecla.a == 1) { per.setPosX(per.getPosX() + velocidad); }
		}
		else {
			gen[i].setRGB(255, 255, 255); // Restablece color
		}
	}
}

void Dibuja() {
	glClear(GL_COLOR_BUFFER_BIT);

	// Movimiento del Jugador 2D
	if (tecla.w == 1) { per.setPosY(per.getPosY() + velocidad); }
	if (tecla.s == 1) { per.setPosY(per.getPosY() - velocidad); }
	if (tecla.d == 1) { per.setPosX(per.getPosX() + velocidad); }
	if (tecla.a == 1) { per.setPosX(per.getPosX() - velocidad); }

	per.Dibuja();
	CrearCudrado();
	//DistanciaLine();
	
	Colision();
	
	glutSwapBuffers();
}

void Actualiza() {	glutPostRedisplay(); }

//Posicion del raton
void Raton(int btn, int state, int x, int y) {
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		objX = (x - (ANCHO / 2)) * 100 / ANCHO;
		objY = ((ALTO / 2) - y) * 100 / ALTO;
		obj.setPosX(objX); // Objetenos la posicion en X del raton
		obj.setPosY(objY); // Objetenos la posicion en Y del raton
		gen.push_back(obj); // Guardamos los objetos creados 

		MobjX = objX;
		MobjY = objY;
		valor = state;
	}

	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
		gen.clear(); //Al Precionar el bton derecho del raton limpiara el vector de objetos/ Borra la pantalla
	}
}

void TecladoAbajo(unsigned char teclas, int x, int y) {
	if (teclas == 'w') { tecla.w = 1; }
	if (teclas == 's') { tecla.s = 1; }
	if (teclas == 'a') { tecla.a = 1; }
	if (teclas == 'd') { tecla.d = 1; }

	switch (teclas) {
	case 27:
		exit(0);
	default:
		break;
	}
	glutPostRedisplay();
}

void TecladoArriba(unsigned char teclas, int x, int y) {
	if (teclas == 'w') { tecla.w = 0; }
	if (teclas == 's') { tecla.s = 0; }
	if (teclas == 'a') { tecla.a = 0; }
	if (teclas == 'd') { tecla.d = 0; }
	glutPostRedisplay();
}


void redimensionar(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 500.0);
}

int main() {
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(ANCHO, ALTO);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("COLISION-VECTOR"); // El valor de la ventana creada se guarda en una variable

	Init();
	glutDisplayFunc(Dibuja);
	glutIdleFunc(Actualiza);
	glutMouseFunc(Raton);
	glutKeyboardFunc(TecladoAbajo); 
	glutKeyboardUpFunc(TecladoArriba); 
	glutMainLoop();
	return 0;
}