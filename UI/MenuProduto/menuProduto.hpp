#ifndef MENU_PRODUTO_HPP
#define MENU_PRODUTO_HPP

#include <iostream>
#include <string>

#include "../../service/ServiceProduto/serviceProduto.hpp"
using namespace std;

class MenuProduto{
    public:

        void abrirArquivo();
        int menuOpcoesProduto();
        void produto_Listar();
        void produto_ListarId();
        void produto_Inserir();
        void produto_Atualizar();
        void produto_Excluir();
};

#endif