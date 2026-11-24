#include "MenuProduto.hpp"
#include "../../models/Categoria/Categoria.hpp"
#include "../../service/ServiceCategoria/serviceCategoria.hpp"
using namespace std;

int MenuProduto::menuOpcoesProduto(){

    cout << "\nMenu de produtos\n";
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

void MenuProduto::produto_Listar(){

    vector<Produto> produtos = ServiceProduto::produto_listar();
    
    if(produtos.empty()){
       cout << "Nenhum produto cadastrado no sistema!\n"; 
       return;
    }

    for(const Produto& p: produtos){
        cout << p.ToString() << "\n";
    
        try{

            Categoria catDesc = ServiceCategoria::categoria_listar_id(p.getIdCategoria());
            cout << "Categoria: " << catDesc.getDescricao() << endl;

        } catch(const exception&){
            cout << "Categoria: Nenhuma categoria encontrada!\n";

        }

     }
}

void MenuProduto::produto_ListarId(){
    int id;

    cout << "Informe o id do produto que você deseja encontrar: ";
    cin >> id;

    try{
        Produto p = ServiceProduto::produto_listar_id(id);
        cout << "\nProduto encontrado\n";
        cout << p.ToString() << "\n";
    } catch(const exception& e){
      cout << "Erro ao buscar produto: " << e.what() << endl;  
    }
}

void MenuProduto::produto_Inserir(){
    int id, estoque, id_categoria;
    string descricao;
    double preco;

    cout << "Digite o Id: ";
    cin >> id;
    cin.ignore();

    cout << "Digite a descrição do produto: ";
    getline(cin, descricao);
    cin.ignore();

    cout << "\nDigite o preço: ";
    cin >> preco;
    cin.ignore();

    cout << "\nDigite a quantidade de estoque: ";
    cin >> estoque;
    cin.ignore();

    cout << "\nDigite o id da categoria pertecente ao estoque: ";
    cin >> id_categoria;
    cin.ignore();

    try{
        ServiceProduto::produto_inserir(id, id_categoria, estoque, descricao, preco);
        cout << "Produto cadastrado com sucesso!\n";

    } catch(const exception& e){
        cout << "Error ao cadastrar produto: " << e.what() << endl;
    }
}

void MenuProduto::produto_Atualizar(){
    int id, estoque, id_categoria, escolher_item;
    string descricao;
    double preco;

    cout << "informe o Id: ";
    cin >> id;
    cin.ignore();
    
    try{
        Produto p = ServiceProduto::produto_listar_id(id);
        id_categoria = p.getIdCategoria();
        descricao = p.getDescricao();
        preco = p.getPreco();
        estoque = p.getEstoque();
        
        cout << "Selecione qual item vc deseja atualizar:\n";
        cout << "[1] Descrição  [2] preço  [3] estoque  [4]id da categoria\n";
        cin >> escolher_item;

        switch(escolher_item){

            case 1 : {
                    cout << "\nInforme a descrição que vc deseja atualizar: ";
                    cin.ignore(); 
                    getline(cin, descricao);
                    break;
            }

            case 2: {
                cout << "Informe o preço que vc deseja atualizar: ";
                cin >> preco;
                break;
            }

            case 3: {
                cout << "\nInforme o estoque que vc deseja atualizar: ";
                cin >> estoque;
                break;
            }
            
            case 4: {
                cout << "Informe o id da categoria que vc deseja atualizar: ";
                cin >> id_categoria;
                break;
            }

            default :{
                cout << "Opção invalida!\n";
                return;
            }

        }
        
        ServiceProduto::produto_atualizar(id, id_categoria, estoque, descricao, preco);
        cout << "Produto atualizado com sucesso!\n";
    }catch(const exception& e){
        cout << "\nErro ao atualizar Produto: " << e.what() << endl; 
    }    
}

void MenuProduto::produto_Excluir(){

    int id;
    cout << "Digite o Id do Produto que deseja excluir: ";
    cin >> id;

    try{
        ServiceProduto::produto_excluir(id);
        cout << "Produto excluido com sucesso!\n";
    } catch(const exception& e){
        cout << "Erro ao excluir Produto: " << e.what() << endl;
    }
}