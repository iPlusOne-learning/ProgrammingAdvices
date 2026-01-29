#include <iostream>


using namespace std;

template <typename T>
class clsCalculator
{
    private:
    T _Number1;
    T _Number2;

    public:
    clsCalculator (T Num1, T Num2)
    {
        _Number1 = Num1;
        _Number2 = Num2;
    }

    void Add()
    {
        cout << _Number1 + _Number2 << endl;
    }
};

int main()
{
    clsCalculator<int> intCal(3,4);
    clsCalculator<string> strCal("hel", "lo");
    intCal.Add();
    strCal.Add();
    return 0;
}