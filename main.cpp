#include <iostream>
#include <string.h>
#include <ctime>
#include <unistd.h>

using namespace std;

//.h & .cpp
#include "definiciones.h"
#include "funciones.cpp"

int main()
{
    //------

    int op=-1;
    bool exit=false;
    string param_string1="";
    string param_string2="";
    int param_int;
    float param_float1;
    float param_float2;

    //------

    while(exit==false){
        cout << "Bienvanido. ELija la opcion." << endl;
        cout << "     "<<"1) Registrar usuario" << endl;
        cout << "     "<<"2) Agregar vehiculo" << endl;
        cout << "     "<<"3) Ingresar Vaije" << endl;
        cout << "     "<<"4) Viajes Antes de Fecha" << endl;
        cout << "     "<<"5) Eliminar Viajes" << endl;
        cout << "     "<<"6) CAmbiar Bateria Vehiculo" << endl;
        cout << "     "<<"7) Obtener Vehiculos" << endl;
        cout << "     "<<"0) Salir" << endl;
        cout << "Opcion:" << endl;
        cin >> op;

        switch(op){
            case 0:
                exit=true;
                break;
            case 1:
                param_string1=SolicitarNombre();
                param_string2=SolicitarCedula();
                RegistrarUsuario(param_string1,param_string2);
                break;
            case 2:
                param_int=SolicitarNroSerieVehiculo();
                param_float1=SolicitarPorcentajeVehiculo();
                param_float2=SolicitarPrecioBaseVehiculo();
                AgregarVehiculo(param_int, param_float1, param_float2);

                break;
            case 3:
                    printV();
                break;
            case 4:
                    printUsuarios();
                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            deafult:
                throw std::invalid_argument("El numero que ingreso no es valido. Intente de nuevo.");
                //cout<<"El numero que ingreso no es valido. Intente de nuevo."<<endl;
        }

    }

    //------

    return 0;

}

