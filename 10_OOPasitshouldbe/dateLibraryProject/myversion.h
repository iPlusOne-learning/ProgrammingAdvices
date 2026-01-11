#pragma once

#include <ctime>
#include <iostream>
#include "../stringLibraryProject/headerFiles/clsString.h"

using namespace std;

class clsDate : public clsString
{

private:
    short _Day;
    short _Month;
    short _Year;
    
    public:
    clsDate()
    {
        time_t t = time(0);
        tm *tp = localtime(&t);
        _Day = tp->tm_mday;
        _Month = tp->tm_mon + 1;
        _Year = tp->tm_year + 1900;
    }
    
    clsDate(string FullDate)
    {
        vector<string> _FullDate;
        clsString S1;
        _FullDate = S1.Split(FullDate, "/");
        _Day = stoi(_FullDate[0]);
        _Month = stoi(_FullDate[1]);
        _Year = stoi(_FullDate[2]);
    }
    
    clsDate(short Day, short Month, short Year)
    {
        
        _Day = Day;
        _Month = Month;
        _Year = Year;
    }

    clsDate(short Days, short Year)
    {
        stDate Date1;
        Date1 = GetDateFromDayOrderInYear(Days, Year);
        _Day = Date1.Day;
        _Month = Date1.Month;
        _Year = Year;
    }
    
    struct stDate
    {
        short Year;
        short Month;
        short Day;
    };
    
    bool IsLeapYear(int Year)
    {
        return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
    }

    short NumberOfDaysInMonth(short Month, short Year)
    {
        if (Month < 1 || Month > 12)
            return 0;

        int DaysInCommonYear[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        return ((Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : DaysInCommonYear[Month - 1]);
    }
    short DayOfWeekOrder(short Day, short Month, short Year)
    {
        short A = (14 - Month) / 12;
        short Y = Year - A;
        short M = Month + (12 * A) - 2;

        return (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;
    }
    std::string MonthShortName(short MonthNumber)
    {
        std::string Months[12] = {"Jan", "Feb", "Mar","Apr", "May", "Jun","Jul", "Aug", "Sep","Oct", "Nov", "Dec"};
        return (Months[MonthNumber - 1]);
    }

    void PrintMonthCalender()
    {
        short NumberOfDays = NumberOfDaysInMonth(_Month, _Year);
        short Current = DayOfWeekOrder(1, _Month, _Year);

        printf("----------------------%s----------------------\n\n", MonthShortName(_Month).c_str());
        printf("  Sun     Mon    Tue    Wed    Thu    Fri    Sat\n");
        int i;
        for (i = 0; i < Current; i++)
            printf("       ");
        for (int j = 1; j <= NumberOfDays; j++)
        {
            printf("%5d  ", j);
            if (++i == 7)
            {
                i = 0;
                printf("\n");
            }
        }
        printf("\n------------------------------------------------\n");
    }

    stDate GetDateFromDayOrderInYear(short DaysOrderInYear, short Year)
    {
        stDate Date;
        short RemainingDays = DaysOrderInYear;
        short MonthDays = 0;

        Date.Year = Year;
        Date.Month = 1;

        while (true)
        {
            MonthDays = NumberOfDaysInMonth(Date.Month, Year);
            if (RemainingDays > MonthDays)
            {
                RemainingDays -= MonthDays;
                Date.Month++;
            }
            else
            {
                Date.Day = RemainingDays;
                break;
            }
        }
        return Date;
    }

    void Print()
    {
        cout << _Day << "/" << _Month << "/" << _Year << endl;
    }
};
