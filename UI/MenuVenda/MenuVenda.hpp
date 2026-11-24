#ifndef MENU_VENDAS_HPP
#define MENU_VENDAS_HPP

#include <iostream>
#include <string>

#include "../../service/ServiceVenda/serviceVenda.hpp"

using namespace std;

class MenuVenda{

    public: 
        void abrirArquivo();
        int menuVendaOpções();
        void venda_Inserir();
        void venda_Listar();
        void venda_ListarId();
        void venda_Atualizar();
        void venda_Excluir();
};

#endif