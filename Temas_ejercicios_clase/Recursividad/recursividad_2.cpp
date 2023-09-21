//Programa de gestion de cadenas 
//'' es caracter,  "" es string 

//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>
#include <string.h>

#define EXT 30

using namespace std;

int main(){

	//Prototypes

    bool Comprobar_palin_iter(char f[]);
    bool Comprobar_pal_palin(char palabra[], int j, int i=0);
    void pasar_a_Palabras(char f[], char f2[][EXT], int *num_pala);
    void Pasar_a_palabras_recur(char frase[], char palabras[][EXT], int *num_pal, int i = 0, int j=0, int k=0);
	//

    char f[EXT];    
    char f2[(EXT/2)][EXT];
    int num_pala=0;

    cout<<"INGRESE una frase"<<endl;

    cin.getline(f, 30, '.');

    for(int i = 0; i < strlen(f); i++) {
        f[i] = tolower(f[i]);
    }
    
    cout<<endl<<"La cadena ingresada es: "<<f<<endl;

    // cout<<endl<<"VERIFICAR SI ES PALINDROMO "<<endl;
    // cout<<endl<<"La cedena tiene de tamaño: "<< strlen(f)<<endl;

    // cout <<endl<<" Esta cadena "<< (Comprobar_palin_recur(f, 0, strlen(f)-1) ? "SI" : "NO" )<<" es un palindromo "<<endl;

    cout<<endl<<"VERIFICAR SI LAS PALABRAS DE LA FRASE SON PALINDROMOS "<<endl;
    
    // pasar_a_Palabras(f, f2, &num_pala);
    Pasar_a_palabras_recur(f, f2, &num_pala);

    for (int i = 0; i <= num_pala; i++){
        cout<<endl<<" "<< f2[i]<<", ES PALINDROMO?"<<endl;
        cout <<" Esta cadena "<< (Comprobar_palin_iter(f2[i]) ? "SI" : "NO" )<<" es un palindromo "<<endl;
    }

}

bool Comprobar_palin_iter(char f[]){  
    int i, j; 
    j = strlen(f) - 1;

    for (int i = 0; (i < j); i++, j--){
        if(f[i] != f[j]){
            return false;
        }
    }
    return true;
}


void pasar_a_Palabras(char f[], char f2[][EXT], int *num_pala){

    int j = 0; // recorre filas matris
    int k =0; //recorre columnas 

    for (int i = 0; i < strlen(f); i++){

        if((f[i] >= 'A') && (f[i] <= 'Z') || ((f[i]>='a') && f[i] <= 'z')){
            f2[j][k] = f[i];
            k++;
        }

        else if((f[i-1] >= 'A') && (f[i-1] <= 'Z') || ((f[i-1]>='a') && f[i-1] <= 'z')){
        //else if(f2[j][k] == f[i-1]){
            f2[j][k] = '\0';  //el back eslah 0 es un fin de cadena
            j++;
            k=0;
        }
    }

    f2[j][k] = '\0';  // Se debe ponerle el back espace para poder indentificar la ultimap palabra 
    *num_pala = j;
}

