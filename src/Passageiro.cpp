#include "Passageiro.h"

/**
 * @brief Construtor da classe Passageiro.
 *
 * Inicializa o nome e a cidade inicial do passageiro. O localAtual
 * aponta para uma cidade já existente no sistema — não cria uma cópia.
 */
Passageiro::Passageiro(std::string nome, Cidade* localAtual) {
    this->nome = nome;
    this->localAtual = localAtual;
}

/**
 * @brief Retorna o nome do passageiro.
 */
std::string Passageiro::getNome() {
    return nome;
}

/**
 * @brief Retorna a cidade onde o passageiro se encontra atualmente.
 */
Cidade* Passageiro::getLocalAtual() {
    return localAtual;
}

/**
 * @brief Atualiza a cidade onde o passageiro se encontra.
 *
 * Chamado automaticamente por Viagem::avancarHoras quando uma
 * viagem é concluída, movendo o passageiro para o destino.
 */
void Passageiro::setLocalAtual(Cidade* local) {
    this->localAtual = local;
}