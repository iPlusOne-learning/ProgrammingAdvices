#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>

short ReadYear()
{
    short Year;
    std::cout << "Please enter year: ";
    std::cin >> Year;
    return Year;
}

short ReadMonth()
{
    short Month;
    std::cout << "\nPlease enter month: ";
    std::cin >> Month;
    return Month;
}

bool IsLeap(int Year)
{
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12 )
        return 0;

    int DaysInCommonYear[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    return ((Month == 2) ? (IsLeap(Year) ? 29 : 28) : DaysInCommonYear[Month - 1]);
}

short NumberOfHoursInMonth(short Month, short Year)
{
    return NumberOfDaysInMonth(Month, Year) * 24;
}

int NumberOfMinutesInMonth(short Month, short Year)
{
    return NumberOfHoursInMonth(Month, Year) * 60;
}

int NumberOfSecondsInMonth(short Month, short Year)
{
    return NumberOfMinutesInMonth(Month, Year) * 60;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    std::cout << "Number of Days in Month[" << Month << "] is "<<  NumberOfDaysInMonth(Month, Year) << std::endl;
    std::cout << "Number of Hours in Month[" << Month << "] is "<<  NumberOfHoursInMonth(Month, Year) << std::endl;
    std::cout << "Number of Minutes in Month[" << Month << "] is "<<  NumberOfMinutesInMonth(Month, Year) << std::endl;
    std::cout << "Number of Seconds in Month[" << Month << "] is "<<  NumberOfSecondsInMonth(Month, Year) << std::endl;

    return 0;
}