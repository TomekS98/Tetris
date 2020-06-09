#pragma once
#include <time.h>
#include <SFML/Graphics.hpp>

#include "Speed.h"

class Timer
{
	float _timer;
	float _delay;
	bool _isSpeededUp;
public:
	Timer();
	void setDelayCausedByLevel();
	void setDelayCausedByKeyDown();
	void resetDelayAfterKeyDown();
	void setTimer(float _time);
	float getDelay();
	float getTimer();
	void resetTimer();
	bool checkIfItsSpeededUp();
	void setSpeed(Speed varOfSpeed,Timer& timer);
	void resetDelay() { _delay = 0.5; }
};

