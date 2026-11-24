#include <stdexcept>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include "ClienteDAO.hpp"

using json = nlohmann::json;

void ClienteDAO::Inserir(Cliente obj){
    Abrir();

    for(const Cliente& c: objetos){
        if(c.getId() == obj.getId()){
            throw invalid_argument("Cliente ja cadastrado no sistema!"); 
        }
    }

    objetos.push_back(obj);
    Salvar();   
}

vector<Cliente> ClienteDAO::Listar(){
    Abrir();
    return objetos;
}

Cliente ClienteDAO::Listar_Id(int id){
    Abrir();
    for(const Cliente& c: objetos){
        if(c.getId() == id){
            return c; 
        }
    }

    throw invalid_argument("Cliente não encontrado!");
}

void ClienteDAO::Atualizar(Cliente obj){
    Abrir();
    for(Cliente& c : objetos){
        
        if(c.getId() == obj.getId()){
            c = obj;
            return;
        }

    }

    throw invalid_argument("Cliente não encontrado!");
}

void ClienteDAO::Excluir(int id){
    Abrir();
    for(size_t i = 0; i < objetos.size(); i++){

        if(objetos[i].getId() == id){
            objetos.erase(objetos.begin() + i);
            return; 
        }
    }

    throw invalid_argument("Cliente não encontrado!");
}

void ClienteDAO::Abrir(){
        ifstream arquivo("clientes.json");

        if(!arquivo.is_open()){
            objetos.clear();
            return;
    }

    json dados;
    arquivo >> dados;
    arquivo.close();
    objetos.clear();

    for(const auto& item: dados){
        objetos.push_back(Cliente::from_json(item));
    } 
}

void ClienteDAO::Salvar(){
json dados = json::array();

for(const Cliente& c: objetos){
  dados.push_back(c.to_json());
}

ofstream arquivo("clientes.json");

if(!arquivo.is_open()){
    throw runtime_error("Não foi possivel salvar o arquivo");
}

arquivo << dados.dump(4);
arquivo.close();
}
