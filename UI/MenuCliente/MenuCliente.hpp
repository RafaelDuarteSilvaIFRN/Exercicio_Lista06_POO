#ifndef MENU_CLIENTE_HPP
#define MENU_CLIENTE_HPP

#include <iostream>
#include <string>

#include "../../ClienteDAO/ClienteDAO.hpp"
using namespace std;

class MenuCliente{

    private:
        ClienteDAO clientedao;

    public:

        void abrirArquivo();
        int menuOpcoesCliente();
        void cliente_Listar();
        void cliente_ListarId();
        void cliente_Inserir();
        void cliente_Atualizar();
        void cliente_Excluir();
};

#endif