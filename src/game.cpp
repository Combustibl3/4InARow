#include "game.hpp"

#define ERR 404

using namespace std;

game::game(){ // Feld mit 0en bef�llen.
    for (int i = 0; i < 42; i++){
        field[i] = 0;
    }
}

game::~game(){}

int game::emptyfield(){
    for (int i = 0; i < 42; i++){
        field[i] = 0;
    }
}

int game::getValue(int row, int column){
    return field[((row-1)* 7) + (column-1)];
}

int game::createfield() {  //Feld : 7 Breit, 6 Hoch
	cout << "  1   2   3   4   5   6   7  " << endl;
	for (int i = 0; i < 6; i++) {
		cout << "+ - + - + - + - + - + - + - +" << endl;
		for (int j = 0; j < 7; j++) {
			if (j == 0) {
				cout << "|";
			}
			cout << " ";
			if (field[(i * 7) + j] == 0) {
				cout << " ";
			}
			else if (field[(i * 7) + j] == 1) {
				cout << "X";
			}
			else if (field[(i * 7) + j] == 2) {
				cout << "O";
			}
			else { return ERR; }
			cout << " |";
		}
		cout << endl;
	}
	cout << "+ - + - + - + - + - + - + - +" << endl;
	return 0;
}

int game::check(int playerID, int y, int x) {	//Player entweder 1 oder 2 // RETURN 1 = 4 in Reihe, RETURN 0 = Nicht 4 in Reihe
	int count = 1;
	int i = 1;

	if (field[(y * 7) + x] != playerID) {
		return ERR;
	}

	//////////////////// Vertikal
	while (count < 4 && (field[(y * 7) + (x - i)] == playerID) && ((x-i) >= 0)) {
		count++;
		i++;
	}
	i = 1;
	while (count < 4 && (field[(y * 7) + (x + i)] == playerID) && ((x + i) < 7)) {
		count++;
		i++;
	}
	if (count >= 4) {
		return 1;
	}
	count = i = 1;
	//////////////////

	//////////////////// Horizontal
	while (count < 4 && (field[((y - i) * 7) + x] == playerID) && ((y - i) >= 0)) {
		count++;
		i++;
	}
	i = 1;
	while (count < 4 && (field[((y + i) * 7) + x] == playerID) && ((y + i) < 6)) {
		count++;
		i++;
	}
	if (count >= 4) {
		return 1;
	}
	count = i = 1;
	//////////////////

	//////////////////// Diagonal nach  unten links / oben rechts
	while (count < 4 && (field[((y + i) * 7) + (x - i)] == playerID) && ((x - i) >= 0) && ((y + i) < 6)) {
		count++;
		i++;
	}
	i = 1;
	while (count < 4 && (field[((y - i) * 7) + (x + i)] == playerID) && ((x + i) < 7) && ((y - i) >= 0)) {
		count++;
		i++;
	}
	if (count >= 4) {
		return 1;
	}
	count = i = 1;
	//////////////////

	//////////////////// Diagonal nach  unten rechts / oben links
	while (count < 4 && (field[((y + i) * 7) + (x + i)] == playerID) && ((x + i) < 7) && ((y + i) < 6)) {
		count++;
		i++;
	}
	i = 1;
	while (count < 4 && (field[((y - i) * 7) + (x - i)] == playerID) && ((x - i) >= 0) && ((y - i) >= 0)) {
		count++;
		i++;
	}
	if (count >= 4) {
		return 1;
	}
	count = i = 1;
	//////////////////

	return 0;
}

int game::placechip(int playerID, int x) {
	int y = 0;

	if ((x > 6) || field[x] != 0) {
		return ERR;
	}
	else {
		while ((y < 5) && field[((y+1) * 7) + x] == 0) {
			y++;
		}
		field[(y * 7) + x] = playerID;
	}
	return y;
}
