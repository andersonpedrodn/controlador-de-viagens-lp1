#pragma once
#include <vector>
#include "Transporte.h"
#include "Passageiro.h"
#include "Cidade.h"

/**
 * @brief Representa uma etapa de viagem entre duas cidades adjacentes.
 *
 * Uma viagem conecta sempre duas cidades vizinhas (um único trajeto).
 * Rotas com escalas são decompostas em várias Viagens encadeadas via
 * o ponteiro `proxima`, que é iniciada automaticamente quando a atual
 * é concluída.
 */
class Viagem {
private:
    Transporte* transporte;                ///< Transporte utilizado nesta etapa
    std::vector<Passageiro*> passageiros;  ///< Passageiros a bordo nesta etapa
    Cidade* origem;                        ///< Cidade de partida desta etapa
    Cidade* destino;                       ///< Cidade de chegada desta etapa
    Viagem* proxima;                       ///< Próxima etapa da rota (nullptr se for a última)
    int horasEmTransito;                   ///< Horas acumuladas desde o início da viagem
    int distancia;                         ///< Distância em km desta etapa
    bool emAndamento;                      ///< True enquanto a viagem está em progresso
    bool concluida;                        ///< True após a viagem ser encerrada

public:
    /**
     * @brief Constrói uma viagem entre duas cidades com um transporte e passageiros.
     * @param transporte  Ponteiro para o transporte utilizado
     * @param passageiros Lista de ponteiros para os passageiros embarcados
     * @param origem      Ponteiro para a cidade de partida
     * @param destino     Ponteiro para a cidade de chegada
     */
    Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros,
           Cidade* origem, Cidade* destino);

    /**
     * @brief Marca a viagem como em andamento e imprime uma mensagem de início.
     */
    void iniciarViagem();

    /**
     * @brief Acumula horas de trânsito e verifica se a viagem foi concluída.
     * @param horas Número de horas a avançar
     */
    void avancarHoras(int horas);

    /**
     * @brief Imprime o estado atual da viagem no console.
     */
    void relatarEstado();

    /**
     * @brief Verifica se a viagem está em andamento.
     * @return True se a viagem ainda não foi concluída
     */
    bool isEmAndamento();

    /**
     * @brief Verifica se a viagem foi concluída.
     * @return True após a viagem ser encerrada
     */
    bool isConcluida();

    /**
     * @brief Retorna a próxima etapa da rota.
     * @return Ponteiro para a próxima Viagem, ou nullptr se for a última etapa
     */
    Viagem* getProxima();

    /**
     * @brief Define a próxima etapa da rota.
     * @param prox Ponteiro para a próxima Viagem
     */
    void setProxima(Viagem* prox);

    /**
     * @brief Define a distância desta etapa em km.
     * @param dist Distância em km
     */
    void setDistancia(int dist);

    /**
     * @brief Retorna a distância desta etapa em km.
     * @return Distância em km
     */
    int getDistancia();

    /**
     * @brief Retorna o transporte utilizado nesta etapa.
     * @return Ponteiro para o transporte
     */
    Transporte* getTransporte();

    /**
     * @brief Retorna a cidade de partida desta etapa.
     * @return Ponteiro para a cidade de origem
     */
    Cidade* getOrigem();

    /**
     * @brief Retorna a cidade de chegada desta etapa.
     * @return Ponteiro para a cidade de destino
     */
    Cidade* getDestino();
};