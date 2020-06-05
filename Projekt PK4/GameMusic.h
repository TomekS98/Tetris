#pragma once
#include <SFML/Audio.hpp>
#include "VolumeChange.h"
#define IN_GAME_MUSIC_FILEPATH "music/tetris_music_piano.ogg"

class GameMusic
{
	sf::Music _music;
	int _powerOfVolium;
public:
	GameMusic();
	void inGameMusic();
	//void inLobbyMusic();
	void volumeChangeOfTheMusic(VolumeChange varOfVolumeChange);
	void musicStop();
};

