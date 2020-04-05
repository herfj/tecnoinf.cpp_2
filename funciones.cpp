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

DtFecha SolicitarFecha(string var){

    //------

    bool again=false;
    bool again2=false;
    DtFecha param;
    char param_char;

    //------

    do{
        param;
        again=false;
        again2=false;

        cout << "     "<<"Ingresa " << var << " - anio:" << endl;
        cout << "     ";
        cin>> param.anio;
        cout << "     "<<"Ingresa " << var << " - mes:" << endl;
        cout << "     ";
        cin>> param.mes;
        cout << "     "<<"Ingresa " << var << " - dia:" << endl;
        cout << "     ";
        cin>> param.dia;

        do{
            again2=false;
            cout << "          ";
            cout<< "Confirma el " << var << " (Si=S o No=N): " << param.dia << "/" <<param.mes << "/" <<param.anio << endl;
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



//Funciones complementarias

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

void LimpiarPantalla(){
    //system("CLS");
}

void Espera(int seg){
    //sleep(seg);
}



//Registro Usuario

void RegistrarUsuario(string nombre, string ci)
{
        bool match=false;
        bool stop=false;
        int i=0;

        while(((match==false)&&(stop==false))&&(i<MAX_U))
        {
            if(a_Usuarios[i]==NULL)
            {
                stop=true;
            }
            else
            {
                if(a_Usuarios[i]->getter_ci()==ci)
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
            if(cant_usuarios<MAX_U)
            {
                Usuario *u = new Usuario(ci, nombre);
                a_Usuarios[cant_usuarios]=u;
                ConfirmacionUsuario(cant_usuarios);
                cant_usuarios++;
            }
            else
            {
                cout<<"Se supera el Array"<<endl;
            }
        }
        else
        {
        try
        {
            throw invalid_argument("La cedula ingresada ya existe");
        }
        catch (const std::invalid_argument& ia)
        {
            std::cerr << "Invalid argument: " << ia.what() << '\n';
        }
        }
    }

void ConfirmacionUsuario(int u){
    cout << "     "<<"Se confirmo la creacion del usuario:"<<endl;
    cout << "          "<<"Nombre: "<<a_Usuarios[u]->getter_n()<<endl;
    cout << "          "<<"Cedula: "<<a_Usuarios[u]->getter_ci()<<endl;
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
            ConfirmacionUsuario(i);
            i++;
        }
    }
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
    bool por=false;

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
    if ((porcentaje>=0)&&(porcentaje<=100)){
        por=true;
    }
    try{
        if(!por){
            throw invalid_argument("El porcentaje debe estar entre 0 y 100");
        }
        if(precioBase<=0){
            throw invalid_argument("El precio base debe ser positivo");
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
                    Vehiculo *pm=m;
                    a_Vehiculos[cant_vehiculos]=pm;
                    ConfirmacionVehiculo(cant_vehiculos);
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
                        Vehiculo *pb=b;
                        a_Vehiculos[cant_vehiculos]=pb;
                        ConfirmacionVehiculo(cant_vehiculos);
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
        throw invalid_argument("Ya existe un Vehiculo con ese nroSerie");
    }
    }
    catch (const std::invalid_argument& ia)
        {
            std::cerr << "Invalid argument: " << ia.what() << '\n';
        }

}

void ConfirmacionVehiculo(int u){
    if (Monopatin *pM = dynamic_cast<Monopatin *>(a_Vehiculos[u])){
        cout << "     "<< "Se confirmo la creacion del Monopatin:" << endl;
        cout << "          "<< "Nro Serie: " << pM->getter_nroS() << endl;
        cout << "          "<< "Porcentaje Bateria: " << pM->getter_porB() << endl;
        cout << "          "<< "Precio Base: " << pM->getter_pB() << endl;
        if (pM->getter_tl()){
            cout << "          "<< "Tiene Luces: si" << endl;
        }
        else{
            cout << "          "<< "Tiene Luces: no" << endl;
        }
    }
    else{
        if (Bicicleta *pB = dynamic_cast<Bicicleta *>(a_Vehiculos[u])){
            cout << "     "<< "Se confirmo la creacion del Bicicleta:" << endl;
            cout << "          "<< "Nro Serie: " << pB->getter_nroS() << endl;
            cout << "          "<< "Porcentaje Bateria: " << pB->getter_porB() << endl;
            cout << "          "<< "Precio Base: " << pB->getter_pB() << endl;
            if (pB->getter_tipoB() == 1){
                cout << "          "<< "Tipo: MONTANIA" << endl;
            }
            else{
                cout << "          "<< "Tipo: PASEO" << endl;
            }
            cout << "          "<< "Cantidad de Cambios: " << pB->getter_cantC() << endl;
        }
    }
}

void printVehiculos(){

    bool stop=false;
    int i=0;

    while(((stop==false))&&(i<MAX_V))
    {
        if(a_Vehiculos[i]==NULL){
            stop=true;
        }
        else{
            ConfirmacionVehiculo(i);
            i++;
        }
    }
}




//Ingresar Viaje

int BuscarUsuario(string ci){
    //variables
    string r;
    int a=0;
    int ubc=0;
    bool stop=false;

    //
    if(cant_usuarios!=0)
    {
        do
        {
            r=a_Usuarios[a]->getter_ci();
            if(ci==r){
                ubc=a;
                stop=true;
            }
            cout<<r<<"--"<<ci<<endl;
            a++;
        }while((a<cant_usuarios) && (ci!=r)&&(stop==false));
        if (ci == r){
            return ubc;
        }
        else{
            if ((a >= cant_usuarios) && (ci != r))
            {
                a = -1;
                cout << "La CI que ingreso no existe." << endl;
                return a;
            }
        }
    }
    else
    {
        a = -1;
        cout << "No existen Usuarios" << endl;
        return a;
    }
}

int BuscarVehiculo(int v){
    //variables
    int a=0;
    int ubc=0;
    int nrov;
    bool stop=false;

    //
    if(cant_vehiculos!=0)
    {
        do
        {
            nrov=a_Vehiculos[a]->getter_nroS();
            if(nrov==v){
                ubc=a;
                stop=true;
            }
            a++;
        }while((a<cant_vehiculos) && (v!=nrov));
        if (nrov == v)
        {
            return ubc;
        }
        else{
            if ((a >= cant_vehiculos) && (v != nrov))
            {
                a = -1;
                cout << "El nro de Serie que ingreso no existe." << endl;
                return a;
            }
        }
    }
    else
    {
        cout << "No existen vehiculos." << endl;
        a = -1;
        return a;
    }
}

void IngresarViaje(string ci,int nroSerie,int dur,int dis,DtFecha fechaViaje){
    //variables
    int a,b;
    DtFecha fusuario;

    //

    a=BuscarUsuario(ci);
    if(a>cant_usuarios || a==-1){
    }
    else
    {
        fusuario=a_Usuarios[a]->getter_f();
        b=BuscarVehiculo(nroSerie);
        if(b>cant_vehiculos || b==-1){
        }
        else{
            try{
                if(fechaViaje.anio<fusuario.anio)
                {
                    throw invalid_argument("La fecha es anterior a la del usuario.");
                }
                else{
                    if(fechaViaje.mes<fusuario.mes && fechaViaje.anio==fusuario.anio)
                    {
                        throw invalid_argument("La fecha es anterior a la del usuario.");
                    }
                    else{
                        if(fechaViaje.mes==fusuario.mes && fechaViaje.anio==fusuario.anio && fechaViaje.dia<fusuario.dia)
                        {
                            throw invalid_argument("La fecha es anterior a la del usuario.");
                        }
                        else{
                            Viaje *v=new Viaje(fechaViaje,dur,dis,a_Vehiculos[b]);
                            a_Usuarios[a]->setter_v(v);
                            int nv=a_Usuarios[a]->getter_cantV()-1;
                            ConfirmacionViaje(a, nv);
                        }
                    }
                }
            }

            catch (const std::invalid_argument& ia)
            {
                std::cerr << "Invalid argument: " << ia.what() << '\n';
            }}
    }
}

void ConfirmacionViaje(int ubc_u, int ubc_v){
    cout << "     "<<"Se confirmo la creacion del Vaije:"<<endl;
    cout << "          "<<"Nombre del Usuario: "<<a_Usuarios[ubc_u]->getter_n()<<endl;
    cout << "          "<<"Cedula del Usuario: "<<a_Usuarios[ubc_u]->getter_ci()<<endl;

    Viaje *pV=a_Usuarios[ubc_u]->getter_viaje(ubc_v);

    Vehiculo *pVe=pV->getter_vehiculo();
    cout<<""<<endl;
    if (Monopatin *pM = dynamic_cast<Monopatin *>(pVe)){
        cout << "          "<< "Nro Serie: " << pM->getter_nroS() << endl;
        cout << "          "<< "Porcentaje Bateria: " << pM->getter_porB() << endl;
        cout << "          "<< "Precio Base: " << pM->getter_pB() << endl;
        if (pM->getter_tl()){
            cout << "          "<< "Tiene Luces: si" << endl;
        }
        else{
            cout << "          "<< "Tiene Luces: no" << endl;
        }
    }
    else{
        if (Bicicleta *pB = dynamic_cast<Bicicleta *>(pVe)){
            cout << "          "<< "Nro Serie: " << pB->getter_nroS() << endl;
            cout << "          "<< "Porcentaje Bateria: " << pB->getter_porB() << endl;
            cout << "          "<< "Precio Base: " << pB->getter_pB() << endl;
            if (pB->getter_tipoB() == 1){
                cout << "          "<< "Tipo: MONTANIA" << endl;
            }
            else{
                cout << "          "<< "Tipo: PASEO" << endl;
            }
            cout << "          "<< "Cantidad de Cambios: " << pB->getter_cantC() << endl;
        }
    }
    cout<<""<<endl;
    cout << "               "<<"Fecha del Viaje: "<<pV->getter_f().dia<<"/"<<pV->getter_f().mes<<"/"<<pV->getter_f().anio<<endl;
    cout << "               "<<"Duracion del Viaje: "<< pV->getter_dur()<<endl;
    cout << "               "<<"Distancia del Viaje: "<< pV->getter_dis()<<endl;
    cout << "               "<<"Pracio Total del Viaje: "<< pV->getter_tp()<<endl;
}

void printViajes(){
    bool stop=false;
    int i=0;
    int ii=0;

    while(((stop==false))&&(i<MAX_U))
    {
        if(a_Usuarios[i]==NULL){
            stop=true;
        }
        else{
            while (ii<(a_Usuarios[i]->getter_cantV())){
                ConfirmacionViaje(i,ii);
                ii++;
            }
            i++;
        }
    }
}



//

bool operator<(DtFecha f1, DtFecha f2)
{
    bool j;
    if ((f1.anio < f2.anio) || ((f1.anio == f2.anio) && (f1.mes < f2.mes)) || ((f1.anio == f2.anio) && (f1.mes == f2.mes) && (f1.dia < f2.dia)))
    {
        j=true;
        return j;
    }
    j=false;
    return j;
}

vaf verviajesantesdefecha(const DtFecha f,string ci)
{
    //variables
    int a,b,c;
    DtFecha fu;
    vaf v;
    bool z;

    //
    b=BuscarUsuario(ci);
    c=a_Usuarios[b]->getter_cantV();
    for(a=0;a<c;a++)
    {
        fu=a_Usuarios[b]->getter_viaje(a)->getter_f();
        if(fu<f)
        {
            v.v[v.cont]=a_Usuarios[b]->getter_viaje(a);
            v.cont++;
        }
    }
    return v;
}


//Cambiar Bateria Vehiculo

void cambiarBateriaVehiculo(int nroSerie,float cargaVehiculo){
    if(a_Vehiculos[0]==NULL){
        cout<<"No hay vehiculos registrados. Porfavor registre uno.";
    }
    else
    {
        int lugar=0;
        bool existe=true;
        do{
            if(a_Vehiculos[lugar]->getter_nroS()==nroSerie){
                existe=true;
            }
            else{
                lugar++;
            }
        }while((a_Vehiculos[lugar]->getter_nroS()!=nroSerie)&&(lugar<cant_vehiculos)&&(!existe));

        if(existe){
            a_Vehiculos[lugar]->setter_porB(cargaVehiculo);
        }
        else{
            cout<<"Ese vehiculo no existe."<<endl;
        }
    }
}


/*
void eliminarViajes(string ci, const DtFecha& fecha)
{


}


Vehiculo** obtenerVehiculos(int& cantVehiculos){
    Vehiculo* arreglovehiculos[cantVehiculos];
    int i;
    for (i=0;i<=cantVehiculos;i++){
            arreglovehiculos[i]=a_Vehiculos[i];
    }

    return arreglovehiculos;
}
*/

ostream &operator <<(ostream &o,class Vehiculo *v)
{
    string a="no";
    string b="Montania";
    if(Monopatin *vM = dynamic_cast<Monopatin *> (v))
    {
        if(vM->getter_tl())
        {
            a="si";
        }
        o << "Numero de serie:" << vM->getter_nroS() << endl << "Porcentaje bateria:" << vM->getter_porB() << endl << "Precio base:" << vM->getter_pB() << endl << "Tiene luces:" << a << endl;
    }
        if(Bicicleta *vB = dynamic_cast<Bicicleta *> (v))
    {
        if(vB->getter_tipoB()==0)
        {
            b="Paseo";
        }
        o << "Numero de serie:" << vB->getter_nroS() << endl << "Porcentaje bateria:" << vB->getter_porB() << endl << "Precio base:" << vB->getter_pB() << endl << "Tipo de bici:" << b << endl << "Cantidad de cambios:" << vB->getter_cantC() << endl;
    }
    return o;
}
