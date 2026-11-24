#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <nlohmann/json.hpp>
using namespace std;

using json = nlohmann::json;
class Cliente{

    private: 
        int id;
        string nome;
        string email;
        string fone;

    public:
        Cliente(int id, string n, string e, string f);
        void setId(int id);
        int getId() const;
        void setNome(string nome);
        string getNome() const;
        void setEmail(string email);
        string getEmail() const;
        void setFone(string fone);
        string getFone() const;
        string ToString() const;
        json to_json() const;
        static Cliente from_json(json dic);
};

#endif