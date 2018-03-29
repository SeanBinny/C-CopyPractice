//Member-function definition for class Time
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include "Time.h"// include definition of class Time from Time.h.
using namespace std;

// Time constructor initializes each data member
Time::Time(int hour, int minute, int second )
{
    setTime( hour, minute, second );// validate and set time
} // end Time constructor

// set new Time value using unversal time
void Time::setTime(int h, int m, int s )
{
    setHour(h);//set private field hour
    setSecond(m);//set private field minute
    setSecond(s);//set private filed second
} // end function setTime

// set hour value
void Time::setHour( int h )
{
    if ( h >= 0 && h < 24)
        hour = h;
    else
        throw invalid_argument( "hour must be 0-23 ");
} // end function setHour

// set minute value
void Time::setMinute( int m )
{
    if( m >= 0 && m < 60 )
        minute = m;
    else
        throw invalid_argument( "minute must be 0-59 ");
} // end function setMinute

// set second value
void Time::setSecond( int s )
{
    if( s >= 0 && s < 60 )
        second = s;
    else
        throw invalid_argument( "second must be 0-59 ");
} //end function setSecond

// return hour value
unsigned int Time::getHour() const
{
    return hour;
} // end function getHour

//return minute value
unsigned Time::getMinute() const
{
    return minute;
}// end function getMinute

//return second value
unsigned Time::getSecond() const
{
    return second;
} // end function setSecond

//print TIme in universal-time format (HH:MM:SS)
void Time::printUniversal() const
{
    cout << setfill( '0' ) << setw( 2 ) << getHour() << ":"
         << setw( 2 ) << getMinute() << ":"<< setw( 2 ) << getSecond();
} // end functin printUniversal

// print Time in standard-timeformat (HH:MM:SS AM or PM)
void Time::printStandard() const
{
    cout << ( ( getHour() == 0 || getHour() == 12 ) ? 12 : getHour() % 12 )
         << ":" << setfill( '0' ) << setw( 2 ) << getMinue()
         << ":" << setw( 2 ) << getSecond() << ( hour < 12 ? " AM " : " PM " );

} // end function printStandard

