
#include "Vehiculo.h"

///VEHICULO

//Constructores

//Setters
void Vehiculo::setter_nroS(int nroS){
    nroSerie=nroS;
}

void Vehiculo::setter_porB(float porB){
    porcentajeBateria=porB;
}

void Vehiculo::setter_pB(float pB){
    precioBase=pB;
}

//Getters
int Vehiculo::getter_nroS(){
    return nroSerie;
}

float Vehiculo::getter_porB(){
    return porcentajeBateria;
}

float Vehiculo::getter_pB(){
    return precioBase;
}



///MONOPATIN

//Constructor

Monopatin::Monopatin(int nroS, float porB, float pB, bool tL){
    tieneLuces=tL;
    nroSerie=nroS;
    porcentajeBateria=porB;
    precioBase=pB;
}

float Monopatin::DarPrecioViaje(int dis, int dur){
    float totalPrecio;
    if(tieneLuces)
    {
        totalPrecio=0.5*dur + dis* precioBase;
    }
    else
    {
        totalPrecio=dis*precioBase;
    }
    return totalPrecio;
}

//Setters
void Monopatin::setter_tl(bool tL){
    tieneLuces=tL;
}

//Getters
bool Monopatin::getter_tl(){
    return tieneLuces;
}


///BICICLETA

//Cosntructor
Bicicleta::Bicicleta (int nroS, float porB, float pB, TipoBici tpB, int cambios){
    tipobici=tpB;
    nroSerie=nroS;
    porcentajeBateria=porB;
    precioBase=pB;
    cantcambios=cambios;
}

float Bicicleta::DarPrecioViaje(int dis){
    float totalPrecio;
    totalPrecio=precioBase*dis;
    return totalPrecio;
}

//Seetters
void Bicicleta::setter(TipoBici tpB){
    tipobici=tpB;
}

//Getters
TipoBici Bicicleta::getter_tipoB(){
    return tipobici;
}

int Bicicleta::getter_cantC(){
    return cantcambios;
}
