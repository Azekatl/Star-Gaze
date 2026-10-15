#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <vector>
using namespace std;

//Creación de las clases y equipamientos

class Equipamiento
{
private:
string nombreItem;
string descripcionItem;
int calidadItem;
public:
Equipamiento(string nombre,string descripcion,int calidad,int cantidadUso):
nombreItem(nombre), descripcionItem(descripcion), calidadItem(calidad){}
string obtenerNombreItem() { return nombreItem;}
};

class Personaje{
private:
    string nombrePersonaje;
    int vidaPersonaje;
    bool personajeVivo;
    int danioPersonaje;
    vector<Equipamiento> items;
public:
    Personaje(string nombreJugador,int vidaJugador,bool estaVivo,int danioJugador):
    nombrePersonaje(nombreJugador), vidaPersonaje(vidaJugador), personajeVivo(estaVivo), danioPersonaje(danioJugador){}
    void avanzar(string nombrePersonaje)

    {
    cout << nombrePersonaje << " avanza con precaución" << endl;
    }
void recibirDanio(string nombrePersonaje, int danio)
{
vidaPersonaje -= danio;
if (vidaPersonaje < 0)
{
vidaPersonaje = 0;
personajeVivo = false;

}
cout << nombrePersonaje << " recibió " << danio << " de daño." << endl;
cout << "La vida que le queda es " << vidaPersonaje << "!" << endl;
}
void verEstado(string nombrePersonaje)
{
string alerta = "";
if (0 < vidaPersonaje && vidaPersonaje <= 25)
{
alerta = "Vida demasiado baja!";
}
else
{
alerta = "";
}
cout << "Estado actual de " << nombrePersonaje << endl;
cout << "Vida restante: " << vidaPersonaje << endl;
cout << "Está Vivo? " << (personajeVivo == true ? "Si" : "No") << endl;
cout << alerta << endl;
}
void obtenerEquipamiento(Equipamiento item){
if(items.size() <= 6){
items.push_back(item);
cout << "Item obtenido: " << item.obtenerNombreItem() << endl;
}
}
virtual void atacar(){};
};

//herencia
class Berserk : public Personaje
{
private:
string arma;
string cyberware;
public:
Berserk(string nombreJugador,int vidaJugador,bool estaVivo,int danioJugador,string armaBerserk,string cyberwareBerserk):
Personaje(nombreJugador, vidaJugador, estaVivo, danioJugador),
arma(armaBerserk), cyberware(cyberwareBerserk){}
void atacar()override{
cout << "Su choom atacó con " << arma << "." << endl;
}
};

class Mercenario : public Personaje
{
private:
string arma;
string armadura;
public:
Mercenario(string nombreJugador,int vidaJugador,bool estaVivo,int danioJugador,string armaMercenario,string cyberwareMercenario):
Personaje(nombreJugador, vidaJugador, estaVivo, danioJugador),
arma(armaMercenario), armadura(cyberwareMercenario){}
void atacar()override{
cout << "Su choom atacó con " << arma << "." << endl;
}
};

class Netrunner : public Personaje
{
private:
string arma;
string cyberware;
public:
Netrunner(string nombreJugador,int vidaJugador,bool estaVivo,int danioJugador,string armaNetrunner,string cyberwareNetrunner):
Personaje(nombreJugador, vidaJugador, estaVivo, danioJugador),
arma(armaNetrunner), cyberware(cyberwareNetrunner){}
void atacar()override{
cout << "Su choom atacó con " << arma << "." << endl;
}
};


int main()
{

SetConsoleOutputCP(CP_UTF8);

    ////estoy como los programadores de valve, volviéndome loco
    //variables base para el personaje que se utilizará

        int opcion = 0;
        int tipoPersonaje = 0;
        string nombrePersonaje = "";
        int vidaPersonaje = 0;
        bool personajeVivo = true;
        int danioPersonaje = 0;
        Personaje* jugador = nullptr;

    //variables para el equipo qué tendrán el choom
        string nombreEquipamiento = "Núcleo Mecatrónico";
        string descripcionEquipamiento = "Da un bonus de daño del personaje en 10 desde la corteza cerebral";
        int calidadEquipamiento = 7;
        int cantidadUso = 2;

    //variables para arma y el cyberware
        string armaSeleccionada;
        string cyberwareSeleccionado;

    //información inicial como nombre y vida
        cout << "Indique el nombre de su personaje: " << endl;
        getline(cin, nombrePersonaje);
        cout << "Indique la vida incial de " << nombrePersonaje << ":" << endl;
        cin >> vidaPersonaje;

    //inicio de selección de clases
        cout << "Choom, no hay orígenes en esté caso, así que tendrá que elegir entre 3 clases distintas" << endl;
        cout << "Seleccione su clase" << endl;
        cout << "[1] Berserk." << endl;
        cout << "[2] Mercenario." << endl;
        cout << "[3] Netrunner." << endl;
        cin >> tipoPersonaje;
        switch (tipoPersonaje)

{
    case 1:
        armaSeleccionada = "Martillo";
        cyberwareSeleccionado = "Brazos de gorila";
        jugador = new Berserk(nombrePersonaje,vidaPersonaje,personajeVivo,danioPersonaje,armaSeleccionada,cyberwareSeleccionado);
        cout << nombrePersonaje << " ahora es un Berserk loco" << endl;
        cout << "Hará uso del cyberware " << cyberwareSeleccionado << " y sin piedad hará uso de su " << armaSeleccionada << endl;
        break;

        case 2:
            armaSeleccionada = "Guts"; 
            cyberwareSeleccionado = "Militech Apoge";
            jugador = new Mercenario(nombrePersonaje,vidaPersonaje,personajeVivo,danioPersonaje,
            armaSeleccionada,cyberwareSeleccionado);
            cout << nombrePersonaje << " ahora es un Mercenario intrepido" << endl;
            cout << "Hará uso del cyberware " << cyberwareSeleccionado << " y despedazará con su " << armaSeleccionada << endl;
            break;
    
            case 3:
                armaSeleccionada = "Monocable térmico";
                cyberwareSeleccionado = "Militech Mk 5";
                jugador = new Netrunner(nombrePersonaje,vidaPersonaje,personajeVivo,danioPersonaje,armaSeleccionada,cyberwareSeleccionado);
                cout << nombrePersonaje << " ahora es un Netrunner especializado" << endl;
                cout << "Hará uso del cyberware" << cyberwareSeleccionado << ", cortará y quemará con su " << armaSeleccionada << endl;
                break;
 }

            // Personaje jugador(nombrePersonaje, vidaPersonaje, personajeVivo, danioPersonaje);
    Equipamiento nucleo(nombreEquipamiento,descripcionEquipamiento,calidadEquipamiento,cantidadUso);

 {
    cout << "\nSeleccione su opción" << endl;
    cout << "[1] Moverse adelante." << endl;
    cout << "[2] Recibir daño." << endl;
    cout << "[3] Revisar estado " << nombrePersonaje << "." << endl;
    cout << "[4] Atacar." << endl;
    cout << "[5] Salir." << endl;
    cin >> opcion;
    switch (opcion)

    {
        case 1:
        jugador->avanzar(nombrePersonaje);
        break;
            case 2:
            cout << "Ingrese el daño a recibir: " << endl;
            cin >> danioPersonaje;
            jugador->recibirDanio(nombrePersonaje,danioPersonaje);
            break;
                case 3:
                jugador->verEstado(nombrePersonaje);
                break;
                    break;
                        case 4:
                        jugador->atacar();
                        break;
                            case 5:
                            cout << "Saliendo..." << endl;
                                exit(0);
                                break;
                                default:
                                cout << "Intente con una opción valida, carne fresca" << endl;
                    }
 //no tuve motivación para ver el tema de equipamiento o hacer esto de manera general
 // mi error por ello algo debo entregar al menos aunque no este completo
 
}
return 0;

}
