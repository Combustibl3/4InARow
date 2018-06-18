//4InARow.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "player.hpp"
#include "game.hpp"

#define CLEAR system("cls")
#define ERR 404

using namespace std;


int main(){
	unsigned int turnID = 2;
	unsigned int stop;
	unsigned int row = 0;
	string column;
    string menueinput = "0";

	game field;

	while (menueinput != "3") {
		cout << "MACH 4" << endl << "1.) Neues Spiel\n2.) Spiel laden\n3.) Programm schliessen" << endl;
		cin >> menueinput;

		if (menueinput == "1") { //Neues Spiel wird gestartet
            field.emptyfield(); //Das Spielfeld wird geleert
			CLEAR;              //Konsole wird geleert

			stop = 0;
			field.createfield();
			player player1;
			player player2;

			while (player::getallchips() <= 42 && (stop == 0)) {
				column = "0";
				if (turnID == 2) {
					turnID = 1;
				}
				else if (turnID == 1) {
					turnID = 2;
				}
				CLEAR;
				while (column == "0") {
					field.createfield();
					cout << endl << "Spieler " << turnID << " ist dran !" << endl << "Waehle eine gueltige Spaltenzahl aus: ";
					cin >> column;

					row = field.placechip(turnID, column);
					if (row == ERR) {
						CLEAR;
						cout << "Diese Spalte ist ungueltig!" << endl << endl;
						column = "0";
					}

					else {
						if (turnID == 1) {
							player1.upchipcount();
						}
						else if (turnID == 2) {
							player2.upchipcount();
						}
						/*if (field.check(turnID, row, column) == 1){ //Funktionierender check
                            stop = 1;
						}*/
					}
				}
			}
		}

		else if (menueinput == "2") {
			CLEAR;
		}

		else if (menueinput == "3") {
			CLEAR;
			cout << "Programm beendet" << endl;
		}

		else { CLEAR; }
	}
    return 0;
}
