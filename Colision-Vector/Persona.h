class Persona {
	float TposX = 10.0f, TposY = 10.0f;
	float posX = 0.0f, posY = 0.0f;
	float radio = 1.0f;
public:
	Persona(){}
	void Dibuja();
	void Actualiza();

	void setPosX(float valor) { TposX = valor; }
	void setPosY(float valor) { TposY = valor; }

	float getPosX() { return TposX; }
	float getPosY() { return TposY; }
};
