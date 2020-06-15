
#include "BlocksGenerator.h"
#include "PlayField.h"
#include "GameController.h"
#include "GameMusic.h"
#include "GameSounds.h"
#include "Menu.h"
#include "Textures.h"
#include <iostream>
#include "Defines.h"



int main()
{
	srand(time(NULL));
	Timer Timer;
	sf::Clock clock;
	sf::RenderWindow window;
	sf::VideoMode VMode(WIDTH_WINDOW, HEIGHT_WINDOW, 32);
	window.create(VMode, NAME_OF_GAME, sf::Style::Close);
	Textures tilesTexture(TILES_PATH);
	Textures background(BACKGROUND_PATH);
	Textures frame_pion(FRAME_PION_PATH);
	frame_pion.setPositionOfSprite(315, 0);
	Textures frame_poziom(FRAME_POZIOM_PATH);
	frame_poziom.setPositionOfSprite(0, 635);
	Textures menu_background(MENU_PATH);
	Textures top5_background(TOP5_PATH);
	GameMusic _gameMusic;
	GameSounds _gameSounds;
	TextPoppingUp _textmsg;
	Level _level;
	Scoreboard _scoreboard;
	Top5Scores _top5(WIDTH_WINDOW, HEIGHT_WINDOW);
	Menu _menu(WIDTH_WINDOW, HEIGHT_WINDOW);
	window.setFramerateLimit(15);
	sf::Event event;
	GameController gameController(BlocksGenerator(0, 0), PlayField());

	while (window.isOpen())
	{
		try
		{
			if (_menu.getTheStateOfEnter()) {
				if (!_gameMusic.getTheStateOfPlayMusic() || _gameMusic.getMusicString() == "Game")
				{
					_gameMusic.inMenuMusic();
				}
				window.clear();
				menu_background.Draw(window);
				_menu.draw(window);
				_menu.MenuController(window);
				window.display();
			}
			if (_menu.getChoicedItemIndex() == 0)
			{
				if (!_gameMusic.getTheStateOfPlayMusic() || _gameMusic.getMusicString() == "Menu")
				{
					_gameMusic.inGameMusic();
				}
				gameController.Tick(clock, Timer, event, window, _gameMusic, _gameSounds, _textmsg, _level, _scoreboard, _top5, _menu, gameController);

				window.pollEvent(event);
				window.clear(sf::Color::Black);
				background.Draw(window);
				_level.levelDraw(window);
				_scoreboard.Draw(window);
				for (int i = 0; i < 4; i++)
				{
					Tile tile = gameController.GetCurrentBlock().GetTile(i);
					tilesTexture.setTextureRectangle(tile.GetColor() * COLOR_MULTIPLIER, 0, TILES_PIXEL_COUNT, TILES_PIXEL_COUNT);
					tilesTexture.setPositionOfSprite(tile.GetX() * TILES_PIXEL_COUNT, tile.GetY() * TILES_PIXEL_COUNT);
					tilesTexture.Draw(window);
				}

				for (int i = 0; i < WIDTH; i++)
				{
					for (int j = 0; j < HEIGHT; j++)
					{
						Tile tile = gameController.GetPlayField().GetTile(i, j);
						tilesTexture.setTextureRectangle(tile.GetColor() * COLOR_MULTIPLIER, 0, TILES_PIXEL_COUNT, TILES_PIXEL_COUNT);
						tilesTexture.setPositionOfSprite(tile.GetX() * TILES_PIXEL_COUNT, tile.GetY() * TILES_PIXEL_COUNT);
						tilesTexture.Draw(window);
					}
				}
				frame_poziom.Draw(window);
				frame_pion.Draw(window);
				window.display();
			}
			else if (_menu.getChoicedItemIndex() == 1)
			{
				window.clear();
				top5_background.Draw(window);
				_top5.changeTheStateOfDisplayHigscores(Bollean::True);
				_top5.scoresWindowController(window, _menu);
				_top5.draw(window);
				window.display();
			}
		}
		catch(const std::exception & e)
		{
			std::cout << "catched exception: ";
			std::cout << e.what();
		}
	}
	return 0;
}


/*******************TO DO****************************
* X | ZAIMPLEMENTOWAC POZIOMY CO 3 ULOZONE LINIJEK  *
* X | ZROBIC BACKGROUND W GIMPIE d-_-b				*
* X | DODAC SOUNDS									*
* X | DODAC GAMEOVER								*
* X | MUZYKA W MENU I HIGHSCORES					*
* X | BACKGROUND HIGHSCORES							*
* X | RESTART PLAYGROUNDU PO PRZEGRANEJ(I KONIEC)	*
*********************ZAAWANSOWANE********************
* X | NAPRAWIC WYSWIETLANIE SCORE I POZIOM			*
* X | MENU											*
* X | HIGHHSCORES									*
****************************************************/