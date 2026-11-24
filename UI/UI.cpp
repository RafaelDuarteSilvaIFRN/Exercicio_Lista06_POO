#include <iostream>
#include "UI.hpp"
#include "MenuCliente/MenuCliente.hpp"
#include "MenuVenda/MenuVenda.hpp"
#include "MenuCategoria/MenuCategoria.hpp"
#include "MenuProduto/MenuProduto.hpp"
#include "MenuVendaItem/MenuVendaItem.hpp"
#include <string>

using namespace std;

int UI::Menu(){

    cout << "\nMenu Principal\n";
    cout << "1 - Gerenciar Clientes\n";
    cout << "2 - Gerenciar Vendas\n";
    cout << "3 - Gerenciar Categorias\n";
    cout << "4 - gerenciar Produtos\n";
    cout << "5 - gerenciar item de venda\n";
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
    produtoDAO.Abrir();
    vendaItemDAO.Abrir();
    do{
        opcao = Menu();

        switch(opcao){

            case 1: {

                MenuCliente menuCliente;

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

            int opVenda;

            do{

                opVenda = menuvenda.menuVendaOpções();

                switch(opVenda){

                    case 1: menuvenda.venda_Inserir(); break;
                    case 2: menuvenda.venda_Listar(); break;
                    case 3: menuvenda.venda_ListarId(); break;
                    case 4: menuvenda.venda_Atualizar(); break;
                    case 5: menuvenda.venda_Excluir(); break;
                    case 0: break;
                    
                    default: cout << "Opção Invalida!\n";
                  }
                } while(opVenda != 0);
                break;
            }

            case 3: {

            MenuCategoria menuCategoria;

            int opCategoria;

            do{

                opCategoria = menuCategoria.menuOpcoesCategoria();

                switch(opCategoria){

                    case 1: menuCategoria.categoria_Inserir(); break;
                    case 2: menuCategoria.categoria_Listar(); break;
                    case 3: menuCategoria.categoria_ListarId(); break;
                    case 4: menuCategoria.categoria_Atualizar(); break;
                    case 5: menuCategoria.categoria_Excluir(); break;
                    case 0: break;
                    
                    default: cout << "Opção Invalida!\n";
                  }
                } while(opCategoria != 0);
                break;
            }

            case 4: {

            MenuProduto menuProduto;

            int opProduto;

            do{

                opProduto = menuProduto.menuOpcoesProduto();

                switch(opProduto){

                    case 1: menuProduto.produto_Inserir(); break;
                    case 2: menuProduto.produto_Listar(); break;
                    case 3: menuProduto.produto_ListarId(); break;
                    case 4: menuProduto.produto_Atualizar(); break;
                    case 5: menuProduto.produto_Excluir(); break;
                    case 0: break;
                    
                    default: cout << "Opção Invalida!\n";
                  }
                } while(opProduto != 0);
                break;
            }

               case 5: {

            MenuVendaItem menu_vendaItem;    
            menu_vendaItem.abrirArquivo();

            int opItem;

            do{

                opItem = menu_vendaItem.menuVendaItemOpções();

                switch(opItem){

                    case 1: menu_vendaItem.vendaItem_Inserir(); break;
                    case 2: menu_vendaItem.vendaItem_Listar(); break;
                    case 3: menu_vendaItem.vendaItem_ListarId(); break;
                    case 4: menu_vendaItem.vendaItem_Atualizar(); break;
                    case 5: menu_vendaItem.vendaItem_Excluir(); break;
                    case 0: break;
                    
                    default: cout << "Opção Invalida!\n";
                  }
                } while(opItem != 0);
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
