#ifndef DEFINCIONES_H_INCLUDED
#define DEFINCIONES_H_INCLUDED

//Structs

typedef struct{
    int dia;
    int mes;
    int anio;
}DtFecha;

typedef struct{
    DtFecha fecha;
    int duracion;
    int distancia;
}DtViajeBase;

//Enums

typedef enum _TipoBici{
    PASEO, MONTANIA
}TipoBici;

//Classes

class Usuario{
    private:
        string cedula;
        string nombre;
        DtFecha fechaIngreso;
        Viaje MisViajes[100];
    public:
        void setter (string ci, string nom, DtFecha f){
            fechaIngreso.anio=f.anio;
            fechaIngreso.dia=f.dia;
            fechaIngreso.mes=f.mes;
            nombre=nom;
            cedula=ci;
        }
};

class Viaje{
    private:
        DtFecha fecha;
        int duracion;
        int distancia;
    public:

    void setter(DtFecha f, int dcion, int dist){
        fecha.anio=f.anio;
        fecha.dia=f.dia;
        fecha.mes=f.mes;
        duracion=dcion;
        distancia=dist;
    }

};

class Vehiculo{

};

class Monopatin : Vehiculo{

};

class Bicicleta : Vehiculo{
    
};

#endif // DEFINCIONES_H_INCLUDED
