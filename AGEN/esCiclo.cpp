#include"agen.h"

template <typename T>
bool hayCiclo(const Agen<T>& A){
    if(A.arbolVacio())
        return false;
    else
        return hayCicloRec(A, A.raiz());
}
template <typename T>
bool comprobarCiclo(const Agen<T>& A, typename Agen<T>::nodo nodo, typename Agen<T>::nodo hijo){
    if(hijo == Agen<T>::NODO_NULO)
        return false;
    if(A.elemento(nodo) == A.elemento(hijo))
        return true;
    bool hayCiclo = false;
    while (A.hermDrcho(hijo) != Agen<T>::NODO_NULO && !hayCiclo){
        hijo = A.hermDrcho(hijo);
        hayCiclo = comprobarCiclo(A, nodo, A.hermDrcho(hijo));
    }
    
    return hayCiclo;
}
template <typename T>
bool hayCicloRec(const Agen<T>& A, typename Agen<T>::nodo nodo){
    if(nodo == Agen<T>::NODO_NULO)
        return false;
    bool hayCiclo = comprobarCiclo(A, nodo);
    typename Agen<T>::nodo hijo = A.hijoIzqdo(nodo);
    while(hijo != Agen<T>::NODO_NULO && !hayCiclo){
        hayCiclo = hayCicloRec(A, hijo);
        hijo = A.hermDrcho(hijo);
    }
    return hayCiclo;
}