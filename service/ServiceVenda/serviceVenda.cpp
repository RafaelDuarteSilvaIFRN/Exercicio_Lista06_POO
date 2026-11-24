#include "serviceVenda.hpp"
#include "../../models/Venda/Venda.hpp"
#include <stdexcept>

VendaDAO ServiceVenda::vendadao;
ClienteDAO ServiceVenda::clienteDAO;

void ServiceVenda::venda_inserir(int id, int id_cliente) {
    if (id_cliente <= 0) {
        throw invalid_argument("id de cliente não encontrado!");
    }

    clienteDAO.Abrir();
    clienteDAO.Listar_Id(id_cliente);

    vendadao.Abrir();
    Venda v(id);
    v.setIdCliente(id_cliente);
    vendadao.Inserir(v);
    vendadao.Salvar();
}

vector<Venda> ServiceVenda::venda_Listar() {
    vendadao.Abrir();
    return vendadao.Listar();
}

Venda ServiceVenda::venda_listar_id(int id) {
    vendadao.Abrir();
    return vendadao.Listar_Id(id);
}

void ServiceVenda::venda_atualizar(int id, int id_cliente, double total) {
    if (id_cliente <= 0) {
        throw invalid_argument("Nome de cliente vazio!\n");
    }

    vendadao.Abrir();
    Venda v = vendadao.Listar_Id(id);
    v.setIdCliente(id_cliente);
    v.setTotal(total);

    vendadao.Atualizar(v);
    vendadao.Salvar();
}

void ServiceVenda::venda_excluir(int id) {
    vendadao.Abrir();
    Venda v = vendadao.Listar_Id(id);
    vendadao.Excluir(v.getId());
    vendadao.Salvar();
}