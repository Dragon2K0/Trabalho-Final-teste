#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <random>
#include <time.h>
#include <iterator>
#include <math.h>
using namespace std;
//Controle (governar) de compra à prazo;
//venda sendo apenas por clientes com cadastro ativo;

typedef struct cliente {
	int codigoCliente;
	string nomeCliente;
	bool statusCadastro;
	// Para teste,deve ser cliente ativo e inativo;
} Cliente;

typedef struct produto {
	int codigoProduto;
	float precoProduto;
	string nomeProduto;
	string dataUltimaAlteracao;
	//dieselS10; Gasolina; Etanol comum;
} Produto;

typedef struct venda {
	int codigoComprador;
	int codigoProdutoVenda;
	float litrosAbastecidos;
	float valorLitros;
	string nomeCliente;
	bool statusPagamento;
	//Saida de venda deve seguir a sequência: Data; Cliente; Combustivel; Quantidade e Responsável;
	//Para teste deve existir vendas pagas e não pagas;
} Venda;

int main() {
	Cliente novoCliente;
	srand(time(0));
	map<int, Cliente> Client;

	//cadastro de Cliente. COMEÇO
	int cont = 1;

	novoCliente.codigoCliente = cont;
	novoCliente.nomeCliente = "Joao_Cleber";
	novoCliente.statusCadastro = false;

	Client[novoCliente.codigoCliente] = novoCliente;

	/*cout << "Cliente Cadastrado: "
	<< Client[novoCliente.codigoCliente].codigoCliente
	<< " " << Client[novoCliente.codigoCliente].nomeCliente
	<< " " << Client[novoCleinte.codigoCliente].statusCadastro << endl;*/

	novoCliente.codigoCliente = ++cont;
	novoCliente.nomeCliente = "Carlos_Alberto";
	novoCliente.statusCadastro = true;

	Client[novoCliente.codigoCliente] = novoCliente;

	map<int, Cliente>::iterator it = Client.begin();
	//cadastro de Cliente. FIM

	//cadastro de Produto. COMEÇO
	Produto novoProduto;
	srand(time(0));
	map<int, Produto> Product;

	novoProduto.codigoProduto = rand() % 100 + 1;
	novoProduto.nomeProduto = "diesel_S_10";
	novoProduto.precoProduto = 4, 988.f;
	novoProduto.dataUltimaAlteracao = "30/05/22";

	Product[novoProduto.codigoProduto] = novoProduto;

	/*cout << "Produto Cadastrado: "
	<< Produto[novoProduto.codigoProduto].codigoProduto
	<< " " << Produto[novoProduto.codigoProduto].nomeCliente
	<< " " << Produto[novoProduto.codigoProduto].precoProduto
	<< " " << Produto[novoProduto.codigoProduto].dataUltimaAlteracao << endl;*/

	novoProduto.codigoProduto = +rand() % 100 + 1;
	novoProduto.nomeProduto = "gasolina";
	novoProduto.precoProduto = 7, 849.f;
	novoProduto.dataUltimaAlteracao = "30/05/22";

	Product[novoProduto.codigoProduto] = novoProduto;

	novoProduto.codigoProduto = +rand() % 100 + 1;
	novoProduto.nomeProduto = "etanol_comum";
	novoProduto.precoProduto = 6, 597.f;
	novoProduto.dataUltimaAlteracao = "30/05/22";

	Product[novoProduto.codigoProduto] = novoProduto;
	//Cadastro de Produto. FIM

	//cadastro de Venda. COMEÇO
	Venda novaVenda;
	srand(time(0));
	map<int, Venda> Sell;

	novaVenda.codigoComprador = 0;
	novaVenda.codigoProdutoVenda = 0;
	novaVenda.litrosAbastecidos = 0;
	novaVenda.valorLitros = 0;
	novaVenda.nomeCliente = 1;
	novaVenda.statusPagamento = 0;

	Sell[novaVenda.codigoProdutoVenda] = novaVenda;

	/*cout << "Produto vendido: "
	<< Sell[novaVenda.codigoProdutoVenda].novaVenda
	<< " " << Sell[novaVenda.codigoProdutoVenda].codigoComprador
	<< " " << Produto[novoProduto.codigoProduto].litrosAbastecidos
	<< " " << Produto[novoProduto.codigoProduto].valorLitros
	<< " " << Sell[novaVenda.codigoProdutoVenda].nomeCliente
	<< " " << Sell[novaVenda.codigoProdutoVenda].statusPagamento << endl;*/

	//cadastro de Venda. FIM


	//MENU.
	int val;

	do {
		system("CLS");

		cout << "\nSelecione uma opcao : \n";
		cout << "\n[1] = Adicionar Cliente.\n";
		cout << "\n[2] = Visualizar Clientes cadastrados.\n";
		cout << "\n[3] = Visualizar Produtos cadastrados.\n";
		cout << "\n[4] = Efetuar Venda.\n";
		cout << "\n[0] = Sair.\n\n";
		cin >> val;

		switch (val) {

		case 1: {//Adicionar Cliente.
			system("CLS");

			cout << "\nDigite o Nome do cliente:\n";
			cin >> novoCliente.nomeCliente;
			cout << "\nDigite o status do cadastro (1= ativo)(0= inativo):\n";
			cin >> novoCliente.statusCadastro;
			novoCliente.codigoCliente = ++cont;

			Client[novoCliente.codigoCliente] = novoCliente;

			system("PAUSE");
			break;
		}

		case 2: {//Visualizar Clientes cadastrados.
			system("CLS");

			map<int, Cliente>::iterator it = Client.begin();

			cout << "\n______________________________________________________________________________________________________________\n";
			while (it != Client.end()) {
				int codigoCliente = it->first;
				Cliente client = it->second;

				cout << "\nCliente Cadastrado: "
					<< " " << "Codigo: " << client.codigoCliente
					<< " - " << client.nomeCliente
					<< " - " << client.statusCadastro << endl;
				it++;
			}
			cout << "\n______________________________________________________________________________________________________________\n\n\n\n";

			system("PAUSE");
			break;
		}

		case 3: {//Visualizar Produtos cadastrados.
			system("CLS");

			map<int, Produto>::iterator it = Product.begin();

			cout << "\n______________________________________________________________________________________________________________\n";
			while (it != Product.end()) {
				int codigoProduto = it->first;
				Produto product = it->second;

				cout << "\nProduto Cadastrado: "
					<< " " << "Codigo: " << product.codigoProduto
					<< " - " << product.nomeProduto
					<< " - " << product.precoProduto
					<< " - " << product.dataUltimaAlteracao << endl;
				it++;
			}
			cout << "\n______________________________________________________________________________________________________________\n\n";

			system("PAUSE");
			break;
		}
		case 4: {//Efetuar Venda.
			system("CLS");

			map<int, Produto>::iterator it = Product.begin();

			cout << "\n______________________________________________________________________________________________________________\n";
			while (it != Product.end()) {
				int codigoProduto = it->first;
				Produto product = it->second;

				cout << "\nProduto Cadastrado: "
					<< " " << "Codigo: " << product.codigoProduto
					<< " - " << product.nomeProduto
					<< " - " << product.precoProduto
					<< " - " << product.dataUltimaAlteracao << endl;
				it++;
			}
			cout << "\n______________________________________________________________________________________________________________\n";

			map<int, Cliente>::iterator its = Client.begin();

			while (its != Client.end()) {
				int codigoCliente = its->first;
				Cliente client = its->second;

				cout << "\nCliente Cadastrado: "
					<< " " << "Codigo: " << client.codigoCliente
					<< " - " << client.nomeCliente
					<< " - " << client.statusCadastro << endl;
				its++;
			}
			cout << "\n______________________________________________________________________________________________________________\n\n";

			cout << "\nDigite o Codigo do Cliente:\n";
			cin >> novaVenda.codigoComprador;
			cout << "\nDigite o Codigo do Produto:\n";
			cin >> novaVenda.codigoProdutoVenda;
			cout << "\nDigite quantidade de litros abastecidos:\n";
			cin >> novaVenda.litrosAbastecidos;
			cout << "\nDigite status do pagamento (1= Efetuado)(0= Nao efetuado):\n";
			cin >> novaVenda.statusPagamento;

			Sell[novaVenda.codigoProdutoVenda] = novaVenda;

			cout << "\n______________________________________________________________________________________________________________\n\n";

			//Saida de venda deve seguir a sequência: Data; Cliente; Combustivel; Quantidade e Responsável;

			float totalPagar = (novaVenda.codigoProdutoVenda = novoProduto.precoProduto) * novaVenda.litrosAbastecidos;

			time_t mytime;
			mytime = time(NULL);
			struct tm tm = *localtime(&mytime);
			cout << "Data: " << tm.tm_mday << " /" << tm.tm_mon + 1 << " /" << tm.tm_year + 1900 << "\n";

			if (novoCliente.statusCadastro == 1 && novaVenda.statusPagamento == 0) {
				cout << "Cliente: " << novoCliente.nomeCliente << " 		-	STATUS: ATIVO" << "\n";
				cout << "Combustivel: " << novoProduto.nomeProduto << "	-	Quantidade: " << novaVenda.litrosAbastecidos << "\n";
				cout << "Total a pagar: " << totalPagar << "\n\n";
				cout << "OBS: O PROPRIO CLIENTE EFETUOU O ABASTECIMENTO." << "\n\n";
			}
			if (novoCliente.statusCadastro == 1 && novaVenda.statusPagamento == 1) {
				cout << "Cliente: " << novoCliente.nomeCliente << "		-	STATUS: ATIVO" << "\n";
				cout << "Combustivel:" << novoProduto.nomeProduto << " -	Quantidade:" << novaVenda.litrosAbastecidos << "\n";
				cout << "PAGAMENTO JA EFETUADO! " << "\n\n";
				cout << "OBS: O PROPRIO CLIENTE EFETUOU O ABASTECIMENTO." << "\n\n";
			}
			if (novoCliente.statusCadastro == 0 && novaVenda.statusPagamento == 0) {
				cout << "Cliente: " << novoCliente.nomeCliente << " -	STATUS: INATIVO" << "\n";
				cout << "Combustivel: " << novoProduto.nomeProduto << " 	-	Quantidade: " << novaVenda.litrosAbastecidos << "\n";
				cout << "Total a pagar: " << totalPagar << "\n\n";
				cout << "VENDA NAO AUTORIZADA. CLIENTE INATIVO. PAGAMENTO NAO EFETUADO. " << "\n\n";
				cout << "OBS: O PROPRIO CLIENTE EFETUOU O ABASTECIMENTO." << "\n\n";
			}
			if (novoCliente.statusCadastro == 0 && novaVenda.statusPagamento == 1) {
				cout << "Cliente: " << novoCliente.nomeCliente << " 		-	STATUS: INATIVO" << "\n";
				cout << "Combustivel: " << novoProduto.nomeProduto << " -	Quantidade: " << novaVenda.litrosAbastecidos << "\n";
				cout << "VENDA NAO AUTORIZADA. CLIENTE INATIVO. PAGAMENTO JA EFETUADO. " << "\n\n";
				cout << "OBS: O PROPRIO CLIENTE EFETUOU O ABASTECIMENTO." << "\n\n";
			}
			cout << "\n______________________________________________________________________________________________________________\n\n";

			system("PAUSE");
			break;
		}
		}
	} while (val != 0);
	return 0;
}
