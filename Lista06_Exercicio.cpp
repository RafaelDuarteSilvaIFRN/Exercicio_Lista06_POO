#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class Cliente{

    private: 
        int id;
        string nome;
        string email;
        string fone;

    public:
        Cliente(int id, string n, string e, string f){
                setId(id);
                setNome(n);
                setEmail(e);
                setFone(f);
        }

        void setId(int id){
             if(id > 0){
                this -> id = id;
             } else{
                throw invalid_argument("Id invalido!");  
             }
        }

        int getId() const{
            return id;
        }

        void setNome(string nome){
            if(!nome.empty()){
                this -> nome = nome;
            } else{
                throw invalid_argument("Nome vazio!");  
            }
        }

        string getNome() const{
            return nome;
        }

        void setEmail(string email){
            if(!email.empty()){
                this -> email = email;
            } else{
               throw invalid_argument("Email vazio!");  
            }
        }

        string getEmail() const{
            return email;
        }

        void setFone(string fone){
            if(!fone.empty()){
                this -> fone = fone;
            } else{
                throw invalid_argument("Fone vazio!");  
            }
        }

        string getFone() const{
            return fone;
        }

        string ToString() const{

            return "Id: " + to_string(id) + "\nNome: " + nome +
                    "\nEmail: " + email + "\nFone: " + fone;

        }
};

class ClienteDAO{

    private:
        
        vector<Cliente> objetos;

    public:

        void Inserir(Cliente obj){
            objetos.push_back(obj);   
        }

        vector<Cliente> Listar(){
            return objetos;
        }

        Cliente Listar_Id(int id){
            for(const Cliente& c: objetos){
                if(c.getId() == id){
                   return c; 
                }
            }

            throw invalid_argument("Cliente não encontrado!");
        }

        void Atualizar(Cliente obj){
            for(Cliente& c : objetos){
                
                if(c.getId() == obj.getId()){
                   c = obj;
                   return;
                }

            }

            throw invalid_argument("Cliente não encontrado!");
        }

        void Excluir(Cliente obj){
            for(size_t i = 0; i < objetos.size(); i++){

                if(objetos[i].getId() == obj.getId()){
                   objetos.erase(objetos.begin() + i);
                   return; 
                }
            }

            throw invalid_argument("Cliente não encontrado!");
        }

        void Abrir(){
            ifstream arquivo("clientes.json");

            if(!arquivo.is_open()){
               objetos.clear();
               return;
            }

            json dados = json::parse(arquivo);
            objetos.clear();

            for(const auto& item: dados){
                Cliente c(

                    item.at("id").get<int>(),
                    item.at("nome").get<string>(),
                    item.at("email").get<string>(),
                    item.at("fone").get<string>()

                );

                objetos.push_back(c);
            } 
        }

        void Salvar(){
            json dados = json::array();

            for(const Cliente& c: objetos){
                json item;

                item["id"] = c.getId();
                item["nome"] = c.getNome();
                item["email"] = c.getEmail();
                item["fone"] = c.getFone();

                dados.push_back(item);
            }

            ofstream arquivo("clientes.json");

            if(!arquivo.is_open()){
                throw runtime_error("Não foi possivel salvar o arquivo");
            }

            arquivo << dados.dump(4);
        }
};

class UI{

    private:
        ClienteDAO dao;

    public:

        int Menu(){

            cout << "\nMenu de clientes\n";
            cout << "1 - Inserir\n";
            cout << "2 - Listar\n";
            cout << "3 - Buscar por ID\n";
            cout << "4 - Atualizar\n";
            cout << "5 - Excluir\n";
            cout << "0 - Sair\n";
            cout << "Escolha uma opcao: ";

            int opcao;
            cin >> opcao;

            return opcao;
        }

        void Main(){
            int opcao;
            
            dao.Abrir();

            do{

                opcao = Menu();

                switch(opcao){
                    case 1:{
                        Cliente_Inserir();
                        break;
                    }

                    case 2:{
                        Cliente_Listar();
                        break;
                    }

                    case 3:{
                        Cliente_ListarId();
                        break;
                    }

                    case 4:{
                        Cliente_Atualizar();
                        break;
                    }

                    case 5:{
                        Cliente_Excluir();
                        break;
                    }

                    case 0:{
                        cout << "Programa encerrado!\n";
                        break;
                    }

                    default:{
                        cout << "Opção invalida!\n";
                        break;
                    }
                }
             } while(opcao != 0);
        }

        void Cliente_Listar(){
             vector<Cliente> clientes = dao.Listar();

             for(const Cliente& c: clientes){
                cout << c.ToString() << "\n\n";
             }
        }

        void Cliente_ListarId(){

            int id;

            cout << "Digite o Id do cliente: ";
            cin >> id;
  
            Cliente c = dao.Listar_Id(id);
            cout << "\nCliente encontrado\n";
            cout << c.ToString() << "\n";

        }

        void Cliente_Inserir(){
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
            dao.Inserir(c);
            dao.Salvar();

            cout << "Cliente cadastrado com sucesso!\n";
        }

        void Cliente_Atualizar(){
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

            dao.Atualizar(c);
            dao.Salvar();

            cout << "\nCliente atualizado com sucesso!\n";
        }

    void Cliente_Excluir(){

        int id;
        cout << "Digite o Id do cliente que deseja excluir: ";
        cin >> id;

        Cliente obj = dao.Listar_Id(id);
        dao.Excluir(obj);
        dao.Salvar();


        cout << "Cliente excluido com sucesso!\n";
    }
};

int main(){
    UI ui;
    ui.Main();

    return 0;
}