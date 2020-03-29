#include <iostream>
#include <unistd.h> //HOLA JACOMO bbte
#include <string.h>

using namespace std;

//.h & .cpp
#include "definiciones.h"

//Variables Globales
Usuario *a_Usuarios[MAX_U];
int cant_usuarios=0;
Vehiculo *a_Vehiculos[MAX_V];
int cant_vehiculos=0;

string SolicitarNombre()
{

    //------

    bool again=false;
    bool again2=false;
    string param_string1="";
    char param_char;

    //------


    do{
        param_string1="";
        again=false;
        again2=false;

        cout << "Registrar usuario" << endl;
        cout << "     "<<"Ingresa nombre:" << endl;
        cout << "     ";
        cin>> param_string1;

        do{
            again2=false;
            cout << "          ";
            cout << "Confirma el nombre (Si=S o No=N): " << param_string1 << endl;
            cout << "          ";
            cin>>param_char;

            if ((param_char=='s')||(param_char=='S')){
                again=false;
            }
            else{
                if ((param_char=='n')||(param_char=='N')){
                    again=true;
                }
                else{
                    cout << "          ";
                    cout<<"Ingrese una letra valida."<<endl;
                    again2=true;
                }
            }
        }while(again2==true);
    }while(again==true);
    return param_string1;
}

string SolicitarCedula(){

    //------

    bool again=false;
    bool again2=false;
    string param_string1="";
    char param_char;

    //------


    do{
        param_string1="";
        again=false;
        again2=false;

        cout << "     "<<"Ingresa CI:" << endl;
        cout << "     ";
        cin>> param_string1;

        do{
            again2=false;
            cout << "          ";
            cout << "Confirma el CI (Si=S o No=N): " << param_string1 << endl;
            cout << "          ";
            cin>>param_char;

            if ((param_char=='s')||(param_char=='S')){
                again=false;
            }
            else{
                if ((param_char=='n')||(param_char=='N')){
                    again=true;
                }
                else{
                    cout << "          ";
                    cout<<"Ingrese una letra valida."<<endl;
                    again2=true;
                }
            }
        }while(again2==true);
    }while(again==true);
    return param_string1;
}

void RegistrarUsuario(string nombre, string ci){

    bool match=false;
    bool stop=false;
    int i=0;

    while(((match==false)&&(stop==false))&&(i<MAX_U))
    {
        if(a_Usuarios[i]==NULL){
            stop=true;
        }
        else{
            if(a_Usuarios[i]->getter_ci()==ci){
                match=true;
            }
            else{
                i++;
            }
        }
    }
    if(match==false){
        if(cant_usuarios<MAX_U)
        {
            Usuario *u = new Usuario();
            u->setter_ci(ci);
            u->setter_n(nombre);
            a_Usuarios[cant_usuarios]=u;
            ConfirmacionUsuario(nombre,ci);
            cant_usuarios++;
        }
        else{
            cout<<"Se supera el Array"<<endl;
        }
    }
    else{
        cout<<"Esto no es una excepcion pero ya eexiste la ci"<<endl;
    }
    sleep(3);
    system("CLS");
}

void printUsuarios(){

    bool stop=false;
    int i=0;

    while(((stop==false))&&(i<MAX_U))
    {
        if(a_Usuarios[i]==NULL){
            stop=true;
        }
        else{
            cout<<a_Usuarios[i]->getter_ci()<<" - "<<a_Usuarios[i]->getter_n()<<endl;
            i++;
        }
    }
}

void ConfirmacionUsuario(string nombre, string ci)
{
    cout << "     "<<"Se confirmo la creacion del usuario:"<<endl;;
    cout << "          "<<"Nombre: "<<nombre<<endl;;
    cout << "          "<<"Cedula: "<<ci<<endl;
}

int SolicitarNroSerieVehiculo()
{

    //------

    bool again=false;
    bool again2=false;
    int param_int=0;
    char param_char;

    //------


    do{
        param_int=0;
        again=false;
        again2=false;

        cout << "Registrar vehiculo" << endl;
        cout << "     "<<"Ingresa NroSerie Vehiculo:" << endl;
        cout << "     ";
        cin>> param_int;

        do{
            again2=false;
            cout << "          ";
            cout << "Confirma el nombre (Si=S o No=N): " << param_int << endl;
            cout << "          ";
            cin>>param_char;

            if ((param_char=='s')||(param_char=='S')){
                again=false;
            }
            else{
                if ((param_char=='n')||(param_char=='N')){
                    again=true;
                }
                else{
                    cout << "          ";
                    cout<<"Ingrese una numero valido."<<endl;
                    again2=true;
                }
            }
        }while(again2==true);
    }while(again==true);
    return param_int;
}

float SolicitarPorcentajeVehiculo()
{
    //------

    bool again=false;
    float param_float   ;

    //------

    cout << "Ingrese el porcentaje de bateria del vehiculo(debe ser positivo y menor o igual a 100)" << endl;
    do{
        again=false;
        cin >> param_float;
        if((param_float<101) && (param_float>-1)){
            return param_float;
        }
        else{
            again=true;
            cout << "El porcentaje de bateria no es aceptable, ingreselo nuevamente" << endl;
        }

    }while(again==true);
}

float SolicitarPrecioBaseVehiculo()
{

    //------

    bool again=false;
    bool again2=false;
    float param_float=0;
    char param_char;

    //------


    do{
        param_float=0;
        again=false;
        again2=false;

        cout << "Registrar vehiculo" << endl;
        cout << "     "<<"Ingresa Precio Base:" << endl;
        cout << "     ";
        cin>> param_float;

        do{
            again2=false;
            again=false;
            cout << "          ";
            cout << "Confirma el nombre (Si=S o No=N): " << param_float << endl;
            cout << "          ";
            cin>>param_char;

            if ((param_char=='s')||(param_char=='S')){
                again=false;
            }
            else{
                if ((param_char=='n')||(param_char=='N')){
                    again=true;
                }
            }
            if (param_float<=0){
                cout << "          ";
                cout<<"Ingrese una numero mayor a 0."<<endl;
                again=true;
            }
        }while(again2==true);

    }while(again==true);

    return param_float;
}

void RegistrarVehiculo(int nroSerie,float porcentaje,float precioBase)
{
    //------

    bool match=false;
    bool stop=false;
    bool luces=false;
    int i=0;
    char v;
    TipoBici tipo;
    int cambios;

    //------

    while(((match==false)&&(stop==false))&&(i<MAX_V))
    {
        if(a_Vehiculos[i]==NULL)
        {
            stop=true;
        }
        else
        {
            if(a_Vehiculos[i]->getter_nroS()==nroSerie)
            {
                match=true;
            }
            else
            {
                i++;
            }
        }
    }
    if(match==false)
    {
        cout << "Desea registrar es un monopatin (S). Ponga (N) para bici" << endl;
        cin >> v;
        if(v=='S' || v=='s')
        {
            cout << "El monopatin tiene luces? S o N" << endl;
            cin >> v;
            do
            {
                if(v=='S' || v=='s')
                {
                    luces=true;
                }
                else
                {
                    if(v=='N' || v=='n')
                    {
                        luces=false;
                    }
                    else
                    {
                        cout << "Inserte la letra correcta" << endl;
                        cin >> v;
                    }
                }
            }
            while(v!='S' && v!='s' && v!='N' && v!='n');
            if(cant_vehiculos<MAX_V)
            {
                Monopatin *m = new Monopatin(nroSerie,porcentaje,precioBase,luces);
                a_Vehiculos[cant_vehiculos]=m;
                ConfirmacionMonopatin(nroSerie, porcentaje, precioBase, luces);
                cant_vehiculos++;
            }
            else
            {
                cout<<"Se supera el Array"<<endl;
            }
        }
        else
        {

            cout << "La bici es de PASEO(P) o MONTANIA(M)" << endl;
            cin >> v;
            do
            {
                if(v=='P' || v=='p')
                {
                    tipo=PASEO;
                }
                else
                {
                    if((v=='M') || (v=='m'))
                    {
                        tipo=MONTANIA;
                    }
                    else
                    {
                        cout << "pone la letrita bien pajerito" << endl;
                        cin >> v;
                    }
                }
            }while((v!='P') && (v!='p') && (v!='P') && (v!='p'));
        }
        if(cant_vehiculos<MAX_V)
        {
            Bicicleta *b = new Bicicleta(nroSerie,porcentaje,precioBase,tipo, cambios);
            a_Vehiculos[cant_vehiculos]=b;
            ConfirmacionBici(nroSerie, porcentaje, precioBase, tipo, cambios);
            cant_vehiculos++;
        }
        else
        {
            cout<<"Se supera el Array"<<endl;
        }
    }
}


void ConfirmacionMonopatin(int nroSerie, float por, float precioBase, bool luces)
{
    cout << "     "<<"Se confirmo la creacion del Monopatin:"<<endl;;
    cout << "          "<<"Porcentaje Bateria: "<<por<<endl;
    cout << "          "<<"Precio Base: "<<precioBase<<endl;
    if (luces==true){
        cout << "          "<<"Tiene Luces: si"<<endl;
    }
    else {
        cout << "          "<<"Tiene Luces: no"<<endl;
    }

}

void ConfirmacionBici(int nroSerie, float por, float precioBase, TipoBici tB, int cantCambios)
{
    cout << "     "<<"Se confirmo la creacion del Monopatin:"<<endl;;
    cout << "          "<<"Porcentaje Bateria: "<<por<<endl;
    cout << "          "<<"Precio Base: "<<precioBase<<endl;
    if (tB==0){
        cout << "          "<<"Tipo: MONTANIA"<<endl;
    }
    else {
        cout << "          "<<"Tipo: PASEO"<<endl;
    }

}

DtFecha fecha_reg (){
    DtFecha fechaing;

    time_t current_time;
    struct tm * timex;
    time(&current_time);
    timex = localtime(&current_time);
        fechaing.anio= timex->tm_year + 1900;
        fechaing.mes= timex->tm_mon + 1;
        fechaing.dia= timex->tm_mday;
    return fechaing;
}
