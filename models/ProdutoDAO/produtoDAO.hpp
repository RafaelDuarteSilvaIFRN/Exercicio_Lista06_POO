#ifndef PRODUTODAO_HPP
#define PRODUTODAO_HPP

#include <vector>
#include "../produto/produto.hpp"

class ProdutoDAO{
    
    private:
        
        vector<Produto> objetos;

    public:

        void Inserir(Produto obj);

        vector<Produto> Listar();

        Produto Listar_Id(int id);

        void Atualizar(Produto obj);

        void Excluir(int id);

        void Abrir();

        void Salvar();
};

#endif