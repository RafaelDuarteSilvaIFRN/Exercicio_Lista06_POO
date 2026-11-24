#include "MenuCategoria.hpp"
using namespace std;

int MenuCategoria::menuOpcoesCategoria(){

    cout << "\nMenu de categorias\n";
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

void MenuCategoria::categoria_Listar(){

    try{

        vector<Categoria> categorias = ServiceCategoria::categoria_listar();
        
        if(categorias.empty()){
        cout << "Lista vazia!\n"; 
        return;
        }

        for(const Categoria& c: categorias){
            cout << c.ToString() << "\n\n";
        } 
    } catch(const exception& e){
        cout << "Erro ao listar categorias: " << e.what() << endl;  
    }
}

void MenuCategoria::categoria_ListarId(){

    int id;

    cout << "Digite o Id do categoria: ";
    cin >> id;

    try{
        Categoria c = ServiceCategoria::categoria_listar_id(id);
        cout << "\nCategoria encontrada\n";
        cout << c.ToString() << "\n";
    } catch(const exception& e){
        cout << "Erro ao buscar categoria: " << e.what() << endl;
    }
}

void MenuCategoria::categoria_Inserir(){
    int id;
    string categoria;

    cout << "Digite o Id da categoria: ";
    cin >> id;
    cin.ignore();

    cout << "\nDigite a categoria do produto: ";
    getline(cin, categoria);

    try{
        ServiceCategoria::categoria_inserir(id, categoria);
        cout << "Categoria cadastrada com sucesso!\n";
    } catch(const exception& e){
       cout << "Erro ao cadastrar categoria: " << e.what() << endl; 
    }
}

void MenuCategoria::categoria_Atualizar(){
    int id;
    string categoria;

    cout << "Atualiza o Id: ";
    cin >> id;
    cin.ignore();

    cout << "\nAtualiza o seu categoria: ";
    getline(cin, categoria);

    try{
        ServiceCategoria::categoria_atualizar(id, categoria);
        cout << "Categoria atualizada com sucesso!\n";
    } catch(const exception& e){
       cout << "Erro ao atualizar categoria: " << e.what() << endl; 
    }

}

void MenuCategoria::categoria_Excluir(){

    int id;
    cout << "Digite o Id do categoria que deseja excluir: ";
    cin >> id;
    cin.ignore();

    try{
        ServiceCategoria::categoria_excluir(id);
        cout << "Categoria excluido com sucesso!\n";
    } catch(const exception& e){
        cout << "Erro ao excluir categoria: " << e.what() << endl;
    }
 
}