#pragma once
#include <string>

/**
 * @brief Representa uma cidade no sistema de controle de viagens.
 * 
 * Cidade é a entidade mais básica do sistema — todas as outras
 * classes (Trajeto, Passageiro, Transporte) referenciam cidades
 * através de ponteiros.
 */
class Cidade {
private:

    std::string nome; ///< Nome da cidade

public:
    /**
     * @brief Constrói uma cidade com o nome fornecido.
     * @param nome Nome da cidade
     */
    Cidade(std::string nome);

    /**
     * @brief Retorna o nome da cidade.
     * @return Nome da cidade
     */
    std::string getNome();
};