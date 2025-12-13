#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

int ReadInput()
{
    int Year;
    std::cout << "Enter the year: ";
    std::cin >> Year;
    return Year;

}

bool isLeap(int Year)
{
    if (Year % 400 == 0)
    {
        return true;
    }
    else if (Year % 100 == 0)
    {
        return false;
    }
    else if (Year % 4 == 0)
    {
        return true;
    }    
    else
    {
        return false;
    }

}

int main()
{
    int Year = ReadInput();
    
    if (isLeap(Year))
        std::cout << "This year: " << Year << " is a LEAP YEAR.\n";
    else
        std::cout << "This year: " << Year << " is NOT a LEAP YEAR.\n";

    return 0;
}