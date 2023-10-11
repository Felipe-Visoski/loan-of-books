#include <bits/stdc++.h>

using namespace std;

struct Livro{
string codigo;
string Titulo;
string disponibilidade="1";
string emprestimo;
};
void login(string l,string s);
void adduser(string l,string s);
void CA();
void MT();
void menup();
void menu();
void emp();

int main(){
 menup();
return 0;
}
void login(string l,string s){
    system("cls");
    ifstream arquivo;
    string linha;
    string user = l;

    string senha1=s;

    arquivo.open("User.txt");
    if(arquivo.is_open()){
    }else{
    cout<<"erro"<<endl;}
    while(getline(arquivo,linha)){

        if(user==linha){

        while(getline(arquivo,linha)){
            if(senha1==linha){
            menu();
            }else{
               cout<<"\n"<<"senha incorreto";
               system("pause");
               cout<<"\n"<<"Tente novamente"<<endl;
               menup();
            }
        }

        }
        }
        system("pause");
        cout<<"\n"<<"senha incorreto";
        system("pause");
        cout<<"\n"<<"Tente novamente"<<endl;
        menup();
        fflush(stdin);
        cout <<"\n";
        arquivo.close();
        login(l,s);
        system("pause");

}
void adduser(string l,string s){
    string lg= l;
    string sa=s;
    fstream arquivo;
    arquivo.open("User.txt",ios::out|ios::app);
    arquivo <<lg<<endl;
    arquivo <<s<<endl;
   arquivo.close();
}
void CA(string t,int c){
  Livro cadl[100];
  cadl[c].Titulo = t;
    fstream arquivoS;
    arquivoS.open("Livros.txt",ios::out|ios::app);
    arquivoS<<c<<endl;
    arquivoS<<cadl[c].Titulo<<endl;
    arquivoS<<cadl[c].disponibilidade<<endl;
    arquivoS.close();
    cout << "\nLivro cadastrado com sucesso.....\n";
    system("pause");
    return menu();
};
void menup(){
 int op;
  cout<<"BEM VINDO"<<endl;
    char  user[30];
    char senha1[30];

  do{
   system("cls");
    cout <<"\n __________MENU_________";
    cout <<"\n|1- Login               |";
    cout <<"\n|2- Cadastrar usuario   |";
    cout <<"\n|3- Sair                |";
    cout <<"\n|_______________________|";
    cout <<"\nDigite uma opcao:";
    cin >> op;
    fflush(stdin);
    switch(op){
    case 1:
    system("cls");
    fflush(stdin);
        cout<<"\n"<<"Login:";
    cin>>user;
    fflush(stdin);
     cout<<"\n"<<"Senha:";
    cin>>senha1;
       login(user,senha1);
       system("pause");
        break;
    case 2:
        system("cls");
        fflush(stdin);
        cout<<"\n"<<"Cadatre seu usuario"<<endl;
        cout<<"\n"<<"Digite login:";
    cin>>user;
    fflush(stdin);
     cout<<"\n"<<"Digite senha:";
    cin>>senha1;
        adduser(user,senha1);
        system("pause");
        break;
    case 3:
        system("cls");
        cout <<"\nFinalizando........";
        exit(0);
        break;
    default:
        cout << "Opcao invalida";
        return menup();
        break;

    }

    }while(op!=3);


}
void menu(){
    int op;
  int codigo1;
  char titulo[30];

    do{
   system("cls");
    cout <<"\n __________MENU_________";
    cout <<"\n|1- Adicionar livro     |";
    cout <<"\n|2- listar livros       |";
    cout <<"\n|3- Emprestar um  livros|";
    cout <<"\n|4- Excluir livro       |";
    cout <<"\n|5- Sair                |";
    cout <<"\n|_______________________|";
    cout <<"\nDigite uma opcao:";
    cin >> op;
    fflush(stdin);
    switch(op){
    case 1:
    system("cls");
    cout <<"\n Digite um codigo para o livro:";
    fflush(stdin);
    cin >>codigo1;
    fflush(stdin);
     cout <<"\n Digite um titulo para o livro:";
     cin >>titulo;
     fflush(stdin);
     CA(titulo,codigo1);
     fflush(stdin);
       system("pause");
        break;
    case 2:
    system("cls");
       MT();
        system("pause");
        break;
    case 3:
        system("cls");
        emp();
        system("pause");
        break;
    case 4:
        system("cls");

        system("pause");
        break;
    case 5:
        system("cls");
        cout <<"\nFinalizando........";
        exit(0);
        break;
    default:
        cout << "Opcao invalida";
        return menu();
        break;

    }

    }while(op!=5);
}
void MT(){
    system("cls");
ifstream arquivoE;
    string linha;
cout<<"\n*********LIVROS******************"<<endl;
    arquivoE.open("Livros.txt");
    if(arquivoE.is_open()){

    }else{
    cout<<"erro"<<endl;}
    while(getline(arquivoE,linha)){

        cout<<"\n"<<linha;
        }
        cout <<"\n";
        arquivoE.close();
        system("pause");
        return menu();
};
void emp(){
 Livro cadl[100];
 int i=0;
 int t=0;
    system("cls");
ifstream arquivoE;
    string linha;
cout<<"\n*********LIVROS******************"<<endl;
    arquivoE.open("Livros.txt");
    if(arquivoE.is_open()){

    }else{
    cout<<"erro"<<endl;}

     arquivoE>>cadl[i].codigo;
     arquivoE>>cadl[i].Titulo;
     arquivoE>>cadl[i].disponibilidade;
        arquivoE.close();



   system("pause");
    cout<<"\n"<"digite o codigo do livro:";
    fflush(stdin);
    cin>>t;
    system("pause");
    if(cadl[t].disponibilidade=="0"){
        cout<<"livro nao disponivel";

    }else{
    cadl[t].disponibilidade="0";
    cout<<"\n"<<"livro emprestado com sucesso";

    }
       fstream arquivoS;
         system("pause");
    arquivoS.open("Livros.txt");
    arquivoS<<cadl[t].codigo<<endl;
    arquivoS<<cadl[t].Titulo<<endl;
    arquivoS<<cadl[t].disponibilidade<<endl;


       arquivoS.close();
        system("pause");
//  return menu();

}
