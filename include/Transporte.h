#pragma once
#include <string>
#include "Cidade.h"

/**
 * @brief Representa um meio de transporte no sistema de viagens.
 *
 * Um transporte possui tipo (Terrestre ou Aquático), capacidade de passageiros,
 * velocidade e parâmetros de descanso que determinam quanto tempo uma viagem
 * leva. O cálculo de tempo total considera paradas obrigatórias a cada
 * distanciaEntreDescansos km.
 */
class Transporte {
private:
    std::string nome;               ///< Nome do transporte
    char tipo;                      ///< Tipo: 'T' para Terrestre, 'A' para Aquático
    int capacidade;                 ///< Número máximo de passageiros
    int velocidade;                 ///< Velocidade em km/h
    int distanciaEntreDescansos;    ///< Km percorridos até a próxima parada obrigatória
    int tempoDeDescanso;            ///< Duração de cada parada em horas
    int tempoDeDescansoAtual;       ///< Horas de descanso acumuladas na viagem atual
    Cidade* localAtual;             ///< Ponteiro para a cidade onde o transporte se encontra

public:
    /**
     * @brief Constrói um transporte com todos os seus atributos.
     * @param nome                  Nome do transporte
     * @param tipo                  Tipo do transporte ('T' ou 'A')
     * @param capacidade            Capacidade máxima de passageiros
     * @param velocidade            Velocidade em km/h
     * @param distanciaEntreDescansos Km entre cada parada obrigatória
     * @param tempoDeDescanso       Horas de descanso por parada
     * @param localAtual            Ponteiro para a cidade inicial
     */
    Transporte(std::string nome, char tipo, int capacidade, int velocidade,
               int distanciaEntreDescansos, int tempoDeDescanso, Cidade* localAtual);

    /**
     * @brief Retorna o nome do transporte.
     * @return Nome do transporte
     */
    std::string getNome();

    /**
     * @brief Retorna o tipo do transporte.
     * @return 'T' para Terrestre ou 'A' para Aquático
     */
    char getTipo();

    /**
     * @brief Retorna a capacidade máxima de passageiros.
     * @return Capacidade de passageiros
     */
    int getCapacidade();

    /**
     * @brief Retorna a velocidade do transporte.
     * @return Velocidade em km/h
     */
    int getVelocidade();

    /**
     * @brief Retorna a distância entre descansos obrigatórios.
     * @return Distância em km
     */
    int getDistanciaEntreDescansos();

    /**
     * @brief Retorna a duração de cada parada de descanso.
     * @return Tempo de descanso em horas
     */
    int getTempoDescanso();

    /**
     * @brief Retorna as horas de descanso acumuladas na viagem atual.
     * @return Horas de descanso acumuladas
     */
    int getTempoDescansoAtual();

    /**
     * @brief Retorna a cidade onde o transporte se encontra.
     * @return Ponteiro para a cidade atual
     */
    Cidade* getLocalAtual();

    /**
     * @brief Atualiza a cidade onde o transporte se encontra.
     * @param local Ponteiro para a nova cidade
     */
    void setLocalAtual(Cidade* local);
};