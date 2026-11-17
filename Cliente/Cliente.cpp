#include <stdexcept>
#include "Cliente.hpp"

Cliente::Cliente(int id, string n, string e, string f){
    setId(id);
    setNome(n);
    setEmail(e);
    setFone(f);
}

void Cliente::setId(int id){
        if(id > 0){
          this -> id = id;
        } else{
           throw invalid_argument("Id invalido!");  
        }
}

int Cliente::getId() const{
    return id;
}

void Cliente::setNome(string nome){
    if(!nome.empty()){
        this -> nome = nome;
    } else{
        throw invalid_argument("Nome vazio!");  
    }
}

string Cliente::getNome() const{
    return nome;
}

void Cliente::setEmail(string email){
    if(!email.empty()){
        this -> email = email;
    } else{
        throw invalid_argument("Email vazio!");  
    }
}

string Cliente::getEmail() const{
    return email;
}

void Cliente::setFone(string fone){
    if(!fone.empty()){
        this -> fone = fone;
    } else{
        throw invalid_argument("Fone vazio!");  
    }
}

string Cliente::getFone() const{
    return fone;
}

string Cliente::ToString() const{

    return "Id: " + to_string(id) + "\nNome: " + nome +
            "\nEmail: " + email + "\nFone: " + fone;

}

json Cliente::to_json() const {

    json dados;

    dados["id"] = id;
    dados["nome"] = nome;
    dados["email"] = email;
    dados["fone"] = fone;

    return dados;
}

Cliente Cliente::from_json(json dic){

    int id = dic.at("id").get<int>();
    string nome = dic.at("nome").get<string>();
    string email = dic.at("email").get<string>();
    string fone = dic.at("fone").get<string>();
    
    return Cliente(id, nome, email, fone);
    
}