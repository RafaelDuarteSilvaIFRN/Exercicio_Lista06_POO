#ifndef VENDAITEM_HPP
#define VENDAITEM_HPP

#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class VendaItem{

    private:
        int id, id_venda, id_produto, qtd;
        double preco;

    public:

        VendaItem(int id, int q, double p);
        
        void setId(int id);
        int getId() const;

        void setPreco(double preco);
        double getPreco() const;
        
        void setIdProduto(int id_produto);
        int getIdProduto() const;
        
        void setIdVenda(int id_venda);
        int getIdVenda() const;
        
        void setQuantidade(int qtd);
        int getQuantidade() const;
        
        string ToString() const;
        json to_json() const;
        static VendaItem from_json(json dic);
};

#endif