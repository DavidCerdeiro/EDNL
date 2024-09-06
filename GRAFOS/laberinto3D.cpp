#include"grafoPMC.h"
#include"alg_grafoPMC.h"

/**
Dada una casilla de entrada y otra de salida en un laberinto NxNxN, el jugador solo se puede realizar los siguientes movimientos: Izquierda, Derecha, Arriba, Abajo, Dentro y Fuera.
Además, se debe tener en cuenta que se colocarán piedras sobre casillas donde no se podrá desplazar el jugador
**/
typedef struct{
    int fil, col, dim;
}casilla;

int casToPos(casilla c, int N){
    return c.fil*N+c.col+c.dim*N*N;
}

casilla posToCas(int pos, int N){
    casilla c;
    c.fil = (pos/N)%N;
    c.col = pos%N;
    c.dim = pos%(N*N);
    return c;
}

bool movimiento(casilla c1, casilla c2){
    return abs(c1.fil-c2.fil) + abs(c1.col-c2.col) + abs(c1.dim-c2.dim) == 1;
}

auto laberinto3D(int N, vector<casilla>& piedras, casilla entrada, casilla salida){
    GrafoP<int> G(N*N*N);
    casilla c1, c2;
    for(int i = 0; i<G.numVert(); i++){
        c1 = posToCas(i, N);
        for(int j = 0; j<G.numVert(); j++){
            c2 = posToCas(j, N);
            if(i == j)
                G[i][j] = 0;
            else if(movimiento(c1, c2))
                G[i][j] = 1;
            else
                G[i][j] = GrafoP<int>::INFINITO;
        }
    }
    casilla piedra;
    for(int i = 0; i<piedras.size(); i++){
        piedra = piedras[i];
        for(int j = 0; j<G.numVert(); j++){
            if(movimiento(piedra, posToCas(j, N))){
                G[i][j] = GrafoP<int>::INFINITO;
                G[j][i] = GrafoP<int>::INFINITO;
            }
        }
    }
    int posEntrada = casToPos(entrada, N);
    int posSalida = casToPos(salida, N);
    vector<typename GrafoP<int>::vertice> P;
    vector<int> D = Dijkstra(G, posEntrada, P);
    return std::make_tuple(P[posSalida], D[posSalida]);
}
