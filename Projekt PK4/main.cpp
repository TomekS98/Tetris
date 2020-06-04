
#include "BlocksGenerator.h"
#include "PlayField.h"
#include "GameController.h"
#include "Scoreboard.h"

#include <iostream>
#include <SFML/Audio.hpp>
const int TILES_PIXEL_COUNT = 32;
const int COLOR_MULTIPLIER = 32;

//float timer = 0, delay = 0.5;

int main()
{
	srand(time(NULL));
	Timer Timer;
	sf::Clock clock;
	sf::RenderWindow window;
	sf::VideoMode VMode(WIDTH * TILES_PIXEL_COUNT+180, HEIGHT * TILES_PIXEL_COUNT, 32);
	window.create(VMode, "Tetris", sf::Style::Close);

	sf::Texture tilesTexture;
	tilesTexture.loadFromFile("images/tiles.png");
	sf::Sprite tilesSprite = sf::Sprite(tilesTexture);
	tilesSprite.setTextureRect(sf::IntRect(0, 0, TILES_PIXEL_COUNT, TILES_PIXEL_COUNT));
	sf::Font _font;
	if (!_font.loadFromFile("fonts/font.ttf"))
	{
		return -1;
	}

	sf::Music music;
	if (!music.openFromFile("music/tetris_music_piano.ogg")) {
		return -1;
	}
	music.setVolume(50);
	music.setLoop(true);
	music.play();

	sf::Text textjakis;
	/*
	textjakis.setFont(_font);
	textjakis.setString("69");
	textjakis.setCharacterSize(64);
	textjakis.setFillColor(sf::Color::Red);
	textjakis.setPosition(350, 100);
	*/
	window.setFramerateLimit(15);

	Scoreboard Scoreboard(_font);
	sf::Event event;
	GameController gameController(BlocksGenerator(0, 0), PlayField());

	while (window.isOpen())
	{
	
		//sf::Text text = Scoreboard.getScoreTxt();
		//window.draw(text);
		gameController.Tick(clock, Timer , event, window);
		
		window.pollEvent(event);
		window.clear(sf::Color::Black);
		
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
		
		window.display();
	}

	return 0;
}


/*******************TO DO************************
* ZAIMPLEMENTOWAC POZIOMY CO 5 ULOZONYCH LINIJEK*
* NAPRAWIC WYSWIETLANIE SCORE I POZIOM			*
* ZROBIC BACKGROUND W GIMPIE d-_-b				*
* DODAC SOUNDS									*
* DODAC GAMEOVER								*
******************ZAAWANSOWANE*******************
* MENU											*
* HIGHHSCORES									*
************************************************/