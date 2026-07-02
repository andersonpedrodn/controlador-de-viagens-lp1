#include "Cidade.h"
/**
 * @brief Construtor da classe Cidade.
 * 
 * Inicializa o atributo nome com o valor recebido por parâmetro.
 * O uso de "this->nome" diferencia o atributo da classe do 
 * parâmetro de mesmo nome recebido pelo construtor.
 */
Cidade::Cidade(std::string nome) {
    this->nome = nome;
}

/**
 * @brief Retorna o nome da cidade.
 * 
 * Getter do atributo privado "nome". Como nome é private,
 * nenhuma outra classe pode acessá-lo diretamente — precisam
 * passar por esse método.
 */
std::string Cidade::getNome() {
    return nome;
}