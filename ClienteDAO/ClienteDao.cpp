#include <stdexcept>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include "ClienteDAO.hpp"

using json = nlohmann::json;

void ClienteDAO::Inserir(Cliente obj){
    objetos.push_back(obj);   
}

vector<Cliente> ClienteDAO::Listar(){
    return objetos;
}

Cliente ClienteDAO::Listar_Id(int id){
    for(const Cliente& c: objetos){
        if(c.getId() == id){
            return c; 
        }
    }

    throw invalid_argument("Cliente não encontrado!");
}

void ClienteDAO::Atualizar(Cliente obj){
    for(Cliente& c : objetos){
        
        if(c.getId() == obj.getId()){
            c = obj;
            return;
        }

    }

    throw invalid_argument("Cliente não encontrado!");
}

void ClienteDAO::Excluir(int id){
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

        if(!arquivo.is_open() || arquivo.peek == ifstream::traits_type::eof()){
            objetos.clear();
            arquivo.close();
            return;
    }

    json j;
    arquivo >> j;

    json dados = json::parse(arquivo);
    objetos.clear();

    for(const auto& item: dados){
        objetos.push_back(Cliente::from_json(item));
    } 

    arquivo.close();
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
}
