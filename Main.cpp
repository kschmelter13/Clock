#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Time.h"

using namespace std;


string nCharString(size_t n, char c) {
    /**
 * Returns a string of length n, each character a c.
 * For example, nCharString(5, '*') should return "*****"
 *
 * @param n string length, >=0
 * @return string of n c's
 */
    string j = "";
    for (int i = 0; i < n; i++) {
        j += c;
    }
    // return the n character string
    return j;
}


string twoDigitString(unsigned int n) {
    /**
 * Formats a number as 2 digits, with a leading 0 if needed
 *
 * @param n number to format, assumed between 0 and 59, inclusive
 * @return two digit string representation of number
 */
    stringstream f;
    f << n;
    string d;
    if (n < 10) {
        d = "0" + f.str();
    }
    else {
        d = f.str();
    }
    // return the two digit string
    return d;
}


string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    /**
 * Formats the time in military format

 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 *
 * @return hh:mm:ss
 */
    string time = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
    // return time as hh:mm:ss
    return time;
}



string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    /**
 * Formats the time in am/pm format
 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 *
 * @return hh:mm:ss A M or hh:mm:ss P M where hh is between 01 and 12, inclusive
 */
    string time;
    if (h == 0) {
        time = twoDigitString(12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";
    }
    else if (h < 12) {
        time = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " A M";
    }
    else if (h == 12) {
        time = twoDigitString(12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";
    }
    else {
        time = twoDigitString(h - 12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";
    }


    // return hh:mm:ss A M or hh:mm:ss P M
    return time;
}


void printMenu(const char* strings[], unsigned int numStrings, unsigned int width) {
    /**
     * In your own program feel free to change the function signature. For now, please first get it to work as is.
     * You may assume <string> and <iostream> have been imported.
     * You may assume a function nCharString has been implemented, and you will want to call it for stars and spaces.
     * string nCharString(size_t n, char c) produces a string of n c's. For example, nCharString(5, '*') returns "*****"
     * and nCharString (7,' ') will return 7 spaces.
     */
     // TODO: Your code here. Use the comments to see the expected format of the menu.
    cout << nCharString(width, '*') << endl;

    // first print width *'s followed by an endl
    for (int i = 0; i < numStrings; i++) {
        stringstream strs;

        strs << "* " << i + 1 << " - " << strings[i];
        string st = strs.str();
        cout << setw(width - 1) << left << st;
        cout << "*" << endl;
    }
    /** Next, for each string s in the array:
     * cout a star, a space, the item Number a space a hyphen another space, s,
     * and enough spaces to get to a length of width - 1 (enough will depend on the length of the current menu item).
     * Close the line with a star and an endl. The goal is that the stars on the right align with each other and each line
     * has the same width, passed in as a parameter.
     * (Hint: calculate the needed number of spaces and use nCharString to produce them)
     * Skip a line after each line except the last line
     */

     // outside the loop print another width *s followed by an endl
    cout << nCharString(width, '*') << endl;

}



unsigned int getMenuChoice(unsigned int maxChoice) {
    /**
 * Gets menu choice 1 through maxChoice, inclusive
 *
 * @param maxChoice, maximum choice index, a number between 2 and 9, inclusive
 * @return the first legal choice input, could be 1 through maxChoice, inclusive
 */
    int val = 0;
    while (!((val >= 1) && (val <= maxChoice))) {
        cin >> val;
    }
    return val;
    // return the value
}

/**
 * Display the clocks
 *
 * @param h, hours 0 to 23
 * @param m, minutes 0 to 59
 * @param s, seconds 0 to 59
 */
void displayClocks(Time t) {

    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    cout << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ');
    cout << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
    cout << endl;
    cout << "*" << nCharString(6, ' ') << formatTime12(t.getHour(), t.getMinute(), t.getSecond()) << nCharString(7, ' ') << "*" << nCharString(3, ' ');
    cout << "*" << nCharString(8, ' ') << formatTime24(t.getHour(), t.getMinute(), t.getSecond()) << nCharString(9, ' ') << "*" << endl;
    cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
}


/**
 * Adds one hour
 */
void addOneHour(Time &c) {
    /** Assume you have a working getHour() and setHour(h)
     * Feel free to change things around in your code, but first please get it working here
     * with these function signatures.
     * if getHour() is between 0 and 22 inclusive, add 1 and setHour() to that
     * if getHour() is 23 the next value for hour is 0 so setHour() to that
     * test will check values of hours from 0 to 23 from getHour()
     */
     // TODO: Your code here
    if (c.getHour() >= 0 && c.getHour() <= 22) {
        c.setHour(c.getHour() + 1);
    }
    else {
        c.setHour(0);
    }
    // nothing to return, just setHour to the appropriate value
}


/**
 * Adds one minute
 */
void addOneMinute(Time &c) {
    /**assume you have working getMinute(), setMinute(m), and addOneHour()
     * Feel free to change these in your program, but for now please get things to work with
     * these function signatures.
     * if getMinute() is between 0 and 58 inclusive, add 1 and setMinute() to the new value
     * if getMinute() is 59 the minutes must be set to 0 and you must call addOneHour()
     * test will set hours and minutes to 0, then addOneMinute 60 times
     */
     //TODO: Your code here
    if (c.getMinute() >= 0 && c.getMinute() <= 58) {
        c.setMinute(c.getMinute() + 1);
    }
    else {
        addOneHour(c);
        c.setMinute(0);
    }
    // nothing to return, just setMinute to the appropriate value and use addOneHour if needed
}


/**
 * Adds one second
 */
void addSecond(Time &c) {
    /** assume you have working getSecond(), setSecond(s), and addOneMinute()
     * addOneMinute will take care of the hours if necessary
     * Feel free to change things around in your program, but for now please make this work with these function signatures.
     * if getSecond() is between 0 and 58 inclusive, add 1 and setSecond()
     * if getSecond() is 59, seconds wrap around to 0 and you need to call addOneMinute()
     * test will set minutes to 4 and seconds to 0, then addOneSecond 60 times
     */

     // TODO: your code here
    if (c.getSecond() >= 0 && c.getSecond() <= 58) {
        c.setSecond(c.getSecond() + 1);
    }
    else {
        c.setSecond(0);
        addOneMinute(c);
    }


    // nothing to return, just call setSecond() with the right value and addOneMinute() when needed
}

int main() {
    Time t;
    const char* strings[4] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
    int choice = 0;
    
    while (choice != 4) {  // continues until 4 entered 
        for (int i = 0; i < 40; ++i)
            cout << endl;
        displayClocks(t);
        printMenu(strings, 4, 27);
        choice = getMenuChoice(4);
        switch(choice) {
        case 1:             // adds hour
            addOneHour(t);
            break;
        case 2:             // adds minute
            addOneMinute(t);
            break;
        case 3:             // adds second
            addSecond(t);
            break;
        case 4:             // exits program
            break;

        default:
            cout << "Invalid";
        }
    }


}