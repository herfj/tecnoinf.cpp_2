
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
        totalPrecio = pM->DarPrecioViaje(distancia, duracion);
    }
    else{
        if(Bicicleta *pB = dynamic_cast<Bicicleta *> (v)){
            totalPrecio = pB->DarPrecioViaje(distancia);
        }
    }
}

//Setters
void Viaje::setter_p(class Vehiculo *v){
    //totalPrecio=*v->DarPrecioViaje(duracion, distancia);
    //vehiculo=(*v);
}

//Getters
Vehiculo* Viaje::getter_vehiculo(){
    return vehiculo;
}

float Viaje::getter_tp(){
    return totalPrecio;
}

