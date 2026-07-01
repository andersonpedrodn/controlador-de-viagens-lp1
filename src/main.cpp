#include <iostream>
#include "Cidade.h"
#include "Passageiro.h"

int main() {
    Cidade natal("Natal");
    Cidade mossoro("Mossoró");

    Passageiro p("Anderson", &natal);

    std::cout << "Passageiro: " << p.getNome()
              << " | Local atual: " << p.getLocalAtual()->getNome()
              << std::endl;

    // simula mudança de cidade
    p.setLocalAtual(&mossoro);

    std::cout << "Após viagem: " << p.getNome()
              << " | Local atual: " << p.getLocalAtual()->getNome()
              << std::endl;

    return 0;
}