//Programa que permite generar los 10 primeros numeros enteros positivos(s msoluciones, iteraticva y recurisiva)


//Autor: Josue Rodriguez 7272
//Materia: Estructura de datos 
 
#include <iostream>
#define NR 10 			//Definicon de la extension del arreglo, es una cosnt simbolica Y SIEMPRE CON MAYUSCULAS 
using namespace std;

int main(){

	int vect[NR];
	int n=0;

	//Prototypes
	int LeerN_elementos(int limit_inf, int limit_sup); //Prototipo de la fucnion, se recomienda porque se trabaja con var. locales 
    void Generar_num_ite(int n);
    int Generar_num_recur(int n, int fin);

    void Generar_letras_min(char n);

	//

	n = LeerN_elementos(1, NR);
    
    cout<<"GENERAR NUMEROS DE FORMA ITERATIVA"<<endl;
    Generar_num_ite(n);
    cout<<endl;

    // cout<<"GENERAR NUMEROS DE FORMA RECURSIVA"<<endl;
    // int sum=0;
    // Generar_num_recur(1, n, &sum);
    // cout<<endl<<"SUMA: "<<sum;

    cout<<"GENERAR NUMEROS DE FORMA RECURSIVA"<<endl;

    cout<<endl<<"SUMA: "<<Generar_num_recur(1, n);

    cout<<endl;

    cout<<"GENERAR LETRAS MINUSCULAS "<<endl;

    Generar_letras_min('A');

   
    cout<<endl;
	
}

int LeerN_elementos(int limit_inf, int limit_sup){
	int n=0;

	do{
		cout <<"Ingrese un valor entero comprendido entre "<<limit_inf <<" hasta "<<limit_sup<<": "; cin>>n;
	}
	while((n > limit_sup) || (n < limit_inf) );
	return n;
}

void Generar_num_ite(int n){

    for (int i = 1; i <= n; i++){
        cout<<endl<<" Valor generado "<<i<<endl;
    }   
}

// void Generar_num_recur(int n, int fin, int *sum){

//     if(n <= fin ){                          //Caso base o caso final 
//         cout<<endl<<" Valor generado: "<<n;
//         Generar_num_recur(n+1, fin, sum);                //Caso recursivo
//         *sum += n;
//     }

//     //if(n <= fin ){                //Esto me retorna al reves, 
//     //     Generar_num_recur(n+1, fin);                           
//     //     cout<<endl<<" Valor generado: "<<n;
//     // }
// }

int  Generar_num_recur(int n, int fin){
    
    if(n <= fin ){                                      //Caso base o caso final 
        // cout<<endl<<" Valor generado: "<<n;
        return n + Generar_num_recur(n+1, fin);
    }
    return 0;               //Cuando llega al fin 
}

void Generar_letras_min(char n){

    if(n <= 'Z' ){

        char min = n+32;

        cout<<endl<<n<<" "<<min<<endl;

        Generar_letras_min(++n);
    }
}

// void Generar_letras_min(char n){

//     if(n <= 'z'){

//         cout<<endl<<n<<endl;
//         Generar_letras_min(n+1);
//         //Generar_letras_min(n+=1);
//         //Generar_letras_min(n++);              //No se puede mandar con n++, ya que primero se usa la var y despues se incrementa, por lo que nunca va a termina

//     }
// }





//n++   //En recursividad no es aconsejablle 
//n+=1
// n= n+1
//++n                  
//No son sinonimos 