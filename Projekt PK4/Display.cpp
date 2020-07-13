#include "Display.h"

Display::Display()
{
	sf::VideoMode VMode(WIDTH_WINDOW, HEIGHT_WINDOW, 32);
	window.create(VMode, NAME_OF_GAME, sf::Style::Close);
	window.setFramerateLimit(15);
}
Display::Display(Textures tab[],  GameController &gameController) {
	sf::VideoMode VMode(WIDTH_WINDOW, HEIGHT_WINDOW, 32);
	window.create(VMode, NAME_OF_GAME, sf::Style::Close);
	window.setFramerateLimit(15);
	for (int i = 0; i < NUMBER_OF_TEXTURES; i++) {
		allTextures[i] = tab[i];
	}
	_gamecontroller = gameController;
}
bool Display::checkIfWindowIsOpen()
{
	return window.isOpen();
}

void Display::displayMenu ()
{
	window.clear();
	MENU_BACKGROUND_TEXTURE.Draw(window);
	this->getMenu().draw(window);
	this->getMenu().MenuController(window);
	window.display();
}

sf::RenderWindow * Display::getWindow()
{
	return &window;
}

void Display::displayGame()
{
	sf::Event e;
	_gamecontroller.Tick(this->getWindow(),gamemusicc, _top5, menu);
	window.pollEvent(e);
	window.clear(sf::Color::Black);
	BACKGROUND_TEXTURE.Draw(window);
	_gamecontroller.getScoreboard().getLevel().levelDraw(window);
	_gamecontroller.getScoreboard().Draw(window);
	for (int i = 0; i < 4; i++)
	{
		Tile tile = _gamecontroller.GetCurrentBlock().GetTile(i);
		TILES_TEXTURE.setTextureRectangle(tile.GetColor() * COLOR_MULTIPLIER, 0, TILES_PIXEL_COUNT, TILES_PIXEL_COUNT);
		TILES_TEXTURE.setPositionOfSprite(tile.GetX() * TILES_PIXEL_COUNT, tile.GetY() * TILES_PIXEL_COUNT);
		TILES_TEXTURE.Draw(window);
	}

	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < HEIGHT; j++)
		{
			Tile tile = _gamecontroller.GetPlayField().GetTile(i, j);
			TILES_TEXTURE.setTextureRectangle(tile.GetColor() * COLOR_MULTIPLIER, 0, TILES_PIXEL_COUNT, TILES_PIXEL_COUNT);
			TILES_TEXTURE.setPositionOfSprite(tile.GetX() * TILES_PIXEL_COUNT, tile.GetY() * TILES_PIXEL_COUNT);
			TILES_TEXTURE.Draw(window);
		}
	}
	FRAME_POZIOM_TEXTURE.Draw(window);
	FRAME_PION_TEXTURE.Draw(window);
	window.display();
}

void Display::displayScores()
{
	window.clear();
	TOP5_BACKGROUND_TEXTURE.Draw(window);
	this->getTop5Scores().changeTheStateOfDisplayHigscores(Bollean::True);
	this->getTop5Scores().scoresWindowController(window, this->getMenu());
	this->getTop5Scores().draw(window);
	window.display();
}