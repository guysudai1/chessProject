#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;


class Game
{
public:
	Game();
	void printGame(RenderWindow* , Tool mouseMove = Tool(-1,-2,true));
	bool setTile(int& , Tool*);
	bool move(Tool* , int&, int&);
	int size;
	Tool* getB();
	~Game();
private:
	void initTool(int , Tool);
	Tool board[64];
};
