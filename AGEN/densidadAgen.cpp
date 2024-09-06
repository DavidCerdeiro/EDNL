#include"agen.h"
template <typename T>
int gradoArbol(const Agen<T>& A, typename Agen<T>::nodo nodo){
    if(nodo == Agen<T>::NODO_NULO || A.hijoIzqdo(nodo) == Agen<T>::NODO_NULO)
        return 0;
    typename Agen<T>::nodo hijo = A.hijoIzqdo(nodo);
    int gradoMax = 0;
    int grado = 0;
    while(hijo != Agen<T>::NODO_NULO){
        grado++;
        gradoMax = max(gradoMax, max(grado, gradoArbol(A, hijo)));
        hijo = A.hermDrcho(hijo);
    }
    return gradoMax;
}
template <typename T>
int contHojas(const Agen<T>& A, typename Agen<T>::nodo nodo){
    if(nodo == Agen<T>::NOD_NULO)
        return 0;
    if(A.hijoIzqdo(nodo) == Agen<T>::NODO_NULO)
        return 1;
    typename Agen<T>::nodo hijo = A.hijoIzqdo(nodo);
    int numHojas = 0;
    while(hijo != Agen<T>::NODO_NULO){
        numHojas += contHojas(A, hijo);
        hijo = A.hermDrcho(hijo);
    }

    return numHojas;
}


template <typename T>
float densidad(const Agen<T>& A){
    if(A.raiz() == Agen<T>::NODO_NULO)
        return 0;
    int grado = gradoArbol(A, A.raiz());
    int nodosHojas = contHojas(A, A.raiz());
    if(nodosHojas != 0)
        return grado / nodosHojas;
    else
        return 0;
}

