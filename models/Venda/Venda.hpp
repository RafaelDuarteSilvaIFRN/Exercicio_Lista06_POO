#ifndef VENDA_HPP
#define VENDA_HPP

#include <chrono>
#include <format>
#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class Venda{

    private:
        int id;
        bool carrinho;
        double total;
        chrono::system_clock::time_point data = chrono::system_clock::now();
        int id_cliente;

    public:

        Venda(int id);
        void setId(int id);
        int getId() const;

        void setTotal(double total);
        double getTotal() const;

        void setCarrinho(bool total);
        bool getCarrinho() const;

        void setIdCliente(int id_cliente);
        int getIdCliente() const;

        string ToString() const;
        json to_json() const;
        static Venda from_json(json dic);
};

#endif