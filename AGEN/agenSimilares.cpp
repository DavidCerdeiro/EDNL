#include"agen.h"
//Comprobar que tenga estructura similar, además, en los nodos hojas deben tener mismo elemento

template <typename T>
bool esHoja(const Agen<T>& A, typename Agen<T>::nodo nodo){
    return A.hijoIzqdo(nodo) == Agen<T>::NODO_NULO;
}

template <typename T>
int numHijos(const Agen<T>& A, typename Agen<T>::nodo nodo){
    int hijos = 0;
    typename Agen<T>::nodo hijo = A.hijoIzqdo(nodo);
    while(hijo != Agen<T>::NODO_NULO){
        hijos++;
        hijo = A.hermDrcho(hijo);
    }

    return hijos;
}
template <typename T>
bool similaresRec(const Agen<T>& A, typename Agen<T>::nodo nodoA, const Agen<T>& B, typename Agen<T>::nodo nodoB){
    if(esHoja(A, nodoA) && esHoja(A, nodoB)){
        if(A.elemento(nodoA) == B.elemento(nodoB))
            return true;
        else
            return false;
    }else if(numHijos(A, nodoA) != numHijos(B, nodoB)){
        return false;
    }else{
        Agen<T>::nodo hijoA = A.hijoIzqdo(nodoA);
        Agen<T>::nodo hijoB = B.hijoIzqdo(nodoB);
        bool similares = true;
        while(hijoA != Agen<T>::NODO_NULO && similares){
            if(!similares(A, hijoA, B, hijoB)){
                similares = false;
            }else{
                hijoA = A.hermDrcho(nodoA);
                hijoB = B.hermDrcho(nodoB);
            }
        }
        return similares;
    }
}

template <typename T>
bool similares(const Agen<T>& A, const Agen<T>& B){
    if(A.raiz() == Agen<T>::NODO_NULO && B.raiz() == Agen<T>::NODO_NULO)
        return true;
    else if((A.raiz() != Agen<T>::NODO_NULO && B.raiz() == Agen<T>::NODO_NULO) || (A.raiz() == Agen<T>::NODO_NULO && B.raiz() != Agen<T>::NODO_NULO))
        return false;
    else
        return similaresRec(A, A.raiz(), B, B.raiz());
}