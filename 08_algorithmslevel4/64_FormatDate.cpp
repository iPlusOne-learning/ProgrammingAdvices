#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>

struct stDate
{
    short Day;
    short Month;
    short Year;
};

std::string ReadStringDate(std::string Message)
{
    std::string DateString;
    std::cout << Message;
    std::getline(std::cin >> std::ws, DateString);
    return DateString;
}

std::vector<std::string> SplitString(std::string Str, std::string Delimiter)
{
    std::vector<std::string> sString;
    std::string sWord;
    int pos;

    while ((pos = Str.find(Delimiter)) != std::string::npos)
    {
        sWord = Str.substr(0, pos);
        if (sWord != "")
            sString.push_back(sWord);
        Str.erase(0, pos + Delimiter.length());
    }
    if (Str != "")
        sString.push_back(Str);
    return sString;
}

std::string ReplaceWordInString(std::string S1, std::string StringToReplace, std::string sRepalceTo)
{
    short pos = S1.find(StringToReplace);
    while (pos != std::string::npos)
    {
        S1 = S1.replace(pos, StringToReplace.length(),sRepalceTo);
        pos = S1.find(StringToReplace);
    }
    return S1;
}

stDate StringToDate(std::string DateString)
{
    stDate Date;
    std::vector<std::string> vDate;

    vDate = SplitString(DateString, "/");

    Date.Day = std::stoi(vDate[0]);
    Date.Month = std::stoi(vDate[1]);
    Date.Year = std::stoi(vDate[2]);

    return Date;
}

std::string FormatDate(stDate Date, std::string DateFormat = "dd/mm/yyyy")
{
    std::string FormattedDateString = "";
    FormattedDateString = ReplaceWordInString(DateFormat, "dd",std::to_string(Date.Day));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "mm", std::to_string(Date.Month));
    FormattedDateString = ReplaceWordInString(FormattedDateString, "yyyy", std::to_string(Date.Year));
    return FormattedDateString;
}

int main()
{

    std::string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy: ");

    stDate Date = StringToDate(DateString);

    std::cout << "\n" << FormatDate(Date) << std::endl;
    std::cout << "\n" << FormatDate(Date, "yyyy/dd/mm") << std::endl;
    std::cout << "\n" << FormatDate(Date,"dd/mm/yyyy") << std::endl;
    std::cout << "\n" << FormatDate(Date,"mm-dd-yyyy") << std::endl;
    std::cout << "\n" << FormatDate(Date,"dd-mm-yyyy") << std::endl;
    std::cout << "\n" << FormatDate(Date, "Date:dd, Month:mm, Year:yyyy") << std::endl;

   
    return 0;
}

// struct stDate
// {
//     short Day;
//     short Month;
//     short Year;
// };

// std::string ReadStringDate(std::string Message)
// {
//     std::string DateString;
//     std::cout << Message;
//     std::getline(std::cin >> std::ws, DateString);
//     return DateString;
// }

// std::vector <std::string> SplitString(std::string Str, std::string Delimiter)
// {
//     std::vector <std::string> sString;
//     std::string sWord;
//     int pos;

//     while ((pos = Str.find(Delimiter)) != std::string::npos)
//     {
//         sWord = Str.substr(0,pos);
//         if (sWord != "")
//             sString.push_back(sWord);
//         Str.erase(0, pos + Delimiter.length());
//     }
//     if (Str != "")
//         sString.push_back(Str);
//     return sString;
// }

// stDate StringToDate(std::string DateString)
// {
//     stDate Date;
//     std::vector <std::string> vDate;

//     vDate = SplitString(DateString, "/");

//     Date.Day = std::stoi(vDate[0]);
//     Date.Month = std::stoi(vDate[1]);
//     Date.Year = std::stoi(vDate[2]);

//     return Date;
// }

// void FormatDate(stDate Date)
// {
//     std::cout << "\n" << std::to_string(Date.Day) + "/" + std::to_string(Date.Month) + "/" + std::to_string(Date.Year) << std::endl;
//     std::cout << "\n" << std::to_string(Date.Year) + "/" + std::to_string(Date.Day) + "/" + std::to_string(Date.Month)<< std::endl;
//     std::cout << "\n" << std::to_string(Date.Month) + "/" + std::to_string(Date.Day) + "/" + std::to_string(Date.Year)<< std::endl;

//     std::cout << "\n" << std::to_string(Date.Month) + "-" + std::to_string(Date.Day) + "-" + std::to_string(Date.Year)<< std::endl;
//     std::cout << "\n" << std::to_string(Date.Day) + "-" + std::to_string(Date.Month) + "-" + std::to_string(Date.Year)<< std::endl;
//     std::cout << "\n" << "Day:" << std::to_string(Date.Day) + " ,Month:" + std::to_string(Date.Month) + " ,Year:" + std::to_string(Date.Month)<< std::endl;

// }

// int main()
// {

//     std::string DateString = ReadStringDate("\nPlease Enter Date dd/mm/yyyy: ");

//     stDate Date = StringToDate(DateString);

//     FormatDate(Date);

//     return 0;
// }