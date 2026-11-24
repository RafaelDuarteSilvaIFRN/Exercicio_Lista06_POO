#ifndef CATEGORIA_HPP
#define CATEGORIA_HPP

#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class Categoria{
    
    private:
        int id;
        string descricao;

    public:
        Categoria(int id, string d);
        
        void setId(int id);
        int getId() const;
        
        void setDescricao(string descricao);
        string getDescricao() const;

        void setIdCategoria(int id_categoria);
        int getIdCategoria() const;

        string ToString() const;
        json to_json() const;
        static Categoria from_json(json dic);
};

#endif