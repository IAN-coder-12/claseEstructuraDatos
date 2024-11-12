#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Piloto{
    public:
        string nombre;
        string escuderia;
        float tiempo;
        int puntos;

        Piloto(const string& nombre, const string& escuderia, float tiempo, int puntos);
        string info();
        void parrillaSalida();
        float getTiempo(){return tiempo;}
        string getNombre() const {
            return nombre;
        }

};


Piloto::Piloto(const string& _nombre, const string& _escuderia, float _tiempo, int _puntos){
    nombre= _nombre;
    escuderia = _escuderia;
    tiempo = _tiempo;
    puntos = _puntos;
}


void Piloto::parrillaSalida(){
     cout << setw(20) << nombre << setw(20) << escuderia << endl;
}
string Piloto::info(){
    ostringstream oss;
     oss << setw(20) << nombre << setw(20) << escuderia << setw(15) << tiempo << setw(15) << puntos << endl;
     return oss.str();
}
