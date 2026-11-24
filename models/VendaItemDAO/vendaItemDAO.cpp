#include <stdexcept>
#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>
#include "VendaItemDAO.hpp"

using json = nlohmann::json;

void VendaItemDAO::Inserir(VendaItem obj){
    Abrir();

    for(const VendaItem& c: objetos){
        if(c.getId() == obj.getId()){
            throw invalid_argument("item de venda ja cadastrado no sistema!"); 
        }
    }

    objetos.push_back(obj);   
    Salvar(); 
}

vector<VendaItem> VendaItemDAO::Listar(){
    Abrir();
    return objetos;
}

VendaItem VendaItemDAO::Listar_Id(int id){
    Abrir();
    for(const VendaItem& c: objetos){
        if(c.getId() == id){
            return c; 
        }
    }

    throw invalid_argument("Item de venda não encontrado!");
}

void VendaItemDAO::Atualizar(VendaItem obj){
    Abrir();
    for(VendaItem& c : objetos){
        
        if(c.getId() == obj.getId()){
            c = obj;
            Salvar();
            return;
        }

    }

    throw invalid_argument("VendaItem não encontrado!");
}

void VendaItemDAO::Excluir(int id){
    Abrir();
    for(size_t i = 0; i < objetos.size(); i++){

        if(objetos[i].getId() == id){
            objetos.erase(objetos.begin() + i);
            Salvar();
            return; 
        }
    }

    throw invalid_argument("VendaItem não encontrado!");
}

void VendaItemDAO::Abrir(){
    ifstream arquivo("vendaItem.json");

    if(!arquivo.is_open()){
        objetos.clear();
        return;
}

json dados;
arquivo >> dados;
arquivo.close();

objetos.clear();

for(const auto& item: dados){
    objetos.push_back(VendaItem::from_json(item));
} 
}

void VendaItemDAO::Salvar(){
json dados = json::array();

for(const VendaItem& c: objetos){
  dados.push_back(c.to_json());
}

ofstream arquivo("vendaItem.json");

if(!arquivo.is_open()){
    throw runtime_error("Não foi possivel salvar o arquivo");
}

arquivo << dados.dump(4);
arquivo.close();
}
