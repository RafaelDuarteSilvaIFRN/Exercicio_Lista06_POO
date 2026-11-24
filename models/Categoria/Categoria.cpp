#include <stdexcept>
#include "Categoria.hpp"
using namespace std;

Categoria::Categoria(int id, string d){

    setId(id);
    setDescricao(d);

}

void Categoria::setId(int id){
        if(id > 0){
          this -> id = id;
        } else{
           throw invalid_argument("Id invalido!");  
        }
}

int Categoria::getId() const{
    return id;
}

void Categoria::setDescricao(string descricao){
    if(!descricao.empty()){
        this -> descricao = descricao;
    } else{
        throw invalid_argument("Descrição vazia!");  
    }
}

string Categoria::getDescricao() const{
    return descricao;
}

string Categoria::ToString() const{

    return "\nId: " + to_string(id) + 
            "\nDescrição: " + descricao + "\n";

}

json Categoria::to_json() const {

    json dados;

    dados["id"] = id;
    dados["descrição"] = descricao;

    return dados;
}

Categoria Categoria::from_json(json dic){

    int id = dic.at("id").get<int>();
    string descricao = dic.at("descrição").get<string>();
    
    return Categoria(id, descricao);
    
}
