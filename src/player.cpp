#include "player.hpp"

unsigned int player::allchips = 0;

player::player() : chipcount(0){}

player::~player(){}

void player::upallchips() {
	allchips++;
}

int player::getallchips() {
	return allchips;
}

void player::upchipcount() {
	chipcount++;
	allchips++;
}

int player::getchipcount() {
	return chipcount;
}

