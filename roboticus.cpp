#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <limits>

#include "termCtrl.hpp"

const int largeur = 7;
const int longueur = 7;

//struct Intello {
//	int vie = 1;
//	int dgt = 1;
//	int cout = 1;
//	int joueur = 0;
//};

//struct Surdoue {
//	int vie = 4;
//	int dgt = 4;
//	int cout = 2;
//	int joueur = 0;
//};

//struct Combattant {
//	int vie = 2;
//	int dgt = 2;
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
	int joueur = 0;
	std::string type = "          ";
};

struct Joueur {
	int vie = 10;
	int mana = 5;
	int num = 0;
};

Roboticus board[largeur][longueur];
Joueur joueur1;
Joueur joueur2;

void display() {
	std::cout<<"///|      A       |      B       |      C       |       D      |       E      |       F      |       G      |"<<std::endl;
	std::cout<<"---+--------------+--------------+--------------+--------------+--------------+--------------+--------------+"<<std::endl;
	std::cout<<" 0 | -"+board[0][0].type+"- | -"+board[0][1].type+"- | -"+board[0][2].type+"- | -"+board[0][3].type+"- | -"+board[0][4].type+"- | -"+board[0][5].type+"- | -"+board[0][6].type+"- |"<<std::endl;
	std::cout<<"---+--------------+--------------+--------------+--------------+--------------+--------------+--------------+"<<std::endl;
	std::cout<<" 1 | -"+board[1][0].type+"- | -"+board[1][1].type+"- | -"+board[1][2].type+"- | -"+board[1][3].type+"- | -"+board[1][4].type+"- | -"+board[1][5].type+"- | -"+board[1][6].type+"- |"<<std::endl;
	std::cout<<"---+--------------+--------------+--------------+--------------+--------------+--------------+--------------+"<<std::endl;
	std::cout<<" 2 | -"+board[2][0].type+"- | -"+board[2][1].type+"- | -"+board[2][2].type+"- | -"+board[2][3].type+"- | -"+board[2][4].type+"- | -"+board[2][5].type+"- | -"+board[2][6].type+"- |"<<std::endl;
	std::cout<<"---+--------------+--------------+--------------+--------------+--------------+--------------+--------------+"<<std::endl;
	std::cout<<" 3 | -"+board[3][0].type+"- | -"+board[3][1].type+"- | -"+board[3][2].type+"- | -"+board[3][3].type+"- | -"+board[3][4].type+"- | -"+board[3][5].type+"- | -"+board[3][6].type+"- |"<<std::endl;
	std::cout<<"---+--------------+--------------+--------------+--------------+--------------+--------------+--------------+"<<std::endl;
	std::cout<<" 4 | -"+board[4][0].type+"- | -"+board[4][1].type+"- | -"+board[4][2].type+"- | -"+board[4][3].type+"- | -"+board[4][4].type+"- | -"+board[4][5].type+"- | -"+board[4][6].type+"- |"<<std::endl;
	std::cout<<"---+--------------+--------------+--------------+--------------+--------------+--------------+--------------+"<<std::endl;
	std::cout<<" 5 | -"+board[5][0].type+"- | -"+board[5][1].type+"- | -"+board[5][2].type+"- | -"+board[5][3].type+"- | -"+board[5][4].type+"- | -"+board[5][5].type+"- | -"+board[5][6].type+"- |"<<std::endl;
	std::cout<<"---+--------------+--------------+--------------+--------------+--------------+--------------+--------------+"<<std::endl;
	std::cout<<" 6 | -"+board[6][0].type+"- | -"+board[6][1].type+"- | -"+board[6][2].type+"- | -"+board[6][3].type+"- | -"+board[6][4].type+"- | -"+board[6][5].type+"- | -"+board[6][6].type+"- |"<<std::endl;
	std::cout<<"---+--------------+--------------+--------------+--------------+--------------+--------------+--------------+"<<std::endl;
}

int main() {
	bool end = false;
	int joueurs[2] = {1,2};
	joueur1.num = 1;
	joueur2.num = 2;
	//int joueur1 = 10;
	//int joueur2 = 10;
	std::string color[2] = {TC_RED, TC_BLU};
	int round = 0;
	int choix = 0;
	char colonne = 'Z';
	int col = 0;
	//int points = 0;
	display();

	play:
	while (!end) {
		std::cout<< "Tour de joueur " << joueurs[round%2] <<std::endl;
		std::cout<< "Phase de placement" << std::endl;
		std::cout<<"-------------------"<< std::endl;

		do {
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

		col = int(colonne) - 65;
		if (round%2 == 0) {
			for (int i = longueur - 1; i >= 0; i--) {
            	if (board[i][col].type == "          ") {
            		if (choix == 1) {
            			board[i][col].type = color[round%2] + "  Intello " + TC_RES;
            			board[i][col].vie = 1;
            			board[i][col].dgt = 1;
            			board[i][col].cout = 1;
            			board[i][col].joueur = joueurs[round%2];
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
		else {
			for (int i = 0; i <= longueur; i++) {
            	if (board[i][col].type == "          ") {
            		if (choix == 1) {
            			board[i][col].type = color[round%2] + "  Intello " + TC_RES;
            			board[i][col].vie = 1;
            			board[i][col].dgt = 1;
            			board[i][col].cout = 1;
            			board[i][col].joueur = joueurs[round%2];
            		} else {
            			board[i][col].type = color[round%2] + "Combattant" + TC_RES;
            			board[i][col].vie = 2;
            			board[i][col].dgt = 2;
            			board[i][col].cout = 2;
            			board[i][col].joueur = joueurs[round%2];
            		}
            	    break;
            	} else if (i == longueur ) {
            	    std::cout << "La colonne est remplie\n";
            	    goto play;
            	}
        	}
		}
            display();

		std::cout<< "Phase de combat" << std::endl;
		std::cout<<"-------------------"<< std::endl;

		
		for (int i = 0; i < largeur; ++i){
			for (int j = 0; j < longueur; ++j){
				if (board[i][j].type != "          "){
					
					if (board[i][j].joueur == 1 && board[i-1][j].type == "          "){
						board[i-1][j] = board[i][j];
						board[i][j].type = "          ";
					}

					if (i == 0 && board[i][j].joueur == 1){
						joueur2.vie -= board[i][j].dgt;
						board[i][j].type = "          ";
						board[i][j].dgt = 0;
					}

				}
			}
		}

		for (int i = largeur - 1; i > largeur; ++i){
			for (int j = longueur - 1; j > 0; ++j){
				if (board[i][j].type != "          "){
					if (board[i][j].joueur == 2 && board[i+1][j].type == "          "){
						board[i+1][j] = board[i][j];
						board[i][j].type = "          ";
					}
					if (i == longueur && board[i][j].joueur == 2){
						joueur1.vie -= board[i][j].dgt;
						board[i][j].type = "          ";
						board[i][j].dgt = 0;
					}
				}
			}
		}

		std::cout << "joueur1 ";
		std::cout << joueur1.vie << std::endl;
		std::cout << "joueur2 ";
		std::cout << joueur2.vie << std::endl;
		std::cout << TC_RES;
		
		display();

		//combat
		//si 2 à coté same type fusion

		if (joueur1.vie <= 0 || joueur2.vie <= 0){
			end = true;
			break;
		}

		round++;
	}

	std::cout << "*************************************" << std::endl;
	std::cout << "Victoire de joueur " << joueurs[round%2] << std::endl;
	std::cout << "*************************************" << std::endl;

	return 0;
}