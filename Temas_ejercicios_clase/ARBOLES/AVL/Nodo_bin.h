#ifndef NODOBINARIO_H
#define NODOBINARIO_H

#define NULL __null

typedef int Tipo;

class NodoBinario{                  
    private:
        Tipo dato;
        NodoBinario *izq;
        NodoBinario *der;
        int height;                           //altura del nodo para que posteriormente se lo pueda dar el factor de equilibrio

    public:
        NodoBinario();
        NodoBinario(Tipo val );
        // NodoBinario(Tipo val, NodoBinario* puntIzq, NodoBinario* puntDer);

        void setDato(Tipo val);
        void setIzq(NodoBinario *punt);
        void setDer(NodoBinario *punt);
        void setHeight(int h);

        Tipo getDato();
        NodoBinario *getIzq();
        NodoBinario *getDer();
        int getHeight();
};

    NodoBinario::NodoBinario(){
        setIzq(NULL);
        setDer(NULL);
        setHeight(1);
    }

    NodoBinario::NodoBinario(Tipo val){
        setDato(val);
        setIzq(NULL);
        setDer(NULL);
        setHeight(1);
    }


    void NodoBinario::setDato(Tipo val){
        dato = val;
    }

    void NodoBinario::setIzq(NodoBinario *punt){
        izq = punt;
    }

    void NodoBinario::setDer(NodoBinario *punt){
        der = punt;
    }

    Tipo NodoBinario:: getDato(){
        return dato;
    }

    NodoBinario* NodoBinario::getIzq(){
        return izq;
    }

    NodoBinario* NodoBinario::getDer(){
        return der;
    }


    void NodoBinario::setHeight(int h){
        height = h;
    }
    
    int NodoBinario::getHeight(){
        return height;
    }

#endif