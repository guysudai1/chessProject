#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;
class Tool
{
public:
	Tool();
	Tool(int,int, bool );
	
	~Tool();
	char getName();
	int getId();
	int getPosMoves();
	bool getSide();
	
private:
	int id;
	bool side; // true means he's black
	int name;
	int value;
};
