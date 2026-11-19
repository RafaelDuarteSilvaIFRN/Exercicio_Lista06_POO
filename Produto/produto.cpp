#include <stdexcept>
#include "produto.hpp"
using namespace std;

Produto::Produto(int id, string d, double p; int e){

    setId(id);
    setDescricao(d);
    setPreco(p);
}

void Produto::setId(int id){
        if(id > 0){
          this -> id = id;
        } else{
           throw invalid_argument("Id invalido!");  
        }
}

int Produto::getId() const{
    return id;
}

void Produto::setDescricao(string descricao){
    if(!descricao.empty()){
        this -> descricao = descricao;
    } else{
        throw invalid_argument("Descrição vazia!");  
    }
}

string Produto::getDescricao() const{
    return descricao;
}

void Produto::setPreco(string preco){
    if(!preco.empty()){
        this -> preco = preco;
    } else{
        throw invalid_argument("Preço informado esta vazio!");  
    }
}

double Produto::getPreco() const{
    return preco;
}

string Produto::ToString() const{

    return "Id: " + to_string(id) + "\nDescrição: " + descricao;

}

json Produto::to_json() const {

    json dados;

    dados["id"] = id;
    dados["descrição"] = descricao;
    dados["preço"] = preco;
    dados["estoque"] = estoque;
    dados["id_categoria"] = id_categoria;

    return dados;
}

Produto Produto::from_json(json dic){

    int id = dic.at("id").get<int>();
    string descricao = dic.at("descrição").get<string>();
    double preco = dic.at("preço").get<double>();
    int estoque = dic.at("estoque").get<int>();
    int categoria_id = dic.at("id_categoria").get<int>();

    return Produto(id, descricao, preco, estoque, categoria_id);
    
}
