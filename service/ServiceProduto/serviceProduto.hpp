#ifndef SERVICE_PRODUTO_HPP
#define SERVICE_PRODUTO_HPP

#include <vector>
#include "../../models/Produto/produto.hpp"
#include "../../models/ProdutoDAO/produtoDAO.hpp"
#include "../../models/CategoriaDAO/CategoriaDAO.hpp"


using namespace std;

class ServiceProduto{
    private:
        static ProdutoDAO produtoDAO;
        static CategoriaDAO categoriaDAO;
    public:

        static void produto_inserir(int id, int id_categoria, int estoque, string descricao, double preco);
        static vector<Produto> produto_listar();
        static Produto produto_listar_id(int id);
        static void produto_atualizar(int id, int id_categoria, int estoque, string descricao, double preco);
        static void produto_excluir(int id);

};

#endif