#include"grafoMA.h"
#include"grafoPMC.h"
#include"alg_grafoPMC.h"
#include<cmath>

/**
Dada dos islas, donde hay ciudades costeras o no, se busca construir un puente que minimice el coste de viajar con el resto de ciudades, teniendo en cuenta que no hay ciudades más importantes que otras.
**/

typedef struct{
    int x, y;
}ciudad;

float distancia(ciudad c1, ciudad c2){
    return sqrt(pow(c2.x-c1.x, 2) + pow(c2.y-c1.y, 2));
}

typedef struct{
    ciudad c1, c2;
}puente;

puente Zuelandia(const Grafo& Fobos, const Grafo& Deimos, vector<ciudad>& ciudadesF, vector<ciudad>& ciudadesD, vector<bool>& costerasF, vector<bool>& costerasD){
    GrafoP<float> F(Fobos.numVert());
    GrafoP<float> D(Deimos.numVert());
    float minF = GrafoP<float>::INFINITO;
    float minD = GrafoP<float>::INFINITO;
    ciudad cF, cD;
    for(int i = 0; i<F.numVert(); i++){
        for(int j = 0; j<F.numVert(); j++){
            F[i][j] = distancia(ciudadesF[i], ciudadesF[j]);
        }
    }
    for(int i = 0; i<D.numVert(); i++){
        for(int j = 0; j<D.numVert(); j++){
            D[i][j] = distancia(ciudadesD[i], ciudadesD[j]);
        }
    }
    vector<typename GrafoP<float>::vertice> P;
    vector<float> Dij;
    float coste;
    for(int i = 0; i<costerasF.size(); i++){
        if(costerasF[i]){
            coste = 0;
            Dij = Dijkstra(F, i, P);
            for(int j = 0; j<F.numVert(); j++){
                if(i != j){
                    coste = suma(coste, Dij[j]);
                }
            }
            if(coste < minF){
                minF = coste;
                cF = ciudadesF[i];
            }
        }
    }

    for(int i = 0; i<costerasD.size(); i++){
        if(costerasD[i]){
            coste = 0;
            Dij = Dijkstra(D, i, P);
            for(int j = 0; j<D.numVert(); j++){
                if(i != j){
                    coste = suma(coste, Dij[j]);
                }
            }
            if(coste < minD){
                minD = coste;
                cF = ciudadesD[i];
            }
        }
    }
    puente p;
    p.c1 = cF;
    p.c2 = cD;
    return p;
}
