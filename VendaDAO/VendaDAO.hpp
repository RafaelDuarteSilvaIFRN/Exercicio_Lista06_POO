#ifndef VENDADAO_HPP
#define VENDADAO_HPP

#include <vector>
#include "../Venda/Venda.hpp"

class VendaDAO{
    
    private:
        
        vector<Venda> objetos;

    public:

        void Inserir(Venda obj);

        vector<Venda> Listar();

        Venda Listar_Id(int id);

        void Atualizar(Venda obj);

        void Excluir(int id);

        void Abrir();

        void Salvar();
};

#endif