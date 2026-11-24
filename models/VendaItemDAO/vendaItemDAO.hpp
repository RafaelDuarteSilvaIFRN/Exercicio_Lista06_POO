#ifndef VENDAITEMDAO_HPP
#define VENDAITEMDAO_HPP

#include <vector>
#include "../VendaItem/VendaItem.hpp"

class VendaItemDAO{
    
    private:
        
        vector<VendaItem> objetos;

    public:

        void Inserir(VendaItem obj);

        vector<VendaItem> Listar();

        VendaItem Listar_Id(int id);

        void Atualizar(VendaItem obj);

        void Excluir(int id);

        void Abrir();

        void Salvar();
};

#endif