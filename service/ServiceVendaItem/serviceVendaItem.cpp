#include "serviceVendaItem.hpp"
#include "../../models/VendaItem/vendaItem.hpp"
#include <stdexcept>

VendaItemDAO ServiceVendaItem::vendaItemDAO;
ProdutoDAO ServiceVendaItem::produtoDAO;
VendaDAO ServiceVendaItem::vendaDAO;

void ServiceVendaItem::vendaItem_inserir(int id, int id_venda, int id_produto, int qtd) {
    if (id_venda <= 0) {
        throw invalid_argument("Venda não encontrada!");
    }

    if (id_produto <= 0) {
        throw invalid_argument("Produto não encontrado!");
    }

    vendaDAO.Abrir();
    vendaDAO.Listar_Id(id_venda);
   
    produtoDAO.Abrir();
    produtoDAO.Listar_Id(id_produto);

    vendaItemdao.Abrir();
    VendaItem v(id);
    
    v.setIdVenda(id_venda);
    v.setIdProduto(id_produto);
    v.setQuantidade(qtd);

    vendaItemdao.Inserir(v);
    vendaItemdao.Salvar();
}

vector<VendaItem> ServiceVendaItem::vendaItem_Listar() {
    vendaItemdao.Abrir();
    return vendaItemdao.Listar();
}

Venda ServiceVendaItem::vendaItem_listar_id(int id) {
    vendaItemdao.Abrir();
    return vendaItemdao.Listar_Id(id);
}

void ServiceVendaItem::vendaItem_atualizar(int id, int id_venda, int id_produto, int qtd) {
    
    if (id_venda <= 0) {
        throw invalid_argument("Venda vazia!\n");
    }
    
    if (id_produto <= 0) {
        throw invalid_argument("Produto vazio!\n");
    }

    vendaItemdao.Abrir();
    VendaItem v = vendaItemdao.Listar_Id(id);
    v.setIdProduto(id_produto);
    v.setIdVenda(id_venda);
    v.setTotal(total);
    v.setQuantidade(qtd);

    vendaItemdao.Atualizar(v);
    vendaItemdao.Salvar();
}

void ServiceVendaItem::vendaItem_excluir(int id) {
    vendaItemdao.Abrir();
    VendaItem v = vendaItemdao.Listar_Id(id);
    vendaItemdao.Excluir(v.getId());
    vendaItemdao.Salvar();
}