#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Time {
private :
	int h = 0;
	int m = 0;
	int s = 0;

public:
	int getHour();
	void setHour(int hour);
	int getMinute();
	void setMinute(int min);
	int getSecond();
	void setSecond(int sec);

};