#ifndef CATEGORIADAO_HPP
#define CATEGORIADAO_HPP

#include <vector>
#include "../Categoria/Categoria.hpp"

class CategoriaDAO{
    
    private:
        
        vector<Categoria> objetos;

    public:

        void Inserir(Categoria obj);

        vector<Categoria> Listar();

        Categoria Listar_Id(int id);

        void Atualizar(Categoria obj);

        void Excluir(int id);

        void Abrir();

        void Salvar();
};

#endif