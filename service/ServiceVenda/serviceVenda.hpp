#ifndef SERVICE_VENDA_HPP
#define SERVICE_VENDA_HPP

#include <vector>
#include "../../models/Venda/Venda.hpp"
#include "../../models/VendaDAO/VendaDAO.hpp"
#include "../../models/ClienteDAO/ClienteDAO.hpp"
#

using namespace std;

class ServiceVenda{

    private:
        static VendaDAO vendadao;
        static ClienteDAO clienteDAO;
    public:

        static void venda_inserir(int id, int id_cliente);
        static vector<Venda> venda_Listar();
        static Venda venda_listar_id(int id);
        static void venda_atualizar(int id, int id_cliente, double total);
        static void venda_excluir(int id);

};

#endif