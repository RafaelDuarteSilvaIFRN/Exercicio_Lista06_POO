#include "MenuVenda.hpp"
#include "../../models/Cliente/Cliente.hpp"
#include "../../service/ServiceCliente/serviceCliente.hpp"

using namespace std;

int MenuVenda::menuVendaOpções(){

    cout << "\nMenu de vendas\n";
    cout << "1 - Inserir vendas\n";
    cout << "2 - Listar vendas\n";
    cout << "3 - buscar venda por id\n";
    cout << "4 - Atualizar vendas\n";
    cout << "5 - Excluir vendas\n";
    cout << "0 - Voltar para o menu principal\n";
    cout << "Escolha uma opcao: ";

    int opcao;
    cin >> opcao;

    return opcao;
}

void MenuVenda::venda_Inserir(){
     int id, id_cliente;

    cout << "Digite o Id da Venda: ";
    cin >> id;
    cin.ignore();

    cout << "Digite o Id do cliente da venda: ";
    cin >> id_cliente;
    cin.ignore();

    try{
        ServiceVenda::venda_inserir(id, id_cliente);
        cout << "Venda cadastrado com sucesso!\n";
    } catch(const exception& e){
        cout << "Error ao cadastrar venda: " << e.what() << endl;
    }
}

void MenuVenda::venda_Listar(){
    try{

        vector<Venda> vendas = ServiceVenda::venda_Listar();
        
        if(vendas.empty()){
           cout << "Lista de vendas vazia!\n"; 
           return;
        }

        for(const Venda& v: vendas){
            cout << v.ToString() << "\n";

            try{
                Cliente c = ServiceCliente::cliente_listar_id(v.getIdCliente());
                cout << "Cliente: " << c.getNome() << endl;

            }catch(const exception& e){
                cout << "Cliente não encontrado! " << e.what() << endl;
            }

        } 

    } catch(const exception& e){
        cout << "Erro ao listar Vendas: " << e.what() << endl;  
    }
}

void MenuVenda::venda_ListarId(){

    int id;

    cout << "Digite o Id da venda: ";
    cin >> id;

    try{
        Venda c = ServiceVenda::venda_listar_id(id);
        cout << "\nVenda encontrada\n";
        cout << c.ToString() << "\n";
    } catch(const exception& e){
        cout << "Erro ao buscar Venda: " << e.what() << endl;
    }
}

void MenuVenda::venda_Atualizar(){
    int id, id_cliente, escolher_item;
    double total;

    cout << "Informe o Id da venda: ";
    cin >> id;
    cin.ignore();

    try {
        Venda v = ServiceVenda::venda_listar_id(id);
        id_cliente = v.getIdCliente();
        total = v.getTotal();

        cout << "Selecione qual item vc deseja atualizar:\n";
        cout << "[1] Id do Cliente  [2] Total\n";

        cin >> escolher_item;
        cin.ignore();

        switch (escolher_item) {
            case 1: {
                cout << "\nAtualiza o Id do Cliente: ";
                cin >> id_cliente;
                cin.ignore();
                break;
            }
            case 2: {
                cout << "\nAtualiza o preço/total: ";
                cin >> total;
                cin.ignore();
                break;
            }
            default: {
                cout << "Opção invalida!\n";
                return;
            }
        }

           ServiceVenda::venda_atualizar(id, id_cliente, total);
           cout << "Venda atualizada com sucesso!\n";
    } catch (const exception& e) {
        cout << "Erro ao atualizar venda: " << e.what() << endl;
    }
}


void MenuVenda::venda_Excluir(){
    int id;
    cout << "Digite o Id da venda que deseja excluir: ";
    cin >> id;
    cin.ignore();

    try{
        ServiceVenda::venda_excluir(id);
        cout << "Venda excluida com sucesso!\n";
    } catch(const exception& e){
        cout << "Erro ao excluir venda: " << e.what() << endl;
    }
}