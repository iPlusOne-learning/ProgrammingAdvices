#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

class clsCalculator
{
private:
    float _Result = 0;
    float _LastNumber = 0;
    float _PreviousResult = 0;
    std::string _LastOperation = "clear";

    bool _IsZero(float Number)
    {
        return (Number == 0);
    }

public:
    void Add(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "Adding";
        _Result += Number;
    }

    void Substract(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "substracting";
        _Result -= Number;
    }
    
    void Divide(float Number)
    {
        _LastNumber = Number;
        if (_IsZero(Number))
        {
            Number = 1;
        }
        _PreviousResult = _Result;
        _LastOperation = "dividing";
        _Result /= Number;
    }
    
    void Multiply(float Number)
    {
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOperation = "multiplying";
        _Result *= Number;
    }
    
    float GetFinalResults()
    {
        return _Result;
    }

    void Clear()
    {
        _Result = 0;
        _PreviousResult = 0;
        _LastOperation = "clear";
        _Result = 0;
    }

    void CancelLastOperation()
    {
        _LastNumber = 0;
        _LastOperation = "Cancelling last operation";
        _Result = _PreviousResult;
    }

    void PrintResult()
    {
        std::cout << "Result ";
        std::cout << "After " << _LastOperation << " " << _LastNumber << " is: "
        << _Result << std::endl;
    }
};

int main()
{
    clsCalculator Calculator1;
    // add, clear, divide, getfinalresult, multiply, printresult, substrcut,

    Calculator1.Clear();
    Calculator1.PrintResult();
    Calculator1.Add(10);
    Calculator1.PrintResult();

    Calculator1.Add(30);
    Calculator1.PrintResult();

    Calculator1.Substract(5);
    Calculator1.PrintResult();

    Calculator1.Multiply(2);
    Calculator1.PrintResult();

    Calculator1.Clear();
    Calculator1.PrintResult();

    Calculator1.Add(80);
    Calculator1.PrintResult();

    Calculator1.Add(7);
    Calculator1.PrintResult();

    Calculator1.Substract(30);
    Calculator1.PrintResult();

    Calculator1.Multiply(10);
    Calculator1.CancelLastOperation();
    Calculator1.PrintResult();

    return 0;
}