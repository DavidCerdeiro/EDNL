#include"agen.h"
#include"agen_E-S.h"

template <typename T>
int altura(const Agen<T>& A, typename Agen<T>::nodo nodo){
    if(nodo == Agen<T>::NODO_NULO)
        return -1;
    Agen<T>::nodo hijo = A.hijoIzqdo(nodo);
    int alturaMax = -1;

    if(hijo != Agen<T>::NODO_NULO){
        alturaMax = max(altura(A, hijo), alturaMax);
        hijo = A.hermDrcho(hijo);
    }
    return alturaMax + 1;
}
template <typename T>
bool similares(const Agen<T>& A, const Agen<T>& B){
    if(A.arbolVacio() && B.arbolVacio())
        return true;
    if((A.arbolVacio() && !B.arbolVacio()) || (!A.arbolVacio() && B.arbolVacio()))
        return false;
    if(altura(A, A.raiz()) == altura(B, B.raiz()))
        return similaresRec(A, A.raiz(), B, B.raiz(), altura(A, A.raiz()));
    else
        return false;
}
template <typename T>
int profundidad(const Agen<T>& A, typename Agen<T>::nodo nodo){
    if(A.padre(nodo) == Agen<T>::NODO_NULO)
        return 0;
    else
        return profundidad(A, A.padre(nodo)) + 1;
}
template <typename T>
int numHijos(const Agen<T>& A, typename Agen<T>::nodo nodo){
    if(A.hijoIzqdo(nodo) == Agen<T>::NODO_NULO)
        return 0;
    typename Agen<T>::nodo hijo = A.hijoIzqdo(nodo);
    int numHijos = 0;
    while(hijo != Agen<T>::NODO_NULO){
        numHijos++;
        hijo = A.hermDrcho(hijo);
    }
    return numHijos;
}
template <typename T>
bool similaresRec(const Agen<T>& A, typename Agen<T>::nodo nodoA, const Agen<T>& B, typename Agen<T>::nodo nodoB, int altura){
    if((nodoA != Agen<T>::NODO_NULO && nodoB == Agen<T>::NODO_NULO) ||(nodoA == Agen<T>::NODO_NULO && nodoB != Agen<T>::NODO_NULO) )
        return false;
    if(profundidad(A, nodoA) == altura && profundidad(A, nodoB) == altura){
        if(A.elemento(nodoA) == B.elemento(nodoB))
            return true;
        else
            return false;
    }
        if(numHijos(A, nodoA) != numHijos(A, nodoB))
            return false;
        typename Agen<T>::nodo hijoA = A.hijoIzqdo(nodoA);
        typename Agen<T>::nodo hijoB = B.hijoIzqdo(nodoB);
        bool esSimilar = true;
        while(hijoA != Agen<T>::NODO_NULO && esSimilar){
            esSimilar = similaresRec(A, hijoA, B, hijoB);
            hijoA = A.hermDrcho(hijoA);
            hijoB = A.hermDrcho(hijoB);
        }
        return esSimilar;
}