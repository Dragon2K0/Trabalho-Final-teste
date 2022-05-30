#include <iostream>
#include <map>
#include <random>
#include <time.h>
#include <iterator>
using namespace std;

typedef struct Music {
	int key;
	string Name;
	string Singer;
	string Album;
	string Duration;

} Music;

int main() {
	Music NewMusic;
	srand(time(0));
	map<int, Music> Single;

	int cont = 0;

	NewMusic.key = rand() % 100 + 1;
	NewMusic.Name = "Something About You?";
	NewMusic.Album = "Something About You? ";
	NewMusic.Singer = "Olivia Rodrigo";
	NewMusic.Duration = "3:10";

	Single[NewMusic.key] = NewMusic;

	/*cout << "Musica Cadastrada: "
	<< Single[NewMusic.key].key
	<< " " << Single[NewMusic.key].Name
	<< " " << Single[NewMusic.key].Singer
	<< " " << Single[NewMusic.key].Album
	<< " " << Single[NewMusic.key].Duration << endl;*/

	NewMusic.key = rand() % 100 + 1;
	NewMusic.Name = "Devil";
	NewMusic.Album = "Devil";
	NewMusic.Singer = "Two Feet";
	NewMusic.Duration = "3:57";

	Single[NewMusic.key] = NewMusic;

	NewMusic.key = rand() % 100 + 1;
	NewMusic.Name = "Sleepless";
	NewMusic.Album = "Sleepless";
	NewMusic.Singer = "Nothing But Thieves";
	NewMusic.Duration = "3:45";

	Single[NewMusic.key] = NewMusic;

	NewMusic.key = rand() % 100 + 1;
	NewMusic.Name = "Four";
	NewMusic.Album = "Four";
	NewMusic.Singer = "Jhin";
	NewMusic.Duration = "4:44";

	Single[NewMusic.key] = NewMusic;

	map<int, Music>::iterator it = Single.begin();

	int val=0;
	int keyFind = 0;

	do {
		system("CLS");

		cout << "\nSelecione uma opcao : \n";
		cout << "\n[1] = Adicionar Musica.\n";
		cout << "\n[2] = Visualizar musicas cadastradas.\n";
		cout << "\n[3] = Apagar musica.\n";
		cout << "\n[0] = Sair.\n\n";
		cin >> val;

		switch (val) {

		case 1:{
			system("CLS");

			cout << "\nDigite o Nome da musica:\n";
			cin >> NewMusic.Name;
			cout << "\nDigite o nome do album;\n";
			cin >> NewMusic.Album;
			cout << "\nDigite o nome do cantor(a):\n";
			cin >> NewMusic.Singer;
			cout << "\nDigite a duracao da musica:\n";
			cin >> NewMusic.Duration;
			NewMusic.key = rand() % 100 + 1;

			Single[NewMusic.key] = NewMusic;

			system("PAUSE");
			break;
		}

		case 2:{
			system("CLS");

			map<int, Music>::iterator it = Single.begin();

			cout << "\n______________________________________________________________________________________________________________\n";

			while (it != Single.end()) {
				int key = it->first;
				Music song = it->second;

				cout << "\nMusica Cadastrada: "
					<< " " << "Codigo: " << song.key
					<< " - " << song.Name
					<< " - " << song.Singer
					<< " - " << song.Album
					<< " - " << song.Duration << endl;
				it++;
			}

			cout << "\n______________________________________________________________________________________________________________\n\n\n\n";


			system("PAUSE");
			break;
		}

		case 3: {

			system("CLS");

			map<int, Music>::iterator it = Single.begin();

			cout << "\n______________________________________________________________________________________________________________\n";

			while (it != Single.end()) {
				int key = it->first;
				Music song = it->second;

				cout << "\nMusica Cadastrada: "
					<< " " << "Codigo: " << song.key
					<< " - " << song.Name
					<< " - " << song.Singer
					<< " - " << song.Album
					<< " - " << song.Duration << endl;
				it++;
			}

			cout << "\n______________________________________________________________________________________________________________\n\n";

			cout << "\nDigite o codigo da musica que deseja remover:";
			cin >> keyFind;
			break;
		}
		}	
	} while (val != 0);
	return 0;
}