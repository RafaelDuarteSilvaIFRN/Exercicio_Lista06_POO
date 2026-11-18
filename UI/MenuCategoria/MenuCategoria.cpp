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

void MenuCategoria::abrirArquivo(){
     categoriadao.Abrir();
}

void MenuCategoria::categoria_Listar(){
    vector<Categoria> categorias = categoriadao.Listar();
    
    if(categorias.empty()){
       cout << "Lista vazia!\n"; 
       return;
    }

    for(const Categoria& c: categorias){
            cout << c.ToString() << "\n\n";
    }
}

void MenuCategoria::categoria_ListarId(){

    int id;

    cout << "Digite o Id do categoria: ";
    cin >> id;

    Categoria c = categoriadao.Listar_Id(id);
    cout << "\nCategoria encontrada\n";
    cout << c.ToString() << "\n";

}

void MenuCategoria::categoria_Inserir(){
    int id;
    string categoria;

    cout << "Digite o Id da categoria: ";
    cin >> id;
    cin.ignore();

    cout << "\nDigite a categoria do produto: ";
    getline(cin, categoria);

    Categoria c(id, categoria);
    categoriadao.Inserir(c);
    categoriadao.Salvar();

    cout << "categoria cadastrado com sucesso!\n";
}

void MenuCategoria::categoria_Atualizar(){
    int id;
    string categoria;

    cout << "Atualiza o Id: ";
    cin >> id;
    cin.ignore();

    cout << "\nAtualiza o seu categoria: ";
    getline(cin, categoria);

    Categoria c(id, categoria);

    categoriadao.Atualizar(c);
    categoriadao.Salvar();

    cout << "\nCategoria atualizado com sucesso!\n";
}

void MenuCategoria::categoria_Excluir(){

    int id;
    cout << "Digite o Id do categoria que deseja excluir: ";
    cin >> id;
    cin.ignore();

    Categoria obj = categoriadao.Listar_Id(id);
    categoriadao.Excluir(obj.getId());
    categoriadao.Salvar();

    cout << "categoria excluido com sucesso!\n";
}