#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>

struct sDate
{
    short Day;
    short Month;
    short Year;
};

short ReadDay()
{
    short Day;
    std::cout << "\nPlease enter day: ";
    std::cin >> Day;
    return Day;
}
short ReadMonth()
{
    short Month;
    std::cout << "\nPlease enter month: ";
    std::cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    std::cout << "\nPlease enter year: ";
    std::cin >> Year;
    return Year;
}

sDate ReadFullDate()
{
    sDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

short ReadDaysToAdd()
{
    short Days;
    std::cout << "\nHow many days to add? ";
    std::cin >> Days;
    return Days;
}

bool IsLeap(int Year)
{
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    int DaysInCommonYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return ((Month == 2) ? (IsLeap(Year) ? 29 : 28) : DaysInCommonYear[Month - 1]);
}

short NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
{
    short TotalDays = 0;

    for (short i = 0; i < Month - 1; i++)
    {
        TotalDays += NumberOfDaysInMonth(i + 1, Year);
    }
    return TotalDays += Day;
}

sDate DateAddDays(short Days, sDate Date)
{
    short RemainingDays = Days + NumberOfDaysFromTheBeginningOfTheYear(Date.Day, Date.Month, Date.Year);
    short MonthDays = 0;
    Date.Month = 1;
    while(true)
    {
        MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
        if( RemainingDays > MonthDays)
        {
            RemainingDays-= MonthDays;
            Date.Month++;
            if (Date.Month > 12)
            {
                Date.Month = 1;
                Date.Year++;
            }
        }
        else
        {
            Date.Day = RemainingDays;
            break;
        }
    }
    return Date;
}

int main()
{
    sDate Date = ReadFullDate();
    short Days = ReadDaysToAdd();

    Date = DateAddDays(Days, Date);

    std::cout << "\nDate after adding [" << Days << "] days i: ";
    std::cout << Date.Day << "/" << Date.Month << "/" << Date.Year << std::endl;

    return 0;
}

// short ReadDay()
// {
//     short Day;
//     std::cout << "\nPlease enter day: ";
//     std::cin >> Day;
//     return Day;
// }
// short ReadMonth()
// {
//     short Month;
//     std::cout << "\nPlease enter month: ";
//     std::cin >> Month;
//     return Month;
// }
// short ReadYear()
// {
//     short Year;
//     std::cout << "\nPlease enter year: ";
//     std::cin >> Year;
//     return Year;
// }
// short ReadDaysToAdd()
// {
//     short DaysToAdd;
//     std::cout << "\nHow many days to add? ";
//     std::cin >> DaysToAdd;
//     return DaysToAdd;
// }

// bool IsLeap(int Year)
// {
//     return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
// }

// short NumberOfDaysInMonth(short Month, short Year)
// {
//     if (Month < 1 || Month > 12)
//         return 0;

//     int DaysInCommonYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

//     return ((Month == 2) ? (IsLeap(Year) ? 29 : 28) : DaysInCommonYear[Month - 1]);
// }

// short    NumberOfDaysFromTheBeginningOfTheYear(short Day, short Month, short Year)
// {
//         short TotalDays = 0;

//         for (short i = 0; i < Month - 1 ; i++)
//         {
//             TotalDays+= NumberOfDaysInMonth(i+1, Year);
//         }
//         return TotalDays+=Day;
// }

// short RemainingDaysFromYear(short Day, short Month, short Year)
// {
//     short TotalDaysOfYear = 0;
//     short TotalDays = NumberOfDaysFromTheBeginningOfTheYear(Day,Month,Year);

//     for (short i = 1; i <= 12; i++)
//     {
//         TotalDaysOfYear+= NumberOfDaysInMonth(i,2022);
//     }
//     return TotalDaysOfYear - TotalDays;
// }

// short DateAfterAddingYears(short Day, short Month, short &Year, short DaysToAdd)
// {
//     short YearTotalDays = 0;
//     DaysToAdd = DaysToAdd - RemainingDaysFromYear(Day, Month, Year);
//     Year++;

//     while (true)
//     {
//         if (IsLeap(Year))
//             YearTotalDays = 366;
//         else
//             YearTotalDays = 365;

//         if (IsLeap(Year))
//         {
//             if (DaysToAdd <= 366)
//                 break;
//         }
//         else if (DaysToAdd <= 365)
//         {
//             break;
//         }

//         DaysToAdd-= YearTotalDays;
//         Year++;

//     }
//     return DaysToAdd;
// }

// struct sDate
// {
//     short DayFinal;
//     short MonthFinal;
//     short YearFinal;
// };

// sDate GetDateFromDayOrderInYear(short DaysOrderInYear, short Year)
// {
//     sDate Date;
//     short RemainingDays = DaysOrderInYear;
//     short MonthDays = 0;
//     Date.YearFinal = Year;
//     Date.MonthFinal = 1;

//     while(true)
//     {
//         MonthDays = NumberOfDaysInMonth(Date.MonthFinal, Year);
//         if (RemainingDays > MonthDays)
//         {
//             RemainingDays-= MonthDays;
//             Date.MonthFinal++;
//         }
//         else
//         {
//             Date.DayFinal = RemainingDays;
//             break;
//         }
//     }
//     return Date;
// }

// int main()
// {
//     short Day = ReadDay();
//     short Month = ReadMonth();
//     short Year = ReadYear();
//     short DaysToAdd = ReadDaysToAdd();
//     short RemainingDays = 0;

//     RemainingDays =  DateAfterAddingYears(Day,Month, Year, DaysToAdd);
//     sDate WholeDate = GetDateFromDayOrderInYear(RemainingDays, Year);

//     std::cout << "\nDate after adding [" << DaysToAdd << "] days i: ";
//     std::cout << WholeDate.DayFinal << "/" << WholeDate.MonthFinal << "/" << WholeDate.YearFinal << std::endl;

//     return 0;
// }