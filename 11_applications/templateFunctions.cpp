#include <iostream>

using namespace std;

template <typename T> 
T myMax(T Number1, T Number2)
{

    return (Number1 > Number2) ? Number1 : Number2;
}

int main()
{

    cout << myMax<float>(3.4,3.5) << endl;
    cout << myMax<int>(4,5) << endl;
}