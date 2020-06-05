#include "GameMusic.h"

GameMusic::GameMusic()
{
	_powerOfVolium = 50;
}

void GameMusic::inGameMusic() {
	if (!_music.openFromFile(IN_GAME_MUSIC_FILEPATH)) {
		return;
	}
	_music.setVolume(_powerOfVolium);
	_music.setLoop(true);
	_music.play();
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

void GameMusic::musicStop() {
	_music.stop();
}