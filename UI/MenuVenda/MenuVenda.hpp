#ifndef MENU_VENDAS_HPP
#define MENU_VENDAS_HPP

#include <iostream>
#include <string>

#include "../../VendaDAO/VendaDAO.hpp"
#include "../../ClienteDAO/ClienteDAO.hpp"
using namespace std;

class MenuVenda{

    private:
        ClienteDAO clientedao;
        VendaDAO vendadao;

    public: 
        void abrirArquivo();
        int menuVendaOpções();
        void venda_Inserir();
        void venda_Listar();
        void venda_Atualizar();
        void venda_Excluir();
};

#endif