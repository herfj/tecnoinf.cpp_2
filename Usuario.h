#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include "definiciones.h"
#include "Viaje.h"


class Usuario{

    private:
        string cedula;
        string nombre;
        DtFecha fechaIngreso;
        class Viaje *MisViajes[100];
        int a;
    public:

        //Constructor
        Usuario(string ci, string nom);

        //Setters
        void setter_ci (string ci);
        void setter_n (string nom);
        void setter_f (DtFecha f);
        void setter_v (class Viaje *v);

        //Getters
        string getter_ci();
        string getter_n();
        DtFecha getter_f();
        int getter_du(int a);
        int getter_di(int a);
        int getter_cantV();
        Viaje* getter_viaje(int a);
};

#endif // USUARIO_H_INCLUDED
