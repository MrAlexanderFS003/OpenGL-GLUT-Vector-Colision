class Objetos {
	float posX = 0.0f, posY = 0.0f;
	float posX2 = 0.0f, posY2 = 0.0f;
	int r = 255, g = 255, b = 255;
public:
	Objetos(){}
	void Cuadrado();
	void Linea();
	void Actualiza();

	void setPosX(float valor) { posX = valor; }
	void setPosY(float valor) { posY = valor; }

	float getPosX() { return posX; }
	float getPosY() { return posY; }

	void setPosX2(float valor) { posX2 = valor; }
	void setPosY2(float valor) { posY2 = valor; }

	float getPosX2() { return posX2; }
	float getPosY2() { return posY2; }

	void setRGB(int vR, int vG, int vB) { r = vR; g = vG; b = vB; }
};