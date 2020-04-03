
#include "Viaje.h"

//VIAJE BASE

//Setters
void ViajeBase::setter_f(DtFecha f){
    fecha.anio=f.anio;
    fecha.dia=f.dia;
    fecha.mes=f.mes;
}

void ViajeBase::setter_dur(int dur){
    duracion=dur;
}

void ViajeBase::setter_dis(int dis){
    distancia=dis;
}

//Getters
DtFecha ViajeBase::getter_f(){
    return fecha;
}

int ViajeBase::getter_dur(){
    return duracion;
}

int ViajeBase::getter_dis(){
    return distancia;
}

//VIAJE

//Constructor
Viaje::Viaje(DtFecha f,int dur, int dis, Vehiculo *v){
    fecha.anio=f.anio;
    fecha.dia=f.dia;
    fecha.mes=f.mes;
    duracion=dur;
    distancia=dis;
    vehiculo=v;

    if(Monopatin *pM = dynamic_cast<Monopatin *> (v)){
        totalPrecio = v->DarPrecioViaje(distancia, duracion);
    }
    else{
        totalPrecio = v->DarPrecioViaje(distancia);
    }
}

//Setters
void Viaje::setter_p(class Vehiculo *v){
    //totalPrecio=*v->DarPrecioViaje(duracion, distancia);
    //vehiculo=(*v);
}

//Getters
float Viaje::getter_p(){
    return totalPrecio;
}

