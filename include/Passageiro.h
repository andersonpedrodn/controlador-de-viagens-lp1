#pragma once
#include <string>
#include "Cidade.h"

/**
 * @brief Representa um passageiro no sistema de controle de viagens.
 * 
 * Um passageiro possui um nome e um local atual que indica em qual
 * cidade ele se encontra. O local atual é atualizado automaticamente
 * quando uma viagem é concluída, refletindo a nova posição do passageiro
 * no sistema.
 */
class Passageiro {
private:
    std::string nome; ///< Nome do passageiro
    Cidade* localAtual; ///< Ponteiro para a cidade onde o passageiro se encontra

public:

    /**
     * @brief Constrói um passageiro com nome e cidade inicial.
     * @param nome       Nome do passageiro
     * @param localAtual Ponteiro para a cidade inicial do passageiro
     */
    Passageiro(std::string nome, Cidade* localAtual);

    /**
     * @brief Retorna o nome do passageiro.
     * @return Nome do passageiro
     */
    std::string getNome();

    /**
     * @brief Retorna a cidade onde o passageiro se encontra.
     * @return Ponteiro para a cidade onde o passageiro se encontra
     */
    Cidade* getLocalAtual();

    /**
     * @brief Define a cidade onde o passageiro se encontra.
     * @param local Ponteiro para a nova cidade onde o passageiro se encontra
     */
    void setLocalAtual(Cidade* local);
};