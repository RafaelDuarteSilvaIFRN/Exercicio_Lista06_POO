#include "serviceProduto.hpp"
#include "../../models/Produto/produto.hpp"
#include <stdexcept>

ProdutoDAO ServiceProduto::produtoDAO;
CategoriaDAO ServiceProduto::categoriaDAO;

void ServiceProduto::produto_inserir(int id, int id_categoria, int estoque, string descricao, double preco) {
    if (id_categoria <= 0) {
        throw invalid_argument("id de categoria não encontrado!");
    }

    categoriaDAO.Abrir();
    categoriaDAO.Listar_Id(id_categoria);

    produtoDAO.Abrir();
    Produto p(id, descricao, preco, estoque);
    p.setIdCategoria(id_categoria);
    produtoDAO.Inserir(p);
    produtoDAO.Salvar();
}

vector<Produto> ServiceProduto::produto_listar() {
    produtoDAO.Abrir();
    return produtoDAO.Listar();
}

Produto ServiceProduto::produto_listar_id(int id) {
    produtoDAO.Abrir();
    return produtoDAO.Listar_Id(id);
}

void ServiceProduto::produto_atualizar(int id, int id_categoria, int estoque, string descricao, double preco) {
    if (id_categoria <= 0) {
        throw invalid_argument("Categoria vazio!\n");
    }

    categoriaDAO.Abrir();
    categoriaDAO.Listar_Id(id_categoria);

    produtoDAO.Abrir();
    Produto p = produtoDAO.Listar_Id(id);
    p.setIdCategoria(id_categoria);
    p.setDescricao(descricao);
    p.setPreco(preco);
    p.setEstoque(estoque);

    produtoDAO.Atualizar(p);
    produtoDAO.Salvar();
}

void ServiceProduto::produto_excluir(int id) {
    produtoDAO.Abrir();
    Produto p = produtoDAO.Listar_Id(id);
    produtoDAO.Excluir(p.getId());
    produtoDAO.Salvar();
}