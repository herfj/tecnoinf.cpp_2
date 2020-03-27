#ifndef DEFINCIONES_H_INCLUDED
#define DEFINCIONES_H_INCLUDED

//Structs

typedef struct{
    int dia;
    int mes;
    int anio;
}DtFecha;

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
        //Viaje MisViajes[100];
    public:
        void setter (string ci, string nom, DtFecha f){
            fechaIngreso.anio=f.anio;
            fechaIngreso.dia=f.dia;
            fechaIngreso.mes=f.mes;
            nombre=nom;
            cedula=ci;
        }
};

class ViajeBase{
    private:
    
    public:

    protected:
        DtFecha fecha;
        int duracion;
        int distancia;

    void setter(DtFecha f, int dcion, int dist){
        fecha.anio=f.anio;
        fecha.dia=f.dia;
        fecha.mes=f.mes;
        duracion=dcion;
        distancia=dist;
    }

};

class Viaje : public ViajeBase{
    private: 
        float precio;
        class Vehiculo *vehiculo;
    
    public:

};

class Vehiculo{
    private:

    protected:
        int nroSerie;
        float PorcentajeBateria;
        float PrecioBase;
        virtual float darprecioviaje(int du,int di);
};

class Monopatin : public Vehiculo{
    private: 
        bool tieneluces;
    public:
        virtual float darprecioviaje(int du,int di){

        };
};

class Bicicleta : public Vehiculo{
    private: 
        TipoBici t;
         int cantcambios;
    public:
        virtual float darprecioviaje(int du,int di){

        };
};

#endif // DEFINCIONES_H_INCLUDED
