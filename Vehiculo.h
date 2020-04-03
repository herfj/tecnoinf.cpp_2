#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED

#include "definiciones.h"



class Vehiculo{
    protected:
        int nroSerie;
        float porcentajeBateria;
        float precioBase;
    public:
        virtual float DarPrecioViaje(int dur, int dis){};
        //Constructores

        //Setters
        void setter_nroS(int nroS);
        void setter_porB(float porB);
        void setter_pB(float pB);

        //Getters
        int getter_nroS();
        float getter_porB();
        float getter_pB();

};

class Monopatin : public Vehiculo{

    private:
        bool tieneLuces;

    public:

        //Cosntructor

        Monopatin(int nroS, float porB, float pB, bool tL);

        float DarPrecioViaje(int dis, int dur);

        //Setters
        void setter_tl(bool tL);

        //Getters
        bool getter_tl();
};

class Bicicleta : public Vehiculo{

    private:
        TipoBici tipobici;
        int cantcambios;

    public:

        //Cosntructor
        Bicicleta (int nroS, float porB, float pB, TipoBici tpB, int cambios);

        float DarPrecioViaje(int dis);

        //Seetters
        void setter(TipoBici tpB);
        //Getters
        TipoBici getter_tipoB();
};


#endif // VEHICULO_H_INCLUDED
