#include "serviceCliente.hpp"
#include <stdexcept>

ClienteDAO ServiceCliente::clienteDAO;

void ServiceCliente::cliente_inserir(int id, const string& nome, const string& email, const string& fone) {
    if (nome.empty()) {
        throw invalid_argument("Nome do cliente vazio!");
    }

    clienteDAO.Abrir();
    Cliente c(id, nome, email, fone);
    clienteDAO.Inserir(c);
    clienteDAO.Salvar();
}

vector<Cliente> ServiceCliente::cliente_listar() {
    clienteDAO.Abrir();
    return clienteDAO.Listar();
}

Cliente ServiceCliente::cliente_listar_id(int id) {
    clienteDAO.Abrir();
    return clienteDAO.Listar_Id(id);
}

void ServiceCliente::cliente_atualizar(int id, const string& nome, const string& email, const string& fone) {
    if (nome.empty()) {
        throw invalid_argument("Nome do cliente vazio!");
    }

    clienteDAO.Abrir();
    Cliente c = clienteDAO.Listar_Id(id);
    c.setNome(nome);
    c.setEmail(email);
    c.setFone(fone);

    clienteDAO.Atualizar(c);
    clienteDAO.Salvar();
}

void ServiceCliente::cliente_excluir(int id) {
    clienteDAO.Abrir();
    Cliente c = clienteDAO.Listar_Id(id);
    clienteDAO.Excluir(c.getId());
    clienteDAO.Salvar();
}