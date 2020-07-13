#pragma once
#include "Defines.h"
#include <SFML/Audio.hpp>



class GameSounds
{
	sf::SoundBuffer _buffer;
	sf::Sound _sound;
public:
	GameSounds();
	void oneLineSound();
	void gameOverSound();
	void levelUpSound();
	void wowSound();
};

