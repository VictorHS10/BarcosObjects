#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include "Barcos.h"

// colores
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

using namespace std;

int main() {
    srand(time(0));

    string nombreBarco1;
    string nombreBarco2;

    cout << RED << "Ingrese el nombre del primer barco: " << RESET;
    cin >> nombreBarco1;

    cout << BLUE << "Ingrese el nombre del segundo barco: " << RESET;
    cin >> nombreBarco2;

    Barcos barco1(nombreBarco1, 0, 0, 1);
    Barcos barco2(nombreBarco2, 0, 0, 1);

    bool disparoBarco1 = false; 
    bool disparoBarco2 = false;

    for (int turno = 1; turno <= 5; turno++) {
        cout << GREEN << "------------- Turno " << turno << " -------------" << RESET << endl;

        cout << RED << "Turno de " << barco1.getName() << ":" << RESET << endl;
        barco1.realizarTurno();

        // Barco 1 dispara solo si no ha disparado antes y decide hacerlo
        if (!disparoBarco1 && turno > 1) {
            cout << "Quieres disparar a " << barco2.getName() << " para realentizarlo? (1: Si, 0: No): ";
            int disparar1;
            cin >> disparar1;
            if (disparar1 == 1) {
                barco1.realentizar(barco2); //Barco 1 dispara a barco 2
                disparoBarco1 = true; //Barco 1 ya disparó
            }
        }

        cout << endl;
        system("pause");

        cout << BLUE << "Turno de " << barco2.getName() << ":" << RESET << endl;
        barco2.realizarTurno();

        //barco 2 dispara solo si no ha disparado antes.
        if (!disparoBarco2 && turno > 1) {
            cout << "Quieres disparar a " << barco1.getName() << " para realentizarlo? (1: Si, 0: No): ";
            int disparar2;
            cin >> disparar2;
            if (disparar2 == 1) {
                barco2.realentizar(barco1); //Barco 2 dispara a barco 1
                disparoBarco2 = true; //Barco 2 ya disparó
            }
        }

        cout << endl;
        system("pause");
    }
// Resultados Finales.
    cout << "------------- Resultado Final -------------" << endl;
    cout << RED << "Distancia recorrida por " << barco1.getName() << ": " << barco1.getDistancia() << RESET << endl;
    cout << BLUE << "Distancia recorrida por " << barco2.getName() << ": " << barco2.getDistancia() << RESET << endl;

    if (barco1.getDistancia() > barco2.getDistancia()) {
        cout << GREEN << "El barco de " << barco1.getName() << " ha ganado la carrera!" << RESET << endl;
    }
    else if (barco1.getDistancia() < barco2.getDistancia()) {
        cout << GREEN << "El barco de " << barco2.getName() << " ha ganado la carrera!" << RESET << endl;
    }
    else {
        cout << "Ha habido un empate!" << endl;
    }

    return 0;
}
