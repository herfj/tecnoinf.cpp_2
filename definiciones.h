#ifndef DEFINICIONES_H_INCLUDED
#define DEFINICIONES_H_INCLUDED

//CONSTANTES

#define MAX_U 10
#define MAX_V 10

//Structs

typedef struct{
    int dia;
    int mes;
    int anio;
}DtFecha;

typedef struct{
class Viaje *v[100];
int cont=0;
}vaf;

//Enums

typedef enum _TipoBici{
    PASEO, MONTANIA
}TipoBici;


//DECLARACIONES
class nelson : public exception
{
public:
    const char* what() const throw()
    {
        return "Error: Ya existe la CI ingresada";
    }
};

//Vehiculo** obtenerVehiculos(int& cantVehiculos);


//Solicitudes
string SolicitarString(string var);
int SolicitarInt(string var);
float SolicitarFloat(string var);
DtFecha SolicitarFecha(string var);

//Funciones complementarias

DtFecha fecha_reg ();
void LimpiarPantalla();
void Espera(int seg);

//Registro Usuarios
void RegistrarUsuario(string nombre, string ci);
void ConfirmacionUsuario(int u);
void printUsuarios();

//AgregarVehiculo
void AgregarVehiculo(int nroSerie,float porcentaje,float precioBase);
void ConfirmacionVehiculo(int u, bool creacion);
void printVehiculos();

//Insertar Viaje
int BuscarUsuario(string ci);
int BuscarVehiculo(int v);
void IngresarViaje(string ci,int nroSerie,int dur,int dis,DtFecha fechaViaje);
void ConfirmacionViaje(int ubc_u, int ubc_v);
void printViajes();

//Cambiar Viaje
void cambiarBateriaVehiculo(int nroSerie,float cargaVehiculo);

//AntesF
vaf verviajesantesdefecha(const DtFecha f,string ci);



#endif // DEFINICIONES_H_INCLUDED
