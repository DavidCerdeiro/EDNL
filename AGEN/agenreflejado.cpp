#include <iostream> 
#include <fstream> 
#include "agen.h" 
#include "agen_E-S.h" 
 
using namespace std; 
 
typedef char tElto; 
const tElto fin = '#';   // fin de lectura 
 template <typename T>
Agen<T> reflejado(const Agen<T>& A);
int main () 
{ 
   Agen<tElto> A, B, R; 
 
   cout << "*** Lectura del árbol A ***\n"; 
   rellenarAgen(A, fin);     // Desde std::cin 
 
   ofstream fs("agen.dat");  // Abrir fichero de salida. 
   imprimirAgen(fs, A, fin); // En fichero. 
   fs.close(); 
   cout << "\n*** Árbol A guardado en fichero agen.dat ***\n"; 
 
   cout << "\n*** Lectura de árbol B de agen.dat ***\n"; 
   ifstream fe("agen.dat");  // Abrir fichero de entrada. 
   rellenarAgen(fe, B);      // Desde fichero. 
   fe.close(); 
 
   cout << "\n*** Mostrar árbol B ***\n"; 
   imprimirAgen(B);          // En std::cout 

    R = reflejado(B);
    cout << "\n*** Mostrar árbol B reflejado***\n"; 
    imprimirAgen(R);
}
template <typename T>
Agen<T> reflejado(const Agen<T>& A){
    Agen<T> B;
    if(A.raiz != Agen<T>::NODO_NULO){
        B.insertarRaiz(A.elemento(A.raiz()));
        reflejadoRec(A, A.raiz(), B, B.raiz());
    }
    return B;
}

template <typename T>
void reflejadoRec(const Agen<T>& A, typename Agen<T>::nodo nodoA, const Agen<T>& B, typename Agen<T>::nodo nodoB){
    if(nodoA != Agen<T>::NODO_NULO){
        typename Agen<T>::nodo hijo = A.hijoIzqdo(nodoA);
        while(hijo != Agen<T>::NODO_NULO){
            B.insertarHijoIzqdo(nodoB, A.elemento(hijo));
            reflejadoRec(A, hijo, B, B.hijoIzqdo(nodoB));
            hijo = A.hermDrcho(hijo);
        }
    }
}