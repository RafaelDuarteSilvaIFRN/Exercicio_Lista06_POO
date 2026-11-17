#include <iostream>
#include "UI.hpp"
#include "MenuCliente/MenuCliente.hpp"
#include "MenuVenda/MenuVenda.hpp"
#include <string>

using namespace std;

int UI::Menu(){

    cout << "\nMenu Principal\n";
    cout << "1 - Gerenciar Clientes\n";
    cout << "2 - Gerenciar Vendas\n";
    cout << "0 - Sair\n";
    cout << "Escolha uma opcao: ";

    int opcao;
    cin >> opcao;

    return opcao;
}

void UI::Main(){
    int opcao;
    
    clientedao.Abrir();
    vendadao.Abrir();

    do{
        opcao = Menu();

        switch(opcao){

            case 1: {

                MenuCliente menuCliente;
                menuCliente.abrirArquivo();

                int opCliente;

                do{

                    opCliente = menuCliente.menuOpcoesCliente();

                    switch(opCliente){

                        case 1: menuCliente.cliente_Inserir(); break;
                        case 2: menuCliente.cliente_Listar(); break;
                        case 3: menuCliente.cliente_ListarId(); break;
                        case 4: menuCliente.cliente_Atualizar(); break;
                        case 5: menuCliente.cliente_Excluir(); break;
                        case 0: break;
                        default: cout << "Opção Invalida!\n";
                    } 
                   } while(opCliente != 0);
                   break;
            }

            case 2: {

            MenuVenda menuvenda;    
            menuvenda.abrirArquivo();

            int opVenda;

            do{

                opVenda = menuvenda.menuVendaOpções();

                switch(opVenda){

                    case 1: menuvenda.venda_Inserir(); break;
                    case 2: menuvenda.venda_Listar(); break;
                    case 3: menuvenda.venda_Atualizar(); break;
                    case 4: menuvenda.venda_Excluir(); break;
                    case 0: break;
                    
                    default: cout << "Opção Invalida!\n";
                  }
                } while(opVenda != 0);
                break;
            }

            case 0: {
                cout << "Programa encerrado!\n";
                break;
            }

            default: {
                cout << "Opção Invalida!\n";
                break;
            }
       }
    } while(opcao != 0);
}    
