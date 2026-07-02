#include "ControladorDeTransito.h"
#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>

/**
 * @brief Busca uma cidade pelo nome percorrendo o vetor de cidades.
 * @return Ponteiro para a cidade encontrada, ou nullptr.
 */
Cidade* ControladorDeTransito::buscarCidade(std::string nome) {
    for (Cidade* c : cidades)
        if (c->getNome() == nome) return c;
    return nullptr;
}

/**
 * @brief Busca um transporte pelo nome percorrendo o vetor de transportes.
 * @return Ponteiro para o transporte encontrado, ou nullptr.
 */
Transporte* ControladorDeTransito::buscarTransporte(std::string nome) {
    for (Transporte* t : transportes)
        if (t->getNome() == nome) return t;
    return nullptr;
}

/**
 * @brief Busca um passageiro pelo nome percorrendo o vetor de passageiros.
 * @return Ponteiro para o passageiro encontrado, ou nullptr.
 */
Passageiro* ControladorDeTransito::buscarPassageiro(std::string nome) {
    for (Passageiro* p : passageiros)
        if (p->getNome() == nome) return p;
    return nullptr;
}

/**
 * @brief Busca um trajeto direto entre duas cidades.
 *
 * Compara ponteiros de cidades (não nomes), então origem e destino
 * devem ser os mesmos objetos armazenados no vetor de cidades.
 * @return Ponteiro para o trajeto encontrado, ou nullptr.
 */
Trajeto* ControladorDeTransito::buscarTrajeto(Cidade* origem, Cidade* destino) {
    for (Trajeto* t : trajetos)
        if (t->getOrigem() == origem && t->getDestino() == destino)
            return t;
    return nullptr;
}

/**
 * @brief Calcula o menor caminho entre duas cidades usando BFS.
 *
 * Trata os trajetos como arestas de um grafo orientado e retorna
 * a sequência de cidades do caminho com menor número de saltos.
 * Retorna vetor vazio se não houver rota entre origem e destino.
 */
std::vector<Cidade*> ControladorDeTransito::calcularMelhorTrajeto(Cidade* origem, Cidade* destino) {
    std::queue<Cidade*> fila;
    std::map<Cidade*, Cidade*> anterior;

    fila.push(origem);
    anterior[origem] = nullptr;

    while (!fila.empty()) {
        Cidade* atual = fila.front();
        fila.pop();

        if (atual == destino) {
            std::vector<Cidade*> caminho;
            Cidade* c = destino;
            while (c != nullptr) {
                caminho.insert(caminho.begin(), c);
                c = anterior[c];
            }
            return caminho;
        }

        for (Trajeto* t : trajetos) {
            if (t->getOrigem() == atual && anterior.find(t->getDestino()) == anterior.end()) {
                anterior[t->getDestino()] = atual;
                fila.push(t->getDestino());
            }
        }
    }

    return {};
}

/**
 * @brief Cadastra uma nova cidade se ela ainda não existir.
 */
void ControladorDeTransito::cadastrarCidade(std::string nome) {
    if (buscarCidade(nome)) {
        std::cout << "Cidade já cadastrada: " << nome << std::endl;
        return;
    }
    cidades.push_back(new Cidade(nome));
    std::cout << "Cidade cadastrada: " << nome << std::endl;
}

/**
 * @brief Cadastra um trajeto entre duas cidades já existentes no sistema.
 */
void ControladorDeTransito::cadastrarTrajeto(std::string nomeOrigem, std::string nomeDestino,
                                              char tipo, int distancia) {
    Cidade* origem = buscarCidade(nomeOrigem);
    Cidade* destino = buscarCidade(nomeDestino);

    if (!origem || !destino) {
        std::cout << "Cidade não encontrada." << std::endl;
        return;
    }

    trajetos.push_back(new Trajeto(origem, destino, tipo, distancia));
    std::cout << "Trajeto cadastrado: " << nomeOrigem << " -> " << nomeDestino << std::endl;
}

/**
 * @brief Cadastra um transporte posicionado em uma cidade já existente.
 */
void ControladorDeTransito::cadastrarTransporte(std::string nome, char tipo, int capacidade,
                                                 int velocidade, int distanciaEntreDescansos,
                                                 int tempoDeDescanso, std::string localAtual) {
    Cidade* cidade = buscarCidade(localAtual);
    if (!cidade) {
        std::cout << "Cidade não encontrada: " << localAtual << std::endl;
        return;
    }
    transportes.push_back(new Transporte(nome, tipo, capacidade, velocidade,
                                          distanciaEntreDescansos, tempoDeDescanso, cidade));
    std::cout << "Transporte cadastrado: " << nome << std::endl;
}

/**
 * @brief Cadastra um passageiro em uma cidade já existente.
 */
void ControladorDeTransito::cadastrarPassageiro(std::string nome, std::string localAtual) {
    Cidade* cidade = buscarCidade(localAtual);
    if (!cidade) {
        std::cout << "Cidade não encontrada: " << localAtual << std::endl;
        return;
    }
    passageiros.push_back(new Passageiro(nome, cidade));
    std::cout << "Passageiro cadastrado: " << nome << std::endl;
}

/**
 * @brief Planeja e inicia uma viagem, decompondo a rota em etapas encadeadas.
 *
 * Usa BFS para encontrar a rota, cria uma Viagem por par de cidades consecutivas
 * e as encadeia via setProxima. Apenas a primeira etapa é iniciada imediatamente;
 * as demais são disparadas automaticamente ao concluir a etapa anterior.
 */
void ControladorDeTransito::iniciarViagem(std::string nomeTransporte,
                                           std::vector<std::string> nomesPassageiros,
                                           std::string nomeOrigem, std::string nomeDestino) {
    Transporte* transporte = buscarTransporte(nomeTransporte);
    Cidade* origem = buscarCidade(nomeOrigem);
    Cidade* destino = buscarCidade(nomeDestino);

    if (!transporte || !origem || !destino) {
        std::cout << "Transporte ou cidade não encontrado." << std::endl;
        return;
    }

    if (transporte->getLocalAtual() != origem) {
        std::cout << "Transporte não está na cidade de origem." << std::endl;
        return;
    }

    std::vector<Passageiro*> listaPassageiros;
    for (std::string nome : nomesPassageiros) {
        Passageiro* p = buscarPassageiro(nome);
        if (p) listaPassageiros.push_back(p);
    }

    std::vector<Cidade*> caminho = calcularMelhorTrajeto(origem, destino);

    if (caminho.empty()) {
        std::cout << "Não existe trajeto entre " << nomeOrigem << " e " << nomeDestino << std::endl;
        return;
    }

    Viagem* primeira = nullptr;
    Viagem* anterior = nullptr;

    for (int i = 0; i < (int)caminho.size() - 1; i++) {
        Viagem* v = new Viagem(transporte, listaPassageiros, caminho[i], caminho[i+1]);

        Trajeto* t = buscarTrajeto(caminho[i], caminho[i+1]);
        if (t) v->setDistancia(t->getDistancia());

        viagens.push_back(v);

        if (!primeira) primeira = v;
        if (anterior) anterior->setProxima(v);
        anterior = v;
    }

    if (primeira) primeira->iniciarViagem();
}

/**
 * @brief Repassa o avanço de horas para todas as viagens em andamento.
 */
void ControladorDeTransito::avancarHoras(int horas) {
    for (Viagem* v : viagens)
        if (v->isEmAndamento())
            v->avancarHoras(horas);
}

/**
 * @brief Exibe o estado de todas as viagens cadastradas no sistema.
 */
void ControladorDeTransito::relatarEstado() {
    std::cout << "\n=== Estado do Sistema ===" << std::endl;
    for (Viagem* v : viagens)
        v->relatarEstado();
}
/**
 * @brief Exibe a localização de cada passageiro — cidade ou trecho em trânsito.
 */
void ControladorDeTransito::relatarPassageiros() {
    std::cout << "\n=== Localização dos Passageiros ===" << std::endl;

    for (Passageiro* p : passageiros) {
        bool emTransito = false;
        for (Viagem* v : viagens) {
            if (v->isEmAndamento()) {
                emTransito = true;
                std::cout << p->getNome() << " | Em trânsito: "
                          << v->getOrigem()->getNome() << " -> "
                          << v->getDestino()->getNome()
                          << " | Transporte: " << v->getTransporte()->getNome()
                          << std::endl;
                break;
            }
        }
        if (!emTransito) {
            std::cout << p->getNome() << " | Em: "
                      << p->getLocalAtual()->getNome() << std::endl;
        }
    }
}

/**
 * @brief Exibe a localização de cada transporte — cidade ou trecho em trânsito.
 */
void ControladorDeTransito::relatarTransportes() {
    std::cout << "\n=== Localização dos Transportes ===" << std::endl;

    for (Transporte* t : transportes) {
        bool emTransito = false;
        for (Viagem* v : viagens) {
            if (v->isEmAndamento() && v->getTransporte() == t) {
                emTransito = true;
                std::cout << t->getNome() << " | Em trânsito: "
                          << v->getOrigem()->getNome() << " -> "
                          << v->getDestino()->getNome()
                          << std::endl;
                break;
            }
        }
        if (!emTransito) {
            std::cout << t->getNome() << " | Em: "
                      << t->getLocalAtual()->getNome() << std::endl;
        }
    }
}

/**
 * @brief Exibe apenas as viagens que ainda estão em progresso.
 */
void ControladorDeTransito::relatarViagensEmAndamento() {
    std::cout << "\n=== Viagens em Andamento ===" << std::endl;

    bool alguma = false;
    for (Viagem* v : viagens) {
        if (v->isEmAndamento()) {
            v->relatarEstado();
            alguma = true;
        }
    }
    if (!alguma)
        std::cout << "Nenhuma viagem em andamento." << std::endl;
}

/**
 * @brief Exibe as cidades de destino com mais viagens concluídas, em ordem decrescente.
 */
void ControladorDeTransito::relatarCidadesMaisVisitadas() {
    std::cout << "\n=== Cidades Mais Visitadas ===" << std::endl;

    std::map<Cidade*, int> visitas;

    for (Viagem* v : viagens) {
        if (v->isConcluida()) {
            visitas[v->getDestino()]++;
        }
    }

    if (visitas.empty()) {
        std::cout << "Nenhuma viagem concluída ainda." << std::endl;
        return;
    }

    std::vector<std::pair<Cidade*, int>> ranking(visitas.begin(), visitas.end());
    std::sort(ranking.begin(), ranking.end(),
              [](auto& a, auto& b) { return a.second > b.second; });

    for (auto& par : ranking) {
        std::cout << par.first->getNome() << " | Visitas: " << par.second << std::endl;
    }
}
/**
 * @brief Salva cidades, trajetos, transportes e passageiros em arquivos CSV na pasta data/.
 *
 * Cada entidade tem seu próprio arquivo. O estado de viagens em andamento
 * não é persistido — ao recarregar, apenas o cadastro base é restaurado.
 */
void ControladorDeTransito::salvarDados() {
    std::ofstream fileCidades("data/cidades.txt");
    for (Cidade* c : cidades)
        fileCidades << c->getNome() << "\n";
    fileCidades.close();

    std::ofstream fileTrajetos("data/trajetos.txt");
    for (Trajeto* t : trajetos)
        fileTrajetos << t->getOrigem()->getNome() << ";"
                     << t->getDestino()->getNome() << ";"
                     << t->getTipo() << ";"
                     << t->getDistancia() << "\n";
    fileTrajetos.close();

    std::ofstream fileTransportes("data/transportes.txt");
    for (Transporte* t : transportes)
        fileTransportes << t->getNome() << ";"
                        << t->getTipo() << ";"
                        << t->getCapacidade() << ";"
                        << t->getVelocidade() << ";"
                        << t->getDistanciaEntreDescansos() << ";"
                        << t->getTempoDescanso() << ";"
                        << t->getLocalAtual()->getNome() << "\n";
    fileTransportes.close();

    std::ofstream filePassageiros("data/passageiros.txt");
    for (Passageiro* p : passageiros)
        filePassageiros << p->getNome() << ";"
                        << p->getLocalAtual()->getNome() << "\n";
    filePassageiros.close();

    std::cout << "Dados salvos com sucesso!" << std::endl;
}

/**
 * @brief Carrega cidades, trajetos, transportes e passageiros dos arquivos CSV na pasta data/.
 *
 * Os campos são separados por ';'. Se um arquivo não existir, ele é ignorado
 * silenciosamente e o carregamento dos demais continua.
 */
void ControladorDeTransito::carregarDados() {
    std::string linha;

    std::ifstream fileCidades("data/cidades.txt");
    if (fileCidades.is_open()) {
        while (std::getline(fileCidades, linha)) {
            if (!linha.empty())
                cadastrarCidade(linha);
        }
        fileCidades.close();
    }

    std::ifstream fileTrajetos("data/trajetos.txt");
    if (fileTrajetos.is_open()) {
        while (std::getline(fileTrajetos, linha)) {
            if (linha.empty()) continue;
            std::stringstream ss(linha);
            std::string origem, destino, tipoStr, distStr;
            std::getline(ss, origem, ';');
            std::getline(ss, destino, ';');
            std::getline(ss, tipoStr, ';');
            std::getline(ss, distStr, ';');
            cadastrarTrajeto(origem, destino, tipoStr[0], std::stoi(distStr));
        }
        fileTrajetos.close();
    }

    std::ifstream fileTransportes("data/transportes.txt");
    if (fileTransportes.is_open()) {
        while (std::getline(fileTransportes, linha)) {
            if (linha.empty()) continue;
            std::stringstream ss(linha);
            std::string nome, tipoStr, cap, vel, dist, tempo, local;
            std::getline(ss, nome, ';');
            std::getline(ss, tipoStr, ';');
            std::getline(ss, cap, ';');
            std::getline(ss, vel, ';');
            std::getline(ss, dist, ';');
            std::getline(ss, tempo, ';');
            std::getline(ss, local, ';');
            cadastrarTransporte(nome, tipoStr[0], std::stoi(cap), std::stoi(vel),
                                std::stoi(dist), std::stoi(tempo), local);
        }
        fileTransportes.close();
    }

    std::ifstream filePassageiros("data/passageiros.txt");
    if (filePassageiros.is_open()) {
        while (std::getline(filePassageiros, linha)) {
            if (linha.empty()) continue;
            std::stringstream ss(linha);
            std::string nome, local;
            std::getline(ss, nome, ';');
            std::getline(ss, local, ';');
            cadastrarPassageiro(nome, local);
        }
        filePassageiros.close();
    }

    std::cout << "Dados carregados com sucesso!" << std::endl;
}