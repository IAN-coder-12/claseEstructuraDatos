//Ian Hernández Hernández
//A01276755
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm> 
#include <fstream>
#include <sstream>
#include <iomanip>
#include "./pilotos.h"
#include "./quickSort.h"
#include "./bst.h"


int main(){

    int carrera;
    vector<Piloto*> listaPilotos;
    vector<string> carreras;
    carreras.push_back("MEXICO");
    carreras.push_back("VEGAS");
    carreras.push_back("MONACO");
    carreras.push_back("MIAMI");
    int numCarreras = carreras.size();

    //Pintamos interfaz
    cout<<"\n     --------------- BIENVENIDO A LA FORMULA 1 ------------------\n"<< endl;
    cout<<"\n--------------- Selecciona la carrera que te gustaría ver------------------\n"<< endl;
    cout<<"1. México\n"<< endl;
    cout<<"2. Vegas\n"<< endl;
    cout<<"3. Mónaco\n"<< endl;
    cout<<"4. Miami\n"<< endl;
    cout<<"5. Salir\n"<< endl;
    
    bool existe = true;

    while(existe){
        cout<< "Ingresa el número de carrera: ";
        cin >> carrera;
        
        //Opción para salir del programa
        if(carrera == 5){
            break;
        }
        //Si la carrera seleccionada no existe
        if(carrera > numCarreras || carrera <= 0){
            existe = false;
        }
        if(!existe){
            cout << "\nEsa carrera no esta en la base de datos, por favor ingrese otra carrera\n" << endl;
        }

       //Creamos e imprimimemos los objetos para la carrera seleccionada
        for(int i = 0; i <= numCarreras; i++){
            if(i+1 == carrera){

                Piloto *piloto[4][20];
                //Iniciamos interfaz
                cout << "\n------------- ¡BIENVENIDO AL GRAN PREMIO DE  " << carreras[i] << "! ---------------\n" << endl;
                
                //Lectura de archivos 
                //Creamos una variable para los archivos
                string nombreArch = carreras[i] + ".csv";
                transform(nombreArch.begin(), nombreArch.end(), nombreArch.begin(), ::tolower);
                
                // Abrir archivo CSV
                ifstream archivo(nombreArch); 
                if (!archivo) { // Verificar si el archivo se abrió correctamente
                    cerr << "No se pudo abrir el archivo." << endl;
                }

                vector<string> pilotos;
                vector<string> escuderias;
                vector<double> tiempo;
                vector<int> puntos;
             
                string linea;

                // Leemos el archivo línea por línea
                while (getline(archivo, linea)) {
                    stringstream ss(linea);
                    string valor;
                    int columna = 0;
                    double segundos_totales;
                    

                    // Leemos los valores separados por comas
                    while (getline(ss, valor, ',')) {
                        stringstream ss(valor);

                        switch (columna) {
                            case 0:
                                pilotos.push_back(valor); // Agregar a la pilotos
                                break;
                            case 1:
                                escuderias.push_back(valor); // Agregar a la columna escuderias
                                break;
                            case 2:
                                //Pasamos el formato horas-string a segundos de ttipo double
                                int horas, minutos, segundos, milisegundos;
                                char separador; // Para almacenar los caracteres separadores ':', '.' 
                                // Extraer horas, minutos, segundos y milisegundos
                                ss >> horas >> separador >> minutos >> separador >> segundos >> separador >> milisegundos;
                                
                                // Convertir todo a segundos
                                if(horas == 0){
                                    segundos_totales = 10101;
                                    tiempo.push_back(segundos_totales); 
                                    break;
                                }else{
                                    segundos_totales = (horas * 3600) + (minutos * 60) + segundos + (milisegundos / 1000.0);
                                    tiempo.push_back(segundos_totales); // Agregar a la columna tiempo
                                    break;
                                }
                            case 3:
                                puntos.push_back(stoi(valor)); // Agregar a la columna puntos
                                break;
                        }
                        columna++;
                    }
                }
                archivo.close(); // Cerrar el archivo
                cout << "<<<<<<<<<<<<< PARRILLA DE SALIDA >>>>>>>>>>>>>>>\n" << endl;
                cout << "\nPosiciones de salida obtenidas de acuerdo a la Qualy de un dia anterior*\n" << endl;
                //imprimimos tabla
                cout << "Pos." << setw(15) << "Piloto" << setw(21) << "Escuderia" << endl;
                cout << setw(15) << setfill('-') << setw(48) << "-" << setfill(' ') << endl;
                for(int j = 1; j <= 20; j++){

                            piloto[i][j] = new Piloto(pilotos[j-1], escuderias[j-1], tiempo[j-1], puntos[j-1]);
                            cout << setw(5) << j; piloto[i][j] -> parrillaSalida();
                            listaPilotos.push_back(new Piloto(pilotos[j-1], escuderias[j-1], tiempo[j-1], puntos[j-1]));
                
                }
            }
        }
        //Ordenamos los pilotos
        quickSort(listaPilotos, 0, listaPilotos.size() - 1);

        cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  MARCADOR FINAL  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n" << endl;
         // Imprimir el encabezado de la tabla
        cout << "Pos." << setw(15) << "Piloto" << setw(21) << "Escuderia" << setw(15) << "Tiempo(s)" << setw(15) << "Puntos" << endl;
        cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;

        for(int i = 0; i < listaPilotos.size(); i++){
            cout << i + 1 << ". " << listaPilotos[i]->info();
        }

        cout << endl;
        cout << "IMPORTANTE: Los pilotos con tiempo 10101 significa que no terminaron la carrera, por algún choque o fallas en el auto." << endl;
        cout << "\nNOTA: Los resultados coninciden con los de las carreras de la temporada 2023\n" << endl;
        
        //Ingresa un piloto nuevo
        char continuar;
        cout << "\n¿Hay algun piloto que te gustaría agregar a la carrera? (s/n): ";
        cin >> continuar;
        while(continuar == 's' || continuar == 'S'){
            ArbolBinario<Piloto> arbolPilotos;
            string nombreN;
            string escuderiaN;
            string tiempoN;
            
            //Pedimos al usuario los datos
            cout << "Nombre del piloto: "; 
            cin >> nombreN;
            cout << "Nombre de la escuderia: "; 
            cin >> escuderiaN;
            cout << "Tiempo de carrera en formato (hrs:min:seg): "; 
            cin >> tiempoN;

            //Pasamos el formato horas-string a segundos de tipo double
            int horas, minutos, segundos, milisegundos;
            double tiempoSegundos; 
            char separador; // Para almacenar los caracteres separadores ':', '.' 
            istringstream ss(tiempoN);
            
            // Extraer horas, minutos, segundos y milisegundos
            ss >> horas >> separador >> minutos >> separador >> segundos >> separador >> milisegundos;
            tiempoSegundos = (horas * 3600) + (minutos * 60) + segundos;

            // Creamos un arbol binario con la lista de pilotos
            for(int i = 0; i < listaPilotos.size(); i++){    
                arbolPilotos.insertarP(listaPilotos[i]);
            }

            //Creamos e insertamos nuevo piloto
            Piloto* pilotoN = new Piloto(nombreN, escuderiaN, tiempoSegundos, 0);
            arbolPilotos.insertarP(pilotoN);
            cout << "\n¡Piloto agregado exitosamente!\n";
            
            // Imprimimos el arbol inorder
            cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  MARCADOR ACTUALIZADO  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n\n" << endl;
            cout << "\nPos." << setw(15) << "Piloto" << setw(21) << "Escuderia" << setw(15) << "Tiempo(s)" << setw(15) << "Puntos" << endl;
            cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
            arbolPilotos.imprimir();

            cout << "¿Desea agregar otro piloto? (s/n): ";
            cin >> continuar;
            if(continuar == 's' || continuar == 'S'){
                existe =true;
            }else{
                break;
            }

        }

        //Ingresar otra carrera
        cout << "\n¿Desea ver otra carrera? (s/n): ";
        cin >> continuar;
        if(continuar == 's' || continuar == 'S'){
            existe =true;
            listaPilotos.clear();
        }else{
            break;
        }


        
    }
    cout << "\n------------ Gracias por ver la FORMULA 1 ------------\n" << endl;

}
