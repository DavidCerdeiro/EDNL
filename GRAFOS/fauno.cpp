#include"grafoPMC.h"
#include"alg_grafoPMC.h"

/**
En el laberinto del fauno nos encontramos que la casilla origen es (0, 0) y la salida (N-1, M-1) siendo el laberinto NxM, y el jugador solo se puede mover en movimiento de caballo de ajedrez.
Luego nos encontramos que por el laberinto habrá trampas donde si caes, el jugador muere o un caballero que golpea a sus casillas alrededor, donde si caes, también mueres

**/
typedef struct{
    int fil, col;
}casilla;

casilla posToCas(int pos, int M){
    casilla c;
    c.fil = pos/M;
    c.col = pos%M;
    return c;
}

int casToPos(casilla c, int M){
    return c.fil*M+c.col;
}

bool caballo(casilla c1, casilla c2){
    return (abs(c1.fil-c2.fil) == 2 && abs(c1.col-c2.col) == 1) || (abs(c1.fil-c2.fil) == 1 && abs(c1.col-c2.col) == 2);
}
bool espada(casilla c1, casilla c2){
    return (abs(c1.fil-c2.fil) + abs(c1.col-c2.col) == 1) && (abs(c1.fil-c2.fil) == 1 && abs(c1.col-c2.col) == 1);
}
bool esEsquina(casilla c, int N, int M){
    if(c.fil == 0){
        if(c.col == 0)
            return true;
        else if(c.col == M-1)
            return true;
    }else if(c.fil == (N-1)){
        if(c.col == 0)
            return true;
        else if(c.col == (M-1))
            return true;
    }
    return false;
}


auto Narnia(vector<casilla>& trampas, vector<casilla>& caballeros, int N, int M){
    casilla salida;
    salida.fil = N-1;
    salida.col = M-1;
    GrafoP<int> G(N*M);
    casilla c1, c2;
    for(int i = 0; i<G.numVert(); i++){
        c1 = posToCas(i, M);
        for(int j = 0; j<G.numVert(); j++){
            c2 = posToCas(j, M);
            if(i == j)
                G[i][j] = 0;
            else if(caballo(c1, c2))
                G[i][j] = 1;
            else
                G[i][j] = GrafoP<int>::INFINITO;
        }
    }
    casilla trampa;
    for(int i = 0; i<trampas.size(); i++){
        trampa = trampas[i];
        for(int j = 0; j<G.numVert(); j++){
            G[i][casToPos(trampa, M)] = GrafoP<int>::INFINITO;
            G[casToPos(trampa, M)][i] = GrafoP<int>::INFINITO;
        }
    }
    casilla caballero;
    int max, cont;
    for(int i = 0; i<caballeros.size(); i++){
        caballero = caballeros[i];
        if(esEsquina(caballero, N, M))
            max = 3;
        else if(caballero.fil == 0 || caballero.col == 0 || caballero.fil == (N-1) || caballero.col == (M-1))
            max = 5;
        else
            max = 8;
        cont = 0;
        for(int i = 0; i<G.numVert() && cont < max; i++){
            if(espada(caballero, posToCas(i, M))){
                for(int j = 0; j<G.numVert(); j++){
                    G[i][j] = GrafoP<int>::INFINITO;
                    G[j][i] = GrafoP<int>::INFINITO;
                }
            }
        }
    }
    vector<typename GrafoP<int>::vertice> P;
    vector<int> D = Dijkstra(G, 0, P);
    if(D[casToPos(salida, M)] != GrafoP<int>::INFINITO){
        return std::make_tuple(true, D[casToPos(salida, M)]);
    }else{
        return std::make_tuple(false, D[casToPos(salida, M)]);
    }
}
