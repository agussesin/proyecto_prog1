#include <iostream>
using namespace std;

struct fecha {
    int dia;
    int mes; 
    int anio;

    int calc_edad(fecha hoy){
        int edad = 0;
        int anios = hoy.anio - anio;
        if(hoy.mes > mes){
            edad = anios;
        }        
        else if(hoy.mes < mes){
            edad = anios-1;
        }else{
            if(hoy.dia >= dia){
                edad = anios;
            }else{
                edad = anios - 1;
            }
        }

        return edad; 
    }
};
struct cama {
    fecha nacim;
    string nombre; 
    int DNI; 
    int numdias; 
};

void cargar_datos(cama camas[][2]){
    //recorre la matriz 

    int paciente = 1;
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            cout<<"datos del paciente: "<<paciente++<<endl;
            // carga datos y alamcena en cada posicion 
            cout<<"Ingrese dia de nacimiento"<<endl; 
            cin>>camas [i][j].nacim.dia;
            cout<<"Ingrese mes de nacimiento"<<endl; 
            cin>>camas[i][j].nacim.mes;
            cout<<"Ingrese anio de nacimiento"<<endl; 
            cin>>camas[i][j].nacim.anio;

            cout<<"ingrese nombre del paciente"<<endl; 
            cin>>camas[i][j].nombre; 
            cout<<"ingrese dni del paciente"<<endl; 
            cin>>camas[i][j].DNI; 
            cout<<"ingrese cantidad de dias que estuvo internado el paciente"<<endl;
            cin>>camas[i][j].numdias;

        }
    }
} 
float calc_prom(cama camas [][2])
{
    fecha hoy; // crea la variable hoy de tipo fecha
    cout<<"Ingrese el dia de hoy: "<<endl;
    cin>>hoy.dia; // guarda el dia
    cout<<"Ingrese el mes de hoy: "<<endl;
    cin>>hoy.mes; // el mes
    cout<<"Ingrese el anio de hoy: "<<endl;
    cin>>hoy.anio; // el anio


    int suma_edades = 0; 
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            cout<<"I: "<<i;
            cout<<", J: "<<j<<endl;
            suma_edades += camas[i][j].nacim.calc_edad(hoy); // es lo mismo que edades = edades + camas[i][j].calc_edad(hoy);
        }

    }
    return (float) suma_edades / 4; 
} 

void mostrarxdiasint(cama camas[][2]){
    cout<<"pacientes con mas de cinco dias de internacion"<<endl;
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            if (camas[i][j].numdias>5){
                cout<<"nombre:"<<camas[i][j].nombre<<endl;
            }
        }
    }
} 

void datubi (cama camas [][2], int f, int c){
    cout<<"----------------------------------"<<endl;
    cout<<camas[f][c].nombre<<"     "<<camas[f][c].nacim.dia<<"/";
    cout<<camas[f][c].nacim.mes<<"/"<<camas[f][c].nacim.anio<<endl;
    cout<<"DNI:     "<<camas[f][c].DNI<<endl;
    cout<<"Dias Internado: "<<camas[f][c].numdias<<endl;
    cout<<"----------------------------------"<<endl;
}


int main(){

    //tipo nombre[filas][cols]

    int filas = 2;
    int columnas = 2;
    cama camas[2][2]; 
    cargar_datos(camas);

    // tipo nombre;
    cout<<"Promedio: "<<calc_prom(camas);
    mostrarxdiasint (camas);
    cout<<"Ingrese la posicion que desea ver"<<endl;
    int f,c;
    cout<<"Fila: ";
    cin>>f;
    cout<<"Columna: ";
    cin>>c;
    cout<<endl;
    datubi(camas, f, c);
 
    // fecha nacimiento;
    // nacimiento.dia = 7;
    // nacimiento.mes = 10;
    // nacimiento.anio = 2000;

    // cout<<"Edad: "<<nacimiento.calc_edad(hoy)<<endl;
    return 0;

}