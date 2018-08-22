#include <iostream>
#include <string>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <Windows.h>
#include "Tool.h"
#include "Game.h"

using namespace sf;
using namespace std;

string toLower(string b) {
	string newS;
	for (int i = 0; i < b.length(); i++) {
		if (b[i] >= 'A' && b[i] <= 'Z') {
			newS[i] = b[i] + ('a' - 'A');
		}
		else {
			newS[i] = b[i];
		}
	}
	return newS;
}
Tool::Tool() : Tool(-1, -1, false) {}
Tool::Tool(int name, int id, bool side) {
	this->id = id;
	this->name = name;
	switch (name) {
		/*

		name list:
		0 - pawn
		1 - knight
		2 - bishop
		3 - rook
		4 - queen
		5 - king
		*/
	case 0:
		this->value = 1;
		break;
	case 1:
		this->value = 3;
		break;
	case 2:
		this->value = 3;
		break;
	case 3:
		this->value = 5;
		break;
	case 4:
		this->value = 9;
		break;
	case 5:
		this->value = -1;
		break;
	default:
		this->value = 0;
		break;
	}

	this->side = side;
}
int Tool::getId() { return id; }
Tool::~Tool()
{
}
char Tool::getName() {
	return name;
}

int Tool::getPosMoves() {
	// returns how many possible moves the troop has
	int sum = 0;
	switch (this->name) {
	case 0:
		break;
	}
	return sum;
}
void Game::initTool(int place, Tool whatT) {
	this->board[place] = whatT;
}
Game::Game()
{
	string side;
	// TODO
	bool sid = false; // if sid is true you're black
	if (toLower(side) != "white") {
		sid = false;
	}
	//this->initTool(1, 1, Tool(3, !sid));
	for (int i = 0; i < 16; i++) {
		int ToolId = 0;

		if ((i / 8) >= 1) {
			ToolId = 0;
		}
		else if (i == 0 || i == 7) {
			ToolId = 3;
		}
		else if (i == 1 || i == 6) {
			ToolId = 1;
		}
		else if (i == 2 || i == 5) {
			ToolId = 2;
		}
		else if (i == 3) {
			ToolId = 4;
		}
		else {
			ToolId = 5;
		}
		if (i < 8) {
			this->initTool((i * 8), Tool(ToolId, i, !sid));
		}
		else {
			this->initTool((i - 8) * 8 + 1, Tool(ToolId, i, !sid));
		}

	}
	for (int i = 16; i < 32; i++) {
		int ToolId = 0;

		if ((i / 8) >= 1) {
			ToolId = 0;
		}
		else if (i == 0 || i == 7) {
			ToolId = 3;
		}
		else if (i == 1 || i == 6) {
			ToolId = 1;
		}
		else if (i == 2 || i == 5) {
			ToolId = 2;
		}
		else if (i == 3) {
			ToolId = 4;
		}
		else {
			ToolId = 5;
		}
		if (i < 16 + 8) {
			this->initTool((i - 16) * 8 + 6, Tool(ToolId, i, sid));
		}
		else {
			this->initTool((i - 16) * 8 + 7, Tool(ToolId, i, sid));
		}

	}
}
bool Tool::getSide() {
	return this->side;
}
Tool* Game::getB() {
	Tool tmpBrd[64];
	for (int i = 0; i < 64; i++) {
		tmpBrd[i] = board[i];
	}
	return tmpBrd;
}
Game::~Game()
{
}
void Game::printGame(RenderWindow* window, Tool notSHOW) {
	Texture white;
	white.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\white.bmp");
	Texture black;
	black.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\black.bmp");
	white.setSmooth(true);
	black.setSmooth(true);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {


			Sprite sp;
			if ((i + j) % 2 == 0) {
				sp.setTexture(white);
			}
			else {
				sp.setTexture(black);
			}


			FloatRect rec = sp.getGlobalBounds();

			sp.scale(window->getSize().x / 8 / rec.width, window->getSize().y / 8 / rec.height); // fitting the cube in the board

			rec = sp.getGlobalBounds(); // getting new size of sprite

			sp.setPosition(i * rec.height, j * rec.width); // setting the position of the sprite

			window->draw(sp);

			Tool thisT = this->board[j + (i * 8)];
			if (thisT.getId() != notSHOW.getId()) {
				Texture txt;
				if (thisT.getSide()) {
					switch (thisT.getName()) {
					case 0:
						txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blackPawn.png");

						break;
					case 1:
						txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blackKnight.png");
						break;
					case 2:
						txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blackBishop.png");
						break;
					case 3:
						txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blackRook.png");
						break;
					case 4:
						txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blackQueen.png");
						break;
					case 5:
						txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blackKing.png");
						break;
					default:
						txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blank.png");
						break;
					}
				}
				else {
					switch (thisT.getName()) {
					case 0:
						txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\whitePawn.png");
						break;
					case 1:
						txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\whiteKnight.png");
						break;
					case 2:
						txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\whiteBishop.png");
						break;
					case 3:
						txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\whiteRook.png");
						break;
					case 4:
						txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\whiteQueen.png");
						break;
					case 5:
						txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\whiteKing.png");
						break;
					default:
						txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blank.png");
						break;
					}
				}
				txt.setSmooth(true);
				Sprite tool(txt);
				FloatRect toolRec = tool.getGlobalBounds();

				tool.setScale(window->getSize().x / 8 / toolRec.width, window->getSize().y / 8 / toolRec.height);
				toolRec = tool.getGlobalBounds();
				this->size = toolRec.width;
				tool.setPosition(i * toolRec.height, toolRec.width * j);

				window->draw(tool); // drawing the sprite
			}



		}
	}

}
bool Game::setTile(int& index, Tool* whatPlace) {
	this->board[index] = *whatPlace;
	return true;

}





int main() {
	RenderWindow input(VideoMode(100, 50), "Pick your side");
	Game chessGame;
	RenderWindow wnd(VideoMode(700, 700), "Chess Game");
	wnd.setVerticalSyncEnabled(false);
	Tool moveMouse = Tool(-1, -2, true);
	bool isMove = false;
	Music m;
	m.openFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\moveTool.ogg");
	m.setRelativeToListener(true);
	m.setPitch(0.95f);
	Mouse myM;
	int mouseBefore = 0;
	while (wnd.isOpen()) {

		Event event;
		while (wnd.pollEvent(event))
		{
			switch (event.type) {
			case Event::Closed:
				wnd.close();
				break;
			case Event::MouseButtonPressed:
				Vector2i mouseP = myM.getPosition(wnd);
				Tool mouseOn = chessGame.getB()[(mouseP.x / chessGame.size) * 8 + ((mouseP.y / chessGame.size))];

				if (moveMouse.getName() != -1) {
					if (isMove) {
						Vector2i locAr((mouseP.x / chessGame.size) * 8, (mouseP.y / chessGame.size));
						int s = (locAr.x + locAr.y);
						if (chessGame.setTile(s, &moveMouse)) {
							if (mouseBefore != s) {
								chessGame.setTile(mouseBefore, &Tool(-1, -2, true));
							}

							moveMouse = Tool(-1, -2, true);
							isMove = false;
							if (m.getStatus() == SoundSource::Status::Playing) {
								m.stop();
							}
							m.play();

						}
					}
					else {
						isMove = true;
					}
				}
				else {

					if (mouseOn.getName() != -1) {
						mouseBefore = (mouseP.x / chessGame.size) * 8 + ((mouseP.y / chessGame.size));
						moveMouse = mouseOn;
						isMove = true;
					}
				}

				break;
			}

		}
		if (!isMove) {
			wnd.clear();
			chessGame.printGame(&wnd);
			wnd.display();
		}

		if (isMove) {
			Vector2i mouseP = myM.getPosition(wnd);
			Texture txt;
			if (moveMouse.getSide()) {
				switch (moveMouse.getName()) {
				case 0:
					txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blackPawn.png");
					break;
				case 1:
					txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blackKnight.png");
					break;
				case 2:
					txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blackBishop.png");
					break;
				case 3:
					txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blackRook.png");
					break;
				case 4:
					txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blackQueen.png");
					break;
				case 5:
					txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blackKing.png");
					break;
				default:
					txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blank.png");
					break;
				}
			}
			else {
				switch (moveMouse.getName()) {
				case 0:
					txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\whitePawn.png");
					break;
				case 1:
					txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\whiteKnight.png");
					break;
				case 2:
					txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\whiteBishop.png");
					break;
				case 3:
					txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\whiteRook.png");
					break;
				case 4:
					txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\whiteQueen.png");
					break;
				case 5:
					txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\whiteKing.png");
					break;
				default:
					txt.loadFromFile("C:\\Users\\GUY\\Desktop\\code\\chess\\Project1\\resources\\blank.png");
					break;
				}
			}
			Sprite sp(txt);
			FloatRect toolRec = sp.getGlobalBounds();
			txt.setSmooth(true);
			sp.setScale(wnd.getSize().x / 8 / toolRec.width, wnd.getSize().y / 8 / toolRec.height);
			toolRec = sp.getGlobalBounds();
			sp.setPosition(mouseP.x - (toolRec.height / 2), mouseP.y - (toolRec.width / 2));
			wnd.clear();
			chessGame.printGame(&wnd, moveMouse);
			wnd.draw(sp);

			wnd.display();
		}
	}

	string v;
	return 0;
}