#include"grafoPMC.h"
#include"alg_grafoPMC.h"
#include"matriz.h"
/**
Debido a la contaminación se busca implantar que no se pueda pasar por la capital, excepto si eres residente, es decir, viajes con origen o llegada en la capital. Se implantará si no se supera un número KMs máxmimos. 
Se recibe la capital, las distancias entre las ciudades, el número de KMs máximos que no se debe exceder y los viajes que se realizan entre cada par de ciudad.
**/
typedef struct{
    float kms;
    bool sePuede;
}solucion;

solucion contaminacion(typename GrafoP<float>::vertice capital, GrafoP<float>& G, float kmMax, matriz<int> viajes){
    float diferenciaKms = 0;
    matriz<typename GrafoP<float>::vertice> P;
    matriz<float> F = Floyd(G , P);
    vector<typename GrafoP<float>::vertice> v;
    vector<float> D = Dijkstra(G, capital, v);
    vector<float> DInv = DijkstraInv(G, capital, v);
    for(int i = 0; i<G.numVert(); i++){
        G[i][capital] = GrafoP<float>::INFINITO;
        G[capital][i] = GrafoP<float>::INFINITO;
    }
    matriz<float> noCap = Floyd(G, P);
    for(int i = 0; i<G.numVert(); i++){
        G[i][capital] = DInv[i];
        G[capital][i] = D[i];
    }
    for(int i = 0; i<G.numVert(); i++){
        for(int j = 0; j<G.numVert(); j++){
            diferenciaKms += noCap[i][j]*viajes[i][j] - F[i][j]*viajes[i][j];
        }
    }
    solucion s;
    s.kms = diferenciaKms;
    if(diferenciaKms > kmMax){
        s.sePuede = false;
    }else{
        s.sePuede = true;
    }
    return s;
}
