#ifndef SERVICE_CATEGORIA_HPP
#define SERVICE_CATEGORIA_HPP

#include <vector>
#include "../../models/Categoria/Categoria.hpp"
#include "../../models/CategoriaDAO/CategoriaDAO.hpp"

using namespace std;

class ServiceCategoria{

    private:
        static CategoriaDAO categoriaDAO;

    public:
        static void categoria_inserir(int id, const string& descricao);
        static vector<Categoria> categoria_listar();
        static Categoria categoria_listar_id(int id);
        static void categoria_atualizar(int id, const string& descricao);
        static void categoria_excluir(int id);
};

#endif