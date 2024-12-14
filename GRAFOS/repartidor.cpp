#include"grafoPMC.h"
#include"alg_grafoPMC.h"
//En este problema tenemos a un repartidor que debe repartir a una serie de clientes.
//Cuando se quede sin mercancia, deberá volver a central para recargar el camión.
//La función pedido suponemos que devuelve cuanto debe repartir al cliente en concreto y además actualiza el valor de este cuando se le reparte.
int Pedido(int i){
    return 0;
}

template <typename tCoste>
void repartidor(const GrafoP<tCoste>& G, int capacidad, int central){
    int aRepartir = G.numVert() - 1;
    int seParteDe = central;
    int enCamion = capacidad;
    tCoste min;
    int cliente;
    tCoste total = 0;
    matriz<GrafoP<tCoste>::vertice> P;
    matriz<tCoste> F = Floyd(G, P);
    
    while(aRepartir != 0){
        min = GrafoP<tCoste>::INFINITO;
        for(int destino = 0; destino<G.numVert(); destino++){
            if(destino != central && F[seParteDe][destino] < min){
                cliente = destino;
                min = F[seParteDe][destino];
            }
        }
        total += min;
        if(Pedido(cliente) <= enCamion){
            enCamion -= Pedido(cliente);
            Pedido = 0;
            for(int i = 0; i<G.numVert(); i++){
                F[i][cliente] = GrafoP<tCoste>::INFINITO;
                F[cliente][i] = GrafoP<tCoste>::INFINITO;
            }
            aRepartir--;
        }else{
            Pedido(cliente) -= enCamion;
            enCamion = 0;
        }
        if(enCamion == 0){
            total += F[seParteDe][central];
            enCamion = capacidad;
            seParteDe = central;
        }else{
            seParteDe = cliente;
        }
    }
    return total;
}
