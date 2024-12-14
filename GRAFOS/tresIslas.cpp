#include"grafoPMC.h"
#include"alg_grafoPMC.h"
#include<cmath>
/**
Tenemos tres islas y queremos reconstruir las carreteras y puentes de modo que estén todas las ciudades de estas islas conectadas, siendo al menor coste general posible.
Contamos con un coste base tanto para carretera como para puente, además de uno adicional según la medida de esta.
**/
typedef struct{
    int x, y;
}ciudad;

float distancia(ciudad c1, ciudad c2){
    return sqrt(pow(c2.x-c1.x, 2) + pow(c2.y-c1.y, 2));
}
typedef struct{
    ciudad c1, c2;
    float coste;
}conexion;

auto NoZuelandia(vector<ciudad>& Fobos, vector<ciudad>& Deimos, vector<ciudad>& Europa, float iniCarretera, float iniPuente, float adicCarretera, float adicPuente){
    int NF = Fobos.size();
    int ND = Deimos.size();
    int NE = Europa.size();
    GrafoP<float> G(NF+ND+NE);
    for(int i = 0; i<NF; i++){
        for(int j = 0; j<NF; j++){
            G[i][j] = iniCarretera + distancia(Fobos[i], Fobos[j])*adicCarretera;
        }
        for(int j = NF; j<NF+ND; j++){
            G[i][j] = iniPuente + distancia(Fobos[i], Deimos[j-NF])*adicPuente;
            G[j][i] = iniPuente + distancia(Fobos[i], Deimos[j-NF])*adicPuente;
        }
        for(int j = NF+ND; j<G.numVert(); j++){
            G[i][j] = iniPuente + distancia(Fobos[i], Europa[j-NF-ND])*adicPuente;
            G[i][j] = iniPuente + distancia(Fobos[i], Europa[j-NF-ND])*adicPuente;
        }
    }
    for(int i = NF; i<NF+ND; i++){
        for(int j = NF; j<NF+ND; j++){
            G[i][j] = iniCarretera + distancia(Deimos[i-NF], Deimos[j-NF])*adicCarretera;
        }
        for(int j = NF+ND; j<G.numVert(); j++){
            G[i][j] = iniPuente + distancia(Deimos[i-NF], Europa[j-NF-ND])*adicPuente;
            G[i][j] = iniPuente + distancia(Deimos[i-NF], Europa[j-NF-ND])*adicPuente;
        }
    }
    for(int i = NF+ND; i<G.numVert(); i++){
        for(int j = NF+ND; j<G.numVert(); j++){
            G[i][j] = iniCarretera + distancia(Europa[j-NF-ND], Europa[j-NF-ND])*adicCarretera;
        }
    }
    GrafoP<float> K = Kruskall(G);
    return K;
}
