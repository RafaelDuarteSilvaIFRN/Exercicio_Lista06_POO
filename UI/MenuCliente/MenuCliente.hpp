#ifndef MENU_CLIENTE_HPP
#define MENU_CLIENTE_HPP

#include <iostream>
#include <string>

#include "../../service/ServiceCliente/serviceCliente.hpp"
using namespace std;

class MenuCliente{
    public:
    
        int menuOpcoesCliente();
        void cliente_Listar();
        void cliente_ListarId();
        void cliente_Inserir();
        void cliente_Atualizar();
        void cliente_Excluir();
};

#endif