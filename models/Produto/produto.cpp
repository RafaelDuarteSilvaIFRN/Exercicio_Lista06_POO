#include <stdexcept>
#include "produto.hpp"
#include <sstream>

Produto::Produto(int id, string d, double p, int e){

    setId(id);
    setDescricao(d);
    setPreco(p);
    setEstoque(e);
    this -> id_categoria = id_categoria;
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

void Produto::setPreco(double preco){
    if(preco > 0){
        this -> preco = preco;
    } else{
        throw invalid_argument("Preço informado esta vazio!");  
    }
}

double Produto::getPreco() const{
    return preco;
}

string Produto::ToString() const{

    std::ostringstream tostring;
    tostring << "\nId: " << id
    << "\nDescrição: " << descricao
    << "\nPreço: R$" << std::fixed << std::setprecision(2) << preco
    << "\nEstoque: " << estoque;

    return tostring.str();
}

void Produto::setEstoque(int estoque){

    if(estoque >= 0){
        this -> estoque = estoque;
    } else{
         throw invalid_argument("Estoque invalido!");
    }

}

int Produto::getEstoque() const{
    return estoque;
}

void Produto::setIdCategoria(int id_categoria){
     if(id_categoria > 0){
        this -> id_categoria = id_categoria;
     } else{
        throw invalid_argument("Id de categoria invalida!");
     }
}

int Produto::getIdCategoria() const{
    return id_categoria;
}

json Produto::to_json() const {

    json dados;

    dados["id"] = id;
    dados["descricao"] = descricao;
    dados["preco"] = preco;
    dados["estoque"] = estoque;
    dados["id_categoria"] = id_categoria;

    return dados;
}

Produto Produto::from_json(json dic){

    int id = dic.at("id").get<int>();
    string descricao = dic.at("descricao").get<string>();
    double preco = dic.at("preco").get<double>();
    int estoque = dic.at("estoque").get<int>();

    Produto p(id, descricao, preco, estoque);

    if(dic.contains("id_categoria")) p.id_categoria = dic.at("id_categoria").get<int>();

    return p;
    
}
