#include <stdexcept>
#include "VendaItem.hpp"

VendaItem::VendaItem(int id, int q, double p){
    setId(id);
    setQuantidade(q);
    setPreco(p);
    this -> id_venda = id_venda;
    this -> id_produto = id_produto;
}

void VendaItem::setId(int id){
        if(id > 0){
          this -> id = id;
        } else{
           throw invalid_argument("Id invalido!");  
        }
}

int VendaItem::getId() const{
    return id;
}

void VendaItem::setPreco(double preco){

    if(preco > 0.0){
        this -> preco = preco;
    } else{
        throw invalid_argument("Preço invalido!");
    }

}

double VendaItem::getPreco() const{
    return preco;
}

void VendaItem::setIdProduto(int id_produto){
        if(id_produto > 0){
          this -> id_produto = id_produto;
        } else{
           throw invalid_argument("Id do Produto invalido!");  
        }
}

int VendaItem::getIdProduto() const{
    return id_produto;
}

void VendaItem::setIdVenda(int id_venda){
        if(id_venda > 0){
          this -> id_venda = id_venda;
        } else{
           throw invalid_argument("Id de venda invalido!");  
        }
}

int VendaItem::getIdVenda() const{
    return id_venda;
}

void VendaItem::setQuantidade(int qtd){

    if(qtd > 0){
       this -> qtd = qtd; 
    } else{
        throw invalid_argument("Quantidade invalida!");
    }

}

int VendaItem::getQuantidade() const{
    return qtd;
}

string VendaItem::ToString() const{
    return "Id: " + to_string(id) +
            "\nId da venda: " + to_string(id_venda) +
            "\nId do produto: " + to_string(id_produto) +
            "\nQuantidade: " + to_string(qtd) +
            "\nPreço: R$" + to_string(preco);
}

json VendaItem::to_json() const {

    json dados_VendaItem;

    dados_VendaItem["id"] = id;
    dados_VendaItem["id_produto"] = id_produto;
    dados_VendaItem["id_venda"] = id_venda;
    dados_VendaItem["quantidade"] = qtd;
    dados_VendaItem["preco"] = preco;

    return dados_VendaItem;
}

VendaItem VendaItem::from_json(json dic){

    int id = dic.at("id").get<int>();
    int quantidade = dic.at("quantidade").get<int>();
    double preco = dic.at("preco").get<double>();

    VendaItem v(id, quantidade, preco);

    if(dic.contains("id_produto")) v.id_produto = dic.at("id_produto").get<int>();
    if(dic.contains("id_venda")) v.id_venda = dic.at("id_venda").get<int>();

    return v;
}