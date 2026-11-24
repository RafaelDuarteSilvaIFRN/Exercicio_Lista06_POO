#ifndef MENU_CATEGORIA_HPP
#define MENU_CATEGORIA_HPP

#include <iostream>
#include <string>

#include "../../service/ServiceCategoria/serviceCategoria.hpp"
using namespace std;

class MenuCategoria{

    public:

        int menuOpcoesCategoria();
        void categoria_Listar();
        void categoria_ListarId();
        void categoria_Inserir();
        void categoria_Atualizar();
        void categoria_Excluir();
};

#endif