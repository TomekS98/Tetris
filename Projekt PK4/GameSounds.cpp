#include "gameSounds.h"

GameSounds::GameSounds(){}

void GameSounds::oneLineSound()
{
	if (!_buffer.loadFromFile(ONE_LINE_S_FILE_PATH))
	{
		return;
	}
	_sound.setBuffer(_buffer);
	_sound.play();
}
void GameSounds::fourLineSound()
{
	if (!_buffer.loadFromFile(FOUR_LINE_S_FILE_PATH))
	{
		return;
	}
	_sound.setBuffer(_buffer);
	_sound.play();
}
void GameSounds::gameOverSound()
{
	if (!_buffer.loadFromFile(GAME_OVER_S_FILE_PATH))
	{
		return;
	}
	_sound.setBuffer(_buffer);
	_sound.play();
}
void GameSounds::levelUpSound()
{
	if (!_buffer.loadFromFile(LEVEL_UP_S_FILE_PATH))
	{
		return;
	}
	_sound.setBuffer(_buffer);
	_sound.play();
}
void GameSounds::wowSound()
{
	if (!_buffer.loadFromFile(WOW_S_FILE_PATH))
	{
		return;
	}
	_sound.setBuffer(_buffer);
	_sound.play();
}