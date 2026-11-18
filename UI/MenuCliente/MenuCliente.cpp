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

void MenuCliente::abrirArquivo(){
     clientedao.Abrir();
}

void MenuCliente::cliente_Listar(){

    vector<Cliente> clientes = clientedao.Listar();
    
    if(clientes.empty()){
       cout << "Lista vazia!\n"; 
       return;
    }

    

    for(const Cliente& c: clientes){
            cout << c.ToString() << "\n\n";
    }
}

void MenuCliente::cliente_ListarId(){
    int id;

    cout << "Digite o Id do cliente: ";
    cin >> id;

    Cliente c = clientedao.Listar_Id(id);
    cout << "\nCliente encontrado\n";
    cout << c.ToString() << "\n";

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

    Cliente c(id, nome, email, fone);
    clientedao.Inserir(c);
    clientedao.Salvar();

    cout << "Cliente cadastrado com sucesso!\n";
}

void MenuCliente::cliente_Atualizar(){
    int id;
    string nome, email, fone;

    cout << "Atualiza o Id: ";
    cin >> id;
    cin.ignore();

    cout << "\nAtualiza o seu nome: ";
    getline(cin, nome);

    cout << "\nAtualiza o seu email: ";
    getline(cin, email);
    
    cout << "\nAtualiza o seu telefone: ";
    getline(cin, fone);

    Cliente c(id, nome, email, fone);

    clientedao.Atualizar(c);
    clientedao.Salvar();

    cout << "\nCliente atualizado com sucesso!\n";
}

void MenuCliente::cliente_Excluir(){

    int id;
    cout << "Digite o Id do cliente que deseja excluir: ";
    cin >> id;

    Cliente obj = clientedao.Listar_Id(id);
    clientedao.Excluir(obj.getId());
    clientedao.Salvar();

    cout << "Cliente excluido com sucesso!\n";
}