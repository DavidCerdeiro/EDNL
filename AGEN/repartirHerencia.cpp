#include"agen.h"
#include"agen_E-S.h"

typedef struct{
    float dinero;
    bool vivo;
}persona;

void herencia(Agen<persona>& A){
    if(A.raiz() != Agen<persona>::NODO_NULO){
        herenciaRec(A, A.raiz());
    }
}
int contarDesc(Agen<persona>& A, typename Agen<persona>::nodo nodo){
    int descendientes = 0;
    Agen<persona>::nodo hijo = A.hijoIzqdo(nodo);
    while(hijo != Agen<persona>::NODO_NULO){
        descendientes++;
        descendientes += contarDesc(A, hijo);
        hijo = A.hermDrcho(hijo);
    }
    return descendientes;
}

void repartir(Agen<persona>& A, typename Agen<persona>::nodo nodo, float porcion){
    if(nodo != Agen<persona>::NODO_NULO){
        Agen<persona>::nodo hijo = A.hijoIzqdo(nodo);
        while(hijo != Agen<persona>::NODO_NULO){
            A.elemento(hijo).dinero += porcion;
            repartir(A, hijo, porcion);
            hijo = A.hermDrcho(hijo);
        }
    }
}

void herenciaRec(Agen<persona>& A, typename Agen<persona>::nodo nodo){
    if(nodo != Agen<persona>::NODO_NULO){
        if(!A.elemento(nodo).vivo){
            int descendientes = contarDesc(A, nodo);
            if(descendientes > 0){
                float aRepartir = A.elemento(nodo).dinero / descendientes;
                A.elemento(nodo).dinero = 0;
                repartir(A, nodo, aRepartir);
            }
        }
        Agen<persona>::nodo hijo = A.hijoIzqdo(nodo);
        while(hijo != Agen<persona>::NODO_NULO){
            herenciaRec(A, hijo);
            hijo = A.hermDrcho(hijo);
        }
    }
}