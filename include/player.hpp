#pragma once

class player{
private:
	static unsigned int allchips;
	unsigned int chipcount;
public:
	player();
	~player();
	static void upallchips();
	static int getallchips();
	void upchipcount();
	int getchipcount();
};
