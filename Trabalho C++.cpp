#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <cstdlib>

using namespace std;

class Professor {
	private:
		string matricula;
		string nome;
		string telefone;
		string email;
	
	public:
		void CriarProfessor() {
			cout << "CADASTRO DO PROFESSOR" << endl;
			cout << "--------------------------------------------" << endl;
			cout << "Informe o nome: ";
			cin >> nome;
			cout << "Informe a matricula: ";
			cin >> matricula;
			cout << "Informe o telefone: ";
			cin >> telefone;
			cout << "Informe o email: ";
			cin >> email;
			cout << "---------------------------------------------" << endl;	
		}
		
		void ImprimirProfessor() {
			cout<<"Nome: " << nome<<endl;
			cout<<"Matricula: "<<matricula<<endl;
			cout<<"Telefone: "<<telefone<<endl;
			cout<<"E-mail: "<<email<<endl;
			cout<<"--------------------------------------------\n";
		}
};

class TipoRecurso {
	private:
		int idTipoRecurso;
		string nome;
		string caracteristica;
		int qtdRecurso;
	public:
		void CriarTipoRecurso () {
			cout << "Informe o ID do Recurso: " << endl;
			cin >> idTipoRecurso;
			cout << "Informe o nome do Recurso: " << endl;
			cin >> nome;
			cout << "Informe as caracteristicas do Recurso:\n";
			setbuf(stdin,NULL);
			getline(cin, caracteristica);
			cout << "Informe a quantidade do Recurso: \n";
			cin >> qtdRecurso;
			cout << "--------------------------------------------\n";
		}
		
		void ImprimirRecurso() {
			cout << "--------------------------------------------\n";
			cout << "ID do Recurso: " << idTipoRecurso << endl;
			cout << "Nome do Recurso: " << nome << endl;
			cout << "Caracteristicas do Recurso: " << caracteristica << endl;
			cout << "Quantidade do Recurso: " << qtdRecurso << endl;
			cout << "--------------------------------------------\n";
		}
		
		int obterIdTipoRecurso() {
			return idTipoRecurso;
		}
};

class Solicitacao {
	private:
		TipoRecurso tiporecurso;
		Professor professor;
		char dtSolicitacao[10];
		char hrSolicitacao[10];
		string predio;
		string sala;
		string dtUso;
		string hrIniUso;
	   	string hrFimUso;
	public:
		void CriarSolicitacao(TipoRecurso tipoRecursoEscolhido) {
			tiporecurso=tipoRecursoEscolhido;
			professor.CriarProfessor();
			cout<<"DADOS DA SOLICITACAO: \n";
			cout<<"--------------------------------------------\n";
			cout<<"Informe o predio da Solicitacao: ";
			cin>>predio;
			cout<<"Informe a sala da Solicitacao: ";
			cin>>sala;
			cout<<"Informe a data de uso: ";
			cin>>dtUso;
				do{
					cout<<"Informe a hora inicial de uso: ";
					cin>>hrIniUso;
					cout<<"Informe a hora de termino do uso: ";
					cin>>hrFimUso;
						if (hrIniUso>hrFimUso) {
							cout << "--------------------------------------------\n";
							cout << "HORA INVALIDA!\nHora de incio nao pode ser maior que a hora de termino!\nDIGITE NOVAMENTE!\n";
							cout << "--------------------------------------------\n";
						}
				} while (hrIniUso>hrFimUso);
			cout << "Solicitacao realizada.\nAperte qualquer tecla para imprimir a solicitacao.\n";
			system("PAUSE");
		}
		
		private:
			TipoRecurso ObterTipoRecurso () {
				return tiporecurso;
			}
			
			Professor ObterProfessor () {
				return professor;
			}
			
		public:
			void ImprimirSolicitacao() {
				system("CLS");
				_strdate(dtSolicitacao);
				_strtime(hrSolicitacao);
				cout<<"-----------|IMPRIMINDO SOLICITACAO|------------\n";
				cout<<"SOLICITACAO:\n";
				cout<<"Data da Solicitacao(mm/dd/yyyy): " << dtSolicitacao<<endl;
				cout<<"Hora da Solicitacao: " << hrSolicitacao<<endl;
				cout<<"Predio da Solicitacao: "<<predio<<endl;
				cout<<"Sala da Solicitacao: "<<sala<<endl;
				cout<<"Data de uso: "<<dtUso<<endl;
				cout<<"Hora inicial de uso: "<<hrIniUso<<endl;
				cout<<"Hora de termino do uso: "<<hrFimUso<<endl;
				cout << "--------------------------------------------\n";
				cout<<"RECURSO SOLICITADO:\n";
				tiporecurso.ImprimirRecurso();
				cout<<"PROFESSOR SOLICITANTE:\n";
				professor.ImprimirProfessor();				
				system("PAUSE");
			}
};

//CLASSE ABSTRATA NÓ
class No {
	public:
		void ImprimirNo();
	private:
		void ObterInfo();
		void ObterProximo();	
};


//CRIAÇÃO DE NÓS
class NoTipoRecurso : public No {
	private:
		TipoRecurso info;
		NoTipoRecurso *proximo;
	public:
		NoTipoRecurso(NoTipoRecurso* cabeca, TipoRecurso novoinfo) {
			info=novoinfo;
			proximo=cabeca;
		}
		void ImprimirNo() {
			info.ImprimirRecurso();
		}
	public:
		TipoRecurso ObterInfo() {
			return info;
		}
		
		NoTipoRecurso* ObterProximo() {
			return proximo;
		}
		
	public:
		TipoRecurso BuscarNo (int chave) {
			TipoRecurso aux;
			if (chave == info.obterIdTipoRecurso()) {
				return info;
			}
			return aux;
		}	
};

class NoSolicitacao : public No {
	private:
		Solicitacao info;
		NoSolicitacao *proximo;
	public:
		NoSolicitacao(NoSolicitacao* cabeca, Solicitacao novoinfo) {
			   info=novoinfo;
			   proximo=cabeca;	
		}
		
		void ImprimirNo() {
			info.ImprimirSolicitacao();
		}
	public:
		Solicitacao ObterInfo() {
			return info;
		}
		
		NoSolicitacao* ObterProximo() {
			return proximo;
		}
};

//CRIAÇÃO DE LISTAS
class Lista {
	private:
		void ObterCabecaLista();
		void AlterCabecaLista();
	public:
		void InserirNo();
		void ImprimirLista();
};

class ListaTipoRecurso : public Lista {
	private:
		NoTipoRecurso *cabecaLista;
	public:
		ListaTipoRecurso() {
			cabecaLista=NULL;
		}
	public:
		NoTipoRecurso* ObterCabecaLista() {
			return cabecaLista;
		}
		
		void AlterarCabecaLista(NoTipoRecurso* novaCabeca) {
			cabecaLista = novaCabeca; 	
		}
    public:
    	void InserirNo(TipoRecurso novoTipoRecurso) {
			   NoTipoRecurso *novo = new NoTipoRecurso (cabecaLista, novoTipoRecurso);
			   this->AlterarCabecaLista(novo);	
		}
		
		void ImprimirLista() {
			NoTipoRecurso *temp = cabecaLista;
						
			while(temp!=NULL) {
				temp->ImprimirNo();
				temp=temp->ObterProximo();
			}
		}
		
		TipoRecurso ObterInfo() {
				NoTipoRecurso *temp;
				TipoRecurso recursoObtido;
				int chave;
				
				do {
					temp = cabecaLista;	
					cout << "Digite o ID do recurso que deseja solicitar: \n";
					scanf("%d", &chave);							 
					while(temp!=NULL) {							
						temp->BuscarNo(chave);						
						if (chave == temp->ObterInfo().obterIdTipoRecurso()) {						;	
							cout<<"Recurso encontrado!\n";
							cout <<"---------------------------------------------\n";							
							recursoObtido = temp->ObterInfo();
							temp=NULL;
						} else {
							temp=temp->ObterProximo();
						}
					}
				if(temp==NULL && recursoObtido.obterIdTipoRecurso()!=chave) {
					cout<<"Recurso nao encontrado! Escolha novamente!\n--------------------------------------------\n";
				}
			} while (temp==NULL && recursoObtido.obterIdTipoRecurso()!=chave);
			return recursoObtido;
		}
		
};

class ListaSolicitacao : public Lista {
	private:
		NoSolicitacao *cabecaLista;
	private:
		NoSolicitacao* ObterCabecaLista() {
			return cabecaLista;
		}		 		
		
		void AlterarCabecaLista(NoSolicitacao* novaCabeca) {
			cabecaLista = novaCabeca;
		}
	public:
		ListaSolicitacao() {
			cabecaLista=NULL;
		}
		
		void InserirNo(Solicitacao novaSolicitacao)	 {
			NoSolicitacao *nova = new NoSolicitacao(cabecaLista, novaSolicitacao);
			this->AlterarCabecaLista(nova);
		}
		
		void ImprimirLista() {
			NoSolicitacao *temp = cabecaLista;
			while(temp!=NULL) {
				temp->ImprimirNo();
				temp=temp->ObterProximo();
			}
		}
};

int main() {
	ListaTipoRecurso listaRecurso;
	ListaSolicitacao listaSolicitacao;
	
	
	int opcaoMenu;
	bool sair;
	char opcao;
	int cadastrados = 0;
	do{
		cout <<"Cheguei aqui \n";
		system("CLS");
		//Solicitacao novaSolicitacao;
		cout<<"-------------------|MENU|--------------------\n";
		printf("1. Cadastrar Recurso. \n");
		printf("2. Solicitar Recurso. \n");
		printf("3. Listar solicitacoes. \n");
		printf("4. Sair. \n");
		cout <<"---------------------------------------------\n";
		printf("Digite a opcao: \n");
		scanf("%d", &opcaoMenu);
		switch(opcaoMenu){
			case 1:
        		do{
        			TipoRecurso recurso;
        			recurso.CriarTipoRecurso();
					listaRecurso.InserirNo(recurso);
					cout << "\nInserir outro recurso(S/N)?\n";
					cin >> opcao;
				}while(opcao == 's' || opcao == 'S');
				cout << "Recursos cadastrados com sucesso!" << endl;
				cout <<"---------------------------------------------\n";
				cadastrados++;
				system("PAUSE");
        		sair = false;
        		break;
			case 2:
				{
					if (cadastrados == 0) {
						cout<<"NAO HA RECURSOS PARA SOLICITAR!"<<endl;
						cout <<"---------------------------------------------\n";
						system("PAUSE");
					}else{	
						listaRecurso.ImprimirLista();
						TipoRecurso tempRecurso;
						Solicitacao novaSolicitacao;
						tempRecurso = listaRecurso.ObterInfo(); /*Atribui o Recurso encontrado a esse variavel*/
					
						novaSolicitacao.CriarSolicitacao(tempRecurso);		
						listaSolicitacao.InserirNo(novaSolicitacao);
						listaSolicitacao.ImprimirLista();        				
					}					
					sair = false;					
    				break;
				}
			case 3:
				{
					printf("Opcao ainda em desenvolvimento\n");
					sair = false;
					system("PAUSE");
					break;
				}
			case 4:
	  	  	  	  {	
					sair = true;
					break;
				  }
			default:
				cout << "Opcao indisponivel" << endl;
				sair = false;
				system("PAUSE");
				break;
		}		
	}while(sair == false);
}