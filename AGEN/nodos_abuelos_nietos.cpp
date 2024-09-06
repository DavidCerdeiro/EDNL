#include"agen.h"

template <typename T>
int abuelosNietos(const Agen<T>& A){
    if(A.arbolVacio())
        return 0;
    else
        return abuelosNietosRec(A, A.raiz());
}

template <typename T>
bool esNieto(const Agen<T>& A, typename Agen<T>::nodo nodo){
    if(A.padre(nodo) != Agen<T>::NODO_NULO){
        if(A.padre(A.padre(nodo)) != Agen<T>::NODO_NULO)
            return true;
    }
    return false;
}
template <typename T>
bool esPadre(const Agen<T>& A, typename Agen<T>::nodo nodo){
    if(A.hijoIzqdo(nodo) != Agen<T>::NODO_NULO)
        return true;
    else
        return false;
}

template <typename T>
int abuelosNietosRec(const Agen<T>& A, typename Agen<T>::nodo nodo){
    bool yaEsAbuelo = false;
    Agen<T>::nodo hijo = A.hijoIzqdo(nodo);
    int numNodos = 0;
    while(hijo != Agen<T>::NODO_NULO){
        if(!yaEsAbuelo && esPadre(A, hijo) && esNieto(A, nodo)){
            yaEsAbuelo = true;
            numNodos++;
        }
        numNodos += abuelosNietosRec(A, hijo);
        hijo = A.hermDrcho(hijo); 
    }

    return numNodos;
}