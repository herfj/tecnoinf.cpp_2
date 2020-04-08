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
        void setter_v_ubc(class Viaje *v, int ubc);
        void setter_cv (int cv);

        //Getters
        string getter_ci();
        string getter_n();
        DtFecha getter_f();
        int getter_du(int u);
        int getter_di(int u);
        int getter_cantV();
        Viaje* getter_viaje(int u);
};

#endif // USUARIO_H_INCLUDED
