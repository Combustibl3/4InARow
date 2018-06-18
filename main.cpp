//4InARow.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "player.hpp"
#include "game.hpp"

#define CLEAR system("cls")
#define ERR 404;

using namespace std;


int main(){
	unsigned int turnID = 2;
	unsigned int stop = 0;
	unsigned int column;

	unsigned menueinput = 0;

	game field;

	while (menueinput != 3) {
		cout << "MACH 4" << endl << "1.) Neues Spiel\n2.) Spiel laden\n3.) Programm schliessen" << endl;
		cin >> menueinput;

		if (menueinput == 1) {
            field.emptyfield();
            fflush(stdin);
			CLEAR;

			field.createfield();
			player player1;
			player player2;
			while (player::getallchips() <= 42 /*&& (stop == 0)*/) {
				column = 10;
				if (turnID == 2) {
					turnID = 1;
				}
				else if (turnID == 1) {
					turnID = 2;
				}
				CLEAR;
				while (column > 7) {          //////////NACH EINGABE VON EINER 6 IST ES WEIRD, erst nach dem Feld mit nur 0en
					field.createfield();
					cout << endl << "Spieler " << turnID << " ist dran !" << endl << "Waehle eine gueltige Spaltenzahl aus: ";
					cin >> column;

					if (field.placechip(turnID, (column-1)) == 404) {
						CLEAR;
						cout << "Diese Spalte ist ungueltig!" << endl << endl;
						column = 10;
					}

					else {
						if (turnID == 1) {
							player1.upchipcount();
						}
						else if (turnID == 2) {
							player2.upchipcount();
						}
					}
				}
			}
		}

		else if (menueinput == 2) {
			CLEAR;
		}

		else if (menueinput == 3) {
			CLEAR;
			cout << "Programm beendet" << endl;
		}

		else { CLEAR; }
	}
    return 0;
}
