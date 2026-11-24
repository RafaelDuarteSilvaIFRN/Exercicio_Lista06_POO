#include <stdexcept>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include "VendaDAO.hpp"

using json = nlohmann::json;

void VendaDAO::Inserir(Venda obj){
    Abrir();

    for(const Venda& c: objetos){
        if(c.getId() == obj.getId()){
            throw invalid_argument("Venda ja cadastrado no sistema!"); 
        }
    }

    objetos.push_back(obj);   
    Salvar(); 
}

vector<Venda> VendaDAO::Listar(){
    Abrir();
    return objetos;
}

Venda VendaDAO::Listar_Id(int id){
    Abrir();
    for(const Venda& c: objetos){
        if(c.getId() == id){
            return c; 
        }
    }

    throw invalid_argument("Cliente não encontrado!");
}

void VendaDAO::Atualizar(Venda obj){
    Abrir();
    for(Venda& c : objetos){
        
        if(c.getId() == obj.getId()){
            c = obj;
            return;
        }

    }

    throw invalid_argument("Venda não encontrado!");
}

void VendaDAO::Excluir(int id){
    Abrir();
    for(size_t i = 0; i < objetos.size(); i++){

        if(objetos[i].getId() == id){
            objetos.erase(objetos.begin() + i);
            return; 
        }
    }

    throw invalid_argument("Venda não encontrado!");
}

void VendaDAO::Abrir(){
    ifstream arquivo("venda.json");

    if(!arquivo.is_open()){
        objetos.clear();
        return;
}

json dados;
arquivo >> dados;
arquivo.close();

objetos.clear();

for(const auto& item: dados){
    objetos.push_back(Venda::from_json(item));
} 
}

void VendaDAO::Salvar(){
json dados = json::array();

for(const Venda& c: objetos){
  dados.push_back(c.to_json());
}

ofstream arquivo("venda.json");

if(!arquivo.is_open()){
    throw runtime_error("Não foi possivel salvar o arquivo");
}

arquivo << dados.dump(4);
arquivo.close();
}
