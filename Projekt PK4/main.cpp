
#include "BlocksGenerator.h"
#include "PlayField.h"
#include "GameController.h"
#include "Scoreboard.h"
#include "GameMusic.h"
#include "GameSounds.h"

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
	s_frame_pion.setPosition(315, 0);
	s_frame_poziom.setPosition(0, 635);
	sf::Font _font;
	if (!_font.loadFromFile("fonts/font.ttf"))
	{
		return -1;
	}
	GameMusic _gameMusic;
	_gameMusic.inGameMusic();
	GameSounds _gameSounds;
	TextPoppingUp _textmsg(_font);
	Level _level(_font);
	Scoreboard _scoreboard(_font);
	
	
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
		

		
		gameController.Tick(clock, Timer, event, window,_gameMusic,_gameSounds,_textmsg,_level,_scoreboard);

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

	return 0;
}


/*******************TO DO****************************
* X | ZAIMPLEMENTOWAC POZIOMY CO 3 ULOZONE LINIJEK  *
* X | ZROBIC BACKGROUND W GIMPIE d-_-b				*
* X | DODAC SOUNDS									*
* X | DODAC GAMEOVER								*
*********************ZAAWANSOWANE********************
* X | NAPRAWIC WYSWIETLANIE SCORE I POZIOM			*
* O | MENU											*
* O | HIGHHSCORES									*
****************************************************/