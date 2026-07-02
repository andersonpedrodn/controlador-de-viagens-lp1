#include "Trajeto.h"

/**
 * @brief Construtor da classe Trajeto.
 * 
 * Inicializa todos os atributos do trajeto. Os ponteiros origem e destino
 * apontam para objetos Cidade já existentes no sistema — não criam cópias.
 * Isso garante que todos os trajetos referenciam as mesmas cidades
 * cadastradas no ControladorDeTransito.
 */
Trajeto::Trajeto(Cidade* origem, Cidade* destino, char tipo, int distancia) {
    this->origem = origem;
    this->destino = destino;
    this->tipo = tipo;
    this->distancia = distancia;
}

/**
 * @brief Retorna a cidade de origem.
 * @return Ponteiro para a cidade de origem
 */
Cidade* Trajeto::getOrigem() {
    return origem;
}
/**
 * @brief Retorna a cidade de destino.
 * @return Ponteiro para a cidade de destino
 */ 
Cidade* Trajeto::getDestino() {
    return destino;
}

/**
 * @brief Retorna o tipo do trajeto.
 * @return 'T' para Terrestre ou 'A' para Aquático
 */
char Trajeto::getTipo() {
    return tipo;
}

/**
 * @brief Retorna a distância do trajeto.
 * @return Distância em km
 */
int Trajeto::getDistancia() {
    return distancia;
}