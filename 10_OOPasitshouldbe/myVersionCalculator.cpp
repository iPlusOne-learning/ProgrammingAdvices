#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

class clsCalculator
{
    private:
    int _Result = 0;
    int _InputValue = 0;
    std::string _OperationType = "";

    public:

    void Clear()
    {
        _Result = 0;
    }
    void Add(int Num)
    {
        _InputValue = Num;
        _Result+= Num;
        _OperationType = "+";
    }

    void Substract(int Num)
    {
        _InputValue = Num;
        _Result-= Num;
        _OperationType = "-";
    }

    void Divide(int Num)
    {
        _InputValue = Num;
        _Result/= Num;
        _OperationType = "/";
    }

    void Multiply(int Num)
    {
        _InputValue = Num;
        _Result*= Num;
        _OperationType = "*";
    }

    void PrintResult()
    {
        if (_OperationType == "+")
        {

            std::cout << "Result after adding " << _InputValue << " is: " << _Result << std::endl;
        }
        else if (_OperationType == "-")
        {
            std::cout << "Result after substracting " << _InputValue << " is: " << _Result << std::endl;
        } 
        else if (_OperationType == "/")
        {
            std::cout << "Result after dividing " << _InputValue << " is: " << _Result << std::endl;
        }
        else
        {
            std::cout << "Result after multiplying " << _InputValue << " is: " << _Result << std::endl;
        }
    }
};

int main()
{
    clsCalculator Calculator1;
    //add, clear, divide, getfinalresult, multiply, printresult, substrcut,

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
    Calculator1.PrintResult();

    return 0;
}