#ifndef DEFINCIONES_H_INCLUDED
#define DEFINCIONES_H_INCLUDED
#include <string.h>

//CONSTANTES

#define MAX_U 10
#define MAX_V 10

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


//Declaraciones

string SolicitarNombre();
string SolicitarCedula();
void RegistrarUsuario(string nombre, string ci);
void ConfirmacionUsuario(string nombre, string ci);
void printUsuarios();
int SolicitarNroSerieVehiculo();
float SolicitarPorcentajeVehiculo();
float SolicitarPrecioBaseVehiculo();
void RegistrarVehiculo(int nroSerie,float porcentaje,float precioBase);
void ConfirmacionMonopatin(int nroSerie, float por, float precioBase, bool luces);
void ConfirmacionBici(int nroSerie, float por, float precioBase, TipoBici tB, int cantCambios);
DtFecha fecha_reg ();

//Classes

class Usuario{

    private:
        string cedula;
        string nombre;
        DtFecha fechaIngreso;
        class Viaje *MisViajes[100];
    public:

        //Constructor
        Usuario(){
            cedula="";
            nombre="";
            fechaIngreso=fecha_reg();
            //aca dentro va la fecha se define
        }

        //Setters
        void setter_ci (string ci){
            cedula=ci;
        }
        void setter_n (string nom){
            nombre=nom;
        }
        void setter_f (DtFecha f){
            fechaIngreso.anio=f.anio;
            fechaIngreso.dia=f.dia;
            fechaIngreso.mes=f.mes;
        }

        //Getters
        string getter_ci()
        {
            return cedula;
        }
        string getter_n()
        {
            return nombre;
        }
        DtFecha getter_f()
        {
            return fechaIngreso;
        }
};

class ViajeBase{

    private:

    protected:
        DtFecha fecha;
        int duracion;
        int distancia;

    public:

        //Setters
        void setter_f(DtFecha f){
            fecha.anio=f.anio;
            fecha.dia=f.dia;
            fecha.mes=f.mes;
        }
        void setter_dur(int dur){
            duracion=dur;
        }
        void setter_dis(int dis){
            distancia=dis;
        }

        //Getters
        DtFecha getter_f(){
            return fecha;
        }
        int getter_dur(){
            return duracion;
        }
        int getter_dis(){
            return distancia;
        }
};

class Vehiculo{
    private:

    protected:
        int nroSerie;
        float porcentajeBateria;
        float precioBase;
        virtual float DarPrecioViaje(int dur,int dis){};
    public:

        //Constructores


        //Setters
        void setter_nroS(int nroS){
            nroSerie=nroS;
        }
        void setter_porB(float porB){
            porcentajeBateria=porB;
        }
        void setter_pB(float pB){
            precioBase=pB;
        }

        //Getters
        int getter_nroS(){
            return nroSerie;
        }
        float getter_porB(){
            return porcentajeBateria;
        }
        float get_pB(){
            return precioBase;
        }

};

class Monopatin : public Vehiculo{

    private:
        bool tieneLuces;

    public:

        //Cosntructor

        Monopatin(int nroS, float porB, float pB, bool tL){
            tieneLuces=tL;
            nroSerie=nroS;
            porcentajeBateria=porB;
            precioBase=pB;
        }

        float DarPrecioViaje(int dur,int dis){
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
        void setter_tl(bool tL){
            tieneLuces=tL;
        }

        //Getters
        bool getter_tl(){
            return tieneLuces;
        }
};

class Bicicleta : public Vehiculo{

    private:
        TipoBici tipobici;
        int cantcambios;

    public:

        //Cosntructor
        Bicicleta (int nroS, float porB, float pB, TipoBici tpB, int cambios){
            tipobici=tpB;
            nroSerie=nroS;
            porcentajeBateria=porB;
            precioBase=pB;
            cantcambios=cambios;
        }

        float DarPrecioViaje(int dis)
        {
            float totalPrecio;
            totalPrecio=precioBase*dis;

            return totalPrecio;
        }

        //Seetters
        void setter(TipoBici tpB){
            tipobici=tpB;
        }

        //Getters
        TipoBici getter_tipoB(){
            return tipobici;
        }
};

class Viaje : public ViajeBase{
    private:
        float totalPrecio;
        Vehiculo* vehiculo;
    public:

        //Constructor
        Viaje(DtFecha f,int dur, int dis, Vehiculo *v){
            fecha.anio=f.anio;
            fecha.dia=f.dia;
            fecha.mes=f.mes;
            duracion=dur;
            distancia=dis;
            //totalPrecio=(*v).DarPrecioViaje(duracion, distancia);
            //vehiculo=(*v);
        }

        //Setters
        void setter_p(class Vehiculo *v){
            //totalPrecio=*v->DarPrecioViaje(duracion, distancia);
            //vehiculo=(*v);
        }

        //Getters
        float getter_p(){
            return totalPrecio;
        }
};





#endif // DEFINCIONES_H_INCLUDED
