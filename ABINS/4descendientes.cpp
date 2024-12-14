#include "abin_E-S.h"
#include "ArbolBinario_dinamico.h"
//Contar los nodos de un árbol binario que contenga 4 descendientes o más

template <typename T>
int cuatroDescendientes(const Abin<T>& A){
    if(A.arbolVacio())
        return 0;
    else
        return descRec(A, A.raiz());
}

template <typename T>
int contarDescendientes(const Abin<T>& A, typename Abin<T>::nodo){
    if(A.hijoIzqdo(nodo) != Abin<T>::NODO_NULO && A.hijoDrcho(nodo) != Abin<T>::NODO_NULO)
        return contarDescendientes(A, A.hijoIzqdo(nodo)) + contarDescendientes(A, A.hijoDrcho(nodo)) + 2;
    else if(A.hijoIzqdo(nodo) != Abin<T>::NODO_NULO)
        return contarDescendientes(A, A.hijoIzqdo(nodo)) + 1;
    else if(A.hijoDrcho(nodo) != Abin<T>::NODO_NULO)
        return contarDescendientes(A, A.hijoDrcho(nodo)) + 1;
    else
        return 0;
}

template <typename T>
int descRec(const Abin<T>& A, typename Abin<T>::nodo nodo){
    if(nodo == Abin<T>::NODO_NULO)
        return 0;
    if(contarDescendientes(A, nodo) >= 4)
        return descRec(A, A.hijoIzqdo(nodo)) + descRec(A, A.hijoDrcho(nodo)) + 1;
    else
        return descRec(A, A.hijoIzqdo(nodo)) + descRec(A, A.hijoDrcho(nodo));
}
