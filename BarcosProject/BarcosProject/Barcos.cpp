#include "Barcos.h"
#include <iostream>

// colores
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

using namespace std;

Barcos::Barcos() {
    Velocidad = 100;
}
Barcos::Barcos(string pName, int pVelocidad, int pDistancia, int pNitro) {

    Name = pName;
    Velocidad = pVelocidad;
    Distancia = pDistancia;
    Nitro = pNitro;

}


int Barcos::getHP() {
    return HP;
}

void Barcos::setHP(int pHP) {
    HP = pHP;
}

int Barcos::getVelocidad() {
    return Velocidad;
}

void Barcos::setVelocidad(int pVelocidad) {
    Velocidad = pVelocidad;
}

int Barcos::getDistancia() {
    return Distancia;
}

void Barcos::setDistancia(int pDistancia) {
    Distancia = pDistancia;
}

int Barcos::getNitro() {
    return Nitro;
}

void Barcos::setNitro(int pNitro) {
    Nitro = pNitro;
}

string Barcos::getName() {
    return Name;
}

void Barcos::setName(string pName) {
    Name = pName;
}

void Barcos::realizarTurno() {
    int dado = rand() % 6 + 1;
    system("pause");
    cout << "Lanzamiento del dado: " << dado << endl;

    //Sumar los puntos obtenidos en el dado a la velocidad actual
    Velocidad += dado;

    //Calcular la distancia recorrida en este turno sin contar el nitro
    int distanciaRecorrida = Velocidad * 100;

    if (Nitro > 0) {
        string usarNitro;
        do {
            cout << "Quieres usar el nitro? Solo se puede usar 1 vez! (1: Si, 0: No): ";
            cin >> usarNitro;
            if (usarNitro != "0" && usarNitro != "1") {
                cout << "Entrada incorrecta! Por favor, ingrese 1 (usar nitro) o 0 (no usarlo)." << endl;
            }
        } while (usarNitro != "0" && usarNitro != "1");

        if (usarNitro == "1") {

            // Ejecutar un número aleatorio entre 0 y 1
            int probabilidadNitro = rand() % 2;
            if (probabilidadNitro == 0) {
                // Dividir la velocidad total por la mitad
                Velocidad /= 2;
                cout << "¡Nitro fallido! Velocidad reducida a la mitad." << endl;
            }
            else {
                // Multiplicar la velocidad total por dos
                Velocidad *= 2;
                cout << "¡Nitro exitoso! Velocidad duplicada." << endl;
            }
            Nitro--; //restar nitro
        }
    }
    else {
        cout << "Ya no tienes nitro disponible." << endl;
    }

    // Actualizar la distancia recorrida con la velocidad modificada por el nitro
    distanciaRecorrida = Velocidad * 100;

    // Actualizar la distancia total
    Distancia += distanciaRecorrida;

    cout << "----------------JUGADOR " << Name << "----------------" << endl;
    cout << "Velocidad actual: " << Velocidad << endl;
    cout << "Distancia recorrida: " << distanciaRecorrida << endl;
    cout << "-----------------------------------------------" << endl;
}

void Barcos::realentizar(Barcos& objetivo) {
    //dado
    int dado = rand() % 6 + 1;

    cout << "Disparos al barco contrario: " << dado << endl;

    //Calcular la nueva velocidad del barco objetivo
    int nuevaVelocidad = objetivo.getVelocidad() - dado;
    if (nuevaVelocidad < 0) {
        nuevaVelocidad = 0;
    }
    objetivo.setVelocidad(nuevaVelocidad);

    cout << "El barco " << objetivo.getName() << " ha sido realentizado!" << endl;
}
