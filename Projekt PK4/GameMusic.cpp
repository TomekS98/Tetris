#include "GameMusic.h"

GameMusic::GameMusic()
{
	_powerOfVolium = 50;
	isBeingPlayed = false;
}

void GameMusic::inGameMusic() {
	if (!_music.openFromFile(IN_GAME_MUSIC_FILEPATH)) {
		return;
	}
	_music.setVolume(_powerOfVolium);
	_music.setLoop(true);
	_music.play();
	changeTheStateOfPlayMusic(True);
	whatMusicIsBeingPlayed = "Game";
}

void GameMusic::inMenuMusic() {
	if (!_music.openFromFile(IN_MENU_MUSIC_FILEPATH)) {
		return;
	}
	_music.setVolume(_powerOfVolium);
	_music.setLoop(true);
	_music.play();
	changeTheStateOfPlayMusic(True);
	whatMusicIsBeingPlayed = "Menu";
}

void GameMusic::volumeChangeOfTheMusic(VolumeChange varOfVolumeChange) 
{
	switch (varOfVolumeChange) {
	case Higher:
		if (_powerOfVolium < 91)
		{
			_powerOfVolium += 10;
		}
		_music.setVolume(_powerOfVolium);
		break;
	case Lower:
		if (_powerOfVolium > 9)
		{
			_powerOfVolium -= 10;
		}
		_music.setVolume(_powerOfVolium);
		break;
	default:
		break;
	}
}

void GameMusic::musicStop()
{
	_music.stop();
}

void GameMusic::changeTheStateOfPlayMusic(Bollean state) 
{
	switch (state) {
	case True:
		isBeingPlayed = true;
		break;
	case False:
		isBeingPlayed = false;
		break;
	default:
		break;
	}
}

bool GameMusic::getTheStateOfPlayMusic() 
{
	return isBeingPlayed;
}
