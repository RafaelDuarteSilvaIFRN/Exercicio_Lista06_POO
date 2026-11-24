#ifndef UI_HPP 
#define UI_HPP 

#include "../models/ClienteDAO/ClienteDAO.hpp"
#include "../models/VendaDAO/VendaDAO.hpp"
#include "../models/ProdutoDAO/produtoDAO.hpp"
#include "../models/VendaItemDAO/vendaItemDAO.hpp"
class UI{

    private:
        ClienteDAO clientedao;
        VendaDAO vendadao;
        ProdutoDAO produtoDAO;
        VendaItemDAO vendaItemDAO;

    public:

        int Menu();
        void Main();
};

#endif