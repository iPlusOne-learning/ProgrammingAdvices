#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

int ReadNumber()
{
    int Number;
    std::cout << "Enter a number: ";
    std::cin >> Number;
    return Number;
}

std::string NumberToText(int Number)
{
    if (Number == 0)
    {
        return "";
    }
    if (Number >= 1 && Number <= 19)
    {
        std::string Arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven",
                             "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
                             "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        return Arr[Number] + " ";
    }
    if (Number >= 20 && Number <= 99)
    {
        std::string Arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
                             "Seventy", "Eighty", "Ninety"};
        return Arr[Number / 10] + " " + NumberToText(Number % 10);
    }
    if (Number >= 100 && Number <= 199)
    {
        return "One hundred " + NumberToText(Number % 100);
    }
    if (Number >= 200 && Number <= 999)
    {
        return NumberToText(Number / 100) + "Hundred and " + NumberToText(Number % 100);
    }
    if (Number >= 1000 && Number <= 1999)
    {
        return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
    }
    if (Number >= 2000 && Number <= 999999)
    {
        return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
    }
    if (Number >= 1000000 && Number <= 1999999)
    {
        return "One Million " + NumberToText(Number / 1000000);
    }
    if (Number >= 2000000 && Number <= 999999999)
    {
        return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
    }
    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billion " + NumberToText(Number % 1000000000);
    }
    else
    {
        return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
    }
}

int main()
{
    int Number = ReadNumber();

    std::cout << NumberToText(Number) << std::endl;

    return 0;
}