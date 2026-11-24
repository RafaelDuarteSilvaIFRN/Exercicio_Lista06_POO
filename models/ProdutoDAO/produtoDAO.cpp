#include <stdexcept>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include "ProdutoDAO.hpp"

using json = nlohmann::json;

void ProdutoDAO::Inserir(Produto obj){
    Abrir();

    for(const Produto& p: objetos){
        if(p.getId() == obj.getId()){
            throw invalid_argument("Produto ja cadastrado no sistema!"); 
        }
    }

    objetos.push_back(obj);   
    Salvar();
}

vector<Produto> ProdutoDAO::Listar(){
    Abrir();
    return objetos;
}

Produto ProdutoDAO::Listar_Id(int id){
    Abrir();
    for(const Produto& c: objetos){
        if(c.getId() == id){
            return c; 
        }
    }

    throw invalid_argument("Produto não encontrado!");
}

void ProdutoDAO::Atualizar(Produto obj){
    Abrir();
    for(Produto& c : objetos){
        
        if(c.getId() == obj.getId()){
            c = obj;
            Salvar();
            return;
        }

    }

    throw invalid_argument("Produto não encontrado!");
}

void ProdutoDAO::Excluir(int id){
    Abrir();
    for(size_t i = 0; i < objetos.size(); i++){

        if(objetos[i].getId() == id){
            objetos.erase(objetos.begin() + i);
            Salvar();
            return; 
        }
    }

    throw invalid_argument("Produto não encontrado!");
}

void ProdutoDAO::Abrir(){
    ifstream arquivo("produto.json");

    if(!arquivo.is_open()){
        objetos.clear();
        return;
}

json dados;
arquivo >> dados;
arquivo.close();

objetos.clear();

for(const auto& item: dados){
    objetos.push_back(Produto::from_json(item));
} 
}

void ProdutoDAO::Salvar(){
json dados = json::array();

for(const Produto& c: objetos){
  dados.push_back(c.to_json());
}

ofstream arquivo("produto.json");

if(!arquivo.is_open()){
    throw runtime_error("Não foi possivel salvar o arquivo");
}

arquivo << dados.dump(4);
arquivo.close();
}
