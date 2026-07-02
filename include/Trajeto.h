#pragma once
#include "Cidade.h"

/**
 * @brief Representa um trajeto entre duas cidades.
 * 
 * Um trajeto define uma ligação direta entre uma cidade de origem
 * e uma cidade de destino, com um tipo (Aquático ou Terrestre) e
 * uma distância em km. Os trajetos formam o "grafo" pelo qual o
 * algoritmo BFS calcula o melhor caminho entre cidades.
 */
class Trajeto {
private:
    Cidade* origem; ///< Ponteiro para a cidade de origem
    Cidade* destino; ///< Ponteiro para a cidade de destino
    char tipo; ///< Tipo do trajeto: 'T' para Terrestre, 'A' para Aquático
    int distancia; ///< Distância em km entre origem e destino

public:
     /**
     * @brief Constrói um trajeto entre duas cidades.
     * @param origem   Ponteiro para a cidade de origem
     * @param destino  Ponteiro para a cidade de destino
     * @param tipo     Tipo do trajeto ('T' ou 'A')
     * @param distancia Distância em km
     */
    Trajeto(Cidade* origem, Cidade* destino, char tipo, int distancia);
    
    /**
     * @brief Retorna a cidade de origem do trajeto.
     * @return Ponteiro para a cidade de origem
     */
    Cidade* getOrigem();
    /**
     * @brief Retorna a cidade de destino do trajeto.
     * @return Ponteiro para a cidade de destino
     */
    Cidade* getDestino();
    /**
     * @brief Retorna o tipo do trajeto.
     * @return Tipo do trajeto ('T' ou 'A')
     */
    char getTipo();
    /**
     * @brief Retorna a distância do trajeto.
     * @return Distância em km
     */
    int getDistancia();
};