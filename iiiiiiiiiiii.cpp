#include <iostream>
using namespace std;

int main() {

    string jugador;
    int vida, ataque, defensa;
    bool estavivo = true;
    bool tienellave = false;
    float probabilidadesquivar = 0.1f;

    cout << "Ingrese el nombre del jugador: ";
    cin >> jugador;

    cout << "Ingrese la vida del jugador: ";
    cin >> vida;

    cout << "Ingrese el ataque del jugador: ";
    cin >> ataque;

    cout << "Ingrese la defensa del jugador: ";
    cin >> defensa;

    //agrega mates por aqui de la probabilidad de esquivar

    cout << "=======Ficha del jugador=======" << endl;

    cout << "Jugador: " << jugador << endl;
    cout << "Vida:    " << vida << endl;
    cout << "Ataque:  " << ataque << endl;
    cout << "Defensa: " << defensa << endl;
    cout << "Esta vivo? " << estavivo << endl;
    cout << "Probabilidad de esquivar base: " << probabilidadesquivar << endl;

    return 0;

}