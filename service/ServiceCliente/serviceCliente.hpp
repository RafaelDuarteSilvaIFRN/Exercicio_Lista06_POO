#ifndef SERVICE_CLIENTE_HPP
#define SERVICE_CLIENTE_HPP

#include "../../models/Cliente/Cliente.hpp"
#include "../../models/ClienteDAO/ClienteDao.hpp"

using namespace std;

class ServiceCliente{

    private:
        static ClienteDAO clienteDAO;

    public:

        static void cliente_inserir(int id, const string& nome, const string& email, const string& fone);
        static vector<Cliente> cliente_listar();
        static Cliente cliente_listar_id(int id);
        static void cliente_atualizar(int id, const string& nome, const string& email, const string& fone);
        static void cliente_excluir(int id);

};

#endif