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

//Enums

typedef enum _TipoBici{
    PASEO, MONTANIA
}TipoBici;


//DECLARACIONES

//Solicitudes
string SolicitarString(string var);
int SolicitarInt(string var);
float SolicitarFloat(string var);

//Registro Usuarios
void RegistrarUsuario(string nombre, string ci);
void ConfirmacionUsuario(string nombre, string ci);
void printUsuarios();

//AgregarVehiculo
void AgregarVehiculo(int nroSerie,float porcentaje,float precioBase);
void ConfirmacionMonopatin(int nroSerie, float por, float precioBase, bool luces);
void ConfirmacionBici(int nroSerie, float por, float precioBase, TipoBici tB, int cantCambios);
DtFecha fecha_reg ();
void printV();

//AgregarViaje
int verificarv(int v);
int insertarusuarioviaje(string c);
void IngresarViaje(string c,int nrov,int du,int di,DtFecha fecha);

//Insertar Viaje
int InsertarUsuarioViaje(string c);
int verificarv(int v);
void IngresarViaje(string c,int nrov,int du,int di,DtFecha fecha);
void printViaje();

//Cambiar Viaje
void cambiarBateriaVehiculo(int nroSerie,float cargaVehiculo);


#endif // DEFINICIONES_H_INCLUDED
