#include <iostream>
#pragma once

using namespace std;

class Barcos
{
private:

	int HP;
	int Velocidad;
	int Distancia;
	int Nitro;
	string Name;

public:

	Barcos();
	Barcos(string Name, int Velocidad, int Distancia, int Nitro);
	int getHP();
	void setHP(int pHP);
	string getName();
	void setName(string pName);
	int getVelocidad();
	void setVelocidad(int pVelocidad);
	int getDistancia();
	void setDistancia(int pDistancia);
	int getNitro();
	void setNitro(int pNitro);
	void realizarTurno();
	void realentizar(Barcos& objetivo);

};

