#ifndef MENU_CATEGORIA_HPP
#define MENU_CATEGORIA_HPP

#include <iostream>
#include <string>

#include "../../CategoriaDAO/CategoriaDAO.hpp"
using namespace std;

class MenuCategoria{

    private:
        CategoriaDAO categoriadao;

    public:

        void abrirArquivo();
        int menuOpcoesCategoria();
        void categoria_Listar();
        void categoria_ListarId();
        void categoria_Inserir();
        void categoria_Atualizar();
        void categoria_Excluir();
};

#endif