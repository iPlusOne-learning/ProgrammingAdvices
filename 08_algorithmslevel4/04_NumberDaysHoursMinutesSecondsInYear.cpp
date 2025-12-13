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
bool IsLeap(int Year)
{
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInYear(short Year)
{
    return (IsLeap(Year) ? 366 : 365);
}

short NumberOfHourInYear(short Year)
{
    return NumberOfDaysInYear(Year) * 24;

}

int NumberOfMinutesInYear(short Year)
{
    return NumberOfHourInYear(Year) * 60;
}

int NumberOfSecondsInYear(short Year)
{
    return NumberOfMinutesInYear(Year) * 60;
}

//This is my own implementation
// void ConvertYear(int Year)
// {
//     int Days = 365;

//     if (IsLeap(Year))
//         Days = 366;

//     std::cout << "Number of Days in year[" << Year << "] is " << Days << std::endl;
//     std::cout << "Number of Hours in year[" << Year << "] is " << Days * 24 << std::endl;
//     std::cout << "Number of Minutes in year[" << Year << "] is " << Days * 24 * 60 << std::endl;
//     std::cout << "Number of Seconds in year[" << Year << "] is " << Days * 24 * 60 * 60 << std::endl;

// }

int main()
{
    int Year = ReadYear();

    std::cout << "Number of Days in year[" << Year << "] is " << NumberOfDaysInYear(Year) << std::endl;
    std::cout << "Number of Hours in year[" << Year << "] is " << NumberOfHourInYear(Year) << std::endl;
    std::cout << "Number of Minutes in year[" << Year << "] is " << NumberOfMinutesInYear(Year) << std::endl;
    std::cout << "Number of Seconds in year[" << Year << "] is " << NumberOfSecondsInYear(Year) << std::endl;
 
    return 0;
}