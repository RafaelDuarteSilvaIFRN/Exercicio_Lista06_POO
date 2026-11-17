#ifndef CLIENTEDAO_HPP
#define CLIENTEDAO_HPP

#include <vector>
#include "../Cliente/Cliente.hpp"

class ClienteDAO{
    
    private:
        
        vector<Cliente> objetos;

    public:

        void Inserir(Cliente obj);

        vector<Cliente> Listar();

        Cliente Listar_Id(int id);

        void Atualizar(Cliente obj);

        void Excluir(int id);

        void Abrir();

        void Salvar();
};

#endif