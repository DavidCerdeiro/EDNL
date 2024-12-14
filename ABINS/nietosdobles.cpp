#include "abin_E-S.h"
#include "ArbolBinario_dinamico.h"
//Contar nodos que tienen el doble de nietos que bisnietos
template <typename T>
int doblesNietos(const Abin<T>& A){
    if(A.arbolVacio())
        return 0;
    else    
        return doblesRec(A, A.raiz());
}
template <typename T>
int contarNietos(const Abin<T>& A, typename Abin<T>::nodo nodo){
    if(nodo == Abin<T>::NODO_NULO)
        return 0;
    int nietos = 0;
    typename Abin<T>::nodo hizq = A.hijoIzqdo(nodo);
    typename Abin<T>::nodo hder = A.hijoDrcho(nodo);
    if(hizq != Abin<T>::NODO_NUlO){
        if(A.hijoIzqdo(hizq) != Abin<T>::NODO_NULO)nietos++;
        if(A.hijoDrcho(hizq) != Abin<T>::NODO_NULO)nietos++;
    }
    if(hder != Abin<T>::NODO_NUlO){
        if(A.hijoIzqdo(hder) != Abin<T>::NODO_NULO)nietos++;
        if(A.hijoDrcho(hder) != Abin<T>::NODO_NULO)nietos++;
    }

    return nietos;
}

template <typename T>
int doblesRec(const Abin<T>& A, typename Abin<T>::nodo nodo){
    if(nodo == Abin<T>::NODO_NULO)
        return 0;
    int nietos = contarNietos(A, nodo);
    int bisnietos = contarNietos(A, A.hijoIzqdo(nodo)) + contarNietos(A, A.hijoDrcho(nodo));
    if(nietos == (2*bisnietos))
        return doblesRec(A, A.hijoIzqdo(nodo)) + doblesRec(A, A.hijoDrcho(nodo)) + 1;
    else
        return doblesRec(A, A.hijoIzqdo(nodo)) + doblesRec(A, A.hijoDrcho(nodo));
}
