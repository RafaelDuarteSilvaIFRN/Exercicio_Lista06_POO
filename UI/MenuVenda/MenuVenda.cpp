#include "MenuVenda.hpp"
#include "../../Cliente/Cliente.hpp"

using namespace std;

int MenuVenda::menuVendaOpções(){

    cout << "\nMenu de vendas\n";
    cout << "1 - Inserir vendas\n";
    cout << "2 - Listar vendas\n";
    cout << "3 - Atualizar vendas\n";
    cout << "4 - Excluir vendas\n";
    cout << "0 - Voltar para o menu principal\n";
    cout << "Escolha uma opcao: ";

    int opcao;
    cin >> opcao;

    return opcao;
}

void MenuVenda::abrirArquivo(){
     vendadao.Abrir();
}

void MenuVenda::venda_Inserir(){
     int id, id_cliente;

    cout << "Digite o Id da Venda: ";
    cin >> id;

    cout << "Digite o Id do cliente da venda: ";
    cin >> id_cliente;

    try{

        clientedao.Abrir();
        clientedao.Listar_Id(id_cliente);

        Venda v(id);

        v.setIdCliente(id_cliente);
        vendadao.Inserir(v);
        vendadao.Salvar();

        cout << "Venda cadastrado com sucesso!\n";
    } catch(const exception& e){
        cout << "Error ao cadastrar venda: " << e.what() << endl;
    }
}

void MenuVenda::venda_Listar(){
       vector<Venda> vendas = vendadao.Listar();

    if(vendas.empty()){
        cout << "Nenhuma venda cadastrada!\n";
        return;
    }   

    for(const Venda& v: vendas){
        string nomeCliente = "Cliente não encontrado!";

        try{

            Cliente c = clientedao.Listar_Id(v.getIdCliente());
            nomeCliente = c.getNome();

        } catch(const exception& e){
           cout << "Cliente não encontrado! " << e.what() << endl;
        }
        
        cout << "\nVenda id: " << v.getId() << "\n";
        cout << "Cliente: " << nomeCliente << "\n";
        cout << "Id do cliente: " << v.getIdCliente() << "\n";
        cout << "Total: R$ " << v.getTotal() << "\n";
    
    }
}

void MenuVenda::venda_Atualizar(){
    int id, id_cliente;
    double total;

    cout << "Informe o Id da venda: ";
    cin >> id;

    cout << "\nAtualiza o Id do Cliente: ";
    cin >> id_cliente;
    
    cout << "\nAtualiza o preço: ";
    cin >> total;

    Venda v(id);

    v.setIdCliente(id_cliente);
    v.setTotal(total);

    vendadao.Atualizar(v);
    vendadao.Salvar();

    cout << "\nVenda atualizado com sucesso!\n";
}


void MenuVenda::venda_Excluir(){
    int id;
    cout << "Digite o Id da venda que deseja excluir: ";
    cin >> id;

    Venda obj = vendadao.Listar_Id(id);
    vendadao.Excluir(obj.getId());
    vendadao.Salvar();

    cout << "Venda excluido com sucesso!\n";
}