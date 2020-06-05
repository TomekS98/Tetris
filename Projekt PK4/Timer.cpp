#include "Timer.h"

Timer::Timer()
{
	_timer = 0.3;
	_delay = 0.5;
	_isSpeededUp=false;
}
void Timer::setDelayCausedByLevel()
{
	_delay *= 0.95;
}

void Timer::setDelayCausedByKeyDown() 
{
	_delay /= 2;
}
void Timer::resetDelayAfterKeyDown()
{
	_delay *= 2;
}
void Timer::setTimer(float _time) 
{
	_timer += _time;
}
float Timer::getDelay()
{
	return _delay;
}
float Timer::getTimer()
{
	return _timer;
}

void Timer::resetTimer() {
	_timer = 0;
}

void Timer::setSpeed(Speed varOfSpeed,Timer &timer) {
	switch (varOfSpeed) 
	{
	case Fast:
		_isSpeededUp = true;
		timer.setDelayCausedByKeyDown();
		break;
	case Regular:
		_isSpeededUp = false;
		timer.resetDelayAfterKeyDown();
		break;
	default:
		break;
	}
}
bool Timer::checkIfItsSpeededUp() {
	return _isSpeededUp;
}