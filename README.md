# COLISIONES EN FIGURAS 2D
En este proyecto veremos las colisiones nuevamente, pero, a diferencia del proyecto:

> https://github.com/MrAlexanderFS003/OpenGL-GLUT-Colisiones-de-figuras-en-2D

En este Tendremos mas de una colision, para este caso la libreria vector nos ayudará mucho. Entonces para que los objetos creados con el raton colisionen con algun
objeto, ya sea con el jugador o un objeto en movimiento por el teclado. Tenemos lo siguiente:

```C++
//Codigo de ejemplo (No funcional al copiar y pegar)

void CreaCuadrado(){
  //Creamos el cuadrado o objeto cuando se dio click con el raton
 for (int i = 0; i < gen.size(); i++) {
	gen[i].Cuadrado();
 }
}

void Colision(){
  for (int i = 0; i < gen.size(); i++) {
   //Distancia de dos puntos
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

void Dibuja(){
  //Movimiento del jugador con teclado
  if (tecla.w == 1) { per.setPosY(per.getPosY() + velocidad); }
	if (tecla.s == 1) { per.setPosY(per.getPosY() - velocidad); }
	if (tecla.d == 1) { per.setPosX(per.getPosX() + velocidad); }
	if (tecla.a == 1) { per.setPosX(per.getPosX() - velocidad); }

  CreaCuadrado();
  Colision()
}

void Raton(int btn, int state, int x, int y){
  //Al dar click 
  if(btn == GLUT_LEFT_BUTTON && state == GLUT_UP){
  obj.setPosX(objX); // Objetenos la posicion en X del raton
	obj.setPosY(objY); // Objetenos la posicion en Y del raton
	gen.push_back(obj); // Crear el objeto
  }

}

```

### Uso de la geometría analítica básica
Para saber cuando una figura geométrica colisiona con otra, debemos saber su posición en X y Y en ambas figuras. Para ello se ha usado la formula de distancia entre dos puntos:

$$d = \sqrt {\left( {x_1 - x_2 } \right)^2 + \left( {y_1 - y_2 } \right)^2 }$$

Realizado en el mismo código (Codigo de ejemplo):

```C++
void Actualizar(){
  distancia = sqrt(pow(posX1 - posX2, 2) + pow(posY1 - posY2,2));
  if(distancia <= 10){
    //hay colision
  }
}
```
### Mas colisiones
Para mas colisiones puede usar la siguiente pagina : https://ants.inf.um.es/staff/jlaguna/tp/tutoriales/colisiones/index.html

![Pag](https://user-images.githubusercontent.com/96871746/213083139-1235fc83-b47a-41d4-8bd7-67a14fff48f5.gif)

### Programa en Ejecución:

![GIF](https://user-images.githubusercontent.com/96871746/222968892-9d7b9d02-34a3-4fca-b089-75db75a6c25e.gif)
