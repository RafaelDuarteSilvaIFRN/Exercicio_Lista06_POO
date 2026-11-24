#include <stdexcept>

#include "Venda.hpp"

Venda::Venda(int id){
    setId(id);
    this -> carrinho = false;
    this -> total = 0.0;
    this -> id_cliente = 0;
    this -> data = chrono::system_clock::now();
}

void Venda::setId(int id){
        if(id > 0){
          this -> id = id;
        } else{
           throw invalid_argument("Id invalido!");  
        }
}

int Venda::getId() const{
    return id;
}

void Venda::setCarrinho(bool carrinho){
     this -> carrinho = carrinho;
}

bool Venda::getCarrinho()const{
    return carrinho;
}

void Venda::setTotal(double total){

    if(total >= 0.0){
        this -> total = total;
    } else{
        throw invalid_argument("Preço invalido!");
    }

}

double Venda::getTotal() const{
    return total;
}

void Venda::setIdCliente(int id_cliente){
        if(id_cliente > 0){
          this -> id_cliente = id_cliente;
        } else{
           throw invalid_argument("Id de cliente invalido!");  
        }
}

int Venda::getIdCliente() const{
    return id_cliente;
}

string Venda::ToString() const{

    auto time_data = chrono::system_clock::to_time_t(data);

    ostringstream vendaString;
    vendaString << "Venda id: " << id << "\n"
        << "Id do cliente: " << id_cliente << "\n"
        << "Data: " << time_data << "\n"
        << "Total: R$ " << fixed << setprecision(2) << total << "\n";

    return vendaString.str();

}

json Venda::to_json() const {

    json dados_vendas;

    dados_vendas["id"] = id;
    dados_vendas["carrinho"] = carrinho;
    dados_vendas["total"] = total;
    dados_vendas["id_cliente"] = id_cliente;

    auto time = chrono::system_clock::to_time_t(data);
    dados_vendas["data"] = static_cast<long long>(time);

    return dados_vendas;
}

Venda Venda::from_json(json dic){

    int id = dic.at("id").get<int>();
    Venda v(id);
    
    if (dic.contains("carrinho")) v.carrinho = dic.at("carrinho").get<bool>();
    if (dic.contains("total")) v.total = dic.at("total").get<double>();
    if (dic.contains("id_cliente")) v.id_cliente = dic.at("id_cliente").get<int>();

    if(dic.contains("data")){
        long long time = dic.at("data").get<long long>();
        v.data = chrono::system_clock::from_time_t(time);
    }

    return v;
}