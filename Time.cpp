#include "Time.h"

using namespace std;

int Time::getHour() {
	return h;
};
void Time::setHour(int hour) {
	this->h = hour;
};
int Time::getMinute() {
	return m;
};
void Time::setMinute(int min) {
	this->m = min;
};
int Time::getSecond() {
	return s;
};
void Time::setSecond(int sec) {
	this->s = sec;
};