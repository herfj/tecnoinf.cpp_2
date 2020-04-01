#include <iostream>
#include <string.h>
#include <ctime>
#include <unistd.h>

using namespace std;

//.h & .cpp
#include "definiciones.h"
#include "funciones.cpp"

//#include "Usuario.cpp"
//#include "Viaje.cpp"
//#include "Vehiculo.cpp"

int main()
{
    //------

    int op=-1;
    bool exit=false;
    string param_string1="";
    string param_string2="";
    int param_int;
    int param_int2;
    int param_int3;
    float param_float1;
    float param_float2;
    DtFecha fecha;

    //------

    while(exit==false){
        cout << "Bienvanido. ELija la opcion." << endl;
        cout << "     "<<"1) Registrar usuario" << endl;
        cout << "     "<<"2) Agregar vehiculo" << endl;
        cout << "     "<<"3) Ingresar Vaije" << endl;
        cout << "     "<<"4) Viajes Antes de Fecha" << endl;
        cout << "     "<<"5) Eliminar Viajes" << endl;
        cout << "     "<<"6) Cambiar Bateria Vehiculo" << endl;
        cout << "     "<<"7) Obtener Vehiculos" << endl;
        cout << "     "<<"0) Salir" << endl;
        cout << "Opcion:" << endl;
        cin >> op;

        switch(op){
            case 0:
                exit=true;
                break;
            case 1:
                cout << "Registrar Usuario" << endl;
                param_string1=SolicitarString("Nombre");
                param_string2=SolicitarString("Cedula");
                RegistrarUsuario(param_string1,param_string2);
                break;
            case 2:
                cout << "Registrar Vehiculo" << endl;
                param_int=SolicitarInt("nro Serie");
                do{
                    param_float1=SolicitarFloat("Porcentaje Bateria");
                    if((param_float1>100) && (param_float1<0)){
                        cout << "          El porcentaje de bateria no es aceptable, ingreselo nuevamente" << endl;
                    }
                }while((param_float1>100) && (param_float1<0));
                do{
                    param_float2=SolicitarFloat("Precio Base");
                    if(param_float2<=0){
                        cout << "          El Precio Base debe ser positivo, ingreselo nuevamente" << endl;
                    }
                }while(param_float2<=0);


                AgregarVehiculo(param_int, param_float1, param_float2);

                break;
            case 3:
                cout << "Ingrese la ci" << endl;
                    cin >> param_string1;
                    cout << "Ingrese el nro de serie" << endl;
                    cin >> param_int;
                    cout << "Ingrese la duracion del viaje." << endl;
                    cin >> param_int2;
                    cout << "Ingrese la distancia del viaje" << endl;
                    cin >> param_int3;
                    cout << "Ingrese el anio:";
                    cin >> fecha.anio;
                    cout << "Ingrese el mes:";
                    cin >> fecha.mes;
                    cout << "Ingrese el dia";
                    cin >> fecha.dia;
                    IngresarViaje(param_string1,param_int,param_int2,param_int3,fecha);
                break;
            case 4:
                    printUsuarios();
                break;
            case 5:
                printV();
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
