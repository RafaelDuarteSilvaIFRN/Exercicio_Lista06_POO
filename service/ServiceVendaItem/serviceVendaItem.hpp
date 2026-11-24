#ifndef SERVICE_VENDAITEM_HPP
#define SERVICE_VENDAITEM_HPP

#include <vector>
#include "../../models/VendaItem/vendaItem.hpp"
#include "../../models/VendaItemDAO/VendaItemDAO.hpp"
#include "../../models/ProdutoDAO/produtoDAO.hpp"
#include "../../models/VendaDAO/VendaDAO.hpp"

using namespace std;

class ServiceVendaItem{

    private:
        static VendaItemDAO vendaItemDAO;
        static ProdutoDAO produtoDAO;
        static VendaDAO vendaDAO;
    public:

        static void vendaItem_inserir(int id, int id_venda, int id_produto, int qtd);
        static vector<VendaItem> vendaItem_listar();
        static VendaItem vendaItem_listar_id(int id);
        static void vendaItem_atualizar(int id, int id_venda, int id_produto, int qtd);
        static void vendaItem_excluir(int id);

};

#endif