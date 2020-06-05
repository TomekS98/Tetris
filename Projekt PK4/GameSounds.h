#pragma once
#include <SFML/Audio.hpp>

#define ONE_LINE_S_FILE_PATH "music/oneline.ogg"
#define FOUR_LINE_S_FILE_PATH "music/fourline.ogg"
#define GAME_OVER_S_FILE_PATH "music/gameover.ogg"
#define LEVEL_UP_S_FILE_PATH "music/lvlup.ogg"
#define WOW_S_FILE_PATH "music/wow.ogg"

class GameSounds
{
	sf::SoundBuffer _buffer;
	sf::Sound _sound;
public:
	GameSounds();
	void oneLineSound();
	void fourLineSound();
	void gameOverSound();
	void levelUpSound();
	void wowSound();
};

