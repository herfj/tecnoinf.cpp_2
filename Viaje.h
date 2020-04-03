#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

#include "definiciones.h"
#include "Vehiculo.h"


class ViajeBase{

    protected:
        DtFecha fecha;
        int duracion;
        int distancia;

    public:

        //Setters
        void setter_f(DtFecha f);
        void setter_dur(int dur);
        void setter_dis(int dis);

        //Getters
        DtFecha getter_f();
        int getter_dur();
        int getter_dis();
};

class Viaje : public ViajeBase{
    private:
        float totalPrecio;
        Vehiculo *vehiculo;
    public:

        //Constructor
        Viaje(DtFecha f,int dur, int dis, Vehiculo *v);

        //Setters
        void setter_p(class Vehiculo *v);

        //Getters
        float getter_tp();
        Vehiculo* getter_vehiculo();

        //Funciones

        friend Viaje &operator<(const Viaje &v1, const Viaje &v2);
};


#endif // VIAJE_H_INCLUDED
