#ifndef UI_HPP 
#define UI_HPP 

#include "../ClienteDAO/ClienteDAO.hpp"
#include "../VendaDAO/VendaDAO.hpp"

class UI{

    private:
        ClienteDAO clientedao;
        VendaDAO vendadao;

    public:

        int Menu();
        void Main();
};

#endif