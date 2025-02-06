#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <limits>

#include "termCtrl.hpp"

const int x = 7;
const int y = 7;

//struct Surdoue {
//	int vie = 4;
//	int dgt = 4;
//	int cout = 2;
//	int joueur = 0;
//};

//struct Warrior {
//	int vie = 5;
//	int dgt = 5;
//	int cout = 3;
//	int joueur = 0;
//};

struct Roboticus {
	int vie = 0;
	int dgt = 0;
	int cout = 0;
	int joueur = -1;
	std::string type = "          ";
	bool moved = false;
};

struct Joueur {
	int vie = 10;
	int mana = 5;
	int num = 0;
};

Roboticus board[x][y];
Joueur joueur1;
Joueur joueur2;

void display() {
	//*****************
	// display colonnes
	//*****************
	std::cout << "////|";
	for (int i = 0; i < x; ++i)	{
		std::cout << "      " << (char)(i + 65) << "       |";
	}
	std::cout<<"\n";
	//*****************
	// display lignes
	//*****************
	for (int i = 0; i < x; ++i)	{
		std::cout << "----+";
		for (int i = 0; i < x; ++i)	{
			std::cout << "--------------+";
		}
		std::cout << "\n";
		printf(" %02d |", i);
		for (int j = 0; j < y; ++j) {
			std::cout << " -" << board[i][j].type << "- |";
		}
		std::cout << "\n";
	}
	std::cout << "----+";
	for (int i = 0; i < x; ++i)	{
		std::cout << "--------------+";
	}
	std::cout << "\n";
}

int main() {
	bool end = false;
	int joueurs[2] = {0,1};
	joueur1.num = 1;
	joueur2.num = 2;
	std::string color[2] = {TC_RED, TC_BLU};
	int round = 0;
	int choix = 0;
	char colonne = 'Z';
	int col = 0;
	display();

	play:
	//***************************
	// Boucle de jeu
	//***************************
	while (!end) {
		std::cout << "Tour de joueur " << joueurs[round%2] + 1 << std::endl;
		std::cout << "Phase de placement" << std::endl;
		std::cout << "-------------------" << std::endl;

		do {
			//***************************
			//Menu de choix
			//***************************
			std::cout << color[round%2];
			std::cout << "Choix :" << std::endl;
			std::cout << "- 1 : Intello" << std::endl;
			std::cout << "- 2 : Combattant" << std::endl;
		    std::cin >> choix;
		    if (std::cin.fail()) {
        		std::cin.clear();
        		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        		choix = -1;
        	}
        	std::cout << TC_RES;
		} while (choix < 1 || choix > 2);

		std::cout << color[round%2];
		std::cout << "Choix de la colonne :" << std::endl;
		std::cin >> colonne;
        colonne = toupper(colonne);

        while (int(colonne) < 65 || int(colonne) > 71) {
            std::cout << "Choix non valide\n";
            std::cout << "Choix de la colonne : ";
            std::cin >> colonne;
            colonne = toupper(colonne);
        }
		std::cout << TC_RES;

		//***************************
		//Gestion pose troupe j2
		//***************************
		col = int(colonne) - 65;
		if (round%2 == 0) {
			for (int i = y - 1; i >= 0; --i) {
            	if (board[i][col].type == "          ") {
            		if (choix == 1) {
            			board[i][col].type = color[round%2] + "  Intello " + TC_RES;
            			board[i][col].vie = 1;
            			board[i][col].dgt = 1;
            			board[i][col].cout = 1;
            			board[i][col].joueur = joueurs[round%2];
            			printf("piece à %d\n", board[i][col].joueur);
            		} else {
            			board[i][col].type = color[round%2] + "Combattant" + TC_RES;
            			board[i][col].vie = 2;
            			board[i][col].dgt = 2;
            			board[i][col].cout = 2;
            			board[i][col].joueur = joueurs[round%2];
            		}
            	    break;
            	} else if (i == 0 ) {
            	    std::cout << "La colonne est remplie\n";
            	    goto play;
            	}
        	}
		}
		//***************************
		//Gestion pose troupe j1
		//***************************
		else {
			for (int i = 0; i <= y; ++i) {
            	if (board[i][col].type == "          ") {
            		if (choix == 1) {
            			board[i][col].type = color[round%2] + "  Intello " + TC_RES;
            			board[i][col].vie = 1;
            			board[i][col].dgt = 1;
            			board[i][col].cout = 1;
            			board[i][col].joueur = joueurs[round%2];
            			printf("piece à %d\n", board[i][col].joueur);
            		} else {
            			board[i][col].type = color[round%2] + "Combattant" + TC_RES;
            			board[i][col].vie = 2;
            			board[i][col].dgt = 2;
            			board[i][col].cout = 2;
            			board[i][col].joueur = joueurs[round%2];
            		}
            	    break;
            	} else if (i == y ) {
            	    std::cout << "La colonne est remplie\n";
            	    goto play;
            	}
        	}
		}
            display();

		std::cout<< "Phase de combat" << std::endl;
		std::cout<< "-------------------" << std::endl;
		
		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				if (board[i][j].type != "          " && board[i][j].joueur == 0) {

					//***************************
					//Gestion vie et degat j1
					//***************************
					if (i == 0 && board[i][j].joueur == 0) {
						printf("dgt j1\n");
						joueur2.vie -= board[i][j].dgt;
						board[i][j].type = "          ";
						board[i][j].dgt = 0;
						board[i][j].joueur = -1;
					}

					//***************************
					// Gestion combat j1
					//***************************
					if (board[i][j].dgt >= board[i - 1][j].vie) {
						printf("fight j1\n");
						board[i - 1][j].type = "          ";
						board[i - 1][j].vie = 0;
						board[i - 1][j].joueur = -1;
					} else if (board[i - 1][j].dgt > board[i][j].vie) {
						printf("defaite j1\n");
						board[i][j].type = "          ";
						board[i][j].vie = 0;
						board[i][j].joueur = -1;
						board[i][j].moved = true;
					} else if (board[i][j].dgt == board[i - 1][j].vie && board[i - 1][j].dgt == board[i][j].vie) {
						printf("equality j1\n");
						board[i][j].type = "          ";
						board[i][j].vie = 0;
						board[i][j].joueur = -1;
						board[i][j].moved = true;
						board[i - 1][j].type = "          ";
						board[i - 1][j].vie = 0;
						board[i - 1][j].joueur = -1;
						board[i - 1][j].moved = true;
					}
					
					//***************************
					//Gestion déplacement j1
					//***************************
					if (board[i][j].joueur == 0 && board[i - 1][j].type == "          " && board[i][j].moved == false) {
						printf("move j1\n");
						board[i - 1][j] = board[i][j];
						board[i][j].type = "          ";
						board[i][j].joueur = -1;
						board[i][j].moved = true;
					}


				} else if (board[i][j].type != "          " && board[i][j].joueur == 1) {

					//***************************
					// Gestion dgt et vie j2
					//***************************
					if (i == y - 1 && board[i][j].joueur == 1 && board[i][j].moved == false) {
						printf("dgt j2\n");
						joueur1.vie -= board[i][j].dgt;
						board[i][j].type = "          ";
						board[i][j].dgt = 0;
						board[i][j].joueur = -1;
						board[i][j].moved = true;
					}

					//***************************
					// Gestion combat j2
					//***************************
					if (board[i][j].dgt >= board[i + 1][j].vie && board[i][j].moved == false) {
						printf("fight j2\n");
						board[i + 1][j].type = "          ";
						board[i + 1][j].vie = 0;
						board[i + 1][j].joueur = -1;
						board[i + 1][j].moved = true;
					} else if (board[i + 1][j].dgt > board[i][j].vie) {
						printf("defaite j2\n");
						board[i][j].type = "          ";
						board[i][j].vie = 0;
						board[i][j].joueur = -1;
						board[i][j].moved = true;
					} else if (board[i][j].dgt == board[i + 1][j].vie && board[i + 1][j].dgt == board[i][j].vie) {
						printf("equality j2\n");
						board[i][j].type = "          ";
						board[i][j].vie = 0;
						board[i][j].joueur = -1;
						board[i][j].moved = true;
						board[i + 1][j].type = "          ";
						board[i + 1][j].vie = 0;
						board[i + 1][j].joueur = -1;
						board[i + 1][j].moved = true;
					}

					//***************************
					// Gestion deplacement j2
					//***************************
					if (board[i][j].joueur == 1 && board[i + 1][j].type == "          " && board[i][j].moved == false) {
						printf("move j2\n");
						board[i + 1][j] = board[i][j];
						board[i + 1][j].moved = true;
						board[i][j].type = "          ";
						board[i][j].joueur = -1;
					}
				}
			}
		}

		std::cout << "joueur1 : ";
		std::cout << joueur1.vie << std::endl;
		std::cout << "joueur2 : ";
		std::cout << joueur2.vie << std::endl;
		std::cout << TC_RES;

		round++;

		for (int i = 0; i < x; ++i) {
			for (int j = 0; j < y; ++j) {
				printf("cleared moved\n");
				board[i][j].moved = false;
			}
		}

		display();

		//fix combat
		//refacto
		//si 2 à coté same type fusion

		//***************************
		//Gestion victoire
		//***************************
		if (joueur1.vie <= 0 || joueur2.vie <= 0) {
			end = true;
			break;
		}

	}

	std::cout << "*************************************" << std::endl;
	std::cout << "Victoire de joueur " << joueurs[round%2] << std::endl;
	std::cout << "*************************************" << std::endl;

	return 0;
}