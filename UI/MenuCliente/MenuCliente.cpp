#include "MenuCliente.hpp"
using namespace std;

int MenuCliente::menuOpcoesCliente(){

    cout << "\nMenu de clientes\n";
    cout << "1 - Inserir\n";
    cout << "2 - Listar\n";
    cout << "3 - Buscar por ID\n";
    cout << "4 - Atualizar\n";
    cout << "5 - Excluir\n";
    cout << "0 - Voltar para o menu principal\n";
    cout << "Escolha uma opcao: ";

    int opcao;
    cin >> opcao;

    return opcao;
}

void MenuCliente::cliente_Listar(){

    try{
        vector<Cliente> clientes = ServiceCliente::cliente_listar();
        
        if(clientes.empty()){
        cout << "Lista vazia!\n"; 
        return;
        }

        for(const Cliente& c: clientes){
                cout << c.ToString() << "\n\n";
        }
    } catch(const exception& e){
        cout << "Erro ao listar clientes: " << e.what() << endl;
    }
}

void MenuCliente::cliente_ListarId(){
    int id;

    cout << "Digite o Id do cliente: ";
    cin >> id;

    try{
        Cliente c = ServiceCliente::cliente_listar_id(id);
        cout << "\nCliente encontrado!\n";
        cout << c.ToString() << endl;
    } catch(const exception& e){
        cout << "Erro ao buscar cliente: " << e.what() << endl;
    }

}

void MenuCliente::cliente_Inserir(){
    int id;
    string nome, email, fone;

    cout << "Digite o Id: ";
    cin >> id;
    cin.ignore();

    cout << "\nDigite o nome: ";
    getline(cin, nome);

    cout << "\nDigite o email: ";
    getline(cin, email);

    cout << "\nDigite o telefone: ";
    getline(cin, fone);

    try{
        ServiceCliente::cliente_inserir(id, nome, email, fone);
        cout << "Cliente cadastrado com sucesso!\n";
    } catch(const exception& e){
        cout << "Erro ao cadastrar cliente: " << e.what() << endl;
    }
}

void MenuCliente::cliente_Atualizar(){
    int id, escolher_item;
    string nome, email, fone;

    cout << "Informe o Id do cliente: ";
    cin >> id;
    cin.ignore();

    try{
        Cliente c = ServiceCliente::cliente_listar_id(id);
        nome = c.getNome();
        email = c.getEmail();
        fone = c.getFone();

        cout << "Selecione qual item vc deseja atualizar:\n";
        cout << "[1] Nome  [2] Email  [3] Telefone\n";
        cin >> escolher_item;
        switch(escolher_item){

            case 1 : {
                    cout << "\nInforme o nome que vc deseja atualizar: ";
                    cin.ignore();
                    getline(cin, nome);
                    break;
                }
                
                case 2: {
                    cout << "Informe o email que vc deseja atualizar: ";
                    cin.ignore();
                    getline(cin, email);
                    break;
            }

            case 3: {
                cout << "\nInforme o telefone que vc deseja atualizar: ";
                cin.ignore();
                getline(cin, fone);
                break;
            }

            default :{
                cout << "Opção invalida!\n";
                return;
            }

        }

        ServiceCliente::cliente_atualizar(id, nome, email, fone);
        cout << "\nCliente atualizado com sucesso!\n";
    } catch(const exception& e){
        cout << "Erro ao atualizar cliente: " << e.what() << endl;
    }
}

void MenuCliente::cliente_Excluir(){

    int id;
    cout << "Digite o Id do cliente que deseja excluir: ";
    cin >> id;
    cin.ignore();
    
    try{
        ServiceCliente::cliente_excluir(id);
        cout << "Cliente excluido com sucesso!\n";
    } catch(const exception& e){
        cout << "Erro ao excluir cliente: " << e.what() << endl;
    }

}