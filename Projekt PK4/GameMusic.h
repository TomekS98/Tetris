#pragma once
#include <SFML/Audio.hpp>
#include "VolumeChange.h"
#include "Bollean.h"
#include "Defines.h"

class GameMusic
{
	sf::Music _music;
	int _powerOfVolium;
	bool isBeingPlayed;
	std::string whatMusicIsBeingPlayed;
public:
	GameMusic();
	void inGameMusic();
	void inMenuMusic();
	void volumeChangeOfTheMusic(VolumeChange varOfVolumeChange);
	void musicStop();
	void changeTheStateOfPlayMusic(Bollean state);
	bool getTheStateOfPlayMusic();
	std::string getMusicString() { return whatMusicIsBeingPlayed; };
};

