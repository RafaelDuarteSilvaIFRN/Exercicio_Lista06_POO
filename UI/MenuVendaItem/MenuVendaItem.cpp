#include "MenuVendaItem.hpp"
#include "../../models/Venda/Venda.hpp"
#include "../../models/Produto/produto.hpp"
#include <iomanip>
using namespace std;

int MenuVendaItem::menuVendaItemOpções(){

    cout << "\nMenu de itens de vendas\n";
    cout << "1 - Inserir item de vendas\n";
    cout << "2 - Listar item de vendas\n";
    cout << "3 - Buscar id de item de venda\n";
    cout << "4 - Atualizar item de venda\n";
    cout << "5 - Excluir id de item de venda\n";
    cout << "0 - Voltar para o menu principal\n";
    cout << "Escolha uma opcao: ";

    int opcao;
    cin >> opcao;

    return opcao;
}

void MenuVendaItem::abrirArquivo(){
     vendaItemDAO.Abrir();
}

void MenuVendaItem::vendaItem_Inserir(){
    int id, id_venda, id_produto, qtd;

    cout << "Digite o Id: ";
    cin >> id;
    cin.ignore();

    cout << "Digite o id da venda: ";
    cin >> id_venda;
    cin.ignore();

    cout << "\nDigite o id do produto: ";
    cin >> id_produto;
    cin.ignore();

    cout << "\nDigite a quantidade: ";
    cin >> qtd;
    cin.ignore();

    try{

        vendaDAO.Abrir();
        vendaDAO.Listar_Id(id_venda);

        produtoDAO.Abrir();
        Produto p = produtoDAO.Listar_Id(id_produto);

        if(qtd > p.getEstoque()){
           throw invalid_argument("Estoque insuficiente!"); 
        }

        VendaItem item(id, qtd, p.getPreco());
        item.setIdVenda(id_venda);
        item.setIdProduto(id_produto);
        
        vendaItemDAO.Inserir(item);
        vendaItemDAO.Salvar();

        cout << "Item de venda cadastrado com sucesso!\n";
    } catch(const exception& e){
        cout << "Erro ao cadastrar item de venda: " << e.what() << endl;
    }
}

void MenuVendaItem::vendaItem_Listar(){
       vector<VendaItem> item_vendas = vendaItemDAO.Listar();
       produtoDAO.Abrir(); 
       if(item_vendas.empty()){
           cout << "Nenhum item de venda cadastrado!\n";
           return;
        }   
        
        for(const VendaItem& item: item_vendas){
        string descricaoProd = "Produto não encontrado!";

        try{

            Produto p = produtoDAO.Listar_Id(item.getIdProduto());
            descricaoProd = p.getDescricao();

        } catch(const exception& e){
           cout << "Aviso: " << e.what() << endl;
        }

        double subtotal = item.getQuantidade() * item.getPreco();
        
        cout << "\nitem de Venda id: " << item.getId() << "\n";
        cout << "Venda Id: " << item.getIdVenda() << "\n";
        cout << "Produto: " << descricaoProd << " (ID: " << item.getIdProduto() << ")\n";
        cout << "Quantidade: " << item.getQuantidade() << "\n";
        cout << "Preço unitario: R$ " << fixed << std::setprecision(2) << item.getPreco() << "\n";
        cout << "Subtotal: R$ " << fixed << std::setprecision(2) << subtotal << "\n";
    
    }
}

void MenuVendaItem::vendaItem_ListarId(){

    int id;
    cout << "Informe o id do item de venda que deseja encontrar: ";
    cin >> id;

    try{
        vendaItemDAO.Abrir();
        VendaItem item = vendaItemDAO.Listar_Id(id);
        
        cout << "\nItem de venda encontrado!\n";
        cout << item.ToString() << "\n";
    } catch(const exception& e) {
        cout << "Erro ao Buscar item de venda: " << e.what() << endl;
    }
}

void MenuVendaItem::vendaItem_Atualizar(){
     int id, id_venda, id_produto, qtd, escolher_item;

    cout << "informe o Id: ";
    cin >> id;
    cin.ignore();

    try{
        vendaItemDAO.Abrir();
        VendaItem item = vendaItemDAO.Listar_Id(id);

        cout << "Selecione qual item vc deseja atualizar:\n";
        cout << "[1] id da venda  [2] id do produto  [3] Quantidade\n";
        cin >> escolher_item;
        switch(escolher_item){

            case 1 : {
                    cout << "\nInforme o novo valor de id da venda que vc deseja atualizar: ";
                    cin >> id_venda;
                    vendaDAO.Abrir();
                    vendaDAO.Listar_Id(id_venda);
                    item.setIdVenda(id_venda);
                    break;
            }

            case 2: {
                cout << "Informe o novo valor de id do produto que vc deseja atualizar: ";
                cin >> id_produto;

                produtoDAO.Abrir();
                Produto p = produtoDAO.Listar_Id(id_produto);

                if(item.getQuantidade() > p.getEstoque()){
                    throw invalid_argument("Estoque insuficiente!\n");
                }

                item.setIdProduto(id_produto);
                item.setPreco(p.getPreco());
                break;
            }

            case 3: {
                cout << "\nInforme a nova quantidade que vc deseja atualizar: ";
                cin >> qtd;

                produtoDAO.Abrir();
                
                Produto p = produtoDAO.Listar_Id(item.getIdProduto());

                if(qtd > p.getEstoque()){
                    throw invalid_argument("Estoque insuficiente!\n");
                }

                item.setQuantidade(qtd);
                break;
            }

            default :{
                cout << "Opção invalida!\n";
                return;
            }

        }
        
        vendaItemDAO.Atualizar(item);
        vendaItemDAO.Salvar();

        cout << "\nItem de venda atualizado com sucesso!\n";
    } catch(const exception& e){
        cout << "Erro ao atualizar item de venda: " << e.what() << endl;
    }
}


void MenuVendaItem::vendaItem_Excluir(){
    int id;
    cout << "Digite o Id que deseja excluir: ";
    cin >> id;
    cin.ignore();
    
    try{
        vendaItemDAO.Abrir();
        VendaItem obj = vendaItemDAO.Listar_Id(id);
        vendaItemDAO.Excluir(obj.getId());
        vendaItemDAO.Salvar();

        cout << "item de Venda excluido com sucesso!\n";
    } catch(const exception& e){
        cout << "Erro ao excluir item de venda: " << e.what() << endl;
    }   
}