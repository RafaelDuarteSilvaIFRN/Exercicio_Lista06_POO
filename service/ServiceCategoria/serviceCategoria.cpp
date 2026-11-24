#include "serviceCategoria.hpp"
#include <stdexcept>

using namespace std;

CategoriaDAO ServiceCategoria::categoriaDAO;

void ServiceCategoria::categoria_inserir(int id, const string& descricao){

    if(descricao.empty()){
        throw invalid_argument("A descrição não pode estar vazia!");
    }

    categoriaDAO.Abrir();
    Categoria c(id, descricao);
    categoriaDAO.Inserir(c);
    categoriaDAO.Salvar();
}

vector<Categoria> ServiceCategoria::categoria_listar(){
    categoriaDAO.Abrir();
    return categoriaDAO.Listar();
}

Categoria ServiceCategoria::categoria_listar_id(int id){
    categoriaDAO.Abrir();
    return categoriaDAO.Listar_Id(id);
}

void ServiceCategoria::categoria_atualizar(int id, const string& descricao){

    if(descricao.empty()){
        throw invalid_argument("A descrição não pode estar vazia!");
    }

    categoriaDAO.Abrir();
    Categoria c = categoriaDAO.Listar_Id(id);
    c.setDescricao(descricao);

    categoriaDAO.Atualizar(c);
    categoriaDAO.Salvar();
}

void ServiceCategoria::categoria_excluir(int id){

    if(id <= 0){
        throw invalid_argument("Id de categoria invalido!");
    }

    categoriaDAO.Abrir();
    Categoria c = categoriaDAO.Listar_Id(id);
    categoriaDAO.Excluir(c.getId());
    categoriaDAO.Salvar();
    
}