#include <stdexcept>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include "CategoriaDAO.hpp"

using json = nlohmann::json;

void CategoriaDAO::Inserir(Categoria obj){
    objetos.push_back(obj);   
}

vector<Categoria> CategoriaDAO::Listar(){
    Abrir();
    return objetos;
}

Categoria CategoriaDAO::Listar_Id(int id){
    Abrir();
    for(const Categoria& c: objetos){
        if(c.getId() == id){
            return c; 
        }
    }

    throw invalid_argument("Cliente não encontrado!");
}

void CategoriaDAO::Atualizar(Categoria obj){
    for(Categoria& c : objetos){
        
        if(c.getId() == obj.getId()){
            c = obj;
            return;
        }

    }

    throw invalid_argument("Categoria não encontrado!");
}

void CategoriaDAO::Excluir(int id){
    for(size_t i = 0; i < objetos.size(); i++){

        if(objetos[i].getId() == id){
            objetos.erase(objetos.begin() + i);
            return; 
        }
    }

    throw invalid_argument("Categoria não encontrado!");
}

void CategoriaDAO::Abrir(){
    ifstream arquivo("categoria.json");

    if(!arquivo.is_open()){
        objetos.clear();
        return;
}

json dados;
arquivo >> dados;
arquivo.close();

objetos.clear();

for(const auto& item: dados){
    objetos.push_back(Categoria::from_json(item));
} 
}

void CategoriaDAO::Salvar(){
json dados = json::array();

for(const Categoria& c: objetos){
  dados.push_back(c.to_json());
}

ofstream arquivo("categoria.json");

if(!arquivo.is_open()){
    throw runtime_error("Não foi possivel salvar o arquivo");
}

arquivo << dados.dump(4);
}
