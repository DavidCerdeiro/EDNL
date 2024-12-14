#include"ArbolBinario_dinamico.h"
//Eliminar los descendientes de aquellos nodos cuyos descendientes son mayores y sus ascendentes son menores
template <typename T>
bool ascendentesMenores(Abin<T>& A, typename Abin<T>::nodo asc, typename Abin<T>::nodo nodo){
    if(asc == Abin<T>::NODO_NULO)
        return true;
    if(A.elemento(asc) <= A.elemento(nodo))
        return ascendentesMenores(A, A.padre(asc), nodo);
    else
        return false;
}
template <typename T>
bool descendientesMayores(Abin<T>& A, typename Abin<T>::nodo desc1, typename Abin<T>::nodo desc2, typename Abin<T>::nodo nodo){
    if(desc1 == Abin<T>::NODO_NULO && desc2 == Abin<T>::NODO_NULO){
        return true;
    }else if(desc1 != Abin<T>::NODO_NULO && desc2 != Abin<T>::NODO_NULO){
        if(A.elemento(desc1) >= A.elemento(nodo) && A.elemento(desc2) >= A.elemento(nodo))
            return descendientesMayores(A, A.hijoIzqdo(desc1), A.hijoDrcho(desc1), nodo) && descendientesMayores(A, A.hijoIzqdo(desc2), A.hijoDrcho(desc2), nodo);
    }else if(desc1 != Abin<T>::NODO_NULO){
        if(A.elemento(desc1) >= A.elemento(nodo))
            return descendientesMayores(A, A.hijoIzqdo(desc1), A.hijoDrcho(desc1), nodo);
        else
            return false;
    }else{
        if(A.elemento(desc2) >= A.elemento(nodo))
            return descendientesMayores(A, A.hijoIzqdo(desc2), A.hijoDrcho(desc2), nodo);
        else
            return false;
    }

}

template <typename T>
bool esHoja(Abin<T>& A, Abin<T>::nodo nodo){
    if(A.hijoIzqdo(nodo) == Abin<T>::NODO_NULO && A.hijoDrcho(nodo) == Abin<T>::NODO_NULO)
        return true;
    else
        return false;
}
template <typename T>
void eliminarDescendientes(Abin<T>& A, Abin<T>::nodo nodo){
    if(A.hijoIzqdo(nodo) != Abin<T>::NODO_NULO){
        if(!esHoja(A, A.hijoIzqdo(nodo)))
            eliminarDescendientes(A, A.hijoIzqdo(nodo));
        A.eliminarHijoIzqdo(nodo);
    }
    if(A.hijoDrcho(nodo) != Agen<T>::NODO_NULO){
        if(!esHoja(A, A.hijoDrcho(nodo)))
            eliminarDescendientes(A, A.hijoDrcho(nodo));
        A.eliminarHijoDrcho(nodo);
    }
}
template <typename T>
void verdesRec(Abin<T>& A, Abin<T>::nodo nodo){
    if(nodo != Abin<T>::NODO_NULO){
        if(ascendentesMenores(A, A.padre(nodo), nodo) && descendientesMayores(A, A.hijoIzqdo(nodo), A.hijoDrcho(nodo)))
            eliminarDescendientes(A, nodo);
        else{
            verdesRec(A, A.hijoIzqdo(nodo));
            verdesRec(A, A.hijoDrcho(nodo));
        }
    }
}

template <typename T>
void nodosVerdes(Abin<T>& A){
    if(!A.arbolVacio())
        verdesRec(A, A.raiz());
}

