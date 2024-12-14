#include "abin_E-S.h"
#include "ArbolBinario_dinamico.h"
//Contar los nodos que tienen 3 nietos
template <typename T>
int contarNodos(const Abin<T>& A){
    if(A.arbolVacio())
        return 0;
    else
        return contarRec(A, A.raiz());
}

template <typename T>
int numNietos(const Abin<T>& A, typename Abin<T>::nodo nodo){
    int nietos = 0;
    if(A.hijoIzqdo(nodo) != Abin<T>::NODO_NULO){
        if(A.hijoIzqdo(A.hijoIzqdo(nodo)) != Abin<T>::NODO_NULO)
            nietos++;
        if(A.hijoDrcho(A.hijoIzqdo(nodo)) != Abin<T>::NODO_NULO)
            nietos++;
    }
    if(A.hijoDrcho(nodo) != Abin<T>::NODO_NULO){
        if(A.hijoIzqdo(A.hijoDrcho(nodo)) != Abin<T>::NODO_NULO)
            nietos++;
        if(A.hijoDrcho(A.hijoDrcho(nodo)) != Abin<T>::NODO_NULO)
            nietos++;

    }

    return nietos;
}

template <typename T>
int contarRec(const Abin<T>& A, typename Abin<T>::nodo nodo){
    if(nodo == Abin<T>::NODO_NULO)
        return 0;
    if(numNietos(A, nodo) == 3)
        return contarRec(A, A.hijoIzqdo(nodo)) + contarRec(A, A.hijoDrcho(nodo)) + 1;
    else
        return contarRec(A, A.hijoIzqdo(nodo)) + contarRec(A, A.hijoDrcho(nodo));
}
