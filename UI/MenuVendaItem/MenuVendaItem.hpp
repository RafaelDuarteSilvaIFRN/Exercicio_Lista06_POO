#ifndef MENU_VENDAITEM_HPP
#define MENU_VENDAITEM_HPP

#include <iostream>
#include <string>

#include "../../models/VendaItemDAO/vendaItemDAO.hpp"
#include "../../models/VendaDAO/VendaDAO.hpp"
#include "../../models/ProdutoDAO/produtoDAO.hpp"
using namespace std;

class MenuVendaItem{

    private:
        VendaItemDAO vendaItemDAO;
        VendaDAO vendaDAO;
        ProdutoDAO produtoDAO;

    public: 
        void abrirArquivo();
        int menuVendaItemOpções();
        void vendaItem_Inserir();
        void vendaItem_Listar();
        void vendaItem_ListarId();
        void vendaItem_Atualizar();
        void vendaItem_Excluir();
};

#endif