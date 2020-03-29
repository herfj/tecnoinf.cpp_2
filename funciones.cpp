using namespace std;

//.h & .cpp
#include "definiciones.h"

//Declaraciones

string SolicitarNombre();
string SolicitarCedula();
void RegistrarUsuario(string nombre, string ci);
void ConfirmacionUsuario(string nombre, string ci);

//Variables Globales
Usuario a_Usuarios[MAX_U];
int cant_usuarios=0;
Vehiculo a_Vehiculos[MAX_V];
int cant_vahiculos=0;

string SolicitarNombre(){

    //------

    bool again=false;
    bool again2=false;
    string param_string1="";
    char param_char;

    //------


    do{
        param_string1="";
        again=false;
        again2=false;

        cout << "Registrar usuario" << endl;
        cout << "     "<<"Ingresa nombre:" << endl;
        cout << "     ";
        cin>> param_string1;

        do{
            again2=false;
            cout << "          ";
            cout << "Confirma el nombre (Si=S o No=N): " << param_string1 << endl;
            cout << "          ";
            cin>>param_char;

            if ((param_char=='s')||(param_char=='S')){
                again=false;
            }
            else{
                if ((param_char=='n')||(param_char=='N')){
                    again=true;
                }
                else{
                    cout << "          ";
                    cout<<"Ingrese una letra valida."<<endl;
                    again2=true;
                }
            }
        }while(again2==true);
    }while(again==true);
    return param_string1;
}

string SolicitarCedula(){

    //------

    bool again=false;
    bool again2=false;
    string param_string1="";
    char param_char;

    //------


    do{
        param_string1="";
        again=false;
        again2=false;

        cout << "     "<<"Ingresa CI:" << endl;
        cout << "     ";
        cin>> param_string1;

        do{
            again2=false;
            cout << "          ";
            cout << "Confirma el CI (Si=S o No=N): " << param_string1 << endl;
            cout << "          ";
            cin>>param_char;

            if ((param_char=='s')||(param_char=='S')){
                again=false;
            }
            else{
                if ((param_char=='n')||(param_char=='N')){
                    again=true;
                }
                else{
                    cout << "          ";
                    cout<<"Ingrese una letra valida."<<endl;
                    again2=true;
                }
            }
        }while(again2==true);
    }while(again==true);
    return param_string1;
}

void RegistrarUsuario(string nombre, string ci){

    bool match=false;
    int i=0;

    while((match==false)&&(i<MAX_U))
    {
        if(a_Usuarios[i].getter_ci()==ci){
            match=true;
        }
        else{
            i++;
        }
    }
    if(match==false){
        a_Usuarios[cant_usuarios].setter_ci(ci);
        a_Usuarios[cant_usuarios].setter_n(nombre);
        ConfirmacionUsuario(nombre,ci);
        cant_usuarios++;
    }
    else{
        cout<<"Esto no es una excepcion pero ya eexiste la ci"<<endl;
    }
    sleep(3);
    system("CLS");

}

void ConfirmacionUsuario(string nombre, string ci){
    cout << "     "<<"Se confirmo la creacion del usuario:"<<endl;;
    cout << "          "<<"Nombre: "<<nombre<<endl;;
    cout << "          "<<"Cedula: "<<ci<<endl;
}
