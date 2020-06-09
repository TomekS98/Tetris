
#include "BlocksGenerator.h"
#include "PlayField.h"
#include "GameController.h"
#include "Scoreboard.h"
#include "GameMusic.h"
#include "GameSounds.h"
#include "Menu.h"
#include <iostream>
#include <SFML/Audio.hpp>
const int TILES_PIXEL_COUNT = 32;
const int COLOR_MULTIPLIER = 32;


int main()
{
	srand(time(NULL));
	Timer Timer;
	sf::Clock clock;
	sf::RenderWindow window;
	sf::VideoMode VMode(WIDTH * TILES_PIXEL_COUNT + 180, HEIGHT * TILES_PIXEL_COUNT+100, 32);
	window.create(VMode, "Tetris", sf::Style::Close);


	sf::Color gray_color(211, 211, 211);
	sf::Texture tilesTexture;
	if (!tilesTexture.loadFromFile("images/tiles.png"))
	{
		return -1;
	}
	sf::Sprite tilesSprite = sf::Sprite(tilesTexture);
	tilesSprite.setTextureRect(sf::IntRect(0, 0, TILES_PIXEL_COUNT, TILES_PIXEL_COUNT));

	sf::Texture background;
	if (!background.loadFromFile("images/tetrisbackground.png"))
	{
		return -1;
	}
	sf::Sprite s_background(background);
	sf::Texture frame_pion;
	if (!frame_pion.loadFromFile("images/frame_pion.png"))
	{
		return -1;
	}
	sf::Texture frame_poziom;
	if (!frame_poziom.loadFromFile("images/frame_poziom.png"))
	{
		return -1;
	}
	sf::Sprite s_frame_poziom = sf::Sprite(frame_poziom);
	sf::Sprite s_frame_pion = sf::Sprite(frame_pion);
	sf::Texture menu_background;
	if (!menu_background.loadFromFile("images/menu_background1.png"))
	{
		return -1;
	}
	sf::Sprite s_menu_background= sf::Sprite(menu_background);
	sf::Texture top5_background;
	if (!top5_background.loadFromFile("images/top5_background.png"))
	{
		return -1;
	}
	sf::Sprite s_top5_background = sf::Sprite(top5_background);
	s_frame_pion.setPosition(315, 0);
	s_frame_poziom.setPosition(0, 635);
	sf::Font _font;
	if (!_font.loadFromFile("fonts/font.ttf"))
	{
		return -1;
	}
	GameMusic _gameMusic;

	GameSounds _gameSounds;
	TextPoppingUp _textmsg(_font);
	Level _level(_font);
	Scoreboard _scoreboard(_font);
	Top5Scores _top5(500,740);
	Menu _menu(500, 740);
	
	sf::Text levelDisplayREPLACEMENT;
	levelDisplayREPLACEMENT.setFont(_font);
	levelDisplayREPLACEMENT.setString(_level.getlevelmsg());
	levelDisplayREPLACEMENT.setCharacterSize(52);
	levelDisplayREPLACEMENT.setFillColor(gray_color);
	levelDisplayREPLACEMENT.setPosition(380, 185);

	sf::Text scoreboardDisplayREPLACEMENT;
	scoreboardDisplayREPLACEMENT.setFont(_font);
	scoreboardDisplayREPLACEMENT.setString(_scoreboard.getscoremsg());
	scoreboardDisplayREPLACEMENT.setCharacterSize(52);
	scoreboardDisplayREPLACEMENT.setFillColor(gray_color);
	scoreboardDisplayREPLACEMENT.setPosition(370, 65);

	window.setFramerateLimit(15);


	sf::Event event;
	GameController gameController(BlocksGenerator(0, 0), PlayField());

	while (window.isOpen())
	{
		if (_menu.getTheStateOfEnter()) {
			if (!_gameMusic.getTheStateOfPlayMusic() || _gameMusic.getMusicString() == "Game")
			{
				_gameMusic.inMenuMusic();
			}
			window.clear();
			window.draw(s_menu_background);
			_menu.draw(window);
			_menu.MenuController(window);
			window.display();
		}
		if (_menu.getChoicedItemIndex() == 0)
		{
			if (!_gameMusic.getTheStateOfPlayMusic()|| _gameMusic.getMusicString()=="Menu")
			{
				_gameMusic.inGameMusic();
			}
			gameController.Tick(clock, Timer, event, window, _gameMusic, _gameSounds, _textmsg, _level, _scoreboard, _top5, _menu, gameController);

			window.pollEvent(event);
			window.clear(sf::Color::Black);
			window.draw(s_background);
			levelDisplayREPLACEMENT.setString(_level.getlevelmsg());
			scoreboardDisplayREPLACEMENT.setString(_scoreboard.getscoremsg());
			window.draw(levelDisplayREPLACEMENT);
			window.draw(scoreboardDisplayREPLACEMENT);
			for (int i = 0; i < 4; i++)
			{
				Tile tile = gameController.GetCurrentBlock().GetTile(i);
				tilesSprite.setTextureRect(sf::IntRect(tile.GetColor() * COLOR_MULTIPLIER, 0, TILES_PIXEL_COUNT, TILES_PIXEL_COUNT));
				tilesSprite.setPosition(tile.GetX() * TILES_PIXEL_COUNT, tile.GetY() * TILES_PIXEL_COUNT);
				window.draw(tilesSprite);
			}
			/*
			for (int i = 0; i < 4; i++)
			{
				Tile tile = gameController.GetIncomingBlock().GetTile(i);
				tilesSprite.setTextureRect(sf::IntRect(tile.GetColor() * COLOR_MULTIPLIER, 0, TILES_PIXEL_COUNT, TILES_PIXEL_COUNT));
				tilesSprite.setPosition(400,500);
				window.draw(tilesSprite);
			}*/

			for (int i = 0; i < WIDTH; i++)
			{
				for (int j = 0; j < HEIGHT; j++)
				{
					Tile tile = gameController.GetPlayField().GetTile(i, j);
					tilesSprite.setTextureRect(sf::IntRect(tile.GetColor() * COLOR_MULTIPLIER, 0, TILES_PIXEL_COUNT, TILES_PIXEL_COUNT));
					tilesSprite.setPosition(tile.GetX() * TILES_PIXEL_COUNT, tile.GetY() * TILES_PIXEL_COUNT);
					window.draw(tilesSprite);
				}
			}
			window.draw(s_frame_poziom);
			window.draw(s_frame_pion);

			window.display();
		}
		else if (_menu.getChoicedItemIndex() == 1)
		{
			window.clear();
			window.draw(s_top5_background);
			_top5.changeTheStateOfDisplayHigscores(Bollean::True);
			_top5.scoresWindowController(window, _menu);
			_top5.draw(window);
			window.display();
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