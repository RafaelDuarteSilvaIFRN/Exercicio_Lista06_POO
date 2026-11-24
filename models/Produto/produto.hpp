#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class Produto{
    
    private:
        int id;
        string descricao;
        double preco;
        int estoque;
        int id_categoria;

    public:
        Produto(int id, string d, double p, int e);
        
        void setId(int id);
        int getId() const;
        
        void setDescricao(string descricao);
        string getDescricao() const;

        void setPreco(double preco);
        double getPreco() const;

        void setEstoque(int estoque);
        int getEstoque() const;

        void setIdCategoria(int id_categoria);
        int getIdCategoria() const;

        string ToString() const;
        json to_json() const;
        static Produto from_json(json dic);
};

#endif