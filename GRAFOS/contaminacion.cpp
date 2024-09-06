#include"grafoPMC.h"
#include"matriz.h"
#include"alg_grafoPMC.h"
/**
Debido a la contaminación en la capital, veta que se pueda pasar por la capital, excepto si es residente, es decir, la capital como origen o destino de los viajes.

**/
template <typename tCoste>
auto noCapital(GrafoP<tCoste>& G, typename GrafoP<tCoste>::vertice capital){
    vector<typename GrafoP<tCoste>::vertice> caminosDesdeCap;
    vector<typename GrafoP<tCoste>::vertice> caminosHastaCap;
    matriz<typename GrafoP<tCoste>::vertice> caminos;
    vector<tCoste> D = Dijkstra(G, capital, caminosDesdeCap);
    vector<tCoste> DInv = DijkstraInv(G, capital, caminosHastaCap);
    GrafoP<tCoste> copia(G);
    for(int i = 0; i<G.numVert(); i++){
        copia[i][capital] = GrafoP<tCoste>::INFINITO;
        copia[capital][i] = GrafoP<tCoste>::INFINITO;
    }
    matriz<tCoste> F = Floyd(copia, caminos);
    for(int i = 0; i<G.numVert(); i++){
        copia[i][capital] = DInv[i];
        copia[capital][i] = D[i];
        caminos[i][capital] = caminosHastaCap[i];
        caminos[capital][i] = caminosDesdeCap[i];
    }

    return std::make_tuple(caminos, F);
}
