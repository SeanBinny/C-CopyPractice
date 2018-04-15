#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

// initialize static member; one classwide copy
const array< unsigned int, 13 > Date::days_ =
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Date::Date( int month, int day, int year )
{
    setDate( month, day, year );
}

void Date::setDate( int mm, int dd, int yy )
{
    if( mm >= 1 && mm <= 12 )
        month_ = mm;
    else
        throw invalid_argument( "Month must be 1-12 " );

    if( yy >= 1900 && yy <= 2100 )
        year_ = yy;
    else
        throw invalid_argument( "Year must be >= 1900 and <= 2100" );
    if( ( month_ == 2 && leapYear( year_ ) && dd >= 1 && dd <= 29 ) ||( dd >= 1 && dd <= days_ [month_] ) )
        day_ = dd;
    else
        throw invalid_argument( "Day is out of range for current month and year " );
}

Date &Date::operator ++()
{
    helpIncrement();
    return *this;
}

Date Date::operator ++( int )
{
    Date temp = *this;
    helpIncrement();

    return temp;
}

Date &Date::operator +=( unsigned int additionalDays )
{
    for( int i = 0; i < additionalDays; ++i )
        helpIncrement();

    return *this;
}

bool Date::leapYear( int testyear )
{
    if( testyear % 400 == 0 ||
      ( testyear % 100 != 0 && testyear % 4 == 0 ))
        return true;
    else
        return false;
}

bool Date::endOfMonth( int testDay ) const
{
    if( month_ == 2 && leapYear( year_ ) )
        return testDay == 29;
    else
        return testDay == days_[month_];
}

void Date::helpIncrement()
{
    if( !endOfMonth( day_ ) )
        ++day_;
    else
        if( month_ < 12 )
        {
            ++month_;
            day_ = 1;
        }
        else
        {
            ++year_;
            month_ = 1;
            day_ = 1;
        }
}

ostream & operator <<( ostream & output, const Date &d)
{
    static string monthName[ 13 ] = { "", "January", "February",
           "March", "April","May","June","July","August",
           "September","Octorber","November","December"};

    output << monthName[ d.month_ ] << " " <<d.day_ << ", " << d.year_;
    return output;
}
