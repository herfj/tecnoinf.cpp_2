#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace std;

//.h & .cpp
#include "definiciones.h"

#include "Usuario.cpp"
#include "Viaje.cpp"
#include "Vehiculo.cpp"


//Variables Globales
Usuario *a_Usuarios[MAX_U];
int cant_usuarios=0;
Vehiculo *a_Vehiculos[MAX_V];
int cant_vehiculos=0;

//Solicitar

string SolicitarString(string var){

    //------

    bool again=false;
    bool again2=false;
    string param="";
    char param_char;

    //------

    do{
        param="";
        again=false;
        again2=false;

        cout << "     "<<"Ingresa " << var << ":" << endl;
        cout << "     ";
        cin>> param;

        do{
            again2=false;
            cout << "          ";
            cout << "Confirma el "<< var <<" (Si=S o No=N): " << param << endl;
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
    return param;
}

int SolicitarInt(string var){

    //------

    bool again=false;
    bool again2=false;
    int param=0;
    char param_char;

    //------

    do{
        param=0;
        again=false;
        again2=false;

        cout << "     "<<"Ingresa " << var << ":" << endl;
        cout << "     ";
        cin>> param;

        do{
            again2=false;
            cout << "          ";
            cout << "Confirma el "<< var <<" (Si=S o No=N): " << param << endl;
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
    return param;
}

float SolicitarFloat(string var){

    //------

    bool again=false;
    bool again2=false;
    float param=0;
    char param_char;

    //------

    do{
        param=0;
        again=false;
        again2=false;

        cout << "     "<<"Ingresa " << var << ":" << endl;
        cout << "     ";
        cin>> param;

        do{
            again2=false;
            cout << "          ";
            cout << "Confirma el "<< var <<" (Si=S o No=N): " << param << endl;
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
    return param;
}


//Registro Usuario

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
            Usuario *u = new Usuario(ci, nombre);
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
            cout<<a_Usuarios[i]->getter_ci()<<" - "<<a_Usuarios[i]->getter_n()<< " - " <<a_Usuarios[i]->getter_f().anio<<" - "<<a_Usuarios[i]->getter_f().mes<<" - " <<a_Usuarios[i]->getter_f().dia<<endl;
            i++;
        }
    }
}

void ConfirmacionUsuario(string nombre, string ci){
    cout << "     "<<"Se confirmo la creacion del usuario:"<<endl;;
    cout << "          "<<"Nombre: "<<nombre<<endl;;
    cout << "          "<<"Cedula: "<<ci<<endl;
}


//Agregar Vehiculo

void AgregarVehiculo(int nroSerie,float porcentaje,float precioBase){
    //------

    bool match=false;
    bool stop=false;
    bool luces=false;
    int i=0;
    char v;
    int cambiios;
    TipoBici tipo;
    int cambios;
    bool again=false;

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
    if(match==false){
        cout << "     ";
        cout << "Desea registrar: Monopatin (M) o Bicicleta (B)" << endl;
        do{
            again=false;
            cout << "     ";
            cin >> v;
            if((v=='M') || (v=='m'))
            {
                cout << "     ";
                cout << "Monopatin tiene luces: S o N" << endl;
                cout << "     ";
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
                            cout << "          ";
                            cout << "Ingrese opcion valida. Intente nuevamente" << endl;
                            cout << "     ";
                            cin >> v;
                        }
                    }
                } while(v!='S' && v!='s' && v!='N' && v!='n');
                if(cant_vehiculos<MAX_V)
                {
                    Monopatin *m = new Monopatin(nroSerie,porcentaje,precioBase,luces);
                    a_Vehiculos[cant_vehiculos]=m;
                    ConfirmacionMonopatin(nroSerie, porcentaje, precioBase, luces);
                    cant_vehiculos++;
                }
                else
                {
                    cout << "          Se supera el Array"<<endl;
                }
            }
            else
            {
                if(v=='B' || v=='b'){
                    cout << "     ";
                    cout << "El tipo de Bicicleta es: PASEO(P) o MONTANIA(M)" << endl;
                    cout << "     ";
                    cin >> v;
                    do
                    {
                        if((v=='P') || (v=='p'))
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
                                cout << "          ";
                                cout << "Ingrese opcion valida. Intente nuevamente" << endl;
                                cout << "     ";
                                cin >> v;
                            }
                        }
                    }while((v!='P') && (v!='p') && (v!='M') && (v!='m'));

                    cout << "     ";
                    cout << "Ingrese el numero de cambios:" << endl;
                    do{
                        cout << "     ";
                        cin >> cambios;
                        if(cambios<0){
                            cout << "          ";
                            cout << "Cambios no puede ser negativo. Intente nuevamente" << endl;
                        }
                    }while(cambios<0);
                    if(cant_vehiculos<MAX_V)
                    {
                        Bicicleta *b = new Bicicleta(nroSerie,porcentaje,precioBase,tipo, cambios);
                        a_Vehiculos[cant_vehiculos]=b;
                        ConfirmacionBici(nroSerie, porcentaje, precioBase, tipo, cambios);
                        cant_vehiculos++;
                    }
                    else
                    {
                        cout << "     ";cout << "     ";
                        cout<<"Se supera el Array"<<endl;
                    }
                }
                else{
                    cout << "          ";
                    cout << "Ingrese opcion valida. Intente nuevamente" << endl;
                    again=true;
                }
            }
        }while(again==true);
    }
    else{
        cout << "          ";
        cout<<"Ya existe un Vehiculo con ese nroSerie"<<endl;
    }
}

void ConfirmacionMonopatin(int nroSerie, float por, float precioBase, bool luces){
    cout << "     "<<"Se confirmo la creacion del Monopatin:"<<endl;
    cout << "          "<<"Nro Serie: "<<nroSerie<<endl;
    cout << "          "<<"Porcentaje Bateria: "<<por<<endl;
    cout << "          "<<"Precio Base: "<<precioBase<<endl;
    if (luces==true){
        cout << "          "<<"Tiene Luces: si"<<endl;
    }
    else {
        cout << "          "<<"Tiene Luces: no"<<endl;
    }

}

void ConfirmacionBici(int nroSerie, float por, float precioBase, TipoBici tB, int cantCambios){
    cout << "     "<<"Se confirmo la creacion del Monopatin:"<<endl;
        cout << "          "<<"Nro Serie: "<<nroSerie<<endl;
    cout << "          "<<"Porcentaje Bateria: "<<por<<endl;
    cout << "          "<<"Precio Base: "<<precioBase<<endl;
    if (tB==1){
        cout << "          "<<"Tipo: MONTANIA"<<endl;
    }
    else {
        cout << "          "<<"Tipo: PASEO"<<endl;
    }
    cout << "          "<<"Cantidad de Cambios: "<<cantCambios<<endl;

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
        //el cout q me pidio el cacique hernan
        //cout << "Hora:Min:Sec: : " << timex->tm_hour <<":"<< timex->tm_min << ":" << timex->tm_sec << endl;
    return fechaing;
}

void printV(){

    bool stop=false;
    int i=0;

    while(((stop==false))&&(i<MAX_V))
    {
        if(a_Vehiculos[i]==NULL){
            stop=true;
        }
        else{
            cout<<a_Vehiculos[i]->getter_nroS()<<" - "<<a_Vehiculos[i]->getter_porB()<< " - "<< a_Vehiculos[i]->getter_pB() <<endl;
            i++;
        }
    }
}



int InsertarUsuarioViaje(string c)
{
    //variables
    string r;
    int a=-1;

    //
    do
    {
        a++;
        r=a_Usuarios[a]->getter_ci();
    }while((a<cant_usuarios) && (c!=r));
    if(a>cant_usuarios)
    {
        cout << "La ci que ingreso es incorrecta." << endl;
        return a;
    }
    else
    {
        cout << "La ci que ingreso es correcta." << endl;
        return a;
    }
}

int verificarv(int v)
{
    //variables
    int a=-1;
    int nrov;

    //
    do
    {
        a++;
        nrov=a_Vehiculos[a]->getter_nroS();
    }while((a<cant_vehiculos) && (v!=nrov));
    if(a>cant_vehiculos)
    {
        cout << "El nro de serie que ingreso es incorrecta." << endl;
        return a;
    }
    else
    {
        cout << "El nro de serie que ingreso es correcta." << endl;
        return a;
    }
}

void IngresarViaje(string c,int nrov,int du,int di,DtFecha fecha)
{
    //variables
    int a,b;
    DtFecha fusuario;

    //
    a=InsertarUsuarioViaje(c);
    if(a>cant_usuarios)
    {

    }
    else
    {
        fusuario=a_Usuarios[a]->getter_f();
        b=verificarv(nrov);
        if(b>cant_vehiculos)
        {

        }
        else
        {
            if(du<=0)
            {
                cout << "La duraci�n debe ser positiva" << endl;
            }
            else
            {
                if(di<=0)
                {
                    cout << "La distancia debe ser positiva." << endl;
                }
                else
                {
                    if(fecha.anio<fusuario.anio)
                    {
                        cout << "La fecha es anterior a la del usuario." << endl;
                    }
                    else
                    {
                        if(fecha.mes<fusuario.mes && fecha.anio==fusuario.anio)
                        {
                            cout << "La fecha es anterior a la del usuario." << endl;
                        }
                        else
                        {
                            if(fecha.mes==fusuario.mes && fecha.anio==fusuario.anio && fecha.dia<fusuario.dia)
                            {
                                cout << "La fecha es anterior a la del usuario." << endl;
                            }
                            else
                            {
                                Viaje *v=new Viaje(fecha,du,di,a_Vehiculos[b]);
                                a_Usuarios[a]->setter_v(v);
                                cout << v->getter_dis();
                                cout << v->getter_dur();
                            }
                        }
                    }
                }
            }
        }
    }
}
