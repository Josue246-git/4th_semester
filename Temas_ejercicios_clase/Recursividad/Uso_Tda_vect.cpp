//Programa quye ghace uso del TDA vecrtor

#include <iostream>
#include  "TDA_vector.h"

using namespace std;


int main(){

    vector vec;                 //Instanciar el objeto del ripo TDA_vector

    vec.setnumElem(5);
    cout<<endl<<"El valor del atributo numElem es: "<<vec.getNumElem()<<endl;

    cout<<endl;
    return 0;

}