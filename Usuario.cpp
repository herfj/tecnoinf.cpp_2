

#include "Usuario.h"

Usuario::Usuario(string ci, string nom){
    cedula=ci;
    nombre=nom;
    a=0;
    fechaIngreso=fecha_reg();
}

//Setters
void Usuario::setter_ci(string ci){
    cedula=ci;
}

void  Usuario::setter_n(string nom){
    nombre=nom;
}

void Usuario::setter_f(DtFecha f){
    fechaIngreso.anio=f.anio;
    fechaIngreso.dia=f.dia;
    fechaIngreso.mes=f.mes;
}

void Usuario::setter_v(class Viaje *v){
    MisViajes[a]=v;
    a++;
}

//Getters
string Usuario::getter_ci(){
    return cedula;
}

string Usuario::getter_n(){
    return nombre;
}

DtFecha Usuario::getter_f(){
    return fechaIngreso;
}

int Usuario::getter_du(int a){
    return MisViajes[a]->getter_dur();
}

int Usuario::getter_di(int a){
    return MisViajes[a]->getter_dis();
}

DtFecha Usuario::getter_fv(int a){
    return MisViajes[a]->getter_f();
}
