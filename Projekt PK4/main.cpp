
#include "BlocksGenerator.h"
#include "PlayField.h"
#include "GameController.h"

const int TILES_PIXEL_COUNT = 32;
const int COLOR_MULTIPLIER = 32;

float timer = 0, delay = 0.5;

int main()
{
	srand(time(NULL));
	sf::Clock clock;
	sf::RenderWindow window;
	sf::VideoMode VMode(WIDTH * TILES_PIXEL_COUNT, HEIGHT * TILES_PIXEL_COUNT, 32);
	window.create(VMode, "Tetris", sf::Style::Close);

	sf::Texture tilesTexture;
	tilesTexture.loadFromFile("images/tiles.png");
	sf::Sprite tilesSprite = sf::Sprite(tilesTexture);
	tilesSprite.setTextureRect(sf::IntRect(0, 0, TILES_PIXEL_COUNT, TILES_PIXEL_COUNT));
	
	window.setFramerateLimit(5);

	sf::Event event;
	GameController gameController(BlocksGenerator(0, 0), PlayField());

	while (window.isOpen())
	{
		gameController.Tick(clock, timer, delay, event, window);

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
